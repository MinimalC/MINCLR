/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Path)
#include <min/System.Path.h>
#endif
#if !defined(code_System_Path)
#define code_System_Path

/** struct System_Path  **/

struct System_Type System_PathType = { .base = { .type = typeof(System_Type) }, .name = "Path" };

System_String8 System_Path_getDirectoryName(System_String8 path) {
    SSize i = System_String8_lastIndexOf(path, '/');
    if (i > -1) return System_String8_copySubstring(path, i + 1);
    return String8_Empty;
}

System_String8 System_Path_getFileName(System_String8 path) {
    SSize i = System_String8_lastIndexOf(path, '/');
    if (i > -1) return System_String8_copyOf(path, i + 1);
    return String8_Empty;
}

System_String8 System_Path_getFileNameExt(System_String8 path) {
    SSize i = System_String8_lastIndexOf(path, '.');
    if (i > -1) return System_String8_copyOf(path, i + 1);
    return String8_Empty;
}

System_String8 System_Path_getFileNameNoExt(System_String8 path) {
    SSize i = System_String8_lastIndexOf(path, '.');
    if (i > -1) return System_String8_copySubstring(path, i);
    return String8_Empty;
}

System_String8 System_Path_combine(System_String8 that, System_String8 other) {
    System_Size length0 = System_String8_get_Length(that);
    System_Size length1 = System_String8_get_Length(other);
    Char8 scratch[4096]; Stack_clear(scratch); Size position = 0; Size slash[16]; Stack_clear(slash); Size slashes = 0;
    for (Size c0 = 0; c0 < length0; ++c0) {
        if (that[c0] == '/') {
            if (slashes) {
                if (that[c0 + 1] == '.' && that[c0 + 2] == '.' && (that[c0 + 3] == '\0' || that[c0 + 3] == '/')) {
                    if (!String8_equalsSubstring(scratch + slash[slashes - 1] + 1, "..", position - slash[slashes - 1] - 1)) {
                        Memory_clear(scratch + slash[slashes - 1], position - slash[slashes - 1]);
                        position = slash[--slashes];
                        slash[slashes] = null;
                        c0 += 2; continue;
                    }
                }
                else if (that[c0 + 1] == '.' && (that[c0 + 2] == '\0' || that[c0 + 2] == '/')) {
                    ++c0; continue;
                }
            }
            slash[slashes++] = position;
        }
        scratch[position++] = that[c0];
    }
    if (position > 0 && scratch[position - 1] != '/') {
        slash[slashes++] = position;
        scratch[position++] = '/';
    }
    Size c1 = 0;
    while (other[c1] == '/') ++c1;
    if (other[c1] == '.' && other[c1 + 1] == '.' && (other[c1 + 2] == '\0' || other[c1 + 2] == '/')) {
        if (slashes > 1 && !String8_equalsSubstring(scratch + slash[slashes - 2] + 1, "..", slash[slashes - 1] - slash[slashes - 2] - 1)) {
            Memory_clear(scratch + slash[slashes - 2], position - slash[slashes - 2]);
            position = slash[slashes - 2];
            slash[--slashes] = null;
            c1 += 2;
        }
    }
    else if (other[c1] == '.' && (other[c1 + 1] == '\0' || other[c1 + 1] == '/')) ++c1;
    for (; c1 < length1; ++c1) {
        if (other[c1] == '/') {
            if (slashes) {
                if (other[c1 + 1] == '.' && other[c1 + 2] == '.' && (other[c1 + 3] == '\0' || other[c1 + 3] == '/')) {
                    if (!String8_equalsSubstring(scratch + slash[slashes - 1] + 1, "..", position - slash[slashes - 1] - 1)) {
                        Memory_clear(scratch + slash[slashes - 1], position - slash[slashes - 1]);
                        position = slash[--slashes];
                        slash[slashes] = null;
                        c1 += 2; continue;
                    }
                }
                else if (other[c1 + 1] == '.' && (other[c1 + 2] == '\0' || other[c1 + 2] == '/')) {
                    ++c1; continue;
                }
                if (slash[slashes - 1] == position - 1) continue;
            }
            slash[slashes++] = position;
        }
        scratch[position++] = other[c1];
    }
    return String8_copy(scratch);
}
#endif
