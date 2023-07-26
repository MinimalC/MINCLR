/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "../System.internal.h"
#endif
#include <min/System.h>

#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

#define STACKSIZE 0x800000UL

Var Environment_GetGlobalOffsetTable() {
    Var reture;
    asm("lea _GLOBAL_OFFSET_TABLE_(%%rip),%0" : "=r"(reture) );
    return reture;
}

int System_Runtime_main(int argc, char  * argv[]) {

    System_Size i;
    System_String8 name = (System_String8)System_Environment_AuxValues[System_Environment_AuxType_EXECFN].value;
    System_Var base = (System_Var)System_Environment_AuxValues[System_Environment_AuxType_BASE].value;

    if (!base || System_String8_endsWith(argv[0], "System.Interpreter")) {
        if (argc == 1) {
            System_Console_writeLine__string("Usage: System.Interpreter filename");
            return false; 
        }

        name = argv[1];
        base = (System_Var)ROUNDDOWN(System_Environment_AuxValues[System_Environment_AuxType_PHDR].value, 4096);

#if DEBUG == DEBUG_System_ELFAssembly
         System_Console_writeLine__string("This is System.Interpreter as command");
#endif
    }
#if DEBUG == DEBUG_System_ELFAssembly
    else System_Console_writeLine__string("This is System.Interpreter as INTERP");
#endif

    /* Read ELFAssembly_Header */
    System_ELF64Assembly_Header header = (System_ELF64Assembly_Header)base;
    if (!System_String8_equalsSubstring(header->magic, System_ELFAssembly_Magic, 4)) {
        System_Console_writeLine__string("NOELF");
        return false; /* TODO throw */
    }
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("ELF_Header: type {0:uint16}, machine {1:uint16}, version {2:uint32}, entryPoint 0x{3:uint:hex}, size {4:uint16}", 5,
        header->type, header->machine, header->version, header->entryPoint, header->size);
#endif

    /* Read ELFAssembly_ProgramHeaders */
    System_ELF64Assembly_ProgramHeader programs = (System_ELF64Assembly_ProgramHeader)(base + header->programHeaderOffset);
    System_ELF64Assembly_DynamicEntry dynamics = null;
    System_ELF64Assembly_SymbolEntry dynamicSymbols = null;
    System_String8 dynamicStrings = null;
    System_Size dynamicsCount = 0, dynamicSymbolSize = 0;
    for (i = 0; i < 32 && i < header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)programs + (i * header->programHeaderSize));

        if (program->type == System_ELFAssembly_ProgramType_Dynamic) {
            dynamics = (System_ELF64Assembly_DynamicEntry)(base + program->virtualAddress);
            dynamicsCount = program->fileSize / sizeof(struct System_ELF64Assembly_DynamicEntry);
        }

#if DEBUG == DEBUG_System_ELFAssembly
        System_Console_writeLine("ELF_ProgramHeader({0:uint}): type {1:uint32}, flags {2:uint32:bin}, offset {3:uint:hex}, virtualAddress {4:uint:hex}, physicalAddress {5:uint:hex}, fileSize {6:uint:hex}, memorySize {7:uint:hex}", 8, i,
            program->type, program->flags, program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
#endif
    }

    System_ELF64Assembly_RelocationAddend relocation = null, relocation1 = null;
    System_Size relocCount = 0, reloc1Count = 0;
    System_Size * plt = null;
    for (i = 0; i < dynamicsCount; ++i) {
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_STRTAB) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            dynamicStrings = (System_String8)(dynamics[i].value); 
        }
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_SYMTAB) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            dynamicSymbols = (System_ELF64Assembly_SymbolEntry)(dynamics[i].value); 
        }
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_SYMENT)
            dynamicSymbolSize = dynamics[i].value; 

        if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELA) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            relocation = (System_ELF64Assembly_RelocationAddend)(dynamics[i].value); 
        }
        // if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELAENT) 
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELASZ)
            relocCount = !dynamics[i].value ? null : dynamics[i].value / sizeof(struct System_ELF64Assembly_RelocationAddend);

        if (dynamics[i].tag == System_ELFAssembly_DynamicType_JMPREL) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            relocation1 = (System_ELF64Assembly_RelocationAddend)(dynamics[i].value);
        }
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_PLTRELSZ)
            reloc1Count = !dynamics[i].value ? null : dynamics[i].value / sizeof(struct System_ELF64Assembly_RelocationAddend);

        if (dynamics[i].tag == System_ELFAssembly_DynamicType_PLTGOT) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            plt = (System_Size *)(dynamics[i].value);
        }
    }
#if DEBUG == DEBUG_System_ELFAssembly
    for (System_Size i = 0; i < dynamicsCount; ++i)
        switch(dynamics[i].tag) {
        case System_ELFAssembly_DynamicType_NEEDED:
        case System_ELFAssembly_DynamicType_SONAME:
            if (!dynamicStrings)
                System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, System_ELFAssembly_DynamicType_toString(dynamics[i].tag), dynamics[i].value);
            else
                System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:string}", 2, System_ELFAssembly_DynamicType_toString(dynamics[i].tag), dynamicStrings + dynamics[i].value);
            break;
        default:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, System_ELFAssembly_DynamicType_toString(dynamics[i].tag), dynamics[i].value);
            break;
        }
#endif

    if (relocation)
    for (i = 0; i < relocCount; ++i) {
        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_NONE) continue;

        System_Size * address = (System_Size * )((System_Size)base + relocation[i].offset), oldies = *address;

        System_ELF64Assembly_SymbolEntry symbol = !relocation[i].symbol ? null : &dynamicSymbols[relocation[i].symbol];

        switch (relocation[i].type) {
        case System_ELFAssembly_AMD64Relocation_RELATIVE: 
            if (relocation[i].addend)
                *address = (System_Size)base + relocation[i].addend; 
            break;
        case System_ELFAssembly_AMD64Relocation_64: 
            if (symbol->value)
                *address = (System_Size)base + symbol->value + relocation->addend; 
            break;
        case System_ELFAssembly_AMD64Relocation_JUMP_SLOT:
            if (symbol->sectionIndex && symbol->value && *address) {
                *address += (System_Size)base;
                break;
            }
        case System_ELFAssembly_AMD64Relocation_GLOB_DAT: 
            if (symbol->value)
                *address = (System_Size)base + symbol->value; 
            break;
        case System_ELFAssembly_AMD64Relocation_COPY: 
            if (symbol->value && symbol->size)
                System_Memory_copyTo(base + symbol->value, symbol->size, address);
            break;
        case System_ELFAssembly_AMD64Relocation_32: 
            *address = (System_Size)base + (symbol->value & 0xFFFFFFFFUL); 
            break;
        }
        
        /*System_Console_writeLine("INTERP Relocation: offset {0:uint:hex}, type {1:uint32:hex}, symbol {2:uint32:hex}, addend {3:uint:hex}; address {4:uint:hex}: old {5:uint:hex} => new {6:uint:hex}", 7,
            relocation[i].offset, relocation[i].type, relocation[i].symbol, relocation[i].addend, address, oldies, *address);

        if (symbol) {
            System_Console_writeLine("INTERP Relocation Symbol: name {0:string}, info {1:uint8:hex}, other {2:uint8:hex}, sectionIndex {3:uint16}, value {4:uint64:hex}, size {5:uint64}", 6, 
                dynamicStrings + symbol->name, symbol->info, symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
        }*/
    }

#if DEBUG == DEBUG_System_ELFAssembly
    System_Size * plt = Environment_GetGlobalOffsetTable();
    if (plt) System_Console_writeLine("INTERP GLOBAL_OFFSET_TABLE: {0:uint:hex}, [0] {1:uint:hex}, [1] {2:uint:hex}, [2] {3:uint:hex}", 4, plt, plt[0], plt[1], plt[2]);
    
    extern System_Size _DYNAMIC;
    System_Console_writeLine("INTERP AddressOf _DYNAMIC: {0:uint:hex}", 1, &_DYNAMIC);
#endif
    

    System_ELF64Assembly assembly = (System_ELF64Assembly)System_Memory_allocClass(typeof(System_ELF64Assembly));
#if DEBUG == DEBUG_System_ELFAssembly
    System_ELF64Assembly_read__print(assembly, name, true);
    System_ELF64Assembly_link__print(assembly, true);
#else
    System_ELF64Assembly_read__print(assembly, name, false);
    System_ELF64Assembly_link__print(assembly, false);
#endif
    //System_ELF64Assembly assembly1;
    //System_ELF64Assembly_SymbolEntry entrySymbol = System_ELF64Assembly_getSymbol("System_Runtime_main", &assembly1);
    //System_Var entry = assembly1->link + entrySymbol->value; 
    System_Var entry = assembly->link + assembly->header->entryPoint;
    //System_Var entry = (System_Var)System_Environment_AuxValues[System_Environment_AuxType_ENTRY].value;
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("INTERP JUMPING to 0x{0:uint:hex}, with stack on 0x{1:uint:hex}", 2, entry, System_Runtime_stack);
#endif

    register System_Var entry0 __asm__("r11") = entry;
    register System_Var exit0 __asm__("rdx") = System_Syscall_terminate;
    register System_Var stack0 __asm__("rsp") = System_Runtime_stack;
    
    __asm__ __volatile__( " jmp *%%r11" : : : "memory" );
    //__asm__ __volatile__( "mov %1, %%rsp ; jmp *%0" : : "r"(entry), "m"(System_Runtime_stack) : "memory" );

    System_Syscall_terminate(false);
}
