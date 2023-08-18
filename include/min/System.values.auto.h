/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_UInt8)
#define have_System_UInt8

export struct System_Type  System_UInt8Type;
#define System_UInt8_String8base2Length_DEFAULT  8
#define System_UInt8_String8base4Length_DEFAULT  4
#define System_UInt8_String8base8Length_DEFAULT  3
#define System_UInt8_String8base16Length_DEFAULT  2
#define System_UInt8_String8base10Length_DEFAULT  3
export System_Bool  System_UInt8_isPrintable(System_UInt8 that);
#define inline_System_UInt8_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
export System_Size  stack_System_UInt8_toString8base2(System_UInt8 that, System_Char8 array[System_UInt8_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_UInt8_toString8base4(System_UInt8 that, System_Char8 array[System_UInt8_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_UInt8_toString8base8(System_UInt8 that, System_Char8 array[System_UInt8_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_UInt8_toString8base16(System_UInt8 that, System_Char8 array[System_UInt8_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_UInt8_toString8base10(System_UInt8 that, System_Char8 array[System_UInt8_String8base10Length_DEFAULT + 1]);
export System_UInt8  System_UInt8_parsebase10(System_String8 that);
export System_UInt8  System_UInt8_toNetworkOrder(System_UInt8 that);
#define inline_System_UInt8_toNetworkOrder(n)  ( n )
#if defined(using_System)
#define stack_UInt8_toString8base2  stack_System_UInt8_toString8base2
#define stack_UInt8_toString8base4  stack_System_UInt8_toString8base4
#define stack_UInt8_toString8base8  stack_System_UInt8_toString8base8
#define stack_UInt8_toString8base16  stack_System_UInt8_toString8base16
#define stack_UInt8_toString8base10  stack_System_UInt8_toString8base10
#if defined(System_internal)
#define UInt8_isPrintable  System_UInt8_isPrintable
#define UInt8_toNetworkOrder  System_UInt8_toNetworkOrder
#else
#define UInt8_isPrintable  inline_System_UInt8_isPrintable
#define UInt8_toNetworkOrder  inline_System_UInt8_toNetworkOrder
#endif
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_UInt16)
#define have_System_UInt16

export struct System_Type  System_UInt16Type;
#define System_UInt16_String8base2Length_DEFAULT  16
#define System_UInt16_String8base4Length_DEFAULT  8
#define System_UInt16_String8base8Length_DEFAULT  6
#define System_UInt16_String8base16Length_DEFAULT  4
#define System_UInt16_String8base10Length_DEFAULT  5
export System_Bool  System_UInt16_isPrintable(System_UInt16 that);
#define inline_System_UInt16_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
export System_Size  stack_System_UInt16_toString8base2(System_UInt16 that, System_Char8 array[System_UInt16_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_UInt16_toString8base4(System_UInt16 that, System_Char8 array[System_UInt16_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_UInt16_toString8base8(System_UInt16 that, System_Char8 array[System_UInt16_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_UInt16_toString8base16(System_UInt16 that, System_Char8 array[System_UInt16_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_UInt16_toString8base10(System_UInt16 that, System_Char8 array[System_UInt16_String8base10Length_DEFAULT + 1]);
export System_UInt16  System_UInt16_parsebase10(System_String8 that);
export System_UInt16  System_UInt16_toNetworkOrder(System_UInt16 that);
#define inline_System_UInt16_toNetworkOrder(n)  ( ( ( n & 0xFF00 ) >> 8  ) | ( (n & 0x00FF ) << 8 ) )
#if defined(using_System)
#define stack_UInt16_toString8base2  stack_System_UInt16_toString8base2
#define stack_UInt16_toString8base4  stack_System_UInt16_toString8base4
#define stack_UInt16_toString8base8  stack_System_UInt16_toString8base8
#define stack_UInt16_toString8base16  stack_System_UInt16_toString8base16
#define stack_UInt16_toString8base10  stack_System_UInt16_toString8base10
#if defined(System_internal)
#define UInt16_isPrintable  System_UInt16_isPrintable
#define UInt16_toNetworkOrder  System_UInt16_toNetworkOrder
#else
#define UInt16_isPrintable  inline_System_UInt16_isPrintable
#define UInt16_toNetworkOrder  inline_System_UInt16_toNetworkOrder
#endif
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_UInt32)
#define have_System_UInt32

export struct System_Type  System_UInt32Type;
#define System_UInt32_String8base2Length_DEFAULT  32
#define System_UInt32_String8base4Length_DEFAULT  16
#define System_UInt32_String8base8Length_DEFAULT  11
#define System_UInt32_String8base16Length_DEFAULT  8
#define System_UInt32_String8base10Length_DEFAULT  10
export System_Bool  System_UInt32_isPrintable(System_UInt32 that);
#define inline_System_UInt32_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
export System_Size  stack_System_UInt32_toString8base2(System_UInt32 that, System_Char8 array[System_UInt32_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_UInt32_toString8base4(System_UInt32 that, System_Char8 array[System_UInt32_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_UInt32_toString8base8(System_UInt32 that, System_Char8 array[System_UInt32_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_UInt32_toString8base16(System_UInt32 that, System_Char8 array[System_UInt32_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_UInt32_toString8base10(System_UInt32 that, System_Char8 array[System_UInt32_String8base10Length_DEFAULT + 1]);
export System_UInt32  System_UInt32_parsebase10(System_String8 that);
export System_UInt32  System_UInt32_toNetworkOrder(System_UInt32 that);
#define inline_System_UInt32_toNetworkOrder(n)  ( ( ( n & 0xFF000000 ) >> 24  ) | ( ( n & 0x00FF0000 ) >> 8  ) | ( ( n & 0x0000FF00 ) << 8  ) | ( (n & 0x000000FF ) << 24 ) )
#if defined(using_System)
#define stack_UInt32_toString8base2  stack_System_UInt32_toString8base2
#define stack_UInt32_toString8base4  stack_System_UInt32_toString8base4
#define stack_UInt32_toString8base8  stack_System_UInt32_toString8base8
#define stack_UInt32_toString8base16  stack_System_UInt32_toString8base16
#define stack_UInt32_toString8base10  stack_System_UInt32_toString8base10
#if defined(System_internal)
#define UInt32_isPrintable  System_UInt32_isPrintable
#define UInt32_toNetworkOrder  System_UInt32_toNetworkOrder
#else
#define UInt32_isPrintable  inline_System_UInt32_isPrintable
#define UInt32_toNetworkOrder  inline_System_UInt32_toNetworkOrder
#endif
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_UInt64)
#define have_System_UInt64

export struct System_Type  System_UInt64Type;
#define System_UInt64_String8base2Length_DEFAULT  64
#define System_UInt64_String8base4Length_DEFAULT  32
#define System_UInt64_String8base8Length_DEFAULT  22
#define System_UInt64_String8base16Length_DEFAULT  16
#define System_UInt64_String8base10Length_DEFAULT  20
export System_Bool  System_UInt64_isPrintable(System_UInt64 that);
#define inline_System_UInt64_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
export System_Size  stack_System_UInt64_toString8base2(System_UInt64 that, System_Char8 array[System_UInt64_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_UInt64_toString8base4(System_UInt64 that, System_Char8 array[System_UInt64_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_UInt64_toString8base8(System_UInt64 that, System_Char8 array[System_UInt64_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_UInt64_toString8base16(System_UInt64 that, System_Char8 array[System_UInt64_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_UInt64_toString8base10(System_UInt64 that, System_Char8 array[System_UInt64_String8base10Length_DEFAULT + 1]);
export System_UInt64  System_UInt64_parsebase10(System_String8 that);
export System_UInt64  System_UInt64_toNetworkOrder(System_UInt64 that);
#define inline_System_UInt64_toNetworkOrder(n):
	((((n) & 0xff00000000000000) >> 56)
    |(((n) & 0x00ff000000000000) >> 40)
    |(((n) & 0x0000ff0000000000) >> 24)
    |(((n) & 0x000000ff00000000) >>  8)
    |(((n) & 0x00000000ff000000) <<  8)
    |(((n) & 0x0000000000ff0000) << 24)
    |(((n) & 0x000000000000ff00) << 40)
    |(((n) & 0x00000000000000ff) << 56))
#end
#if defined(using_System)
#define stack_UInt64_toString8base2  stack_System_UInt64_toString8base2
#define stack_UInt64_toString8base4  stack_System_UInt64_toString8base4
#define stack_UInt64_toString8base8  stack_System_UInt64_toString8base8
#define stack_UInt64_toString8base16  stack_System_UInt64_toString8base16
#define stack_UInt64_toString8base10  stack_System_UInt64_toString8base10
#if defined(System_internal)
#define UInt64_isPrintable  System_UInt64_isPrintable
#define UInt64_toNetworkOrder  System_UInt64_toNetworkOrder
#else
#define UInt64_isPrintable  inline_System_UInt64_isPrintable
#define UInt64_toNetworkOrder  inline_System_UInt64_toNetworkOrder
#endif
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_Int8)
#define have_System_Int8

export struct System_Type  System_Int8Type;


#define System_Int8_String8base2Length_DEFAULT  9
#define System_Int8_String8base4Length_DEFAULT  5
#define System_Int8_String8base8Length_DEFAULT  4
#define System_Int8_String8base16Length_DEFAULT  3
#define System_Int8_String8base10Length_DEFAULT  4

export System_Bool  System_Int8_isPrintable(System_Int8 that);
export System_Size  stack_System_Int8_toString8base2(System_Int8 that, System_Char8 array[System_Int8_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_Int8_toString8base4(System_Int8 that, System_Char8 array[System_Int8_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_Int8_toString8base8(System_Int8 that, System_Char8 array[System_Int8_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_Int8_toString8base16(System_Int8 that, System_Char8 array[System_Int8_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_Int8_toString8base10(System_Int8 that, System_Char8 array[System_Int8_String8base10Length_DEFAULT + 1]);;
#define inline_System_Int8_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define Int8Type  System_Int8Type
#define Int8_isPrintable  System_Int8_isPrintable
#define stack_Int8_toString8base2  stack_System_Int8_toString8base2
#define stack_Int8_toString8base4  stack_System_Int8_toString8base4
#define stack_Int8_toString8base8  stack_System_Int8_toString8base8
#define stack_Int8_toString8base16  stack_System_Int8_toString8base16
#define stack_Int8_toString8base10  stack_System_Int8_toString8base10
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_Int16)
#define have_System_Int16

export struct System_Type  System_Int16Type;


#define System_Int16_String8base2Length_DEFAULT  17
#define System_Int16_String8base4Length_DEFAULT  9
#define System_Int16_String8base8Length_DEFAULT  7
#define System_Int16_String8base16Length_DEFAULT  5
#define System_Int16_String8base10Length_DEFAULT  6

export System_Bool  System_Int16_isPrintable(System_Int16 that);
export System_Size  stack_System_Int16_toString8base2(System_Int16 that, System_Char8 array[System_Int16_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_Int16_toString8base4(System_Int16 that, System_Char8 array[System_Int16_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_Int16_toString8base8(System_Int16 that, System_Char8 array[System_Int16_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_Int16_toString8base16(System_Int16 that, System_Char8 array[System_Int16_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_Int16_toString8base10(System_Int16 that, System_Char8 array[System_Int16_String8base10Length_DEFAULT + 1]);;
#define inline_System_Int16_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define Int16Type  System_Int16Type
#define Int16_isPrintable  System_Int16_isPrintable
#define stack_Int16_toString8base2  stack_System_Int16_toString8base2
#define stack_Int16_toString8base4  stack_System_Int16_toString8base4
#define stack_Int16_toString8base8  stack_System_Int16_toString8base8
#define stack_Int16_toString8base16  stack_System_Int16_toString8base16
#define stack_Int16_toString8base10  stack_System_Int16_toString8base10
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_Int32)
#define have_System_Int32

export struct System_Type  System_Int32Type;


#define System_Int32_String8base2Length_DEFAULT  33
#define System_Int32_String8base4Length_DEFAULT  17
#define System_Int32_String8base8Length_DEFAULT  12
#define System_Int32_String8base16Length_DEFAULT  9
#define System_Int32_String8base10Length_DEFAULT  11

export System_Bool  System_Int32_isPrintable(System_Int32 that);
export System_Size  stack_System_Int32_toString8base2(System_Int32 that, System_Char8 array[System_Int32_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_Int32_toString8base4(System_Int32 that, System_Char8 array[System_Int32_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_Int32_toString8base8(System_Int32 that, System_Char8 array[System_Int32_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_Int32_toString8base16(System_Int32 that, System_Char8 array[System_Int32_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_Int32_toString8base10(System_Int32 that, System_Char8 array[System_Int32_String8base10Length_DEFAULT + 1]);;
#define inline_System_Int32_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define Int32Type  System_Int32Type
#define Int32_isPrintable  System_Int32_isPrintable
#define stack_Int32_toString8base2  stack_System_Int32_toString8base2
#define stack_Int32_toString8base4  stack_System_Int32_toString8base4
#define stack_Int32_toString8base8  stack_System_Int32_toString8base8
#define stack_Int32_toString8base16  stack_System_Int32_toString8base16
#define stack_Int32_toString8base10  stack_System_Int32_toString8base10
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Decimal)
#include "System.Decimal.h"
#endif
#if !defined(have_System_Int64)
#define have_System_Int64

export struct System_Type  System_Int64Type;


#define System_Int64_String8base2Length_DEFAULT  65
#define System_Int64_String8base4Length_DEFAULT  33
#define System_Int64_String8base8Length_DEFAULT  23
#define System_Int64_String8base16Length_DEFAULT  17
#define System_Int64_String8base10Length_DEFAULT  21

export System_Bool  System_Int64_isPrintable(System_Int64 that);
export System_Size  stack_System_Int64_toString8base2(System_Int64 that, System_Char8 array[System_Int64_String8base2Length_DEFAULT + 1]);
export System_Size  stack_System_Int64_toString8base4(System_Int64 that, System_Char8 array[System_Int64_String8base4Length_DEFAULT + 1]);
export System_Size  stack_System_Int64_toString8base8(System_Int64 that, System_Char8 array[System_Int64_String8base8Length_DEFAULT + 1]);
export System_Size  stack_System_Int64_toString8base16(System_Int64 that, System_Char8 array[System_Int64_String8base16Length_DEFAULT + 1]);
export System_Size  stack_System_Int64_toString8base10(System_Int64 that, System_Char8 array[System_Int64_String8base10Length_DEFAULT + 1]);;
#define inline_System_Int64_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define Int64Type  System_Int64Type
#define Int64_isPrintable  System_Int64_isPrintable
#define stack_Int64_toString8base2  stack_System_Int64_toString8base2
#define stack_Int64_toString8base4  stack_System_Int64_toString8base4
#define stack_Int64_toString8base8  stack_System_Int64_toString8base8
#define stack_Int64_toString8base16  stack_System_Int64_toString8base16
#define stack_Int64_toString8base10  stack_System_Int64_toString8base10
#endif
#endif
