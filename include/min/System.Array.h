/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Array)
#define have_System_Array

/* 1-Dimensional, Indexed System_ObjectArray */

typedef fixed struct System_Array {
    struct System_Object base;

    System_Size  length;

    System_Object  (* value)[];

}  * System_Array;

#define stack_System_Array(LENGTH) (struct System_Array){ .base = stack_System_Object(System_Array), .length = LENGTH, }
#define new_System_Array(LENGTH)  (base_System_Array_init((System_Array)System_Memory_allocClass(typeof(System_Array)), LENGTH))

export struct System_Type  System_ArrayType;

typedef void  delegate(System_Array_free)(System_Array that);
typedef System_Array  delegate(System_Array_init)(System_Array that, System_Size length);
typedef System_Size  delegate(System_Array_get_Length)(System_Array that);
typedef System_Object  delegate(System_Array_get_index)(System_Array that, System_Size index);
typedef void  delegate(System_Array_set_index)(System_Array that, System_Size index, System_Object value);
typedef void  delegate(System_Array_copyTo)(System_Array that, System_Array other, System_Size offset);
typedef void  delegate(System_Array_resize)(System_Array that, System_Size length);
typedef System_IEnumerator  delegate(System_Array_getEnumerator)(System_Array that);

export System_Array  base_System_Array_init(System_Array that, System_Size length);
export void  base_System_Array_free(System_Array that);
export System_Size  base_System_Array_get_Length(System_Array that);
export System_Object  base_System_Array_get_index(System_Array that, System_Size index);
export void  base_System_Array_set_index(System_Array that, System_Size index, System_Object value);
export void  base_System_Array_copyTo(System_Array that, System_Array other, System_Size offset);
export void  base_System_Array_resize(System_Array that, System_Size length);
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
#define stack_Array  stack_System_Array
#define new_Array  new_System_Array
#define Array_init  System_Array_init
#define Array_free  System_Array_free
#define Array_get_Length  System_Array_get_Length
#define Array_get_index  System_Array_get_index
#define Array_set_index  System_Array_set_index
#define Array_resize  System_Array_resize
#define Array_getEnumerator  System_Array_getEnumerator
#endif
#endif
