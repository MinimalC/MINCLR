/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_uint64
#define Generic_T0Array  System_uint64Array
#define struct_Generic_T0Array  struct_System_uint64Array
#define Generic_T0ArrayType  System_uint64ArrayType
#endif
/* FileName Generic.T0Array */
/* seeAlso valueArrayEnumeratorT */
/* GENERIC */
#if !defined(have_Generic_T0)
#include "Generic.T0.h"
#endif
#if !defined(have_Generic_T0Array)
#define have_Generic_T0Array

#define struct_Generic_T0Array  struct Generic_T0Array
typedef fixed struct_Generic_T0Array {
    struct_System_Object base;

    System_size  length;

    Generic_T0  (* value)[];

}  * Generic_T0Array;

export struct_System_Type  Generic_T0ArrayType;

typedef void delegate(Generic_T0Array_free)(Generic_T0Array that);
typedef Generic_T0Array delegate(Generic_T0Array_init)(Generic_T0Array that, System_size length);
typedef System_size  delegate(Generic_T0Array_get_Length)(Generic_T0Array that);
typedef Generic_T0  delegate(Generic_T0Array_get_index)(Generic_T0Array that, System_size index);
typedef void  delegate(Generic_T0Array_set_index)(Generic_T0Array that, System_size index, Generic_T0 value);
typedef void delegate(Generic_T0Array_copyTo)(Generic_T0Array that, Generic_T0Array other, System_size offset);
typedef void delegate(Generic_T0Array_resize)(Generic_T0Array that, System_size length);
typedef System_IEnumerator  delegate(Generic_T0Array_getEnumerator)(Generic_T0Array that);

export Generic_T0Array  base_Generic_T0Array_init(Generic_T0Array that, System_size length);
export void  base_Generic_T0Array_free(Generic_T0Array that);
export System_size  base_Generic_T0Array_get_Length(Generic_T0Array that);
export Generic_T0  base_Generic_T0Array_get_index(Generic_T0Array that, System_size index);
export void  base_Generic_T0Array_set_index(Generic_T0Array that, System_size index, Generic_T0 value);
export void  base_Generic_T0Array_copyTo(Generic_T0Array that, Generic_T0Array other, System_size offset);
export void  base_Generic_T0Array_resize(Generic_T0Array that, System_size length);
export System_IEnumerator  base_Generic_T0Array_getEnumerator(Generic_T0Array that);

#define Generic_T0Array_init(o,...)  ((function_Generic_T0Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic_T0Array_init))(o, __VA_ARGS__)
#define Generic_T0Array_free(o)  ((function_Generic_T0Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define Generic_T0Array_get_Length(o)  ((function_Generic_T0Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define Generic_T0Array_get_index(o,...)  ((function_Generic_T0Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define Generic_T0Array_set_index(o,...)  ((function_Generic_T0Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define Generic_T0Array_copyTo(o,...)  ((function_Generic_T0Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define Generic_T0Array_resize(o,...)  ((function_Generic_T0Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_Generic_T0Array_resize))(o,__VA_ARGS__)
#define Generic_T0Array_getEnumerator(o)  ((function_Generic_T0Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define new_Generic_T0Array(LENGTH)  (base_Generic_T0Array_init(inline_System_Object_allocClass(Generic_T0Array), LENGTH))

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
