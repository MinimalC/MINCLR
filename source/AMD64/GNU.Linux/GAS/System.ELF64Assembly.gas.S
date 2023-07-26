# Gemeinfrei. Public Domain.
.text
.global System_ELF64Assembly_jump
.type   System_ELF64Assembly_jump,@function
System_ELF64Assembly_jump:

	pushq	%rax			/* save register arguments */
	pushq	%rdi
	pushq	%rsi
	pushq	%rdx
	pushq	%rcx
	pushq	%r8
	pushq	%r9
	movq	56(%rsp),%rdi	/* assembly handle */
	movq	64(%rsp),%rsi	/* relocation entry = 24*(index) */
	leaq	(%rsi,%rsi,2),%rsi
	shlq	$3,%rsi
	call	System_ELF64Assembly_resolve
	movq	%rax,%r11		/* save return value */
	popq	%r9				/* restore register args */
	popq	%r8
	popq	%rcx
	popq	%rdx
	popq	%rsi
	popq	%rdi
	popq	%rax
	addq	$16,%rsp		/* remove arguments from plt */
	jmpq	*%r11			/* jump to function address */

.size System_ELF64Assembly_jump,.-System_ELF64Assembly_jump
