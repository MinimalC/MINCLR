/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Math)
#define have_System_Math

export struct System_Type  System_MathType;

#define System_Math_divideRemain__uint64  System_Math_divideRemain__uint64__generic

export System_uint64  System_Math_divideRemain__uint64(System_uint64 divident, System_uint64 divisor, System_uint64 ref remainder);

#define inline_System_Math_addInt8(a, b)  ((a) == 0 ? (b) : ((b) == 0 ? (a) : ((b) > 0 ? (System_int8_Max - (b) > (a) ? (a) + (b) : 0) : ((System_int8_Min - (b) < (a)) ? (a) + (b) : 0))))

#if defined(using_System)
#define Math_divideRemain__uint64  System_Math_divideRemain__uint64
#define Math_addInt8  inline_System_Math_addInt8
#endif


#if defined(have_Linux)

#if defined(have_ARM)
#include "ARM32/GNU.Linux/System.Math.h"

#elif defined(have_AMD64)
#include "AMD64/GNU.Linux/System.Math.h"

#elif defined(have_X86)
#include "X86/GNU.Linux/System.Math.h"

#else
#error Architecture not implemented
#endif

#else
#error Platform not implemented
#endif

#endif
