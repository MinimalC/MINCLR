/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IStream)
#include "System.IStream.h"
#endif
#if !defined(have_System_File)
#define have_System_File


typedef System_intptr  System_File_mode;

#define System_File_mode_readOnly                 00
#define System_File_mode_writeOnly                01
#define System_File_mode_readWrite                02
#define System_File_mode_create                 0100
#define System_File_mode_exclusive              0200
#define System_File_mode_noControllingTerminal  0400
#define System_File_mode_truncate              01000
#define System_File_mode_append                02000
#define System_File_mode_nonBlock              04000
#define System_File_mode_dsync                010000
#define System_File_mode_async                020000
#define System_File_mode_direct               040000
#define System_File_mode_LargeFile           0100000
#define System_File_mode_Directory           0200000
#define System_File_mode_nonFollow           0400000
#define System_File_mode_noAccessTime       01000000
#define System_File_mode_closeOnExecute     02000000
#define System_File_mode_sync              (04000000 | System_File_mode_dsync)
#define System_File_mode_Path              010000000
#define System_File_mode_temporary        (020000000 | System_File_mode_Directory)


typedef System_intptr  System_File_permission;

#define System_File_permission_UserRead             0400
#define System_File_permission_UserWrite            0200
#define System_File_permission_UserReadWrite        (System_File_permission_UserRead | System_File_permission_UserWrite)
#define System_File_permission_UserExecute          0100
#define System_File_permission_UserEverything       (System_File_permission_UserRead | System_File_permission_UserWrite | System_File_permission_UserExecute)
#define System_File_permission_GroupRead            (System_File_permission_UserRead >> 3)
#define System_File_permission_GroupWrite           (System_File_permission_UserWrite >> 3)
#define System_File_permission_GroupReadWrite       (System_File_permission_GroupRead | System_File_permission_GroupWrite)
#define System_File_permission_GroupExecute         (System_File_permission_UserExecute >> 3)
#define System_File_permission_GroupEverything      (System_File_permission_GroupRead | System_File_permission_GroupWrite | System_File_permission_GroupExecute)
#define System_File_permission_EverybodyRead        (System_File_permission_GroupRead >> 3)
#define System_File_permission_EverybodyWrite       (System_File_permission_GroupWrite >> 3)
#define System_File_permission_EverybodyReadWrite   (System_File_permission_EverybodyRead | System_File_permission_EverybodyWrite)
#define System_File_permission_EverybodyExecute     (System_File_permission_GroupExecute >> 3)
#define System_File_permission_EverybodyEverything  (System_File_permission_EverybodyRead | System_File_permission_EverybodyWrite | System_File_permission_EverybodyExecute)


typedef System_var  System_File_special;

#define System_File_special_STDIN   ((System_var)0)
#define System_File_special_STDOUT  ((System_var)1)
#define System_File_special_STDERR  ((System_var)2)
#define System_File_special_CurrentWorkingDirectory  ((System_var)-100)


/* class System_File */

#define struct_System_File  struct System_File

typedef fixed struct_System_File {
	struct_System_Object  base;

    System_var filePtr;

    System_size position;

}  * System_File;

export struct_System_Type  System_FileType;

typedef System_File  delegate(System_File_init)(System_File that);
typedef void  delegate(System_File_free)(System_File that);
typedef void  delegate(System_File_write)(System_File that, System_size count, System_string8 value);
typedef void  delegate(System_File_sync)(System_File that);
typedef System_size  delegate(System_File_read)(System_File that, System_size count, System_string8 value);
typedef void  delegate(System_File_seek)(System_File that, System_ssize offset, System_origin origin);
typedef System_intptr  delegate(System_File_get_Position)(System_File that);
typedef void  delegate(System_File_set_Position)(System_File that, System_size value);

export System_File  System_File_open(System_string8 filename, System_File_mode flags);
export System_File  base_System_File_init(System_File that);
export void  base_System_File_free(System_File that);
export void  base_System_File_write(System_File that, System_size count, System_string8 value);
export void  base_System_File_sync(System_File that);
export void  base_System_File_seek(System_File that, System_ssize offset, System_origin origin);
export System_size  base_System_File_read(System_File that, System_size count, System_string8 value);
export System_intptr  base_System_File_get_Position(System_File that);
export void  base_System_File_set_Position(System_File that, System_size value);

#define System_File_free(o)  ((function_System_File_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_File_init(o)  ((function_System_File_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_File_write(o,...)  ((function_System_File_write)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_write))(o, __VA_ARGS__)
#define System_File_sync(o)  ((function_System_File_sync)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_sync))(o)
#define System_File_read(o,...)  ((function_System_File_read)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_read))(o, __VA_ARGS__)
#define System_File_seek(o,...)  ((function_System_File_seek)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_seek))(o, __VA_ARGS__)
#define System_File_get_Position(o)  ((function_System_File_get_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_get_Position))(o)
#define System_File_set_Position(o,...)  ((function_System_File_set_Position)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IStream_set_Position))(o, __VA_ARGS__)

#define new_System_File()  (base_System_File_init((System_File)System_Memory_allocClass(typeof(System_File))))

#if defined(using_System)
#define File_mode  System_File_mode
#define File_mode_readOnly  System_File_mode_readOnly
#define File_mode_writeOnly  System_File_mode_writeOnly
#define File_mode_readWrite  System_File_mode_readWrite
#define File_mode_create  System_File_mode_create
#define File_mode_append  System_File_mode_append
#define File_mode_exclusive  System_File_mode_exclusive
#define File_mode_direct  System_File_mode_direct
#define File_mode_Directory  System_File_mode_Directory
#define File_mode_closeOnExecute  System_File_mode_closeOnExecute
#define File_mode_syncd  System_File_mode_syncd

#define File_special  System_File_special
#define File_special_STDIN  System_File_special_STDIN
#define File_special_STDOUT  System_File_special_STDOUT
#define File_special_STDERR  System_File_special_STDERR

#define struct_File  struct_System_File
#define File  System_File
#define FileType  System_FileType

#define File_free  System_File_free
#define File_init  System_File_init
#define new_File  System_File
#define File_open  System_File_open
#define File_read  System_File_read
#define File_write  System_File_write
#define File_seek  System_File_seek
#define File_get_Position  System_File_get_Position
#define File_set_Position  System_File_set_Position
#define File_sync  System_File_sync

#define base_File_free  base_System_File_free
#define base_File_init  base_System_File_init
#define base_File_read  base_System_File_read
#define base_File_write  base_System_File_write
#define base_File_seek  base_System_File_seek
#define base_File_get_Position  base_System_File_get_Position
#define base_File_set_Position  base_System_File_set_Position
#define base_File_sync  base_System_File_sync
#endif


#endif
