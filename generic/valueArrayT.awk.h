/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_UInt64
#define Generic_T0Array  System_UInt64Array

#define Generic_T0ArrayType  System_UInt64ArrayType
#endif
/* FileName Generic.T0Array */
/* seeAlso valueArrayEnumeratorT */
/* GENERIC */
#if !defined(have_Generic_T0)
#include "System.Integers.auto.h"
#endif
#if !defined(have_System_IEnumerable)
#include "System.IEnumerable.h"
#endif
#if !defined(have_System_ICollection)
#include "System.ICollection.h"
#endif
#if !defined(have_Generic_T0Array)
#define have_Generic_T0Array

typedef System_fixed struct Generic_T0Array {
    struct System_Object base;

    System_Size  length;

    Generic_T0  (* value)[];

}  * Generic_T0Array;

export struct System_Type  Generic_T0ArrayType;

export Generic_T0Array  new_Generic_T0Array(System_Size length);
export void  base_Generic_T0Array_init(Generic_T0Array that, System_Size length);
export void  base_Generic_T0Array_free(Generic_T0Array that);
export System_Size  base_Generic_T0Array_get_Length(Generic_T0Array that);
export Generic_T0  base_Generic_T0Array_get_index(Generic_T0Array that, System_Size index);
export void  base_Generic_T0Array_set_index(Generic_T0Array that, System_Size index, Generic_T0 value);
export void  base_Generic_T0Array_copyTo(Generic_T0Array that, Generic_T0Array other, System_Size offset);
export void  base_Generic_T0Array_resize(Generic_T0Array that, System_Size length);
export System_IEnumerator  base_Generic_T0Array_getEnumerator(Generic_T0Array that);

#define Generic_T0Array_init(o,...)  ((function_Generic_T0Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic_T0Array_init))(o, __VA_ARGS__)
#define Generic_T0Array_free(o)  ((function_Generic_T0Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define Generic_T0Array_get_Length(o)  ((function_Generic_T0Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define Generic_T0Array_get_index(o,...)  ((function_Generic_T0Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define Generic_T0Array_set_index(o,...)  ((function_Generic_T0Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define Generic_T0Array_copyTo(o,...)  ((function_Generic_T0Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define Generic_T0Array_resize(o,...)  ((function_Generic_T0Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic_T0Array_resize))(o,__VA_ARGS__)
#define Generic_T0Array_getEnumerator(o)  ((function_Generic_T0Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define T0Array  Generic_T0Array
#define T0ArrayType  Generic_T0ArrayType
#define new_T0Array  new_Generic_T0Array

#define T0Array_init  Generic_T0Array_init
#define T0Array_free  Generic_T0Array_free
#define T0Array_get_Length  Generic_T0Array_get_Length
#define T0Array_get_index  Generic_T0Array_get_index
#define T0Array_set_index  Generic_T0Array_set_index
#define T0Array_resize  Generic_T0Array_resize
#define base_T0Array_init  base_Generic_T0Array_init
#define base_T0Array_free  base_Generic_T0Array_free
#define base_T0Array_get_Length  base_Generic_T0Array_get_Length
#define base_T0Array_get_index  base_Generic_T0Array_get_index
#define base_T0Array_set_index  base_Generic_T0Array_set_index
#define base_T0Array_resize  base_Generic_T0Array_resize
#define base_T0Array_getEnumerator  base_Generic_T0Array_getEnumerator
#define function_T0Array_init  function_Generic_T0Array_init
#define function_T0Array_free  function_Generic_T0Array_free
#define function_T0Array_get_Length  function_Generic_T0Array_get_Length
#define function_T0Array_get_index  function_Generic_T0Array_get_index
#define function_T0Array_set_index  function_Generic_T0Array_set_index
#define function_T0Array_resize  function_Generic_T0Array_resize
#define function_T0Array_getEnumerator  function_Generic_T0Array_getEnumerator
#endif
#endif
