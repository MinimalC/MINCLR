/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_String)
#define have_System_String

typedef unsigned  System_byteOrder;
#define System_byteOrder_LittleEndian  0xFFFFFEFE
#define System_byteOrder_BigEndian     0xFEFEFFFF
/* #define System_byteOrder_PDPEndian  0xFFFEFFFE (?) */

#if !defined(System_byteOrder_NATIVE)
#if defined(i386)     || defined(__i386__)   || defined(_M_IX86) ||\
    defined(__x86_64) || defined(__x86_64__) || defined(_M_X64)  ||\
    defined(_M_AMD64) || defined(_M_ARM)     || defined(__x86)   ||\
    defined(__arm__)

#define System_byteOrder_NATIVE    System_byteOrder_LittleEndian

#elif defined(sparc)  || defined(__ppc__)
#define System_byteOrder_NATIVE    System_byteOrder_BigEndian

#else
/* inspired by sqliteInt.h */
#error Unknown System_byteOrder_NATIVE
/*#ifdef SQLITE_AMALGAMATION	const int System_byteOrder_check = 1; **
extern const uint32_t System_byteOrder_check;
#define System_byteOrder_LittleEndian_check (*(uint8_t *)(&System_byteOrder_check) == 1)
#define System_byteOrder_BigEndian_check    (*(uint8_t *)(&System_byteOrder_check) == 0)
#define System_byteOrder_NATIVE	(System_byteOrder_LittleEndian_check ? System_byteOrder_LittleEndian : System_byteOrder_BigEndian) */
#endif
#endif

/*	Unicode MetaStandard: */
/*	UTF8   : EF BB BF 00  00 00 00 00
	UTF16LE: FF FE 00 00  00 00 00 00
	UTF16BE: FE FF 00 00  00 00 00 00
	UTF32LE: FF FF FE FE  00 00 00 00
	UTF32BE: FE FE FF FF  00 00 00 00
	new:
	UTF64LE: FF FF FF FF  FE FE FE FE
	UTF64BE: FE FE FE FE  FF FF FF FF */
typedef System_uint32  System_encoding;
#define System_encoding_UTF8     0x0000000000EFBBBF
#define System_encoding_UTF16LE  0x000000000000FFFE
#define System_encoding_UTF16BE  0x000000000000FEFF
#define System_encoding_UTF32LE  0x00000000FFFFFEFE
#define System_encoding_UTF32BE  0x00000000FEFEFFFF

#if System_byteOrder_NATIVE == System_byteOrder_BigEndian
/* This is BigEndian */
#define System_encoding_UTF16  System_encoding_UTF16BE
#define System_encoding_UTF32  System_encoding_UTF32BE

#elif System_byteOrder_NATIVE == System_byteOrder_LittleEndian
/* This is LitteEndian */
#define System_encoding_UTF16  System_encoding_UTF16LE
#define System_encoding_UTF32  System_encoding_UTF32LE

#else
#error System_encoding: Unknown System_byteOrder_NATIVE
/*	#define System_encoding_UTF16	( System_byteOrder_BigEndian ? System_encoding_UTF16BE : System_encoding_UTF16LE )
#define System_encoding_UTF32	( System_byteOrder_BigEndian ? System_encoding_UTF32BE : System_encoding_UTF32LE ) */
#endif

/* static class System.String */


typedef fixed struct System_String {
	struct System_Object  base;

	System_size  length;

	System_encoding  codepage;

	System_string8  value;

/*  System_string16  value16;

	System_string32  value32; */

}  * System_String;


#if UNICODE == 32
#define stack_System_String(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_encoding_UTF32, .length = (sizeof(s) - 1), .value32 = (System_string32)(s), }
#define System_encoding_DEFAULT	System_encoding_UTF32

#elif UNICODE == 16
#define stack_System_String(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_encoding_UTF16, .length = (sizeof(s) - 1), .value16 = (System_string16)(s), }
#define System_encoding_DEFAULT	System_encoding_UTF16

#else /* if UNICODE == 8 */
#define stack_System_String(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_encoding_UTF8, .length = (sizeof(s) - 1), .value = (System_string8)(s), }
#define System_encoding_DEFAULT	System_encoding_UTF8
#endif

#define new_System_String(s)  (base_System_String_init((System_String)System_Memory_allocClass(typeof(System_String)), s))

export struct System_Type  System_StringType;

typedef System_String delegate(System_String_init)(System_String, System_string8);
typedef void delegate(System_String_free)(System_String that);
typedef System_uint64 delegate(System_String_getSipHash)(System_String that);

export System_String  base_System_String_init(System_String, System_string8);
export void  base_System_String_free(System_String);
export System_uint64  base_System_String_getSipHash(System_String that);

#define System_String_init(o,...)  ((function_System_String_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String_init))(o, __VA_ARGS__)
#define System_String_free(o)  ((function_System_String_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String_getSipHash(o)  ((function_System_String_getSipHash)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_getSipHash))(o)


#if defined(using_System)
#define byteOrder  System_byteOrder
#define byteOrder_LittleEndian  System_byteOrder_LittleEndian
#define byteOrder_BigEndian  System_byteOrder_BigEndian
#define byteOrder_NATIVE  System_byteOrder_NATIVE

#define encoding  System_encoding
#define encoding_UTF8  System_encoding_UTF8
#define encoding_UTF16  System_encoding_UTF16
#define encoding_UTF32  System_encoding_UTF32
#define encoding_DEFAULT  System_encoding_DEFAULT


#define stack_String  stack_System_String
#define String  System_String
#define StringType  System_StringType
#define new_String  new_System_String
#define function_String_free  function_System_String_free
#define function_String_init  function_System_String_init
#define function_System_String_getSipHash  function_System_String_getSipHash
#define base_String_free  base_System_String_free
#define base_String_init  base_System_String_init
#define base_String_getSipHash  base_System_String_getSipHash
#define String_init  System_String_init
#define String_free  System_String_free
#define String_getSipHash  System_String_getSipHash
#endif

#endif
