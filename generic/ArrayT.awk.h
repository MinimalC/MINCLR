/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array
#define class_Generic_T0Array  class_System_Array
#define Generic_T0ArrayType  System_ArrayType
#endif
/* FileName Generic.T0Array */
/* GENERIC */
#if !defined(have_System)
#warning "System.h not included"
#include "System.h"
#endif
#if !defined(have_Generic_T0)
#warning "Generic.T0.h not included"
#include "Generic.T0.h"
#endif
#if !defined(have_auto_Generic_T0Array)
#define have_auto_Generic_T0Array

#define struct_Generic_T0Array  struct class_Generic_T0Array
typedef fixed struct_Generic_T0Array {
    struct_System_Array base;

}  * Generic_T0Array;

#define stack_Generic_T0Array(LENGTH,...) { .base = { .base = stack_System_Object(Generic_T0Array), .length = LENGTH, .value = &(Generic_T0 []){ __VA_ARGS__ } } }

export struct_System_Type  Generic_T0ArrayType;

typedef void delegate(Generic_T0Array_free)(Generic_T0Array that);
typedef void delegate(Generic_T0Array_init)(Generic_T0Array that);
typedef System_size  delegate(Generic_T0Array_get_Length)(Generic_T0Array that);
typedef Generic_T0  delegate(Generic_T0Array_get_index)(Generic_T0Array that, System_size index);
typedef void  delegate(Generic_T0Array_set_index)(Generic_T0Array that, System_size index, Generic_T0 value);
typedef void delegate(Generic_T0Array_copyTo)(Generic_T0Array that, Generic_T0Array other, System_size offset);
typedef void delegate(Generic_T0Array_resize)(Generic_T0Array that, System_size length);

export Generic_T0Array  Generic_T0Array_new(System_size length);

#define Generic_T0Array_init(o,...)  ((function_Generic_T0Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_init))(o, __VA_ARGS__)
#define Generic_T0Array_free(o)  ((function_Generic_T0Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define Generic_T0Array_get_Length(o)  ((function_Generic_T0Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define Generic_T0Array_get_index(o,...)  ((function_Generic_T0Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define Generic_T0Array_set_index(o,...)  ((function_Generic_T0Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define Generic_T0Array_copyTo(o,...)  ((function_Generic_T0Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define Generic_T0Array_resize(o,...)  ((function_Generic_T0Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Generic_T0Array_resize))(o,__VA_ARGS__)

#define inline_Generic_T0Array_new(LENGTH)  (base_Generic_T0Array_init(inline_System_Object_allocClass(Generic_T0Array), LENGTH))

#if defined(using_Generic)
#define struct_T0Array  struct class_Generic_T0Array
#define stack_T0Array  stack_Generic_T0Array
#define T0Array  Generic_T0Array
#define T0ArrayType  Generic_T0ArrayType

#define T0Array_new  Generic_T0Array_new

#define T0Array_init  Generic_T0Array_init
#define T0Array_free  Generic_T0Array_free
#define T0Array_get_Length  Generic_T0Array_get_Length
#define T0Array_get_index  Generic_T0Array_get_index
#define T0Array_set_index  Generic_T0Array_set_index
#define T0Array_resize  Generic_T0Array_resize

#define function_T0Array_init  function_Generic_T0Array_init
#define function_T0Array_free  function_Generic_T0Array_free
#define function_T0Array_get_Length  function_Generic_T0Array_get_Length
#define function_T0Array_get_index  function_Generic_T0Array_get_index
#define function_T0Array_set_index  function_Generic_T0Array_set_index
#define function_T0Array_copyTo  function_Generic_T0Array_copyTo
#define function_T0Array_resize  function_Generic_T0Array_resize
#endif

#endif
