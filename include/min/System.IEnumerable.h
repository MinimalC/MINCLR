/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
#if !defined(have_System_IEnumerable)
#define have_System_IEnumerable

/* interface System_IEnumerator */

#define struct_System_IEnumerator  struct interface_System_IEnumerator
typedef __fixed  struct_System_IEnumerator { }  * System_IEnumerator;

__export struct_System_Type  System_IEnumeratorType;

typedef System_var __delegate(System_IEnumerator_get_current)(System_IEnumerator that);
typedef System_boolean __delegate(System_IEnumerator_moveNext)(System_IEnumerator that);

__export System_var  base_System_IEnumerator_get_current(System_IEnumerator that);
__export System_boolean  base_System_IEnumerator_moveNext(System_IEnumerator that);

#define System_IEnumerator_get_current(o)  ((function_System_IEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_IEnumerator_moveNext(o)  ((function_System_IEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define struct_IEnumerator  struct_System_IEnumerator
#define __IEnumerator  System_IEnumerator
#define __IEnumeratorType  System_IEnumeratorType
#define function_IEnumerator_get_current  function_System_IEnumerator_get_current
#define function_IEnumerator_moveNext  function_System_IEnumerator_moveNext
#define base_IEnumerator_get_current  base_System_IEnumerator_get_current
#define base_IEnumerator_moveNext  base_System_IEnumerator_moveNext
#define __IEnumerator_get_current  System_IEnumerator_get_current
#define __IEnumerator_moveNext  System_IEnumerator_moveNext
#endif

/* interface System_IEnumerable */

#define struct_System_IEnumerable  struct interface_System_IEnumerable
typedef __fixed  struct_System_IEnumerable { }  * System_IEnumerable;

__export struct_System_Type  System_IEnumerableType;

typedef System_IEnumerator __delegate(System_IEnumerable_getEnumerator)(System_IEnumerable that);
typedef System_void  __delegate(System_IEnumerable_foreach)(System_IEnumerable that, System_Type type, void * action);

__export System_IEnumerator  base_System_IEnumerable_getEnumerator(System_IEnumerable that);
__export System_void  base_System_IEnumerable_foreach(System_IEnumerable that, System_Type type, void * action);

#define System_IEnumerable_getEnumerator(o)  ((function_System_IEnumerable_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)
#define System_IEnumerable_foreach(o,...)  ((function_System_IEnumerable_foreach)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_foreach))(o,__VA_ARGS__)

#define stack_System_foreach__n(__num,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  {\
    __ccc(struct_,__ARRAYT,Enumerator) enumerator##__num = __ccc(stack_,__ARRAYT,Enumerator)();\
    __cc(__ARRAYT,Enumerator_init)(&enumerator##__num, __ARRAY);\
    while (__cc(__ARRAYT,Enumerator_moveNext)(&enumerator##__num)) {\
        __TYPE __THAT = (__TYPE)__cc(__ARRAYT,Enumerator_get_current)(&enumerator##__num);\
        if (System_Exception_get_current()) goto break_stack_foreach##__num;\
        __action ;\
    } break_stack_foreach##__num: ;\
    __cc(__ARRAYT,Enumerator_free)(&enumerator##__num); }

#define stack_System_foreach(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(00,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)

#define inline_System_foreach__n(__num,__TYPE,__THAT,__ARRAY,__action)  {\
    System_IEnumerator enumerator##__num = System_IEnumerable_getEnumerator((System_IEnumerable)__ARRAY);\
    while (System_IEnumerator_moveNext(enumerator##__num)) {\
        __TYPE __THAT = (__TYPE)System_IEnumerator_get_current(enumerator##__num);\
        if (System_Exception_get_current()) goto break_inline_foreach##__num;\
        __action ;\
    } break_inline_foreach##__num: ;\
    inline_System_Object_freeClass(&enumerator##__num); }

#define inline_System_foreach(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(00,__TYPE,__THAT,__ARRAY,__action)

#if defined(using_System)
#define struct_IEnumerable  struct_System_IEnumerable
#define __IEnumerable  System_IEnumerable
#define __IEnumerableType  System_IEnumerableType

#define function_IEnumerable_getEnumerator  function_System_IEnumerable_getEnumerator
#define base_IEnumerable_getEnumerator  base_System_IEnumerable_getEnumerator
#define __IEnumerable_getEnumerator  System_IEnumerable_getEnumerator

#define stack_foreach  stack_System_foreach
#define __foreach  inline_System_foreach
#endif

#define stack_System_foreach_(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(01,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)
#define stack_System_foreach__(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(02,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)
#define stack_System_foreach___(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(03,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)
#define stack_System_foreach____(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(04,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)
#define _stack_System_foreach(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(05,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)
#define __stack_System_foreach(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(06,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)
#define ___stack_System_foreach(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(07,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)
#define ____stack_System_foreach(__TYPE,__THAT,__ARRAYT,__ARRAY,__action)  stack_System_foreach__n(08,__TYPE,__THAT,__ARRAYT,__ARRAY,__action)

#define inline_System_foreach_(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(01,__TYPE,__THAT,__ARRAY,__action)
#define inline_System_foreach__(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(02,__TYPE,__THAT,__ARRAY,__action)
#define inline_System_foreach___(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(03,__TYPE,__THAT,__ARRAY,__action)
#define inline_System_foreach____(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(04,__TYPE,__THAT,__ARRAY,__action)
#define _inline_System_foreach(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(05,__TYPE,__THAT,__ARRAY,__action)
#define __inline_System_foreach(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(06,__TYPE,__THAT,__ARRAY,__action)
#define ___inline_System_foreach(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(07,__TYPE,__THAT,__ARRAY,__action)
#define ____inline_System_foreach(__TYPE,__THAT,__ARRAY,__action)  inline_System_foreach__n(08,__TYPE,__THAT,__ARRAY,__action)


#endif
