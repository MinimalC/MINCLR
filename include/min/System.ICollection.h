/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_ICollection)
#define have_System_ICollection

/* interface System_ICollection */


typedef fixed  struct System_ICollection { }  * System_ICollection;

export struct System_Type  System_ICollectionType;

typedef System_var  delegate(System_ICollection_get_index)(System_ICollection that);
typedef void  delegate(System_ICollection_set_index)(System_ICollection that, System_var value);
typedef System_size delegate(System_ICollection_get_Length)(System_ICollection that);
typedef void delegate(System_ICollection_copyTo)(System_ICollection that, System_ICollection other, System_size offset);

export System_var  base_System_ICollection_get_index(System_ICollection that);
export void  base_System_ICollection_set_index(System_ICollection that, System_var value);
export System_size  base_System_ICollection_get_Length(System_ICollection that);
export void  base_System_ICollection_copyTo(System_ICollection that, System_ICollection other, System_size offset);

#define System_ICollection_get_index(o)  ((function_System_ICollection_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), System_ICollection_get_index))(o)
#define System_ICollection_set_index(o,...)  ((function_System_ICollection_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), System_ICollection_set_index))(o, __VA_ARGS__)
#define System_ICollection_get_Length(o)  ((function_System_ICollection_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), System_ICollection_get_Length))(o)
#define System_ICollection_copyTo(o,...)  ((function_System_ICollection_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o, __VA_ARGS__)

#if defined(using_System)

#define ICollection  System_ICollection
#define ICollectionType  System_ICollectionType

#define function_ICollection_get_index  function_System_ICollection_get_index
#define function_ICollection_set_index  function_System_ICollection_set_index
#define function_ICollection_get_Length  function_System_ICollection_get_Length
#define function_ICollection_copyTo  function_System_ICollection_copyTo
#define base_ICollection_get_index  base_System_ICollection_get_index
#define base_ICollection_set_index  base_System_ICollection_get_index
#define base_ICollection_get_Length  base_System_ICollection_get_Length
#define base_ICollection_copyTo  base_System_ICollection_copyTo
#define ICollection_get_index  System_ICollection_get_index
#define ICollection_set_index  System_ICollection_set_index
#define ICollection_get_Length  System_ICollection_get_Length
#define ICollection_copyTo  System_ICollection_copyTo
#endif

#endif
