/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_Object)
#warning "System.Object.h not included"
#include "System.Object.h"
#endif */
#if !defined(have_System_varArray)
#define have_System_varArray

/* 1-Dimensional, Indexed System_varArray */

#define struct_System_varArray  struct class_System_varArray
typedef __fixed struct_System_varArray {
    struct_System_Object base;

    System_size  length;
    System_var  (* value)[];

}  * System_varArray;

#define stack_System_varArray(__length,...) (struct_System_varArray){ .base = stack_System_Object(System_varArray),\
    .length = __length, .value = &(System_Object []){ __VA_ARGS__ }, }

__export struct_System_Type  System_varArrayType;

typedef System_void  __delegate(System_varArray_free)(System_varArray that);
typedef System_varArray  __delegate(System_varArray_init)(System_varArray that, System_size length);
typedef System_size  __delegate(System_varArray_get_Length)(System_varArray that);
typedef System_Object  __delegate(System_varArray_get_index)(System_varArray that, System_size index);
typedef System_void  __delegate(System_varArray_set_index)(System_varArray that, System_size index, System_Object value);
typedef System_void  __delegate(System_varArray_copyTo)(System_varArray that, System_varArray other, System_size offset);
typedef System_void  __delegate(System_varArray_resize)(System_varArray that, System_size length);
typedef System_IEnumerator  __delegate(System_varArray_getEnumerator)(System_varArray that);

__export System_varArray  System_varArray_new(System_size length);
__export System_varArray  base_System_varArray_init(System_varArray that, System_size length);
__export System_void  base_System_varArray_free(System_varArray that);
__export System_size  base_System_varArray_get_Length(System_varArray that);
__export System_Object  base_System_varArray_get_index(System_varArray that, System_size index);
__export System_void  base_System_varArray_set_index(System_varArray that, System_size index, System_Object value);
__export System_void  base_System_varArray_copyTo(System_varArray that, System_varArray other, System_size offset);
__export System_void  base_System_varArray_resize(System_varArray that, System_size length);
__export System_IEnumerator  base_System_varArray_getEnumerator(System_varArray that);

#define System_varArray_init(o,...)  ((function_System_varArray_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_varArray_init))(o, __VA_ARGS__)
#define System_varArray_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_varArray_get_Length(o)  ((function_System_varArray_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_varArray_get_index(o,...)  ((function_System_varArray_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_varArray_set_index(o,...)  ((function_System_varArray_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_varArray_copyTo(o,...)  ((function_System_varArray_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_varArray_resize(o,...)  ((function_System_varArray_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_varArray_resize))(o,__VA_ARGS__)
#define System_varArray_getEnumerator(o)  ((function_System_varArray_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_varArray_new(__length)  (base_System_varArray_init(inline_System_Object_allocClass(System_varArray), __length))

#if defined(using_System)
#define struct_varArray  struct class_System_varArray
#define stack_varArray  stack_System_varArray
#define __varArray  System_varArray
#define __varArrayType  System_varArrayType

#define __varArray_new  System_varArray_new
#define __varArray_init  System_varArray_init
#define __varArray_free  System_varArray_free
#define __varArray_get_Length  System_varArray_get_Length
#define __varArray_get_index  System_varArray_get_index
#define __varArray_set_index  System_varArray_set_index
#define __varArray_resize  System_varArray_resize
#define __varArray_getEnumerator  System_varArray_getEnumerator
#endif

#endif
