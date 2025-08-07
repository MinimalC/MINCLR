/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IStream)
#define have_System_IStream

typedef System_IntPtr  System_Origin;
enum {
    System_Origin_Begin,
    System_Origin_Current,
    System_Origin_End,
};

#if defined(using_System)
#define Origin  System_Origin
#define Origin_Begin  System_Origin_Begin
#define Origin_Current  System_Origin_Current
#define Origin_End  System_Origin_End
#endif

/* interface System.IStream */

typedef System_fixed struct System_IStream { } * System_IStream;

export struct System_Type  System_IStreamType;

export void  System_IStream_write(System_IStream stream, System_String8 format, ...);
export void  System_IStream_write__arguments(System_IStream stream, System_String8 format, System_Size argc, System_Var argv[]);
export void  System_IStream_writeLine(System_IStream stream, System_String8 format, ...);
export void  System_IStream_writeLine__arguments(System_IStream stream, System_String8 format, System_Size argc, System_Var argv[]);
export void  System_IStream_writeEnd(System_IStream stream, System_String8 format, System_Char8 suffix, ...);

typedef void  delegate(System_IStream_write__string_size)(System_IStream that, System_String8 value, System_Size count);
typedef void  delegate(System_IStream_writeEnd__arguments)(System_IStream stream, System_String8 format, System_Char8 suffix, System_Size argc, System_Var argv[]);
typedef void  delegate(System_IStream_sync)(System_IStream that);
typedef System_Size  delegate(System_IStream_read)(System_IStream that, System_String8 value, System_Size count);
typedef System_Size  delegate(System_IStream_seek)(System_IStream that, System_SSize offset, System_Origin origin);
typedef System_IntPtr  delegate(System_IStream_get_Position)(System_IStream that);
typedef void  delegate(System_IStream_set_Position)(System_IStream that, System_Size value);

export void  base_System_IStream_write__string_size(System_IStream that, System_String8 value, System_Size count);
export void  base_System_IStream_writeEnd__arguments(System_IStream stream, System_String8 format, System_Char8 suffix, System_Size argc, System_Var argv[]);
export void  base_System_IStream_sync(System_IStream that);
export System_Size  base_System_IStream_read(System_IStream that, System_String8 value, System_Size count);
export System_Size  base_System_IStream_seek(System_IStream that, System_SSize offset, System_Origin origin);
export System_IntPtr  base_System_IStream_get_Position(System_IStream that);
export void  base_System_IStream_set_Position(System_IStream that, System_Size value);

#define System_IStream_write__string_size(o,...)  ((function_System_IStream_write__string_size)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_write__string_size))(o, __VA_ARGS__)
#define System_IStream_writeEnd__arguments(o,...)  ((function_System_IStream_writeEnd__arguments)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_write__writeEnd__arguments))(o, __VA_ARGS__)
#define System_IStream_sync(o)      ((function_System_IStream_sync)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_sync))(o)
#define System_IStream_read(o,...)  ((function_System_IStream_read)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_read))(o, __VA_ARGS__)
#define System_IStream_seek(o,...)  ((function_System_IStream_seek)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_seek))(o, __VA_ARGS__)
#define System_IStream_get_Position(o)      ((function_System_IStream_get_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_get_Position))(o)
#define System_IStream_set_Position(o,...)  ((function_System_IStream_set_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_set_Position))(o, __VA_ARGS__)

#if defined(using_System)
#define IStream  System_IStream
#define IStreamType  System_IStreamType

#define IStream_write  System_IStream_write
#define IStream_writeLine  System_IStream_writeLine
#define IStream_writeEnd  System_IStream_writeEnd
#define IStream_writeEnd__arguments  System_IStream_writeEnd__arguments

#define IStream_write__string_size  System_IStream_write__string_size
#define IStream_sync  System_IStream_sync
#define IStream_read  System_IStream_read
#define IStream_seek  System_IStream_seek
#define IStream_get_Position  System_IStream_get_Position
#define IStream_set_Position  System_IStream_set_Position
#endif
#endif