# Gemeinfrei. Public Domain.

.include "GAS.H"

.text

function System_Syscall_call00
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
end_function System_Syscall_call00

function System_Syscall_call01
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
end_function System_Syscall_call01

function System_Syscall_call02
    movq  %rdi, %rax    /* enum_System_Syscall_command */
    movq  %rsi, %rdi    /* arg1 */
    movq  %rdx, %rsi    /* arg2 */
    syscall
    sub   $8, %rsp      /* push */
    movq  %rax, (%rsp)
    cmpq  $-4095, %rax
    jae   System_Syscall_failed
    jmp   System_Syscall_good
end_function System_Syscall_call02

function System_Syscall_call03
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
end_function System_Syscall_call03

function System_Syscall_call04
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
end_function System_Syscall_call04

function System_Syscall_call05
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
end_function System_Syscall_call05

function System_Syscall_call06
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
end_function System_Syscall_call06

hidden_function System_Syscall_good
    movq  $0, %rdi
    call_function System_Syscall_error
    movq  (%rsp), %rax  /* pop */
    add   $8, %rsp
    ret
end_function System_Syscall_good

hidden_function System_Syscall_failed
    negq  %rax
    movq  %rax, %rdi
    call_function System_Syscall_error
    movq  $0, %rax      /* return 0 */
    add   $8, %rsp
    ret
end_function System_Syscall_failed
