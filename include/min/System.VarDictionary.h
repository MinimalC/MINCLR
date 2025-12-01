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

enum { System_VarDictionary_Capacity = 64 };

typedef System_fixed struct System_VarDictionary {
    struct System_Object base;

    System_Size  length;

    System_Size capacity;
    
    System_String8  (* key)[];

    System_Var  (* value)[];

}  * System_VarDictionary;

export struct System_Type  System_VarDictionaryType;

export System_VarDictionary  new_System_VarDictionary();
export void  System_VarDictionary_init(System_VarDictionary that);
export void  System_VarDictionary_free(System_VarDictionary that);
export System_Size System_VarDictionary_add(System_VarDictionary that, System_String8 key, System_Var value);
export System_Size  System_VarDictionary_get_Length(System_VarDictionary that);
export System_Var  System_VarDictionary_get_index(System_VarDictionary that, System_Size index);
export System_Size  System_VarDictionary_get_key(System_VarDictionary that, System_String8 key);
export System_Var  System_VarDictionary_get_value(System_VarDictionary that, System_String8 key);
export void  System_VarDictionary_set_index(System_VarDictionary that, System_Size index, System_Var value);
export void  System_VarDictionary_set_value(System_VarDictionary that, System_String8 key, System_Var value);
export void  System_VarDictionary_copyTo(System_VarDictionary that, System_VarDictionary other, System_Size offset);
export void  System_VarDictionary_resize(System_VarDictionary that, System_Size length);
export void  System_VarDictionary_remove(System_VarDictionary that, System_String8 key);
export System_Bool  System_VarDictionary_containsKey(System_VarDictionary that, System_String8 key);
export System_IEnumerator  System_VarDictionary_getEnumerator(System_VarDictionary that);

#if defined(using_System)
#define VarDictionary  System_VarDictionary
#define VarDictionaryType  System_VarDictionaryType
#define new_VarDictionary  new_System_VarDictionary
#define VarDictionary_init  System_VarDictionary_init
#define VarDictionary_free  System_VarDictionary_free
#define VarDictionary_add  System_VarDictionary_add
#define VarDictionary_get_Length  System_VarDictionary_get_Length
#define VarDictionary_get_index  System_VarDictionary_get_index
#define VarDictionary_set_index  System_VarDictionary_set_index
#define VarDictionary_resize  System_VarDictionary_resize
#define VarDictionary_remove  System_VarDictionary_remove
#define VarDictionary_getEnumerator  System_VarDictionary_getEnumerator
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
typedef void delegate(System_VarDictionaryEnumerator_init)(System_VarDictionaryEnumerator that, System_VarDictionary array);
typedef System_Var delegate(System_VarDictionaryEnumerator_get_current)(System_VarDictionaryEnumerator that);
typedef System_Bool delegate(System_VarDictionaryEnumerator_moveNext)(System_VarDictionaryEnumerator that);

export System_VarDictionaryEnumerator  new_System_VarDictionaryEnumerator(System_VarDictionary array);
export void  base_System_VarDictionaryEnumerator_init(System_VarDictionaryEnumerator that, System_VarDictionary array);
export void  base_System_VarDictionaryEnumerator_free(System_VarDictionaryEnumerator that);
export System_Var  base_System_VarDictionaryEnumerator_get_current(System_VarDictionaryEnumerator that);
export System_Bool  base_System_VarDictionaryEnumerator_moveNext(System_VarDictionaryEnumerator that);

#define System_VarDictionaryEnumerator_init(o,...)  ((function_System_VarDictionaryEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_VarDictionaryEnumerator_init))(o,__VA_ARGS__)
#define System_VarDictionaryEnumerator_free(o)  ((function_System_VarDictionaryEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_VarDictionaryEnumerator_get_current(o)  ((function_System_VarDictionaryEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_VarDictionaryEnumerator_moveNext(o)  ((function_System_VarDictionaryEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define VarDictionaryEnumerator  System_VarDictionaryEnumerator
#define VarDictionaryEnumeratorType  System_VarDictionaryEnumeratorType
#define function_VarDictionaryEnumerator_init  function_System_VarDictionaryEnumerator_init
#define function_VarDictionaryEnumerator_free  function_System_VarDictionaryEnumerator_free
#define base_VarDictionaryEnumerator_init  base_System_VarDictionaryEnumerator_init
#define base_VarDictionaryEnumerator_free  base_System_VarDictionaryEnumerator_free
#define VarDictionaryEnumerator_init  System_VarDictionaryEnumerator_init
#define VarDictionaryEnumerator_free  System_VarDictionaryEnumerator_free
#endif
#endif
