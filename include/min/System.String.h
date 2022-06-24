/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_String)
#define have_System_String

typedef unsigned int  System_byteOrder;
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
typedef System_uint64  System_encoding;
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

#define struct_System_String  struct class_System_String
typedef __fixed struct_System_String {
	struct_System_Object  base;

	System_size  length;

	System_encoding  codepage;

	System_string  value;

}  * System_String;

#define const_System_String__UTF8(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_encoding_UTF8, .length = (sizeof(s) - 1), .value = (System_string8)(s), }

#define const_System_String__UTF16(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_encoding_UTF16, .length = (sizeof(s) - 1), .value = (System_string16)(s), }

#define const_System_String__UTF32(s)  { .base = stack_System_Object(System_String),\
    .codepage = System_encoding_UTF32, .length = (sizeof(s) - 1), .value = (System_string32)(s), }

#define stack_System_String__UTF8  (struct_System_String)const_System_String__UTF8

#define stack_System_String__UTF16  (struct_System_String)const_System_String__UTF16

#define stack_System_String__UTF32  (struct_System_String)const_System_String__UTF32

#if __UNICODE == 32
#define System_encoding_DEFAULT	System_encoding_UTF32
#define const_System_String  const_System_String__UTF32
#define stack_System_String  stack_System_String__UTF32

#elif __UNICODE == 16
#define System_encoding_DEFAULT	System_encoding_UTF16
#define const_System_String  const_System_String__UTF16
#define stack_System_String  stack_System_String__UTF16

#else /* if __UNICODE == 8 */
#define System_encoding_DEFAULT	System_encoding_UTF8
#define const_System_String  const_System_String__UTF8
#define stack_System_String  stack_System_String__UTF8
#endif

/* static class System_String */

__export struct_System_Type  System_StringType;

/* class System.String */

typedef System_String __delegate(System_String_init)(System_String, System_string8);
typedef System_void __delegate(System_String_free)(System_String that);
typedef System_uint64 __delegate(System_String_getSipHash)(System_String that);

__export System_String  System_String_new(System_string8);
__export System_String  base_System_String_init(System_String, System_string8);
__export System_void  base_System_String_free(System_String);
__export System_uint64  base_System_String_getSipHash(System_String that);

#define System_String_init(o,...)  ((function_System_String_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String_init))(o, __VA_ARGS__)
#define System_String_free(o)  ((function_System_String_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String_getSipHash(o)  ((function_System_String_getSipHash)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_getSipHash))(o)

#define inline_System_String_new(s)  (base_System_String_init(inline_System_Object_allocClass(System_String), s))


#if __UNICODE == 32
#define System_stringType  System_string32Type

#elif __UNICODE == 16
#define System_stringType  System_string16Type

#else /* if __UNICODE == 8 */
#define System_stringType  System_string8Type
#endif

#if defined(using_System)
#define __byteOrder  System_byteOrder
#define __byteOrder_LittleEndian  System_byteOrder_LittleEndian
#define __byteOrder_BigEndian  System_byteOrder_BigEndian
#define __byteOrder_NATIVE  System_byteOrder_NATIVE

#define __encoding  System_encoding
#define __encoding_UTF8  System_encoding_UTF8
#define __encoding_UTF16  System_encoding_UTF16
#define __encoding_UTF32  System_encoding_UTF32
#define __encoding_DEFAULT  System_encoding_DEFAULT

#define __string8Type  System_string8Type
#define __string16Type  System_string16Type
#define __string32Type  System_string32Type
#define __stringType  System_stringType

#define struct_String  struct_System_String
#define stack_String  stack_System_String
#define __String  System_String
#define __StringType  System_StringType

#define stack_String32  stack_System_String32
#define stack_String16  stack_System_String16
#define stack_String8  stack_System_String8

#define function_String_init  function_System_String_init
#define base_String_free  base_System_String_free
#define base_String_init  base_System_String_init
#define base_String_getSipHash  base_System_String_getSipHash
#define __String_new  System_String_new
#define __String_init  System_String_init
#define __String_free  System_String_free
#define __String_getSipHash  System_String_getSipHash
#endif

#endif
