/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
/* #if !defined(have_System_Object)
#warning "System.Object.h not included"
#include "System.Object.h"
#endif */
#if !defined(have_System_Array)
#define have_System_Array

/* 1-Dimensional, Indexed System_ObjectArray */

#define struct_System_Array  struct class_System_Array
typedef __fixed struct_System_Array {
    struct_System_Object base;

    System_size  length;
    System_Object  (* value)[];

}  * System_Array;

#define stack_System_Array(__length,...) (struct_System_Array){ .base = stack_System_Object(System_Array),\
    .length = __length, .value = &(System_Object []){ __VA_ARGS__ }, }

__export struct_System_Type  System_ArrayType;

typedef System_void  __delegate(System_Array_free)(System_Array that);
typedef System_Array  __delegate(System_Array_init)(System_Array that, System_size length);
typedef System_size  __delegate(System_Array_get_Length)(System_Array that);
typedef System_Object  __delegate(System_Array_get_index)(System_Array that, System_size index);
typedef System_void  __delegate(System_Array_set_index)(System_Array that, System_size index, System_Object value);
typedef System_void  __delegate(System_Array_copyTo)(System_Array that, System_Array other, System_size offset);
typedef System_void  __delegate(System_Array_resize)(System_Array that, System_size length);
typedef System_IEnumerator  __delegate(System_Array_getEnumerator)(System_Array that);

__export System_Array  System_Array_new(System_size length);
__export System_Array  base_System_Array_init(System_Array that, System_size length);
__export System_void  base_System_Array_free(System_Array that);
__export System_size  base_System_Array_get_Length(System_Array that);
__export System_Object  base_System_Array_get_index(System_Array that, System_size index);
__export System_void  base_System_Array_set_index(System_Array that, System_size index, System_Object value);
__export System_void  base_System_Array_copyTo(System_Array that, System_Array other, System_size offset);
__export System_void  base_System_Array_resize(System_Array that, System_size length);
__export System_IEnumerator  base_System_Array_getEnumerator(System_Array that);

#define System_Array_init(o,...)  ((function_System_Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_init))(o, __VA_ARGS__)
#define System_Array_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Array_get_Length(o)  ((function_System_Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_Array_get_index(o,...)  ((function_System_Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_Array_set_index(o,...)  ((function_System_Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_Array_copyTo(o,...)  ((function_System_Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_Array_resize(o,...)  ((function_System_Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_resize))(o,__VA_ARGS__)
#define System_Array_getEnumerator(o)  ((function_System_Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_Array_new(__length)  (base_System_Array_init(inline_System_Object_allocClass(System_Array), __length))

#if defined(using_System)
#define struct_Array  struct class_System_Array
#define stack_Array  stack_System_Array
#define __Array  System_Array
#define __ArrayType  System_ArrayType

#define __Array_new  System_Array_new
#define __Array_init  System_Array_init
#define __Array_free  System_Array_free
#define __Array_get_Length  System_Array_get_Length
#define __Array_get_index  System_Array_get_index
#define __Array_set_index  System_Array_set_index
#define __Array_resize  System_Array_resize
#define __Array_getEnumerator  System_Array_getEnumerator
#endif

#endif
