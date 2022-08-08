/* Gemeinfrei. Public Domain. */
#if !defined(code_System_Runtime)
asm(".text\n"
".global System_Runtime_start\n"
".global _start\n"
".type _start,@function\n"
"_start:\n"
"    xor %rbp,%rbp\n"
"    mov %rsp,%rdi\n"
".weak _DYNAMIC\n"
".hidden _DYNAMIC\n"
"    lea _DYNAMIC(%rip),%rsi\n"
"    and $-16,%rsp\n"
"    jmp System_Runtime_start\n"
);
#endif
#if !defined(internal_System)
#include "internal.System.h"
#endif
#if !defined(have_System_Runtime)
#include <min/System.Runtime.h>
#endif
#if !defined(have_System_ELFAssembly)
#include <min/System.ELFAssembly.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(code_System_Runtime)
#define code_System_Runtime

typedef struct vdso_info {
    Bool valid;

    /* Load information */
    System_ELFAssembly_Header header;
    System_Var load_offset;  /* load_addr - recorded vaddr */
    System_Var entryPoint;

    System_ELFAssembly_ProgramHeader program;
    System_ELFAssembly_DynamicEntry dynamic;

    /* Symbol table */
    System_ELFAssembly_SymbolEntry  symbols;
    System_Size symbolSize;
    System_String8 strings;
    System_Size stringsSize;

    System_UInt32 *bucket, *chain;
    System_UInt32 nbucket, nchain;

    /* Version table */
    System_UInt16 *versym;
    System_ELFAssembly_VersionDefinition verdef;
} * vdso_info;

Bool vdso_init_from_sysinfo_ehdr(vdso_info info, System_ELFAssembly_Header header) {

    info->valid = false;
    info->header = header;
    info->load_offset = null;

    if (header->class != (System_Size_Width == 32 ? System_ELFAssembly_Class_32 : System_ELFAssembly_Class_64)) {
        return false;  /* Wrong ELF class -- check ELF_BITS */
    }
System_Console_write("ELF_Header: type {0:string}, machine {1:string}, version {2:uint}, size {3:uint}", 4, 
    System_enum_getName(typeof(System_ELFAssembly_AssemblyType), header->type),
    System_enum_getName(typeof(System_ELFAssembly_Machine), header->machine),
    header->version,
    header->size);
System_Console_writeLine(", class {0:uint}, endianess {1:uint}, elfVersion {2:uint}, abi {3:string}", 4, 
    header->class, header->endianess, header->elfVersion,
    System_enum_getName(typeof(System_ELFAssembly_ABI), header->abi));

    info->program = (System_ELFAssembly_ProgramHeader)((System_Var)header + header->programHeaderOffset);
    info->dynamic = null;

    /* We need two things from the segment table: the load offset and the dynamic table. */
    for (Size i = 0; i < header->programHeaderCount; i++) {            
        if (info->program[i].type == System_ELFAssembly_ProgramType_Loadable) {
            info->load_offset = (System_Var)header + info->program[i].offset - info->program[i].virtualAddress;
System_Console_write__string("using ");
        } else if (info->program[i].type == System_ELFAssembly_ProgramType_Dynamic) {
            info->dynamic = (System_ELFAssembly_DynamicEntry)((System_Var)header + info->program[i].offset);
System_Console_write__string("using ");
        }
System_Console_writeLine("ELF_ProgramHeader({0:uint}): type {1:string}, fileSize {2:uint}, memorySize {3:uint}", 4, i, 
    System_enum_getName(typeof(System_ELFAssembly_ProgramType), info->program[i].type),
    info->program[i].fileSize, info->program[i].memorySize);
    }

    if (!info->load_offset || !info->dynamic)
        return false;  /* Failed */

    info->entryPoint = (System_Var)(info->load_offset + header->entryPoint);

    /* Fish out the useful bits of the dynamic table. */
    System_UInt32 *hash = 0;
    info->strings = 0;
    info->symbols = 0;
    info->versym = 0;
    info->verdef = 0;
    for (Size i = 0; info->dynamic[i].tag != System_ELFAssembly_DynamicType_NULL; i++) {
        switch (info->dynamic[i].tag) {
        case System_ELFAssembly_DynamicType_STRSZ:
            info->stringsSize = (System_Size)info->dynamic[i].value;
            break;
        case System_ELFAssembly_DynamicType_STRTAB:
            info->strings = (String8)((System_Size)info->dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_SYMENT:
            info->symbolSize = (System_Size)info->dynamic[i].value;
            break;
        case System_ELFAssembly_DynamicType_SYMTAB:
            info->symbols = (System_ELFAssembly_SymbolEntry)((System_Size)info->dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_HASH:
            hash = (System_UInt32 *)((System_Size)info->dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_VERSYM:
            info->versym = (System_UInt16 *)((System_Size)info->dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_VERDEF:
            info->verdef = (System_ELFAssembly_VersionDefinition)((System_Size)info->dynamic[i].value + info->load_offset);
            break;
        }
System_Console_writeLine("ELF_DynamicEntry({0:uint}): tag {1:string}, value {2:uint}", 3, i, 
    System_enum_getName(typeof(System_ELFAssembly_DynamicType), info->dynamic[i].tag),
    info->dynamic[i].value);
    }
    if (!info->strings || !info->symbols || !hash) return false;  /* Failed */

    if (!info->verdef) info->versym = 0;

    /* Parse the hash table header. */
    info->nbucket = hash[0];
    info->nchain = hash[1];
    info->bucket = &hash[2];
    info->chain = &hash[info->nbucket + 2];

    /* That's all we need. */
    return info->valid = true;
}

struct System_ELFAssembly_AuxValue System_ELFAssembly_AuxValue_Current[System_ELFAssembly_AuxValue_Current_Length_VALUE] = { };


void System_Runtime_start(Var  * stack) {

    Size argc = (Size)*stack;
    String8 * argv = (String8 *)(++stack);
    Size envc = 0;
    String8 * envv = (String8 *)(stack += argc + 1);
    while (*stack) { ++envc; ++stack; }

    for (Size i = 0; i < argc; ++i)
System_Console_writeLine("System_Console_Arguments({0:uint}): {1:string}", 2, i, argv[i]);

    for (Size i = 0; i < envc; ++i)
System_Console_writeLine("System_Environment_Arguments({0:uint}): {1:string}", 2, i, envv[i]);

    System_ELFAssembly_AuxValue auxv = (System_ELFAssembly_AuxValue)(++stack);
    System_ELFAssembly_Header header = null;
    System_ELFAssembly_ProgramHeader program = null;
    function_System_Runtime_main entryPoint = null;
    System_Size pageSize = 0, programCount = 0;
    struct vdso_info info = { .valid = false };
    Size auxc = 0;
    for (Size i = 0; auxv[i].type != System_ELFAssembly_AuxType_NULL; ++i) {
        ++auxc;
        System_ELFAssembly_AuxValue_Current[i].type = auxv[i].type;
        System_ELFAssembly_AuxValue_Current[i].value = auxv[i].value;
System_Console_writeLine("System_ELFAssembly_AuxValue({0:uint}): type {1:string}, value {2:uint}", 3, i,
    System_enum_getName(typeof(System_ELFAssembly_AuxType), auxv[i].type),
    auxv[i].value);
        if (auxv[i].type == System_ELFAssembly_AuxType_SYSINFO_EHDR) {
            vdso_init_from_sysinfo_ehdr(&info, (System_ELFAssembly_Header)auxv[i].value);
            break;
        }
        switch (auxv[i].type) {
        case System_ELFAssembly_AuxType_BASE:
            header = (System_ELFAssembly_Header)(auxv[i].value);
            break;
        case System_ELFAssembly_AuxType_ENTRY:
            entryPoint = (function_System_Runtime_main)(auxv[i].value);
            break;
        case System_ELFAssembly_AuxType_PAGESZ:
            pageSize = (System_Size)(auxv[i].value);
            break;
        case System_ELFAssembly_AuxType_PHDR:
            program = (System_ELFAssembly_ProgramHeader)(auxv[i].value); 
            break;
        case System_ELFAssembly_AuxType_PHNUM:
            programCount = (System_Size)(auxv[i].value); 
            break;
        }
    }
    int reture = info.valid;  /* info.valid; */

System_Console_writeLine("System_Runtime_start: argc {0:uint}, envc {1:uint}, auxc {2:uint}, return {3:uint}, entryPoint {4:uint}", 5, argc, envc, auxc, reture, info.entryPoint);

    /* TODO */

    if (!info.valid) /* try base + entryPoint */
        System_Console_writeLine__string("System_Runtime_start: EntryPoint not found.");
    else
        reture = entryPoint(argc, argv);

    System_Syscall_terminate(reture);
}

#endif