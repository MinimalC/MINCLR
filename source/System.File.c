/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_File)
#include <min/System.File.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(code_System_File)
#define code_System_File

/*# System_File #*/

File  base_System_File_init(File that) {
	base_System_Object_init((Object)that);

    return that;
}

void  base_System_File_free(File that) {

/*  ISO_fclose((ISO_File)that->filePtr); */
    if (that->filePtr) System_Syscall_close(that->filePtr);

	base_System_Object_free((Object)that);
}

File  System_File_open(string8 filename, File_mode flags) {
/*  System_var filePtr = ISO_fopen(filename, modes); */
    System_var filePtr = System_Syscall_openat((System_var)System_File_special_CurrentWorkingDirectory, filename,
        System_File_mode_noControllingTerminal | flags,
        System_File_permission_UserReadWrite | System_File_permission_GroupReadWrite | System_File_permission_EverybodyRead);

    /* DEBUG Console_writeLine("ERROR: System_File_open, flags: {0:uint:hex}", 1, flags); */
    if (!filePtr) return null;

    File that = new_System_File();
    that->filePtr = filePtr;
    return that;
}

size  base_System_File_read(File that, size count, string8 value) {
/*  return ISO_fread(value, 1, count, (ISO_File)that->filePtr); */
    size length = System_Syscall_read(that->filePtr, value, count);
    that->position += length;
    return length;
}

void  base_System_File_write(File that, size count, string8 value) {
/*  ISO_fwrite(value, 1, count, (ISO_File)that->filePtr); */
    size length = System_Syscall_write(that->filePtr, value, count);
    that->position += length;
}

void  base_System_File_seek(File that, ssize offset, origin origin) {
/*  ISO_fseek((ISO_File)that->filePtr, offset, origin); */
    that->position = System_Syscall_lseek(that->filePtr, offset, origin);
}

intptr  base_System_File_get_Position(File that) {
/*  return ISO_ftell((ISO_File)that->filePtr); */
    return that->position;
}
void  base_System_File_set_Position(File that, size value) {
    base_System_File_seek(that, value, origin_Begin);
}

void  base_System_File_sync(File that) {
/*  ISO_fflush((ISO_File)that->filePtr); */
    System_Syscall_fsync(that->filePtr);
}

struct System_Type_FunctionInfo  System_FileTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_File_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_File_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .name = "base_System_File_write", .function = base_System_IStream_write, .value = base_System_File_write },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_sync, .value = base_System_File_sync },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_read, .value = base_System_File_read },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_seek, .value = base_System_File_seek },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_get_Position, .value = base_System_File_get_Position },
    [7] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_set_Position, .value = base_System_File_set_Position },
};

struct System_Type_InterfaceInfo  System_FileTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IStreamType },
};

struct System_Type  System_FileType = {
    .base = stack_System_Object(System_Type),
	.name = "System.File",
    .size = sizeof(struct System_File),
	.baseType = &System_ObjectType,
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_FileTypeFunctions), .value = &System_FileTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(System_FileTypeInterfaces), .value = &System_FileTypeInterfaces
    },
};

#endif
