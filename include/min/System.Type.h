/* Gemeinfrei. Public Domain. */
#if !defined(have_System_asm)
#include "System.asm.h"
#endif
#if !defined(have_System_stddef)
#include "System.stddef.h"
#endif
#if !defined(have_System_limits)
#include "System.limits.h"
#endif
#if !defined(have_System_assert)
#include "System.assert.h"
#endif
#if !defined(have_System_string8)
#include "System.string8.h"
#endif
#if !defined(have_System_value)
#include "System.value.h"
#endif
#if !defined(have_System_arguments)
#include "System.arguments.h"
#endif

#if !defined(have_System_Type)
#define have_System_Type

/* static class System.Type */

#define struct_System_Type  struct class_System_Type

typedef __fixed struct_System_Type  * System_Type;

/* static struct System.Object.bitConfig */

#define struct_System_Object_bitConfig  struct System_Object_bitConfig

struct_System_Object_bitConfig {

    System_uint8  isAllocated; // : 1;

    System_uint8  isValueAllocated; // : 1;

    System_uint16  __padding_0;
};

/* static class System.Object */

#define struct_System_Object  struct class_System_Object

typedef __fixed struct_System_Object {

    System_Type  Type;

    struct_System_Object_bitConfig  bitConfig;

    System_uint32  refCount;

    System_size  hashCode;

}  * System_Object;

#define stack_System_Object(T)  (struct_System_Object){ .Type = __typeof(T), }


typedef unsigned int  enum_System_byteOrder;
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
typedef System_uint64  enum_System_encoding;
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

	enum_System_encoding  codepage;

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

/* static class System.Type.FunctionInfo */

#define struct_System_Type_FunctionInfo  struct class_System_Type_FunctionInfo
typedef __fixed struct_System_Type_FunctionInfo {
	struct_System_Object  base;

	System_string8  name;

	System_var function;

	System_var value;

}  * System_Type_FunctionInfo;

/* static class System.Type.FunctionInfoArray */

#define struct_System_Type_FunctionInfoArray  struct class_System_Type_FunctionInfoArray
typedef __fixed struct_System_Type_FunctionInfoArray {
	struct_System_Object base;

	System_size  length;

	struct_System_Type_FunctionInfo  (* value)[];

}  * System_Type_FunctionInfoArray;

/* static class System.Type.InterfaceInfo */

#define struct_System_Type_InterfaceInfo  struct class_System_Type_InterfaceInfo
typedef __fixed struct_System_Type_InterfaceInfo {
	struct_System_Object  base;

    System_Type  interfaceType;

	System_size  offset;

	struct_System_Type_FunctionInfoArray  functions;

}  * System_Type_InterfaceInfo;

/* static class System.Type.InterfaceInfoArray */

#define struct_System_Type_InterfaceInfoArray  struct class_System_Type_InterfaceInfoArray
typedef __fixed struct_System_Type_InterfaceInfoArray {
	struct_System_Object base;

	System_size  length;

	struct_System_Type_InterfaceInfo  (* value)[];

}  * System_Type_InterfaceInfoArray;


/* static class System.Type.FieldInfo */

#define struct_System_Type_FieldInfo  struct class_System_Type_FieldInfo
typedef __fixed struct_System_Type_FieldInfo {
	struct_System_Object  base;

    System_string8  name;

    System_intptr  value;

}  * System_Type_FieldInfo;

/* static class System.Type.FieldInfoArray */

#define struct_System_Type_FieldInfoArray  struct class_System_Type_FieldInfoArray
typedef __fixed struct_System_Type_FieldInfoArray {
	struct_System_Object base;

	System_size  length;

	struct_System_Type_FieldInfo  (* value)[];

}  * System_Type_FieldInfoArray;


struct_System_Type {
	struct_System_Object  base;

	System_String  name;
	System_size  size;
	System_Type  baseType;

	struct_System_Type_FunctionInfoArray  functions;
	struct_System_Type_InterfaceInfoArray  interfaces;
	struct_System_Type_FieldInfoArray  fields; /* for Enum.getValue */
	/* TODO: struct_System_Type_PropertyInfoArray  properties; */
};

#define stack_System_Type__baseType(___name, ___size)  (struct_System_Type){ .base = { .Type = __typeof(System_Type) },\
    .name =  ___name, .size = ___size, .baseType =  __typeof(System_Object) }


/* literal Types */

__export struct_System_Type  System_voidType; /* sizeof(void) == 1  */
__export struct_System_Type  System_varType;  /* sizeof(void *) on x86_64 is * 8 == 64bits  */

__export struct_System_Type  System_sizeType;
__export struct_System_Type  System_intptrType;
__export struct_System_Type  System_ssizeType;
__export struct_System_Type  System_sintptrType;

__export struct_System_Type  System_booleanType;

#if defined(using_System)
#define __voidType  System_voidType
#define __varType  System_varType
#define __sizeType  System_sizeType
#define __intptrType  System_intptrType
#define __ssizeType  System_ssizeType
#define __sintptrType  System_sintptrType

#define __booleanType  System_booleanType
#endif

#include "System.values.auto.h"

#include "System.decimal.h"

/* class Types */

/* __export struct_System_Type  namespace_System; */

__export struct_System_Type  System_TypeType;

__export struct_System_Type  System_Type_FunctionInfoType;
__export struct_System_Type  System_Type_FunctionInfoArrayType;

__export struct_System_Type  System_Type_InterfaceInfoType;
__export struct_System_Type  System_Type_InterfaceInfoArrayType;

__export struct_System_Type  System_Type_FieldInfoType;
__export struct_System_Type  System_Type_FieldInfoArrayType;

#if defined(using_System)
#define struct_Type  struct_System_Type
#define stack_Type  stack_System_Type
#define __Type  System_Type
#define __TypeType  System_TypeType

#define struct_Type_FunctionInfo  struct_System_Type_FunctionInfo
#define __Type_FunctionInfo  System_Type_FunctionInfo
#define __Type_FunctionInfoType  System_Type_FunctionInfoType
#define struct_Type_FunctionInfoArray  struct_System_Type_FunctionInfoArray
#define __Type_FunctionInfoArray  System_Type_FunctionInfoArray
#define __Type_FunctionInfoArrayType  System_Type_FunctionInfoArrayType

#define struct_Type_InterfaceInfo  struct_System_Type_InterfaceInfo
#define __Type_InterfaceInfo  System_Type_InterfaceInfo
#define __Type_InterfaceInfoType  System_Type_InterfaceInfoType
#define struct_Type_InterfaceInfoArray  struct_System_Type_InterfaceInfoArray
#define __Type_InterfaceInfoArray  System_Type_InterfaceInfoArray
#define __Type_InterfaceInfoArrayType  System_Type_InterfaceInfoArrayType

#define struct_Type_FieldInfo  struct_System_Type_FieldInfo
#define __Type_FieldInfo  System_Type_FieldInfo
#define __Type_FieldInfoType  System_Type_FieldInfoType
#define struct_Type_FieldInfoArray  struct_System_Type_FieldInfoArray
#define __Type_FieldInfoArray  System_Type_FieldInfoArray
#define __Type_FieldInfoArrayType  System_Type_FieldInfoArrayType
#endif

#include "System.Object.h"

#include "System.IEnumerable.h"

#include "System.ICollection.h"

#include "System.Exception.h"

#include "System.String.h"

#include "System.valueArrays.auto.h"

#include "System.Array.h"
#include "System.ArrayEnumerator.h"

#include "System.Arrays.auto.h"

#include "System.Memory.h"

#include "System.Console.h"

__export System_string8  System_enum_getName(System_Type type, System_intptr value);

#define inline_System_enum_getName(__CLASS, __VALUE)  System_enum_getName(__typeof(__CLASS), (System_intptr)(__VALUE))

#if defined(using_System)
#define __enum_getName  System_enum_getName
#define inline_enum_getName  inline_System_enum_getName
#endif


__export void  System_function_void(void);

__export void  System_function_that(System_Object that);

__export System_var System_function_that_return(System_Object that);

__export System_var System_Type_getMethod(System_Type  that, System_var function);

__private inline __artificial System_var inline_System_Type_getMethod(System_Type  that, System_var function) {
    System_assert(that)

    for (System_size i = 0; i < that->functions.length; ++i) {
        struct_System_Type_FunctionInfo info =  __array(that->functions.value)[i];

        if (info.function == function) {
            return info.value;
        }
    }

    if (that->baseType) return System_Type_getMethod(that->baseType, function);

    __throw_terminate(inline_System_Exception_new("NotImplementedException_new: Method not found"));
}

__export System_boolean  System_Type_isAssignableFrom(System_Type  that, System_Type  other);

#if defined(using_System)
#define __Type_getMethod  System_Type_getMethod
#endif

#endif
