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
enum {
    System_File_Mode_readOnly                 = 00,
    System_File_Mode_writeOnly                = 01,
    System_File_Mode_readWrite                = 02,
    System_File_Mode_create                 = 0100,
    System_File_Mode_exclusive              = 0200,
    System_File_Mode_noControllingTerminal  = 0400,
    System_File_Mode_truncate              = 01000,
    System_File_Mode_append                = 02000,
    System_File_Mode_nonBlock              = 04000,
    System_File_Mode_dsync                = 010000,
    System_File_Mode_async                = 020000,
    System_File_Mode_direct               = 040000,
    System_File_Mode_LargeFile           = 0100000,
    System_File_Mode_Directory           = 0200000,
    System_File_Mode_nonFollow           = 0400000,
    System_File_Mode_noAccessTime       = 01000000,
    System_File_Mode_closeOnExecute     = 02000000,
    System_File_Mode_sync              = (04000000 | System_File_Mode_dsync),
    System_File_Mode_Path              = 010000000,
    System_File_Mode_temporary        = (020000000 | System_File_Mode_Directory),
};

typedef System_IntPtr  System_File_Permission;
enum {
    System_File_Permission_UserRead             = 0400,
    System_File_Permission_UserWrite            = 0200,
    System_File_Permission_UserReadWrite        = (System_File_Permission_UserRead | System_File_Permission_UserWrite),
    System_File_Permission_UserExecute          = 0100,
    System_File_Permission_UserEverything       = (System_File_Permission_UserRead | System_File_Permission_UserWrite | System_File_Permission_UserExecute),
    System_File_Permission_GroupRead            = (System_File_Permission_UserRead >> 3),
    System_File_Permission_GroupWrite           = (System_File_Permission_UserWrite >> 3),
    System_File_Permission_GroupReadWrite       = (System_File_Permission_GroupRead | System_File_Permission_GroupWrite),
    System_File_Permission_GroupExecute         = (System_File_Permission_UserExecute >> 3),
    System_File_Permission_GroupEverything      = (System_File_Permission_GroupRead | System_File_Permission_GroupWrite | System_File_Permission_GroupExecute),
    System_File_Permission_EverybodyRead        = (System_File_Permission_GroupRead >> 3),
    System_File_Permission_EverybodyWrite       = (System_File_Permission_GroupWrite >> 3),
    System_File_Permission_EverybodyReadWrite   = (System_File_Permission_EverybodyRead | System_File_Permission_EverybodyWrite),
    System_File_Permission_EverybodyExecute     = (System_File_Permission_GroupExecute >> 3),
    System_File_Permission_EverybodyEverything  = (System_File_Permission_EverybodyRead | System_File_Permission_EverybodyWrite | System_File_Permission_EverybodyExecute),
};

typedef System_fixed struct System_File {
	struct System_Object  base;

    System_IntPtr fileId;
    
    System_String8 name;

}  * System_File;

export struct System_Type  System_FileType;

export System_Bool  System_File_exists(System_String8 name);
export System_File  System_File_open(System_String8 name, System_File_Mode flags);
export System_Bool  stack_System_File_open(System_File that, System_String8 name, System_File_Mode flags);

export System_File  new_System_File();
export void  System_File_init(System_File that);
export void  System_File_free(System_File that);
export void  System_File_write__string_size(System_File that, System_String8 value, System_Size count);
export void  System_File_write__string(System_File that, System_String8 string);
export void  System_File_write__char(System_File that, System_Char8 character);
export void  System_File_writeLineEmpty(System_File that);
export void  System_File_write(System_File that, System_String8 format, ...);
export void  System_File_writeLine__string(System_File that, System_String8 string);
export void  System_File_writeLine(System_File that, System_String8 format, ...);
export void  System_File_writeEnd__arguments(System_File that, System_String8 format, System_Char8 suffix, System_Size argc, System_Var argv[]);
export void  System_File_sync(System_File that);
export System_Size  System_File_seek(System_File that, System_SSize offset, System_Origin origin);
export System_Size  System_File_read(System_File that, System_String8 value, System_Size count);
export System_Size  System_File_get_Position(System_File that);
export void  System_File_set_Position(System_File that, System_Size value);
export System_Size  System_File_get_Length(System_File that);
export void  System_File_set_Length(System_File that, System_Size value);
export void  System_File_close(System_File that);

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

#define File  System_File
#define FileType  System_FileType
#define File_exists  System_File_exists
#define File_open  System_File_open
#define new_File  new_System_File
#define File_free  System_File_free
#define File_init  System_File_init
#define File_write__string_size  System_File_write__string_size
#define File_write__string  System_File_write__string
#define File_write__char  System_File_write__char
#define File_writeLineEmpty  System_File_writeLineEmpty
#define File_write  System_File_write
#define File_writeLine__string  System_File_writeLine__string
#define File_writeLine  System_File_writeLine
#define File_writeEnd__arguments  System_File_writeEnd__arguments
#define File_sync  System_File_sync
#define File_seek  System_File_seek
#define File_read  System_File_read
#define File_get_Position  System_File_get_Position
#define File_set_Position  System_File_set_Position
#define File_get_Length  System_File_set_Length
#define File_set_Length  System_File_set_Length
#define File_close  System_File_close
#endif
#endif