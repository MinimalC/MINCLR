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
#if !defined(have_System_arguments)
#include "System.arguments.h"
#endif
#if defined(__cplusplus)
#error "This doesn't work in C++. Use AWK and C !"
/*
1. C++Exceptions are using setjmp, to jump the stack.
   In Minimal C, Exceptions just return, return 0 or terminate.
2. typedef struct Name Name; even in extern "C": C++ throws a compiler exception.
   In Minimal C, you just use typedef struct Name * Name;
*/
#endif
#if !defined(have_System_Type)
#define have_System_Type

/* static class System.Type */

#define struct_System_Type  struct class_System_Type

typedef fixed struct_System_Type  * System_Type;

#include "System.Object.h"

/* static class System.Type.FunctionInfo */

#define struct_System_Type_FunctionInfo  struct class_System_Type_FunctionInfo
typedef fixed struct_System_Type_FunctionInfo {
	struct_System_Object  base;

	System_string8  name;

	System_var function;

	System_var value;

}  * System_Type_FunctionInfo;

/* static class System.Type.FunctionInfoArray */

#define struct_System_Type_FunctionInfoArray  struct class_System_Type_FunctionInfoArray
typedef fixed struct_System_Type_FunctionInfoArray {
	struct_System_Object base;

	System_size  length;

	struct_System_Type_FunctionInfo  (* value)[];

}  * System_Type_FunctionInfoArray;

/* static class System.Type.InterfaceInfo */

#define struct_System_Type_InterfaceInfo  struct class_System_Type_InterfaceInfo
typedef fixed struct_System_Type_InterfaceInfo {
	struct_System_Object  base;

    System_Type  interfaceType;

	System_size  offset;

	struct_System_Type_FunctionInfoArray  functions;

}  * System_Type_InterfaceInfo;

/* static class System.Type.InterfaceInfoArray */

#define struct_System_Type_InterfaceInfoArray  struct class_System_Type_InterfaceInfoArray
typedef fixed struct_System_Type_InterfaceInfoArray {
	struct_System_Object base;

	System_size  length;

	struct_System_Type_InterfaceInfo  (* value)[];

}  * System_Type_InterfaceInfoArray;


/* static class System.Type.FieldInfo */

#define struct_System_Type_FieldInfo  struct class_System_Type_FieldInfo
typedef fixed struct_System_Type_FieldInfo {
	struct_System_Object  base;

    System_string8  name;

    System_intptr  value;

}  * System_Type_FieldInfo;

/* static class System.Type.FieldInfoArray */

#define struct_System_Type_FieldInfoArray  struct class_System_Type_FieldInfoArray
typedef fixed struct_System_Type_FieldInfoArray {
	struct_System_Object base;

	System_size  length;

	struct_System_Type_FieldInfo  (* value)[];

}  * System_Type_FieldInfoArray;


struct_System_Type {
	struct_System_Object  base;

	System_string8  name;
	System_size  size;
	System_Type  baseType;

	struct_System_Type_FunctionInfoArray  functions;
	struct_System_Type_InterfaceInfoArray  interfaces;
	struct_System_Type_FieldInfoArray  fields; /* for Enum.getValue */
	/* TODO: struct_System_Type_PropertyInfoArray  properties; */
};


/* class Types */

/* export struct_System_Type  namespace_System; */

export struct_System_Type  System_TypeType;

export struct_System_Type  System_Type_FunctionInfoType;
export struct_System_Type  System_Type_FunctionInfoArrayType;

export struct_System_Type  System_Type_InterfaceInfoType;
export struct_System_Type  System_Type_InterfaceInfoArrayType;

export struct_System_Type  System_Type_FieldInfoType;
export struct_System_Type  System_Type_FieldInfoArrayType;

#if defined(using_System)
#define struct_Type  struct_System_Type
#define stack_Type  stack_System_Type
#define Type  System_Type
#define TypeType  System_TypeType

#define struct_Type_FunctionInfo  struct_System_Type_FunctionInfo
#define Type_FunctionInfo  System_Type_FunctionInfo
#define Type_FunctionInfoType  System_Type_FunctionInfoType
#define struct_Type_FunctionInfoArray  struct_System_Type_FunctionInfoArray
#define Type_FunctionInfoArray  System_Type_FunctionInfoArray
#define Type_FunctionInfoArrayType  System_Type_FunctionInfoArrayType

#define struct_Type_InterfaceInfo  struct_System_Type_InterfaceInfo
#define Type_InterfaceInfo  System_Type_InterfaceInfo
#define Type_InterfaceInfoType  System_Type_InterfaceInfoType
#define struct_Type_InterfaceInfoArray  struct_System_Type_InterfaceInfoArray
#define Type_InterfaceInfoArray  System_Type_InterfaceInfoArray
#define Type_InterfaceInfoArrayType  System_Type_InterfaceInfoArrayType

#define struct_Type_FieldInfo  struct_System_Type_FieldInfo
#define Type_FieldInfo  System_Type_FieldInfo
#define Type_FieldInfoType  System_Type_FieldInfoType
#define struct_Type_FieldInfoArray  struct_System_Type_FieldInfoArray
#define Type_FieldInfoArray  System_Type_FieldInfoArray
#define Type_FieldInfoArrayType  System_Type_FieldInfoArrayType
#endif

/* literal Types */

export struct_System_Type  voidType; /* sizeof(void) == 1  */
export struct_System_Type  System_varType;  /* sizeof(void *) on x86_64 is * 8 == 64bits  */

export struct_System_Type  System_sizeType;
export struct_System_Type  System_intptrType;
export struct_System_Type  System_ssizeType;
export struct_System_Type  System_sintptrType;

export struct_System_Type  System_booleanType;

#if defined(using_System)
#define varType  System_varType
#define sizeType  System_sizeType
#define intptrType  System_intptrType
#define ssizeType  System_ssizeType
#define sintptrType  System_sintptrType

#define booleanType  System_booleanType
#endif

export System_string8  System_enum_getName(System_Type type, System_intptr value);

#define inline_System_enum_getName(CLASS, VALUE)  System_enum_getName(typeof(CLASS), (System_intptr)(VALUE))

#if defined(using_System)
#define enum_getName  System_enum_getName
#define inline_enum_getName  inline_System_enum_getName
#endif

export System_var System_Type_getMethod(System_Type  that, System_var function);

// internal inline artificial System_var inline_System_Type_getMethod(System_Type  that, System_var function) {

export System_boolean  System_Type_isAssignableFrom(System_Type  that, System_Type  other);

#if defined(using_System)
#define Type_getMethod  System_Type_getMethod
#endif
#endif
