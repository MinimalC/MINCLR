# Gemeinfrei. Public Domain.
.text
.global System_Thread_boot
.type   System_Thread_boot,@function
System_Thread_boot:

    movq (%rsp),%rbx    # arg0: that
    movq 24(%rbx),%rsi  # that->tls
    cmpq $0,%rsi
    je boot_no_tls
    movq $158,%rax      # System_Syscall_Command_arch_prctl
    movq $4098,%rdi     # ARCH_SET_FS
    syscall
    movq System_Thread_Current@GOTTPOFF(%rip),%rax
    movq %rbx,%fs:(%rax)
    movq $186,%rax      # System_Syscall_Command_gettid  
    syscall
    movq System_Thread_TID@GOTTPOFF(%rip),%rcx
    movq %rax,%fs:(%rcx)

boot_no_tls:
    movq 8(%rsp),%r11   # arg2: function
    movq 16(%rsp),%rdi  # arg3: argc
    movq %rsp,%rsi      # arg4: argv
    addq $24,%rsi
    call *%r11
    movq %rax,%rsi
    movq (%rsp),%rdi
    jmp System_Thread_terminate

.size System_Thread_boot,.-System_Thread_boot

.text
.global System_Thread_terminate
.type   System_Thread_terminate,@function
System_Thread_terminate:

    movq %rdi,%rbx  # arg0: that
    movq %rsi,%rcx  # arg1: returnValue

    cmpq $0,%rbx
    jne terminate_have_that
    movq System_Thread_Current@GOTTPOFF(%rip),%rbx
    movq %fs:(%rbx),%rbx
    cmpq $0,%rbx
    je terminate_no_tls

terminate_have_that:
    movl $0,%esi
    lock xchgl %ecx,12(%rbx)  # that->returnValue
    lock xchgl %esi,8(%rbx)   # that->threadId
    mfence

    /*movl System_Thread_PID@GOTPCREL(%rip), %edi
    movl 8(%rdi),%esi   # that->threadId
    movq $234,%rax      # System_Syscall_Command_tgkill
    movq $17,%rdx       # System_Signal_Number_SIGCHILD
    syscall*/

    movq $11,%rax       # System_Syscall_Command_munmap
    movq 16(%rbx),%rdi  # that->stack
    syscall
/* if DEBUG == DEBUG_System_Syscall_mmap */
    movq System_Syscall_mmapCount@GOTPCREL(%rip),%rsi
    decq (%rsi)
    movq $0,16(%rbx)
    movq 24(%rbx),%rdi  # that->tls
    cmpq $0,%rdi
    je terminate_no_tls
    
    syscall
/* if DEBUG == DEBUG_System_Syscall_mmap */
    decq (%rsi)
    movq $0,24(%rbx)

terminate_no_tls:
    movq $60,%rax       # System_Syscall_Command_exit
    movl %ecx,%edi    
    syscall

.size System_Thread_terminate,.-System_Thread_terminate
