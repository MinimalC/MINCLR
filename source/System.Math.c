/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Math)
#include <min/System.Math.h>
#endif
#if !defined(code_System_Math)
#define code_System_Math

/*# System_Math #*/

struct_System_String  STRING_System_Math = const_System_String("System.Math");

struct_System_Type  System_MathType = { .base = stack_System_Object(System_Type),
    .name = &STRING_System_Math,
};

System_uint64  System_Math_divideRemain__uint64__generic(System_uint64 divident, System_uint64 divisor, System_uint64 __ref remainder) {

    *remainder = divident % divisor;

    return divident / divisor;
}

#endif
