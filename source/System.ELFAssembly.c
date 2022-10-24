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

struct System_Type  System_ELF32AssemblyType = { .base = { .type = typeof(System_Type), }, .name = "System.ELF32Assembly", };

#endif
#if !defined(code_System_ELF64Assembly)
#define code_System_ELF64Assembly

struct System_Type  System_ELF64AssemblyType = { .base = { .type = typeof(System_Type), }, .name = "System.ELF64Assembly", };

void System_ELF64Assembly_load(System_ELF64Assembly assembly, System_String8 name) {

    System_Char8 buffer[System_UInt16_Max];
    System_Char8 strings[System_UInt16_Max];
    for (System_Size i = 0; i < System_UInt16_Max; ++i) buffer[i] = 0;
    for (System_Size i = 0; i < System_UInt16_Max; ++i) strings[i] = 0;

    struct System_File file = stack_System_File();
    if (!stack_System_File_open(&file, name, System_File_Mode_readOnly)) return;

    /* Read ELFAssembly_Header */
    System_File_read(&file, buffer, System_UInt16_Max);
    System_Memory_copyTo(buffer, sizeof(struct System_ELFAssembly_Header), &assembly->header);

    if (!System_String8_equals(assembly->header.magic, System_ELFAssembly_Magic)) return; /* TODO throw */

    /* Read ELFAssembly_ProgramHeaders */
    System_File_seek(&file, assembly->header.programHeaderOffset, System_origin_Begin);
    System_File_read(&file, buffer, System_UInt16_Max);

    for (System_Size i = 0; i < 32 && i < assembly->header.programHeaderCount; ++i) {
        System_ELFAssembly_ProgramHeader program = (System_ELFAssembly_ProgramHeader)((System_Var)buffer + (i * assembly->header.programHeaderSize));

        System_Memory_copyTo(program, sizeof(struct System_ELFAssembly_ProgramHeader), &assembly->programs[i]);
    }

    /* Read all ELFAssembly_SectionHeaders */
    System_File_seek(&file, assembly->header.sectionHeaderOffset, System_origin_Begin);
    System_File_read(&file, buffer, System_UInt16_Max);

    struct System_ELFAssembly_SectionHeader  sections[32];
    for (System_Size i = 0; i < assembly->header.sectionHeaderCount; ++i) {
        System_ELFAssembly_SectionHeader section = (System_ELFAssembly_SectionHeader)((System_Var)buffer + (i * assembly->header.sectionHeaderSize));
        System_Memory_copyTo(section, sizeof(struct System_ELFAssembly_SectionHeader), &assembly->sections[i]);
    }

    /* Read the ELFAssembly Strings Section */
    for (System_Size i = 0; i < System_UInt16_Max; ++i) assembly->strings[i] = 0;
    System_Size strings_position = sections[assembly->header.stringSectionIndex].size;
    System_File_seek(&file, sections[assembly->header.stringSectionIndex].offset, System_origin_Begin);
    System_File_read(&file, assembly->strings, strings_position);

}

#define ROUND(X,ALIGN)  (((X) + (ALIGN - 1)) & ~(ALIGN - 1))

void System_ELF64Assembly_link(System_ELF64Assembly assembly, System_String8 name) {

    System_Char8 buffer[System_UInt16_Max];
    System_Char8 strings[System_UInt16_Max];
    for (System_Size i = 0; i < System_UInt16_Max; ++i) buffer[i] = 0;
    for (System_Size i = 0; i < System_UInt16_Max; ++i) strings[i] = 0;

    struct System_File file = stack_System_File();
    if (!stack_System_File_open(&file, name, System_File_Mode_readOnly)) return;

    /* Read ELFAssembly_Header */
    System_File_read(&file, buffer, System_UInt16_Max);
    System_Memory_copyTo(buffer, sizeof(struct System_ELFAssembly_Header), &assembly->header);

    if (!System_String8_equals(assembly->header.magic, System_ELFAssembly_Magic)) return; /* TODO throw */

    /* Read ELFAssembly_ProgramHeaders */
    System_File_seek(&file, assembly->header.programHeaderOffset, System_origin_Begin);
    System_File_read(&file, buffer, System_UInt16_Max);

    for (System_Size i = 0; i < 32 && i < assembly->header.programHeaderCount; ++i) {
        System_ELFAssembly_ProgramHeader program = (System_ELFAssembly_ProgramHeader)((System_Var)buffer + (i * assembly->header.programHeaderSize));

        System_Memory_copyTo(program, sizeof(struct System_ELFAssembly_ProgramHeader), &assembly->programs[i]);
    }

    System_Size load_size = 0;
    for (System_Size i = 0; i < 32 && i < assembly->header.programHeaderCount; ++i) {
        if (assembly->programs[i].type != System_ELFAssembly_ProgramType_Loadable) continue;
        load_size = assembly->programs[i].virtualAddress + assembly->programs[i].memorySize;
    }
    load_size = ROUND(load_size, 4096);
System_Console_writeLine("load_size: {0:uint}", 1, load_size);

    System_Var base = System_Syscall_mmap(load_size, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write | System_Memory_PageFlags_Execute, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
    if (!base) return; // TODO: throw

    System_ELF64Assembly_ProgramHeader programHeader = null, loadable0 = null;
    System_ELF64Assembly_DynamicEntry dynamics = null;
    System_Size dynamicsCount = 0;
    System_UInt32 dynamicFlags = 0;
    for (System_Size i = 0; i < 32 && i < assembly->header.programHeaderCount; ++i) {
        if (!programHeader && assembly->programs[i].type == System_ELFAssembly_ProgramType_ProgramHeader) programHeader = &assembly->programs[i];
        if (!dynamics && assembly->programs[i].type == System_ELFAssembly_ProgramType_Dynamic) {
            dynamics = (System_ELF64Assembly_DynamicEntry)(base + assembly->programs[i].virtualAddress);
            dynamicsCount = assembly->programs[i].fileSize / sizeof(struct System_ELFAssembly_DynamicEntry);
            dynamicFlags = assembly->programs[i].flags;
        }
        if (assembly->programs[i].type != System_ELFAssembly_ProgramType_Loadable) continue;
        if (!loadable0) loadable0 = &assembly->programs[i];

        System_Var target = (System_Var)base + assembly->programs[i].virtualAddress;
System_Console_writeLine("ELFLoadable: fileSize {0:uint}, target {1:uint:hex}", 2, assembly->programs[i].fileSize, target);

        /* Read ELFAssembly_Program */
        System_File_seek(&file, assembly->programs[i].offset, System_origin_Begin);
        System_File_read(&file, target, assembly->programs[i].fileSize);
    }
    if (!programHeader && loadable0) programHeader = loadable0;
    if (!programHeader) return; // TODO: throw

    System_Var entry = base + assembly->header.entryPoint;
System_Console_writeLine("ELFEntryPoint: {0:uint}", 1, entry);
    
    if (dynamics) {
        System_ELF64Assembly_linkDynamic(base, dynamics, dynamicsCount, dynamicFlags);
    }

}

void System_ELF64Assembly_linkDynamic(System_Var base, System_ELF64Assembly_DynamicEntry dynamics, System_Size dynamicsCount, System_UInt32 dynamicFlags) {

    System_String8 strings = null;
    System_Size stringsSize = 0, symbolSize = 0, PLT_relocationCount = 0, GOT_relocationCount = 0, neededCount = 0;
    System_ELF64Assembly_SymbolEntry symbols = null;
    System_ELF64Assembly_AddendRelocation PLT_relocation = null;
    System_ELF64Assembly_AddendRelocation GOT_relocation = null;
    System_String8 needed[8];

    for (System_Size i = 0; i < dynamicsCount; ++i) {
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_NULL) break;

System_Console_writeLine("ELFDynamicEntry: tag {0:string}, value {1:uint}", 2, System_enum_getName(typeof(System_ELFAssembly_DynamicType), dynamics[i].tag), dynamics[i].value);

        switch(dynamics[i].tag) {
        case System_ELFAssembly_DynamicType_STRTAB: strings = (System_String8)(base + dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_STRSZ: stringsSize = dynamics[i].value; break;
        case System_ELFAssembly_DynamicType_SYMTAB: symbols = (System_ELF64Assembly_SymbolEntry)(base + dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_SYMENT: symbolSize = dynamics[i].value; break;

        /* case System_ELFAssembly_DynamicType_PLTREL: break; */
        case System_ELFAssembly_DynamicType_JMPREL: PLT_relocation = (System_ELF64Assembly_AddendRelocation)(base + dynamics[i].value); break;
        case System_ELFAssembly_DynamicType_RELA: GOT_relocation = (System_ELF64Assembly_AddendRelocation)(base + dynamics[i].value); break;
        /* case System_ELFAssembly_DynamicType_RELAENT: relocationSize = dynamics[i].value; break; */
        }
    }

    for (System_Size i = 0; i < dynamicsCount; ++i) {
        if (dynamics[i].tag == System_ELFAssembly_DynamicType_NULL) break;

        switch(dynamics[i].tag) {
        case System_ELFAssembly_DynamicType_NEEDED: 
            needed[neededCount++] = (System_String8)(strings + dynamics[i].value); 
System_Console_writeLine("ELFAssembly name: {0:string}", 1, (System_String8)(strings + dynamics[i].value));
            break;

        case System_ELFAssembly_DynamicType_PLTRELSZ: PLT_relocationCount = dynamics[i].value / sizeof(struct System_ELF64Assembly_AddendRelocation); break;
        case System_ELFAssembly_DynamicType_RELASZ: GOT_relocationCount = dynamics[i].value / sizeof(struct System_ELF64Assembly_AddendRelocation); break;
        }
    }

    System_ELF64Assembly_applyRelocations(base, PLT_relocation, PLT_relocationCount, symbols, strings);
    System_ELF64Assembly_applyRelocations(base, GOT_relocation, GOT_relocationCount, symbols, strings);
}

void System_ELF64Assembly_applyRelocations(System_Var base, System_ELF64Assembly_AddendRelocation relocation, System_Size relocationCount, System_ELF64Assembly_SymbolEntry symbols, System_String8 strings) {

    for (System_Size i = 0; i < relocationCount; ++i) {
        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_NONE) continue;

System_Console_write("ELFRelocation: offset {0:uint:hex}, info {1:uint32:hex}, type {2:string}, addend {3:uint:hex}", 4,
    relocation[i].offset, relocation[i].info, System_enum_getName(typeof(System_ELFAssembly_AMD64Relocation), relocation[i].type), relocation[i].addend);

        System_Size * address = (System_Size *)(base + relocation[i].offset);

        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_RELATIVE) {
System_Console_write("; address {0:uint:hex}", 1, *address);
            *address = (System_Size)base + relocation[i].addend;
System_Console_writeLine(" -> {0:uint:hex}", 1, *address);
            continue;
        }

        System_ELF64Assembly_SymbolEntry symbol = &symbols[relocation[i].info];

System_Console_write(", ELFSymbol: name {0:string}, info {1:uint8:hex}, other {2:uint8:hex}, sectionIndex {3:uint16}, value {4:uint64:hex}, size {5:uint64}", 6, 
    strings + symbol->name, symbol->info, symbol->other, symbol->sectionIndex, symbol->value, symbol->size);

System_Console_write("; address {0:uint:hex}", 1, *address);

        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_JUMP_SLOT || relocation[i].type == System_ELFAssembly_AMD64Relocation_GLOB_DAT) {
            *address = (System_Size)base + symbol->value;
        }
        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_64) {
            *address = (System_Size)base + symbol->value + relocation[i].addend;
        }
        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_32 || relocation[i].type == System_ELFAssembly_AMD64Relocation_32S) {
            *address = (System_Size)base + symbol->value + relocation[i].addend;
        }

        if (relocation[i].type == System_ELFAssembly_AMD64Relocation_COPY) { }

System_Console_writeLine(" -> {0:uint:hex}", 1, *address);

    }

}

#endif
#if !defined(code_System_ELFAssembly)
#define code_System_ELFAssembly

System_String8  System_Environment_Arguments[System_Environment_Arguments_Length] = { };

struct System_Environment_AuxValue  System_Environment_AuxValues[System_Environment_AuxValues_Length] = { };


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

struct System_Type  System_ELFAssembly_ABIType = { .base = { .type = typeof(System_Type) },
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

struct System_Type  System_ELFAssembly_AssemblyTypeType = { .base = { .type = typeof(System_Type) },
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

struct System_Type  System_ELFAssembly_MachineType = { .base = { .type = typeof(System_Type) },
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

struct System_Type  System_ELFAssembly_ProgramTypeType = { .base = { .type = typeof(System_Type) },
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

struct System_Type  System_ELFAssembly_ProgramFlagsType = { .base = { .type = typeof(System_Type) },
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

struct System_Type  System_ELFAssembly_SectionTypeType = { .base = { .type = typeof(System_Type) },
    .name = "SectionType",
    .size = sizeof(System_ELFAssembly_SectionType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_SectionTypeTypeFields, .length = sizeof_array(System_ELFAssembly_SectionTypeTypeFields),
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

struct System_Type  System_ELFAssembly_DynamicTypeType = { .base = { .type = typeof(System_Type) },
    .name = "DynamicType",
    .size = sizeof(System_ELFAssembly_DynamicType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_DynamicTypeTypeFields, .length = sizeof_array(System_ELFAssembly_DynamicTypeTypeFields),
    },
};

struct System_Type_FieldInfo  System_Environment_AuxTypeTypeFields[] = {
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NULL", .value = System_Environment_AuxType_NULL },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IGNORE", .value = System_Environment_AuxType_IGNORE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EXECFD", .value = System_Environment_AuxType_EXECFD },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PHDR", .value = System_Environment_AuxType_PHDR },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PHENT", .value = System_Environment_AuxType_PHENT },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PHNUM", .value = System_Environment_AuxType_PHNUM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PAGESZ", .value = System_Environment_AuxType_PAGESZ },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BASE", .value = System_Environment_AuxType_BASE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FLAGS", .value = System_Environment_AuxType_FLAGS },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ENTRY", .value = System_Environment_AuxType_ENTRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "NOTELF", .value = System_Environment_AuxType_NOTELF },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "UID", .value = System_Environment_AuxType_UID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EUID", .value = System_Environment_AuxType_EUID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "GID", .value = System_Environment_AuxType_GID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EGID", .value = System_Environment_AuxType_EGID },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "CLKTCK", .value = System_Environment_AuxType_CLKTCK },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "PLATFORM", .value = System_Environment_AuxType_PLATFORM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HWCAP", .value = System_Environment_AuxType_HWCAP },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "FPUCW", .value = System_Environment_AuxType_FPUCW },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "DCACHEBSIZE", .value = System_Environment_AuxType_DCACHEBSIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "ICACHEBSIZE", .value = System_Environment_AuxType_ICACHEBSIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "UCACHEBSIZE", .value = System_Environment_AuxType_UCACHEBSIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "IGNOREPPC", .value = System_Environment_AuxType_IGNOREPPC },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SECURE", .value = System_Environment_AuxType_SECURE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "BASE_PLATFORM", .value = System_Environment_AuxType_BASE_PLATFORM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "RANDOM", .value = System_Environment_AuxType_RANDOM },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "HWCAP2", .value = System_Environment_AuxType_HWCAP2 },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "EXECFN", .value = System_Environment_AuxType_EXECFN },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYSINFO", .value = System_Environment_AuxType_SYSINFO },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "SYSINFO_EHDR", .value = System_Environment_AuxType_SYSINFO_EHDR },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1I_CACHESHAPE", .value = System_Environment_AuxType_L1I_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1D_CACHESHAPE", .value = System_Environment_AuxType_L1D_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L2_CACHESHAPE", .value = System_Environment_AuxType_L2_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L3_CACHESHAPE", .value = System_Environment_AuxType_L3_CACHESHAPE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1I_CACHESIZE", .value = System_Environment_AuxType_L1I_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1I_CACHEGEOMETRY", .value = System_Environment_AuxType_L1I_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1D_CACHESIZE", .value = System_Environment_AuxType_L1D_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L1D_CACHEGEOMETRY", .value = System_Environment_AuxType_L1D_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L2_CACHESIZE", .value = System_Environment_AuxType_L2_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L2_CACHEGEOMETRY", .value = System_Environment_AuxType_L2_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L3_CACHESIZE", .value = System_Environment_AuxType_L3_CACHESIZE },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "L3_CACHEGEOMETRY", .value = System_Environment_AuxType_L3_CACHEGEOMETRY },
    { .base = stack_System_Object(System_Type_FieldInfo), .name = "MINSIGSTKSZ", .value = System_Environment_AuxType_MINSIGSTKSZ },
};

struct System_Type  System_Environment_AuxTypeType = { .base = { .type = typeof(System_Type) },
    .name = "AuxType",
    .size = sizeof(System_Environment_AuxType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_Environment_AuxTypeTypeFields, .length = sizeof_array(System_Environment_AuxTypeTypeFields),
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

struct System_Type  System_ELFAssembly_AMD64RelocationType = { .base = { .type = typeof(System_Type) },
    .name = "AMD64Relocation",
    .size = sizeof(System_ELFAssembly_AMD64RelocationType),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ELFAssembly_AMD64RelocationTypeFields, .length = sizeof_array(System_ELFAssembly_AMD64RelocationTypeFields),
    },
};

#endif