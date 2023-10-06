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

struct System_Type System_PathType = { .base = { .type = typeof(System_Type) }, .name = "Path" };

System_String8 System_Path_getDirectoryName(System_String8 path) {
    Size i = System_String8_lastIndexOf(path, '/');
    if (i == -1) return null;
    return System_String8_copySubstring(path, i + 1);
}

System_String8 System_Path_getFileName(System_String8 path) {
    Size i = System_String8_lastIndexOf(path, '/');
    if (i == -1) return null;
    return System_String8_copyOf(path, i + 1);
}

System_String8 System_Path_getFileExtension(System_String8 path) {
    Size i = System_String8_lastIndexOf(path, '.');
    if (i == -1) return null;
    return System_String8_copyOf(path, i + 1);
}

System_String8 System_Path_combine(System_String8 that, System_String8 other) {
    System_Size thatL = System_String8_get_Length(that);
    System_Size otherL = System_String8_get_Length(other);
    System_String8 path = System_Memory_allocArray(typeof(System_Char8), thatL + 1 + otherL + 1);
    System_String8_copyTo(that, path);
    *(path + thatL) = '/';
    System_String8_copyToAt(other, path, thatL + 1);
    System_String8Array split = System_String8_split(path, '/');
    System_Memory_free(path);
    System_String8 last = null, item = null;
    System_Size itemL = 0;
    for (Size i = 0; i < split->length; ++i) {
        item = array(split->value)[i];
        itemL = System_String8_get_Length(item);
        if (i == 0) {
            if (itemL == 0) continue;
            if (itemL == 1 && *item == '.') continue;
            if (String8_equals(item, "..")) continue;
            continue;
        }
        if (itemL == 0 && i < split->length - 1) {
            base_System_String8Array_remove(split, i--);
            continue;
        }
        if (itemL == 1 && *item == '.') {
            base_System_String8Array_remove(split, i--);
            continue;
        }
        if (String8_equals(item, "..")) {
            last = array(split->value)[i - 1];
            if (!String8_equals(last, "..")) {
                base_System_String8Array_remove(split, i--);
                base_System_String8Array_remove(split, i--);
            }
            continue;
        }
    }
    String8 reture = System_Char8_join('/', split);
    System_Memory_free(split);
    return reture;
}

#endif
