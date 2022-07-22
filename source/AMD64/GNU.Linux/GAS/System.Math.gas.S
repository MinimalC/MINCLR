/* Gemeinfrei. Public Domain. */

.include "GAS.H"

.text

function System_Math_divideRemain__UInt64__amd64
    movq  %rdx, %rcx     # remainder
    movq  %rdi, %rax     # divident
    movl  $0, %edx
    divq  %rsi           # divisor
    movq  %rdx, (%rcx)   # *remainder
    ret
end_function System_Math_divideRemain__UInt64__amd64
