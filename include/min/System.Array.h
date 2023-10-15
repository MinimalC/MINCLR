/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IEnumerable)
#include "System.IEnumerable.h"
#endif
#if !defined(have_System_ICollection)
#include "System.ICollection.h"
#endif
#if !defined(have_System_Array)
#define have_System_Array

/* 1-Dimensional, Indexed System_ObjectArray */

enum {
    System_Array_DefaultCapacity =  64,
};

typedef System_fixed struct System_Array {
    struct System_Object base;

    System_Size  length;

    System_Size capacity;

    System_Object  (* value)[];

}  * System_Array;

export struct System_Type  System_ArrayType;

typedef void  delegate(System_Array_init)(System_Array that, System_Size capacity);
typedef System_Size  delegate(System_Array_get_Length)(System_Array that);
typedef System_Object  delegate(System_Array_get_index)(System_Array that, System_Size index);
typedef void  delegate(System_Array_set_index)(System_Array that, System_Size index, System_Object value);
typedef void  delegate(System_Array_copyTo)(System_Array that, System_Array other, System_Size offset);
typedef void  delegate(System_Array_resize)(System_Array that, System_Size capacity);
typedef System_IEnumerator  delegate(System_Array_getEnumerator)(System_Array that);

export System_Array  new_System_Array(System_Size capacity);
export void  base_System_Array_init(System_Array that, System_Size capacity);
export void  base_System_Array_free(System_Array that);
export System_Size  base_System_Array_get_Length(System_Array that);
export System_Object  base_System_Array_get_index(System_Array that, System_Size index);
export void  base_System_Array_set_index(System_Array that, System_Size index, System_Object value);
export void  base_System_Array_copyTo(System_Array that, System_Array other, System_Size offset);
export void  base_System_Array_resize(System_Array that, System_Size capacity);
export System_IEnumerator  base_System_Array_getEnumerator(System_Array that);

#define System_Array_init(o,...)  ((function_System_Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_init))(o, __VA_ARGS__)
#define System_Array_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Array_get_Length(o)  ((function_System_Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_Array_get_index(o,...)  ((function_System_Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_Array_set_index(o,...)  ((function_System_Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_Array_copyTo(o,...)  ((function_System_Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_Array_resize(o,...)  ((function_System_Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_resize))(o,__VA_ARGS__)
#define System_Array_getEnumerator(o)  ((function_System_Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define Array  System_Array
#define ArrayType  System_ArrayType

#define Array_init  System_Array_init
#define Array_free  System_Array_free
#define Array_get_Length  System_Array_get_Length
#define Array_get_index  System_Array_get_index
#define Array_set_index  System_Array_set_index
#define Array_resize  System_Array_resize
#define Array_getEnumerator  System_Array_getEnumerator
#endif
#endif
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_ArrayEnumerator)
#define have_System_ArrayEnumerator

typedef System_fixed struct System_ArrayEnumerator {
    struct System_Object base;

    System_Array array;

    System_Size index;

}  * System_ArrayEnumerator;

export struct System_Type  System_ArrayEnumeratorType;

typedef void delegate(System_ArrayEnumerator_free)(System_ArrayEnumerator that);
typedef void delegate(System_ArrayEnumerator_init)(System_ArrayEnumerator that, System_Array array);
typedef System_Object delegate(System_ArrayEnumerator_get_current)(System_ArrayEnumerator that);
typedef System_Bool delegate(System_ArrayEnumerator_moveNext)(System_ArrayEnumerator that);

export System_ArrayEnumerator  new_System_ArrayEnumerator(System_Array array);
export void  base_System_ArrayEnumerator_init(System_ArrayEnumerator that, System_Array array);
export void  base_System_ArrayEnumerator_free(System_ArrayEnumerator that);
export System_Object  base_System_ArrayEnumerator_get_current(System_ArrayEnumerator that);
export System_Bool  base_System_ArrayEnumerator_moveNext(System_ArrayEnumerator that);

#define System_ArrayEnumerator_init(o,...)  ((function_System_ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_ArrayEnumerator_free(o)  ((function_System_ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_ArrayEnumerator_get_current(o)  ((function_System_ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_ArrayEnumerator_moveNext(o)  ((function_System_ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define ArrayEnumerator  System_ArrayEnumerator
#define ArrayEnumeratorType  System_ArrayEnumeratorType

#define function_ArrayEnumerator_init  function_System_ArrayEnumerator_init
#define function_ArrayEnumerator_free  function_System_ArrayEnumerator_free
#define base_ArrayEnumerator_init  base_System_ArrayEnumerator_init
#define base_ArrayEnumerator_free  base_System_ArrayEnumerator_free
#define ArrayEnumerator_init  System_ArrayEnumerator_init
#define ArrayEnumerator_free  System_ArrayEnumerator_free
#endif
#endif
