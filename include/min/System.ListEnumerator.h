/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
/* #if !defined(have_System_List)
#warning "System.List.h not included"
#include "System.List.h"
#endif */
#if !defined(have_System_ListEnumerator)
#define have_System_ListEnumerator

typedef fixed struct System_ListEnumerator {
    struct System_Object base;

    System_List array;

    System_Size index;

}  * System_ListEnumerator;

#define stack_System_ListEnumerator()  (struct System_ListEnumerator){ .base = stack_System_Object(System_ListEnumerator), }
#define new_System_ListEnumerator(ARRAY)  (base_System_ListEnumerator_init((System_ListEnumerator)System_Memory_allocClass(typeof(System_ListEnumerator), ARRAY)))

export struct System_Type  System_ListEnumeratorType;

typedef void delegate(System_ListEnumerator_free)(System_ListEnumerator that);
typedef System_ListEnumerator delegate(System_ListEnumerator_init)(System_ListEnumerator that, System_List array);
typedef System_Object delegate(System_ListEnumerator_get_current)(System_ListEnumerator that);
typedef System_Bool delegate(System_ListEnumerator_moveNext)(System_ListEnumerator that);

export System_ListEnumerator  base_System_ListEnumerator_init(System_ListEnumerator that, System_List array);
export void  base_System_ListEnumerator_free(System_ListEnumerator that);
export System_Object  base_System_ListEnumerator_get_current(System_ListEnumerator that);
export System_Bool  base_System_ListEnumerator_moveNext(System_ListEnumerator that);

#define System_ListEnumerator_init(o,...)  ((function_System_ListEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ListEnumerator_init))(o,__VA_ARGS__)
#define System_ListEnumerator_free(o)  ((function_System_ListEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_ListEnumerator_get_current(o)  ((function_System_ListEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_ListEnumerator_moveNext(o)  ((function_System_ListEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define ListArrayEnumerator  System_ListEnumerator
#define ListArrayEnumeratorType  System_ListEnumeratorType
#define stack_ListArrayEnumerator  stack_System_ListEnumerator
#define new_ListArrayEnumerator  new_System_ListEnumerator
#define function_ListArrayEnumerator_init  function_System_ListEnumerator_init
#define function_ListArrayEnumerator_free  function_System_ListEnumerator_free
#define base_ListArrayEnumerator_init  base_System_ListEnumerator_init
#define base_ListArrayEnumerator_free  base_System_ListEnumerator_free
#define ListArrayEnumerator_init  System_ListEnumerator_init
#define ListArrayEnumerator_free  System_ListEnumerator_free
#endif
#endif
