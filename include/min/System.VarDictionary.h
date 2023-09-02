/* Gemeinfrei. Public Domain. */

#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IEnumerable)
#include "System.IEnumerable.h"
#endif
#if !defined(have_System_ICollection)
#include "System.ICollection.h"
#endif
#if !defined(have_System_VarDictionary)
#define have_System_VarDictionary

typedef System_fixed struct System_VarDictionary {
    struct System_Object base;

    System_Size  length;

    System_Size capacity;
    
    System_Var  (* key)[];

    System_Var  (* value)[];

}  * System_VarDictionary;

export struct System_Type  System_VarDictionaryType;

typedef System_VarDictionary delegate(System_VarDictionary_init)(System_VarDictionary that, System_Size capacity);
typedef void delegate(System_VarDictionary_free)(System_VarDictionary that);
typedef System_Size  delegate(System_VarDictionary_get_Length)(System_VarDictionary that);
typedef System_Var  delegate(System_VarDictionary_get_index)(System_VarDictionary that, System_Size index);
typedef void  delegate(System_VarDictionary_set_index)(System_VarDictionary that, System_Size index, System_Var value);
typedef void delegate(System_VarDictionary_copyTo)(System_VarDictionary that, System_VarDictionary other, System_Size offset);
typedef void delegate(System_VarDictionary_resize)(System_VarDictionary that, System_Size length);
typedef System_IEnumerator  delegate(System_VarDictionary_getEnumerator)(System_VarDictionary that);

export System_VarDictionary  base_System_VarDictionary_init(System_VarDictionary that, System_Size capacity);
export void  base_System_VarDictionary_free(System_VarDictionary that);
export System_Size base_System_VarDictionary_add(System_VarDictionary that, System_Var key, System_Var value);
export System_Size  base_System_VarDictionary_get_Length(System_VarDictionary that);
export System_Var  base_System_VarDictionary_get_index(System_VarDictionary that, System_Size index);
export System_Size  base_System_VarDictionary_get_key(System_VarDictionary that, System_Var key);
export System_Var  base_System_VarDictionary_get_value(System_VarDictionary that, System_Var key);
export void  base_System_VarDictionary_set_index(System_VarDictionary that, System_Size index, System_Var value);
export void  base_System_VarDictionary_set_key(System_VarDictionary that, System_Var old, System_Var new);
export void  base_System_VarDictionary_set_value(System_VarDictionary that, System_Var key, System_Var value);
export void  base_System_VarDictionary_copyTo(System_VarDictionary that, System_VarDictionary other, System_Size offset);
export void  base_System_VarDictionary_resize(System_VarDictionary that, System_Size length);
export System_IEnumerator  base_System_VarDictionary_getEnumerator(System_VarDictionary that);

#define System_VarDictionary_init(o,...)  ((function_System_VarDictionary_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_VarDictionary_init))(o, __VA_ARGS__)
#define System_VarDictionary_free(o)  ((function_System_VarDictionary_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_VarDictionary_get_Length(o)  ((function_System_VarDictionary_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_VarDictionary_get_index(o,...)  ((function_System_VarDictionary_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_VarDictionary_set_index(o,...)  ((function_System_VarDictionary_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_VarDictionary_copyTo(o,...)  ((function_System_VarDictionary_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_VarDictionary_resize(o,...)  ((function_System_VarDictionary_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_VarDictionary_resize))(o,__VA_ARGS__)
#define System_VarDictionary_getEnumerator(o)  ((function_System_VarDictionary_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define new_System_VarDictionary(LENGTH)  (base_System_VarDictionary_init((System_VarDictionary)System_Memory_allocClass(typeof(System_VarDictionary)), LENGTH))

#if defined(using_System)
#define VarDictionary  System_VarDictionary
#define VarDictionaryType  System_VarDictionaryType

#define new_VarDictionary  new_System_VarDictionary

#define VarDictionary_init  System_VarDictionary_init
#define VarDictionary_free  System_VarDictionary_free
#define VarDictionary_get_Length  System_VarDictionary_get_Length
#define VarDictionary_get_index  System_VarDictionary_get_index
#define VarDictionary_set_index  System_VarDictionary_set_index
#define VarDictionary_resize  System_VarDictionary_resize
#define base_VarDictionary_init  base_System_VarDictionary_init
#define base_VarDictionary_free  base_System_VarDictionary_free
#define base_VarDictionary_get_Length  base_System_VarDictionary_get_Length
#define base_VarDictionary_get_index  base_System_VarDictionary_get_index
#define base_VarDictionary_set_index  base_System_VarDictionary_set_index
#define base_VarDictionary_resize  base_System_VarDictionary_resize
#define base_VarDictionary_getEnumerator  base_System_VarDictionary_getEnumerator
#define function_VarDictionary_init  function_System_VarDictionary_init
#define function_VarDictionary_free  function_System_VarDictionary_free
#define function_VarDictionary_get_Length  function_System_VarDictionary_get_Length
#define function_VarDictionary_get_index  function_System_VarDictionary_get_index
#define function_VarDictionary_set_index  function_System_VarDictionary_set_index
#define function_VarDictionary_resize  function_System_VarDictionary_resize
#define function_VarDictionary_getEnumerator  function_System_VarDictionary_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_VarDictionaryEnumerator)
#define have_System_VarDictionaryEnumerator


typedef System_fixed struct System_VarDictionaryEnumerator {
    struct System_Object base;

    System_VarDictionary array;

    System_Size index;

}  * System_VarDictionaryEnumerator;

export struct System_Type  System_VarDictionaryEnumeratorType;

typedef void delegate(System_VarDictionaryEnumerator_free)(System_VarDictionaryEnumerator that);
typedef System_VarDictionaryEnumerator delegate(System_VarDictionaryEnumerator_init)(System_VarDictionaryEnumerator that, System_VarDictionary array);
typedef System_Var delegate(System_VarDictionaryEnumerator_get_current)(System_VarDictionaryEnumerator that);
typedef System_Bool delegate(System_VarDictionaryEnumerator_moveNext)(System_VarDictionaryEnumerator that);

export System_VarDictionaryEnumerator  base_System_VarDictionaryEnumerator_init(System_VarDictionaryEnumerator that, System_VarDictionary array);
export void  base_System_VarDictionaryEnumerator_free(System_VarDictionaryEnumerator that);
export System_Var  base_System_VarDictionaryEnumerator_get_current(System_VarDictionaryEnumerator that);
export System_Bool  base_System_VarDictionaryEnumerator_moveNext(System_VarDictionaryEnumerator that);

#define System_VarDictionaryEnumerator_init(o,...)  ((function_System_VarDictionaryEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_VarDictionaryEnumerator_init))(o,__VA_ARGS__)
#define System_VarDictionaryEnumerator_free(o)  ((function_System_VarDictionaryEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_VarDictionaryEnumerator_get_current(o)  ((function_System_VarDictionaryEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_VarDictionaryEnumerator_moveNext(o)  ((function_System_VarDictionaryEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define new_System_VarDictionaryEnumerator(a)  (base_System_VarDictionaryEnumerator_init((System_VarDictionaryEnumerator)System_Memory_allocClass(typeof(System_VarDictionaryEnumerator)), a))

#if defined(using_System)
#define VarDictionaryEnumerator  System_VarDictionaryEnumerator
#define VarDictionaryEnumeratorType  System_VarDictionaryEnumeratorType
#define function_VarDictionaryEnumerator_init  function_System_VarDictionaryEnumerator_init
#define function_VarDictionaryEnumerator_free  function_System_VarDictionaryEnumerator_free
#define base_VarDictionaryEnumerator_init  base_System_VarDictionaryEnumerator_init
#define base_VarDictionaryEnumerator_free  base_System_VarDictionaryEnumerator_free
#define VarDictionaryEnumerator_init  System_VarDictionaryEnumerator_init
#define VarDictionaryEnumerator_free  System_VarDictionaryEnumerator_free
#define new_VarDictionaryEnumerator  new_System_VarDictionaryEnumerator
#endif
#endif
