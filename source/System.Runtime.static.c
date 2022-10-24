/* Gemeinfrei. Public Domain. */
#if !defined(code_System_Runtime)
asm(
".global _start\n"
".type _start,\u0040function\n"
"_start:\n"
"    xor %rbp,%rbp\n"
"    mov %rsp,%rdi\n"
"    and $-16,%rsp\n"
"    jmp System_Runtime_start\n"
);
#endif
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Runtime)
#include <min/System.Runtime.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_Environment)
#include <min/System.Environment.h>
#endif
#if !defined(code_System_Runtime)
#define code_System_Runtime

void System_Runtime_start(Var * stack) {

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

    int reture = false;

    reture = System_Runtime_main(argc, argv, envv);

    System_Syscall_terminate(reture);
}

#endif
