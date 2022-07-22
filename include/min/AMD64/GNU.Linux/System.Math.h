#if !defined(have_System_Math)
#include "../../System.Math.h"
#endif
#if !defined(have_System_Math__amd64)
#define have_System_Math__amd64

#undef  System_Math_divideRemain__UInt64
#define System_Math_divideRemain__UInt64  System_Math_divideRemain__UInt64__amd64

import System_UInt64  System_Math_divideRemain__UInt64(System_UInt64 divident, System_UInt64 divisor, System_UInt64 ref remainder);

#endif
