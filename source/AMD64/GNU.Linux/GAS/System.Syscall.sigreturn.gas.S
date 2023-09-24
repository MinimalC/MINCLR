# Gemeinfrei. Public Domain.
.text
.global System_Syscall_sigreturn
.type   System_Syscall_sigreturn,@function
System_Syscall_sigreturn:

    movq $15,%rax    /* System_Syscall_Command_rt_sigreturn */
    syscall

.size System_Syscall_sigreturn,.-System_Syscall_sigreturn
