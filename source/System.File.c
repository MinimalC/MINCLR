/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
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

/** class System_File */

/** function System_File_exists
    True or false, if a named File exists.
    argument System_String8 name: Name of the File.
    returns System_Bool
*/
System_Bool System_File_exists(System_String8 name) {
    struct System_FileInfo info; System_Stack_clearType(info, typeof(System_FileInfo));
    System_FileInfo_init(&info, name);
    return System_FileInfo_isRegular(&info);
}

/** function System_File_open
    Opens a File by name, with the specified flags.
    argument System_String8 filename: Name of the File.
    argument File_Mode flags: Flags how to open the File.
    returns System_File, or null
*/
File  System_File_open(String8 filename, File_Mode flags) {

    File that = new_File();
    if (stack_System_File_open(that, filename, flags)) {
        return that;
    }
    Memory_free(that);
    return null;
}

/** function stack_System_File_open
    Opens a File by name, with the specified flags on stack.
    this argument System_File file.
    argument System_String8 filename: Name of the File.
    argument File_Mode flags: Flags how to open the File.
    returns System_Bool, if the file was opened.
*/
System_Bool  stack_System_File_open(System_File that, System_String8 filename, System_File_Mode flags) {

    if (that->fileId) return false; /* TODO */

/*  System_Var id = ISO_fopen(filename, modes); */
    System_IntPtr id = System_Syscall_openat(System_Syscall_StandardFile_CurrentWorkingDirectory, filename,
        System_File_Mode_noControllingTerminal | flags,
        System_File_Permission_UserReadWrite | System_File_Permission_GroupReadWrite | System_File_Permission_EverybodyRead);

    System_ErrorCode error = System_Syscall_get_Error();
    if (error) { /* TODO */
        System_Exception exception = new_System_IOException("FileNotFound");
        exception->error = error;
        Exception_throw(exception);
        return false;
    }

/*    System_FileInfo info = new_System_FileInfo(filename);
    that->info = (System_FileInfo)System_Memory_addReference((System_Object)info); */

    that->fileId = id;
    return true;
}

/** function System_File_new
    Creates a new File object.
    returns System_File
*/
System_File  new_System_File() {
    System_File that = (System_File)System_Memory_allocClass(typeof(System_File));
    System_File_init(that);
    return that;
}

void  System_File_init(File that) { }

/** function System_File_close
    This method closes the File.
    argument System_File file
*/
void  System_File_close(File that) {
    if (!that->fileId) return;
/*  ISO_fclose((ISO_File)that->fileId); */
    System_Syscall_close(that->fileId);
    that->fileId = null;
}

void  System_File_free(File that) {
    System_File_close(that);
}

Size  System_File_read(File that, String8 value, Size count) {
/*  return ISO_fread(value, 1, count, (ISO_File)that->fileId); */
    Size length = System_Syscall_read(that->fileId, value, count);
    return length;
}

void  System_File_write__string_size(File that, String8 value, Size count) {
/*  ISO_fwrite(value, 1, count, (ISO_File)that->fileId); */
    Size length = System_Syscall_write(that->fileId, value, count);
}

void  System_File_write__string(File that, String8 string) {
    System_File_write__string_size(that, string, String8_get_Length(string));
}

void  System_File_write__char(File that, Char8 character) {
    System_File_write__string_size(that, &character, 1);
}

void  System_File_writeLineEmpty(File that) {
    System_File_write__string_size(that, "\n", 1);
}

void  System_File_write(File that, String8 format, ...) {
    Console_assert(format);
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_File_writeEnd__arguments(that, format, 0, argc, argv);
}

void  System_File_writeLine__string(File that, String8 string) {
    System_File_writeLine(that, string, 0);
}

void  System_File_writeLine(File that, String8 format, ...) {
    Console_assert(format);
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_File_writeEnd__arguments(that, format, '\n', argc, argv);
}

void  System_File_writeEnd__arguments(File stream, String8 format, Char8 suffix, Size argc, Var argv[]) {
    Char8  message[System_String8_formatLimit_VALUE]; System_Stack_clear(message);
    Size message_length = stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
    System_File_write__string_size(stream, message, message_length);
}

Size  System_File_seek(File that, SSize offset, origin origin) {
/*  ISO_fseek((ISO_File)that->fileId, offset, origin); */
    return System_Syscall_lseek(that->fileId, offset, origin);
}

Size  System_File_get_Position(File that) {
    return System_File_seek(that, 0, origin_Current);
}
void  System_File_set_Position(File that, Size value) {
    System_File_seek(that, value, origin_Begin);
}

Size  System_File_get_Length(File that) {
    Size position = System_File_seek(that, 0, origin_Current);
    Size reture = System_File_seek(that, 0, origin_End);
    System_File_seek(that, position, origin_Begin);
    return reture;
}

void  System_File_set_Length(File that, Size value) {
    System_Syscall_ftruncate(that->fileId, value);
}

void  System_File_sync(File that) {
/*  ISO_fflush((ISO_File)that->fileId); */
    System_Syscall_fsync(that->fileId);
}

struct System_Type_FunctionInfo  System_FileTypeFunctions[] = {
    [0] = { .function = base_System_Object_init, .value = System_File_init },
    [1] = { .function = base_System_Object_free, .value = System_File_free },
    [2] = { .function = base_System_IStream_write__string_size, .value = System_File_write__string_size },
    [3] = { .function = base_System_IStream_writeEnd__arguments, .value = System_File_write__string_size },
    [4] = { .function = base_System_IStream_sync, .value = System_File_sync },
    [5] = { .function = base_System_IStream_read, .value = System_File_read },
    [6] = { .function = base_System_IStream_seek, .value = System_File_seek },
    [7] = { .function = base_System_IStream_get_Position, .value = System_File_get_Position },
    [8] = { .function = base_System_IStream_set_Position, .value = System_File_set_Position },
};

struct System_Type_InterfaceInfo  System_FileTypeInterfaces[] = {
    [0] = { .interfaceType = &System_IStreamType },
};

struct System_Type System_FileType = {
    .base = { .type = typeof(System_Type) },
	.name = "File",
    .size = sizeof(struct System_File),
	.baseType = &System_ObjectType,
    .functions = { .length = sizeof_array(System_FileTypeFunctions), .value = &System_FileTypeFunctions },
    .interfaces = { .length = sizeof_array(System_FileTypeInterfaces), .value = &System_FileTypeInterfaces },
};

#endif
