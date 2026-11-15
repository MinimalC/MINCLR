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
#if !defined(have_System_HashTable)
#define have_System_HashTable

enum { System_HashTable_Capacity = 64 };

typedef System_fixed struct System_HashTableItem {

    System_UInt64 hash;

    System_Var value;

} * System_HashTableItem;

typedef System_fixed struct System_HashTable {
    struct System_Object base;

    System_Size  length;

    System_Size capacity;
    
    struct System_HashTableItem (* items)[];

}  * System_HashTable;

export struct System_Type  System_HashTableType;

weak struct System_HashTable System_TypeTable;

export System_HashTable  new_System_HashTable();
export void  System_HashTable_init(System_HashTable that);
export void  System_HashTable_free(System_HashTable that);
export System_Size System_HashTable_add(System_HashTable that, System_String8 key, System_Var value);
export System_Size  System_HashTable_get_Length(System_HashTable that);
export System_Var  System_HashTable_get_index(System_HashTable that, System_Size index);
export System_Size  System_HashTable_get_key(System_HashTable that, System_String8 key);
export System_Var  System_HashTable_get_value(System_HashTable that, System_String8 key);
export void  System_HashTable_set_index(System_HashTable that, System_Size index, System_Var value);
export void  System_HashTable_set_value(System_HashTable that, System_String8 key, System_Var value);
export void  System_HashTable_copyTo(System_HashTable that, System_HashTable other, System_Size offset);
export void  System_HashTable_resize(System_HashTable that, System_Size length);
export void  System_HashTable_remove(System_HashTable that, System_String8 key);
export System_Bool  System_HashTable_containsKey(System_HashTable that, System_String8 key);
export System_IEnumerator  System_HashTable_getEnumerator(System_HashTable that);

#if defined(using_System)
#define HashTable  System_HashTable
#define HashTableType  System_HashTableType
#define new_HashTable  new_System_HashTable
#define HashTable_init  System_HashTable_init
#define HashTable_free  System_HashTable_free
#define HashTable_add  System_HashTable_add
#define HashTable_get_Length  System_HashTable_get_Length
#define HashTable_get_index  System_HashTable_get_index
#define HashTable_set_index  System_HashTable_set_index
#define HashTable_resize  System_HashTable_resize
#define HashTable_remove  System_HashTable_remove
#define HashTable_getEnumerator  System_HashTable_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_HashTableEnumerator)
#define have_System_HashTableEnumerator


typedef System_fixed struct System_HashTableEnumerator {
    struct System_Object base;

    System_HashTable array;

    System_Size index;

}  * System_HashTableEnumerator;

export struct System_Type  System_HashTableEnumeratorType;

typedef void delegate(System_HashTableEnumerator_free)(System_HashTableEnumerator that);
typedef void delegate(System_HashTableEnumerator_init)(System_HashTableEnumerator that, System_HashTable array);
typedef System_Var delegate(System_HashTableEnumerator_get_current)(System_HashTableEnumerator that);
typedef System_Bool delegate(System_HashTableEnumerator_moveNext)(System_HashTableEnumerator that);

export System_HashTableEnumerator  new_System_HashTableEnumerator(System_HashTable array);
export void  base_System_HashTableEnumerator_init(System_HashTableEnumerator that, System_HashTable array);
export void  base_System_HashTableEnumerator_free(System_HashTableEnumerator that);
export System_Var  base_System_HashTableEnumerator_get_current(System_HashTableEnumerator that);
export System_Bool  base_System_HashTableEnumerator_moveNext(System_HashTableEnumerator that);

#define System_HashTableEnumerator_init(o,...)  ((function_System_HashTableEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_HashTableEnumerator_init))(o,__VA_ARGS__)
#define System_HashTableEnumerator_free(o)  ((function_System_HashTableEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_HashTableEnumerator_get_current(o)  ((function_System_HashTableEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_HashTableEnumerator_moveNext(o)  ((function_System_HashTableEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define HashTableEnumerator  System_HashTableEnumerator
#define HashTableEnumeratorType  System_HashTableEnumeratorType
#define function_HashTableEnumerator_init  function_System_HashTableEnumerator_init
#define function_HashTableEnumerator_free  function_System_HashTableEnumerator_free
#define base_HashTableEnumerator_init  base_System_HashTableEnumerator_init
#define base_HashTableEnumerator_free  base_System_HashTableEnumerator_free
#define HashTableEnumerator_init  System_HashTableEnumerator_init
#define HashTableEnumerator_free  System_HashTableEnumerator_free
#endif
#endif
