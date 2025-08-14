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

/** struct System_File */

/** function System_File_exists
    argument System_String8 name of the File.
    Returns true or false, if the File exists.
*/
System_Bool System_File_exists(System_String8 name) {
    struct System_FileInfo info; System_Stack_clearType(info, typeof(System_FileInfo)); System_FileInfo_init(&info, name);
    return System_FileInfo_isRegular(&info);
}

/** function System_File_open
    Open a File by name, with the specified flags.
    argument System_String8 fileName
    argument File_Mode flags, on how to open the File.
    Returns System_File
*/
File  System_File_open(String8 filename, File_Mode flags) {
    File that = new_File();
    stack_System_File_open(that, filename, flags);
    return that;
}

/** function stack_System_File_open
    Open a File by name, with the specified flags on stack.
    argument System_File file.
    argument System_String8 filename: Name of the File.
    argument File_Mode flags: Flags how to open the File.
    Returns System_Bool, if the file was opened.
*/
System_Bool  stack_System_File_open(System_File that, System_String8 filename, System_File_Mode flags) {

    if (that->fileId) return false;

    that->name = Memory_addReference(filename);

/*  System_Var id = ISO_fopen(filename, modes); */
    System_IntPtr id = System_Syscall_openat(System_Syscall_StandardFile_CurrentWorkingDirectory, filename,
        System_File_Mode_noControllingTerminal | flags,
        System_File_Permission_UserReadWrite | System_File_Permission_GroupReadWrite | System_File_Permission_EverybodyRead);

    System_ErrorCode error = System_Syscall_get_Error();
    if (error) {
        System_Exception_throw(new_System_IOException__error(error, "File not found"));
        return false;
    }
    that->fileId = id;
    return true;
}

/** function System_File_new
    Create a new File object.
    Returns System_File.
*/
System_File  new_System_File() {
    return (System_File)System_Memory_allocClass(typeof(System_File));
}

/** function System_File_close
    Close the File.
    argument System_File that
*/
void  System_File_close(File that) {
    if (that->fileId) {
/*  ISO_fclose((ISO_File)that->fileId); */
        System_Syscall_close(that->fileId);
        that->fileId = null;
    }
}

/** function System_File_free
    Close the File and free the System_String8 name.
    argument System_File that
*/
void  System_File_free(File that) {
    System_File_close(that);
    if (that->name) Memory_free(that->name);
}

/** function System_File_read
    Read into System_String8 value, with System_Size count bytes.
    argument System_File that
    argument System_String8 value
    argument System_Size count
    Returns the count of bytes actually read.
*/
Size  System_File_read(File that, String8 value, Size count) {
/*  return ISO_fread(value, 1, count, (ISO_File)that->fileId); */
    Size length = System_Syscall_read(that->fileId, value, count);
    return length;
}

/** function System_File_write__string_size
    Write a System_String8 value, with System_Size count bytes.
    argument System_File that
    argument System_String8 value
    argument System_Size count
    Returns the count of bytes actually wrote.
*/
Size  System_File_write__string_size(File that, String8 value, Size count) {
/*  ISO_fwrite(value, 1, count, (ISO_File)that->fileId); */
    return System_Syscall_write(that->fileId, value, count);
}

/** function System_File_write__string
    Write a System_String8 value, this function is using System_String8_get_Length.
    argument System_File that
    argument System_String8 value
    Returns the count of bytes actually wrote.
*/
Size  System_File_write__string(File that, String8 string) {
    Size length = String8_get_Length(string);
    return System_File_write__string_size(that, string, length);
}

/** function System_File_write__char
    Write a System_Char8 value.
    argument System_File that
    argument System_Char8 character
    Returns 1.
*/
Size  System_File_write__char(File that, Char8 character) {
    System_File_write__string_size(that, &character, 1);
    return 1;
}

/** function System_File_writeLineEmpty
    Write an empty new line.
    argument System_File that
    Returns 1.
*/
Size  System_File_writeLineEmpty(File that) {
    System_File_write__string_size(that, "\n", 1);
    return 1;
}

/** function System_File_write
    Write a formatted string with arguments into the File.
    argument System_File that
    argument System_String8 format
    argument ...
    Returns the length of the formatted string.
*/
Size  System_File_write(File that, String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(that, format, 0, argc, argv);
}

/** function System_File_writeLine__string
    Write a string and a new line into the File.
    argument System_File that
    argument System_String8 string
    Returns the length of the string + 1.
*/
Size  System_File_writeLine__string(File that, String8 string) {
    return System_File_writeLine(that, string, 0);
}

/** function System_File_writeLine
    Write a formatted string and a new line into the File.
    argument System_File that
    argument System_String8 format
    argument ...
    Returns the length of the formatted string.
*/
Size  System_File_writeLine(File that, String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(that, format, '\n', argc, argv);
}

/** function System_File_writeEnd__arguments
    Write a formatted string with a suffix and arguments into the File.
    argument System_File that
    argument System_String8 format
    argument System_Char8 suffix
    argument System_Size argc
    argument System_Var argv[]
    Returns the length of the formatted string.
*/
Size  System_File_writeEnd__arguments(File stream, String8 format, Char8 suffix, Size argc, Var argv[]) {
    Char8  message[System_String8_FormatLimit_VALUE]; System_Stack_clear(message);
    Size message_length = stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
    return System_File_write__string_size(stream, message, message_length);
}

/** function System_File_seek
    Set the read, write position of the file.
    argument System_File that
    argument System_SSize offset
    argument System_Origin origin, System_Origin_Begin, System_Origin_Current, System_Origin_End
    Returns the new position.
*/
Size  System_File_seek(File that, SSize offset, Origin origin) {
/*  ISO_fseek((ISO_File)that->fileId, offset, origin); */
    return System_Syscall_lseek(that->fileId, offset, origin);
}

/** function System_File_get_position
    Get the read, write position of the file.
    argument System_File that
    Returns the current position.
*/
Size  System_File_get_Position(File that) {
    return System_File_seek(that, 0, Origin_Current);
}
/** function System_File_set_position
    Set the read, write position of the file.
    argument System_File that
    argument System_Size position
*/
void  System_File_set_Position(File that, Size value) {
    System_File_seek(that, value, Origin_Begin);
}

/** function System_File_get_Length
    argument System_File that
    Returns the length of the file.
*/
Size  System_File_get_Length(File that) {
    /*Size position = System_File_seek(that, 0, Origin_Current);
    Size length = System_File_seek(that, 0, Origin_End);
    System_File_seek(that, position, Origin_Begin);
    return length;*/
    struct System_FileInfo info; System_Stack_clearType(info, typeof(System_FileInfo)); System_FileInfo_init__fileId(&info, that->fileId);
    return info.status.size;
}

/** function System_File_set_Length
    Set the length of the file.
    argument System_File that
    argument System_Size value
*/
void  System_File_set_Length(File that, Size value) {
    System_Syscall_ftruncate(that->fileId, value);
}

/** function System_File_sync
    Synchronize the file.
    argument System_File that
*/
void  System_File_sync(File that) {
/*  ISO_fflush((ISO_File)that->fileId); */
    System_Syscall_fsync(that->fileId);
}

struct System_Type_FunctionInfo  System_FileTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_File_free },
    { .function = base_System_IStream_write__string_size, .value = System_File_write__string_size },
    { .function = base_System_IStream_sync, .value = System_File_sync },
    { .function = base_System_IStream_read, .value = System_File_read },
    { .function = base_System_IStream_seek, .value = System_File_seek },
    { .function = base_System_IStream_get_Position, .value = System_File_get_Position },
    { .function = base_System_IStream_set_Position, .value = System_File_set_Position },
};

struct System_Type_InterfaceInfo  System_FileTypeInterfaces[] = {
    { .interfaceType = &System_IStreamType },
};

struct System_Type System_FileType = {
    .base = { .type = typeof(System_Type) },
	.name = "File",
    .size = sizeof(struct System_File),
	.baseType = typeof(System_Object),
    .functions = { .length = sizeof_array(System_FileTypeFunctions), .value = &System_FileTypeFunctions },
    .interfaces = { .length = sizeof_array(System_FileTypeInterfaces), .value = &System_FileTypeInterfaces },
};

#endif
