/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_FileInfo)
#include <min/System.FileInfo.h>
#endif
#if !defined(have_System_File)
#include <min/System.File.h>
#endif

/*# System_FileInfo #*/

System_FileInfo  base_System_FileInfo_init(System_FileInfo that, System_string8 fileName) {
    base_System_Object_init((System_Object)that);

    struct System_Syscall_stat stat;
    System_Syscall_fstatat(System_File_special_CurrentWorkingDirectory, fileName, &stat, 0);

    that->name = fileName;

    that->deviceId = stat.deviceId;
    that->iNodeId = stat.iNodeId;
    that->hardlinks = stat.hardlinks;

    that->mode = stat.mode;
    that->userId = stat.userId;
    that->groupId = stat.groupId;

    that->isDevice = stat.isDevice;
    that->size = stat.size;
    that->bulkSize = stat.bulkSize;
    that->blocks = stat.blocks;

    that->lastAccessTime = stat.accessTime;
    that->lastWriteTime = stat.modifyTime;
    that->changeTime = stat.changeTime;

    return that;
}

/* void  base_System_FileInfo_free(System_FileInfo that) {

    base_System_Object_free((System_Object)that);
} */

struct System_Type_FunctionInfo  System_FileInfoTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_FileInfo_init, .value = base_System_FileInfo_init },
/*    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_FileInfo_free }, */
};

struct System_Type  System_FileInfoType = {
    .base = { .type = typeof(System_Type) },
    .name = "System.FileInfo",
    .size = sizeof(struct System_FileInfo),
    .baseType = &System_ObjectType,
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_FileInfoTypeFunctions), .value = &System_FileInfoTypeFunctions
    },
};
