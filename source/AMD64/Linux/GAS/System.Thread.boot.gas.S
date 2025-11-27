# Gemeinfrei. Public Domain.
.text
.global System_Thread_boot
.type   System_Thread_boot,@function
System_Thread_boot:

    movq (%rsp),%rbx # arg0: that
    movq $158,%rax      # System_Syscall_Command_arch_prctl
    movq $4098,%rdi     # ARCH_SET_FS
    movq 8(%rsp),%rsi  # arg1: tls
    syscall

    movq System_Thread_Current@GOTTPOFF(%rip),%rax
    movq %rbx,%fs:(%rax)
    movq $186,%rax      # System_Syscall_Command_gettid  
    syscall
    movq System_Thread_TID@GOTTPOFF(%rip),%rcx
    movq %rax,%fs:(%rcx)

    movq 16(%rsp),%r11   # arg2: function
    movq 24(%rsp),%rdi  # arg3: argc
    addq $24,%rsp
    movq %rsp,%rsi      # arg4: argv
    addq $8,%rsi
    call *%r11
    movq %rax,%rdi
    jmp System_Thread_terminate
    /*call System_Console_exit@PLT*/

.size System_Thread_boot,.-System_Thread_boot

.section .rodata
.TERMINIERT:
.string	"THREAD TERMINIERT: "

.text
.global System_Thread_terminate
.type   System_Thread_terminate,@function
System_Thread_terminate:

    subq $8, %rsp
    movq %rdi,(%rsp)

    /*movl System_Thread_PID@GOTPCREL(%rip), %edi
    movl 8(%rdi),%esi   # that->threadId
    movq $234,%rax      # System_Syscall_Command_tgkill
    movq $17,%rdx       # System_Signal_Number_SIGCHILD
    syscall*/

	movq System_Exception_current@gottpoff(%rip), %rdi
	movq %fs:(%rdi), %rdi
	testq %rdi, %rdi
	je	.terminate_no_exception

	leaq .TERMINIERT(%rip), %rdi
    call System_Console_write__string@PLT
	
/* if DEBUG && DEBUG != DEBUG_System_Exception */
	movq System_Exception_current@gottpoff(%rip), %rdi
	movq %fs:(%rdi), %rdi
    call System_Exception_print@PLT

.terminate_no_exception:
    movq System_Thread_TID@GOTTPOFF(%rip),%rdi
    movq %fs:(%rdi),%rdi
    call System_Memory_cleanup__threadId@PLT

    movq (%rsp),%r10

    movq System_Thread_Current@GOTTPOFF(%rip),%rbx
    movq %fs:(%rbx),%rbx

    movq $11,%rax       # System_Syscall_Command_munmap
    movq 16(%rbx),%rdi  # that->stack
    movq $8388608,%rsi  # STACK_SIZE
    syscall
    movq $0,16(%rbx)
/* if DEBUG == DEBUG_System_Syscall_mmap */
    movq System_Syscall_mmapCount@GOTPCREL(%rip),%rsi
    decq (%rsi)

    movq $0,%rsi
    movq %r10,%rdi
    lock xchgl %edi,12(%rbx)  # that->returnValue
    lock xchgl %esi,8(%rbx)   # that->threadId
    mfence

    /*movq (%rsp),%rax  # arg0: returnValue
    movl %eax,%edi
    call System_Console_exit@PLT*/

    movq $60,%rax       # System_Syscall_Command_exit
    syscall

.size System_Thread_terminate,.-System_Thread_terminate
