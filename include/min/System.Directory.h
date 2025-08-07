/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Directory)
#define have_System_Directory

typedef System_fixed struct System_Directory {
	struct System_Object  base;

    System_IntPtr dirId;
    
    System_String8 name;

}  * System_Directory;

export struct System_Type  System_DirectoryType;

export System_Bool System_Directory_exists(System_String8 name);
export System_Bool System_Directory_change(System_String8 path);
export System_Bool System_Directory_create(System_String8 directoryName);
export System_String8 System_Directory_get_current();

export System_Directory  new_System_Directory();
export System_Directory  System_Directory_open(System_String8 filename, System_File_Mode flags);
export System_Bool  stack_System_Directory_open(System_Directory that, System_String8 dirName, System_File_Mode flags);
export void  System_Directory_close(System_Directory that);
export void  System_Directory_free(System_Directory that);

#if defined(using_System)
#define Directory  System_Directory
#define DirectoryType  System_DirectoryType

#define new_Directory  new_System_Directory
#define Directory_exists  System_Directory_exists
#define Directory_get_current  System_Directory_get_current
#define Directory_get_TemporaryDirectory  System_Directory_get_TemporaryDirectory
#define Directory_change  System_Directory_change
#define Directory_create  System_Directory_create
#endif
#endif
