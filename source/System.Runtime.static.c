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
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(code_System_Runtime)
#define code_System_Runtime

void System_Runtime_start(Var * stack) {

    Size argc = (Size)*stack;
    String8 * argv = (String8 *)(++stack);
    Size envc = 0;
    String8 * envp = (String8 *)(stack =+ argc + 1);
    while (*stack) { ++envc; ++stack; }

    int reture = false;

    if (!System_Runtime_main) {
        System_Debug_writeLine("System_Runtime_main not found.", 0);
        goto termin;
    }
    
    reture = System_Runtime_main(argc, argv);

termin:
    System_Syscall_terminate(reture);
}

#endif