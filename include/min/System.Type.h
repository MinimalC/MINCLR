/* Gemeinfrei. Public Domain. */
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
#error "This doesn't work in C++, as this throws a compiler exception. Use AWK and C !"
/*
1. C++Exceptions are using setjmp, to jump the stack.
   In Minimal C, Exceptions just return, return 0 or System_Exception_terminate.
2. typedef struct Name Name; even in extern "C": C++ throws a compiler exception.
   In Minimal C, you just use typedef struct Name * Name;
*/
#endif
#if !defined(have_System_Type)
#define have_System_Type

typedef System_fixed struct System_Type  * System_Type;

#include "System.Object.h"

typedef System_fixed struct System_Type_FunctionInfo {
	struct System_Object  base;

	System_String8  name;

	System_Var function;

	System_Var value;

}  * System_Type_FunctionInfo;

typedef System_fixed struct System_Type_FunctionInfoArray {
	struct System_Object base;

	System_Size  length;

	struct System_Type_FunctionInfo  (* value)[];

}  * System_Type_FunctionInfoArray;

typedef System_fixed struct System_Type_InterfaceInfo {
	struct System_Object  base;

    System_Type  interfaceType;

	System_Size  offset;

	struct System_Type_FunctionInfoArray  functions;

}  * System_Type_InterfaceInfo;

typedef System_fixed struct System_Type_InterfaceInfoArray {
	struct System_Object base;

	System_Size  length;

	struct System_Type_InterfaceInfo  (* value)[];

}  * System_Type_InterfaceInfoArray;

typedef System_fixed struct System_Type_FieldInfo {
	struct System_Object  base;

    System_String8  name;

    System_IntPtr  value;

}  * System_Type_FieldInfo;

typedef System_fixed struct System_Type_FieldInfoArray {
	struct System_Object base;

	System_Size  length;

	struct System_Type_FieldInfo  (* value)[];

}  * System_Type_FieldInfoArray;


struct System_Type {
	struct System_Object  base;

	System_String8  name;
	System_Size  size;
	System_Type  baseType;

	struct System_Type_FunctionInfoArray  functions;
	struct System_Type_InterfaceInfoArray  interfaces;
	struct System_Type_FieldInfoArray  fields; /* for Enum.getValue */
	/* TODO: struct System_Type_PropertyInfoArray  properties; */
};

/* export struct System_Type  namespace_System; */

export struct System_Type  System_TypeType;

export struct System_Type  System_Type_FunctionInfoType;
export struct System_Type  System_Type_FunctionInfoArrayType;

export struct System_Type  System_Type_InterfaceInfoType;
export struct System_Type  System_Type_InterfaceInfoArrayType;

export struct System_Type  System_Type_FieldInfoType;
export struct System_Type  System_Type_FieldInfoArrayType;

#if defined(using_System)
#define Type  System_Type
#define TypeType  System_TypeType
#define Type_FunctionInfo  System_Type_FunctionInfo
#define Type_FunctionInfoType  System_Type_FunctionInfoType
#define Type_FunctionInfoArray  System_Type_FunctionInfoArray
#define Type_FunctionInfoArrayType  System_Type_FunctionInfoArrayType
#define Type_InterfaceInfo  System_Type_InterfaceInfo
#define Type_InterfaceInfoType  System_Type_InterfaceInfoType
#define Type_InterfaceInfoArray  System_Type_InterfaceInfoArray
#define Type_InterfaceInfoArrayType  System_Type_InterfaceInfoArrayType
#define Type_FieldInfo  System_Type_FieldInfo
#define Type_FieldInfoType  System_Type_FieldInfoType
#define Type_FieldInfoArray  System_Type_FieldInfoArray
#define Type_FieldInfoArrayType  System_Type_FieldInfoArrayType
#endif

export struct System_Type  System_VoidType; /* sizeof(void) == 1  */
export struct System_Type  System_VarType;  /* sizeof(void *) on x86_64 is * 8 == 64bits  */
export struct System_Type  System_SizeType;
export struct System_Type  System_IntPtrType;
export struct System_Type  System_BoolType;

#if defined(using_System)
#define VarType  System_VarType
#define SizeType  System_SizeType
#define IntPtrType  System_IntPtrType
#define BoolType  System_BoolType
#endif

export System_Var System_Type_getMethod(System_Type  that, System_Var function);
export System_Var System_Type_tryMethod(System_Type  that, System_Var function);
// internal inline artificial System_Var inline_System_Type_getMethod(System_Type  that, System_Var function) {

export System_Bool  System_Type_isAssignableFrom(System_Type  that, System_Type  other);

#if defined(using_System)
#define Type_getMethod  System_Type_getMethod
#define Type_tryMethod  System_Type_tryMethod
#define Type_isAssignableFrom  System_Type_isAssignableFrom
#endif

#if !defined(have_System_enum)
#define have_System_enum
export System_String8  System_enum_getName(System_Type type, System_IntPtr value);
#define inline_System_enum_getName(CLASS, VALUE)  System_enum_getName(typeof(CLASS), (System_IntPtr)(VALUE))
/* TODO: inline_System_enum_toString is running into enum_System_Origin_toString(value), possibly returning a string for that value */
#define inline_System_enum_toString(ENUM, VALUE)  ccc(enum_,ENUM,_toString)(VALUE)
#if defined(using_System)
#define enum_getName  System_enum_getName
#define inline_enum_getName  inline_System_enum_getName
#define inline_enum_toString  inline_System_enum_toString
#endif
#endif

export void  System_Debug_assert__String8(const System_String8 expression, const System_String8 functionName, const System_String8 file, const System_Size line);
export void  System_Debug_writeLine__message(const System_String8 message, ...);
#if !DEBUG
#define System_Debug_assert(expression) (void)(expression)
#define System_Debug_writeLine(message,...) (void)(message, __VA_ARGS__)
#else
#define System_Debug_assert(expression)  (void)(!(expression) ? System_Debug_assert__String8((System_String8)#expression, (System_String8)__func__, (System_String8)__FILE__, (System_Size)__LINE__) : 0)
#define System_Debug_writeLine(message,...)  (void)System_Debug_writeLine__message((System_String8)message, __VA_ARGS__)
#endif
#if defined(using_System)
#define Debug_assert  System_Debug_assert
#define Debug_writeLine  System_Debug_writeLine
#endif
#endif
