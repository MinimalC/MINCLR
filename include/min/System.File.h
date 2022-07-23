/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IStream)
#include "System.IStream.h"
#endif
#if !defined(have_System_FileInfo)
#include "System.FileInfo.h"
#endif
#if !defined(have_System_File)
#define have_System_File


typedef System_IntPtr  System_File_Mode;

#define System_File_Mode_readOnly                 00
#define System_File_Mode_writeOnly                01
#define System_File_Mode_readWrite                02
#define System_File_Mode_create                 0100
#define System_File_Mode_exclusive              0200
#define System_File_Mode_noControllingTerminal  0400
#define System_File_Mode_truncate              01000
#define System_File_Mode_append                02000
#define System_File_Mode_nonBlock              04000
#define System_File_Mode_dsync                010000
#define System_File_Mode_async                020000
#define System_File_Mode_direct               040000
#define System_File_Mode_LargeFile           0100000
#define System_File_Mode_Directory           0200000
#define System_File_Mode_nonFollow           0400000
#define System_File_Mode_noAccessTime       01000000
#define System_File_Mode_closeOnExecute     02000000
#define System_File_Mode_sync              (04000000 | System_File_Mode_dsync)
#define System_File_Mode_Path              010000000
#define System_File_Mode_temporary        (020000000 | System_File_Mode_Directory)


typedef System_IntPtr  System_File_Permission;

#define System_File_Permission_UserRead             0400
#define System_File_Permission_UserWrite            0200
#define System_File_Permission_UserReadWrite        (System_File_Permission_UserRead | System_File_Permission_UserWrite)
#define System_File_Permission_UserExecute          0100
#define System_File_Permission_UserEverything       (System_File_Permission_UserRead | System_File_Permission_UserWrite | System_File_Permission_UserExecute)
#define System_File_Permission_GroupRead            (System_File_Permission_UserRead >> 3)
#define System_File_Permission_GroupWrite           (System_File_Permission_UserWrite >> 3)
#define System_File_Permission_GroupReadWrite       (System_File_Permission_GroupRead | System_File_Permission_GroupWrite)
#define System_File_Permission_GroupExecute         (System_File_Permission_UserExecute >> 3)
#define System_File_Permission_GroupEverything      (System_File_Permission_GroupRead | System_File_Permission_GroupWrite | System_File_Permission_GroupExecute)
#define System_File_Permission_EverybodyRead        (System_File_Permission_GroupRead >> 3)
#define System_File_Permission_EverybodyWrite       (System_File_Permission_GroupWrite >> 3)
#define System_File_Permission_EverybodyReadWrite   (System_File_Permission_EverybodyRead | System_File_Permission_EverybodyWrite)
#define System_File_Permission_EverybodyExecute     (System_File_Permission_GroupExecute >> 3)
#define System_File_Permission_EverybodyEverything  (System_File_Permission_EverybodyRead | System_File_Permission_EverybodyWrite | System_File_Permission_EverybodyExecute)


typedef fixed struct System_File {
	struct System_Object  base;

    System_Var filePtr;

    System_FileInfo info;

    System_Size position;

}  * System_File;

export struct System_Type  System_FileType;

typedef System_File  delegate(System_File_init)(System_File that);
typedef void  delegate(System_File_free)(System_File that);
typedef void  delegate(System_File_write__string_size)(System_File that, System_String8 value, System_Size count);
typedef void  delegate(System_File_sync)(System_File that);
typedef System_Size  delegate(System_File_read)(System_File that, System_String8 value, System_Size count);
typedef void  delegate(System_File_seek)(System_File that, System_SSize offset, System_origin origin);
typedef System_IntPtr  delegate(System_File_get_Position)(System_File that);
typedef void  delegate(System_File_set_Position)(System_File that, System_Size value);

export System_File  System_File_open(System_String8 filename, System_File_Mode flags);
export System_File  base_System_File_init(System_File that);
export void  base_System_File_free(System_File that);
export void  base_System_File_write__string_size(System_File that, System_String8 value, System_Size count);
export void  base_System_File_sync(System_File that);
export void  base_System_File_seek(System_File that, System_SSize offset, System_origin origin);
export System_Size  base_System_File_read(System_File that, System_String8 value, System_Size count);
export System_IntPtr  base_System_File_get_Position(System_File that);
export void  base_System_File_set_Position(System_File that, System_Size value);

#define System_File_free(o)  ((function_System_File_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_File_init(o)  ((function_System_File_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_File_write__string_size(o,...)  ((function_System_File_write__string_size)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_write__string_size))(o, __VA_ARGS__)
#define System_File_sync(o)  ((function_System_File_sync)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_sync))(o)
#define System_File_read(o,...)  ((function_System_File_read)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_read))(o, __VA_ARGS__)
#define System_File_seek(o,...)  ((function_System_File_seek)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_seek))(o, __VA_ARGS__)
#define System_File_get_Position(o)  ((function_System_File_get_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_get_Position))(o)
#define System_File_set_Position(o,...)  ((function_System_File_set_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_set_Position))(o, __VA_ARGS__)

#define stack_System_File() { .base = stack_System_Object(System_File) }
#define new_System_File()  (base_System_File_init((System_File)System_Memory_allocClass(typeof(System_File))))

#if defined(using_System)
#define File_Mode  System_File_Mode
#define File_Mode_readOnly  System_File_Mode_readOnly
#define File_Mode_writeOnly  System_File_Mode_writeOnly
#define File_Mode_readWrite  System_File_Mode_readWrite
#define File_Mode_create  System_File_Mode_create
#define File_Mode_append  System_File_Mode_append
#define File_Mode_exclusive  System_File_Mode_exclusive
#define File_Mode_direct  System_File_Mode_direct
#define File_Mode_Directory  System_File_Mode_Directory
#define File_Mode_closeOnExecute  System_File_Mode_closeOnExecute
#define File_Mode_syncd  System_File_Mode_syncd

#define Syscall_StandardFile  System_Syscall_StandardFile
#define Syscall_StandardFile_STDIN  System_Syscall_StandardFile_STDIN
#define Syscall_StandardFile_STDOUT  System_Syscall_StandardFile_STDOUT
#define Syscall_StandardFile_STDERR  System_Syscall_StandardFile_STDERR


#define File  System_File
#define FileType  System_FileType

#define new_File  new_System_File

#define File_free  System_File_free
#define File_init  System_File_init
#define File_open  System_File_open
#define File_read  System_File_read
#define File_write__string_size  System_File_write__string_size
#define File_seek  System_File_seek
#define File_get_Position  System_File_get_Position
#define File_set_Position  System_File_set_Position
#define File_sync  System_File_sync

#define base_File_free  base_System_File_free
#define base_File_init  base_System_File_init
#define base_File_read  base_System_File_read
#define base_File_write__string_size  base_System_File_write__string_size
#define base_File_seek  base_System_File_seek
#define base_File_get_Position  base_System_File_get_Position
#define base_File_set_Position  base_System_File_set_Position
#define base_File_sync  base_System_File_sync
#endif


#endif
