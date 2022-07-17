/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Dictionary)
#define have_System_Dictionary

/* 3-Dimensional, Unique SipHash-Indexed ObjectObjectDictionary */

#define struct_System_Dictionary  struct System_Dictionary
typedef fixed struct_System_Dictionary {
    struct_System_Object base;

    System_uint64Array hashes;

    System_Array keys;

    System_Array values;

}  * System_Dictionary;

#define stack_System_Dictionary()  (struct_System_Dictionary){ .base = stack_System_Object(System_Dictionary), }

export struct_System_Type  System_DictionaryType;

typedef System_Dictionary delegate(System_Dictionary_init)(System_Dictionary that);
typedef void delegate(System_Dictionary_free)(System_Dictionary that);

#define System_Dictionary_new  System_Dictionary_new__00

export System_Dictionary  System_Dictionary_new();
export System_Dictionary  base_System_Dictionary_init(System_Dictionary that);
/* export void  base_System_Dictionary_free(System_Dictionary that); */

#define System_Dictionary_init(o)  ((function_System_Dictionary_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_Dictionary_free(o)  ((function_System_Dictionary_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define new_System_Dictionary()  (base_System_Dictionary_init((System_Dictionary)System_Memory_allocClass(typeof(System_Dictionary))))

#if !defined(have_System_internal)
#undef  System_Dictionary_new
#define System_Dictionary_new  inline_System_Dictionary_new
#endif

#if defined(using_System)
#define struct_Dictionary  struct_System_Dictionary
#define Dictionary  System_Dictionary
#define DictionaryType  System_DictionaryType
#define function_Dictionary_init  function_System_Dictionary_init
#define function_Dictionary_free  function_System_Dictionary_free
#define base_Dictionary_init  base_System_Dictionary_init
/* #define base_Dictionary_free  base_System_Dictionary_free */
#define Dictionary_new  System_Dictionary_new
#define Dictionary_init  System_Dictionary_init
#define Dictionary_free  System_Dictionary_free
#endif

#endif
