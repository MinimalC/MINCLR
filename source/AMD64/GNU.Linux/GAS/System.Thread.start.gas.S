# Gemeinfrei. Public Domain.
.text
.global System_Thread_start
.type   System_Thread_start,@function
System_Thread_start:

	movq (%rsp),%r11	/* function */
	movq 8(%rsp),%rdi	/* argc */
	leaq 16(%rsp),%rsi	/* argv */
	call *%r11

	movq $1,%rdi	/* true */
	movq $60,%rax	/* System_Syscall_Command_exit */
	syscall

.size System_Thread_start,.-System_Thread_start
