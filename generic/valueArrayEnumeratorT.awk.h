/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_uint64
#define Generic_T0Array  System_uint64Array
#define Generic_T0ArrayEnumerator  System_uint64ArrayEnumerator
#define struct_Generic_T0ArrayEnumerator  struct_System_uint64ArrayEnumerator
#define Generic_T0ArrayEnumeratorType  System_uint64ArrayEnumeratorType
#endif
/* FileName Generic.T0ArrayEnumerator */
/* GENERIC */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_Generic_T0)
#warning "Generic.T.h not included"
#include "Generic.T.h"
#endif */
#if !defined(have_auto_Generic_T0ArrayEnumerator)
#define have_auto_Generic_T0ArrayEnumerator

#define struct_Generic_T0ArrayEnumerator  struct class_Generic_T0ArrayEnumerator
typedef fixed struct_Generic_T0ArrayEnumerator {
    struct_System_Object base;

    Generic_T0Array array;

    System_size index;

}  * Generic_T0ArrayEnumerator;

#define stack_Generic_T0ArrayEnumerator()  (struct_Generic_T0ArrayEnumerator){ .base = stack_System_Object(Generic_T0ArrayEnumerator), .array = null, }

export struct_System_Type  Generic_T0ArrayEnumeratorType;

typedef void delegate(Generic_T0ArrayEnumerator_free)(Generic_T0ArrayEnumerator that);
typedef Generic_T0ArrayEnumerator delegate(Generic_T0ArrayEnumerator_init)(Generic_T0ArrayEnumerator that, Generic_T0Array array);
typedef Generic_T0 delegate(Generic_T0ArrayEnumerator_get_current)(Generic_T0ArrayEnumerator that);
typedef System_boolean delegate(Generic_T0ArrayEnumerator_moveNext)(Generic_T0ArrayEnumerator that);

#define Generic_T0ArrayEnumerator_new  Generic_T0ArrayEnumerator_new__00

export Generic_T0ArrayEnumerator  Generic_T0ArrayEnumerator_new(Generic_T0Array array);
export Generic_T0ArrayEnumerator  base_Generic_T0ArrayEnumerator_init(Generic_T0ArrayEnumerator that, Generic_T0Array array);
export void  base_Generic_T0ArrayEnumerator_free(Generic_T0ArrayEnumerator that);
export Generic_T0  base_Generic_T0ArrayEnumerator_get_current(Generic_T0ArrayEnumerator that);
export System_boolean  base_Generic_T0ArrayEnumerator_moveNext(Generic_T0ArrayEnumerator that);

#define Generic_T0ArrayEnumerator_init(o,...)  ((function_Generic_T0ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic_T0ArrayEnumerator_init))(o,__VA_ARGS__)
#define Generic_T0ArrayEnumerator_free(o)  ((function_Generic_T0ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define Generic_T0ArrayEnumerator_get_current(o)  ((function_Generic_T0ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define Generic_T0ArrayEnumerator_moveNext(o)  ((function_Generic_T0ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_Generic_T0ArrayEnumerator_new(a)  (base_Generic_T0ArrayEnumerator_init(inline_System_Object_allocClass(Generic_T0ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  Generic_T0ArrayEnumerator_new
#define Generic_T0ArrayEnumerator_new  inline_Generic_T0ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_T0ArrayEnumerator  struct_Generic_T0ArrayEnumerator
#define T0ArrayEnumerator  Generic_T0ArrayEnumerator
#define T0ArrayEnumeratorType  Generic_T0ArrayEnumeratorType
#define function_T0ArrayEnumerator_init  function_Generic_T0ArrayEnumerator_init
#define function_T0ArrayEnumerator_free  function_Generic_T0ArrayEnumerator_free
#define base_T0ArrayEnumerator_init  base_Generic_T0ArrayEnumerator_init
#define base_T0ArrayEnumerator_free  base_Generic_T0ArrayEnumerator_free
#define T0ArrayEnumerator_new  Generic_T0ArrayEnumerator_new
#define T0ArrayEnumerator_init  Generic_T0ArrayEnumerator_init
#define T0ArrayEnumerator_free  Generic_T0ArrayEnumerator_free
#endif


#endif
