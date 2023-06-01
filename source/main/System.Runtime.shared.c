/* Gemeinfrei. Public Domain. */
#if !defined(code_System_Runtime)
asm(
".global _start\n"
".type _start,\u0040function\n"
"_start:\n"
"    xor %rbp,%rbp\n"
"    mov %rsp,%rdi\n"
/*".weak _DYNAMIC\n"
".hidden _DYNAMIC\n"
"    lea _DYNAMIC(%rip),%rsi\n"*/
"    and $-16,%rsp\n"
"    jmp System_Runtime_start\n"
);
#endif
#if !defined(System_internal)
#include "../System.internal.h"
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
#if !defined(have_System_Environment)
#include <min/System.Environment.h>
#endif
#if !defined(code_System_Runtime)
#define code_System_Runtime


import Var _DYNAMIC;

#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

Size Environment_GetGlobalOffsetTable() {
    Size reture;
    asm("lea _GLOBAL_OFFSET_TABLE_(%%rip),%0" : "=r"(reture) );
    return reture;
}

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

    for (Size i = 0; i < argc && i < System_Console_Arguments_Length; ++i)
        System_Console_Arguments[i] = argv[i];
    for (Size i = 0; i < envc && i < System_Environment_Arguments_Length; ++i)
        System_Environment_Arguments[i] = envv[i];

    System_Environment_AuxValue auxv = (System_Environment_AuxValue)(++stack);
    System_Var base = null;
    System_Size pageSize = 0, programHeader = 0, programHeaderSize = 0, programHeaderCount = 0, entryPoint = 0;
    /* struct vdso_info info = { .valid = false }; */
    Size auxc = 0;
    for (Size i = 0; i < System_Environment_AuxValues_Length && auxv[i].type != System_Environment_AuxType_NULL; ++i) {
        ++auxc;
        System_Environment_AuxValues[i].type = auxv[i].type;
        System_Environment_AuxValues[i].value = auxv[i].value;
        /*if (auxv[i].type == System_Environment_AuxType_SYSINFO_EHDR) {
            vdso_init_from_sysinfo_ehdr(&info, (System_ELFAssembly_Header)auxv[i].value);
            continue;
        }*/
/*#if DEBUG == DEBUG_System_Console_Environment_Arguments
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i,
    System_enum_getName(typeof(System_Environment_AuxType), auxv[i].type),
    auxv[i].value);
#endif*/
        switch (auxv[i].type) {
        case System_Environment_AuxType_HWCAP:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "HWCAP", auxv[i].value);
            break;
        case System_Environment_AuxType_PAGESZ:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "PAGESZ", auxv[i].value);
            pageSize = (System_Size)(auxv[i].value);
            break;
        case System_Environment_AuxType_CLKTCK:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "CLKTCK", auxv[i].value);
            break;
        case System_Environment_AuxType_PHDR:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "PHDR", auxv[i].value);
            programHeader = (System_Size)(auxv[i].value);
            break;
        case System_Environment_AuxType_PHENT:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "PHENT", auxv[i].value);
            programHeaderSize = (System_Size)(auxv[i].value);
            break;
        case System_Environment_AuxType_PHNUM:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "PHNUM", auxv[i].value);
            programHeaderCount = (System_Size)(auxv[i].value);
            break;
        case System_Environment_AuxType_BASE:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "BASE", auxv[i].value);
            base = (System_Var)(auxv[i].value);
            break;
        case System_Environment_AuxType_FLAGS:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "FLAGS", auxv[i].value);
            break;
        case System_Environment_AuxType_ENTRY:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "ENTRY", auxv[i].value);
            entryPoint = (System_Size)(auxv[i].value);
            break;
/* System_Environment_AuxType_UID
System_Environment_AuxType_EUID
System_Environment_AuxType_GID
System_Environment_AuxType_EGID
System_Environment_AuxType_SECURE */
        case System_Environment_AuxType_RANDOM:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "RANDOM", auxv[i].value);
            break;
        case System_Environment_AuxType_HWCAP2:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value 0x{2:uint:hex}", 3, i, "HWCAP2", auxv[i].value);
            break;
        case System_Environment_AuxType_EXECFN:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value {2:string}", 3, i, "EXECFN", auxv[i].value);
            break;
        case System_Environment_AuxType_PLATFORM:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type {1:string}, value {2:string}", 3, i, "PLATFORM", auxv[i].value);
            break;
        default:
System_Console_writeLine("System_Environment_AuxValue({0:uint}): type ({1:uint}), value 0x{2:uint:hex}", 3, i, 
            auxv[i].type, auxv[i].value);
            break;
        }
    }
    int reture = false;


    function_System_Runtime_main entry = &System_Runtime_main;
#if DEBUG
System_Console_writeLine("AddressOf System_Runtime_main: {0:uint:hex}", 1, entry);
System_Console_writeLine("AddressOf String8_Empty: {0:uint:hex}", 1, System_String8_Empty);
System_ELF64Assembly_DynamicEntry GOT = (System_ELF64Assembly_DynamicEntry)Environment_GetGlobalOffsetTable();
System_Console_writeLine("AddressOf _GLOBAL_OFFSET_TABLE_: {0:uint:hex}", 1, GOT);
System_Var dynamic = &_DYNAMIC;
System_Console_writeLine("AddressOf _DYNAMIC: {0:uint:hex}", 1, dynamic);
System_Console_writeLine("System_Runtime_start: argc {0:uint}, envc {1:uint}, auxc {2:uint}: {3:string}", 4, argc, envc, auxc, argv[0]);
#endif

    reture = entry(argc, argv);
#if DEBUG
System_Console_writeLine("System_Runtime_start: return {0:uint}", 1, reture);
#endif

    System_Syscall_terminate(reture);
}

#endif