/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Math)
#include <min/System.Math.h>
#endif
#if !defined(code_System_Math)
#define code_System_Math

/*# System_Math #*/

struct System_Type System_MathType = { .base = { .type = typeof(System_Type) }, .name = "Math", };

System_UInt64  System_Math_divRem__UInt64__generic(System_UInt64 divident, System_UInt64 divisor, System_UInt64 ref remainder) {

    *remainder = divident % divisor;

    return divident / divisor;
}

#endif
