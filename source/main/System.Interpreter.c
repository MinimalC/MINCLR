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

    if (System_String8_endsWith(argv[0], "System.Interpreter")) {
        if (argc == 1) {
            System_Console_writeLine__string("Usage: System.Interpreter filename");
            return false; 
        }

        System_Console_writeLine__string("This is System.Interpreter as command");
        name = argv[1];
        base = (System_Var)ROUNDDOWN(System_Environment_AuxValues[System_Environment_AuxType_PHDR].value, 4096);
    }
    else  System_Console_writeLine__string("This is System.Interpreter as INTERP");


    /* Read ELFAssembly_Header */
    System_ELF64Assembly_Header header = (System_ELF64Assembly_Header)base;
    if (!System_String8_equalsSubstring(header->magic, System_ELFAssembly_Magic, 4)) {
        System_Console_writeLine__string("NOELF");
        return false; /* TODO throw */
    }
    System_Console_writeLine("ELF_Header: type {0:uint16}, machine {1:uint16}, version {2:uint32}, entryPoint 0x{3:uint:hex}, size {4:uint16}", 5,
        header->type, header->machine, header->version, header->entryPoint, header->size);


    /* Read ELFAssembly_ProgramHeaders */
    // extern System_Size _DYNAMIC; System_Size * dynamic = &_DYNAMIC;
    System_ELF64Assembly_ProgramHeader programs = (System_ELF64Assembly_ProgramHeader)(base + header->programHeaderOffset);
    System_ELF64Assembly_DynamicEntry dynamics = null; //(System_ELF64Assembly_DynamicEntry)(base + dynamic);
    System_ELF64Assembly_SymbolEntry dynamicSymbols = null;
    System_ELF64Assembly_RelocationAddend relocation = null, relocation1 = null;
    Size dynamicsCount = 0, dynamicSymbolSize = 0, relocSize = 0, relocCount = 0, reloc1Size = 0, reloc1Count = 0;
    System_String8 dynamicSymbolsStrings = null;
    for (i = 0; i < 32 && i < header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)programs + (i * header->programHeaderSize));

        if (program->type == System_ELFAssembly_ProgramType_Dynamic) {
            dynamics = (System_ELF64Assembly_DynamicEntry)(base + program->virtualAddress);
            dynamicsCount = program->fileSize / sizeof(struct System_ELF64Assembly_DynamicEntry);
        }

        System_Console_writeLine("ELF_ProgramHeader({0:uint}): type {1:uint32}, flags {2:uint32:bin}, offset {3:uint:hex}, virtualAddress {4:uint:hex}, physicalAddress {5:uint:hex}, fileSize {6:uint:hex}, memorySize {7:uint:hex}", 8, i,
            program->type, program->flags, program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
    }

    for (i = 0; i < dynamicsCount; ++i) {
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_STRTAB) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            dynamicSymbolsStrings = (System_String8)(dynamics[i].value); 
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
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELAENT)
            relocSize = dynamics[i].value;

        if (dynamics[i].tag == System_ELFAssembly_DynamicType_JMPREL) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            // relocation1 = (System_ELF64Assembly_RelocationAddend)(dynamics[i].value);
        }
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_PLTRELSZ)
            // relocation1Count = dynamics[i].value / sizeof(struct System_ELF64Assembly_RelocationAddend);

        if (dynamics[i].tag == System_ELFAssembly_DynamicType_PLTGOT) {
            dynamics[i].value = (System_Size)base + dynamics[i].value;
            // plt = (System_Var *)(dynamics[i].value);
        }
    }
    for (i = 0; i < dynamicsCount; ++i) {
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_RELASZ)
            relocCount = !dynamics[i].value ? null : dynamics[i].value / relocSize;
    }
    System_ELF64Assembly_DynamicEntry_toString(dynamics, dynamicsCount, dynamicSymbolsStrings);

    if (relocation)
    for (i = 0; i < relocCount; ++i) {
        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_NONE) continue;

        System_Size * address = (System_Size * )((System_Size)base + relocation[i].offset), oldies = *address;

        System_ELF64Assembly_SymbolEntry symbol = !relocation[i].symbol ? null : &dynamicSymbols[relocation[i].symbol];

        switch (relocation[i].type) {
        case System_ELFAssembly_AMD64Relocation_JUMP_SLOT:
        case System_ELFAssembly_AMD64Relocation_GLOB_DAT: *address = symbol->value; break;
        case System_ELFAssembly_AMD64Relocation_RELATIVE: *address = (System_Size)base + relocation[i].addend; break;
        default: System_Console_write__string("unknown "); break;
        }
        
        /*System_Console_writeLine("INTERP Relocation: offset {0:uint:hex}, type {1:uint32:hex}, symbol {2:uint32:hex}, addend {3:uint:hex}; address {4:uint:hex}: old {5:uint:hex} => new {6:uint:hex}", 7,
            relocation[i].offset, relocation[i].type, relocation[i].symbol, relocation[i].addend, address, oldies, *address);

        if (symbol) {
            System_Console_writeLine("INTERP Relocation Symbol: name {0:string}, info {1:uint8:hex}, other {2:uint8:hex}, sectionIndex {3:uint16}, value {4:uint64:hex}, size {5:uint64}", 6, 
                dynamicSymbolsStrings + symbol->name, symbol->info, symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
        }*/
    }

    //System_Size * plt = Environment_GetGlobalOffsetTable();
    // if (plt) System_Console_writeLine("INTERP GLOBAL_OFFSET_TABLE: {0:uint:hex}, [0] {1:uint:hex}, [1] {2:uint:hex}, [2] {3:uint:hex}", 4, plt, plt[0], plt[1], plt[2]);
    
    extern System_Size _DYNAMIC;
    System_Console_writeLine("INTERP AddressOf _DYNAMIC: {0:uint:hex}", 1, &_DYNAMIC);

    

    System_ELF64Assembly assembly = (System_ELF64Assembly)System_Memory_allocClass(typeof(System_ELF64Assembly));
    System_ELF64Assembly_read__print(assembly, name, 1);
    System_ELF64Assembly_link__print(assembly, 1);
    
    //System_ELF64Assembly assembly1;
    //System_ELF64Assembly_SymbolEntry entrySymbol = System_ELF64Assembly_getSymbol("System_Runtime_main", &assembly1);
    //System_Var entry = assembly1->link + entrySymbol->value; 
    System_Var entry = assembly->link + assembly->header->entryPoint;
    //System_Var entry = (System_Var)System_Environment_AuxValues[System_Environment_AuxType_ENTRY].value;
#if DEBUG
    System_Console_writeLine("Interpreter JUMPING to 0x{0:uint:hex}, with stack on 0x{1:uint:hex}", 2, entry, System_Runtime_stack);
#endif

    register System_Var entry0 __asm__("r11") = entry;
    register System_Var exit0 __asm__("rdx") = System_Syscall_terminate;
    register System_Var stack0 __asm__("rsp") = System_Runtime_stack;
    
    __asm__ __volatile__( " jmp *%%r11" : : : "memory" );
    //__asm__ __volatile__( "mov %1, %%rsp ; jmp *%0" : : "r"(entry), "m"(System_Runtime_stack) : "memory" );

    System_Syscall_terminate(false);
}
