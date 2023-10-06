/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_String8)
#include "System.String8.h"
#endif
#if !defined(have_System_IEnumerable)
#include "System.IEnumerable.h"
#endif
#if !defined(have_System_ICollection)
#include "System.ICollection.h"
#endif
#if !defined(have_System_String8Dictionary)
#define have_System_String8Dictionary

typedef System_fixed struct System_String8Dictionary {
    struct System_Object base;

    System_Size  length;

    System_Size capacity;
    
    System_String8  (* key)[];

    System_String8  (* value)[];

}  * System_String8Dictionary;

export struct System_Type  System_String8DictionaryType;

typedef System_String8Dictionary delegate(System_String8Dictionary_init)(System_String8Dictionary that, System_Size capacity);
typedef void delegate(System_String8Dictionary_free)(System_String8Dictionary that);
typedef System_Size  delegate(System_String8Dictionary_get_Length)(System_String8Dictionary that);
typedef System_String8  delegate(System_String8Dictionary_get_index)(System_String8Dictionary that, System_Size index);
typedef void  delegate(System_String8Dictionary_set_index)(System_String8Dictionary that, System_Size index, System_String8 value);
typedef void delegate(System_String8Dictionary_copyTo)(System_String8Dictionary that, System_String8Dictionary other, System_Size offset);
typedef void delegate(System_String8Dictionary_resize)(System_String8Dictionary that, System_Size length);
typedef System_IEnumerator  delegate(System_String8Dictionary_getEnumerator)(System_String8Dictionary that);

export System_String8Dictionary  base_System_String8Dictionary_init(System_String8Dictionary that, System_Size capacity);
export void  base_System_String8Dictionary_free(System_String8Dictionary that);
export System_Size base_System_String8Dictionary_add(System_String8Dictionary that, System_String8 key, System_String8 value);
export System_Size  base_System_String8Dictionary_get_Length(System_String8Dictionary that);
export System_String8  base_System_String8Dictionary_get_index(System_String8Dictionary that, System_Size index);
export System_Size  base_System_String8Dictionary_get_key(System_String8Dictionary that, System_String8 key);
export System_String8  base_System_String8Dictionary_get_value(System_String8Dictionary that, System_String8 key);
export void  base_System_String8Dictionary_set_index(System_String8Dictionary that, System_Size index, System_String8 value);
export void  base_System_String8Dictionary_set_key(System_String8Dictionary that, System_String8 old, System_String8 new);
export void  base_System_String8Dictionary_set_value(System_String8Dictionary that, System_String8 key, System_String8 value);
export void  base_System_String8Dictionary_copyTo(System_String8Dictionary that, System_String8Dictionary other, System_Size offset);
export void  base_System_String8Dictionary_resize(System_String8Dictionary that, System_Size length);
export System_IEnumerator  base_System_String8Dictionary_getEnumerator(System_String8Dictionary that);

#define System_String8Dictionary_init(o,...)  ((function_System_String8Dictionary_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String8Dictionary_init))(o, __VA_ARGS__)
#define System_String8Dictionary_free(o)  ((function_System_String8Dictionary_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String8Dictionary_get_Length(o)  ((function_System_String8Dictionary_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_String8Dictionary_get_index(o,...)  ((function_System_String8Dictionary_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_String8Dictionary_set_index(o,...)  ((function_System_String8Dictionary_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_String8Dictionary_copyTo(o,...)  ((function_System_String8Dictionary_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_String8Dictionary_resize(o,...)  ((function_System_String8Dictionary_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String8Dictionary_resize))(o,__VA_ARGS__)
#define System_String8Dictionary_getEnumerator(o)  ((function_System_String8Dictionary_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define new_System_String8Dictionary(LENGTH)  (base_System_String8Dictionary_init((System_String8Dictionary)System_Memory_allocClass(typeof(System_String8Dictionary)), LENGTH))

#if defined(using_System)
#define String8Dictionary  System_String8Dictionary
#define String8DictionaryType  System_String8DictionaryType

#define new_String8Dictionary  new_System_String8Dictionary

#define String8Dictionary_init  System_String8Dictionary_init
#define String8Dictionary_free  System_String8Dictionary_free
#define String8Dictionary_get_Length  System_String8Dictionary_get_Length
#define String8Dictionary_get_index  System_String8Dictionary_get_index
#define String8Dictionary_set_index  System_String8Dictionary_set_index
#define String8Dictionary_resize  System_String8Dictionary_resize
#define base_String8Dictionary_init  base_System_String8Dictionary_init
#define base_String8Dictionary_free  base_System_String8Dictionary_free
#define base_String8Dictionary_get_Length  base_System_String8Dictionary_get_Length
#define base_String8Dictionary_get_index  base_System_String8Dictionary_get_index
#define base_String8Dictionary_set_index  base_System_String8Dictionary_set_index
#define base_String8Dictionary_resize  base_System_String8Dictionary_resize
#define base_String8Dictionary_getEnumerator  base_System_String8Dictionary_getEnumerator
#define function_String8Dictionary_init  function_System_String8Dictionary_init
#define function_String8Dictionary_free  function_System_String8Dictionary_free
#define function_String8Dictionary_get_Length  function_System_String8Dictionary_get_Length
#define function_String8Dictionary_get_index  function_System_String8Dictionary_get_index
#define function_String8Dictionary_set_index  function_System_String8Dictionary_set_index
#define function_String8Dictionary_resize  function_System_String8Dictionary_resize
#define function_String8Dictionary_getEnumerator  function_System_String8Dictionary_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_String8DictionaryEnumerator)
#define have_System_String8DictionaryEnumerator


typedef System_fixed struct System_String8DictionaryEnumerator {
    struct System_Object base;

    System_String8Dictionary array;

    System_Size index;

}  * System_String8DictionaryEnumerator;

export struct System_Type  System_String8DictionaryEnumeratorType;

typedef void delegate(System_String8DictionaryEnumerator_free)(System_String8DictionaryEnumerator that);
typedef System_String8DictionaryEnumerator delegate(System_String8DictionaryEnumerator_init)(System_String8DictionaryEnumerator that, System_String8Dictionary array);
typedef System_String8 delegate(System_String8DictionaryEnumerator_get_current)(System_String8DictionaryEnumerator that);
typedef System_Bool delegate(System_String8DictionaryEnumerator_moveNext)(System_String8DictionaryEnumerator that);

export System_String8DictionaryEnumerator  base_System_String8DictionaryEnumerator_init(System_String8DictionaryEnumerator that, System_String8Dictionary array);
export void  base_System_String8DictionaryEnumerator_free(System_String8DictionaryEnumerator that);
export System_String8  base_System_String8DictionaryEnumerator_get_current(System_String8DictionaryEnumerator that);
export System_Bool  base_System_String8DictionaryEnumerator_moveNext(System_String8DictionaryEnumerator that);

#define System_String8DictionaryEnumerator_init(o,...)  ((function_System_String8DictionaryEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String8DictionaryEnumerator_init))(o,__VA_ARGS__)
#define System_String8DictionaryEnumerator_free(o)  ((function_System_String8DictionaryEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String8DictionaryEnumerator_get_current(o)  ((function_System_String8DictionaryEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_String8DictionaryEnumerator_moveNext(o)  ((function_System_String8DictionaryEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define new_System_String8DictionaryEnumerator(a)  (base_System_String8DictionaryEnumerator_init((System_String8DictionaryEnumerator)System_Memory_allocClass(typeof(System_String8DictionaryEnumerator)), a))

#if defined(using_System)
#define String8DictionaryEnumerator  System_String8DictionaryEnumerator
#define String8DictionaryEnumeratorType  System_String8DictionaryEnumeratorType
#define function_String8DictionaryEnumerator_init  function_System_String8DictionaryEnumerator_init
#define function_String8DictionaryEnumerator_free  function_System_String8DictionaryEnumerator_free
#define base_String8DictionaryEnumerator_init  base_System_String8DictionaryEnumerator_init
#define base_String8DictionaryEnumerator_free  base_System_String8DictionaryEnumerator_free
#define String8DictionaryEnumerator_init  System_String8DictionaryEnumerator_init
#define String8DictionaryEnumerator_free  System_String8DictionaryEnumerator_free
#define new_String8DictionaryEnumerator  new_System_String8DictionaryEnumerator
#endif
#endif
