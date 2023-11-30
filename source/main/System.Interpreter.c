/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#include <min/System.Runtime.h>
#include <min/System.Type.h>
#include <min/System.Memory.h>
#include <min/System.String8.h>
#include <min/System.Console.h>
#include <min/System.Environment.h>
#include <min/System.ELFAssembly.h>
#include <min/System.Thread.h>

#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

System_Var Environment_GetGlobalOffsetTable() {
    System_Var reture; asm("lea _GLOBAL_OFFSET_TABLE_(%%rip),%0" : "=r"(reture) ); return reture;
}

void System_Runtime_relocate(System_Var base, System_ELF64Assembly_Relocation relocation, System_ELF64Assembly_Symbol dynamicSymbols, System_String8 dynamicStrings) {

    if (!relocation->type) return;

    System_Size * address = (System_Size * )((System_Size)base + relocation->offset), oldies = *address;

    System_ELF64Assembly_Symbol symbol = !relocation->symbol ? null : dynamicSymbols + relocation->symbol;

    switch (relocation->type) {
    case System_ELFAssembly_AMD64_RELATIVE: 
        if (relocation->addend)
            *address = (System_Size)base + relocation->addend; 
        break;
    case System_ELFAssembly_AMD64_64: 
        if (symbol->value)
            *address = (System_Size)base + symbol->value + relocation->addend; 
        break;
    case System_ELFAssembly_AMD64_32: 
        *address = (System_Size)base + (symbol->value & 0xFFFFFFFFUL); 
        break;
    case System_ELFAssembly_AMD64_JUMP_SLOT:
    case System_ELFAssembly_AMD64_GLOB_DAT: 
        if (symbol->value)
            *address = (System_Size)base + symbol->value; 
        else if (*address)
            *address += (System_Size)base;
        break;
    case System_ELFAssembly_AMD64_COPY: 
        if (symbol->value && symbol->size)
            System_Memory_copyTo(base + symbol->value, symbol->size, address);
        break;
#if DEBUG
    default:
        System_Console_writeLine("INTERP ELFRelocation unlinked: offset {0:uint:hex}, type {1:uint32:hex}, symbol {2:uint32:hex}, addend {3:uint:hex}; address {4:uint:hex}: old {5:uint:hex} => new {6:uint:hex}", 7,
            relocation->offset, relocation->type, relocation->symbol, relocation->addend, address, oldies, *address);

        if (symbol)
            System_Console_writeLine("       Symbol: name {0:string}, info {1:uint8:hex}, other {2:uint8:hex}, sectionIndex {3:uint16}, value {4:uint64:hex}, size {5:uint64}", 6, 
                dynamicStrings + symbol->name, symbol->info, symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
        break;
#endif 
    }
}

void System_Runtime_selflink(System_Var base) {
    System_Size i;

    /* Read ELFAssembly_Header */
    System_ELF64Assembly_Header header = (System_ELF64Assembly_Header)base;
    if (!System_String8_equalsSubstring(header->magic, System_ELFAssembly_Magic, 4)) {
        System_Console_writeLine__string("NOELF");
        return; /* TODO throw */
    }
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("ELFHeader: type {0:uint16}, machine {1:uint16}, version {2:uint32}, entryPoint 0x{3:uint:hex}, size {4:uint16}", 5,
        header->type, header->machine, header->version, header->entryPoint, header->size);
#endif
    
    /* Read ELFAssembly_ProgramHeaders */
    System_ELF64Assembly_ProgramHeader programs = (System_ELF64Assembly_ProgramHeader)(base + header->programHeaderOffset);
    System_ELF64Assembly_DynamicEntry dynamics = null;
    System_Size dynamicsCount = 0;
    for (i = 0; i < 32 && i < header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)programs + (i * header->programHeaderSize));

        if (program->type == System_ELFAssembly_ProgramType_Dynamic) {
            dynamics = (System_ELF64Assembly_DynamicEntry)(base + program->virtualAddress);
            dynamicsCount = program->fileSize / sizeof(struct System_ELF64Assembly_DynamicEntry);
        }

#if DEBUG == DEBUG_System_ELFAssembly
        System_Console_writeLine("ELFProgramHeader({0:uint}): type {1:string}, flags {2:uint32:bin}, offset {3:uint:hex}, virtualAddress {4:uint:hex}, physicalAddress {5:uint:hex}, fileSize {6:uint:hex}, memorySize {7:uint:hex}", 8, i,
            System_ELFAssembly_ProgramType_toString(program->type), program->flags, program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
#endif
    }
    System_ELF64Assembly_Symbol dynamicSymbols = null;
    System_String8 dynamicStrings = null;
    System_ELF64Assembly_Relocation GOT_relocation = null, PLT_relocation = null;
    System_Size GOT_relocationCount = 0, PLT_relocationCount = 0;
    System_Size * PLT = null;
    for (i = 0; i < dynamicsCount; ++i) {
        System_ELF64Assembly_DynamicEntry dynamic = dynamics + i;
        if (dynamic->tag == System_ELFAssembly_DynamicType_STRTAB) {
            dynamic->value = (System_Size)base + dynamic->value;
            dynamicStrings = (System_String8)(dynamic->value); 
        }
        if (dynamic->tag == System_ELFAssembly_DynamicType_SYMTAB) {
            dynamic->value = (System_Size)base + dynamic->value;
            dynamicSymbols = (System_ELF64Assembly_Symbol)(dynamic->value); 
        }
        //if (dynamic->tag == System_ELFAssembly_DynamicType_SYMENT)
        if (dynamic->tag == System_ELFAssembly_DynamicType_RELA) {
            dynamic->value = (System_Size)base + dynamic->value;
            GOT_relocation = (System_ELF64Assembly_Relocation)(dynamic->value); 
        }
        // if (dynamic->tag == System_ELFAssembly_DynamicType_RELAENT) 
        if (dynamic->tag == System_ELFAssembly_DynamicType_RELASZ)
            GOT_relocationCount = !dynamic->value ? null : dynamic->value / sizeof(struct System_ELF64Assembly_Relocation);

        if (dynamic->tag == System_ELFAssembly_DynamicType_JMPREL) {
            dynamic->value = (System_Size)base + dynamic->value;
            PLT_relocation = (System_ELF64Assembly_Relocation)(dynamic->value);
        }
        if (dynamic->tag == System_ELFAssembly_DynamicType_PLTRELSZ)
            PLT_relocationCount = !dynamic->value ? null : dynamic->value / sizeof(struct System_ELF64Assembly_Relocation);

        if (dynamic->tag == System_ELFAssembly_DynamicType_PLTGOT) {
            dynamic->value = (System_Size)base + dynamic->value;
            PLT = (System_Size *)(dynamic->value);
        }
    }
#if DEBUG == DEBUG_System_ELFAssembly
    for (i = 0; i < dynamicsCount; ++i) {
        System_ELF64Assembly_DynamicEntry dynamic = dynamics + i;
        switch(dynamic->tag) {
        case System_ELFAssembly_DynamicType_STRTAB:
        case System_ELFAssembly_DynamicType_SYMTAB:
        case System_ELFAssembly_DynamicType_PLTGOT:
        case System_ELFAssembly_DynamicType_JMPREL:
        case System_ELFAssembly_DynamicType_RELA:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value 0x{1:uint:hex}", 2, System_ELFAssembly_DynamicType_toString(dynamic->tag), dynamic->value);
            break;                
        case System_ELFAssembly_DynamicType_NEEDED:
        case System_ELFAssembly_DynamicType_SONAME:
            if (dynamicStrings) {
                System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:string}", 2, System_ELFAssembly_DynamicType_toString(dynamic->tag), dynamicStrings + dynamic->value);
                break;
            }
        default:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, System_ELFAssembly_DynamicType_toString(dynamic->tag), dynamic->value);
            break;
        }
    }
#endif
    if (GOT_relocation)
        for (i = 0; i < GOT_relocationCount; ++i)
            System_Runtime_relocate(base, GOT_relocation + i, dynamicSymbols, dynamicStrings);
    if (PLT_relocation)
        for (i = 0; i < PLT_relocationCount; ++i)
            System_Runtime_relocate(base, PLT_relocation + i, dynamicSymbols, dynamicStrings);
}

void System_Runtime_readlink(System_ELF64Assembly assembly, System_Var base) {
    System_Size i;

    assembly->link = base;

    /* Read ELFAssembly_Header */
    System_ELF64Assembly_Header header = (System_ELF64Assembly_Header)base;
    if (!System_String8_equalsSubstring(header->magic, System_ELFAssembly_Magic, 4)) {
        System_Console_writeLine__string("NOELF");
        return; /* TODO throw */
    }
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("ELFHeader: type {0:uint16}, machine {1:uint16}, version {2:uint32}, entryPoint 0x{3:uint:hex}, size {4:uint16}", 5,
        header->type, header->machine, header->version, header->entryPoint, header->size);
#endif
    
    /* Read ELFAssembly_ProgramHeaders */
    System_ELF64Assembly_ProgramHeader programs = (System_ELF64Assembly_ProgramHeader)(base + header->programHeaderOffset);
    for (i = 0; i < 32 && i < header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)programs + (i * header->programHeaderSize));

        if (program->type == System_ELFAssembly_ProgramType_Dynamic) {
            assembly->dynamics = (System_ELF64Assembly_DynamicEntry)(base + program->virtualAddress);
            assembly->dynamicsCount = program->fileSize / sizeof(struct System_ELF64Assembly_DynamicEntry);
        }

#if DEBUG == DEBUG_System_ELFAssembly
        System_Console_writeLine("ELFProgramHeader({0:uint}): type {1:string}, flags {2:uint32:bin}, offset {3:uint:hex}, virtualAddress {4:uint:hex}, physicalAddress {5:uint:hex}, fileSize {6:uint:hex}, memorySize {7:uint:hex}", 8, i,
            System_ELFAssembly_ProgramType_toString(program->type), program->flags, program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
#endif
    }
    /* Read all ELFAssembly_SectionHeaders */
    System_ELF64Assembly_SectionHeader sections = assembly->sections = (System_ELF64Assembly_SectionHeader)(assembly->link + header->sectionHeaderOffset);
    System_ELF64Assembly_SectionHeader stringSection = (System_ELF64Assembly_SectionHeader)((System_Var)sections + (header->stringSectionIndex * header->sectionHeaderSize));
    assembly->sectionsStrings = (System_String8)(assembly->link + stringSection->offset);
    for (System_Size i = 0; i < header->sectionHeaderCount; ++i) {
        System_ELF64Assembly_SectionHeader section = (System_ELF64Assembly_SectionHeader)((System_Var)sections + (i * header->sectionHeaderSize));

        if (System_String8_equals(assembly->sectionsStrings + section->name, ".dynsym"))
            assembly->dynamicSymbolsCount = section->size / sizeof(struct System_ELF64Assembly_Symbol);

#if DEBUG == DEBUG_System_ELFAssembly
        System_Console_writeLine("ELFSectionHeader({0:uint}): name {1:string}, type {2:string}, flags {3:uint:bin}, offset {4:uint:hex}, size {5:uint:hex}, virtualAddress {6:uint:hex}, link {7:uint32}", 8, i,
            assembly->sectionsStrings + section->name, System_enum_getName(typeof(System_ELFAssembly_SectionType), section->type), 
            section->flags, section->offset, section->size, section->virtualAddress, section->link);
#endif
    }

    for (i = 0; i < assembly->dynamicsCount; ++i) {
        System_ELF64Assembly_DynamicEntry dynamic = assembly->dynamics + i;
        if (dynamic->tag == System_ELFAssembly_DynamicType_STRTAB) {
            assembly->dynamicStrings = (System_String8)(base + dynamic->value); 
        }
        if (dynamic->tag == System_ELFAssembly_DynamicType_SYMTAB) {
            assembly->dynamicSymbols = (System_ELF64Assembly_Symbol)(base + dynamic->value); 
        }
        //if (dynamic->tag == System_ELFAssembly_DynamicType_SYMENT)
        if (dynamic->tag == System_ELFAssembly_DynamicType_RELA) {
            assembly->GOT_relocation = (System_ELF64Assembly_Relocation)(base + dynamic->value); 
        }
        // if (dynamic->tag == System_ELFAssembly_DynamicType_RELAENT) 
        if (dynamic->tag == System_ELFAssembly_DynamicType_RELASZ)
            assembly->GOT_relocationCount = !dynamic->value ? null : dynamic->value / sizeof(struct System_ELF64Assembly_Relocation);

        if (dynamic->tag == System_ELFAssembly_DynamicType_JMPREL) {
            assembly->PLT_relocation = (System_ELF64Assembly_Relocation)(base + dynamic->value);
        }
        if (dynamic->tag == System_ELFAssembly_DynamicType_PLTRELSZ)
            assembly->PLT_relocationCount = !dynamic->value ? null : dynamic->value / sizeof(struct System_ELF64Assembly_Relocation);

        if (dynamic->tag == System_ELFAssembly_DynamicType_PLTGOT) {
            assembly->PLT = (System_Size *)(base + dynamic->value);
        }
    }
#if DEBUG == DEBUG_System_ELFAssembly
    for (i = 0; i < assembly->dynamicsCount; ++i) {
        System_ELF64Assembly_DynamicEntry dynamic = assembly->dynamics + i;
        switch(dynamic->tag) {
        case System_ELFAssembly_DynamicType_STRTAB:
        case System_ELFAssembly_DynamicType_SYMTAB:
        case System_ELFAssembly_DynamicType_PLTGOT:
        case System_ELFAssembly_DynamicType_JMPREL:
        case System_ELFAssembly_DynamicType_RELA:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value 0x{1:uint:hex}", 2, System_ELFAssembly_DynamicType_toString(dynamic->tag), dynamic->value);
            break;                
        case System_ELFAssembly_DynamicType_NEEDED:
        case System_ELFAssembly_DynamicType_SONAME:
            if (assembly->dynamicStrings) {
                System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:string}", 2, System_ELFAssembly_DynamicType_toString(dynamic->tag), assembly->dynamicStrings + dynamic->value);
                break;
            }
        default:
            System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, System_ELFAssembly_DynamicType_toString(dynamic->tag), dynamic->value);
            break;
        }
    }
    for (i = 0; i < assembly->dynamicSymbolsCount; ++i) {
        System_ELF64Assembly_Symbol symbol = assembly->dynamicSymbols + i;
        System_Console_writeLine("ELFSymbol: bind {1:string}, type {2:string}, other {3:uint8:hex}, sectionIndex {4:uint16}, value {5:uint64:hex}, size {6:uint64}, {0:string}", 7, 
            assembly->dynamicStrings + symbol->name, System_ELFAssembly_SymbolBinding_toString(System_ELFAssembly_Symbol_BIND(symbol->info)), 
            System_ELFAssembly_SymbolType_toString(System_ELFAssembly_Symbol_TYPE(symbol->info)),
            symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
    }
#endif

    System_ELF64Assembly_loaded[System_ELF64Assembly_loadedCount++] = assembly;
}

int System_Runtime_main(int argc, char  * argv[]) {

    /* Modify auxv on stack */
    System_Size * stack = System_Runtime_stack;
    stack += argc + 2;
    while (*stack) ++stack;

    System_String8 name = null;
    System_Var base = null, exec = null;
    System_Size auxc = 0;
    System_Environment_AuxValue auxv = (System_Environment_AuxValue)(++stack);
    System_Var vdso = null;
    for (; auxv[auxc].type; ++auxc, stack += 2) {
        System_Environment_AuxValue aux = auxv + auxc;
        
        if (aux->type == System_Environment_AuxType_SYSINFO_EHDR)
            vdso = (System_Var)aux->value;

        if (aux->type == System_Environment_AuxType_PAGESZ) 
            System_Runtime_pageSize = aux->value;

        if (aux->type == System_Environment_AuxType_EXECFN)
            name = (System_String8)aux->value;

        if (aux->type == System_Environment_AuxType_BASE)
            base = (System_Var)aux->value;

        if (aux->type == System_Environment_AuxType_PHDR)
            exec = (System_Var)ROUNDDOWN(aux->value, 4096);

        if (aux->type == System_Environment_AuxType_RANDOM) {
            aux->type = System_Environment_AuxType_INTERP;   
            aux->value = true;
        }
    }

    if (!base) {
        if (argc == 1) {
            System_Console_writeLine__string("Usage: System.Interpreter filename");
            return false; 
        }
        name = argv[1];
        if (!exec) return false; // throw
        base = exec;
        exec = null;

        /* Remove argv[0] */
        *(++System_Runtime_stack) = --argc;
        
#if DEBUG == DEBUG_System_ELFAssembly
        System_Console_writeLine__string("This is System.Interpreter as command");
#endif
    }
#if DEBUG == DEBUG_System_ELFAssembly
    else System_Console_writeLine__string("This is System.Interpreter as INTERP");
#endif

    System_Runtime_selflink(base);

    System_ELF64Assembly assembly_vdso = System_Memory_allocClass(typeof(System_ELF64Assembly));
    System_Runtime_readlink(assembly_vdso, vdso);

    System_ELF64Assembly assembly = (System_ELF64Assembly)System_Memory_allocClass(typeof(System_ELF64Assembly));
#if DEBUG == DEBUG_System_ELFAssembly
    System_ELF64Assembly_read__print(assembly, name, true);
#else
    System_ELF64Assembly_read__print(assembly, name, false);
#endif
    System_ELF64Assembly_link(assembly);

    System_ELF64Assembly assembly1;
    System_ELF64Assembly_Symbol symbol1;
    System_Size * symbol1_value;

    symbol1 = System_ELF64Assembly_getSymbol("System_ELF64Assembly_loadedCount", &assembly1);
    if (symbol1) {
        symbol1_value = (System_Size *)(assembly1->link + symbol1->value);
        *symbol1_value = System_ELF64Assembly_loadedCount;
    }

    symbol1 = System_ELF64Assembly_getSymbol("System_ELF64Assembly_loaded", &assembly1);
    if (symbol1) {
        symbol1_value = (System_Size *)(assembly1->link + symbol1->value);
        for (System_Size i = 0; i < System_ELF64Assembly_loadedCount; ++i, ++symbol1_value)
            *symbol1_value = (System_Size)System_ELF64Assembly_loaded[i];
    }

    extern System_Var  System_Memory_ProcessVars[];
    symbol1 = System_ELF64Assembly_getSymbol("System_Memory_ProcessVars", &assembly1);
    if (symbol1) {
        symbol1_value = (System_Size *)(assembly1->link + symbol1->value);
        for (System_Size i = 0; i < 4; ++i, ++symbol1_value) /* TODO: sizeof_array(System_Memory_ProcessVars) */
            *symbol1_value = (System_Size)System_Memory_ProcessVars[i];
    }

    System_Var entry = assembly->link + assembly->header->entryPoint;
    // System_Var entry = (System_Var)System_Environment_AuxValues[System_Environment_AuxType_ENTRY];
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("INTERP JUMPING to 0x{0:uint:hex}, with stack on 0x{1:uint:hex}", 2, entry, System_Runtime_stack);
#endif

    System_Var tls = System_Thread_createStorage();
    if (tls) System_Thread_setRegister(tls);

    register System_Var entry0 __asm__("r11") = entry;
    // register System_Var exit0 __asm__("rdx") = ;
    register System_Var stack0 __asm__("rsp") = System_Runtime_stack;
    
    __asm__ __volatile__( "jmp *%%r11" : : : "memory" );

}
