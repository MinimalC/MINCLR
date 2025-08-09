/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IStream)
#include "System.IStream.h"
#endif
#if !defined(have_System_MemoryStream)
#define have_System_MemoryStream

enum {
    System_MemoryStream_Capacity = 4096,
};

typedef System_fixed struct System_MemoryStream {
	struct System_Object  base;

    System_String8 buffer;

    System_Size capacity;

    System_Size size;

    System_Size position;

}  * System_MemoryStream;

export struct System_Type  System_MemoryStreamType;

export System_MemoryStream  System_MemoryStream_open();
export System_Bool  stack_System_MemoryStream_open(System_MemoryStream that);

export System_MemoryStream  new_System_MemoryStream();
export void  System_MemoryStream_init(System_MemoryStream that);
export void  System_MemoryStream_free(System_MemoryStream that);
export System_Size  System_MemoryStream_write__string_size(System_MemoryStream that, System_String8 value, System_Size count);
export System_Size  System_MemoryStream_write__string(System_MemoryStream that, System_String8 string);
export System_Size  System_MemoryStream_write__char(System_MemoryStream that, System_Char8 character);
export System_Size  System_MemoryStream_writeLineEmpty(System_MemoryStream that);
export System_Size  System_MemoryStream_write(System_MemoryStream that, System_String8 format, ...);
export System_Size  System_MemoryStream_writeLine__string(System_MemoryStream that, System_String8 string);
export System_Size  System_MemoryStream_writeLine(System_MemoryStream that, System_String8 format, ...);
export System_Size  System_MemoryStream_writeEnd__arguments(System_MemoryStream that, System_String8 format, System_Char8 suffix, System_Size argc, System_Var argv[]);
export void  System_MemoryStream_sync(System_MemoryStream that);
export System_Size  System_MemoryStream_seek(System_MemoryStream that, System_SSize offset, System_Origin origin);
export System_Size  System_MemoryStream_read(System_MemoryStream that, System_String8 value, System_Size count);
export System_Size  System_MemoryStream_get_Position(System_MemoryStream that);
export void  System_MemoryStream_set_Position(System_MemoryStream that, System_Size value);
export System_Size  System_MemoryStream_get_Length(System_MemoryStream that);
export void  System_MemoryStream_set_Length(System_MemoryStream that, System_Size value);
export void  System_MemoryStream_close(System_MemoryStream that);
export System_String8  System_MemoryStream_final(System_MemoryStream that);
export System_String8  System_MemoryStream_snapshot(System_MemoryStream that);

#if defined(using_System)
#define MemoryStream  System_MemoryStream
#define MemoryStreamType  System_MemoryStreamType
#define MemoryStream_exists  System_MemoryStream_exists
#define MemoryStream_open  System_MemoryStream_open
#define new_MemoryStream  new_System_MemoryStream
#define MemoryStream_free  System_MemoryStream_free
#define MemoryStream_init  System_MemoryStream_init
#define MemoryStream_write__string_size  System_MemoryStream_write__string_size
#define MemoryStream_write__string  System_MemoryStream_write__string
#define MemoryStream_write__char  System_MemoryStream_write__char
#define MemoryStream_writeLineEmpty  System_MemoryStream_writeLineEmpty
#define MemoryStream_write  System_MemoryStream_write
#define MemoryStream_writeLine__string  System_MemoryStream_writeLine__string
#define MemoryStream_writeLine  System_MemoryStream_writeLine
#define MemoryStream_writeEnd__arguments  System_MemoryStream_writeEnd__arguments
#define MemoryStream_sync  System_MemoryStream_sync
#define MemoryStream_seek  System_MemoryStream_seek
#define MemoryStream_read  System_MemoryStream_read
#define MemoryStream_get_Position  System_MemoryStream_get_Position
#define MemoryStream_set_Position  System_MemoryStream_set_Position
#define MemoryStream_get_Length  System_MemoryStream_set_Length
#define MemoryStream_set_Length  System_MemoryStream_set_Length
#define MemoryStream_close  System_MemoryStream_close
#define MemoryStream_final  System_MemoryStream_final
#define MemoryStream_snapshot  System_MemoryStream_snapshot
#endif
#endif