/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Path)
#define have_System_Path

export struct System_Type  System_PathType;

export System_String8 System_Path_getDirectoryName(System_String8 path);
export System_String8 System_Path_getFileName(System_String8 path);
export System_String8 System_Path_getFileExtension(System_String8 path);
export System_String8 System_Path_combine(System_String8 that, System_String8 other);

#endif
