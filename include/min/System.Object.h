/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#error "Use include System.Type.h instead."
#endif
#if !defined(have_System_Object)
#define have_System_Object

#define struct_System_Object_bitConfig  struct System_Object_bitConfig

struct_System_Object_bitConfig {

    unsigned  isAllocated : 1;

    unsigned  isValueAllocated : 1;

    unsigned  isValue1Allocated : 1;

    unsigned  isValue2Allocated : 1;
};

#define struct_System_Object  struct class_System_Object

typedef fixed struct_System_Object {

    System_Type  type;

    struct_System_Object_bitConfig  bitConfig;

    System_uint32  refCount;

    System_size  hashCode;

} * System_Object;

#define stack_System_Object(T)  (struct_System_Object){ .type = typeof(T), }

export struct_System_Type  System_ObjectType;

export System_Object  System_Object_new();
export System_Object  System_Object_allocClass(System_Type type);
export void  System_Object_freeClass(System_Object  * that);
export System_Type  System_Object_get_Type(System_Object that);
export System_boolean  System_Object_isInstanceof(System_Object that, System_Type type);
export System_Object  System_Object_asInstanceof(System_Object that, System_Type type);
export System_boolean  System_Object_referenceEquals(System_Object that, System_Object other);
export System_Object  System_Object_addReference(System_Object that);

typedef void delegate(System_Object_free)(System_Object that);
typedef System_Object delegate(System_Object_init)(System_Object that);
typedef System_uint64 delegate(System_Object_getSipHash)(System_Object that);

export void  base_System_Object_free(System_Object that);
export System_Object  base_System_Object_init(System_Object that);
export System_uint64  base_System_Object_getSipHash(System_Object that);

#define System_Object_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Object_init(o)  ((function_System_Object_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_Object_getSipHash(o)  ((function_System_Object_getSipHash)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_getSipHash))(o)

#define inline_System_Object_new()  (base_System_Object_init(inline_System_Object_allocClass(System_Object)))
#define inline_System_Object_allocClass(T)  ((T)System_Object_allocClass(typeof(T)))
#define inline_System_Object_freeClass(T)  ((void)System_Object_freeClass((System_Object *)T))
#define inline_System_Object_get_Type(that)  ((System_Object)that)->type
#define inline_System_Object_isInstanceof(o,T)  (System_Object_isInstanceof((System_Object)o,typeof(T)))
#define inline_System_Object_asInstanceof(o,T)  ((T)System_Object_asInstanceof((System_Object)o,typeof(T)))
#define inline_System_Object_referenceEquals(THAT,OTHER)  (THAT == OTHER)

#if defined(using_System)
#define struct_Object_bitConfig  struct_System_Object_bitConfig
#define struct_Object  struct_System_Object
#define stack_Object  stack_System_Object
#define Object  System_Object
#define ObjectType  System_ObjectType

#define Object_new  System_Object_new
#define Object_allocClass  System_Object_allocClass
#define Object_freeClass  System_Object_freeClass
#define Object_get_Type  System_Object_get_Type
#define Object_isInstanceof  System_Object_isInstanceof
#define Object_asInstanceof  System_Object_asInstanceof
#define Object_referenceEquals  System_Object_referenceEquals
#define Object_addReference  System_Object_addReference

#define function_Object_init  function_System_Object_init
#define function_Object_free  function_System_Object_free

#define base_Object_free  base_System_Object_free
#define base_Object_init  base_System_Object_init
#define base_Object_getSipHash  base_System_Object_getSipHash

#define Object_free  System_Object_free
#define Object_init  System_Object_init
#define Object_getSipHash  System_Object_getSipHash

#define inline_Object_new  inline_System_Object_new
#define inline_Object_allocClass  inline_System_Object_allocClass
#define inline_Object_freeClass  inline_System_Object_freeClass
#define inline_Object_get_Type  inline_System_Object_get_Type
#define inline_Object_isType  inline_System_Object_isType
#define inline_Object_asType  inline_System_Object_asType
#define inline_Object_referenceEquals  inline_System_Object_referenceEquals

#define isInstanceof  inline_Object_isInstanceof
#define asInstanceof  inline_Object_asInstanceof
#endif
#endif
