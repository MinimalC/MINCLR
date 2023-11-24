# Gemeinfrei. Public Domain.
.text
.global __tls_get_addr
.type   __tls_get_addr,@function
__tls_get_addr:

    subq $16,%rsp
    movq 8(%rdi),%rax
    movq %rax,8(%rsp)

/*    movq (%rdi),%rax
    cmpq $1,%rax
    jne exit */

    movq $0,(%rsp)

    movq $158,%rax /* System_Syscall_Command_arch_prctl */
    movq $4099,%rdi /* ARCH_GET_FS */
    movq %rsp,%rsi
    syscall

    movq (%rsp),%rax
    addq 8(%rsp),%rax

exit:
    addq $16,%rsp
    ret

.size __tls_get_addr,.-__tls_get_addr
