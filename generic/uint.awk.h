/* Gemeinfrei. Public Domain. */
#define Generic_T0  System_UInt8
/* GENERIC */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_Generic_T0)
#define have_Generic_T0
enum {
##if Type == "UInt64"
    Generic_T0_String8Capacity_base2 = 64,
    Generic_T0_String8Capacity_base4 = 32,
    Generic_T0_String8Capacity_base8 = 22,
    Generic_T0_String8Capacity_base16 = 16,
    Generic_T0_String8Capacity_base10 = 20,
##else if Type == "UInt32"
    Generic_T0_String8Capacity_base2 = 32,
    Generic_T0_String8Capacity_base4 = 16,
    Generic_T0_String8Capacity_base8 = 11,
    Generic_T0_String8Capacity_base16 = 8,
    Generic_T0_String8Capacity_base10 = 10,
##else if Type == "UInt16"
    Generic_T0_String8Capacity_base2 = 16,
    Generic_T0_String8Capacity_base4 = 8,
    Generic_T0_String8Capacity_base8 = 6,
    Generic_T0_String8Capacity_base16 = 4,
    Generic_T0_String8Capacity_base10 = 5,
##else if Type == "UInt8"
    Generic_T0_String8Capacity_base2 = 8,
    Generic_T0_String8Capacity_base4 = 4,
    Generic_T0_String8Capacity_base8 = 3,
    Generic_T0_String8Capacity_base16 = 2,
    Generic_T0_String8Capacity_base10 = 3,
##else
##error "Unknown Type. System.uint.awk implements UInt8, UInt16, UInt32 and UInt64"
##endif
};
export struct System_Type  Generic_T0Type;
export System_Bool  Generic_T0_isPrintable(Generic_T0 that);
#define inline_Generic_T0_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
export System_Size  stack_Generic_T0_toString8base2(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base2 + 1]);
export System_Size  stack_Generic_T0_toString8base4(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base4 + 1]);
export System_Size  stack_Generic_T0_toString8base8(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base8 + 1]);
export System_Size  stack_Generic_T0_toString8base16(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base16 + 1]);
export System_Size  stack_Generic_T0_toString8base10(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base10 + 1]);
export System_String8  Generic_T0_toString8base2(Generic_T0 that);
export System_String8  Generic_T0_toString8base4(Generic_T0 that);
export System_String8  Generic_T0_toString8base8(Generic_T0 that);
export System_String8  Generic_T0_toString8base16(Generic_T0 that);
export System_String8  Generic_T0_toString8base10(Generic_T0 that);
export Generic_T0  Generic_T0_parsebase10(System_String8 that);
export Generic_T0  Generic_T0_toNetworkOrder(Generic_T0 that);

#if defined(have_AMD64)
import Generic_T0  Generic_T0_divRem(Generic_T0 divident, Generic_T0 divisor, Generic_T0 ref remainder);
#else
export Generic_T0  Generic_T0_divRem(Generic_T0 divident, Generic_T0 divisor, Generic_T0 ref remainder);
#endif

##if Type == "UInt16"
#define inline_Generic_T0_toNetworkOrder(n)  ( ( ( n & 0xFF00 ) >> 8  ) | ( (n & 0x00FF ) << 8 ) )

##else if Type == "UInt32"
#define inline_Generic_T0_toNetworkOrder(n)  ( ( ( n & 0xFF000000 ) >> 24  ) | ( ( n & 0x00FF0000 ) >> 8  ) | ( ( n & 0x0000FF00 ) << 8  ) | ( (n & 0x000000FF ) << 24 ) )

##else if Type == "UInt64"
#define inline_Generic_T0_toNetworkOrder(n) \
	((((n) & 0xff00000000000000) >> 56)\
    |(((n) & 0x00ff000000000000) >> 40)\
    |(((n) & 0x0000ff0000000000) >> 24)\
    |(((n) & 0x000000ff00000000) >>  8)\
    |(((n) & 0x00000000ff000000) <<  8)\
    |(((n) & 0x0000000000ff0000) << 24)\
    |(((n) & 0x000000000000ff00) << 40)\
    |(((n) & 0x00000000000000ff) << 56))

##else if Type == "UInt8"
#define inline_Generic_T0_add(a, b)  ((a) == 0 ? (b) : ((b) == 0 ? (a) : ((b) > 0 ? (Generic_T0_Max - (b) > (a) ? (a) + (b) : 0) : ((Generic_T0_Min - (b) < (a)) ? (a) + (b) : 0))))
#define inline_Generic_T0_toNetworkOrder(n)  ( n )
##else
##error "Unknown Type. System.uint.awk implements UInt8, UInt16, UInt32 and UInt64"
##endif
#if defined(using_Generic)
#define stack_T0_toString8base2  stack_Generic_T0_toString8base2
#define stack_T0_toString8base4  stack_Generic_T0_toString8base4
#define stack_T0_toString8base8  stack_Generic_T0_toString8base8
#define stack_T0_toString8base16  stack_Generic_T0_toString8base16
#define stack_T0_toString8base10  stack_Generic_T0_toString8base10
#if defined(Generic_internal)
#define T0_isPrintable  Generic_T0_isPrintable
#define T0_toNetworkOrder  Generic_T0_toNetworkOrder
#else
#define T0_isPrintable  inline_Generic_T0_isPrintable
#define T0_toNetworkOrder  inline_Generic_T0_toNetworkOrder
#endif
#endif
#endif
