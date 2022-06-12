/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
#if !defined(have_System_IStream)
#define have_System_IStream

typedef System_intptr  enum_System_origin;
#define System_origin_Begin  0
#define System_origin_Current  1
#define System_origin_End  2

#if defined(using_System)
#define enum_origin  enum_System_origin
#define __origin_Begin  System_origin_Begin
#define __origin_Current  System_origin_Current
#define __origin_End  System_origin_End
#endif

/* interface System.IStream */

#define struct_System_IStream  struct class_System_IStream
typedef __fixed struct_System_IStream { } * System_IStream;
__export struct_System_Type  System_IStreamType;

typedef System_void  __delegate(System_IStream_write)(System_IStream that, System_size count, System_string8 value);
typedef System_void  __delegate(System_IStream_sync)(System_IStream that);
typedef System_size  __delegate(System_IStream_read)(System_IStream that, System_size count, System_string8 value);
typedef System_void  __delegate(System_IStream_seek)(System_IStream that, System_ssize offset, enum_System_origin origin);
typedef System_intptr  __delegate(System_IStream_get_Position)(System_IStream that);
typedef System_void  __delegate(System_IStream_set_Position)(System_IStream that, System_size value);

__export System_void  base_System_IStream_write(System_IStream that, System_size count, System_string8 value);
__export System_void  base_System_IStream_sync(System_IStream that);
__export System_size  base_System_IStream_read(System_IStream that, System_size count, System_string8 value);
__export System_void  base_System_IStream_seek(System_IStream that, System_ssize offset, enum_System_origin origin);
__export System_intptr  base_System_IStream_get_Position(System_IStream that);
__export System_void  base_System_IStream_set_Position(System_IStream that, System_size value);

#define System_IStream_write(o,...)  ((function_System_IStream_write)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_write))(o, __VA_ARGS__)
#define System_IStream_sync(o)      ((function_System_IStream_sync)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_sync))(o)
#define System_IStream_read(o,...)  ((function_System_IStream_read)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_read))(o, __VA_ARGS__)
#define System_IStream_seek(o,...)  ((function_System_IStream_seek)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_seek))(o, __VA_ARGS__)
#define System_IStream_get_Position(o)      ((function_System_IStream_get_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_get_Position))(o)
#define System_IStream_set_Position(o,...)  ((function_System_IStream_set_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_set_Position))(o, __VA_ARGS__)

#if defined(using_System)
#define struct_IStream  struct_System_IStream
#define __IStream  System_IStream
#define __IStreamType  System_IStreamType

#define __IStream_write  System_IStream_write
#define __IStream_sync  System_IStream_sync
#define __IStream_read  System_IStream_read
#define __IStream_seek  System_IStream_seek
#define __IStream_get_Position  System_IStream_get_Position
#define __IStream_set_Position  System_IStream_set_Position
#endif


#endif
