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

typedef System_fixed struct System_DirectoryEntry {

    System_IntPtr inode;
    
    System_Char8 type;

    System_String8 name;

}  * System_DirectoryEntry;

export struct System_Type  System_DirectoryEntryType;

typedef System_fixed struct System_DirectoryEntryArray {
	struct System_Object base;

	System_Size  length;

	struct System_DirectoryEntry  (* value)[];

}  * System_DirectoryEntryArray;

export struct System_Type  System_DirectoryEntryArrayType;

export System_Bool System_Directory_exists(System_String8 name);
export System_Bool System_Directory_change(System_String8 path);
export System_Bool System_Directory_create(System_String8 directoryName);
export System_String8 System_Directory_get_current();

export System_Directory  new_System_Directory();
export System_Directory  System_Directory_open(System_String8 directoryName);
export System_Bool  stack_System_Directory_open(System_Directory that, System_String8 directoryName);
export System_SSize  System_DirectoryEntry_alphacompare(System_DirectoryEntry memory0, System_DirectoryEntry memory1, System_Size itemSize);
export System_DirectoryEntryArray  System_Directory_list(System_Directory that);
export void  System_Directory_close(System_Directory that);
export void  System_Directory_free(System_Directory that);

#if defined(using_System)
#define Directory  System_Directory
#define DirectoryType  System_DirectoryType
#define DirectoryEntry  System_DirectoryEntry
#define DirectoryEntryType  System_DirectoryEntryType
#define DirectoryEntryArray  System_DirectoryEntryArray
#define DirectoryEntryArrayType  System_DirectoryEntryArrayType

#define Directory_exists  System_Directory_exists
#define Directory_change  System_Directory_change
#define Directory_create  System_Directory_create
#define Directory_get_current  System_Directory_get_current
#define new_Directory  new_System_Directory
#define Directory_open  System_Directory_open
#define stack_Directory_open  stack_System_Directory_open
#define DirectoryEntry_alphacompare  System_DirectoryEntry_alphacompare
#define Directory_list  System_Directory_list
#define Directory_close  System_Directory_close
#define Directory_free  System_Directory_free
#endif
#endif
