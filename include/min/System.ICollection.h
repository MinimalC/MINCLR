/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
#if !defined(have_System_ICollection)
#define have_System_ICollection

/* interface System_ICollection */

#define struct_System_ICollection  struct interface_System_ICollection
typedef __fixed  struct_System_ICollection { }  * System_ICollection;

__export struct_System_Type  System_ICollectionType;

typedef System_var  __delegate(System_ICollection_get_index)(System_ICollection that);
typedef System_void  __delegate(System_ICollection_set_index)(System_ICollection that, System_var value);
typedef System_size __delegate(System_ICollection_get_Length)(System_ICollection that);
typedef System_void __delegate(System_ICollection_copyTo)(System_ICollection that, System_ICollection other, System_size offset);

__export System_var  base_System_ICollection_get_index(System_ICollection that);
__export System_void  base_System_ICollection_set_index(System_ICollection that, System_var value);
__export System_size  base_System_ICollection_get_Length(System_ICollection that);
__export System_void  base_System_ICollection_copyTo(System_ICollection that, System_ICollection other, System_size offset);

#define System_ICollection_get_index(o)  ((function_System_ICollection_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), System_ICollection_get_index))(o)
#define System_ICollection_set_index(o,...)  ((function_System_ICollection_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), System_ICollection_set_index))(o, __VA_ARGS__)
#define System_ICollection_get_Length(o)  ((function_System_ICollection_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), System_ICollection_get_Length))(o)
#define System_ICollection_copyTo(o,...)  ((function_System_ICollection_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o, __VA_ARGS__)

#if defined(using_System)
#define struct_ICollection  struct_System_ICollection
#define __ICollection  System_ICollection
#define __ICollectionType  System_ICollectionType

#define function_ICollection_get_index  function_System_ICollection_get_index
#define function_ICollection_set_index  function_System_ICollection_set_index
#define function_ICollection_get_Length  function_System_ICollection_get_Length
#define function_ICollection_copyTo  function_System_ICollection_copyTo
#define base_ICollection_get_index  base_System_ICollection_get_index
#define base_ICollection_set_index  base_System_ICollection_get_index
#define base_ICollection_get_Length  base_System_ICollection_get_Length
#define base_ICollection_copyTo  base_System_ICollection_copyTo
#define __ICollection_get_index  System_ICollection_get_index
#define __ICollection_set_index  System_ICollection_set_index
#define __ICollection_get_Length  System_ICollection_get_Length
#define __ICollection_copyTo  System_ICollection_copyTo
#endif

#endif
