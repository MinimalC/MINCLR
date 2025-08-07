/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Path)
#define have_System_Path

export struct System_Type  System_PathType;

export System_String8 System_Path_getDirectoryName(System_String8 path);
export System_String8 System_Path_getFileName(System_String8 path);
export System_String8 System_Path_getFileNameExt(System_String8 path);
export System_String8 System_Path_getFileNameNoExt(System_String8 path);
export System_String8 System_Path_combine(System_String8 that, System_String8 other);

#if defined(using_System)
#define PathType  System_PathType
#define Path_getDirectoryName  System_Path_getDirectoryName
#define Path_getFileName  System_Path_getFileName
#define Path_getFileNameExt  System_Path_getFileNameExt
#define Path_getFileNameNoExt  System_Path_getFileNameNoExt
#define Path_combine  System_Path_combine
#endif
#endif
