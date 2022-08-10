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
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(code_System_Runtime)
#define code_System_Runtime

typedef struct vdso_info {
    Bool valid;

    /* Load information */
    System_ELFAssembly_Header header;
    System_Var load_offset;  /* load_addr - recorded vaddr */
    /* function_System_Runtime_main entryPoint; */

    System_ELFAssembly_ProgramHeader program;
    System_ELFAssembly_DynamicEntry dynamic;
    System_Size dynamicCount;

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

    if (!System_String8_equals(header->magic, System_ELFAssembly_Magic)) {
        return false;
    }
    if (header->class != (System_Size_Width == 32 ? System_ELFAssembly_Class_32 : System_ELFAssembly_Class_64)) {
        return false;  /* Wrong ELF class -- check ELF_BITS */
    }
#if DEBUG == DEBUG_System_Runtime
System_Console_write("vDSO ELF_Header: type {0:string}, machine {1:string}, version {2:uint}, entryPoint 0x{3:uint:hex}, size {4:uint}", 5, 
    System_enum_getName(typeof(System_ELFAssembly_AssemblyType), header->type),
    System_enum_getName(typeof(System_ELFAssembly_Machine), header->machine),
    header->version, header->entryPoint, header->size);
System_Console_writeLine(", class {0:uint}, endianess {1:uint}, elfVersion {2:uint}, abi {3:string}", 4, 
    header->class, header->endianess, header->elfVersion,
    System_enum_getName(typeof(System_ELFAssembly_ABI), header->abi));
#endif

    info->program = (System_ELFAssembly_ProgramHeader)((System_Var)header + header->programHeaderOffset);
    info->dynamic = null;

    /* We need two things from the segment table: the load offset and the dynamic table. */
    for (Size using = false, i = 0; i < header->programHeaderCount; using = false, ++i) {
        if (info->program[i].type == System_ELFAssembly_ProgramType_Loadable) {
            info->load_offset = (System_Var)header + info->program[i].offset - info->program[i].virtualAddress;
            using = true;
        } else if (info->program[i].type == System_ELFAssembly_ProgramType_Dynamic) {
            info->dynamic = (System_ELFAssembly_DynamicEntry)((System_Var)header + info->program[i].offset);
            info->dynamicCount = info->program[i].memorySize / sizeof(struct System_ELFAssembly_DynamicEntry);
            using = true;
        }
#if DEBUG == DEBUG_System_Runtime
System_Console_writeLine("vDSO ELF_ProgramHeader({0:uint}): used {1:bool}, type {2:string}, offset {3:uint}, virtualAddress {4:uint}, physicalAddress {5:uint}, fileSize {6:uint}, memorySize {7:uint}", 8, i, 
    using, System_enum_getName(typeof(System_ELFAssembly_ProgramType), info->program[i].type),
    info->program[i].offset, info->program[i].virtualAddress, info->program[i].physicalAddress, info->program[i].fileSize, info->program[i].memorySize);
#endif
    }

    if (!info->load_offset || !info->dynamic)
        return false;  /* Failed */

    /* info->entryPoint = (function_System_Runtime_main)(header->entryPoint + info->load_offset); */

    /* Fish out the useful bits of the dynamic table. */
    System_UInt32 *hash = 0;
    info->strings = 0;
    info->symbols = 0;
    info->versym = 0;
    info->verdef = 0;
    for (Size i = 0; i < info->dynamicCount && info->dynamic[i].tag != System_ELFAssembly_DynamicType_NULL; ++i) {
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
#if DEBUG == DEBUG_System_Runtime
System_Console_writeLine("vDSO ELF_DynamicEntry({0:uint}): tag {1:string}, value {2:uint}", 3, i, 
    System_enum_getName(typeof(System_ELFAssembly_DynamicType), info->dynamic[i].tag),
    info->dynamic[i].value);
#endif
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
    String8 * envv = (String8 *)(stack = stack + argc + 1);
    while (*stack) { ++envc; ++stack; }

#if DEBUG == DEBUG_System_Console_Environment_Arguments
    for (Size i = 0; i < argc; ++i)
        System_Console_writeLine("System_Console_Arguments({0:uint}): {1:string}", 2, i, argv[i]);
    for (Size i = 0; i < envc; ++i)
        System_Console_writeLine("System_Environment_Arguments({0:uint}): {1:string}", 2, i, envv[i]);
#endif

    System_ELFAssembly_AuxValue auxv = (System_ELFAssembly_AuxValue)(++stack);
    /*System_Var base = null;
    System_Size programHeader = 0, programHeaderSize = 0, programHeaderCount = 0, entryPoint = 0; */
    struct vdso_info info = { .valid = false };
    Size auxc = 0;
    for (Size i = 0; i < 64 && auxv[i].type != System_ELFAssembly_AuxType_NULL; ++i) {
        ++auxc;
        System_ELFAssembly_AuxValue_Current[i].type = auxv[i].type;
        System_ELFAssembly_AuxValue_Current[i].value = auxv[i].value;
        if (auxv[i].type == System_ELFAssembly_AuxType_SYSINFO_EHDR) {
            vdso_init_from_sysinfo_ehdr(&info, (System_ELFAssembly_Header)auxv[i].value);
            continue;
        }
#if DEBUG == DEBUG_System_Runtime
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i,
    System_enum_getName(typeof(System_ELFAssembly_AuxType), auxv[i].type),
    auxv[i].value);
#endif
        /*switch (auxv[i].type) {
        case System_ELFAssembly_AuxType_BASE:
            base = (System_Var)(auxv[i].value);
            break;
        case System_ELFAssembly_AuxType_ENTRY:
            entryPoint = (System_Size)(auxv[i].value);
            break;
        **case System_ELFAssembly_AuxType_PAGESZ:
            pageSize = (System_Size)(auxv[i].value);
            break;**
        case System_ELFAssembly_AuxType_PHDR:
            programHeader = (System_Size)(auxv[i].value); 
            break;
        case System_ELFAssembly_AuxType_PHENT:
            programHeaderSize = (System_Size)(auxv[i].value);
            break;
        case System_ELFAssembly_AuxType_PHNUM:
            programHeaderCount = (System_Size)(auxv[i].value); 
            break;
        } */
    }
    int reture = info.valid;  /* info.valid; */

#if DEBUG == DEBUG_System_Runtime
    if (!reture) System_Console_writeLine__string("System_Runtime_start: No vDSO");

    /* TODO */
    System_ELFAssembly_Header header = (System_ELFAssembly_Header)base;

System_Console_write("my ELF_Header: type {0:string}, machine {1:string}, version {2:uint}, entryPoint 0x{3:uint:hex}, size {4:uint}", 5, 
    System_enum_getName(typeof(System_ELFAssembly_AssemblyType), header->type),
    System_enum_getName(typeof(System_ELFAssembly_Machine), header->machine),
    header->version, header->entryPoint, header->size);
System_Console_writeLine(", class {0:uint}, endianess {1:uint}, elfVersion {2:uint}, abi {3:string}", 4, 
    header->class, header->endianess, header->elfVersion,
    System_enum_getName(typeof(System_ELFAssembly_ABI), header->abi));

    System_ELFAssembly_ProgramHeader program = (System_ELFAssembly_ProgramHeader)programHeader;

    for (Size using = false, i = 0; i < programHeaderCount; using = false, ++i) {
System_Console_writeLine("my ELF_ProgramHeader({0:uint}): used {1:bool}, type {2:string}, offset {3:uint}, virtualAddress {4:uint}, physicalAddress {5:uint}, fileSize {6:uint}, memorySize {7:uint}", 8, i, 
    using, System_enum_getName(typeof(System_ELFAssembly_ProgramType), program[i].type),
    program[i].offset, program[i].virtualAddress, program[i].physicalAddress, program[i].fileSize, program[i].memorySize);
    }
#endif

    function_System_Runtime_main entry = &System_Runtime_main;
#if DEBUG == DEBUG_System_Runtime
System_Console_writeLine("System_Runtime_start: argc {0:uint}, envc {1:uint}, auxc {2:uint}, return {3:uint}, entry 0x{4:uint:hex}", 5, argc, envc, auxc, reture, entry);
#endif
    reture = entry(argc, argv);

    System_Syscall_terminate(reture);
}

#endif