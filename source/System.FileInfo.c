/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_FileInfo)
#include <min/System.FileInfo.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif

/** class System_FileInfo  **/

System_FileInfo  new_System_FileInfo(System_String8 fileName) {
    System_FileInfo that = (System_FileInfo)System_Memory_allocClass(typeof(System_FileInfo));
    System_FileInfo_init(that, fileName);
    return that;
}

void  System_FileInfo_init(System_FileInfo that, System_String8 fileName) {

    that->name = (System_String8)System_Memory_addReference((System_Var)fileName);

    System_Syscall_fstatat(System_Syscall_StandardFile_CurrentWorkingDirectory, fileName, &that->status.containerId, 0);

    that->error = System_Syscall_get_Error();
}

System_Bool System_FileInfo_isRegular(System_FileInfo that) {
    return that->status.mode & FileInfo_Type_Regular;
}
System_Bool System_FileInfo_isDirectory(System_FileInfo that) {
    return that->status.mode & FileInfo_Type_Directory;
}
System_Bool System_FileInfo_isLink(System_FileInfo that) {
    return that->status.mode & FileInfo_Type_Link;
}

void System_FileInfo_free(System_FileInfo that) {
    if (that->name) {
        Memory_free(that->name);
        that->name = null;
    }
}

struct System_Type_FunctionInfo  System_FileInfoTypeFunctions[] = {
    [0] = { .function = base_System_Object_init, .value = System_FileInfo_init },
    [1] = { .function = base_System_Object_free, .value = System_FileInfo_free },
};

struct System_Type System_FileInfoType = {
    .base = { .type = typeof(System_Type) },
    .name = "FileInfo",
    .size = sizeof(struct System_FileInfo),
    .baseType = &System_ObjectType,
    .functions = { .length = sizeof_array(System_FileInfoTypeFunctions), .value = &System_FileInfoTypeFunctions },
};
