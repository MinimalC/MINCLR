/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Path)
#include <min/System.Path.h>
#endif
#if !defined(code_System_Path)
#define code_System_Path

/*# System_Path #*/

struct System_Type System_PathType = { .base = stack_System_Object(System_Type),
    .name = "Path",
};

System_String8 System_Path_getDirectoryName(System_String8 path) {
    Size i = System_String8_lastIndexOf(path, '/');
    if (i == -1) return System_String8_Empty;
    return System_String8_copySubstring(path, i);
}

System_String8 System_Path_getFileName(System_String8 path) {
    Size i = System_String8_lastIndexOf(path, '/');
    if (i == -1) return path; /* TODO: Memory_addReference? */
    return System_String8_copyFrom(path, i);
}

#endif
