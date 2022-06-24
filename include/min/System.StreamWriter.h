/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_auto_System_StreamWriter)
#define have_auto_System_StreamWriter

#define struct_System_StreamWriter  struct class_System_StreamWriter
typedef __fixed struct_System_StreamWriter {
    struct_System_Object base;

    System_IStream stream;

}  * System_StreamWriter;

#define stack_System_StreamWriter()  (struct_System_StreamWriter){ .base = stack_System_Object(System_StreamWriter), }

__export struct_System_Type  System_StreamWriterType;

typedef System_StreamWriter __delegate(System_StreamWriter_init)(System_StreamWriter that, System_IStream stream);
typedef System_void __delegate(System_StreamWriter_free)(System_StreamWriter that);
typedef System_void __delegate(System_StreamWriter_write)(System_StreamWriter that, System_string8 format, ...);

__export System_StreamWriter  System_StreamWriter_new(System_IStream stream);
__export System_StreamWriter  base_System_StreamWriter_init(System_StreamWriter that, System_IStream stream);
__export System_void  base_System_StreamWriter_free(System_StreamWriter that);
__export System_void  base_System_StreamWriter_write(System_StreamWriter that, System_string8 format, ...);

#define System_StreamWriter_init(o,...)  ((function_System_StreamWriter_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_StreamWriter_init))(o, __VA_ARGS__)
#define System_StreamWriter_free(o)  ((function_System_StreamWriter_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_StreamWriter_write(o,...)  ((function_System_StreamWriter_write)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_StreamWriter_write))(o, __VA_ARGS__)

#define inline_System_StreamWriter_new(stream)  (base_System_StreamWriter_init(inline_System_Object_allocClass(System_StreamWriter), stream))

#if defined(using_System)
#define struct_StreamWriter  struct_System_StreamWriter
#define __StreamWriter  System_StreamWriter
#define __StreamWriterType  System_StreamWriterType
#define __StreamWriter_new  System_StreamWriter_new
#define __StreamWriter_init  System_StreamWriter_init
#define __StreamWriter_free  System_StreamWriter_free
#define __StreamWriter_write  System_StreamWriter_write
#define base_StreamWriter_init  base_System_StreamWriter_init
#define base_StreamWriter_free  base_System_StreamWriter_free
#define base_StreamWriter_write  base_System_StreamWriter_write
#define function_StreamWriter_init  function_System_StreamWriter_init
#define function_StreamWriter_free  function_System_StreamWriter_free
#define function_StreamWriter_write  function_System_StreamWriter_write
#endif
#endif
