/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_List)
#define have_System_List

/* 2-Dimensional, Unique SipHash-Indexed ObjectList */

typedef System_fixed struct System_List {
    struct System_Object base;

    System_Array items;

}  * System_List;

#define stack_System_List()  { .base = stack_System_Object(System_List), }
#define new_System_List()  (base_System_List_init((System_List)System_Memory_allocClass(typeof(System_List))))

export struct System_Type  System_ListType;

typedef System_List delegate(System_List_init)(System_List that);
typedef void delegate(System_List_free)(System_List that);
typedef System_Size  delegate(System_List_get_Length)(System_List that);
typedef System_Object  delegate(System_List_get_index)(System_List that, System_Size index);
typedef void  delegate(System_List_set_index)(System_List that, System_Size index, System_Object value);
typedef void delegate(System_List_copyTo)(System_List that, System_List other, System_Size offset);
typedef System_Bool  delegate(System_List_contains)(System_List that, System_Object object);
typedef void delegate(System_List_add)(System_List that, System_Object object);

export System_List  base_System_List_init(System_List that);
export void  base_System_List_free(System_List that);
export System_Size  base_System_List_get_Length(System_List that);
export System_Object  base_System_List_get_index(System_List that, System_Size index);
export void  base_System_List_set_index(System_List that, System_Size index, System_Object value);
export void  base_System_List_copyTo(System_List that, System_List other, System_Size offset);
export System_Bool  base_System_List_contains(System_List that, System_Object object);
export void  base_System_List_add(System_List that, System_Object object);

#define System_List_init(o)  ((function_System_List_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_List_free(o)  ((function_System_List_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_List_get_Length(o)  ((function_System_List_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_List_get_index(o,...)  ((function_System_List_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_List_set_index(o,...)  ((function_System_List_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_List_copyTo(o,...)  ((function_System_List_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_List_contains(o,...)  ((function_System_List_contains)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_List_contains))(o,__VA_ARGS__)
#define System_List_add(o,...)  ((function_System_List_add)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_List_add))(o,__VA_ARGS__)

#if defined(using_System)
#define List  System_List
#define ListType  System_ListType
#define stack_List  stack_System_List
#define new_List  new_System_List
#define function_List_init  function_System_List_init
#define function_List_free  function_System_List_free
#define function_List_contains  function_System_List_contains
#define function_List_add  function_System_List_add
#define base_List_init  base_System_List_init
#define base_List_free  base_System_List_free
#define base_List_contains  base_System_List_contains
#define base_List_add  base_System_List_add
#define List_init  System_List_init
#define List_free  System_List_free
#define List_contains  System_List_contains
#define List_add  System_List_add
#endif
#endif
