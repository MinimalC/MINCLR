/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IEnumerable)
#include "System.IEnumerable.h"
#endif
#if !defined(have_System_ICollection)
#include "System.ICollection.h"
#endif
#if !defined(have_System_varArray)
#define have_System_varArray

#define struct_System_varArray struct System_varArray
typedef fixed struct_System_varArray {
    struct_System_Object base;

    System_size  length;

    System_var  (* value)[];

}  * System_varArray;

export struct_System_Type  System_varArrayType;

typedef void delegate(System_varArray_free)(System_varArray that);
typedef System_varArray delegate(System_varArray_init)(System_varArray that);
typedef System_size  delegate(System_varArray_get_Length)(System_varArray that);
typedef System_var  delegate(System_varArray_get_index)(System_varArray that, System_size index);
typedef void  delegate(System_varArray_set_index)(System_varArray that, System_size index, System_var value);
typedef void delegate(System_varArray_copyTo)(System_varArray that, System_varArray other, System_size offset);
typedef void delegate(System_varArray_resize)(System_varArray that, System_size length);
typedef System_IEnumerator  delegate(System_varArray_getEnumerator)(System_varArray that);

export System_varArray  base_System_varArray_init(System_varArray that, System_size length);
export void  base_System_varArray_free(System_varArray that);
export System_size  base_System_varArray_get_Length(System_varArray that);
export System_var  base_System_varArray_get_index(System_varArray that, System_size index);
export void  base_System_varArray_set_index(System_varArray that, System_size index, System_var value);
export void  base_System_varArray_copyTo(System_varArray that, System_varArray other, System_size offset);
export void  base_System_varArray_resize(System_varArray that, System_size length);
export System_IEnumerator  base_System_varArray_getEnumerator(System_varArray that);

#define System_varArray_init(o,...)  ((function_System_varArray_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_varArray_init))(o, __VA_ARGS__)
#define System_varArray_free(o)  ((function_System_varArray_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_varArray_get_Length(o)  ((function_System_varArray_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_varArray_get_index(o,...)  ((function_System_varArray_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_varArray_set_index(o,...)  ((function_System_varArray_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_varArray_copyTo(o,...)  ((function_System_varArray_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_varArray_resize(o,...)  ((function_System_varArray_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_varArray_resize))(o,__VA_ARGS__)
#define System_varArray_getEnumerator(o)  ((function_System_varArray_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define new_System_varArray(LENGTH)  (base_System_varArray_init((System_varArray)System_Memory_allocClass(typeof(System_varArray)), LENGTH))

#if defined(using_System)
#define varArray  System_varArray
#define varArrayType  System_varArrayType

#define new_varArray  new_System_varArray

#define varArray_init  System_varArray_init
#define varArray_free  System_varArray_free
#define varArray_get_Length  System_varArray_get_Length
#define varArray_get_index  System_varArray_get_index
#define varArray_set_index  System_varArray_set_index
#define varArray_resize  System_varArray_resize
#define base_varArray_init  base_System_varArray_init
#define base_varArray_free  base_System_varArray_free
#define base_varArray_get_Length  base_System_varArray_get_Length
#define base_varArray_get_index  base_System_varArray_get_index
#define base_varArray_set_index  base_System_varArray_set_index
#define base_varArray_resize  base_System_varArray_resize
#define base_varArray_getEnumerator  base_System_varArray_getEnumerator
#define function_varArray_init  function_System_varArray_init
#define function_varArray_free  function_System_varArray_free
#define function_varArray_get_Length  function_System_varArray_get_Length
#define function_varArray_get_index  function_System_varArray_get_index
#define function_varArray_set_index  function_System_varArray_set_index
#define function_varArray_resize  function_System_varArray_resize
#define function_varArray_getEnumerator  function_System_varArray_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_varArrayEnumerator)
#define have_System_varArrayEnumerator

#define struct_System_varArrayEnumerator struct System_varArrayEnumerator
typedef fixed struct_System_varArrayEnumerator {
    struct_System_Object base;

    System_varArray array;

    System_size index;

}  * System_varArrayEnumerator;

export struct_System_Type  System_varArrayEnumeratorType;

typedef void delegate(System_varArrayEnumerator_free)(System_varArrayEnumerator that);
typedef System_varArrayEnumerator delegate(System_varArrayEnumerator_init)(System_varArrayEnumerator that, System_varArray array);
typedef System_var delegate(System_varArrayEnumerator_get_current)(System_varArrayEnumerator that);
typedef System_boolean delegate(System_varArrayEnumerator_moveNext)(System_varArrayEnumerator that);

export System_varArrayEnumerator  base_System_varArrayEnumerator_init(System_varArrayEnumerator that, System_varArray array);
export void  base_System_varArrayEnumerator_free(System_varArrayEnumerator that);
export System_var  base_System_varArrayEnumerator_get_current(System_varArrayEnumerator that);
export System_boolean  base_System_varArrayEnumerator_moveNext(System_varArrayEnumerator that);

#define System_varArrayEnumerator_init(o,...)  ((function_System_varArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_varArrayEnumerator_init))(o,__VA_ARGS__)
#define System_varArrayEnumerator_free(o)  ((function_System_varArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_varArrayEnumerator_get_current(o)  ((function_System_varArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_varArrayEnumerator_moveNext(o)  ((function_System_varArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define new_System_varArrayEnumerator(a)  (base_System_varArrayEnumerator_init((System_varArrayEnumerator)System_Memory_allocClass(typeof(System_varArrayEnumerator)), a))

#if defined(using_System)
#define varArrayEnumerator  System_varArrayEnumerator
#define varArrayEnumeratorType  System_varArrayEnumeratorType
#define function_varArrayEnumerator_init  function_System_varArrayEnumerator_init
#define function_varArrayEnumerator_free  function_System_varArrayEnumerator_free
#define base_varArrayEnumerator_init  base_System_varArrayEnumerator_init
#define base_varArrayEnumerator_free  base_System_varArrayEnumerator_free
#define varArrayEnumerator_init  System_varArrayEnumerator_init
#define varArrayEnumerator_free  System_varArrayEnumerator_free
#define new_varArrayEnumerator  new_System_varArrayEnumerator
#endif
#endif
