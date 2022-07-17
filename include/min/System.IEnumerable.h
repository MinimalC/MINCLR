/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IEnumerable)
#define have_System_IEnumerable

/* interface System_IEnumerator */

#define struct_System_IEnumerator  struct System_IEnumerator
typedef fixed  struct_System_IEnumerator { }  * System_IEnumerator;

export struct_System_Type  System_IEnumeratorType;

typedef System_var delegate(System_IEnumerator_get_current)(System_IEnumerator that);
typedef System_boolean delegate(System_IEnumerator_moveNext)(System_IEnumerator that);

export System_var  base_System_IEnumerator_get_current(System_IEnumerator that);
export System_boolean  base_System_IEnumerator_moveNext(System_IEnumerator that);

#define System_IEnumerator_get_current(o)  ((function_System_IEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_IEnumerator_moveNext(o)  ((function_System_IEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define struct_IEnumerator  struct_System_IEnumerator
#define IEnumerator  System_IEnumerator
#define IEnumeratorType  System_IEnumeratorType
#define function_IEnumerator_get_current  function_System_IEnumerator_get_current
#define function_IEnumerator_moveNext  function_System_IEnumerator_moveNext
#define base_IEnumerator_get_current  base_System_IEnumerator_get_current
#define base_IEnumerator_moveNext  base_System_IEnumerator_moveNext
#define IEnumerator_get_current  System_IEnumerator_get_current
#define IEnumerator_moveNext  System_IEnumerator_moveNext
#endif

/* interface System_IEnumerable */

#define struct_System_IEnumerable  struct interface_System_IEnumerable
typedef fixed  struct_System_IEnumerable { }  * System_IEnumerable;

export struct_System_Type  System_IEnumerableType;

typedef System_IEnumerator delegate(System_IEnumerable_getEnumerator)(System_IEnumerable that);
typedef void  delegate(System_IEnumerable_foreach)(System_IEnumerable that, System_Type type, void * action);

export System_IEnumerator  base_System_IEnumerable_getEnumerator(System_IEnumerable that);
export void  base_System_IEnumerable_foreach(System_IEnumerable that, System_Type type, void * action);

#define System_IEnumerable_getEnumerator(o)  ((function_System_IEnumerable_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)
#define System_IEnumerable_foreach(o,...)  ((function_System_IEnumerable_foreach)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_foreach))(o,__VA_ARGS__)

#define stack_System_foreach__n(N,TYPE,THAT,ARRAYT,ARRAY,ACTION)  {\
    ccc(struct_,ARRAYT,Enumerator) enumerator##N = ccc(stack_,ARRAYT,Enumerator)();\
    cc(ARRAYT,Enumerator_init)(&enumerator##N, ARRAY);\
    while (cc(ARRAYT,Enumerator_moveNext)(&enumerator##N)) {\
        TYPE THAT = (TYPE)cc(ARRAYT,Enumerator_get_current)(&enumerator##N);\
        if (System_Exception_get_current()) goto break_stack_foreach##N;\
        ACTION ;\
    } break_stack_foreach##N: ;\
    cc(ARRAYT,Enumerator_free)(&enumerator##N); }


#define inline_System_foreach__n(N,TYPE,THAT,ARRAY,ACTION)  {\
    System_IEnumerator enumerator##N = System_IEnumerable_getEnumerator((System_IEnumerable)ARRAY);\
    while (System_IEnumerator_moveNext(enumerator##N)) {\
        TYPE THAT = (TYPE)System_IEnumerator_get_current(enumerator##N);\
        if (System_Exception_get_current()) goto break_inline_foreach##N;\
        ACTION ;\
    } break_inline_foreach##N: ;\
    inline_System_Object_freeClass(&enumerator##N); }

#define stack_System_foreach(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(00,TYPE,THAT,ARRAYT,ARRAY,ACTION)
#define stack_System_foreach_(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(01,TYPE,THAT,ARRAYT,ARRAY,ACTION)
#define stack_System_foreach__(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(02,TYPE,THAT,ARRAYT,ARRAY,ACTION)
#define stack_System_foreach___(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(03,TYPE,THAT,ARRAYT,ARRAY,ACTION)
#define stack_System_foreach____(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(04,TYPE,THAT,ARRAYT,ARRAY,ACTION)
#define _stack_System_foreach(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(05,TYPE,THAT,ARRAYT,ARRAY,ACTION)
#define __stack_System_foreach(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(06,TYPE,THAT,ARRAYT,ARRAY,ACTION)
#define ___stack_System_foreach(TYPE,THAT,ARRAYT,ARRAY,ACTION)  stack_System_foreach__n(07,TYPE,THAT,ARRAYT,ARRAY,ACTION)

#define inline_System_foreach(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(00,TYPE,THAT,ARRAY,ACTION)
#define inline_System_foreach_(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(01,TYPE,THAT,ARRAY,ACTION)
#define inline_System_foreach__(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(02,TYPE,THAT,ARRAY,ACTION)
#define inline_System_foreach___(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(03,TYPE,THAT,ARRAY,ACTION)
#define inline_System_foreach____(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(04,TYPE,THAT,ARRAY,ACTION)
#define _inline_System_foreach(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(05,TYPE,THAT,ARRAY,ACTION)
#define __inline_System_foreach(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(06,TYPE,THAT,ARRAY,ACTION)
#define ___inline_System_foreach(TYPE,THAT,ARRAY,ACTION)  inline_System_foreach__n(07,TYPE,THAT,ARRAY,ACTION)

#if defined(using_System)
#define struct_IEnumerable  struct_System_IEnumerable
#define IEnumerable  System_IEnumerable
#define IEnumerableType  System_IEnumerableType

#define function_IEnumerable_getEnumerator  function_System_IEnumerable_getEnumerator
#define base_IEnumerable_getEnumerator  base_System_IEnumerable_getEnumerator
#define IEnumerable_getEnumerator  System_IEnumerable_getEnumerator

#define stack_foreach  stack_System_foreach
#define foreach  inline_System_foreach
#endif
#endif
