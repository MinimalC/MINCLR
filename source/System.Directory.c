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


System_Bool System_Directory_exists(System_String8 name) {
    struct System_FileInfo info; System_Stack_clearType(info, typeof(System_FileInfo));
    System_FileInfo_init(&info, name);
    return System_FileInfo_isDirectory(&info);
}

System_Bool System_Directory_change(System_String8 path) {
    System_Syscall_chdir(path);
    System_ErrorCode error = System_Syscall_get_Error();
    if (error) return false; // throw
    return true;
}

System_Bool System_Directory_create(System_String8 directoryName) {
    return !System_Syscall_mkdir(directoryName, 0777);
}

System_String8 System_Directory_get_current() {

    System_Char8 buffer[4096]; System_Stack_clear(buffer);
    System_Syscall_getcwd(buffer, 4096);
    System_ErrorCode error = System_Syscall_get_Error();
    if (error) return null; // throw

    System_Size length = System_String8_get_Length(buffer);
    System_String8 System_Directory_current = System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(buffer, System_Directory_current);

    return System_Directory_current;
}

System_Directory  new_System_Directory() {
    System_Directory that = (System_Directory)System_Memory_allocClass(typeof(System_Directory));
    return that;
}

System_Directory  System_Directory_open(String8 dirName, File_Mode flags) {

    Directory that = new_Directory();
    if (stack_System_Directory_open(that, dirName, flags)) return that;
    Memory_free(that);
    return null;
}

System_Bool  stack_System_Directory_open(System_Directory that, System_String8 dirName, System_File_Mode flags) {

    if (that->dirId) return false;

    System_IntPtr id = System_Syscall_openat(System_Syscall_StandardFile_CurrentWorkingDirectory, dirName,
        System_File_Mode_noControllingTerminal | System_File_Mode_Directory | flags,
        System_File_Permission_UserReadWrite | System_File_Permission_GroupReadWrite | System_File_Permission_EverybodyRead);

    System_ErrorCode error = System_Syscall_get_Error();
    if (error) { /* TODO */
        System_Exception exception = new_System_IOException("Directory not found");
        exception->error = error;
        Exception_throw(exception);
        return false;
    }

    that->dirId = id;
    that->name = Memory_addReference(dirName);
    return true;
}

void System_Directory_close(System_Directory that) {
    if (!that->dirId) return;
    System_Syscall_close(that->dirId);
    that->dirId = null;
}

void  System_Directory_free(System_Directory that) {
    System_Directory_close(that);
}

struct System_Type_FunctionInfo  System_DirectoryTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_Directory_free },
};

struct System_Type System_DirectoryType = { 
    .base = { .type = typeof(System_Type) }, .name = "Directory",
    .size = sizeof(struct System_Directory), .baseType = typeof(System_Object), 
    .functions = { .length = sizeof_array(System_DirectoryTypeFunctions), .value = &System_DirectoryTypeFunctions },
};