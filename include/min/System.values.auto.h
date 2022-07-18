/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_uint8)
#define have_System_uint8

export struct System_Type  System_uint8Type;


#define System_uint8_string8base2Length_DEFAULT  8
#define System_uint8_string8base4Length_DEFAULT  4
#define System_uint8_string8base8Length_DEFAULT  3
#define System_uint8_string8base16Length_DEFAULT  2
#define System_uint8_string8base10Length_DEFAULT  3

export System_boolean  System_uint8_isPrintable(System_uint8 that);
export System_size  System_uint8_tostring8base2__stack(System_uint8 that, System_char8 array[System_uint8_string8base2Length_DEFAULT + 1]);
export System_size  System_uint8_tostring8base4__stack(System_uint8 that, System_char8 array[System_uint8_string8base4Length_DEFAULT + 1]);
export System_size  System_uint8_tostring8base8__stack(System_uint8 that, System_char8 array[System_uint8_string8base8Length_DEFAULT + 1]);
export System_size  System_uint8_tostring8base16__stack(System_uint8 that, System_char8 array[System_uint8_string8base16Length_DEFAULT + 1]);
export System_size  System_uint8_tostring8base10__stack(System_uint8 that, System_char8 array[System_uint8_string8base10Length_DEFAULT + 1]);
export System_uint8  System_uint8_parsebase10(System_string8 that);
#define inline_System_uint8_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define uint8Type  System_uint8Type
#define uint8_isPrintable  System_uint8_isPrintable
#define uint8_tostring8base2__stack  System_uint8_tostring8base2__stack
#define uint8_tostring8base4__stack  System_uint8_tostring8base4__stack
#define uint8_tostring8base8__stack  System_uint8_tostring8base8__stack
#define uint8_tostring8base16__stack  System_uint8_tostring8base16__stack
#define uint8_tostring8base10__stack  System_uint8_tostring8base10__stack
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_uint16)
#define have_System_uint16

export struct System_Type  System_uint16Type;


#define System_uint16_string8base2Length_DEFAULT  16
#define System_uint16_string8base4Length_DEFAULT  8
#define System_uint16_string8base8Length_DEFAULT  6
#define System_uint16_string8base16Length_DEFAULT  4
#define System_uint16_string8base10Length_DEFAULT  5

export System_boolean  System_uint16_isPrintable(System_uint16 that);
export System_size  System_uint16_tostring8base2__stack(System_uint16 that, System_char8 array[System_uint16_string8base2Length_DEFAULT + 1]);
export System_size  System_uint16_tostring8base4__stack(System_uint16 that, System_char8 array[System_uint16_string8base4Length_DEFAULT + 1]);
export System_size  System_uint16_tostring8base8__stack(System_uint16 that, System_char8 array[System_uint16_string8base8Length_DEFAULT + 1]);
export System_size  System_uint16_tostring8base16__stack(System_uint16 that, System_char8 array[System_uint16_string8base16Length_DEFAULT + 1]);
export System_size  System_uint16_tostring8base10__stack(System_uint16 that, System_char8 array[System_uint16_string8base10Length_DEFAULT + 1]);
export System_uint16  System_uint16_parsebase10(System_string8 that);
#define inline_System_uint16_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define uint16Type  System_uint16Type
#define uint16_isPrintable  System_uint16_isPrintable
#define uint16_tostring8base2__stack  System_uint16_tostring8base2__stack
#define uint16_tostring8base4__stack  System_uint16_tostring8base4__stack
#define uint16_tostring8base8__stack  System_uint16_tostring8base8__stack
#define uint16_tostring8base16__stack  System_uint16_tostring8base16__stack
#define uint16_tostring8base10__stack  System_uint16_tostring8base10__stack
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_uint32)
#define have_System_uint32

export struct System_Type  System_uint32Type;


#define System_uint32_string8base2Length_DEFAULT  32
#define System_uint32_string8base4Length_DEFAULT  16
#define System_uint32_string8base8Length_DEFAULT  11
#define System_uint32_string8base16Length_DEFAULT  8
#define System_uint32_string8base10Length_DEFAULT  10

export System_boolean  System_uint32_isPrintable(System_uint32 that);
export System_size  System_uint32_tostring8base2__stack(System_uint32 that, System_char8 array[System_uint32_string8base2Length_DEFAULT + 1]);
export System_size  System_uint32_tostring8base4__stack(System_uint32 that, System_char8 array[System_uint32_string8base4Length_DEFAULT + 1]);
export System_size  System_uint32_tostring8base8__stack(System_uint32 that, System_char8 array[System_uint32_string8base8Length_DEFAULT + 1]);
export System_size  System_uint32_tostring8base16__stack(System_uint32 that, System_char8 array[System_uint32_string8base16Length_DEFAULT + 1]);
export System_size  System_uint32_tostring8base10__stack(System_uint32 that, System_char8 array[System_uint32_string8base10Length_DEFAULT + 1]);
export System_uint32  System_uint32_parsebase10(System_string8 that);
#define inline_System_uint32_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define uint32Type  System_uint32Type
#define uint32_isPrintable  System_uint32_isPrintable
#define uint32_tostring8base2__stack  System_uint32_tostring8base2__stack
#define uint32_tostring8base4__stack  System_uint32_tostring8base4__stack
#define uint32_tostring8base8__stack  System_uint32_tostring8base8__stack
#define uint32_tostring8base16__stack  System_uint32_tostring8base16__stack
#define uint32_tostring8base10__stack  System_uint32_tostring8base10__stack
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_uint64)
#define have_System_uint64

export struct System_Type  System_uint64Type;


#define System_uint64_string8base2Length_DEFAULT  64
#define System_uint64_string8base4Length_DEFAULT  32
#define System_uint64_string8base8Length_DEFAULT  22
#define System_uint64_string8base16Length_DEFAULT  16
#define System_uint64_string8base10Length_DEFAULT  20

export System_boolean  System_uint64_isPrintable(System_uint64 that);
export System_size  System_uint64_tostring8base2__stack(System_uint64 that, System_char8 array[System_uint64_string8base2Length_DEFAULT + 1]);
export System_size  System_uint64_tostring8base4__stack(System_uint64 that, System_char8 array[System_uint64_string8base4Length_DEFAULT + 1]);
export System_size  System_uint64_tostring8base8__stack(System_uint64 that, System_char8 array[System_uint64_string8base8Length_DEFAULT + 1]);
export System_size  System_uint64_tostring8base16__stack(System_uint64 that, System_char8 array[System_uint64_string8base16Length_DEFAULT + 1]);
export System_size  System_uint64_tostring8base10__stack(System_uint64 that, System_char8 array[System_uint64_string8base10Length_DEFAULT + 1]);
export System_uint64  System_uint64_parsebase10(System_string8 that);
#define inline_System_uint64_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define uint64Type  System_uint64Type
#define uint64_isPrintable  System_uint64_isPrintable
#define uint64_tostring8base2__stack  System_uint64_tostring8base2__stack
#define uint64_tostring8base4__stack  System_uint64_tostring8base4__stack
#define uint64_tostring8base8__stack  System_uint64_tostring8base8__stack
#define uint64_tostring8base16__stack  System_uint64_tostring8base16__stack
#define uint64_tostring8base10__stack  System_uint64_tostring8base10__stack
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_int8)
#define have_System_int8

export struct System_Type  System_int8Type;


#define System_int8_string8base2Length_DEFAULT  9
#define System_int8_string8base4Length_DEFAULT  5
#define System_int8_string8base8Length_DEFAULT  4
#define System_int8_string8base16Length_DEFAULT  3
#define System_int8_string8base10Length_DEFAULT  4

export System_boolean  System_int8_isPrintable(System_int8 that);
export System_size  System_int8_tostring8base2__stack(System_int8 that, System_char8 array[System_int8_string8base2Length_DEFAULT + 1]);
export System_size  System_int8_tostring8base4__stack(System_int8 that, System_char8 array[System_int8_string8base4Length_DEFAULT + 1]);
export System_size  System_int8_tostring8base8__stack(System_int8 that, System_char8 array[System_int8_string8base8Length_DEFAULT + 1]);
export System_size  System_int8_tostring8base16__stack(System_int8 that, System_char8 array[System_int8_string8base16Length_DEFAULT + 1]);
export System_size  System_int8_tostring8base10__stack(System_int8 that, System_char8 array[System_int8_string8base10Length_DEFAULT + 1]);;
#define inline_System_int8_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define int8Type  System_int8Type
#define int8_isPrintable  System_int8_isPrintable
#define int8_tostring8base2__stack  System_int8_tostring8base2__stack
#define int8_tostring8base4__stack  System_int8_tostring8base4__stack
#define int8_tostring8base8__stack  System_int8_tostring8base8__stack
#define int8_tostring8base16__stack  System_int8_tostring8base16__stack
#define int8_tostring8base10__stack  System_int8_tostring8base10__stack
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_int16)
#define have_System_int16

export struct System_Type  System_int16Type;


#define System_int16_string8base2Length_DEFAULT  17
#define System_int16_string8base4Length_DEFAULT  9
#define System_int16_string8base8Length_DEFAULT  7
#define System_int16_string8base16Length_DEFAULT  5
#define System_int16_string8base10Length_DEFAULT  6

export System_boolean  System_int16_isPrintable(System_int16 that);
export System_size  System_int16_tostring8base2__stack(System_int16 that, System_char8 array[System_int16_string8base2Length_DEFAULT + 1]);
export System_size  System_int16_tostring8base4__stack(System_int16 that, System_char8 array[System_int16_string8base4Length_DEFAULT + 1]);
export System_size  System_int16_tostring8base8__stack(System_int16 that, System_char8 array[System_int16_string8base8Length_DEFAULT + 1]);
export System_size  System_int16_tostring8base16__stack(System_int16 that, System_char8 array[System_int16_string8base16Length_DEFAULT + 1]);
export System_size  System_int16_tostring8base10__stack(System_int16 that, System_char8 array[System_int16_string8base10Length_DEFAULT + 1]);;
#define inline_System_int16_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define int16Type  System_int16Type
#define int16_isPrintable  System_int16_isPrintable
#define int16_tostring8base2__stack  System_int16_tostring8base2__stack
#define int16_tostring8base4__stack  System_int16_tostring8base4__stack
#define int16_tostring8base8__stack  System_int16_tostring8base8__stack
#define int16_tostring8base16__stack  System_int16_tostring8base16__stack
#define int16_tostring8base10__stack  System_int16_tostring8base10__stack
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_int32)
#define have_System_int32

export struct System_Type  System_int32Type;


#define System_int32_string8base2Length_DEFAULT  33
#define System_int32_string8base4Length_DEFAULT  17
#define System_int32_string8base8Length_DEFAULT  12
#define System_int32_string8base16Length_DEFAULT  9
#define System_int32_string8base10Length_DEFAULT  11

export System_boolean  System_int32_isPrintable(System_int32 that);
export System_size  System_int32_tostring8base2__stack(System_int32 that, System_char8 array[System_int32_string8base2Length_DEFAULT + 1]);
export System_size  System_int32_tostring8base4__stack(System_int32 that, System_char8 array[System_int32_string8base4Length_DEFAULT + 1]);
export System_size  System_int32_tostring8base8__stack(System_int32 that, System_char8 array[System_int32_string8base8Length_DEFAULT + 1]);
export System_size  System_int32_tostring8base16__stack(System_int32 that, System_char8 array[System_int32_string8base16Length_DEFAULT + 1]);
export System_size  System_int32_tostring8base10__stack(System_int32 that, System_char8 array[System_int32_string8base10Length_DEFAULT + 1]);;
#define inline_System_int32_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define int32Type  System_int32Type
#define int32_isPrintable  System_int32_isPrintable
#define int32_tostring8base2__stack  System_int32_tostring8base2__stack
#define int32_tostring8base4__stack  System_int32_tostring8base4__stack
#define int32_tostring8base8__stack  System_int32_tostring8base8__stack
#define int32_tostring8base16__stack  System_int32_tostring8base16__stack
#define int32_tostring8base10__stack  System_int32_tostring8base10__stack
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_decimal)
#include "System.decimal.h"
#endif
#if !defined(have_System_int64)
#define have_System_int64

export struct System_Type  System_int64Type;


#define System_int64_string8base2Length_DEFAULT  65
#define System_int64_string8base4Length_DEFAULT  33
#define System_int64_string8base8Length_DEFAULT  23
#define System_int64_string8base16Length_DEFAULT  17
#define System_int64_string8base10Length_DEFAULT  21

export System_boolean  System_int64_isPrintable(System_int64 that);
export System_size  System_int64_tostring8base2__stack(System_int64 that, System_char8 array[System_int64_string8base2Length_DEFAULT + 1]);
export System_size  System_int64_tostring8base4__stack(System_int64 that, System_char8 array[System_int64_string8base4Length_DEFAULT + 1]);
export System_size  System_int64_tostring8base8__stack(System_int64 that, System_char8 array[System_int64_string8base8Length_DEFAULT + 1]);
export System_size  System_int64_tostring8base16__stack(System_int64 that, System_char8 array[System_int64_string8base16Length_DEFAULT + 1]);
export System_size  System_int64_tostring8base10__stack(System_int64 that, System_char8 array[System_int64_string8base10Length_DEFAULT + 1]);;
#define inline_System_int64_isPrintable(CHAR)  (CHAR > 0x1F && CHAR < 0x7F) || (CHAR > 0x9F && CHAR != 0xAD)
#if defined(using_System)
#define int64Type  System_int64Type
#define int64_isPrintable  System_int64_isPrintable
#define int64_tostring8base2__stack  System_int64_tostring8base2__stack
#define int64_tostring8base4__stack  System_int64_tostring8base4__stack
#define int64_tostring8base8__stack  System_int64_tostring8base8__stack
#define int64_tostring8base16__stack  System_int64_tostring8base16__stack
#define int64_tostring8base10__stack  System_int64_tostring8base10__stack
#endif
#endif
