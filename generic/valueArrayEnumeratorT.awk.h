/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_UInt64
#define Generic_T0Array  System_UInt64Array
#define Generic_T0ArrayEnumerator  System_UInt64ArrayEnumerator
#define Generic_T0ArrayEnumeratorType  System_UInt64ArrayEnumeratorType
#endif
/* FileName Generic.T0ArrayEnumerator */
/* GENERIC */
#if !defined(have_Generic_T0Array)
#include "Generic.T0Array.h"
#endif
#if !defined(have_Generic_T0ArrayEnumerator)
#define have_Generic_T0ArrayEnumerator

typedef System_fixed struct Generic_T0ArrayEnumerator {
    struct System_Object base;

    Generic_T0Array array;

    System_Size index;

}  * Generic_T0ArrayEnumerator;

#define stack_Generic_T0ArrayEnumerator(ARRAY)  { .base = stack_System_Object(Generic_T0ArrayEnumerator), .array = ARRAY, }
#define new_Generic_T0ArrayEnumerator(ARRAY)  (base_Generic_T0ArrayEnumerator_init((Generic_T0ArrayEnumerator)System_Memory_allocClass(typeof(Generic_T0ArrayEnumerator)), ARRAY))

export struct System_Type  Generic_T0ArrayEnumeratorType;

typedef void delegate(Generic_T0ArrayEnumerator_free)(Generic_T0ArrayEnumerator that);
typedef Generic_T0ArrayEnumerator delegate(Generic_T0ArrayEnumerator_init)(Generic_T0ArrayEnumerator that, Generic_T0Array array);
typedef Generic_T0 delegate(Generic_T0ArrayEnumerator_get_current)(Generic_T0ArrayEnumerator that);
typedef System_Bool delegate(Generic_T0ArrayEnumerator_moveNext)(Generic_T0ArrayEnumerator that);

export Generic_T0ArrayEnumerator  base_Generic_T0ArrayEnumerator_init(Generic_T0ArrayEnumerator that, Generic_T0Array array);
export void  base_Generic_T0ArrayEnumerator_free(Generic_T0ArrayEnumerator that);
export Generic_T0  base_Generic_T0ArrayEnumerator_get_current(Generic_T0ArrayEnumerator that);
export System_Bool  base_Generic_T0ArrayEnumerator_moveNext(Generic_T0ArrayEnumerator that);

#define Generic_T0ArrayEnumerator_init(o,...)  ((function_Generic_T0ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic_T0ArrayEnumerator_init))(o,__VA_ARGS__)
#define Generic_T0ArrayEnumerator_free(o)  ((function_Generic_T0ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define Generic_T0ArrayEnumerator_get_current(o)  ((function_Generic_T0ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define Generic_T0ArrayEnumerator_moveNext(o)  ((function_Generic_T0ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define T0ArrayEnumerator  Generic_T0ArrayEnumerator
#define T0ArrayEnumeratorType  Generic_T0ArrayEnumeratorType
#define stack_T0ArrayEnumerator  stack_Generic_T0ArrayEnumerator
#define new_T0ArrayEnumerator  new_Generic_T0ArrayEnumerator
#define function_T0ArrayEnumerator_init  function_Generic_T0ArrayEnumerator_init
#define function_T0ArrayEnumerator_free  function_Generic_T0ArrayEnumerator_free
#define base_T0ArrayEnumerator_init  base_Generic_T0ArrayEnumerator_init
#define base_T0ArrayEnumerator_free  base_Generic_T0ArrayEnumerator_free
#define T0ArrayEnumerator_init  Generic_T0ArrayEnumerator_init
#define T0ArrayEnumerator_free  Generic_T0ArrayEnumerator_free
#endif
#endif
