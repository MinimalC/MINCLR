
#include <min/System.String8.h>
#include <min/System.Console.h>
#include <min/System.Decimal.h>
#include <min/System.Memory.h>
#include <min/System.File.h>
#include <min/System.ELFAssembly.h>

#define ROUND(X,ALIGN)  (((X) + (ALIGN - 1)) & ~(ALIGN - 1))
#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

void ELFAssembly_read(System_String8 name) {

    System_Char8 buffer[System_UInt16_Max];
    System_Char8 strings[System_UInt16_Max];
    System_Char8 section_names[4096];
    for (System_Size i = 0; i < System_UInt16_Max; ++i) buffer[i] = 0;
    for (System_Size i = 0; i < System_UInt16_Max; ++i) strings[i] = 0;
    for (System_Size i = 0; i < 4096; ++i) section_names[i] = 0;

    struct System_File file = stack_System_File();
    if (!stack_System_File_open(&file, name, System_File_Mode_readOnly)) return;

    /* Read ELFAssembly_Header */
    System_File_read(&file, buffer, System_UInt16_Max);

    struct System_ELFAssembly_Header header;
    System_Memory_copyTo(buffer, sizeof(struct System_ELFAssembly_Header), &header);

    if (!System_String8_equals(header.magic, System_ELFAssembly_Magic)) {
        System_Console_writeLine__string("NOELF");
        return;
    }

    System_Console_write("ELF_Header: type {0:string}, machine {1:string}, version {2:uint}, entryPoint 0x{3:uint:hex}, size {4:uint}", 5,
        System_enum_getName(typeof(System_ELFAssembly_AssemblyType), header.type),
        System_enum_getName(typeof(System_ELFAssembly_Machine), header.machine),
        header.version, header.entryPoint, header.size);
    System_Console_writeLine(", class {0:uint}, endianess {1:uint}, elfVersion {2:uint}, abi {3:string}", 4,
        header.class, header.endianess, header.elfVersion,
        System_enum_getName(typeof(System_ELFAssembly_ABI), header.abi));

    /* Read ELFAssembly_ProgramHeaders */
    struct System_ELFAssembly_ProgramHeader  programs[32];
    System_File_seek(&file, header.programHeaderOffset, System_origin_Begin);
    System_File_read(&file, buffer, System_UInt16_Max);

    for (System_Size i = 0; i < 32 && i < header.programHeaderCount; ++i) {
        System_ELFAssembly_ProgramHeader program = (System_ELFAssembly_ProgramHeader)((System_Var)buffer + (i * header.programHeaderSize));

        System_Memory_copyTo(program, sizeof(struct System_ELFAssembly_ProgramHeader), &programs[i]);

        System_Console_writeLine("ELF_ProgramHeader({0:uint}): type {1:string}, offset {2:uint}, virtualAddress {3:uint}, physicalAddress {4:uint}, fileSize {5:uint}, memorySize {6:uint}", 7, i,
            System_enum_getName(typeof(System_ELFAssembly_ProgramType), program->type),
            program->offset, program->virtualAddress, program->physicalAddress, program->fileSize, program->memorySize);
    }

    /* Read ELFAssembly_ProgramHeaders contents */
    System_Size dynamicsCount = 0;
    struct System_ELFAssembly_DynamicEntry  dynamics[32];
    for (System_Size p = 0; p < header.programHeaderCount; ++p) {
        if (programs[p].type == System_ELFAssembly_ProgramType_Interpreter) {
            System_File_seek(&file, programs[p].offset, System_origin_Begin);
            System_Size bytes = System_File_read(&file, buffer, System_UInt16_Max);

            System_Console_writeLine("ELF_Interpreter: {0:string}", 1, buffer);
            continue;
        }
        if (programs[p].type == System_ELFAssembly_ProgramType_Dynamic) {
            System_File_seek(&file, programs[p].offset, System_origin_Begin);
            System_Size bytes = System_File_read(&file, buffer, System_UInt16_Max);

            System_ELFAssembly_DynamicEntry dynamic = (System_ELFAssembly_DynamicEntry)((System_Var)buffer);
            dynamicsCount = programs[p].fileSize / sizeof(struct System_ELFAssembly_DynamicEntry);

            for (System_Size i = 0; i < 32 && i < dynamicsCount; ++i) {
                if (dynamic[i].tag == System_ELFAssembly_DynamicType_NULL) break;

                System_Memory_copyTo(&dynamic[i], sizeof(struct System_ELFAssembly_DynamicEntry), &dynamics[i]);

System_Console_writeLine("ELF_DynamicEntry({0:uint}): tag {1:string}, value {2:uint:hex}", 3, i,
    System_enum_getName(typeof(System_ELFAssembly_DynamicType), dynamic[i].tag),
    dynamic[i].value);
            }
        }
    }



    /* Read all ELFAssembly_SectionHeaders */
    System_File_seek(&file, header.sectionHeaderOffset, System_origin_Begin);
    System_File_read(&file, buffer, System_UInt16_Max);

    struct System_ELFAssembly_SectionHeader  sections[32];
    for (System_Size i = 0; i < header.sectionHeaderCount; ++i) {
        System_ELFAssembly_SectionHeader section = (System_ELFAssembly_SectionHeader)((System_Var)buffer + (i * header.sectionHeaderSize));
        System_Memory_copyTo(section, sizeof(struct System_ELFAssembly_SectionHeader), &sections[i]);
    }

    /* Read the ELFAssembly SectionHeader name String Section */
    System_File_seek(&file, sections[header.stringSectionIndex].offset, System_origin_Begin);
    System_File_read(&file, section_names, 4096);

    /* Write all ELFAssembly_SectionHeaders */
    for (System_Size i = 0; i < header.sectionHeaderCount; ++i) {
        System_Console_writeLine("ELF_SectionHeader({0:uint}){1:string}: name {2:string}, type {3:string}, size {4:uint}, link {5:uint}", 6, i,
            (i == header.stringSectionIndex ? " Strings" : ""),
            &section_names[sections[i].name],
            System_enum_getName(typeof(System_ELFAssembly_SectionType), sections[i].type),
            sections[i].size,
            sections[i].link);
    }

    /* Read all ELFAssembly_SymbolEntry in section typeof SYMTAB or DYNSYM */
    for (System_Size s = 0; s < header.sectionHeaderCount; ++s) {
        if (sections[s].type == System_ELFAssembly_SectionType_SYMTAB || sections[s].type == System_ELFAssembly_SectionType_DYNSYM) {

            System_File_seek(&file, sections[s].offset, System_origin_Begin);
            System_Size bytes = System_File_read(&file, buffer, System_UInt16_Max);

            System_File_seek(&file, sections[sections[s].link].offset, System_origin_Begin);
            System_File_read(&file, strings, System_UInt16_Max);

            for (System_Size i = 0; i < System_UInt16_Max; ++i) {
                System_ELFAssembly_SymbolEntry symbol = (System_ELFAssembly_SymbolEntry)((System_Var)buffer + (i * sections[s].entrySize));
                if ((System_Var)symbol >= (System_Var)buffer + sections[s].size) break;

                System_Console_writeLine("ELF_Section({0:uint}) SymbolEntry({1:uint}): name {2:string}, value {3:uint}, size {4:uint}, info {5:uint}, other {6:uint}, sectionIndex {7:uint}", 8, s, i,
                    &strings[symbol->name], symbol->value, symbol->size, symbol->info, symbol->other, symbol->sectionIndex);
            }
        }
    }

    System_File_close(&file);
}

int System_Runtime_main(int argc, char  * argv[]) {

    if (argc < 2) {
        System_Console_writeLine__string("ELFAssembly_read <file>");
        return false;
    }

    /* ELFAssembly_read(".make/libSystem.so"); */
    ELFAssembly_read(argv[1]);

    struct System_ELF64Assembly assembly; //{ .base = { .type = typeof(System_ELF64Assembly) } };
    System_ELF64Assembly_link(&assembly, argv[1]);

    return true;
}
