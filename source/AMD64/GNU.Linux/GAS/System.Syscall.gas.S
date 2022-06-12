/* Gemeinfrei. Public Domain. */

#include <min/linux/x86_64/System.gas.h>

.text

__function(System_Syscall_call00)
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
__end_function(System_Syscall_call00)

__function(System_Syscall_call01)
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
__end_function(System_Syscall_call01)

__function(System_Syscall_call02)
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    movq  %rdx, %rsi    /* arg2 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
__end_function(System_Syscall_call02)

__function(System_Syscall_call03)
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    movq  %rdx, %rsi    /* arg2 */
    movq  %rcx, %rdx    /* arg3 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
__end_function(System_Syscall_call03)

__function(System_Syscall_call04)
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    movq  %rdx, %rsi    /* arg2 */
    movq  %rcx, %rdx    /* arg3 */
    movq  %r8, %r10     /* arg4 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
__end_function(System_Syscall_call04)

__function(System_Syscall_call05)
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    movq  %rdx, %rsi    /* arg2 */
    movq  %rcx, %rdx    /* arg3 */
    movq  %r8, %r10     /* arg4 */
    movq  %r9, %r8      /* arg5 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
__end_function(System_Syscall_call05)

__function(System_Syscall_call06)
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    movq  %rdx, %rsi    /* arg2 */
    movq  %rcx, %rdx    /* arg3 */
    movq  %r8, %r10     /* arg4 */
    movq  %r9, %r8      /* arg5 */
    movq  8(%rsp),%r9   /* arg6 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
__end_function(System_Syscall_call06)

__hidden_function(System_Syscall_good)
    movq  $0, %rdi
    __call(System_Syscall_error)
    movq  (%rsp), %rax  /* pop */
    add   $8, %rsp
    ret
__end_function(System_Syscall_good)

__hidden_function(System_Syscall_failed)
    negq  %rax
    movq  %rax, %rdi
    __call(System_Syscall_error)
    movq  $0, %rax      /* return 0 */
    add   $8, %rsp
    ret
__end_function(System_Syscall_failed)
