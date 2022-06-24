/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_uint8)
#define have_auto_System_uint8

__export struct_System_Type  System_uint8Type;


#define System_uint8_string8base2Length_DEFAULT  8
#define System_uint8_string8base4Length_DEFAULT  4
#define System_uint8_string8base8Length_DEFAULT  3
#define System_uint8_string8base16Length_DEFAULT  2
#define System_uint8_string8base10Length_DEFAULT  3

__export System_boolean  System_uint8_isPrintable(System_uint8 that);
__export System_size  System_uint8_tostring8base2__stack(System_uint8 that, System_char8 array[System_uint8_string8base2Length_DEFAULT + 1]);
__export System_size  System_uint8_tostring8base4__stack(System_uint8 that, System_char8 array[System_uint8_string8base4Length_DEFAULT + 1]);
__export System_size  System_uint8_tostring8base8__stack(System_uint8 that, System_char8 array[System_uint8_string8base8Length_DEFAULT + 1]);
__export System_size  System_uint8_tostring8base16__stack(System_uint8 that, System_char8 array[System_uint8_string8base16Length_DEFAULT + 1]);
__export System_size  System_uint8_tostring8base10__stack(System_uint8 that, System_char8 array[System_uint8_string8base10Length_DEFAULT + 1]);
#define inline_System_uint8_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __uint8Type  System_uint8Type
#define __uint8_isPrintable  System_uint8_isPrintable
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_uint16)
#define have_auto_System_uint16

__export struct_System_Type  System_uint16Type;


#define System_uint16_string8base2Length_DEFAULT  16
#define System_uint16_string8base4Length_DEFAULT  8
#define System_uint16_string8base8Length_DEFAULT  6
#define System_uint16_string8base16Length_DEFAULT  4
#define System_uint16_string8base10Length_DEFAULT  5

__export System_boolean  System_uint16_isPrintable(System_uint16 that);
__export System_size  System_uint16_tostring8base2__stack(System_uint16 that, System_char8 array[System_uint16_string8base2Length_DEFAULT + 1]);
__export System_size  System_uint16_tostring8base4__stack(System_uint16 that, System_char8 array[System_uint16_string8base4Length_DEFAULT + 1]);
__export System_size  System_uint16_tostring8base8__stack(System_uint16 that, System_char8 array[System_uint16_string8base8Length_DEFAULT + 1]);
__export System_size  System_uint16_tostring8base16__stack(System_uint16 that, System_char8 array[System_uint16_string8base16Length_DEFAULT + 1]);
__export System_size  System_uint16_tostring8base10__stack(System_uint16 that, System_char8 array[System_uint16_string8base10Length_DEFAULT + 1]);
#define inline_System_uint16_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __uint16Type  System_uint16Type
#define __uint16_isPrintable  System_uint16_isPrintable
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_uint32)
#define have_auto_System_uint32

__export struct_System_Type  System_uint32Type;


#define System_uint32_string8base2Length_DEFAULT  32
#define System_uint32_string8base4Length_DEFAULT  16
#define System_uint32_string8base8Length_DEFAULT  11
#define System_uint32_string8base16Length_DEFAULT  8
#define System_uint32_string8base10Length_DEFAULT  10

__export System_boolean  System_uint32_isPrintable(System_uint32 that);
__export System_size  System_uint32_tostring8base2__stack(System_uint32 that, System_char8 array[System_uint32_string8base2Length_DEFAULT + 1]);
__export System_size  System_uint32_tostring8base4__stack(System_uint32 that, System_char8 array[System_uint32_string8base4Length_DEFAULT + 1]);
__export System_size  System_uint32_tostring8base8__stack(System_uint32 that, System_char8 array[System_uint32_string8base8Length_DEFAULT + 1]);
__export System_size  System_uint32_tostring8base16__stack(System_uint32 that, System_char8 array[System_uint32_string8base16Length_DEFAULT + 1]);
__export System_size  System_uint32_tostring8base10__stack(System_uint32 that, System_char8 array[System_uint32_string8base10Length_DEFAULT + 1]);
#define inline_System_uint32_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __uint32Type  System_uint32Type
#define __uint32_isPrintable  System_uint32_isPrintable
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_uint64)
#define have_auto_System_uint64

__export struct_System_Type  System_uint64Type;


#define System_uint64_string8base2Length_DEFAULT  64
#define System_uint64_string8base4Length_DEFAULT  32
#define System_uint64_string8base8Length_DEFAULT  22
#define System_uint64_string8base16Length_DEFAULT  16
#define System_uint64_string8base10Length_DEFAULT  20

__export System_boolean  System_uint64_isPrintable(System_uint64 that);
__export System_size  System_uint64_tostring8base2__stack(System_uint64 that, System_char8 array[System_uint64_string8base2Length_DEFAULT + 1]);
__export System_size  System_uint64_tostring8base4__stack(System_uint64 that, System_char8 array[System_uint64_string8base4Length_DEFAULT + 1]);
__export System_size  System_uint64_tostring8base8__stack(System_uint64 that, System_char8 array[System_uint64_string8base8Length_DEFAULT + 1]);
__export System_size  System_uint64_tostring8base16__stack(System_uint64 that, System_char8 array[System_uint64_string8base16Length_DEFAULT + 1]);
__export System_size  System_uint64_tostring8base10__stack(System_uint64 that, System_char8 array[System_uint64_string8base10Length_DEFAULT + 1]);
#define inline_System_uint64_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __uint64Type  System_uint64Type
#define __uint64_isPrintable  System_uint64_isPrintable
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_int8)
#define have_auto_System_int8

__export struct_System_Type  System_int8Type;


#define System_int8_string8base2Length_DEFAULT  9
#define System_int8_string8base4Length_DEFAULT  5
#define System_int8_string8base8Length_DEFAULT  4
#define System_int8_string8base16Length_DEFAULT  3
#define System_int8_string8base10Length_DEFAULT  4

__export System_boolean  System_int8_isPrintable(System_int8 that);
__export System_size  System_int8_tostring8base2__stack(System_int8 that, System_char8 array[System_int8_string8base2Length_DEFAULT + 1]);
__export System_size  System_int8_tostring8base4__stack(System_int8 that, System_char8 array[System_int8_string8base4Length_DEFAULT + 1]);
__export System_size  System_int8_tostring8base8__stack(System_int8 that, System_char8 array[System_int8_string8base8Length_DEFAULT + 1]);
__export System_size  System_int8_tostring8base16__stack(System_int8 that, System_char8 array[System_int8_string8base16Length_DEFAULT + 1]);
__export System_size  System_int8_tostring8base10__stack(System_int8 that, System_char8 array[System_int8_string8base10Length_DEFAULT + 1]);;
#define inline_System_int8_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __int8Type  System_int8Type
#define __int8_isPrintable  System_int8_isPrintable
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_int16)
#define have_auto_System_int16

__export struct_System_Type  System_int16Type;


#define System_int16_string8base2Length_DEFAULT  17
#define System_int16_string8base4Length_DEFAULT  9
#define System_int16_string8base8Length_DEFAULT  7
#define System_int16_string8base16Length_DEFAULT  5
#define System_int16_string8base10Length_DEFAULT  6

__export System_boolean  System_int16_isPrintable(System_int16 that);
__export System_size  System_int16_tostring8base2__stack(System_int16 that, System_char8 array[System_int16_string8base2Length_DEFAULT + 1]);
__export System_size  System_int16_tostring8base4__stack(System_int16 that, System_char8 array[System_int16_string8base4Length_DEFAULT + 1]);
__export System_size  System_int16_tostring8base8__stack(System_int16 that, System_char8 array[System_int16_string8base8Length_DEFAULT + 1]);
__export System_size  System_int16_tostring8base16__stack(System_int16 that, System_char8 array[System_int16_string8base16Length_DEFAULT + 1]);
__export System_size  System_int16_tostring8base10__stack(System_int16 that, System_char8 array[System_int16_string8base10Length_DEFAULT + 1]);;
#define inline_System_int16_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __int16Type  System_int16Type
#define __int16_isPrintable  System_int16_isPrintable
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_int32)
#define have_auto_System_int32

__export struct_System_Type  System_int32Type;


#define System_int32_string8base2Length_DEFAULT  33
#define System_int32_string8base4Length_DEFAULT  17
#define System_int32_string8base8Length_DEFAULT  12
#define System_int32_string8base16Length_DEFAULT  9
#define System_int32_string8base10Length_DEFAULT  11

__export System_boolean  System_int32_isPrintable(System_int32 that);
__export System_size  System_int32_tostring8base2__stack(System_int32 that, System_char8 array[System_int32_string8base2Length_DEFAULT + 1]);
__export System_size  System_int32_tostring8base4__stack(System_int32 that, System_char8 array[System_int32_string8base4Length_DEFAULT + 1]);
__export System_size  System_int32_tostring8base8__stack(System_int32 that, System_char8 array[System_int32_string8base8Length_DEFAULT + 1]);
__export System_size  System_int32_tostring8base16__stack(System_int32 that, System_char8 array[System_int32_string8base16Length_DEFAULT + 1]);
__export System_size  System_int32_tostring8base10__stack(System_int32 that, System_char8 array[System_int32_string8base10Length_DEFAULT + 1]);;
#define inline_System_int32_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __int32Type  System_int32Type
#define __int32_isPrintable  System_int32_isPrintable
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(have_auto_System_int64)
#define have_auto_System_int64

__export struct_System_Type  System_int64Type;


#define System_int64_string8base2Length_DEFAULT  65
#define System_int64_string8base4Length_DEFAULT  33
#define System_int64_string8base8Length_DEFAULT  23
#define System_int64_string8base16Length_DEFAULT  17
#define System_int64_string8base10Length_DEFAULT  21

__export System_boolean  System_int64_isPrintable(System_int64 that);
__export System_size  System_int64_tostring8base2__stack(System_int64 that, System_char8 array[System_int64_string8base2Length_DEFAULT + 1]);
__export System_size  System_int64_tostring8base4__stack(System_int64 that, System_char8 array[System_int64_string8base4Length_DEFAULT + 1]);
__export System_size  System_int64_tostring8base8__stack(System_int64 that, System_char8 array[System_int64_string8base8Length_DEFAULT + 1]);
__export System_size  System_int64_tostring8base16__stack(System_int64 that, System_char8 array[System_int64_string8base16Length_DEFAULT + 1]);
__export System_size  System_int64_tostring8base10__stack(System_int64 that, System_char8 array[System_int64_string8base10Length_DEFAULT + 1]);;
#define inline_System_int64_isPrintable(byte)  (byte > 0x1F && byte < 0x7F) || (byte > 0x9F && byte != 0xAD)
#if defined(using_System)
#define __int64Type  System_int64Type
#define __int64_isPrintable  System_int64_isPrintable
#endif
#endif
