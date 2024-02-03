/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_String8)
#include "System.String8.h"
#endif
#if !defined(have_System_IEnumerable)
#include "System.IEnumerable.h"
#endif
#if !defined(have_System_ICollection)
#include "System.ICollection.h"
#endif
#if !defined(have_System_String8Array)
#define have_System_String8Array

typedef System_fixed struct System_String8Array {
    struct System_Object base;

    System_Size  length;

    System_Size  capacity;
    
    System_String8  (* value)[];

}  * System_String8Array;

export struct System_Type  System_String8ArrayType;

typedef void delegate(System_String8Array_init)(System_String8Array that, System_Size capacity);
typedef System_Size  delegate(System_String8Array_get_Length)(System_String8Array that);
typedef System_String8  delegate(System_String8Array_get_index)(System_String8Array that, System_Size index);
typedef void  delegate(System_String8Array_set_index)(System_String8Array that, System_Size index, System_String8 value);
typedef void delegate(System_String8Array_copyTo)(System_String8Array that, System_String8Array other, System_Size offset);
typedef void delegate(System_String8Array_resize)(System_String8Array that, System_Size capacity);
typedef System_IEnumerator  delegate(System_String8Array_getEnumerator)(System_String8Array that);

export System_String8Array  new_System_String8Array(System_Size capacity);
export void  base_System_String8Array_init(System_String8Array that, System_Size capacity);
export void  base_System_String8Array_free(System_String8Array that);
export System_Size  base_System_String8Array_get_Length(System_String8Array that);
export System_String8  base_System_String8Array_get_index(System_String8Array that, System_Size index);
export void  base_System_String8Array_set_index(System_String8Array that, System_Size index, System_String8 value);
export void  base_System_String8Array_add(System_String8Array that, System_String8 item);
export void  base_System_String8Array_remove(System_String8Array that, System_Size index);
export void  base_System_String8Array_copyTo(System_String8Array that, System_String8Array other, System_Size offset);
export void  base_System_String8Array_resize(System_String8Array that, System_Size capacity);
export System_IEnumerator  base_System_String8Array_getEnumerator(System_String8Array that);

export System_String8Array  System_String8_split(System_String8 that, System_Char8 separator);
export System_String8  System_Char8_join(System_Char8 that, System_String8Array array);

#define System_String8Array_init(o,...)  ((function_System_String8Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String8Array_init))(o, __VA_ARGS__)
#define System_String8Array_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String8Array_get_Length(o)  ((function_System_String8Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_String8Array_get_index(o,...)  ((function_System_String8Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_String8Array_set_index(o,...)  ((function_System_String8Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_String8Array_copyTo(o,...)  ((function_System_String8Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_String8Array_resize(o,...)  ((function_System_String8Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String8Array_resize))(o,__VA_ARGS__)
#define System_String8Array_getEnumerator(o)  ((function_System_String8Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define String8Array  System_String8Array
#define String8ArrayType  System_String8ArrayType

#define String8Array_init  System_String8Array_init
#define String8Array_free  System_String8Array_free
#define String8Array_get_Length  System_String8Array_get_Length
#define String8Array_get_index  System_String8Array_get_index
#define String8Array_set_index  System_String8Array_set_index
#define String8Array_resize  System_String8Array_resize
#define base_String8Array_init  base_System_String8Array_init
#define base_String8Array_free  base_System_String8Array_free
#define base_String8Array_get_Length  base_System_String8Array_get_Length
#define base_String8Array_get_index  base_System_String8Array_get_index
#define base_String8Array_set_index  base_System_String8Array_set_index
#define base_String8Array_resize  base_System_String8Array_resize
#define base_String8Array_getEnumerator  base_System_String8Array_getEnumerator
#define function_String8Array_init  function_System_String8Array_init
#define function_String8Array_free  function_System_String8Array_free
#define function_String8Array_get_Length  function_System_String8Array_get_Length
#define function_String8Array_get_index  function_System_String8Array_get_index
#define function_String8Array_set_index  function_System_String8Array_set_index
#define function_String8Array_resize  function_System_String8Array_resize
#define function_String8Array_getEnumerator  function_System_String8Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_String8ArrayEnumerator)
#define have_System_String8ArrayEnumerator


typedef System_fixed struct System_String8ArrayEnumerator {
    struct System_Object base;

    System_String8Array array;

    System_Size index;

}  * System_String8ArrayEnumerator;

export struct System_Type  System_String8ArrayEnumeratorType;

typedef void delegate(System_String8ArrayEnumerator_init)(System_String8ArrayEnumerator that, System_String8Array array);
typedef System_String8 delegate(System_String8ArrayEnumerator_get_current)(System_String8ArrayEnumerator that);
typedef System_Bool delegate(System_String8ArrayEnumerator_moveNext)(System_String8ArrayEnumerator that);

export System_String8ArrayEnumerator  new_System_String8ArrayEnumerator(System_String8Array array);
export void  base_System_String8ArrayEnumerator_init(System_String8ArrayEnumerator that, System_String8Array array);
export void  base_System_String8ArrayEnumerator_free(System_String8ArrayEnumerator that);
export System_String8  base_System_String8ArrayEnumerator_get_current(System_String8ArrayEnumerator that);
export System_Bool  base_System_String8ArrayEnumerator_moveNext(System_String8ArrayEnumerator that);

#define System_String8ArrayEnumerator_init(o,...)  ((function_System_String8ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String8ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_String8ArrayEnumerator_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String8ArrayEnumerator_get_current(o)  ((function_System_String8ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_String8ArrayEnumerator_moveNext(o)  ((function_System_String8ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define String8ArrayEnumerator  System_String8ArrayEnumerator
#define String8ArrayEnumeratorType  System_String8ArrayEnumeratorType
#define function_String8ArrayEnumerator_init  function_System_String8ArrayEnumerator_init
#define function_String8ArrayEnumerator_free  function_System_String8ArrayEnumerator_free
#define base_String8ArrayEnumerator_init  base_System_String8ArrayEnumerator_init
#define base_String8ArrayEnumerator_free  base_System_String8ArrayEnumerator_free
#define String8ArrayEnumerator_init  System_String8ArrayEnumerator_init
#define String8ArrayEnumerator_free  System_String8ArrayEnumerator_free
#define new_String8ArrayEnumerator  new_System_String8ArrayEnumerator
#endif
#endif
