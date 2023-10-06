/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Directory)
#define have_System_Directory

export struct System_Type  System_DirectoryType;

export System_Bool System_Directory_exists(System_String8 name);
export System_String8 System_Directory_get_current();
export System_Bool System_Directory_change(System_String8 path);

#if defined(using_System)
#define Directory  System_Directory
#define DirectoryType  System_DirectoryType
#endif
#endif
