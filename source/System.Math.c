/* Gemeinfrei. Public Domain. */
#if !defined(internal_System)
#include "internal.System.h"
#endif
#if !defined(have_System_Math)
#include <min/System.Math.h>
#endif
#if !defined(code_System_Math)
#define code_System_Math

/*# System_Math #*/

struct System_String  STRING_System_Math = const_System_String("System.Math");

struct System_Type  System_MathType = { .base = stack_System_Object(System_Type),
    .name = &STRING_System_Math,
};

System_UInt64  System_Math_divRem__UInt64__generic(System_UInt64 divident, System_UInt64 divisor, System_UInt64 ref remainder) {

    *remainder = divident % divisor;

    return divident / divisor;
}

#endif
