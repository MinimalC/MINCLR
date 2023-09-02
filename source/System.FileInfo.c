/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_FileInfo)
#include <min/System.FileInfo.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif

/*# System_FileInfo #*/

System_FileInfo  base_System_FileInfo_init(System_FileInfo that, System_String8 fileName) {
    base_System_Object_init((System_Object)that);

    System_Syscall_fstatat(System_Syscall_StandardFile_CurrentWorkingDirectory, fileName, &that->stat, 0);

    System_ErrorCode error = System_Syscall_get_Error();
    if (error) { /* TODO */
        System_Console_writeLine("System_FileInfo_init Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), error));
        return that;
    }

    that->name = fileName;

    return that;
}

System_Bool System_FileInfo_isRegular(System_FileInfo that) {
    return that->stat.mode & FileInfo_Type_Regular;
}
System_Bool System_FileInfo_isDirectory(System_FileInfo that) {
    return that->stat.mode & FileInfo_Type_Directory;
}
System_Bool System_FileInfo_isLink(System_FileInfo that) {
    return that->stat.mode & FileInfo_Type_Link;
}

/* void  base_System_FileInfo_free(System_FileInfo that) {

    base_System_Object_free((System_Object)that);
} */

struct System_Type_FunctionInfo  System_FileInfoTypeFunctions[] = {
    [0] = { .function = base_System_FileInfo_init, .value = base_System_FileInfo_init },
/*    [1] = { .function = base_System_Object_free, .value = base_System_FileInfo_free }, */
};

struct System_Type System_FileInfoType = {
    .base = { .type = typeof(System_Type) },
    .name = "FileInfo",
    .size = sizeof(struct System_FileInfo),
    .baseType = &System_ObjectType,
    .functions = { 
        .length = sizeof_array(System_FileInfoTypeFunctions), .value = &System_FileInfoTypeFunctions
    },
};
