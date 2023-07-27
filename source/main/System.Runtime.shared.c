/* Gemeinfrei. Public Domain. */
#if !defined(code_System_Runtime)
asm(
".global _start\n"
".hidden _start\n"
".type _start,\u0040function\n"
"_start:\n"
"    xor %rbp,%rbp\n"
"    mov %rsp,%rdi\n"
".weak _DYNAMIC\n"
".hidden _DYNAMIC\n"
"    lea _DYNAMIC(%rip),%rsi\n"
//"    and $-16,%rsp\n"
"    jmp System_Runtime_start\n"
".size _start,.-_start\n"
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

#define ROUNDDOWN(X,ALIGN)  ((X) & ~(ALIGN - 1))

System_Size * System_Runtime_stack = null;

void System_Runtime_start(Var  * stack) {

    System_Runtime_stack = (Size *)stack;
    Size argc = (Size)*stack;
    String8 * argv = (String8 *)(++stack);
    Size envc = 0;
    String8 * envv = (String8 *)(stack = stack + argc + 1);
    while (*stack) { ++envc; ++stack; }

#if DEBUG == DEBUG_System_Console_Environment_Arguments || DEBUG == DEBUG_System_ELFAssembly
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
    /* struct vdso_info info = { .valid = false }; */
    System_Size auxc = 0;
    for (Size i = 0; auxv[i].type && i < System_Environment_AuxValues_Length; ++i) {
        ++auxc;
        System_Environment_AuxValues[auxv[i].type].type = auxv[i].type;
        System_Environment_AuxValues[auxv[i].type].value = auxv[i].value;

        switch (auxv[i].type) {
        case System_Environment_AuxType_BASE:
            base = (System_Var)(auxv[i].value); break;
        }
        /*if (auxv[i].type == System_Environment_AuxType_SYSINFO_EHDR) {
            vdso_init_from_sysinfo_ehdr(&info, (System_ELFAssembly_Header)auxv[i].value);
            continue;
        }*/

#if DEBUG == DEBUG_System_Console_Environment_Arguments || DEBUG == DEBUG_System_ELFAssembly
        switch (auxv[i].type) {
        case System_Environment_AuxType_EXECFN:
        case System_Environment_AuxType_PLATFORM:
            System_Console_writeLine("System_Environment_AuxValue({0:uint}): type ({1:string}), value {2:string}", 3, i, System_Environment_AuxType_toString(auxv[i].type), auxv[i].value); 
            break;
        default:
            System_Console_writeLine("System_Environment_AuxValue({0:uint}): type ({1:string}), value 0x{2:uint:hex}", 3, i, System_Environment_AuxType_toString(auxv[i].type), auxv[i].value); 
            break;
        }
#endif
    }

    function_System_Runtime_main entry = &System_Runtime_main;
#if DEBUG == DEBUG_System_ELFAssembly
extern System_Size _DYNAMIC;
System_Console_writeLine("AddressOf _DYNAMIC: {0:uint:hex}", 2, &_DYNAMIC);
System_Console_writeLine("AddressOf System_Runtime_stack: {0:uint:hex}", 1, System_Runtime_stack);
System_Console_writeLine("AddressOf System_Runtime_main: {0:uint:hex}", 1, entry);
System_Console_writeLine("System_Runtime_start: argc {0:uint}, envc {1:uint}, auxc {2:uint}: {3:string}", 4, argc, envc, auxc, argv[0]);
#endif

    int reture = entry(argc, argv);
#if DEBUG == DEBUG_System_ELFAssembly
System_Console_writeLine("System_Runtime_start: return {0:uint}", 1, reture);
#endif

    System_Syscall_terminate(reture);
}

#endif