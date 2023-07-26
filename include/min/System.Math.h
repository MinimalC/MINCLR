/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Math)
#define have_System_Math

export struct System_Type  System_MathType;


export System_UInt64  System_Math_divRem__UInt64__generic(System_UInt64 divident, System_UInt64 divisor, System_UInt64 ref remainder);

#define System_Math_divRem__UInt64  System_Math_divRem__UInt64__generic
#define inline_System_Math_addInt8(a, b)  ((a) == 0 ? (b) : ((b) == 0 ? (a) : ((b) > 0 ? (System_Int8_Max - (b) > (a) ? (a) + (b) : 0) : ((System_Int8_Min - (b) < (a)) ? (a) + (b) : 0))))

#if defined(using_System)
#define Math_divRem__UInt64  System_Math_divRem__UInt64
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
