/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_File)
#include <min/System.File.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_File)
#define code_System_File

/*# System_File #*/

System_Bool System_File_exists(System_String8 name) {
    struct System_FileInfo info; System_Stack_zero(info);
    return base_System_FileInfo_init(&info, name) && System_FileInfo_isRegular(&info);
}

File  System_File_open(String8 filename, File_Mode flags) {

    File that = new_File();
    if (stack_System_File_open(that, filename, flags)) {
        return that;
    }
    Memory_free(that);
    return null;
}

System_Bool  stack_System_File_open(System_File that, System_String8 filename, System_File_Mode flags) {

    if (that->filePtr) return false; /* TODO */

/*  System_Var filePtr = ISO_fopen(filename, modes); */
    System_Var filePtr = System_Syscall_openat((System_Var)System_Syscall_StandardFile_CurrentWorkingDirectory, filename,
        System_File_Mode_noControllingTerminal | flags,
        System_File_Permission_UserReadWrite | System_File_Permission_GroupReadWrite | System_File_Permission_EverybodyRead);

    System_ErrorCode error = System_Syscall_get_Error();
    if (error || !filePtr) { /* TODO */
        System_Exception exception = new_System_Exception("FileNotFound");
        exception->error = error;
        throw_return(exception);
    }

    that->filePtr = filePtr;

/*    System_FileInfo info = new_System_FileInfo(filename);
    that->info = (System_FileInfo)System_Memory_addReference((System_Object)info); */

    return true;
}

File  base_System_File_init(File that) {
	base_System_Object_init((Object)that);

    return that;
}

void  base_System_File_close(File that) {
    if (!that->filePtr) return;
/*  ISO_fclose((ISO_File)that->filePtr); */
    System_Syscall_close(that->filePtr);
    that->filePtr = null;
}

void  base_System_File_free(File that) {
    base_System_File_close(that);
	base_System_Object_free((Object)that);
}

Size  base_System_File_read(File that, String8 value, Size count) {
/*  return ISO_fread(value, 1, count, (ISO_File)that->filePtr); */
    Size length = System_Syscall_read(that->filePtr, value, count);
    that->position += length;
    return length;
}

void  base_System_File_write__string_size(File that, String8 value, Size count) {
/*  ISO_fwrite(value, 1, count, (ISO_File)that->filePtr); */
    Size length = System_Syscall_write(that->filePtr, value, count);
    that->position += length;
}

void  base_System_File_writeEnd__arguments(File stream, String8 format, Char8 suffix, Size argc, Var argv[]) {
    Char8  message[System_String8_formatLimit_VALUE];
    for (Size i = 0; i < System_String8_formatLimit_VALUE; ++i) message[i] = 0;
    Size message_length = stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
    base_System_File_write__string_size(stream, message, message_length);
}

Size  base_System_File_seek(File that, SSize offset, origin origin) {
/*  ISO_fseek((ISO_File)that->filePtr, offset, origin); */
    return that->position = System_Syscall_lseek(that->filePtr, offset, origin);
}

Size  base_System_File_get_Position(File that) {
/*  return ISO_ftell((ISO_File)that->filePtr); */
    return that->position;
}
void  base_System_File_set_Position(File that, Size value) {
    base_System_File_seek(that, value, origin_Begin);
}

Size  base_System_File_get_Length(File that) {
    Size position = base_System_File_seek(that, 0, origin_Current);
    Size reture = base_System_File_seek(that, 0, origin_End);
    base_System_File_seek(that, position, origin_Begin);
    return reture;
}

void  base_System_File_sync(File that) {
/*  ISO_fflush((ISO_File)that->filePtr); */
    System_Syscall_fsync(that->filePtr);
}

struct System_Type_FunctionInfo  System_FileTypeFunctions[] = { 
    [0] = { .function = base_System_Object_init, .value = base_System_File_init },
    [1] = { .function = base_System_Object_free, .value = base_System_File_free },
    [2] = { .name = "base_System_File_write__string_size", .function = base_System_IStream_write__string_size, .value = base_System_File_write__string_size },
    [3] = { .name = "base_System_File_writeEnd__arguments", .function = base_System_IStream_writeEnd__arguments, .value = base_System_File_write__string_size },
    [4] = { .function = base_System_IStream_sync, .value = base_System_File_sync },
    [5] = { .function = base_System_IStream_read, .value = base_System_File_read },
    [6] = { .function = base_System_IStream_seek, .value = base_System_File_seek },
    [7] = { .function = base_System_IStream_get_Position, .value = base_System_File_get_Position },
    [8] = { .function = base_System_IStream_set_Position, .value = base_System_File_set_Position },
    [9] = { .function = base_System_File_close, .value = base_System_File_close },
};

struct System_Type_InterfaceInfo  System_FileTypeInterfaces[] = {
    [0] = { .interfaceType = &System_IStreamType },
};

struct System_Type System_FileType = {
    .base = stack_System_Object(System_Type),
	.name = "File",
    .size = sizeof(struct System_File),
	.baseType = &System_ObjectType,
    .functions = { 
        .length = sizeof_array(System_FileTypeFunctions), .value = &System_FileTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_FileTypeInterfaces), .value = &System_FileTypeInterfaces
    },
};

#endif
