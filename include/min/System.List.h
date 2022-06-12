/* Gemeinfrei. Public Domain. */
#if !defined(have_System)
#warning "System.h not included"
#include "System.h"
#endif
#if !defined(have_System_List)
#define have_System_List

/* 2-Dimensional, Unique SipHash-Indexed ObjectList */

#define System_List_Capacity_DEFAULT  64
__export const System_size  System_List_Capacity;

#define struct_System_List  struct class_System_List
typedef __fixed struct_System_List {
    struct_System_Object base;

    System_size capacity;

    System_size length;

    System_uint64Array hashes;

    System_Array items;

}  * System_List;

#define stack_System_List()  (struct_System_List){ .base = stack_System_Object(System_List), }

__export struct_System_Type  System_ListType;

typedef System_List __delegate(System_List_init)(System_List that);
typedef System_void __delegate(System_List_free)(System_List that);
typedef System_size  __delegate(System_List_get_Length)(System_List that);
typedef System_Object  __delegate(System_List_get_index)(System_List that, System_size index);
typedef System_void  __delegate(System_List_set_index)(System_List that, System_size index, System_Object value);
typedef System_void __delegate(System_List_copyTo)(System_List that, System_List other, System_size offset);
typedef System_boolean  __delegate(System_List_contains)(System_List that, System_Object object);
typedef System_void __delegate(System_List_add)(System_List that, System_Object object);

#define System_List_new  System_List_new__00

__export System_List  System_List_new();
__export System_List  base_System_List_init(System_List that);
__export System_void  base_System_List_free(System_List that);
__export System_size  base_System_List_get_Length(System_List that);
__export System_Object  base_System_List_get_index(System_List that, System_size index);
__export System_void  base_System_List_set_index(System_List that, System_size index, System_Object value);
__export System_void  base_System_List_copyTo(System_List that, System_List other, System_size offset);
__export System_boolean  base_System_List_contains(System_List that, System_Object object);
__export System_void  base_System_List_add(System_List that, System_Object object);

#define System_List_init(o)  ((function_System_List_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_List_free(o)  ((function_System_List_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_List_get_Length(o)  ((function_System_List_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_List_get_index(o,...)  ((function_System_List_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_List_set_index(o,...)  ((function_System_List_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_List_copyTo(o,...)  ((function_System_List_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_List_contains(o,...)  ((function_System_List_contains)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_List_contains))(o,__VA_ARGS__)
#define System_List_add(o,...)  ((function_System_List_add)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_List_add))(o,__VA_ARGS__)

#define inline_System_List_new()  (base_System_List_init(inline_System_Object_allocClass(System_List)))

#if !defined(have_System_internal)
#undef  System_List_new
#define System_List_new  inline_System_List_new
#endif

#if defined(using_System)
#define struct_List  struct_System_List
#define __List  System_List
#define __ListType  System_ListType

#define function_List_init  function_System_List_init
#define function_List_free  function_System_List_free
#define function_List_contains  function_System_List_contains
#define function_List_add  function_System_List_add
#define base_List_init  base_System_List_init
#define base_List_free  base_System_List_free
#define base_List_contains  base_System_List_contains
#define base_List_add  base_System_List_add
#define __List_new  System_List_new
#define __List_init  System_List_init
#define __List_free  System_List_free
#define __List_contains  System_List_contains
#define __List_add  System_List_add
#endif

#endif
