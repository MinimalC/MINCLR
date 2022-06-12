/* Gemeinfrei. Public Domain. */

#include <min/linux/x86_64/System.gas.h>

.text

__function(System_Math_divideRemain__uint64__amd64)
    movq  %rdx, %rcx     # remainder
    movq  %rdi, %rax     # divident
    movl  $0, %edx
    divq  %rsi           # divisor
    movq  %rdx, (%rcx)   # *remainder
    ret
__end_function(System_Math_divideRemain__uint64__amd64)
