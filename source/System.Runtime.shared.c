/* Gemeinfrei. Public Domain. */
#if !defined(code_System_Runtime)
asm(".text\n"
".global _start\n"
".type _start,@function\n"
"_start:\n"
"    xor %rbp,%rbp\n"
"    mov %rsp,%rdi\n"
".weak System_Runtime_START\n"
".hidden System_Runtime_START\n"
"    lea System_Runtime_START(%rip),%rsi\n"
"    and $-16,%rsp\n"
"    jmp System_Runtime_start\n");
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
    System_Var load_address;
    System_Var load_offset;  /* load_addr - recorded vaddr */

    /* Symbol table */
    System_ELFAssembly_Symbol  symtab;
    System_String8 symstrings;
    System_UInt32 *bucket, *chain;
    System_UInt32 nbucket, nchain;

    /* Version table */
    System_UInt16 *versym;
    System_ELFAssembly_VersionDefinition verdef;
} * vdso_info;

Bool vdso_init_from_sysinfo_ehdr(vdso_info info, System_Var base) {
    Size i;
    Bool found_vaddr = false;

    info->valid = false;

    info->load_address = base;
    info->load_offset = null;

    System_ELFAssembly_Header header = (System_ELFAssembly_Header)base;
    if (header->class != (System_Size_Width == 32 ? System_ELFAssembly_Class_32 : System_ELFAssembly_Class_64)) {
        return false;  /* Wrong ELF class -- check ELF_BITS */
    }

    System_ELFAssembly_ProgramHeader program = (System_ELFAssembly_ProgramHeader)(info->load_address + header->programHeaderOffset);
    System_ELFAssembly_DynamicEntry dynamic = null;

    /* We need two things from the segment table: the load offset and the dynamic table. */
    for (i = 0; i < header->programHeaderCount; i++) {
        if (program[i].type == System_ELFAssembly_ProgramType_Loadable) {
            info->load_offset = base + program[i].offset - program[i].virtualAddress;
        } else if (program[i].type == System_ELFAssembly_ProgramType_Dynamic) {
            dynamic = (System_ELFAssembly_DynamicEntry)(base + program[i].offset);
        }
    }

    if (!info->load_offset || !dynamic)
        return false;  /* Failed */

    /* Fish out the useful bits of the dynamic table. */
    System_UInt32 *hash = 0;
    info->symstrings = 0;
    info->symtab = 0;
    info->versym = 0;
    info->verdef = 0;
    for (i = 0; dynamic[i].tag != System_ELFAssembly_DynamicType_NULL; i++) {
        switch (dynamic[i].tag) {
        case System_ELFAssembly_DynamicType_STRTAB:
            info->symstrings = (String8)((System_Size)dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_SYMTAB:
            info->symtab = (System_ELFAssembly_Symbol)((System_Size)dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_HASH:
            hash = (System_UInt32 *)((System_Size)dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_VERSYM:
            info->versym = (System_UInt16 *)((System_Size)dynamic[i].value + info->load_offset);
            break;
        case System_ELFAssembly_DynamicType_VERDEF:
            info->verdef = (System_ELFAssembly_VersionDefinition)((System_Size)dynamic[i].value + info->load_offset);
            break;
        }
    }
    if (!info->symstrings || !info->symtab || !hash) return false;  /* Failed */

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
    String8 * argv = (String8 *)(stack + 1);
    String8 * envp = (argv + argc + 1);
    while (*envp) ++envp;

    System_ELFAssembly_AuxValue auxv = (System_ELFAssembly_AuxValue)(envp + 1);
    struct vdso_info info;
    for (Size i = 0; auxv[i].type != System_ELFAssembly_AuxType_NULL; i++) {
        System_ELFAssembly_AuxValue_Current[i].type = auxv[i].type;
        System_ELFAssembly_AuxValue_Current[i].value = auxv[i].value;
        if (auxv[i].type == System_ELFAssembly_AuxType_SYSINFO_EHDR) {
            vdso_init_from_sysinfo_ehdr(&info, (System_Var)auxv[i].value);
        }
    }
    int reture = info.valid;

    /* TODO */

    reture = System_Runtime_main(argc, argv);

    System_Syscall_terminate(reture);
}

#endif