/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IEnumerable)
#include "System.IEnumerable.h"
#endif
#if !defined(have_System_ICollection)
#include "System.ICollection.h"
#endif
#if !defined(have_System_VarArray)
#define have_System_VarArray

typedef System_fixed struct System_VarArray {
    struct System_Object base;

    System_Size  length;

    System_Size  capacity;
    
    System_Var  (* value)[];

}  * System_VarArray;

export struct System_Type  System_VarArrayType;

typedef void delegate(System_VarArray_init)(System_VarArray that, System_Size capacity);
typedef void delegate(System_VarArray_free)(System_VarArray that);
typedef System_Size  delegate(System_VarArray_get_Length)(System_VarArray that);
typedef System_Var  delegate(System_VarArray_get_index)(System_VarArray that, System_Size index);
typedef void  delegate(System_VarArray_set_index)(System_VarArray that, System_Size index, System_Var value);
typedef void delegate(System_VarArray_copyTo)(System_VarArray that, System_VarArray other, System_Size offset);
typedef void delegate(System_VarArray_resize)(System_VarArray that, System_Size capacity);
typedef System_IEnumerator  delegate(System_VarArray_getEnumerator)(System_VarArray that);

export System_VarArray  new_System_VarArray(System_Size capacity);
export void  base_System_VarArray_init(System_VarArray that, System_Size capacity);
export void  base_System_VarArray_free(System_VarArray that);
export System_Size  base_System_VarArray_get_Length(System_VarArray that);
export System_Var  base_System_VarArray_get_index(System_VarArray that, System_Size index);
export void  base_System_VarArray_set_index(System_VarArray that, System_Size index, System_Var value);
export void  base_System_VarArray_copyTo(System_VarArray that, System_VarArray other, System_Size offset);
export void  base_System_VarArray_resize(System_VarArray that, System_Size capacity);
export System_IEnumerator  base_System_VarArray_getEnumerator(System_VarArray that);

#define System_VarArray_init(o,...)  ((function_System_VarArray_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_VarArray_init))(o, __VA_ARGS__)
#define System_VarArray_free(o)  ((function_System_VarArray_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_VarArray_get_Length(o)  ((function_System_VarArray_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_VarArray_get_index(o,...)  ((function_System_VarArray_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_VarArray_set_index(o,...)  ((function_System_VarArray_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_VarArray_copyTo(o,...)  ((function_System_VarArray_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_VarArray_resize(o,...)  ((function_System_VarArray_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_VarArray_resize))(o,__VA_ARGS__)
#define System_VarArray_getEnumerator(o)  ((function_System_VarArray_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define VarArray  System_VarArray
#define VarArrayType  System_VarArrayType

#define VarArray_init  System_VarArray_init
#define VarArray_free  System_VarArray_free
#define VarArray_get_Length  System_VarArray_get_Length
#define VarArray_get_index  System_VarArray_get_index
#define VarArray_set_index  System_VarArray_set_index
#define VarArray_resize  System_VarArray_resize
#define base_VarArray_init  base_System_VarArray_init
#define base_VarArray_free  base_System_VarArray_free
#define base_VarArray_get_Length  base_System_VarArray_get_Length
#define base_VarArray_get_index  base_System_VarArray_get_index
#define base_VarArray_set_index  base_System_VarArray_set_index
#define base_VarArray_resize  base_System_VarArray_resize
#define base_VarArray_getEnumerator  base_System_VarArray_getEnumerator
#define function_VarArray_init  function_System_VarArray_init
#define function_VarArray_free  function_System_VarArray_free
#define function_VarArray_get_Length  function_System_VarArray_get_Length
#define function_VarArray_get_index  function_System_VarArray_get_index
#define function_VarArray_set_index  function_System_VarArray_set_index
#define function_VarArray_resize  function_System_VarArray_resize
#define function_VarArray_getEnumerator  function_System_VarArray_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_VarArrayEnumerator)
#define have_System_VarArrayEnumerator


typedef System_fixed struct System_VarArrayEnumerator {
    struct System_Object base;

    System_VarArray array;

    System_Size index;

}  * System_VarArrayEnumerator;

export struct System_Type  System_VarArrayEnumeratorType;

typedef void delegate(System_VarArrayEnumerator_free)(System_VarArrayEnumerator that);
typedef void delegate(System_VarArrayEnumerator_init)(System_VarArrayEnumerator that, System_VarArray array);
typedef System_Var delegate(System_VarArrayEnumerator_get_current)(System_VarArrayEnumerator that);
typedef System_Bool delegate(System_VarArrayEnumerator_moveNext)(System_VarArrayEnumerator that);

export System_VarArrayEnumerator  new_System_VarArrayEnumerator(System_VarArray array);
export void  base_System_VarArrayEnumerator_init(System_VarArrayEnumerator that, System_VarArray array);
export void  base_System_VarArrayEnumerator_free(System_VarArrayEnumerator that);
export System_Var  base_System_VarArrayEnumerator_get_current(System_VarArrayEnumerator that);
export System_Bool  base_System_VarArrayEnumerator_moveNext(System_VarArrayEnumerator that);

#define System_VarArrayEnumerator_init(o,...)  ((function_System_VarArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_VarArrayEnumerator_init))(o,__VA_ARGS__)
#define System_VarArrayEnumerator_free(o)  ((function_System_VarArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_VarArrayEnumerator_get_current(o)  ((function_System_VarArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_VarArrayEnumerator_moveNext(o)  ((function_System_VarArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define VarArrayEnumerator  System_VarArrayEnumerator
#define VarArrayEnumeratorType  System_VarArrayEnumeratorType
#define function_VarArrayEnumerator_init  function_System_VarArrayEnumerator_init
#define function_VarArrayEnumerator_free  function_System_VarArrayEnumerator_free
#define base_VarArrayEnumerator_init  base_System_VarArrayEnumerator_init
#define base_VarArrayEnumerator_free  base_System_VarArrayEnumerator_free
#define VarArrayEnumerator_init  System_VarArrayEnumerator_init
#define VarArrayEnumerator_free  System_VarArrayEnumerator_free
#endif
#endif
