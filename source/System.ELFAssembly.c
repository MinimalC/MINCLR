/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_Environment)
#include <min/System.Environment.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_File)
#include <min/System.File.h>
#endif
#if !defined(have_System_ELFAssembly)
#include <min/System.ELFAssembly.h>
#endif
#if !defined(code_System_ELF32Assembly)
#define code_System_ELF32Assembly

#endif
#if !defined(code_System_ELF64Assembly)
#define code_System_ELF64Assembly

#define ROUND(X,ALIGN)  (((X) + (ALIGN - 1)) & ~(ALIGN - 1))
#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

struct System_Type System_ELF64AssemblyType = { .base = { .type = typeof(System_Type), }, 
    .name = "ELF64Assembly", 
    .size = sizeof(struct System_ELF64Assembly), 
    .baseType = typeof(System_Object),
};

System_ELF64Assembly  new_System_ELF64Assembly() {
    System_ELF64Assembly that = (System_ELF64Assembly)System_Memory_allocClass(typeof(System_ELF64Assembly));
    //base_System_ELF64Assembly_init(that);
    return that;
}

void System_ELF64Assembly_read__print(System_ELF64Assembly assembly, System_String8 name, System_Bool print) {

    if (assembly->name) return; // throw

    assembly->name = name;

    if (!assembly->buffer) {
        struct System_File file; System_Stack_clear(file);
        if (!stack_System_File_open(&file, name, System_File_Mode_readOnly)) return;
        System_Size fileSize = base_System_File_get_Length(&file);

        assembly->buffer = System_Memory_allocArray(typeof(System_Char8), fileSize);
        base_System_File_read(&file, assembly->buffer, fileSize);
        base_System_File_close(&file);
    }

    /* Read ELFAssembly_Header */
    System_ELF64Assembly_Header header = assembly->header = (System_ELF64Assembly_Header)assembly->buffer;
    if (!System_String8_equalsSubstring(header->magic, System_ELFAssembly_Magic, 4)) {
        if (print) System_Console_writeLine__string("NOELF");
        return; /* TODO throw */
    }
    if (print == 2) {
        System_Console_write("ELF_Header: type {0:uint16}, machine {1:uint16}, version {2:uint32}, entryPoint 0x{3:uint:hex}, size {4:uint16}", 5,
            header->type, header->machine, header->version, header->entryPoint, header->size);
        System_Console_write(", class {0:uint8}, endianess {1:uint8}, elfVersion {2:uint8}, abi {3:uint8}", 4,
            header->class, header->endianess, header->elfVersion, header->abi);
        System_Console_write(", programHeaderOffset {0:uint:hex}, programHeaderSize {1:uint16}, programHeaderCount {2:uint16}", 3,
            header->programHeaderOffset, header->programHeaderSize, header->programHeaderCount);
        System_Console_writeLine(", sectionHeaderOffset {0:uint:hex}, sectionHeaderSize {1:uint16}, sectionHeaderCount {2:uint16}", 3,
            header->sectionHeaderOffset, header->sectionHeaderSize, header->sectionHeaderCount);
    }
    else if (print) {
        System_Console_write("ELF_Header: type {0:string}, machine {1:string}, version {2:uint32}, entryPoint 0x{3:uint:hex}, size {4:uint16}", 5,
            System_enum_getName(typeof(System_ELFAssembly_AssemblyType), header->type),
            System_enum_getName(typeof(System_ELFAssembly_Machine), header->machine),
            header->version, header->entryPoint, header->size);
        System_Console_writeLine(", class {0:uint8}, endianess {1:uint8}, elfVersion {2:uint8}, abi {3:string}", 4,
            header->class, header->endianess, header->elfVersion,
            System_enum_getName(typeof(System_ELFAssembly_ABI), header->abi));
    }
    
    /* Read ELFAssembly_ProgramHeaders */
    System_ELF64Assembly_ProgramHeader programs = assembly->programs = (System_ELF64Assembly_ProgramHeader)(assembly->buffer + header->programHeaderOffset);
    assembly->dynamics = null;
    assembly->dynamicsCount = 0;
    for (System_Size i = 0; i < 32 && i < header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)programs + (i * header->programHeaderSize));

        if (program->type == System_ELFAssembly_ProgramType_Dynamic) {
            assembly->dynamics = (System_ELF64Assembly_DynamicEntry)(assembly->buffer + program->offset);
            assembly->dynamicsCount = program->fileSize / sizeof(struct System_ELFAssembly_DynamicEntry);
        }

        if (print == 2) {
        System_Console_writeLine("ELF_ProgramHeader({0:uint}): type {1:uint32}, flags {2:uint32:bin}, offset {3:uint:hex}, virtualAddress {4:uint:hex}, physicalAddress {5:uint:hex}, fileSize {6:uint:hex}, memorySize {7:uint:hex}", 8, i,
            program->type, program->flags, program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
        }
        else if (print) {
        System_Console_writeLine("ELF_ProgramHeader({0:uint}): type {1:string}, flags {2:uint32:bin}, offset {3:uint:hex}, virtualAddress {4:uint:hex}, physicalAddress {5:uint:hex}, fileSize {6:uint:hex}, memorySize {7:uint:hex}", 8, i,
            System_enum_getName(typeof(System_ELFAssembly_ProgramType), program->type),
            program->flags, program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
        }
    }

    /* Read all ELFAssembly_SectionHeaders */
    System_ELF64Assembly_SectionHeader sections = assembly->sections = (System_ELF64Assembly_SectionHeader)(assembly->buffer + header->sectionHeaderOffset);
    System_ELF64Assembly_SectionHeader stringSection = (System_ELF64Assembly_SectionHeader)((System_Var)sections + (header->stringSectionIndex * header->sectionHeaderSize));
    assembly->sectionsStrings = (System_String8)(assembly->buffer + stringSection->offset);
    assembly->symbols = null;
    assembly->symbolsCount = 0;
    assembly->symbolStrings = null;
    assembly->dynamicSymbolsCount = 0;
    for (System_Size i = 0; i < header->sectionHeaderCount; ++i) {
        System_ELF64Assembly_SectionHeader section = (System_ELF64Assembly_SectionHeader)((System_Var)sections + (i * header->sectionHeaderSize));

        if (System_String8_equals(assembly->sectionsStrings + section->name, ".symtab")) {
            assembly->symbols = (System_ELF64Assembly_SymbolEntry)(assembly->buffer + section->offset);
            assembly->symbolsCount = section->size / sizeof(struct System_ELF64Assembly_SymbolEntry);
            System_ELF64Assembly_SectionHeader stringSection1 = (System_ELF64Assembly_SectionHeader)(assembly->sections + section->link);
            assembly->symbolStrings = (System_String8)(assembly->buffer + stringSection1->offset);
        }
        if (System_String8_equals(assembly->sectionsStrings + section->name, ".dynsym"))
            assembly->dynamicSymbolsCount = section->size / sizeof(struct System_ELF64Assembly_SymbolEntry);

        /* Write all ELFAssembly_SectionHeaders */
        if (print == 2) {
            System_Console_writeLine("ELF_SectionHeader({0:uint}): name {1:string}, type {2:uint32}, flags {3:uint:bin}, offset {4:uint:hex}, size {5:uint:hex}, virtualAddress {6:uint:hex}, link {7:uint32}", 8, i,
                assembly->sectionsStrings + section->name, section->type, section->flags, section->offset, section->size, section->virtualAddress, section->link);
        }
        else if (print) {
            System_Console_writeLine("ELF_SectionHeader({0:uint}): name {1:string}, type {2:string}, flags {3:uint:bin}, offset {4:uint:hex}, size {5:uint:hex}, virtualAddress {6:uint:hex}, link {7:uint32}", 8, i,
                assembly->sectionsStrings + section->name, System_enum_getName(typeof(System_ELFAssembly_SectionType), section->type), 
                section->flags, section->offset, section->size, section->virtualAddress, section->link);
        }
    }

    if (assembly->dynamics) {
        for (System_Size i = 0; i < assembly->dynamicsCount; ++i) {
            System_ELF64Assembly_DynamicEntry dynamic = assembly->dynamics + i;
            switch (dynamic->tag) {
            case System_ELFAssembly_DynamicType_STRTAB: 
                assembly->dynamicStrings = (System_String8)(assembly->buffer + dynamic->value); 
                break;
            case System_ELFAssembly_DynamicType_SYMTAB: 
                assembly->dynamicSymbols = (System_ELF64Assembly_SymbolEntry)(assembly->buffer + dynamic->value); 
                break;
            }
        }
        assembly->neededCount = 0;
        for (System_Size i = 0; i < assembly->dynamicsCount; ++i) {
            System_ELF64Assembly_DynamicEntry dynamic = assembly->dynamics + i;
            switch (dynamic->tag) {
            case System_ELFAssembly_DynamicType_NEEDED:
                assembly->needed[assembly->neededCount++] = assembly->dynamicStrings + dynamic->value; 
                break;
            }
        }
        if (print) {
            for (System_Size i = 0; i < assembly->dynamicsCount; ++i) {
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
            System_Console_writeLine__string("DYNAMIC SYMBOLS");
            for (System_Size i = 0; i < assembly->dynamicSymbolsCount; ++i) {
                System_ELF64Assembly_SymbolEntry symbol = assembly->dynamicSymbols + i;
                System_Console_writeLine("ELFSymbol: bind {1:string}, type {2:string}, other {3:uint8:hex}, sectionIndex {4:uint16}, value {5:uint64:hex}, size {6:uint64}, {0:string}", 7, 
                    assembly->dynamicStrings + symbol->name, System_ELFAssembly_SymbolBinding_toString(System_ELFAssembly_SymbolEntry_BIND(symbol->info)), 
                    System_ELFAssembly_SymbolType_toString(System_ELFAssembly_SymbolEntry_TYPE(symbol->info)),
                    symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
            }
        }
    }
    if (print) {
        System_Console_writeLine__string("SYMBOLS");
        for (System_Size i = 0; i < assembly->symbolsCount; ++i) {
            System_ELF64Assembly_SymbolEntry symbol = assembly->symbols + i;
            System_Console_writeLine("ELFSymbol: bind {1:string}, type {2:string}, other {3:uint8:hex}, sectionIndex {4:uint16}, value {5:uint64:hex}, size {6:uint64}, {0:string}", 7, 
                assembly->symbolStrings + symbol->name, System_ELFAssembly_SymbolBinding_toString(System_ELFAssembly_SymbolEntry_BIND(symbol->info)), 
                System_ELFAssembly_SymbolType_toString(System_ELFAssembly_SymbolEntry_TYPE(symbol->info)),
                symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
        }
    }
}

void System_ELF64Assembly_read(System_ELF64Assembly assembly, System_String8 name) {
    System_ELF64Assembly_read__print(assembly, name, false);
}

System_ELF64Assembly System_ELF64Assembly_loaded[64];

System_Size System_ELF64Assembly_loadedCount = 0;

System_ELF64Assembly_SectionHeader System_ELF64Assembly_getSection(System_ELF64Assembly assembly, System_String8 name) {

    for (System_Size i = 0; i < assembly->header->sectionHeaderCount; ++i) {
        System_ELF64Assembly_SectionHeader section = (System_ELF64Assembly_SectionHeader)((System_Var)assembly->sections + (i * assembly->header->sectionHeaderSize));

        if (System_String8_equals(assembly->sectionsStrings + section->name, name)) return section;
    }
    return null;
}

void System_ELF64Assembly_link(System_ELF64Assembly assembly) {

    if (!assembly->name) return; // throw

    // Now read and link other libraries first
    for (System_Size i = 0; i < assembly->neededCount; ++i) {
        System_Bool need = true;
        for (System_Size l = 0; l < System_ELF64Assembly_loadedCount; ++l) {
            if (System_String8_endsWith(System_ELF64Assembly_loaded[l]->name, assembly->needed[i])) {
                need = false;
                break;
            }
        }
        if (need) {
            System_ELF64Assembly required = (System_ELF64Assembly)System_Memory_allocClass(typeof(System_ELF64Assembly));
#if DEBUG == DEBUG_System_ELFAssembly
            System_Console_writeLine("ELF NEEDED({0:uint}): {1:string}", 2, i, assembly->needed[i]);
            System_ELF64Assembly_read__print(required, assembly->needed[i], true);
#else
            System_ELF64Assembly_read__print(required, assembly->needed[i], false);
#endif
            System_ELF64Assembly_link(required);
        }
    }

    System_Size load_size = 0;
    for (System_Size i = 0; i < 32 && i < assembly->header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)assembly->programs + (i * assembly->header->programHeaderSize));
        if (program->type == System_ELFAssembly_ProgramType_Loadable) {
            if (load_size < program->virtualAddress + program->memorySize) {
                load_size = program->virtualAddress + program->memorySize; 
#if DEBUG == DEBUG_System_ELFAssembly
                System_Console_writeLine("Loadable virtualAddress: {1:uint:hex} + memorySize: {2:uint:hex} = load_size: {0:uint:hex}", 3, load_size, program->virtualAddress, program->memorySize);
#endif
            }
        }
    }
    /* for (System_Size i = 0; i < assembly->header->sectionHeaderCount; ++i) {
        System_ELF64Assembly_SectionHeader section = (System_ELF64Assembly_SectionHeader)((System_Var)assembly->sections + (i * assembly->header->sectionHeaderSize));

        if (System_String8_equals(assembly->sectionsStrings + section->name, ".bss")) {
            if (load_size < section->virtualAddress + section->size) {
                load_size = section->virtualAddress + section->size; 
#if DEBUG == DEBUG_System_ELFAssembly
                System_Console_writeLine(".bss virtualAddress: {1:uint:hex} + memorySize: {2:uint:hex} = load_size: {0:uint:hex}", 3, load_size, section->virtualAddress, section->size);
#endif
            }
            continue;
        }
    } */
    load_size = ROUND(load_size, 4096);

    assembly->link = System_Syscall_mmap(load_size, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous);
    if (!assembly->link) return; // TODO: throw
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("final load_size: {0:uint:hex} linked at: {1:uint:hex}", 2, load_size, assembly->link);
#endif

    for (System_Size i = 0; i < 32 && i < assembly->header->programHeaderCount; ++i) {
        System_ELF64Assembly_ProgramHeader program = (System_ELF64Assembly_ProgramHeader)((System_Var)assembly->programs + (i * assembly->header->programHeaderSize));

        if (program->type == System_ELFAssembly_ProgramType_Loadable) {
            System_Memory_copyTo((System_Var)assembly->header + program->offset, program->fileSize, assembly->link + program->virtualAddress);

            System_Memory_PageFlags protection = System_Memory_PageFlags_None;
            if (enum_hasFlag(program->flags, System_ELFAssembly_ProgramFlags_Readable))
                protection |= System_Memory_PageFlags_Read;
            if (enum_hasFlag(program->flags, System_ELFAssembly_ProgramFlags_Writable))
                protection |= System_Memory_PageFlags_Write;
            if (enum_hasFlag(program->flags, System_ELFAssembly_ProgramFlags_Executable))
                protection |= System_Memory_PageFlags_Execute;

            System_Syscall_mprotect(assembly->link + program->virtualAddress, program->memorySize, protection);
        }
        if (program->type == System_ELFAssembly_ProgramType_Dynamic) {
            assembly->dynamics = (System_ELF64Assembly_DynamicEntry)(assembly->link + program->virtualAddress);
            assembly->dynamicsCount = program->fileSize / sizeof(struct System_ELFAssembly_DynamicEntry);
        }
    }
    if (assembly->dynamics) {
        for (System_Size i = 0; i < assembly->dynamicsCount; ++i) {
            System_ELF64Assembly_DynamicEntry dynamic = assembly->dynamics + i;

            if (dynamic->tag == System_ELFAssembly_DynamicType_STRTAB) {
                dynamic->value = (System_Size)assembly->link + dynamic->value;
                assembly->dynamicStrings = (System_String8)(dynamic->value);
            }
            if (dynamic->tag == System_ELFAssembly_DynamicType_SYMTAB) {
                dynamic->value = (System_Size)assembly->link + dynamic->value;
                assembly->dynamicSymbols = (System_ELF64Assembly_SymbolEntry)(dynamic->value);
            }
            // if (dynamic->tag == System_ELFAssembly_DynamicType_SYMENT) 
            if (dynamic->tag == System_ELFAssembly_DynamicType_RELA) {
                dynamic->value = (System_Size)assembly->link + dynamic->value;
                assembly->GOT_relocation = (System_ELF64Assembly_RelocationAddend)(dynamic->value);
            }
            // if (dynamic->tag == System_ELFAssembly_DynamicType_RELAENT) 
            if (dynamic->tag == System_ELFAssembly_DynamicType_RELASZ)
                assembly->GOT_relocationCount = !dynamic->value ? null : dynamic->value / sizeof(struct System_ELF64Assembly_RelocationAddend);
            
            if (dynamic->tag == System_ELFAssembly_DynamicType_JMPREL) {
                dynamic->value = (System_Size)assembly->link + dynamic->value;
                assembly->PLT_relocation = (System_ELF64Assembly_RelocationAddend)(dynamic->value);
            }
            if (dynamic->tag == System_ELFAssembly_DynamicType_PLTRELSZ)
                assembly->PLT_relocationCount = !dynamic->value ? null : dynamic->value / sizeof(struct System_ELF64Assembly_RelocationAddend);

            if (dynamic->tag == System_ELFAssembly_DynamicType_PLTGOT) {
                dynamic->value = (System_Size)assembly->link + dynamic->value;
                assembly->PLT = (System_Size *)(dynamic->value);
            }
        }

#if DEBUG == DEBUG_System_ELFAssembly
        for (System_Size i = 0; i < assembly->dynamicsCount; ++i) {
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

        System_Console_writeLine__string("GOT");
#endif
        for (System_Size i = 0; i < assembly->GOT_relocationCount; ++i)
            System_ELF64Assembly_relocate(assembly, assembly->GOT_relocation + i);

#if DEBUG == DEBUG_System_ELFAssembly
        System_Console_writeLine__string("PLT");
#endif
        for (System_Size i = 0; i < assembly->PLT_relocationCount; ++i) 
            System_ELF64Assembly_relocate(assembly, assembly->PLT_relocation + i);

        if (assembly->PLT) {
            if (!System_ELF64Assembly_loadedCount) {
                
                assembly->PLT[1] = (System_Size)assembly;
                assembly->PLT[2] = (System_Size)System_ELF64Assembly_jump;
            }
#if DEBUG == DEBUG_System_ELFAssembly
            System_Console_writeLine("ELF GLOBAL_OFFSET_TABLE: {0:uint:hex}, [0] {1:uint:hex}, [1] {2:uint:hex}, [2] {3:uint:hex}", 4, assembly->PLT, assembly->PLT[0], assembly->PLT[1], assembly->PLT[2]);
#endif
        }
    }

    System_ELF64Assembly_loaded[System_ELF64Assembly_loadedCount++] = assembly;
}

System_ELF64Assembly_SymbolEntry System_ELF64Assembly_getSymbol(System_String8 name, System_ELF64Assembly * out_assembly) {
    Debug_assert(name);

    for (System_Size l = 0; l < System_ELF64Assembly_loadedCount; ++l) {
        System_ELF64Assembly assembly = System_ELF64Assembly_loaded[l];
        if (!assembly->symbols) continue;
        if (!assembly->symbolStrings) continue;
    for (System_Size i = 0; i < assembly->symbolsCount; ++i) {
        System_ELF64Assembly_SymbolEntry symbol = assembly->symbols + i;
        if (!symbol->sectionIndex || !symbol->value) continue;
        if (System_String8_equals(assembly->symbolStrings + symbol->name, name)) {
            *out_assembly = assembly;
            return symbol;
        }
    } }
    *out_assembly = null;
    return null;
}

System_ELF64Assembly_SymbolEntry System_ELF64Assembly_getDynamicSymbol(System_String8 name, System_ELF64Assembly * out_assembly) {
    Debug_assert(name);

    for (System_Size l = 0; l < System_ELF64Assembly_loadedCount; ++l) {
        System_ELF64Assembly assembly = System_ELF64Assembly_loaded[l];
        if (!assembly->dynamicSymbols) continue;
        if (!assembly->dynamicStrings) continue;
    for (System_Size i = 0; i < assembly->dynamicSymbolsCount; ++i) {
        System_ELF64Assembly_SymbolEntry symbol = assembly->dynamicSymbols + i;
        if (!symbol->sectionIndex || !symbol->value) continue;
        if (System_String8_equals(assembly->dynamicStrings + symbol->name, name)) {
            *out_assembly = assembly;
            return symbol;
        }
    } }
    *out_assembly = null;
    return null;
}

System_Var System_ELF64Assembly_nothing(void) { return null; }

System_Var System_ELF64Assembly_resolve(System_ELF64Assembly assembly, System_UInt64 relocationOffset) {
    if (!assembly->PLT_relocation) {
        goto error;
    }
    if (!relocationOffset) {
        goto error;
    }
    System_ELF64Assembly_RelocationAddend relocation = (System_Var)assembly->PLT_relocation + relocationOffset;
    if (!assembly->dynamicSymbols) {
        goto error;
    }
    if (!relocation->symbol) {
        goto error;
    }
    System_ELF64Assembly_SymbolEntry symbol =  assembly->dynamicSymbols + relocation->symbol;
    if (!symbol) {
        goto error;
    }
    if (!assembly->dynamicStrings) {
        goto error;
    }
    System_String8 name = assembly->dynamicStrings + symbol->name;
    if (System_String8_isNullOrEmpty(name)) {
        goto error;
    }
    System_ELF64Assembly assembly1 = null;
    System_ELF64Assembly_SymbolEntry symbol1 = System_ELF64Assembly_getDynamicSymbol(name, &assembly1);
    if (!symbol1) {
        
    }
    if (!assembly->link) {
        goto error;
    }
    if (!relocation->offset) {
        goto error;
    }
    System_Var * address = (System_Var *)(assembly->link + relocation->offset), old = *address;

    if (assembly1 && symbol1) {
        *address = assembly1->link + symbol1->value;
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("ELFAssembly_resolve: {0:string}, {1:uint:hex} old => new {2:uint:hex}", 3, name, old, *address);
    System_Console_writeLine("   ELFSymbol1: bind {1:string}, type {2:string}, other {3:uint8:hex}, sectionIndex {4:uint16}, value {5:uint64:hex}, size {6:uint64}, {0:string}", 7, 
        assembly1->dynamicStrings + symbol1->name, System_ELFAssembly_SymbolBinding_toString(System_ELFAssembly_SymbolEntry_BIND(symbol1->info)), 
        System_ELFAssembly_SymbolType_toString(System_ELFAssembly_SymbolEntry_TYPE(symbol1->info)),
        symbol1->other, symbol1->sectionIndex, symbol1->value, symbol1->size);
#endif
    }
    else {
        *address = assembly->link + symbol->value;
#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("ELFAssembly_resolve: {0:string}, {1:uint:hex} old => new {2:uint:hex}", 3, name, old, *address);
    System_Console_writeLine("   ELFSymbol: bind {1:string}, type {2:string}, other {3:uint8:hex}, sectionIndex {4:uint16}, value {5:uint64:hex}, size {6:uint64}, {0:string}", 7, 
        assembly->dynamicStrings + symbol->name, System_ELFAssembly_SymbolBinding_toString(System_ELFAssembly_SymbolEntry_BIND(symbol->info)), 
        System_ELFAssembly_SymbolType_toString(System_ELFAssembly_SymbolEntry_TYPE(symbol->info)),
        symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
#endif
    }
    return *address;
error:
    return System_ELF64Assembly_nothing;
}

void System_ELF64Assembly_relocate(System_ELF64Assembly assembly, System_ELF64Assembly_RelocationAddend relocation) {

    if (!relocation->type) return;

    System_Size * address = (System_Size *)(assembly->link + relocation->offset), old = *address;

    System_ELF64Assembly_SymbolEntry symbol = !relocation->symbol ? null : assembly->dynamicSymbols + relocation->symbol;
    System_ELF64Assembly_SymbolEntry symbol1 = null;
    System_ELF64Assembly assembly1 = null;

    switch (relocation->type) {
    case System_ELFAssembly_AMD64Relocation_RELATIVE: 
        if (relocation->addend)
            *address = (System_Size)assembly->link + relocation->addend; 
        break;
    case System_ELFAssembly_AMD64Relocation_64: 
        symbol1 = System_ELF64Assembly_getDynamicSymbol(assembly->dynamicStrings + symbol->name, &assembly1);
        if (symbol1 && symbol1->value) 
            *address = (System_Size)assembly1->link + symbol1->value + relocation->addend;
        else if (symbol->value)
            *address = (System_Size)assembly->link + symbol->value + relocation->addend; 
        break;
    case System_ELFAssembly_AMD64Relocation_JUMP_SLOT:
    case System_ELFAssembly_AMD64Relocation_GLOB_DAT: 
        symbol1 = System_ELF64Assembly_getDynamicSymbol(assembly->dynamicStrings + symbol->name, &assembly1);
        if (symbol1 && symbol1->value) 
            *address = (System_Size)assembly1->link + symbol1->value;
        else if (symbol->value)
            *address = (System_Size)assembly->link + symbol->value; 
        else if (*address)
            *address += (System_Size)assembly->link;
        break;
    case System_ELFAssembly_AMD64Relocation_COPY: 
        symbol1 = System_ELF64Assembly_getDynamicSymbol(assembly->dynamicStrings + symbol->name, &assembly1);
        if (symbol1 && symbol1->value && symbol1->size) 
            System_Memory_copyTo(assembly1->link + symbol1->value, symbol1->size, address);
        else if (symbol->value && symbol->size)
            System_Memory_copyTo(assembly->link + symbol->value, symbol->size, address);
        break;
    case System_ELFAssembly_AMD64Relocation_32: 
        *address = (System_Size)assembly->link + (symbol->value & 0xFFFFFFFFUL); 
        break;
#if DEBUG
    default:
        System_Console_writeLine("UNLINKED ELFRelocation: offset {0:uint:hex}, type {1:string}, symbol {2:uint32}, addend {3:uint:hex}, old {4:uint:hex}", 5,
            relocation->offset, System_ELFAssembly_AMD64Relocation_toString(relocation->type), relocation->symbol, relocation->addend, old);
        break;
#endif    
    }

#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("ELFRelocation: offset {0:uint:hex}, type {1:string}, symbol {2:uint32}, addend {3:uint:hex}, old {4:uint:hex} => new {5:uint:hex}", 6,
        relocation->offset, System_ELFAssembly_AMD64Relocation_toString(relocation->type), relocation->symbol, relocation->addend, old, *address);

    if (symbol1) {
        System_Console_writeLine("      Symbol1: bind {1:string}, type {2:string}, other {3:uint8:hex}, sectionIndex {4:uint16}, value {5:uint64:hex}, size {6:uint64}, {0:string}", 7, 
            assembly1->dynamicStrings + symbol1->name, System_ELFAssembly_SymbolBinding_toString(System_ELFAssembly_SymbolEntry_BIND(symbol1->info)), 
            System_ELFAssembly_SymbolType_toString(System_ELFAssembly_SymbolEntry_TYPE(symbol1->info)),
            symbol1->other, symbol1->sectionIndex, symbol1->value, symbol1->size);
    }
    else if (symbol) {
        System_Console_writeLine("       Symbol: bind {1:string}, type {2:string}, other {3:uint8:hex}, sectionIndex {4:uint16}, value {5:uint64:hex}, size {6:uint64}, {0:string}", 7, 
            assembly->dynamicStrings + symbol->name, System_ELFAssembly_SymbolBinding_toString(System_ELFAssembly_SymbolEntry_BIND(symbol->info)), 
            System_ELFAssembly_SymbolType_toString(System_ELFAssembly_SymbolEntry_TYPE(symbol->info)),
            symbol->other, symbol->sectionIndex, symbol->value, symbol->size);
    }
#endif
}

System_String8 System_ELFAssembly_AMD64Relocation_toString(System_UInt32 value) {
    switch (value) {
    case System_ELFAssembly_AMD64Relocation_NONE: return "NONE";
    case System_ELFAssembly_AMD64Relocation_64: return "64";
    case System_ELFAssembly_AMD64Relocation_PC32: return "PC32";
    case System_ELFAssembly_AMD64Relocation_COPY: return "COPY";
    case System_ELFAssembly_AMD64Relocation_GLOB_DAT: return "GLOB_DAT";
    case System_ELFAssembly_AMD64Relocation_JUMP_SLOT: return "JUMP_SLOT";
    case System_ELFAssembly_AMD64Relocation_RELATIVE: return "RELATIVE";
    default: return "UNKNOWN";
    }
}

System_String8 System_ELFAssembly_SymbolBinding_toString(System_UInt8 value) {
    switch (value) {
    case System_ELFAssembly_SymbolBinding_LOCAL: return "LOCAL";
    case System_ELFAssembly_SymbolBinding_GLOBAL: return "GLOBAL";
    case System_ELFAssembly_SymbolBinding_WEAK: return "WEAK";
    default: return "UNKNOWN";
    }
}

System_String8 System_ELFAssembly_SymbolType_toString(System_UInt8 value) {
    switch (value) {
    case System_ELFAssembly_SymbolType_NULL: return "NULL";
    case System_ELFAssembly_SymbolType_OBJECT: return "OBJECT";
    case System_ELFAssembly_SymbolType_FUNCTION: return "FUNCTION";
    case System_ELFAssembly_SymbolType_SECTION: return "SECTION";
    case System_ELFAssembly_SymbolType_FILE: return "FILE";
    default: return "UNKNOWN";
    }    
}

System_String8 System_ELFAssembly_DynamicType_toString(System_ELFAssembly_DynamicType value) {
    switch (value) {
    case System_ELFAssembly_DynamicType_NULL: return "NULL";
    case System_ELFAssembly_DynamicType_NEEDED: return "NEEDED";
    case System_ELFAssembly_DynamicType_PLTRELSZ: return "PLTRELSZ";
    case System_ELFAssembly_DynamicType_PLTGOT: return "PLTGOT";
    case System_ELFAssembly_DynamicType_HASH: return "HASH";
    case System_ELFAssembly_DynamicType_STRTAB: return "STRTAB";
    case System_ELFAssembly_DynamicType_SYMTAB: return "SYMTAB";
    case System_ELFAssembly_DynamicType_RELA: return "RELA";
    case System_ELFAssembly_DynamicType_RELASZ: return "RELASZ";
    case System_ELFAssembly_DynamicType_RELAENT: return "RELAENT";
    case System_ELFAssembly_DynamicType_STRSZ: return "STRSZ";
    case System_ELFAssembly_DynamicType_SYMENT: return "SYMENT";
    case System_ELFAssembly_DynamicType_INIT: return "INIT";
    case System_ELFAssembly_DynamicType_FINI: return "FINI";
    case System_ELFAssembly_DynamicType_SONAME: return "SONAME";
    case System_ELFAssembly_DynamicType_RPATH: return "RPATH";
    case System_ELFAssembly_DynamicType_SYMBOLIC: return "SYMBOLIC";
    case System_ELFAssembly_DynamicType_REL: return "REL";
    case System_ELFAssembly_DynamicType_RELSZ: return "RELSZ";
    case System_ELFAssembly_DynamicType_RELENT: return "RELENT";
    case System_ELFAssembly_DynamicType_PLTREL: return "PLTREL";
    case System_ELFAssembly_DynamicType_DEBUG: return "DEBUG";
    case System_ELFAssembly_DynamicType_TEXTREL: return "TEXTREL";
    case System_ELFAssembly_DynamicType_JMPREL: return "JMPREL";
    case System_ELFAssembly_DynamicType_BIND_NOW: return "BIND_NOW";
    case System_ELFAssembly_DynamicType_INIT_ARRAY: return "INIT_ARRAY";
    case System_ELFAssembly_DynamicType_FINI_ARRAY: return "FINI_ARRAY";
    case System_ELFAssembly_DynamicType_INIT_ARRAYSZ: return "INIT_ARRAYSZ";
    case System_ELFAssembly_DynamicType_FINI_ARRAYSZ: return "FINI_ARRAYSZ";
    case System_ELFAssembly_DynamicType_RUNPATH: return "RUNPATH";
    case System_ELFAssembly_DynamicType_FLAGS: return "FLAGS";
    case System_ELFAssembly_DynamicType_ENCODING: return "ENCODING";
    case System_ELFAssembly_DynamicType_PREINIT_ARRAY: return "PREINIT_ARRAY";
    case System_ELFAssembly_DynamicType_PREINIT_ARRAYSZ: return "PREINIT_ARRAYSZ";
    case System_ELFAssembly_DynamicType_SYMTAB_SHNDX: return "SYMTAB_SHNDX";

    case System_ELFAssembly_DynamicType_NUM: return "NUM";

    case System_ELFAssembly_DynamicType_LOOS: return "LOOS";
    case System_ELFAssembly_DynamicType_HIOS: return "HIOS";
    case System_ELFAssembly_DynamicType_LOPROC: return "LOPROC";
    case System_ELFAssembly_DynamicType_HIPROC: return "HIPROC";

/*    case System_ELFAssembly_DynamicType_MIPSNUM: return "MIPSNUM";
    case System_ELFAssembly_DynamicType_VALRNGLO: return "VALRNGLO";
    case System_ELFAssembly_DynamicType_GNU_PRELINKED: return "GNU_PRELINKED";
    case System_ELFAssembly_DynamicType_GNU_CONFLICTSZ: return "GNU_CONFLICTSZ";
    case System_ELFAssembly_DynamicType_GNU_LIBLISTSZ: return "GNU_LIBLISTSZ";
    case System_ELFAssembly_DynamicType_CHECKSUM: return "CHECKSUM";
    case System_ELFAssembly_DynamicType_PLTPADSZ: return "PLTPADSZ";
    case System_ELFAssembly_DynamicType_MOVEENT: return "MOVEENT";
    case System_ELFAssembly_DynamicType_MOVESZ: return "MOVESZ";
    case System_ELFAssembly_DynamicType_FEATURE_1: return "FEATURE_1";
    case System_ELFAssembly_DynamicType_POSFLAG_1: return "POSFLAG_1";
    case System_ELFAssembly_DynamicType_SYMINSZ: return "SYMINSZ";
    case System_ELFAssembly_DynamicType_SYMINENT: return "SYMINENT";
    case System_ELFAssembly_DynamicType_VALRNGHI: return "VALRNGHI";
    case System_ELFAssembly_DynamicType_VALNUM: return "VALNUM";
    case System_ELFAssembly_DynamicType_ADDRRNGLO: return "ADDRRNGLO";
    case System_ELFAssembly_DynamicType_GNU_HASH: return "GNU_HASH";
    case System_ELFAssembly_DynamicType_TLSDESC_PLT: return "TLSDESC_PLT";
    case System_ELFAssembly_DynamicType_TLSDESC_GOT: return "TLSDESC_GOT";
    case System_ELFAssembly_DynamicType_GNU_CONFLICT: return "GNU_CONFLICT";
    case System_ELFAssembly_DynamicType_GNU_LIBLIST: return "GNU_LIBLIST";
    case System_ELFAssembly_DynamicType_CONFIG: return "CONFIG";
    case System_ELFAssembly_DynamicType_DEPAUDIT: return "DEPAUDIT";
    case System_ELFAssembly_DynamicType_AUDIT: return "AUDIT";
    case System_ELFAssembly_DynamicType_PLTPAD: return "PLTPAD";
    case System_ELFAssembly_DynamicType_MOVETAB: return "MOVETAB";
    case System_ELFAssembly_DynamicType_SYMINFO: return "SYMINFO";
    case System_ELFAssembly_DynamicType_ADDRRNGHI: return "ADDRRNGHI";
    case System_ELFAssembly_DynamicType_ADDRNUM: return "ADDRNUM";
    case System_ELFAssembly_DynamicType_VERSYM: return "VERSYM";
    case System_ELFAssembly_DynamicType_RELACOUNT: return "RELACOUNT";
    case System_ELFAssembly_DynamicType_RELCOUNT: return "RELCOUNT";
    case System_ELFAssembly_DynamicType_FLAGS_1: return "FLAGS_1";
    case System_ELFAssembly_DynamicType_VERDEF: return "VERDEF";
    case System_ELFAssembly_DynamicType_VERDEFNUM: return "VERDEFNUM";
    case System_ELFAssembly_DynamicType_VERNEED: return "VERNEED";
    case System_ELFAssembly_DynamicType_VERNEEDNUM: return "VERNEEDNUM";
    case System_ELFAssembly_DynamicType_VERSIONTAGNUM: return "VERSIONTAGNUM";
    case System_ELFAssembly_DynamicType_AUXILIARY: return "AUXILIARY";
    case System_ELFAssembly_DynamicType_FILTER: return "FILTER";
    case System_ELFAssembly_DynamicType_EXTRANUM: return "EXTRANUM";*/

    default: return "UNKNOWN";
    }    
}

#endif
#if !defined(code_System_ELFAssembly)
#define code_System_ELFAssembly

struct System_Type_FieldInfo  System_ELFAssembly_ABITypeFields[] = {
    { .name = "SysV", .value = System_ELFAssembly_ABI_SysV },
    { .name = "HPUX", .value = System_ELFAssembly_ABI_HPUX },
    { .name = "NetBSD", .value = System_ELFAssembly_ABI_NetBSD },
    { .name = "GNU", .value = System_ELFAssembly_ABI_GNU },
    { .name = "Linux", .value = System_ELFAssembly_ABI_Linux },
    { .name = "Solaris", .value = System_ELFAssembly_ABI_Solaris },
    { .name = "AIX", .value = System_ELFAssembly_ABI_AIX },
    { .name = "IRIX", .value = System_ELFAssembly_ABI_IRIX },
    { .name = "FreeBSD", .value = System_ELFAssembly_ABI_FreeBSD },
    { .name = "TRU64", .value = System_ELFAssembly_ABI_TRU64 },
    { .name = "Modesto", .value = System_ELFAssembly_ABI_Modesto },
    { .name = "OpenBSD", .value = System_ELFAssembly_ABI_OpenBSD },
    { .name = "ARM_EABI", .value = System_ELFAssembly_ABI_ARM_EABI },
    { .name = "ARM", .value = System_ELFAssembly_ABI_ARM },
    { .name = "Standalone", .value = System_ELFAssembly_ABI_Standalone },
};

struct System_Type System_ELFAssembly_ABIType = { .base = { .type = typeof(System_Type) },
    .name = "ABI",
    .size = sizeof(System_ELFAssembly_ABI),
	.fields = { 
        .value = &System_ELFAssembly_ABITypeFields, .length = sizeof_array(System_ELFAssembly_ABITypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_AssemblyTypeTypeFields[] = {
    { .name = "None", .value = System_ELFAssembly_AssemblyType_None },
    { .name = "Relocatable", .value = System_ELFAssembly_AssemblyType_Relocatable },
    { .name = "Executable", .value = System_ELFAssembly_AssemblyType_Executable },
    { .name = "Dynamic", .value = System_ELFAssembly_AssemblyType_Dynamic },
    { .name = "Core", .value = System_ELFAssembly_AssemblyType_Core },
    { .name = "OSSpecificLow", .value = System_ELFAssembly_AssemblyType_OSSpecificLow },
    { .name = "OSSpecificHigh", .value = System_ELFAssembly_AssemblyType_OSSpecificHigh },
    { .name = "ProcessorSpecificLow", .value = System_ELFAssembly_AssemblyType_ProcessorSpecificLow },
    { .name = "ProcessorSpecificHigh", .value = System_ELFAssembly_AssemblyType_ProcessorSpecificHigh },
};

struct System_Type System_ELFAssembly_AssemblyTypeType = { .base = { .type = typeof(System_Type) },
    .name = "AssemblyType",
    .size = sizeof(System_ELFAssembly_AssemblyType),
	.fields = { 
        .value = &System_ELFAssembly_AssemblyTypeTypeFields, .length = sizeof_array(System_ELFAssembly_AssemblyTypeTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_MachineTypeFields[] = {
    { .name = "None", .value = System_ELFAssembly_Machine_None },
    { .name = "M32", .value = System_ELFAssembly_Machine_M32 },
    { .name = "SPARC", .value = System_ELFAssembly_Machine_SPARC },
    { .name = "386", .value = System_ELFAssembly_Machine_386 },
    { .name = "68K", .value = System_ELFAssembly_Machine_68K },
    { .name = "88K", .value = System_ELFAssembly_Machine_88K },
    { .name = "IAMCU", .value = System_ELFAssembly_Machine_IAMCU },
    { .name = "860", .value = System_ELFAssembly_Machine_860 },
    { .name = "MIPS", .value = System_ELFAssembly_Machine_MIPS },
    { .name = "S370", .value = System_ELFAssembly_Machine_S370 },
    { .name = "MIPS_RS3_LE", .value = System_ELFAssembly_Machine_MIPS_RS3_LE },
    { .name = "PARISC", .value = System_ELFAssembly_Machine_PARISC },
    { .name = "VPP500", .value = System_ELFAssembly_Machine_VPP500 },
    { .name = "SPARC32PLUS", .value = System_ELFAssembly_Machine_SPARC32PLUS },
    { .name = "960", .value = System_ELFAssembly_Machine_960 },
    { .name = "PPC", .value = System_ELFAssembly_Machine_PPC },
    { .name = "PPC64", .value = System_ELFAssembly_Machine_PPC64 },
    { .name = "S390", .value = System_ELFAssembly_Machine_S390 },
    { .name = "SPU", .value = System_ELFAssembly_Machine_SPU },
    { .name = "V800", .value = System_ELFAssembly_Machine_V800 },
    { .name = "FR20", .value = System_ELFAssembly_Machine_FR20 },
    { .name = "RH32", .value = System_ELFAssembly_Machine_RH32 },
    { .name = "RCE", .value = System_ELFAssembly_Machine_RCE },
    { .name = "ARM", .value = System_ELFAssembly_Machine_ARM },
    { .name = "FAKE_ALPHA", .value = System_ELFAssembly_Machine_FAKE_ALPHA },
    { .name = "SH", .value = System_ELFAssembly_Machine_SH },
    { .name = "SPARCV9", .value = System_ELFAssembly_Machine_SPARCV9 },
    { .name = "TRICORE", .value = System_ELFAssembly_Machine_TRICORE },
    { .name = "ARC", .value = System_ELFAssembly_Machine_ARC },
    { .name = "H8_300", .value = System_ELFAssembly_Machine_H8_300 },
    { .name = "H8_300H", .value = System_ELFAssembly_Machine_H8_300H },
    { .name = "H8S", .value = System_ELFAssembly_Machine_H8S },
    { .name = "H8_500", .value = System_ELFAssembly_Machine_H8_500 },
    { .name = "IA_64", .value = System_ELFAssembly_Machine_IA_64 },
    { .name = "MIPS_X", .value = System_ELFAssembly_Machine_MIPS_X },
    { .name = "COLDFIRE", .value = System_ELFAssembly_Machine_COLDFIRE },
    { .name = "68HC12", .value = System_ELFAssembly_Machine_68HC12 },
    { .name = "MMA", .value = System_ELFAssembly_Machine_MMA },
    { .name = "PCP", .value = System_ELFAssembly_Machine_PCP },
    { .name = "NCPU", .value = System_ELFAssembly_Machine_NCPU },
    { .name = "NDR1", .value = System_ELFAssembly_Machine_NDR1 },
    { .name = "STARCORE", .value = System_ELFAssembly_Machine_STARCORE },
    { .name = "ME16", .value = System_ELFAssembly_Machine_ME16 },
    { .name = "ST100", .value = System_ELFAssembly_Machine_ST100 },
    { .name = "TINYJ", .value = System_ELFAssembly_Machine_TINYJ },
    { .name = "X86_64", .value = System_ELFAssembly_Machine_X86_64 },
    { .name = "PDSP", .value = System_ELFAssembly_Machine_PDSP },
    { .name = "PDP10", .value = System_ELFAssembly_Machine_PDP10 },
    { .name = "PDP11", .value = System_ELFAssembly_Machine_PDP11 },
    { .name = "FX66", .value = System_ELFAssembly_Machine_FX66 },
    { .name = "ST9PLUS", .value = System_ELFAssembly_Machine_ST9PLUS },
    { .name = "ST7", .value = System_ELFAssembly_Machine_ST7 },
    { .name = "68HC16", .value = System_ELFAssembly_Machine_68HC16 },
    { .name = "68HC11", .value = System_ELFAssembly_Machine_68HC11 },
    { .name = "68HC08", .value = System_ELFAssembly_Machine_68HC08 },
    { .name = "68HC05", .value = System_ELFAssembly_Machine_68HC05 },
    { .name = "SVX", .value = System_ELFAssembly_Machine_SVX },
    { .name = "ST19", .value = System_ELFAssembly_Machine_ST19 },
    { .name = "VAX", .value = System_ELFAssembly_Machine_VAX },
    { .name = "CRIS", .value = System_ELFAssembly_Machine_CRIS },
    { .name = "JAVELIN", .value = System_ELFAssembly_Machine_JAVELIN },
    { .name = "FIREPATH", .value = System_ELFAssembly_Machine_FIREPATH },
    { .name = "ZSP", .value = System_ELFAssembly_Machine_ZSP },
    { .name = "MMIX", .value = System_ELFAssembly_Machine_MMIX },
    { .name = "HUANY", .value = System_ELFAssembly_Machine_HUANY },
    { .name = "PRISM", .value = System_ELFAssembly_Machine_PRISM },
    { .name = "AVR", .value = System_ELFAssembly_Machine_AVR },
    { .name = "FR30", .value = System_ELFAssembly_Machine_FR30 },
    { .name = "D10V", .value = System_ELFAssembly_Machine_D10V },
    { .name = "D30V", .value = System_ELFAssembly_Machine_D30V },
    { .name = "V850", .value = System_ELFAssembly_Machine_V850 },
    { .name = "M32R", .value = System_ELFAssembly_Machine_M32R },
    { .name = "MN10300", .value = System_ELFAssembly_Machine_MN10300 },
    { .name = "MN10200", .value = System_ELFAssembly_Machine_MN10200 },
    { .name = "PJ", .value = System_ELFAssembly_Machine_PJ },
    { .name = "OPENRISC", .value = System_ELFAssembly_Machine_OPENRISC },
    { .name = "ARC_COMPACT", .value = System_ELFAssembly_Machine_ARC_COMPACT },
    { .name = "XTENSA", .value = System_ELFAssembly_Machine_XTENSA },
    { .name = "VIDEOCORE", .value = System_ELFAssembly_Machine_VIDEOCORE },
    { .name = "TMM_GPP", .value = System_ELFAssembly_Machine_TMM_GPP },
    { .name = "NS32K", .value = System_ELFAssembly_Machine_NS32K },
    { .name = "TPC", .value = System_ELFAssembly_Machine_TPC },
    { .name = "SNP1K", .value = System_ELFAssembly_Machine_SNP1K },
    { .name = "ST200", .value = System_ELFAssembly_Machine_ST200 },
    { .name = "IP2K", .value = System_ELFAssembly_Machine_IP2K },
    { .name = "MAX", .value = System_ELFAssembly_Machine_MAX },
    { .name = "CR", .value = System_ELFAssembly_Machine_CR },
    { .name = "F2MC16", .value = System_ELFAssembly_Machine_F2MC16 },
    { .name = "MSP430", .value = System_ELFAssembly_Machine_MSP430 },
    { .name = "BLACKFIN", .value = System_ELFAssembly_Machine_BLACKFIN },
    { .name = "SE_C33", .value = System_ELFAssembly_Machine_SE_C33 },
    { .name = "SEP", .value = System_ELFAssembly_Machine_SEP },
    { .name = "ARCA", .value = System_ELFAssembly_Machine_ARCA },
    { .name = "UNICORE", .value = System_ELFAssembly_Machine_UNICORE },
    { .name = "EXCESS", .value = System_ELFAssembly_Machine_EXCESS },
    { .name = "DXP", .value = System_ELFAssembly_Machine_DXP },
    { .name = "ALTERA_NIOS2", .value = System_ELFAssembly_Machine_ALTERA_NIOS2 },
    { .name = "CRX", .value = System_ELFAssembly_Machine_CRX },
    { .name = "XGATE", .value = System_ELFAssembly_Machine_XGATE },
    { .name = "C166", .value = System_ELFAssembly_Machine_C166 },
    { .name = "M16C", .value = System_ELFAssembly_Machine_M16C },
    { .name = "DSPIC30F", .value = System_ELFAssembly_Machine_DSPIC30F },
    { .name = "CE", .value = System_ELFAssembly_Machine_CE },
    { .name = "M32C", .value = System_ELFAssembly_Machine_M32C },
    { .name = "TSK3000", .value = System_ELFAssembly_Machine_TSK3000 },
    { .name = "RS08", .value = System_ELFAssembly_Machine_RS08 },
    { .name = "SHARC", .value = System_ELFAssembly_Machine_SHARC },
    { .name = "ECOG2", .value = System_ELFAssembly_Machine_ECOG2 },
    { .name = "SCORE7", .value = System_ELFAssembly_Machine_SCORE7 },
    { .name = "DSP24", .value = System_ELFAssembly_Machine_DSP24 },
    { .name = "VIDEOCORE3", .value = System_ELFAssembly_Machine_VIDEOCORE3 },
    { .name = "LATTICEMICO32", .value = System_ELFAssembly_Machine_LATTICEMICO32 },
    { .name = "SE_C17", .value = System_ELFAssembly_Machine_SE_C17 },
    { .name = "TI_C6000", .value = System_ELFAssembly_Machine_TI_C6000 },
    { .name = "TI_C2000", .value = System_ELFAssembly_Machine_TI_C2000 },
    { .name = "TI_C5500", .value = System_ELFAssembly_Machine_TI_C5500 },
    { .name = "TI_ARP32", .value = System_ELFAssembly_Machine_TI_ARP32 },
    { .name = "TI_PRU", .value = System_ELFAssembly_Machine_TI_PRU },
    { .name = "MMDSP_PLUS", .value = System_ELFAssembly_Machine_MMDSP_PLUS },
    { .name = "CYPRESS_M8C", .value = System_ELFAssembly_Machine_CYPRESS_M8C },
    { .name = "R32C", .value = System_ELFAssembly_Machine_R32C },
    { .name = "TRIMEDIA", .value = System_ELFAssembly_Machine_TRIMEDIA },
    { .name = "QDSP6", .value = System_ELFAssembly_Machine_QDSP6 },
    { .name = "8051", .value = System_ELFAssembly_Machine_8051 },
    { .name = "STXP7X", .value = System_ELFAssembly_Machine_STXP7X },
    { .name = "NDS32", .value = System_ELFAssembly_Machine_NDS32 },
    { .name = "ECOG1X", .value = System_ELFAssembly_Machine_ECOG1X },
    { .name = "MAXQ30", .value = System_ELFAssembly_Machine_MAXQ30 },
    { .name = "XIMO16", .value = System_ELFAssembly_Machine_XIMO16 },
    { .name = "MANIK", .value = System_ELFAssembly_Machine_MANIK },
    { .name = "CRAYNV2", .value = System_ELFAssembly_Machine_CRAYNV2 },
    { .name = "RX", .value = System_ELFAssembly_Machine_RX },
    { .name = "METAG", .value = System_ELFAssembly_Machine_METAG },
    { .name = "MCST_ELBRUS", .value = System_ELFAssembly_Machine_MCST_ELBRUS },
    { .name = "ECOG16", .value = System_ELFAssembly_Machine_ECOG16 },
    { .name = "CR16", .value = System_ELFAssembly_Machine_CR16 },
    { .name = "ETPU", .value = System_ELFAssembly_Machine_ETPU },
    { .name = "SLE9X", .value = System_ELFAssembly_Machine_SLE9X },
    { .name = "L10M", .value = System_ELFAssembly_Machine_L10M },
    { .name = "K10M", .value = System_ELFAssembly_Machine_K10M },
    { .name = "AARCH64", .value = System_ELFAssembly_Machine_AARCH64 },
    { .name = "AVR32", .value = System_ELFAssembly_Machine_AVR32 },
    { .name = "STM8", .value = System_ELFAssembly_Machine_STM8 },
    { .name = "TILE64", .value = System_ELFAssembly_Machine_TILE64 },
    { .name = "TILEPRO", .value = System_ELFAssembly_Machine_TILEPRO },
    { .name = "MICROBLAZE", .value = System_ELFAssembly_Machine_MICROBLAZE },
    { .name = "CUDA", .value = System_ELFAssembly_Machine_CUDA },
    { .name = "TILEGX", .value = System_ELFAssembly_Machine_TILEGX },
    { .name = "CLOUDSHIELD", .value = System_ELFAssembly_Machine_CLOUDSHIELD },
    { .name = "COREA_1ST", .value = System_ELFAssembly_Machine_COREA_1ST },
    { .name = "COREA_2ND", .value = System_ELFAssembly_Machine_COREA_2ND },
    { .name = "ARC_COMPACT2", .value = System_ELFAssembly_Machine_ARC_COMPACT2 },
    { .name = "OPEN8", .value = System_ELFAssembly_Machine_OPEN8 },
    { .name = "RL78", .value = System_ELFAssembly_Machine_RL78 },
    { .name = "VIDEOCORE5", .value = System_ELFAssembly_Machine_VIDEOCORE5 },
    { .name = "78KOR", .value = System_ELFAssembly_Machine_78KOR },
    { .name = "56800EX", .value = System_ELFAssembly_Machine_56800EX },
    { .name = "BA1", .value = System_ELFAssembly_Machine_BA1 },
    { .name = "BA2", .value = System_ELFAssembly_Machine_BA2 },
    { .name = "XCORE", .value = System_ELFAssembly_Machine_XCORE },
    { .name = "MCHP_PIC", .value = System_ELFAssembly_Machine_MCHP_PIC },
    { .name = "KM32", .value = System_ELFAssembly_Machine_KM32 },
    { .name = "KMX32", .value = System_ELFAssembly_Machine_KMX32 },
    { .name = "EMX16", .value = System_ELFAssembly_Machine_EMX16 },
    { .name = "EMX8", .value = System_ELFAssembly_Machine_EMX8 },
    { .name = "KVARC", .value = System_ELFAssembly_Machine_KVARC },
    { .name = "CDP", .value = System_ELFAssembly_Machine_CDP },
    { .name = "COGE", .value = System_ELFAssembly_Machine_COGE },
    { .name = "COOL", .value = System_ELFAssembly_Machine_COOL },
    { .name = "NORC", .value = System_ELFAssembly_Machine_NORC },
    { .name = "CSR_KALIMBA", .value = System_ELFAssembly_Machine_CSR_KALIMBA },
    { .name = "Z80", .value = System_ELFAssembly_Machine_Z80 },
    { .name = "VISIUM", .value = System_ELFAssembly_Machine_VISIUM },
    { .name = "FT32", .value = System_ELFAssembly_Machine_FT32 },
    { .name = "MOXIE", .value = System_ELFAssembly_Machine_MOXIE },
    { .name = "AMDGPU", .value = System_ELFAssembly_Machine_AMDGPU },
    { .name = "RISCV", .value = System_ELFAssembly_Machine_RISCV },
    { .name = "BPF", .value = System_ELFAssembly_Machine_BPF },
    { .name = "CSKY", .value = System_ELFAssembly_Machine_CSKY },
    { .name = "ALPHA", .value = System_ELFAssembly_Machine_ALPHA },
};

struct System_Type System_ELFAssembly_MachineType = { .base = { .type = typeof(System_Type) },
    .name = "Machine",
    .size = sizeof(System_ELFAssembly_Machine),
	.fields = { 
        .value = &System_ELFAssembly_MachineTypeFields, .length = sizeof_array(System_ELFAssembly_MachineTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_ProgramTypeTypeFields[] = {
    { .name = "Null", .value = System_ELFAssembly_ProgramType_Null },
    { .name = "Loadable", .value = System_ELFAssembly_ProgramType_Loadable },
    { .name = "Dynamic", .value = System_ELFAssembly_ProgramType_Dynamic },
    { .name = "Interpreter", .value = System_ELFAssembly_ProgramType_Interpreter },
    { .name = "AuxiliaryNote", .value = System_ELFAssembly_ProgramType_AuxiliaryNote },
    { .name = "SHLIB", .value = System_ELFAssembly_ProgramType_SHLIB },
    { .name = "ProgramHeader", .value = System_ELFAssembly_ProgramType_ProgramHeader },
    { .name = "ThreadLocalStorage", .value = System_ELFAssembly_ProgramType_ThreadLocalStorage },
    { .name = "NUMBER", .value = System_ELFAssembly_ProgramType_NUMBER },
    { .name = "GNU_EHFRAME", .value = System_ELFAssembly_ProgramType_GNU_EHFRAME },
    { .name = "GNU_Stack", .value = System_ELFAssembly_ProgramType_GNU_Stack },
    { .name = "GNU_ReadOnlyRelocation", .value = System_ELFAssembly_ProgramType_GNU_ReadOnlyRelocation },
};

struct System_Type System_ELFAssembly_ProgramTypeType = { .base = { .type = typeof(System_Type) },
    .name = "ProgramType",
    .size = sizeof(System_ELFAssembly_ProgramType),
	.fields = { 
        .value = &System_ELFAssembly_ProgramTypeTypeFields, .length = sizeof_array(System_ELFAssembly_ProgramTypeTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_ProgramFlagsTypeFields[] = {
    { .name = "None", .value = System_ELFAssembly_ProgramFlags_None },
    { .name = "Executable", .value = System_ELFAssembly_ProgramFlags_Executable },
    { .name = "Writable", .value = System_ELFAssembly_ProgramFlags_Writable },
    { .name = "Readable", .value = System_ELFAssembly_ProgramFlags_Readable },
    { .name = "OSSpecific", .value = System_ELFAssembly_ProgramFlags_OSSpecific },
    { .name = "ProcessorSpecific", .value = System_ELFAssembly_ProgramFlags_ProcessorSpecific },
};

struct System_Type System_ELFAssembly_ProgramFlagsType = { .base = { .type = typeof(System_Type) },
    .name = "ProgramFlags",
    .size = sizeof(System_ELFAssembly_ProgramFlags),
	.fields = { 
        .value = &System_ELFAssembly_ProgramFlagsTypeFields, .length = sizeof_array(System_ELFAssembly_ProgramFlagsTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_SectionTypeTypeFields[] = {
    { .name = "NULL", .value = System_ELFAssembly_SectionType_NULL },
    { .name = "PROGBITS", .value = System_ELFAssembly_SectionType_PROGBITS },
    { .name = "SYMTAB", .value = System_ELFAssembly_SectionType_SYMTAB },
    { .name = "STRTAB", .value = System_ELFAssembly_SectionType_STRTAB },
    { .name = "RELA", .value = System_ELFAssembly_SectionType_RELA },
    { .name = "HASH", .value = System_ELFAssembly_SectionType_HASH },
    { .name = "DYNAMIC", .value = System_ELFAssembly_SectionType_DYNAMIC },
    { .name = "NOTE", .value = System_ELFAssembly_SectionType_NOTE },
    { .name = "NOBITS", .value = System_ELFAssembly_SectionType_NOBITS },
    { .name = "REL", .value = System_ELFAssembly_SectionType_REL },
    { .name = "SHLIB", .value = System_ELFAssembly_SectionType_SHLIB },
    { .name = "DYNSYM", .value = System_ELFAssembly_SectionType_DYNSYM },
    { .name = "INIT_ARRAY", .value = System_ELFAssembly_SectionType_INIT_ARRAY },
    { .name = "FINI_ARRAY", .value = System_ELFAssembly_SectionType_FINI_ARRAY },
    { .name = "PREINIT_ARRAY", .value = System_ELFAssembly_SectionType_PREINIT_ARRAY },
    { .name = "GROUP", .value = System_ELFAssembly_SectionType_GROUP },
    { .name = "SYMTAB_SHNDX", .value = System_ELFAssembly_SectionType_SYMTAB_SHNDX },
    { .name = "NUM", .value = System_ELFAssembly_SectionType_NUM },
    { .name = "LOOS", .value = System_ELFAssembly_SectionType_LOOS },
    { .name = "GNU_ATTRIBUTES", .value = System_ELFAssembly_SectionType_GNU_ATTRIBUTES },
    { .name = "GNU_HASH", .value = System_ELFAssembly_SectionType_GNU_HASH },
    { .name = "GNU_LIBLIST", .value = System_ELFAssembly_SectionType_GNU_LIBLIST },
    { .name = "CHECKSUM", .value = System_ELFAssembly_SectionType_CHECKSUM },
    { .name = "LOSUNW", .value = System_ELFAssembly_SectionType_LOSUNW },
    { .name = "SUNW_move", .value = System_ELFAssembly_SectionType_SUNW_move },
    { .name = "SUNW_COMDAT", .value = System_ELFAssembly_SectionType_SUNW_COMDAT },
    { .name = "SUNW_syminfo", .value = System_ELFAssembly_SectionType_SUNW_syminfo },
    { .name = "GNU_verdef", .value = System_ELFAssembly_SectionType_GNU_verdef },
    { .name = "GNU_verneed", .value = System_ELFAssembly_SectionType_GNU_verneed },
    { .name = "GNU_versym", .value = System_ELFAssembly_SectionType_GNU_versym },
    { .name = "HISUNW", .value = System_ELFAssembly_SectionType_HISUNW },
    { .name = "HIOS", .value = System_ELFAssembly_SectionType_HIOS },
    { .name = "LOPROC", .value = System_ELFAssembly_SectionType_LOPROC },
    { .name = "HIPROC", .value = System_ELFAssembly_SectionType_HIPROC },
    { .name = "LOUSER", .value = System_ELFAssembly_SectionType_LOUSER },
    { .name = "HIUSER", .value = System_ELFAssembly_SectionType_HIUSER },
};

struct System_Type System_ELFAssembly_SectionTypeType = { .base = { .type = typeof(System_Type) },
    .name = "SectionType",
    .size = sizeof(System_ELFAssembly_SectionType),
	.fields = { 
        .value = &System_ELFAssembly_SectionTypeTypeFields, .length = sizeof_array(System_ELFAssembly_SectionTypeTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_SectionFlagsTypeFields[] = {
    { .name = "None", .value = System_ELFAssembly_SectionFlags_None },
    { .name = "Writable", .value = System_ELFAssembly_SectionFlags_Writable },
    { .name = "Alloc", .value = System_ELFAssembly_SectionFlags_Alloc },
    { .name = "Executable", .value = System_ELFAssembly_SectionFlags_Executable },
    { .name = "Merge", .value = System_ELFAssembly_SectionFlags_Merge },
    { .name = "Strings", .value = System_ELFAssembly_SectionFlags_Strings },
};

struct System_Type System_ELFAssembly_SectionFlagsType = { .base = { .type = typeof(System_Type) },
    .name = "SectionFlags",
    .size = sizeof(System_ELFAssembly_SectionFlags),
	.fields = { 
        .value = &System_ELFAssembly_SectionFlagsTypeFields, .length = sizeof_array(System_ELFAssembly_SectionFlagsTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_DynamicTypeTypeFields[] = {
    { .name = "NULL", .value = System_ELFAssembly_DynamicType_NULL },
    { .name = "NEEDED", .value = System_ELFAssembly_DynamicType_NEEDED },
    { .name = "PLTRELSZ", .value = System_ELFAssembly_DynamicType_PLTRELSZ },
    { .name = "PLTGOT", .value = System_ELFAssembly_DynamicType_PLTGOT },
    { .name = "HASH", .value = System_ELFAssembly_DynamicType_HASH },
    { .name = "STRTAB", .value = System_ELFAssembly_DynamicType_STRTAB },
    { .name = "SYMTAB", .value = System_ELFAssembly_DynamicType_SYMTAB },
    { .name = "RELA", .value = System_ELFAssembly_DynamicType_RELA },
    { .name = "RELASZ", .value = System_ELFAssembly_DynamicType_RELASZ },
    { .name = "RELAENT", .value = System_ELFAssembly_DynamicType_RELAENT },
    { .name = "STRSZ", .value = System_ELFAssembly_DynamicType_STRSZ },
    { .name = "SYMENT", .value = System_ELFAssembly_DynamicType_SYMENT },
    { .name = "INIT", .value = System_ELFAssembly_DynamicType_INIT },
    { .name = "FINI", .value = System_ELFAssembly_DynamicType_FINI },
    { .name = "SONAME", .value = System_ELFAssembly_DynamicType_SONAME },
    { .name = "RPATH", .value = System_ELFAssembly_DynamicType_RPATH },
    { .name = "SYMBOLIC", .value = System_ELFAssembly_DynamicType_SYMBOLIC },
    { .name = "REL", .value = System_ELFAssembly_DynamicType_REL },
    { .name = "RELSZ", .value = System_ELFAssembly_DynamicType_RELSZ },
    { .name = "RELENT", .value = System_ELFAssembly_DynamicType_RELENT },
    { .name = "PLTREL", .value = System_ELFAssembly_DynamicType_PLTREL },
    { .name = "DEBUG", .value = System_ELFAssembly_DynamicType_DEBUG },
    { .name = "TEXTREL", .value = System_ELFAssembly_DynamicType_TEXTREL },
    { .name = "JMPREL", .value = System_ELFAssembly_DynamicType_JMPREL },
    { .name = "BIND_NOW", .value = System_ELFAssembly_DynamicType_BIND_NOW },
    { .name = "INIT_ARRAY", .value = System_ELFAssembly_DynamicType_INIT_ARRAY },
    { .name = "FINI_ARRAY", .value = System_ELFAssembly_DynamicType_FINI_ARRAY },
    { .name = "INIT_ARRAYSZ", .value = System_ELFAssembly_DynamicType_INIT_ARRAYSZ },
    { .name = "FINI_ARRAYSZ", .value = System_ELFAssembly_DynamicType_FINI_ARRAYSZ },
    { .name = "RUNPATH", .value = System_ELFAssembly_DynamicType_RUNPATH },
    { .name = "FLAGS", .value = System_ELFAssembly_DynamicType_FLAGS },
    { .name = "ENCODING", .value = System_ELFAssembly_DynamicType_ENCODING },
    { .name = "PREINIT_ARRAY", .value = System_ELFAssembly_DynamicType_PREINIT_ARRAY },
    { .name = "PREINIT_ARRAYSZ", .value = System_ELFAssembly_DynamicType_PREINIT_ARRAYSZ },
    { .name = "SYMTAB_SHNDX", .value = System_ELFAssembly_DynamicType_SYMTAB_SHNDX },
    { .name = "NUM", .value = System_ELFAssembly_DynamicType_NUM },
    { .name = "LOOS", .value = System_ELFAssembly_DynamicType_LOOS },
    { .name = "HIOS", .value = System_ELFAssembly_DynamicType_HIOS },
    { .name = "LOPROC", .value = System_ELFAssembly_DynamicType_LOPROC },
    { .name = "HIPROC", .value = System_ELFAssembly_DynamicType_HIPROC },
    { .name = "MIPSNUM", .value = System_ELFAssembly_DynamicType_MIPSNUM },
    { .name = "PROCNUM", .value = System_ELFAssembly_DynamicType_PROCNUM },
    { .name = "VALRNGLO", .value = System_ELFAssembly_DynamicType_VALRNGLO },
    { .name = "GNU_PRELINKED", .value = System_ELFAssembly_DynamicType_GNU_PRELINKED },
    { .name = "GNU_CONFLICTSZ", .value = System_ELFAssembly_DynamicType_GNU_CONFLICTSZ },
    { .name = "GNU_LIBLISTSZ", .value = System_ELFAssembly_DynamicType_GNU_LIBLISTSZ },
    { .name = "CHECKSUM", .value = System_ELFAssembly_DynamicType_CHECKSUM },
    { .name = "PLTPADSZ", .value = System_ELFAssembly_DynamicType_PLTPADSZ },
    { .name = "MOVEENT", .value = System_ELFAssembly_DynamicType_MOVEENT },
    { .name = "MOVESZ", .value = System_ELFAssembly_DynamicType_MOVESZ },
    { .name = "FEATURE_1", .value = System_ELFAssembly_DynamicType_FEATURE_1 },
    { .name = "POSFLAG_1", .value = System_ELFAssembly_DynamicType_POSFLAG_1 },
    { .name = "SYMINSZ", .value = System_ELFAssembly_DynamicType_SYMINSZ },
    { .name = "SYMINENT", .value = System_ELFAssembly_DynamicType_SYMINENT },
    { .name = "VALRNGHI", .value = System_ELFAssembly_DynamicType_VALRNGHI },
    { .name = "VALNUM", .value = System_ELFAssembly_DynamicType_VALNUM },
    { .name = "ADDRRNGLO", .value = System_ELFAssembly_DynamicType_ADDRRNGLO },
    { .name = "GNU_HASH", .value = System_ELFAssembly_DynamicType_GNU_HASH },
    { .name = "TLSDESC_PLT", .value = System_ELFAssembly_DynamicType_TLSDESC_PLT },
    { .name = "TLSDESC_GOT", .value = System_ELFAssembly_DynamicType_TLSDESC_GOT },
    { .name = "GNU_CONFLICT", .value = System_ELFAssembly_DynamicType_GNU_CONFLICT },
    { .name = "GNU_LIBLIST", .value = System_ELFAssembly_DynamicType_GNU_LIBLIST },
    { .name = "CONFIG", .value = System_ELFAssembly_DynamicType_CONFIG },
    { .name = "DEPAUDIT", .value = System_ELFAssembly_DynamicType_DEPAUDIT },
    { .name = "AUDIT", .value = System_ELFAssembly_DynamicType_AUDIT },
    { .name = "PLTPAD", .value = System_ELFAssembly_DynamicType_PLTPAD },
    { .name = "MOVETAB", .value = System_ELFAssembly_DynamicType_MOVETAB },
    { .name = "SYMINFO", .value = System_ELFAssembly_DynamicType_SYMINFO },
    { .name = "ADDRRNGHI", .value = System_ELFAssembly_DynamicType_ADDRRNGHI },
    { .name = "ADDRNUM", .value = System_ELFAssembly_DynamicType_ADDRNUM },
    { .name = "VERSYM", .value = System_ELFAssembly_DynamicType_VERSYM },
    { .name = "RELACOUNT", .value = System_ELFAssembly_DynamicType_RELACOUNT },
    { .name = "RELCOUNT", .value = System_ELFAssembly_DynamicType_RELCOUNT },
    { .name = "FLAGS_1", .value = System_ELFAssembly_DynamicType_FLAGS_1 },
    { .name = "VERDEF", .value = System_ELFAssembly_DynamicType_VERDEF },
    { .name = "VERDEFNUM", .value = System_ELFAssembly_DynamicType_VERDEFNUM },
    { .name = "VERNEED", .value = System_ELFAssembly_DynamicType_VERNEED },
    { .name = "VERNEEDNUM", .value = System_ELFAssembly_DynamicType_VERNEEDNUM },
    { .name = "VERSIONTAGNUM", .value = System_ELFAssembly_DynamicType_VERSIONTAGNUM },
    { .name = "AUXILIARY", .value = System_ELFAssembly_DynamicType_AUXILIARY },
    { .name = "FILTER", .value = System_ELFAssembly_DynamicType_FILTER },
    { .name = "EXTRANUM", .value = System_ELFAssembly_DynamicType_EXTRANUM },
};

struct System_Type System_ELFAssembly_DynamicTypeType = { .base = { .type = typeof(System_Type) },
    .name = "DynamicType",
    .size = sizeof(System_ELFAssembly_DynamicType),
	.fields = { 
        .value = &System_ELFAssembly_DynamicTypeTypeFields, .length = sizeof_array(System_ELFAssembly_DynamicTypeTypeFields),
    },
};


struct System_Type_FieldInfo  System_ELFAssembly_AMD64RelocationTypeFields[] = {
    { .name = "NONE", .value = System_ELFAssembly_AMD64Relocation_NONE },
    { .name = "64", .value = System_ELFAssembly_AMD64Relocation_64 },
    { .name = "PC32", .value = System_ELFAssembly_AMD64Relocation_PC32 },
    { .name = "GOT32", .value = System_ELFAssembly_AMD64Relocation_GOT32 },
    { .name = "PLT32", .value = System_ELFAssembly_AMD64Relocation_PLT32 },
    { .name = "COPY", .value = System_ELFAssembly_AMD64Relocation_COPY },
    { .name = "GLOB_DAT", .value = System_ELFAssembly_AMD64Relocation_GLOB_DAT },
    { .name = "JUMP_SLOT", .value = System_ELFAssembly_AMD64Relocation_JUMP_SLOT },
    { .name = "RELATIVE", .value = System_ELFAssembly_AMD64Relocation_RELATIVE },
    { .name = "GOTPCREL", .value = System_ELFAssembly_AMD64Relocation_GOTPCREL },
    { .name = "32", .value = System_ELFAssembly_AMD64Relocation_32 },
    { .name = "32S", .value = System_ELFAssembly_AMD64Relocation_32S },
    { .name = "16", .value = System_ELFAssembly_AMD64Relocation_16 },
    { .name = "PC16", .value = System_ELFAssembly_AMD64Relocation_PC16 },
    { .name = "8", .value = System_ELFAssembly_AMD64Relocation_8 },
    { .name = "PC8", .value = System_ELFAssembly_AMD64Relocation_PC8 },
    { .name = "DTPMOD64", .value = System_ELFAssembly_AMD64Relocation_DTPMOD64 },
    { .name = "DTPOFF64", .value = System_ELFAssembly_AMD64Relocation_DTPOFF64 },
    { .name = "TPOFF64", .value = System_ELFAssembly_AMD64Relocation_TPOFF64 },
    { .name = "TLSGD", .value = System_ELFAssembly_AMD64Relocation_TLSGD },
    { .name = "TLSLD", .value = System_ELFAssembly_AMD64Relocation_TLSLD },
    { .name = "DTPOFF32", .value = System_ELFAssembly_AMD64Relocation_DTPOFF32 },
    { .name = "GOTTPOFF", .value = System_ELFAssembly_AMD64Relocation_GOTTPOFF },
    { .name = "TPOFF32", .value = System_ELFAssembly_AMD64Relocation_TPOFF32 },
    { .name = "PC64", .value = System_ELFAssembly_AMD64Relocation_PC64 },
    { .name = "GOTOFF64", .value = System_ELFAssembly_AMD64Relocation_GOTOFF64 },
    { .name = "GOTPC32", .value = System_ELFAssembly_AMD64Relocation_GOTPC32 },
    { .name = "GOT64", .value = System_ELFAssembly_AMD64Relocation_GOT64 },
    { .name = "GOTPCREL64", .value = System_ELFAssembly_AMD64Relocation_GOTPCREL64 },
    { .name = "GOTPC64", .value = System_ELFAssembly_AMD64Relocation_GOTPC64 },
    { .name = "GOTPLT64", .value = System_ELFAssembly_AMD64Relocation_GOTPLT64 },
    { .name = "PLTOFF64", .value = System_ELFAssembly_AMD64Relocation_PLTOFF64 },
    { .name = "SIZE32", .value = System_ELFAssembly_AMD64Relocation_SIZE32 },
    { .name = "SIZE64", .value = System_ELFAssembly_AMD64Relocation_SIZE64 },
    { .name = "GOTPC32_TLSDESC", .value = System_ELFAssembly_AMD64Relocation_GOTPC32_TLSDESC },
    { .name = "TLSDESC_CALL", .value = System_ELFAssembly_AMD64Relocation_TLSDESC_CALL },
    { .name = "TLSDESC", .value = System_ELFAssembly_AMD64Relocation_TLSDESC },
    { .name = "IRELATIVE", .value = System_ELFAssembly_AMD64Relocation_IRELATIVE },
    { .name = "RELATIVE64", .value = System_ELFAssembly_AMD64Relocation_RELATIVE64 },
    /* 39 Reserved was System_ELFAssembly_AMD64Relocation_PC32_BND */
    /* 40 Reserved was System_ELFAssembly_AMD64Relocation_PLT32_BND */
    { .name = "GOTPCRELX", .value = System_ELFAssembly_AMD64Relocation_GOTPCRELX },
    { .name = "REX_GOTPCRELX", .value = System_ELFAssembly_AMD64Relocation_REX_GOTPCRELX },
};

struct System_Type System_ELFAssembly_AMD64RelocationType = { .base = { .type = typeof(System_Type) },
    .name = "AMD64Relocation",
    .size = sizeof(System_ELFAssembly_AMD64RelocationType),
	.fields = { 
        .value = &System_ELFAssembly_AMD64RelocationTypeFields, .length = sizeof_array(System_ELFAssembly_AMD64RelocationTypeFields),
    },
};

#endif