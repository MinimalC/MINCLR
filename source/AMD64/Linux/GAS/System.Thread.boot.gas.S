# Gemeinfrei. Public Domain.
.text
.global System_Thread_boot
.type   System_Thread_boot,@function
System_Thread_boot:

    movq $158,%rax /* System_Syscall_Command_arch_prctl */
    movq $4098,%rdi /* ARCH_SET_FS */
    movq (%rsp),%rsi /* arg0: tls */
    syscall

    movq 8(%rsp),%r11    /* arg1: function */
    movq 16(%rsp),%rdi    /* arg2: argc */
    movq %rsp,%rsi        /* arg3: argv */
    addq $24,%rsi
    call *%r11

    movq %rax,%rdi    /* true */
    movq $60,%rax    /* System_Syscall_Command_exit */
    syscall

.size System_Thread_boot,.-System_Thread_boot
