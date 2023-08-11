# Gemeinfrei. Public Domain.
.text
.global System_Thread_start
.type   System_Thread_start,@function
System_Thread_start:

	movq (%rsp),%r11
	movq 8(%rsp),%rdi
	leaq 16(%rsp),%rsi
	call *%r11

	movq %rax,%rdi
	movq $60,%rax	/* System_Syscall_Command_exit */
	syscall

.size System_Thread_start,.-System_Thread_start
