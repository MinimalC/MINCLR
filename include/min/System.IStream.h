/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IStream)
#define have_System_IStream

typedef System_intptr  System_origin;
#define System_origin_Begin  0
#define System_origin_Current  1
#define System_origin_End  2

#if defined(using_System)
#define origin  System_origin
#define origin_Begin  System_origin_Begin
#define origin_Current  System_origin_Current
#define origin_End  System_origin_End
#endif

/* interface System.IStream */


typedef fixed struct System_IStream { } * System_IStream;

export struct System_Type  System_IStreamType;

export void  System_IStream_format(System_IStream stream, System_string8 format, ...);
export void  System_IStream_formatLine(System_IStream stream, System_string8 format, ...);
export void  System_IStream_formatEnd(System_IStream stream, System_string8 format, System_char8 suffix, ...);
export void  System_IStream_formatEnd__arguments(System_IStream stream, System_string8 format, System_char8 suffix, System_size argc, System_var argv[]);

typedef void  delegate(System_IStream_write)(System_IStream that, System_size count, System_string8 value);
typedef void  delegate(System_IStream_sync)(System_IStream that);
typedef System_size  delegate(System_IStream_read)(System_IStream that, System_size count, System_string8 value);
typedef void  delegate(System_IStream_seek)(System_IStream that, System_ssize offset, System_origin origin);
typedef System_intptr  delegate(System_IStream_get_Position)(System_IStream that);
typedef void  delegate(System_IStream_set_Position)(System_IStream that, System_size value);

export void  base_System_IStream_write(System_IStream that, System_size count, System_string8 value);
export void  base_System_IStream_sync(System_IStream that);
export System_size  base_System_IStream_read(System_IStream that, System_size count, System_string8 value);
export void  base_System_IStream_seek(System_IStream that, System_ssize offset, System_origin origin);
export System_intptr  base_System_IStream_get_Position(System_IStream that);
export void  base_System_IStream_set_Position(System_IStream that, System_size value);

#define System_IStream_write(o,...)  ((function_System_IStream_write)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_write))(o, __VA_ARGS__)
#define System_IStream_sync(o)      ((function_System_IStream_sync)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_sync))(o)
#define System_IStream_read(o,...)  ((function_System_IStream_read)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_read))(o, __VA_ARGS__)
#define System_IStream_seek(o,...)  ((function_System_IStream_seek)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_seek))(o, __VA_ARGS__)
#define System_IStream_get_Position(o)      ((function_System_IStream_get_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_get_Position))(o)
#define System_IStream_set_Position(o,...)  ((function_System_IStream_set_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_set_Position))(o, __VA_ARGS__)

#if defined(using_System)
#define IStream  System_IStream
#define IStreamType  System_IStreamType

#define IStream_format  System_IStream_format
#define IStream_formatLine  System_IStream_formatLine
#define IStream_formatEnd  System_IStream_formatEnd
#define IStream_formatEnd__arguments  System_IStream_formatEnd__arguments

#define IStream_write  System_IStream_write
#define IStream_sync  System_IStream_sync
#define IStream_read  System_IStream_read
#define IStream_seek  System_IStream_seek
#define IStream_get_Position  System_IStream_get_Position
#define IStream_set_Position  System_IStream_set_Position
#endif
#endif