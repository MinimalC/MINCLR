/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_String)
#define have_System_String

typedef unsigned  System_ByteOrder;
#define System_ByteOrder_LittleEndian  0xFFFFFEFE
#define System_ByteOrder_BigEndian     0xFEFEFFFF
/* #define System_ByteOrder_PDPEndian  0xFFFEFFFE (?) */

#if !defined(System_ByteOrder_NATIVE)
#if defined(i386)     || defined(__i386__)   || defined(_M_IX86) ||\
    defined(__x86_64) || defined(__x86_64__) || defined(_M_X64)  ||\
    defined(_M_AMD64) || defined(_M_ARM)     || defined(__x86)   ||\
    defined(__arm__)

#define System_ByteOrder_NATIVE    System_ByteOrder_LittleEndian

#elif defined(sparc)  || defined(__ppc__)
#define System_ByteOrder_NATIVE    System_ByteOrder_BigEndian

#else
/* inspired by sqliteInt.h */
#error Unknown System_ByteOrder_NATIVE
/*#ifdef SQLITE_AMALGAMATION	const int System_ByteOrder_check = 1; **
extern const UInt32_t System_ByteOrder_check;
#define System_ByteOrder_LittleEndian_check (*(uint8_t *)(&System_ByteOrder_check) == 1)
#define System_ByteOrder_BigEndian_check    (*(uint8_t *)(&System_ByteOrder_check) == 0)
#define System_ByteOrder_NATIVE	(System_ByteOrder_LittleEndian_check ? System_ByteOrder_LittleEndian : System_ByteOrder_BigEndian) */
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
typedef System_UInt32  System_Encoding;
#define System_Encoding_UTF8     0x0000000000EFBBBF
#define System_Encoding_UTF16LE  0x000000000000FFFE
#define System_Encoding_UTF16BE  0x000000000000FEFF
#define System_Encoding_UTF32LE  0x00000000FFFFFEFE
#define System_Encoding_UTF32BE  0x00000000FEFEFFFF

#if System_ByteOrder_NATIVE == System_ByteOrder_BigEndian
/* This is BigEndian */
#define System_Encoding_UTF16  System_Encoding_UTF16BE
#define System_Encoding_UTF32  System_Encoding_UTF32BE

#elif System_ByteOrder_NATIVE == System_ByteOrder_LittleEndian
/* This is LitteEndian */
#define System_Encoding_UTF16  System_Encoding_UTF16LE
#define System_Encoding_UTF32  System_Encoding_UTF32LE

#else
#error System_Encoding: Unknown System_ByteOrder_NATIVE
/*	#define System_Encoding_UTF16	( System_ByteOrder_BigEndian ? System_Encoding_UTF16BE : System_Encoding_UTF16LE )
#define System_Encoding_UTF32	( System_ByteOrder_BigEndian ? System_Encoding_UTF32BE : System_Encoding_UTF32LE ) */
#endif

/* static class System.String */


typedef fixed struct System_String {
	struct System_Object  base;

	System_Size  length;

	System_Encoding  codepage;

	System_String8  value;

/*  System_string16  value16;

	System_string32  value32; */

}  * System_String;


#if UNICODE == 32
#define stack_System_String(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_Encoding_UTF32, .length = (sizeof(s) - 1), .value32 = (System_string32)(s), }
#define System_Encoding_DEFAULT	System_Encoding_UTF32

#elif UNICODE == 16
#define stack_System_String(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_Encoding_UTF16, .length = (sizeof(s) - 1), .value16 = (System_string16)(s), }
#define System_Encoding_DEFAULT	System_Encoding_UTF16

#else /* if UNICODE == 8 */
#define stack_System_String(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_Encoding_UTF8, .length = (sizeof(s) - 1), .value = (System_String8)(s), }
#define System_Encoding_DEFAULT	System_Encoding_UTF8
#endif

#define new_System_String(s)  (base_System_String_init((System_String)System_Memory_allocClass(typeof(System_String)), s))

export struct System_Type  System_StringType;

typedef System_String delegate(System_String_init)(System_String, System_String8);
typedef void delegate(System_String_free)(System_String that);
typedef System_UInt64 delegate(System_String_getSipHash)(System_String that);

export System_String  base_System_String_init(System_String, System_String8);
export void  base_System_String_free(System_String);
export System_UInt64  base_System_String_getSipHash(System_String that);

#define System_String_init(o,...)  ((function_System_String_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String_init))(o, __VA_ARGS__)
#define System_String_free(o)  ((function_System_String_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String_getSipHash(o)  ((function_System_String_getSipHash)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_getSipHash))(o)


#if defined(using_System)
#define byteOrder  System_ByteOrder
#define byteOrder_LittleEndian  System_ByteOrder_LittleEndian
#define byteOrder_BigEndian  System_ByteOrder_BigEndian
#define byteOrder_NATIVE  System_ByteOrder_NATIVE

#define encoding  System_Encoding
#define encoding_UTF8  System_Encoding_UTF8
#define encoding_UTF16  System_Encoding_UTF16
#define encoding_UTF32  System_Encoding_UTF32
#define encoding_DEFAULT  System_Encoding_DEFAULT


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
