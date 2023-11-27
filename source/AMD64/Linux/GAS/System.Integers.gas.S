/* Gemeinfrei. Public Domain. */

.include "GAS.H"

.text

function System_UInt64_divRem
    movq  %rdx, %rcx     # remainder
    movq  %rdi, %rax     # divident
    movl  $0, %edx
    divq  %rsi           # divisor
    movq  %rdx, (%rcx)   # *remainder
    ret
end_function System_UInt64_divRem
