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
#if !defined(have_System_arguments)
#include "System.arguments.h"
#endif
#if !defined(have_System_Type)
#define have_System_Type

/* static class System.Type */

#define struct_System_Type  struct class_System_Type

typedef __fixed struct_System_Type  * System_Type;

#include "System.Object.h"

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

	System_string8  name;
	System_size  size;
	System_Type  baseType;

	struct_System_Type_FunctionInfoArray  functions;
	struct_System_Type_InterfaceInfoArray  interfaces;
	struct_System_Type_FieldInfoArray  fields; /* for Enum.getValue */
	/* TODO: struct_System_Type_PropertyInfoArray  properties; */
};

#define stack_System_Type__baseType(___name, ___size)  (struct_System_Type){ .base = { .Type = __typeof(System_Type) },\
    .name =  ___name, .size = ___size, .baseType =  __typeof(System_Object) }


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

__export System_string8  System_enum_getName(System_Type type, System_intptr value);

#define inline_System_enum_getName(__CLASS, __VALUE)  System_enum_getName(__typeof(__CLASS), (System_intptr)(__VALUE))

#if defined(using_System)
#define __enum_getName  System_enum_getName
#define inline_enum_getName  inline_System_enum_getName
#endif

__export System_var System_Type_getMethod(System_Type  that, System_var function);

// __private inline __artificial System_var inline_System_Type_getMethod(System_Type  that, System_var function) {

__export System_boolean  System_Type_isAssignableFrom(System_Type  that, System_Type  other);

#if defined(using_System)
#define __Type_getMethod  System_Type_getMethod
#endif

#endif
