/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "../System.internal.h"
#endif
#include <min/System.h>

#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

#define STACKSIZE 0x800000UL

int System_Runtime_main(int argc, char  * argv[]) {

    System_Size i;

    if (System_String8_endsWith(argv[0], "System.Interpreter")) {
        if (argc == 1) {
            System_Console_writeLine__string("Usage: System.Interpreter filename");
            return false; 
        }

        System_Console_writeLine__string("This is System.Interpreter as command");

        /*struct System_ELF64Assembly assembly;
        System_ELF64Assembly_read(&assembly, argv[arg0]);
        System_ELF64Assembly_link(&assembly);*/

        return true;
    }
    
    System_Console_writeLine__string("This is System.Interpreter as INTERP");


    /* Read ELFAssembly_Header */
    System_Var base = (System_Var)System_Environment_AuxValues[System_Environment_AuxType_BASE].value;
    System_ELF64Assembly_Header header = (System_ELF64Assembly_Header)base;
    if (!System_String8_equals(header->magic, System_ELFAssembly_Magic)) {
        System_Console_writeLine__string("NOELF");
        return false; /* TODO throw */
    }
    System_Console_writeLine("ELF_Header: type {0:uint16}, machine {1:uint16}, version {2:uint32}, entryPoint 0x{3:uint:hex}, size {4:uint16}", 5,
        header->type, header->machine, header->version, header->entryPoint, header->size);


    /* Read ELFAssembly_ProgramHeaders */
    System_ELF64Assembly_ProgramHeader programs = (System_ELF64Assembly_ProgramHeader)(base + header->programHeaderOffset);
    System_ELF64Assembly_DynamicEntry dynamics = null;
    System_ELF64Assembly_SymbolEntry symbols = null;
    System_ELF64Assembly_RelocationAddend relocation = null;
    Size dynamicsCount = 0, symbolSize = 0, relocSize = 0, relocCount = 0;
    System_String8 symbolsStrings = null;
    for (i = 0; i < 32 && i < header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)programs + (i * header->programHeaderSize));

        if (program->type == System_ELFAssembly_ProgramType_Dynamic) {
            dynamics = (System_ELF64Assembly_DynamicEntry)(base + program->offset);
            dynamicsCount = program->fileSize / sizeof(struct System_ELF64Assembly_DynamicEntry);
        }

        System_Console_writeLine("ELF_ProgramHeader({0:uint}): type {1:uint32}, flags {2:uint32:bin}, offset {3:uint:hex}, virtualAddress {4:uint:hex}, physicalAddress {5:uint:hex}, fileSize {6:uint:hex}, memorySize {7:uint:hex}", 8, i,
            program->type, program->flags, program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
    }
    for (i = 0; i < dynamicsCount; ++i) {
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_STRTAB)
            symbolsStrings = (System_String8)(base + dynamics[i].value); 
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_SYMTAB)
            symbols = (System_ELF64Assembly_SymbolEntry)(base + dynamics[i].value); 
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_SYMENT)
            symbolSize = dynamics[i].value; 
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELA)
            relocation = (System_ELF64Assembly_RelocationAddend)(base + dynamics[i].value); 
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELAENT)
            relocSize = dynamics[i].value;
    }
    for (i = 0; i < dynamicsCount; ++i)
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELASZ)
            if (dynamics[i].value) { 
                relocCount = dynamics[i].value / relocSize;
                break;
            }

    System_Console_writeLine("INTERP dynamicsCount {0:uint}, symbolSize {1:uint:hex}, relocSize {2:uint:hex}, relocCount {3:uint};", 4, 
        dynamicsCount, symbolSize, relocSize, relocCount);

   for (i = 0; i < relocCount; ++i) {
        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_NONE) continue;

        System_Size * address = (System_Size * )(((System_Size)base) + relocation[i].offset);
        System_Size oldies = *address;

        System_ELF64Assembly_SymbolEntry symbol = !relocation[i].symbol ? null : &symbols[relocation[i].symbol];

        switch (relocation[i].type) {
        case System_ELFAssembly_AMD64Relocation_JUMP_SLOT:
        case System_ELFAssembly_AMD64Relocation_GLOB_DAT: *address = (System_Size)base + symbol->value; break;
        case System_ELFAssembly_AMD64Relocation_RELATIVE: *address = (System_Size)base + relocation[i].addend; break;
        default: System_Console_write__string("unknown "); break;
        }
        
        System_Console_writeLine("INTERP Relocation: offset {0:uint:hex}, type {1:uint32:hex}, symbol {2:uint32:hex}, addend {3:uint:hex}; address {4:uint:hex}: old {5:uint:hex} => new {6:uint:hex}", 7,
            relocation[i].offset, relocation[i].type, relocation[i].symbol, relocation[i].addend, address, oldies, *address);

        if (symbol) {
            System_Console_writeLine("INTERP Relocation Symbol: name {0:string}, info {1:uint8:hex}, other {2:uint8:hex}, sectionIndex {3:uint16}, value {4:uint64:hex}, size {5:uint64}", 6, 
                symbolsStrings + symbol->name, symbol->info, symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
        }
    }

    /*for (i = 0; i < symbolSize; ++i) {
        System_ELF64Assembly_SymbolEntry symbol = &symbols[i];

        System_Console_writeLine("INTERP Symbol: name {0:string}, info {1:uint8:hex}, other {2:uint8:hex}, sectionIndex {3:uint16}, value {4:uint64:hex}, size {5:uint64}", 6, 
            symbolsStrings + symbol->name, symbol->info, symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
    }*/

    for (i = 0; i < dynamicsCount; ++i) {
        switch(dynamics[i].tag) {
        case System_ELFAssembly_DynamicType_NEEDED:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:string}", 2, "NEEDED", symbolsStrings + dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_PLTRELSZ:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "PLTRELSZ", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_PLTGOT:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "PLTGOT", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_HASH:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "HASH", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_STRTAB:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "STRTAB", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_SYMTAB:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "SYMTAB", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RELA:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "RELA", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RELASZ:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "RELASZ", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RELAENT:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "RELAENT", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_STRSZ:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "STRSZ", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_SYMENT:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "SYMENT", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_INIT:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "INIT", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_FINI:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "FINI", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_SONAME:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "SONAME", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RPATH:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "RPATH", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_SYMBOLIC:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "SYMBOLIC", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_REL:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "REL", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RELSZ:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "RELSZ", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RELENT:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "RELENT", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_PLTREL:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "PLTREL", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_DEBUG:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "DEBUG", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_TEXTREL:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "TEXTREL", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_JMPREL:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "JMPREL", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_BIND_NOW:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "BIND_NOW", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_INIT_ARRAY:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "INIT_ARRAY", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_FINI_ARRAY:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "FINI_ARRAY", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_INIT_ARRAYSZ:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "INIT_ARRAYSZ", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_FINI_ARRAYSZ:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "FINI_ARRAYSZ", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RUNPATH:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "RUNPATH", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_FLAGS:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "FLAGS", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_ENCODING:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "ENCODING", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_PREINIT_ARRAY:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "PREINIT_ARRAY", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_PREINIT_ARRAYSZ:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "PREINIT_ARRAYSZ", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_SYMTAB_SHNDX:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "SYMTAB_SHNDX", dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_NUM:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, "NUM", dynamics[i].value); break;
        default:
            System_Console_writeLine("ELFDynamicEntry: tag {0:uint}, value {1:uint}", 2, dynamics[i].tag, dynamics[i].value); break;
        }
    }
    

    System_String8 name = (System_String8)System_Environment_AuxValues[System_Environment_AuxType_EXECFN].value;

    struct ELFAssembly assembly = {};
    System_ELF64Assembly_read__print(&assembly, name, 2);
    System_ELF64Assembly_link__print(&assembly, 2);
    
    
    System_Var stack = System_Syscall_mmap(STACKSIZE, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous | System_Memory_MapFlags_Stack, null, 0);
    System_Size * stackOrigin = (System_Size *)(stack + STACKSIZE - sizeof(System_Size));
    System_Size * stackPtr = stackOrigin;
    *(stackPtr--) = 0;
    for (Size i = 0; i < System_Environment_AuxValues_Length; ++i)
        if (System_Environment_AuxValues[i].type != 0) {
            *(stackPtr--) = (System_Size)System_Environment_AuxValues[i].value;
            *(stackPtr--) = (System_Size)System_Environment_AuxValues[i].type;
        }
    *(stackPtr--) = 0;
    for (Size i = 0; i < System_Environment_Arguments_Length; ++i)
        *(stackPtr--) = (System_Size)System_Environment_Arguments[i];
    *(stackPtr--) = 0;
    for (Size i = 0; i < argc; ++i)
        *(stackPtr--) = (System_Size)argv[i];
    *(stackPtr--) = (System_Size)argc;

    // System_Var entry = (System_Var)System_Environment_AuxValues[System_Environment_AuxType_ENTRY].value;
    System_Var entry = assembly.link + assembly.header->entryPoint;
#if DEBUG
    System_Console_writeLine("Interpreter JUMPING to 0x{0:uint:hex}, with stack on 0x{1:uint:hex} and System_Console_exit on 0x{2:uint:hex}", 3, entry, stack, System_Console_exit);
#endif
    __asm__ __volatile__( "mov %0, %%rdx ; mov %1, %%rsp ; jmp *%2" : : "r"(System_Console_exit), "r"(stack), "r"(entry) : "memory" );
    //__asm__ __volatile__( "mov %0, %%rsp ; jmp *%1" : : "r"(stackPtr + 1), "r"(entry) : "memory" );

    System_Console_exit(true);
}