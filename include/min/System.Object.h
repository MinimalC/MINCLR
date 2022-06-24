/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#error "Use include System.Type.h instead."
#endif
#if !defined(have_System_Object)
#define have_System_Object

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

__export struct_System_Type  System_ObjectType;

__export System_Object  System_Object_new();
__export System_Object  System_Object_allocClass(System_Type type);
__export System_void  System_Object_freeClass(System_Object  * that);
__export System_Type  System_Object_get_Type(System_Object that);
__export System_boolean  System_Object_isInstanceOf(System_Object that, System_Type type);
__export System_Object  System_Object_asInstanceOf(System_Object that, System_Type type);
__export System_boolean  System_Object_referenceEquals(System_Object that, System_Object other);
__export System_Object  System_Object_addReference(System_Object that);

#define inline_System_Object_new()  (base_System_Object_init(inline_System_Object_allocClass(System_Object)))
#define inline_System_Object_allocClass(T)  ((T)System_Object_allocClass(__typeof(T)))
#define inline_System_Object_freeClass(T)  ((System_void)System_Object_freeClass((System_Object *)T))
#define inline_System_Object_get_Type(that)  ((System_Object)that)->Type
#define inline_System_Object_isInstanceOf(o,T)  (System_Object_isInstanceOf((System_Object)o,__typeof(T)))
#define inline_System_Object_asInstanceOf(o,T)  ((T)System_Object_asInstanceOf((System_Object)o,__typeof(T)))
#define inline_System_Object_referenceEquals(THAT,OTHER)  (THAT == OTHER)

#if defined(using_System)
#define struct_Object_bitConfig  struct_System_Object_bitConfig
#define struct_Object  struct_System_Object
#define stack_Object  stack_System_Object
#define __Object  System_Object
#define __ObjectType  System_ObjectType

#define __Object_new  System_Object_new
#define __Object_allocClass  System_Object_allocClass
#define __Object_freeClass  System_Object_freeClass
#define __Object_get_Type  System_Object_get_Type
#define __Object_isInstanceOf  System_Object_isInstanceOf
#define __Object_asInstanceOf  System_Object_asInstanceOf
#define __Object_referenceEquals  System_Object_referenceEquals

#define inline_Object_new  inline_System_Object_new
#define inline_Object_allocClass  inline_System_Object_allocClass
#define inline_Object_freeClass  inline_System_Object_freeClass
#define inline_Object_get_Type  inline_System_Object_get_Type
#define inline_Object_isType  inline_System_Object_isType
#define inline_Object_asType  inline_System_Object_asType
#define inline_Object_referenceEquals  inline_System_Object_referenceEquals

#define __Object_addReference  System_Object_addReference

#define __is  inline_Object_isInstanceOf
#define __as  inline_Object_asInstanceOf
#endif


/* class System.Object */

/* delegate functions */
typedef System_void __delegate(System_Object_free)(System_Object that);
typedef System_Object __delegate(System_Object_init)(System_Object that);
typedef System_uint64 __delegate(System_Object_getSipHash)(System_Object that);

/* methods */
__export System_void  base_System_Object_free(System_Object that);
__export System_Object  base_System_Object_init(System_Object that);
__export System_uint64  base_System_Object_getSipHash(System_Object that);

#define System_Object_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Object_init(o)  ((function_System_Object_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_Object_getSipHash(o)  ((function_System_Object_getSipHash)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_getSipHash))(o)

#if defined(using_System)
#define function_Object_init  function_System_Object_init
#define function_Object_free  function_System_Object_free

#define base_Object_free  base_System_Object_free
#define base_Object_init  base_System_Object_init
#define base_Object_getSipHash  base_System_Object_getSipHash

#define __Object_free  System_Object_free
#define __Object_init  System_Object_init
#define __Object_getSipHash  System_Object_getSipHash
#endif

#endif
