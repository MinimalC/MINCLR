/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
#if !defined(have_System_String)
#define have_System_String


/* static class System_String */

__export struct_System_Type  System_StringType;

/* class System.String */

typedef System_String __delegate(System_String_init)(System_String, System_string8);
typedef System_void __delegate(System_String_free)(System_String that);
typedef System_uint64 __delegate(System_String_getSipHash)(System_String that);

__export System_String  System_String_new(System_string8);
__export System_String  base_System_String_init(System_String, System_string8);
__export System_void  base_System_String_free(System_String);
__export System_uint64  base_System_String_getSipHash(System_String that);

#define System_String_init(o,...)  ((function_System_String_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_String_init))(o, __VA_ARGS__)
#define System_String_free(o)  ((function_System_String_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_String_getSipHash(o)  ((function_System_String_getSipHash)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_getSipHash))(o)

#define inline_System_String_new(s)  (base_System_String_init(inline_System_Object_allocClass(System_String), s))


#if __UNICODE == 32
#define System_stringType  System_string32Type

#elif __UNICODE == 16
#define System_stringType  System_string16Type

#else /* if __UNICODE == 8 */
#define System_stringType  System_string8Type
#endif

#if defined(using_System)
#define enum_byteOrder  enum_System_byteOrder
#define __byteOrder_LittleEndian  System_byteOrder_LittleEndian
#define __byteOrder_BigEndian  System_byteOrder_BigEndian
#define __byteOrder_NATIVE  System_byteOrder_NATIVE

#define enum_encoding  enum_System_encoding
#define __encoding_UTF8  System_encoding_UTF8
#define __encoding_UTF16  System_encoding_UTF16
#define __encoding_UTF32  System_encoding_UTF32
#define __encoding_DEFAULT  System_encoding_DEFAULT

#define __string8Type  System_string8Type
#define __string16Type  System_string16Type
#define __string32Type  System_string32Type
#define __stringType  System_stringType

#define struct_String  struct_System_String
#define stack_String  stack_System_String
#define __String  System_String
#define __StringType  System_StringType

#define stack_String32  stack_System_String32
#define stack_String16  stack_System_String16
#define stack_String8  stack_System_String8

#define function_String_init  function_System_String_init
#define base_String_free  base_System_String_free
#define base_String_init  base_System_String_init
#define base_String_getSipHash  base_System_String_getSipHash
#define __String_new  System_String_new
#define __String_init  System_String_init
#define __String_free  System_String_free
#define __String_getSipHash  System_String_getSipHash
#endif

#endif
