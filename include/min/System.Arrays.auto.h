/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include "System.h"
#endif
#if !defined(have_System_String)
#warning "System.String.h not included"
#include "System.String.h"
#endif
#if !defined(have_auto_System_StringArray)
#define have_auto_System_StringArray

#define struct_System_StringArray  struct class_System_StringArray
typedef __fixed struct_System_StringArray {
    struct_System_Array base;

}  * System_StringArray;

__export struct_System_Type  System_StringArrayType;

#define System_StringArray_new(__length)  (base_System_Array_init(__null, __length))
#define System_StringArray_init(o,...)  ((function_System_Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_init))(o, __VA_ARGS__)
#define System_StringArray_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_StringArray_get_Length(o)  ((function_System_Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_StringArray_copyTo(o,...)  ((function_System_Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_StringArray_get_index(o,...)  ((function_System_Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_StringArray_set_index(o,...)  ((function_System_Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_StringArray_resize(o,...)  ((function_System_Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_resize))(o,__VA_ARGS__)

#if defined(using_System)
#define struct_StringArray  struct class_System_StringArray
#define __StringArray  System_StringArray
#define __StringArrayType  System_StringArrayType
#define __StringArray_new  System_StringArray_new

#define __StringArray_init  System_StringArray_init
#define __StringArray_free  System_StringArray_free
#define __StringArray_get_Length  System_StringArray_get_Length
#define __StringArray_get_index  System_StringArray_get_index
#define __StringArray_set_index  System_StringArray_set_index
#define __StringArray_resize  System_StringArray_resize
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include "System.h"
#endif
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
#if !defined(have_auto_System_TypeArray)
#define have_auto_System_TypeArray

#define struct_System_TypeArray  struct class_System_TypeArray
typedef __fixed struct_System_TypeArray {
    struct_System_Array base;

}  * System_TypeArray;

__export struct_System_Type  System_TypeArrayType;

#define System_TypeArray_new(__length)  (base_System_Array_init(__null, __length))
#define System_TypeArray_init(o,...)  ((function_System_Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_init))(o, __VA_ARGS__)
#define System_TypeArray_free(o)  ((function_System_Object_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_TypeArray_get_Length(o)  ((function_System_Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_TypeArray_copyTo(o,...)  ((function_System_Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_TypeArray_get_index(o,...)  ((function_System_Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_TypeArray_set_index(o,...)  ((function_System_Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_TypeArray_resize(o,...)  ((function_System_Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Array_resize))(o,__VA_ARGS__)

#if defined(using_System)
#define struct_TypeArray  struct class_System_TypeArray
#define __TypeArray  System_TypeArray
#define __TypeArrayType  System_TypeArrayType
#define __TypeArray_new  System_TypeArray_new

#define __TypeArray_init  System_TypeArray_init
#define __TypeArray_free  System_TypeArray_free
#define __TypeArray_get_Length  System_TypeArray_get_Length
#define __TypeArray_get_index  System_TypeArray_get_index
#define __TypeArray_set_index  System_TypeArray_set_index
#define __TypeArray_resize  System_TypeArray_resize
#endif

#endif
