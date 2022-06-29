/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Array)
#include "System.Array.h"
#endif
#if !defined(have_System_ArrayEnumerator)
#define have_System_ArrayEnumerator

#define struct_System_ArrayEnumerator  struct class_System_ArrayEnumerator
typedef fixed struct_System_ArrayEnumerator {
    struct_System_Object base;

    System_Array array;

    System_size index;

}  * System_ArrayEnumerator;

#define stack_System_ArrayEnumerator()  (struct_System_ArrayEnumerator){ .base = stack_System_Object(System_ArrayEnumerator), .array = null, }

export struct_System_Type  System_ArrayEnumeratorType;

typedef void delegate(System_ArrayEnumerator_free)(System_ArrayEnumerator that);
typedef System_ArrayEnumerator delegate(System_ArrayEnumerator_init)(System_ArrayEnumerator that, System_Array array);
typedef System_Object delegate(System_ArrayEnumerator_get_current)(System_ArrayEnumerator that);
typedef System_boolean delegate(System_ArrayEnumerator_moveNext)(System_ArrayEnumerator that);

#define System_ArrayEnumerator_new  System_ArrayEnumerator_new__00

export System_ArrayEnumerator  System_ArrayEnumerator_new(System_Array array);
export System_ArrayEnumerator  base_System_ArrayEnumerator_init(System_ArrayEnumerator that, System_Array array);
export void  base_System_ArrayEnumerator_free(System_ArrayEnumerator that);
export System_Object  base_System_ArrayEnumerator_get_current(System_ArrayEnumerator that);
export System_boolean  base_System_ArrayEnumerator_moveNext(System_ArrayEnumerator that);

#define System_ArrayEnumerator_init(o,...)  ((function_System_ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_ArrayEnumerator_free(o)  ((function_System_ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_ArrayEnumerator_get_current(o)  ((function_System_ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_ArrayEnumerator_moveNext(o)  ((function_System_ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_ArrayEnumerator_new(a)  (base_System_ArrayEnumerator_init(inline_System_Object_allocClass(System_ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_ArrayEnumerator_new
#define System_ArrayEnumerator_new  inline_System_ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_ArrayEnumerator  struct_System_ArrayEnumerator
#define ArrayEnumerator  System_ArrayEnumerator
#define ArrayEnumeratorType  System_ArrayEnumeratorType
#define function_ArrayEnumerator_init  function_System_ArrayEnumerator_init
#define function_ArrayEnumerator_free  function_System_ArrayEnumerator_free
#define base_ArrayEnumerator_init  base_System_ArrayEnumerator_init
#define base_ArrayEnumerator_free  base_System_ArrayEnumerator_free
#define ArrayEnumerator_new  System_ArrayEnumerator_new
#define ArrayEnumerator_init  System_ArrayEnumerator_init
#define ArrayEnumerator_free  System_ArrayEnumerator_free
#endif

#endif
