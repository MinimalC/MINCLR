/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
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

Size  base_System_File_read(File that, String8 value, Size count) {
/*  return ISO_fread(value, 1, count, (ISO_File)that->filePtr); */
    Size length = System_Syscall_read(that->filePtr, value, count);
    that->position += length;
    return length;
}

void  base_System_File_write__String8_size(File that, String8 value, Size count) {
/*  ISO_fwrite(value, 1, count, (ISO_File)that->filePtr); */
    Size length = System_Syscall_write(that->filePtr, value, count);
    that->position += length;
}

void  base_System_File_seek(File that, SSize offset, origin origin) {
/*  ISO_fseek((ISO_File)that->filePtr, offset, origin); */
    that->position = System_Syscall_lseek(that->filePtr, offset, origin);
}

IntPtr  base_System_File_get_Position(File that) {
/*  return ISO_ftell((ISO_File)that->filePtr); */
    return that->position;
}
void  base_System_File_set_Position(File that, Size value) {
    base_System_File_seek(that, value, origin_Begin);
}

void  base_System_File_sync(File that) {
/*  ISO_fflush((ISO_File)that->filePtr); */
    System_Syscall_fsync(that->filePtr);
}

struct System_Type_FunctionInfo  System_FileTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_File_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_File_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .name = "base_System_File_write__String8_size", .function = base_System_IStream_write__String8_size, .value = base_System_File_write__String8_size },
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

File  System_File_open(String8 filename, File_Mode flags) {

/*  System_Var filePtr = ISO_fopen(filename, modes); */
    System_Var filePtr = System_Syscall_openat((System_Var)System_Syscall_StandardFile_CurrentWorkingDirectory, filename,
        System_File_Mode_noControllingTerminal | flags,
        System_File_Permission_UserReadWrite | System_File_Permission_GroupReadWrite | System_File_Permission_EverybodyRead);

    System_Error error = System_Syscall_get_Error();
    if (error || !filePtr) { /* TODO */
        return null;
    }

    File that = new_System_File();
    that->filePtr = filePtr;
    System_FileInfo info = new_System_FileInfo(filename);
    that->info = (System_FileInfo)System_Memory_addReference((System_Object)info);
    return that;
}

#endif
