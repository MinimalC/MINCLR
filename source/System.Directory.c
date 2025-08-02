/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Directory)
#include <min/System.Directory.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif

/** class System_Directory  **/

struct System_Type System_DirectoryType = { .base = { .type = typeof(System_Type) }, .name = "Directory", };

System_Bool System_Directory_exists(System_String8 name) {
    struct System_FileInfo info; System_Stack_clearType(info, typeof(System_FileInfo));
    System_FileInfo_init(&info, name);
    return System_FileInfo_isDirectory(&info);
}

System_String8 System_Directory_current = null;

System_String8 System_Directory_get_current() {

    if (!System_Directory_current) {
        System_Char8 buffer[4096]; System_Stack_clear(buffer);

        System_Syscall_getcwd(buffer, 4096);
        System_ErrorCode error = System_Syscall_get_Error();
        if (error) return null; // throw

        System_Size length = System_String8_get_Length(buffer);
        System_Directory_current = System_Memory_allocArray(typeof(System_Char8), length + 1);
        System_String8_copyTo(buffer, System_Directory_current);
    }
    return (System_String8)System_Memory_addReference(System_Directory_current);
}

System_Bool System_Directory_change(System_String8 path) {
    System_Syscall_chdir(path);
    System_ErrorCode error = System_Syscall_get_Error();
    if (error) return false; // throw
    if (System_Directory_current) System_Memory_free(System_Directory_current);
    return true;
}
