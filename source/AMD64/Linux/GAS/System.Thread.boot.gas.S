# Gemeinfrei. Public Domain.
.text
.global System_Thread_boot
.type   System_Thread_boot,@function
System_Thread_boot:

    movq (%rsp),%r11    /* function */
    movq 8(%rsp),%rdi    /* argc */
    movq %rsp,%rsi        /* argv */
    addq $16,%rsi
    call *%r11

    movq %rax,%rdi    /* true */
    movq $60,%rax    /* System_Syscall_Command_exit */
    syscall

.size System_Thread_boot,.-System_Thread_boot
