/* Gemeinfrei. Public Domain. */
#if !defined(have_System_stddef)
#include "System.stddef.h"
#endif
#if !defined(have_System_limits)
#include "System.limits.h"
#endif
#if !defined(have_System_Arguments)
#include "System.Arguments.h"
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
	System_String8  name;
	System_Var function;
	System_Var value;
}  * System_Type_FunctionInfo;

typedef System_fixed struct System_Type_FunctionInfoArray {
	System_Size  length;
	struct System_Type_FunctionInfo  (* value)[];
}  * System_Type_FunctionInfoArray;

typedef System_fixed struct System_Type_InterfaceInfo {
    System_Type  interfaceType;
	System_Size  offset;
	struct System_Type_FunctionInfoArray  functions;
}  * System_Type_InterfaceInfo;

typedef System_fixed struct System_Type_InterfaceInfoArray {
	System_Size  length;
	struct System_Type_InterfaceInfo  (* value)[];
}  * System_Type_InterfaceInfoArray;

typedef System_fixed struct System_Type_FieldInfo {
    System_String8  name;
    System_IntPtr  value;
}  * System_Type_FieldInfo;

typedef System_fixed struct System_Type_FieldInfoArray {
	System_Size  length;
	struct System_Type_FieldInfo  (* value)[];
}  * System_Type_FieldInfoArray;

struct System_Type {
	struct System_Object  base;

	System_String8  name;
	System_Size  size;
	System_UInt64  baseType;

	struct System_Type_FunctionInfoArray  functions;
	struct System_Type_InterfaceInfoArray  interfaces;
	struct System_Type_FieldInfoArray  fields; /* for Enum.getValue */
	/* TODO: struct System_Type_PropertyInfoArray  properties; */
};

export struct System_Type  System_TypeType;
export struct System_Type  System_VoidType; /* sizeof(void) == 1  */
export struct System_Type  System_VarType;  /* sizeof(void *) on x86_64 is * 8 == 64bits  */
export struct System_Type  System_SizeType;
export struct System_Type  System_SSizeType;
export struct System_Type  System_IntPtrType;
export struct System_Type  System_SIntPtrType;
export struct System_Type  System_BoolType;

#if defined(using_System)
#define Type  System_Type
#define TypeType  System_TypeType
#define VoidType  System_VoidType
#define VarType  System_VarType
#define SizeType  System_SizeType
#define SSizeType  System_SSizeType
#define IntPtrType  System_IntPtrType
#define SIntPtrType  System_SIntPtrType
#define BoolType  System_BoolType
#endif

enum { typeof_System_Type = 0xE8E7E4A139BB3C3D };   /* SipHash48 of "System.Type" */

#if defined(using_System)
#define typeof_Type  typeof_System_Type
#endif

export System_Var System_Type_getMethod(System_Type  that, System_Var function);
export System_Var System_Type_tryMethod(System_Type  that, System_Var function);
// inline artificial System_Var inline_System_Type_getMethod(System_Type  that, System_Var function)
export System_Bool  System_Type_isAssignableFrom(System_Type  that, System_Type  other);
export System_UInt64 System_Type_getSipHash(System_Type that);
export System_Type System_Type_getBySipHash(System_UInt64 hash);
export System_Type System_Type_getBySipHash__name(System_UInt64 hash, System_String8 name);

#if defined(using_System)
#define Type_get  System_Type_get
#define Type_getMethod  System_Type_getMethod
#define Type_tryMethod  System_Type_tryMethod
#define Type_isAssignableFrom  System_Type_isAssignableFrom
#define Type_getSipHash  System_Type_getSipHash
#endif
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
