/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#error "Use include System.Type.h instead."
#endif
#if !defined(have_System_Object)
#define have_System_Object

typedef System_fixed struct System_Object {

    System_Type  type;

} * System_Object;

export struct System_Type  System_ObjectType;

typedef void delegate(System_Object_free)(System_Object that);
typedef void delegate(System_Object_init)(System_Object that);
typedef void delegate(System_Object_init1)(System_Object that, System_Var arg1);
typedef void delegate(System_Object_init2)(System_Object that, System_Var arg1, System_Var arg2);
typedef void delegate(System_Object_init3)(System_Object that, System_Var arg1, System_Var arg2, System_Var arg3);
typedef void delegate(System_Object_init4)(System_Object that, System_Var arg1, System_Var arg2, System_Var arg3, System_Var arg4);
typedef System_UInt64 delegate(System_Object_getSipHash)(System_Object that);

export System_Object  new_System_Object();
export void  base_System_Object_free(System_Object that);
export void  base_System_Object_init(System_Object that);
export void  base_System_Object_init1(System_Object that, System_Var arg1);
export void  base_System_Object_init2(System_Object that, System_Var arg1, System_Var arg2);
export void  base_System_Object_init3(System_Object that, System_Var arg1, System_Var arg2, System_Var arg3);
export void  base_System_Object_init4(System_Object that, System_Var arg1, System_Var arg2, System_Var arg3, System_Var arg4);
export System_UInt64  base_System_Object_getSipHash(System_Object that);
export System_Type  System_Object_get_Type(System_Object that);
export System_Bool  System_Object_isInstanceof(System_Object that, System_Type type);
export System_Object  System_Object_asInstanceof(System_Object that, System_Type type);

#define System_Object_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Object_init(o)  ((function_System_Object_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_Object_getSipHash(o)  ((function_System_Object_getSipHash)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_getSipHash))(o)

#define inline_System_Object_get_Type(that)  ((System_Object)that)->type
#define inline_System_Object_isInstanceof(o,T)  (System_Object_isInstanceof((System_Object)o,typeof(T)))
#define inline_System_Object_asInstanceof(o,T)  ((T)System_Object_asInstanceof((System_Object)o,typeof(T)))

#if defined(using_System)

#define Object  System_Object
#define ObjectType  System_ObjectType
#define new_Object  new_System_Object

#define Object_get_Type  System_Object_get_Type
#define Object_isInstanceof  System_Object_isInstanceof
#define Object_asInstanceof  System_Object_asInstanceof

#define function_Object_init  function_System_Object_init
#define function_Object_free  function_System_Object_free

#define base_Object_free  base_System_Object_free
#define base_Object_init  base_System_Object_init
#define base_Object_getSipHash  base_System_Object_getSipHash

#define Object_free  System_Object_free
#define Object_init  System_Object_init
#define Object_getSipHash  System_Object_getSipHash

#define inline_Object_get_Type  inline_System_Object_get_Type
#define inline_Object_isInstanceof  inline_System_Object_isInstanceof
#define inline_Object_asInstanceof  inline_System_Object_asInstanceof
#define inline_Object_referenceEquals  inline_System_Object_referenceEquals

#define isInstanceof  inline_Object_isInstanceof
#define asInstanceof  inline_Object_asInstanceof
#endif
#endif
