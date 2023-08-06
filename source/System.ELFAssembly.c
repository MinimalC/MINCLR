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

void System_ELF64Assembly_read__print(System_ELF64Assembly assembly, System_String8 name, System_Bool print) {

    if (assembly->name) return; // throw

    assembly->name = name;

    if (!assembly->buffer) {
        struct System_File file = stack_System_File();
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

    assembly->link = System_Syscall_mmap(load_size, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
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

    for (System_Size l = 0; l < System_ELF64Assembly_loadedCount; ++l) {
        System_ELF64Assembly assembly = System_ELF64Assembly_loaded[l];
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

    for (System_Size l = 0; l < System_ELF64Assembly_loadedCount; ++l) {
        System_ELF64Assembly assembly = System_ELF64Assembly_loaded[l];
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

System_Var System_ELF64Assembly_resolve(System_ELF64Assembly assembly, System_UInt64 relocationOffset) {
    System_ELF64Assembly_RelocationAddend relocation = (System_Var)assembly->PLT_relocation + relocationOffset;

    System_ELF64Assembly_SymbolEntry symbol = !relocation->symbol ? null : assembly->dynamicSymbols + relocation->symbol;

    System_String8 name = assembly->dynamicStrings + symbol->name;

    System_Var * address = (System_Var *)(assembly->link + relocation->offset), old = *address;

    *address = assembly->link + symbol->value;

#if DEBUG == DEBUG_System_ELFAssembly
    System_Console_writeLine("ELFAssembly_resolve: {0:string}, {1:uint:hex} old => new {2:uint:hex}", 3, name, old, *address);
#endif

    return *address;
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
        if (symbol->value)
            *address = (System_Size)assembly->link + symbol->value + relocation->addend; 
        break;
    case System_ELFAssembly_AMD64Relocation_JUMP_SLOT:
        if ((symbol->sectionIndex || symbol->value) && *address) {
            *address += (System_Size)assembly->link;
            break;
        }
    case System_ELFAssembly_AMD64Relocation_GLOB_DAT: 
        symbol1 = System_ELF64Assembly_getDynamicSymbol(assembly->dynamicStrings + symbol->name, &assembly1);
        if (symbol1 && symbol1->value) 
            *address = (System_Size)assembly1->link + symbol1->value;
        else if (symbol->value)
            *address = (System_Size)assembly->link + symbol->value; 
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
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SysV", .value = System_ELFAssembly_ABI_SysV },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HPUX", .value = System_ELFAssembly_ABI_HPUX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NetBSD", .value = System_ELFAssembly_ABI_NetBSD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU", .value = System_ELFAssembly_ABI_GNU },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Linux", .value = System_ELFAssembly_ABI_Linux },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Solaris", .value = System_ELFAssembly_ABI_Solaris },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AIX", .value = System_ELFAssembly_ABI_AIX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IRIX", .value = System_ELFAssembly_ABI_IRIX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FreeBSD", .value = System_ELFAssembly_ABI_FreeBSD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TRU64", .value = System_ELFAssembly_ABI_TRU64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Modesto", .value = System_ELFAssembly_ABI_Modesto },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "OpenBSD", .value = System_ELFAssembly_ABI_OpenBSD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ARM_EABI", .value = System_ELFAssembly_ABI_ARM_EABI },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ARM", .value = System_ELFAssembly_ABI_ARM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Standalone", .value = System_ELFAssembly_ABI_Standalone },
};

struct System_Type System_ELFAssembly_ABIType = { .base = { .type = typeof(System_Type) },
    .name = "ABI",
    .size = sizeof(System_ELFAssembly_ABI),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_ABITypeFields, .length = sizeof_array(System_ELFAssembly_ABITypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_AssemblyTypeTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "None", .value = System_ELFAssembly_AssemblyType_None },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Relocatable", .value = System_ELFAssembly_AssemblyType_Relocatable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Executable", .value = System_ELFAssembly_AssemblyType_Executable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Dynamic", .value = System_ELFAssembly_AssemblyType_Dynamic },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Core", .value = System_ELFAssembly_AssemblyType_Core },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "OSSpecificLow", .value = System_ELFAssembly_AssemblyType_OSSpecificLow },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "OSSpecificHigh", .value = System_ELFAssembly_AssemblyType_OSSpecificHigh },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ProcessorSpecificLow", .value = System_ELFAssembly_AssemblyType_ProcessorSpecificLow },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ProcessorSpecificHigh", .value = System_ELFAssembly_AssemblyType_ProcessorSpecificHigh },
};

struct System_Type System_ELFAssembly_AssemblyTypeType = { .base = { .type = typeof(System_Type) },
    .name = "AssemblyType",
    .size = sizeof(System_ELFAssembly_AssemblyType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_AssemblyTypeTypeFields, .length = sizeof_array(System_ELFAssembly_AssemblyTypeTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_MachineTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "None", .value = System_ELFAssembly_Machine_None },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "M32", .value = System_ELFAssembly_Machine_M32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SPARC", .value = System_ELFAssembly_Machine_SPARC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "386", .value = System_ELFAssembly_Machine_386 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "68K", .value = System_ELFAssembly_Machine_68K },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "88K", .value = System_ELFAssembly_Machine_88K },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IAMCU", .value = System_ELFAssembly_Machine_IAMCU },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "860", .value = System_ELFAssembly_Machine_860 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MIPS", .value = System_ELFAssembly_Machine_MIPS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "S370", .value = System_ELFAssembly_Machine_S370 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MIPS_RS3_LE", .value = System_ELFAssembly_Machine_MIPS_RS3_LE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PARISC", .value = System_ELFAssembly_Machine_PARISC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VPP500", .value = System_ELFAssembly_Machine_VPP500 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SPARC32PLUS", .value = System_ELFAssembly_Machine_SPARC32PLUS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "960", .value = System_ELFAssembly_Machine_960 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PPC", .value = System_ELFAssembly_Machine_PPC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PPC64", .value = System_ELFAssembly_Machine_PPC64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "S390", .value = System_ELFAssembly_Machine_S390 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SPU", .value = System_ELFAssembly_Machine_SPU },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "V800", .value = System_ELFAssembly_Machine_V800 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FR20", .value = System_ELFAssembly_Machine_FR20 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RH32", .value = System_ELFAssembly_Machine_RH32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RCE", .value = System_ELFAssembly_Machine_RCE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ARM", .value = System_ELFAssembly_Machine_ARM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FAKE_ALPHA", .value = System_ELFAssembly_Machine_FAKE_ALPHA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SH", .value = System_ELFAssembly_Machine_SH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SPARCV9", .value = System_ELFAssembly_Machine_SPARCV9 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TRICORE", .value = System_ELFAssembly_Machine_TRICORE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ARC", .value = System_ELFAssembly_Machine_ARC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "H8_300", .value = System_ELFAssembly_Machine_H8_300 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "H8_300H", .value = System_ELFAssembly_Machine_H8_300H },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "H8S", .value = System_ELFAssembly_Machine_H8S },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "H8_500", .value = System_ELFAssembly_Machine_H8_500 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IA_64", .value = System_ELFAssembly_Machine_IA_64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MIPS_X", .value = System_ELFAssembly_Machine_MIPS_X },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "COLDFIRE", .value = System_ELFAssembly_Machine_COLDFIRE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "68HC12", .value = System_ELFAssembly_Machine_68HC12 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MMA", .value = System_ELFAssembly_Machine_MMA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PCP", .value = System_ELFAssembly_Machine_PCP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NCPU", .value = System_ELFAssembly_Machine_NCPU },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NDR1", .value = System_ELFAssembly_Machine_NDR1 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "STARCORE", .value = System_ELFAssembly_Machine_STARCORE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ME16", .value = System_ELFAssembly_Machine_ME16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ST100", .value = System_ELFAssembly_Machine_ST100 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TINYJ", .value = System_ELFAssembly_Machine_TINYJ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "X86_64", .value = System_ELFAssembly_Machine_X86_64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PDSP", .value = System_ELFAssembly_Machine_PDSP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PDP10", .value = System_ELFAssembly_Machine_PDP10 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PDP11", .value = System_ELFAssembly_Machine_PDP11 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FX66", .value = System_ELFAssembly_Machine_FX66 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ST9PLUS", .value = System_ELFAssembly_Machine_ST9PLUS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ST7", .value = System_ELFAssembly_Machine_ST7 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "68HC16", .value = System_ELFAssembly_Machine_68HC16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "68HC11", .value = System_ELFAssembly_Machine_68HC11 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "68HC08", .value = System_ELFAssembly_Machine_68HC08 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "68HC05", .value = System_ELFAssembly_Machine_68HC05 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SVX", .value = System_ELFAssembly_Machine_SVX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ST19", .value = System_ELFAssembly_Machine_ST19 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VAX", .value = System_ELFAssembly_Machine_VAX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CRIS", .value = System_ELFAssembly_Machine_CRIS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "JAVELIN", .value = System_ELFAssembly_Machine_JAVELIN },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FIREPATH", .value = System_ELFAssembly_Machine_FIREPATH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ZSP", .value = System_ELFAssembly_Machine_ZSP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MMIX", .value = System_ELFAssembly_Machine_MMIX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HUANY", .value = System_ELFAssembly_Machine_HUANY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PRISM", .value = System_ELFAssembly_Machine_PRISM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AVR", .value = System_ELFAssembly_Machine_AVR },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FR30", .value = System_ELFAssembly_Machine_FR30 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "D10V", .value = System_ELFAssembly_Machine_D10V },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "D30V", .value = System_ELFAssembly_Machine_D30V },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "V850", .value = System_ELFAssembly_Machine_V850 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "M32R", .value = System_ELFAssembly_Machine_M32R },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MN10300", .value = System_ELFAssembly_Machine_MN10300 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MN10200", .value = System_ELFAssembly_Machine_MN10200 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PJ", .value = System_ELFAssembly_Machine_PJ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "OPENRISC", .value = System_ELFAssembly_Machine_OPENRISC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ARC_COMPACT", .value = System_ELFAssembly_Machine_ARC_COMPACT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "XTENSA", .value = System_ELFAssembly_Machine_XTENSA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VIDEOCORE", .value = System_ELFAssembly_Machine_VIDEOCORE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TMM_GPP", .value = System_ELFAssembly_Machine_TMM_GPP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NS32K", .value = System_ELFAssembly_Machine_NS32K },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TPC", .value = System_ELFAssembly_Machine_TPC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SNP1K", .value = System_ELFAssembly_Machine_SNP1K },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ST200", .value = System_ELFAssembly_Machine_ST200 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IP2K", .value = System_ELFAssembly_Machine_IP2K },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MAX", .value = System_ELFAssembly_Machine_MAX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CR", .value = System_ELFAssembly_Machine_CR },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "F2MC16", .value = System_ELFAssembly_Machine_F2MC16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MSP430", .value = System_ELFAssembly_Machine_MSP430 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BLACKFIN", .value = System_ELFAssembly_Machine_BLACKFIN },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SE_C33", .value = System_ELFAssembly_Machine_SE_C33 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SEP", .value = System_ELFAssembly_Machine_SEP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ARCA", .value = System_ELFAssembly_Machine_ARCA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "UNICORE", .value = System_ELFAssembly_Machine_UNICORE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EXCESS", .value = System_ELFAssembly_Machine_EXCESS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DXP", .value = System_ELFAssembly_Machine_DXP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ALTERA_NIOS2", .value = System_ELFAssembly_Machine_ALTERA_NIOS2 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CRX", .value = System_ELFAssembly_Machine_CRX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "XGATE", .value = System_ELFAssembly_Machine_XGATE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "C166", .value = System_ELFAssembly_Machine_C166 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "M16C", .value = System_ELFAssembly_Machine_M16C },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DSPIC30F", .value = System_ELFAssembly_Machine_DSPIC30F },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CE", .value = System_ELFAssembly_Machine_CE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "M32C", .value = System_ELFAssembly_Machine_M32C },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TSK3000", .value = System_ELFAssembly_Machine_TSK3000 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RS08", .value = System_ELFAssembly_Machine_RS08 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SHARC", .value = System_ELFAssembly_Machine_SHARC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ECOG2", .value = System_ELFAssembly_Machine_ECOG2 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SCORE7", .value = System_ELFAssembly_Machine_SCORE7 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DSP24", .value = System_ELFAssembly_Machine_DSP24 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VIDEOCORE3", .value = System_ELFAssembly_Machine_VIDEOCORE3 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "LATTICEMICO32", .value = System_ELFAssembly_Machine_LATTICEMICO32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SE_C17", .value = System_ELFAssembly_Machine_SE_C17 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TI_C6000", .value = System_ELFAssembly_Machine_TI_C6000 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TI_C2000", .value = System_ELFAssembly_Machine_TI_C2000 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TI_C5500", .value = System_ELFAssembly_Machine_TI_C5500 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TI_ARP32", .value = System_ELFAssembly_Machine_TI_ARP32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TI_PRU", .value = System_ELFAssembly_Machine_TI_PRU },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MMDSP_PLUS", .value = System_ELFAssembly_Machine_MMDSP_PLUS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CYPRESS_M8C", .value = System_ELFAssembly_Machine_CYPRESS_M8C },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "R32C", .value = System_ELFAssembly_Machine_R32C },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TRIMEDIA", .value = System_ELFAssembly_Machine_TRIMEDIA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "QDSP6", .value = System_ELFAssembly_Machine_QDSP6 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "8051", .value = System_ELFAssembly_Machine_8051 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "STXP7X", .value = System_ELFAssembly_Machine_STXP7X },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NDS32", .value = System_ELFAssembly_Machine_NDS32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ECOG1X", .value = System_ELFAssembly_Machine_ECOG1X },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MAXQ30", .value = System_ELFAssembly_Machine_MAXQ30 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "XIMO16", .value = System_ELFAssembly_Machine_XIMO16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MANIK", .value = System_ELFAssembly_Machine_MANIK },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CRAYNV2", .value = System_ELFAssembly_Machine_CRAYNV2 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RX", .value = System_ELFAssembly_Machine_RX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "METAG", .value = System_ELFAssembly_Machine_METAG },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MCST_ELBRUS", .value = System_ELFAssembly_Machine_MCST_ELBRUS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ECOG16", .value = System_ELFAssembly_Machine_ECOG16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CR16", .value = System_ELFAssembly_Machine_CR16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ETPU", .value = System_ELFAssembly_Machine_ETPU },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SLE9X", .value = System_ELFAssembly_Machine_SLE9X },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L10M", .value = System_ELFAssembly_Machine_L10M },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "K10M", .value = System_ELFAssembly_Machine_K10M },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AARCH64", .value = System_ELFAssembly_Machine_AARCH64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AVR32", .value = System_ELFAssembly_Machine_AVR32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "STM8", .value = System_ELFAssembly_Machine_STM8 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TILE64", .value = System_ELFAssembly_Machine_TILE64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TILEPRO", .value = System_ELFAssembly_Machine_TILEPRO },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MICROBLAZE", .value = System_ELFAssembly_Machine_MICROBLAZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CUDA", .value = System_ELFAssembly_Machine_CUDA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TILEGX", .value = System_ELFAssembly_Machine_TILEGX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CLOUDSHIELD", .value = System_ELFAssembly_Machine_CLOUDSHIELD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "COREA_1ST", .value = System_ELFAssembly_Machine_COREA_1ST },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "COREA_2ND", .value = System_ELFAssembly_Machine_COREA_2ND },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ARC_COMPACT2", .value = System_ELFAssembly_Machine_ARC_COMPACT2 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "OPEN8", .value = System_ELFAssembly_Machine_OPEN8 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RL78", .value = System_ELFAssembly_Machine_RL78 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VIDEOCORE5", .value = System_ELFAssembly_Machine_VIDEOCORE5 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "78KOR", .value = System_ELFAssembly_Machine_78KOR },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "56800EX", .value = System_ELFAssembly_Machine_56800EX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BA1", .value = System_ELFAssembly_Machine_BA1 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BA2", .value = System_ELFAssembly_Machine_BA2 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "XCORE", .value = System_ELFAssembly_Machine_XCORE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MCHP_PIC", .value = System_ELFAssembly_Machine_MCHP_PIC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "KM32", .value = System_ELFAssembly_Machine_KM32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "KMX32", .value = System_ELFAssembly_Machine_KMX32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EMX16", .value = System_ELFAssembly_Machine_EMX16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EMX8", .value = System_ELFAssembly_Machine_EMX8 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "KVARC", .value = System_ELFAssembly_Machine_KVARC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CDP", .value = System_ELFAssembly_Machine_CDP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "COGE", .value = System_ELFAssembly_Machine_COGE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "COOL", .value = System_ELFAssembly_Machine_COOL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NORC", .value = System_ELFAssembly_Machine_NORC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CSR_KALIMBA", .value = System_ELFAssembly_Machine_CSR_KALIMBA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Z80", .value = System_ELFAssembly_Machine_Z80 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VISIUM", .value = System_ELFAssembly_Machine_VISIUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FT32", .value = System_ELFAssembly_Machine_FT32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MOXIE", .value = System_ELFAssembly_Machine_MOXIE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AMDGPU", .value = System_ELFAssembly_Machine_AMDGPU },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RISCV", .value = System_ELFAssembly_Machine_RISCV },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BPF", .value = System_ELFAssembly_Machine_BPF },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CSKY", .value = System_ELFAssembly_Machine_CSKY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ALPHA", .value = System_ELFAssembly_Machine_ALPHA },
};

struct System_Type System_ELFAssembly_MachineType = { .base = { .type = typeof(System_Type) },
    .name = "Machine",
    .size = sizeof(System_ELFAssembly_Machine),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_MachineTypeFields, .length = sizeof_array(System_ELFAssembly_MachineTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_ProgramTypeTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Null", .value = System_ELFAssembly_ProgramType_Null },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Loadable", .value = System_ELFAssembly_ProgramType_Loadable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Dynamic", .value = System_ELFAssembly_ProgramType_Dynamic },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Interpreter", .value = System_ELFAssembly_ProgramType_Interpreter },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AuxiliaryNote", .value = System_ELFAssembly_ProgramType_AuxiliaryNote },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SHLIB", .value = System_ELFAssembly_ProgramType_SHLIB },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ProgramHeader", .value = System_ELFAssembly_ProgramType_ProgramHeader },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ThreadLocalStorage", .value = System_ELFAssembly_ProgramType_ThreadLocalStorage },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NUMBER", .value = System_ELFAssembly_ProgramType_NUMBER },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_EHFRAME", .value = System_ELFAssembly_ProgramType_GNU_EHFRAME },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_Stack", .value = System_ELFAssembly_ProgramType_GNU_Stack },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_ReadOnlyRelocation", .value = System_ELFAssembly_ProgramType_GNU_ReadOnlyRelocation },
};

struct System_Type System_ELFAssembly_ProgramTypeType = { .base = { .type = typeof(System_Type) },
    .name = "ProgramType",
    .size = sizeof(System_ELFAssembly_ProgramType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_ProgramTypeTypeFields, .length = sizeof_array(System_ELFAssembly_ProgramTypeTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_ProgramFlagsTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "None", .value = System_ELFAssembly_ProgramFlags_None },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Executable", .value = System_ELFAssembly_ProgramFlags_Executable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Writable", .value = System_ELFAssembly_ProgramFlags_Writable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Readable", .value = System_ELFAssembly_ProgramFlags_Readable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "OSSpecific", .value = System_ELFAssembly_ProgramFlags_OSSpecific },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ProcessorSpecific", .value = System_ELFAssembly_ProgramFlags_ProcessorSpecific },
};

struct System_Type System_ELFAssembly_ProgramFlagsType = { .base = { .type = typeof(System_Type) },
    .name = "ProgramFlags",
    .size = sizeof(System_ELFAssembly_ProgramFlags),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_ProgramFlagsTypeFields, .length = sizeof_array(System_ELFAssembly_ProgramFlagsTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_SectionTypeTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NULL", .value = System_ELFAssembly_SectionType_NULL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PROGBITS", .value = System_ELFAssembly_SectionType_PROGBITS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMTAB", .value = System_ELFAssembly_SectionType_SYMTAB },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "STRTAB", .value = System_ELFAssembly_SectionType_STRTAB },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELA", .value = System_ELFAssembly_SectionType_RELA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HASH", .value = System_ELFAssembly_SectionType_HASH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DYNAMIC", .value = System_ELFAssembly_SectionType_DYNAMIC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NOTE", .value = System_ELFAssembly_SectionType_NOTE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NOBITS", .value = System_ELFAssembly_SectionType_NOBITS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "REL", .value = System_ELFAssembly_SectionType_REL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SHLIB", .value = System_ELFAssembly_SectionType_SHLIB },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DYNSYM", .value = System_ELFAssembly_SectionType_DYNSYM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "INIT_ARRAY", .value = System_ELFAssembly_SectionType_INIT_ARRAY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FINI_ARRAY", .value = System_ELFAssembly_SectionType_FINI_ARRAY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PREINIT_ARRAY", .value = System_ELFAssembly_SectionType_PREINIT_ARRAY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GROUP", .value = System_ELFAssembly_SectionType_GROUP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMTAB_SHNDX", .value = System_ELFAssembly_SectionType_SYMTAB_SHNDX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NUM", .value = System_ELFAssembly_SectionType_NUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "LOOS", .value = System_ELFAssembly_SectionType_LOOS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_ATTRIBUTES", .value = System_ELFAssembly_SectionType_GNU_ATTRIBUTES },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_HASH", .value = System_ELFAssembly_SectionType_GNU_HASH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_LIBLIST", .value = System_ELFAssembly_SectionType_GNU_LIBLIST },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CHECKSUM", .value = System_ELFAssembly_SectionType_CHECKSUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "LOSUNW", .value = System_ELFAssembly_SectionType_LOSUNW },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SUNW_move", .value = System_ELFAssembly_SectionType_SUNW_move },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SUNW_COMDAT", .value = System_ELFAssembly_SectionType_SUNW_COMDAT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SUNW_syminfo", .value = System_ELFAssembly_SectionType_SUNW_syminfo },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_verdef", .value = System_ELFAssembly_SectionType_GNU_verdef },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_verneed", .value = System_ELFAssembly_SectionType_GNU_verneed },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_versym", .value = System_ELFAssembly_SectionType_GNU_versym },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HISUNW", .value = System_ELFAssembly_SectionType_HISUNW },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HIOS", .value = System_ELFAssembly_SectionType_HIOS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "LOPROC", .value = System_ELFAssembly_SectionType_LOPROC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HIPROC", .value = System_ELFAssembly_SectionType_HIPROC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "LOUSER", .value = System_ELFAssembly_SectionType_LOUSER },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HIUSER", .value = System_ELFAssembly_SectionType_HIUSER },
};

struct System_Type System_ELFAssembly_SectionTypeType = { .base = { .type = typeof(System_Type) },
    .name = "SectionType",
    .size = sizeof(System_ELFAssembly_SectionType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_SectionTypeTypeFields, .length = sizeof_array(System_ELFAssembly_SectionTypeTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_SectionFlagsTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "None", .value = System_ELFAssembly_SectionFlags_None },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Writable", .value = System_ELFAssembly_SectionFlags_Writable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Alloc", .value = System_ELFAssembly_SectionFlags_Alloc },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Executable", .value = System_ELFAssembly_SectionFlags_Executable },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Merge", .value = System_ELFAssembly_SectionFlags_Merge },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "Strings", .value = System_ELFAssembly_SectionFlags_Strings },
};

struct System_Type System_ELFAssembly_SectionFlagsType = { .base = { .type = typeof(System_Type) },
    .name = "SectionFlags",
    .size = sizeof(System_ELFAssembly_SectionFlags),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_SectionFlagsTypeFields, .length = sizeof_array(System_ELFAssembly_SectionFlagsTypeFields),
    },
};

struct System_Type_FieldInfo  System_ELFAssembly_DynamicTypeTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NULL", .value = System_ELFAssembly_DynamicType_NULL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NEEDED", .value = System_ELFAssembly_DynamicType_NEEDED },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLTRELSZ", .value = System_ELFAssembly_DynamicType_PLTRELSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLTGOT", .value = System_ELFAssembly_DynamicType_PLTGOT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HASH", .value = System_ELFAssembly_DynamicType_HASH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "STRTAB", .value = System_ELFAssembly_DynamicType_STRTAB },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMTAB", .value = System_ELFAssembly_DynamicType_SYMTAB },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELA", .value = System_ELFAssembly_DynamicType_RELA },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELASZ", .value = System_ELFAssembly_DynamicType_RELASZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELAENT", .value = System_ELFAssembly_DynamicType_RELAENT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "STRSZ", .value = System_ELFAssembly_DynamicType_STRSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMENT", .value = System_ELFAssembly_DynamicType_SYMENT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "INIT", .value = System_ELFAssembly_DynamicType_INIT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FINI", .value = System_ELFAssembly_DynamicType_FINI },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SONAME", .value = System_ELFAssembly_DynamicType_SONAME },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RPATH", .value = System_ELFAssembly_DynamicType_RPATH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMBOLIC", .value = System_ELFAssembly_DynamicType_SYMBOLIC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "REL", .value = System_ELFAssembly_DynamicType_REL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELSZ", .value = System_ELFAssembly_DynamicType_RELSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELENT", .value = System_ELFAssembly_DynamicType_RELENT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLTREL", .value = System_ELFAssembly_DynamicType_PLTREL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DEBUG", .value = System_ELFAssembly_DynamicType_DEBUG },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TEXTREL", .value = System_ELFAssembly_DynamicType_TEXTREL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "JMPREL", .value = System_ELFAssembly_DynamicType_JMPREL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BIND_NOW", .value = System_ELFAssembly_DynamicType_BIND_NOW },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "INIT_ARRAY", .value = System_ELFAssembly_DynamicType_INIT_ARRAY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FINI_ARRAY", .value = System_ELFAssembly_DynamicType_FINI_ARRAY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "INIT_ARRAYSZ", .value = System_ELFAssembly_DynamicType_INIT_ARRAYSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FINI_ARRAYSZ", .value = System_ELFAssembly_DynamicType_FINI_ARRAYSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RUNPATH", .value = System_ELFAssembly_DynamicType_RUNPATH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FLAGS", .value = System_ELFAssembly_DynamicType_FLAGS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ENCODING", .value = System_ELFAssembly_DynamicType_ENCODING },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PREINIT_ARRAY", .value = System_ELFAssembly_DynamicType_PREINIT_ARRAY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PREINIT_ARRAYSZ", .value = System_ELFAssembly_DynamicType_PREINIT_ARRAYSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMTAB_SHNDX", .value = System_ELFAssembly_DynamicType_SYMTAB_SHNDX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NUM", .value = System_ELFAssembly_DynamicType_NUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "LOOS", .value = System_ELFAssembly_DynamicType_LOOS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HIOS", .value = System_ELFAssembly_DynamicType_HIOS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "LOPROC", .value = System_ELFAssembly_DynamicType_LOPROC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HIPROC", .value = System_ELFAssembly_DynamicType_HIPROC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MIPSNUM", .value = System_ELFAssembly_DynamicType_MIPSNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PROCNUM", .value = System_ELFAssembly_DynamicType_PROCNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VALRNGLO", .value = System_ELFAssembly_DynamicType_VALRNGLO },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_PRELINKED", .value = System_ELFAssembly_DynamicType_GNU_PRELINKED },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_CONFLICTSZ", .value = System_ELFAssembly_DynamicType_GNU_CONFLICTSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_LIBLISTSZ", .value = System_ELFAssembly_DynamicType_GNU_LIBLISTSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CHECKSUM", .value = System_ELFAssembly_DynamicType_CHECKSUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLTPADSZ", .value = System_ELFAssembly_DynamicType_PLTPADSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MOVEENT", .value = System_ELFAssembly_DynamicType_MOVEENT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MOVESZ", .value = System_ELFAssembly_DynamicType_MOVESZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FEATURE_1", .value = System_ELFAssembly_DynamicType_FEATURE_1 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "POSFLAG_1", .value = System_ELFAssembly_DynamicType_POSFLAG_1 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMINSZ", .value = System_ELFAssembly_DynamicType_SYMINSZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMINENT", .value = System_ELFAssembly_DynamicType_SYMINENT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VALRNGHI", .value = System_ELFAssembly_DynamicType_VALRNGHI },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VALNUM", .value = System_ELFAssembly_DynamicType_VALNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ADDRRNGLO", .value = System_ELFAssembly_DynamicType_ADDRRNGLO },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_HASH", .value = System_ELFAssembly_DynamicType_GNU_HASH },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TLSDESC_PLT", .value = System_ELFAssembly_DynamicType_TLSDESC_PLT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TLSDESC_GOT", .value = System_ELFAssembly_DynamicType_TLSDESC_GOT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_CONFLICT", .value = System_ELFAssembly_DynamicType_GNU_CONFLICT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GNU_LIBLIST", .value = System_ELFAssembly_DynamicType_GNU_LIBLIST },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CONFIG", .value = System_ELFAssembly_DynamicType_CONFIG },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DEPAUDIT", .value = System_ELFAssembly_DynamicType_DEPAUDIT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AUDIT", .value = System_ELFAssembly_DynamicType_AUDIT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLTPAD", .value = System_ELFAssembly_DynamicType_PLTPAD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MOVETAB", .value = System_ELFAssembly_DynamicType_MOVETAB },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYMINFO", .value = System_ELFAssembly_DynamicType_SYMINFO },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ADDRRNGHI", .value = System_ELFAssembly_DynamicType_ADDRRNGHI },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ADDRNUM", .value = System_ELFAssembly_DynamicType_ADDRNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VERSYM", .value = System_ELFAssembly_DynamicType_VERSYM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELACOUNT", .value = System_ELFAssembly_DynamicType_RELACOUNT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELCOUNT", .value = System_ELFAssembly_DynamicType_RELCOUNT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FLAGS_1", .value = System_ELFAssembly_DynamicType_FLAGS_1 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VERDEF", .value = System_ELFAssembly_DynamicType_VERDEF },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VERDEFNUM", .value = System_ELFAssembly_DynamicType_VERDEFNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VERNEED", .value = System_ELFAssembly_DynamicType_VERNEED },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VERNEEDNUM", .value = System_ELFAssembly_DynamicType_VERNEEDNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "VERSIONTAGNUM", .value = System_ELFAssembly_DynamicType_VERSIONTAGNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "AUXILIARY", .value = System_ELFAssembly_DynamicType_AUXILIARY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FILTER", .value = System_ELFAssembly_DynamicType_FILTER },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EXTRANUM", .value = System_ELFAssembly_DynamicType_EXTRANUM },
};

struct System_Type System_ELFAssembly_DynamicTypeType = { .base = { .type = typeof(System_Type) },
    .name = "DynamicType",
    .size = sizeof(System_ELFAssembly_DynamicType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_DynamicTypeTypeFields, .length = sizeof_array(System_ELFAssembly_DynamicTypeTypeFields),
    },
};


struct System_Type_FieldInfo  System_ELFAssembly_AMD64RelocationTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NONE", .value = System_ELFAssembly_AMD64Relocation_NONE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "64", .value = System_ELFAssembly_AMD64Relocation_64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PC32", .value = System_ELFAssembly_AMD64Relocation_PC32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOT32", .value = System_ELFAssembly_AMD64Relocation_GOT32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLT32", .value = System_ELFAssembly_AMD64Relocation_PLT32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "COPY", .value = System_ELFAssembly_AMD64Relocation_COPY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GLOB_DAT", .value = System_ELFAssembly_AMD64Relocation_GLOB_DAT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "JUMP_SLOT", .value = System_ELFAssembly_AMD64Relocation_JUMP_SLOT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELATIVE", .value = System_ELFAssembly_AMD64Relocation_RELATIVE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTPCREL", .value = System_ELFAssembly_AMD64Relocation_GOTPCREL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "32", .value = System_ELFAssembly_AMD64Relocation_32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "32S", .value = System_ELFAssembly_AMD64Relocation_32S },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "16", .value = System_ELFAssembly_AMD64Relocation_16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PC16", .value = System_ELFAssembly_AMD64Relocation_PC16 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "8", .value = System_ELFAssembly_AMD64Relocation_8 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PC8", .value = System_ELFAssembly_AMD64Relocation_PC8 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DTPMOD64", .value = System_ELFAssembly_AMD64Relocation_DTPMOD64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DTPOFF64", .value = System_ELFAssembly_AMD64Relocation_DTPOFF64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TPOFF64", .value = System_ELFAssembly_AMD64Relocation_TPOFF64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TLSGD", .value = System_ELFAssembly_AMD64Relocation_TLSGD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TLSLD", .value = System_ELFAssembly_AMD64Relocation_TLSLD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DTPOFF32", .value = System_ELFAssembly_AMD64Relocation_DTPOFF32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTTPOFF", .value = System_ELFAssembly_AMD64Relocation_GOTTPOFF },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TPOFF32", .value = System_ELFAssembly_AMD64Relocation_TPOFF32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PC64", .value = System_ELFAssembly_AMD64Relocation_PC64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTOFF64", .value = System_ELFAssembly_AMD64Relocation_GOTOFF64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTPC32", .value = System_ELFAssembly_AMD64Relocation_GOTPC32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOT64", .value = System_ELFAssembly_AMD64Relocation_GOT64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTPCREL64", .value = System_ELFAssembly_AMD64Relocation_GOTPCREL64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTPC64", .value = System_ELFAssembly_AMD64Relocation_GOTPC64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTPLT64", .value = System_ELFAssembly_AMD64Relocation_GOTPLT64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLTOFF64", .value = System_ELFAssembly_AMD64Relocation_PLTOFF64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SIZE32", .value = System_ELFAssembly_AMD64Relocation_SIZE32 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SIZE64", .value = System_ELFAssembly_AMD64Relocation_SIZE64 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTPC32_TLSDESC", .value = System_ELFAssembly_AMD64Relocation_GOTPC32_TLSDESC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TLSDESC_CALL", .value = System_ELFAssembly_AMD64Relocation_TLSDESC_CALL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "TLSDESC", .value = System_ELFAssembly_AMD64Relocation_TLSDESC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IRELATIVE", .value = System_ELFAssembly_AMD64Relocation_IRELATIVE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RELATIVE64", .value = System_ELFAssembly_AMD64Relocation_RELATIVE64 },
    /* 39 Reserved was System_ELFAssembly_AMD64Relocation_PC32_BND */
    /* 40 Reserved was System_ELFAssembly_AMD64Relocation_PLT32_BND */
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GOTPCRELX", .value = System_ELFAssembly_AMD64Relocation_GOTPCRELX },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "REX_GOTPCRELX", .value = System_ELFAssembly_AMD64Relocation_REX_GOTPCRELX },
};

struct System_Type System_ELFAssembly_AMD64RelocationType = { .base = { .type = typeof(System_Type) },
    .name = "AMD64Relocation",
    .size = sizeof(System_ELFAssembly_AMD64RelocationType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_AMD64RelocationTypeFields, .length = sizeof_array(System_ELFAssembly_AMD64RelocationTypeFields),
    },
};

#endif