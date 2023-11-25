# Gemeinfrei. Public Domain.
.text
.global System_Thread_boot
.type   System_Thread_boot,@function
System_Thread_boot:

    movq $158,%rax /* System_Syscall_Command_arch_prctl */
    movq $4098,%rdi /* ARCH_SET_FS */
    movq 8(%rsp),%rsi /* arg1: tls */
    syscall
    movq __Current@gottpoff(%rip), %rax
    movq (%rsp),%rdi
    movq %rdi,%fs:(%rax)

    movq 16(%rsp),%r11    /* arg2: function */
    movq 24(%rsp),%rdi    /* arg3: argc */
    movq %rsp,%rsi        /* arg4: argv */
    addq $32,%rsi
    call *%r11
    movq (%rsp),%r10      /* arg0: that */
    movl %eax,12(%r10)    /* that->returnValue */ 

    /* movq $39,%rax       # System_Syscall_Command_getpid
    syscall
    movq %rax,%rdi
    movq $129,%rax      # System_Syscall_Command_rt_sigqueueinfo
    movq $17,%rsi       # System_Signal_Number_SIGCHILDs
    movl 8(%r10),%edx   # that->threadId
    syscall */

    movl 12(%r10),%edi    
    movq $60,%rax    /* System_Syscall_Command_exit */
    syscall

.size System_Thread_boot,.-System_Thread_boot
