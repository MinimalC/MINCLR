#if !defined(have_System_Math)
#include "../../System.Math.h"
#endif
#if !defined(have_System_Math__amd64)
#define have_System_Math__amd64

#undef  System_Math_divideRemain__uint64
#define System_Math_divideRemain__uint64  System_Math_divideRemain__uint64__amd64

__import System_uint64  System_Math_divideRemain__uint64(System_uint64 divident, System_uint64 divisor, System_uint64 __ref remainder);

#endif
