/* Gemeinfrei. Public Domain. */
.text
.global System_UInt64_divRem
.type   System_UInt64_divRem,@function
System_UInt64_divRem:

    movq  %rdx, %rcx     # remainder
    movq  %rdi, %rax     # divident
    movl  $0, %edx
    divq  %rsi           # divisor
    movq  %rdx, (%rcx)   # *remainder
    ret

.size System_UInt64_divRem,.-System_UInt64_divRem
