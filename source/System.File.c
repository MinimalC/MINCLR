#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_File)
#define code_System_File

/*# System_File #*/

System_File  System_File_new() {
    return inline_System_File_new();
}

__File  base_System_File_init(__File that) {
	base_System_Object_init((__Object)that);

    return that;
}

void  base_System_File_free(__File that) {

/*  ISO_fclose((ISO_File)that->filePtr); */
    if (that->filePtr) System_Syscall_close(that->filePtr);

	base_System_Object_free((__Object)that);
}

__File  System_File_open(__string8 filename, enum_File_mode flags) {
/*  System_intptr filePtr = ISO_fopen(filename, modes); */
    System_intptr filePtr = System_Syscall_openat(System_File_special_CurrentWorkingDirectory, filename,
        System_File_mode_noControllingTerminal | flags,
        System_File_permission_UserReadWrite | System_File_permission_GroupReadWrite | System_File_permission_EverybodyRead);

    /* DEBUG __Console_printLine("ERROR: System_File_open, flags: %X", flags); */
    if (!filePtr) return __null;

    __File that = System_File_new();
    that->filePtr = filePtr;
    return that;
}

__size  base_System_File_read(__File that, __size count, __string8 value) {
/*  return ISO_fread(value, 1, count, (ISO_File)that->filePtr); */
    __size length = System_Syscall_read(that->filePtr, value, count);
    that->position += length;
    return length;
}

void  base_System_File_write(__File that, __size count, __string8 value) {
/*  ISO_fwrite(value, 1, count, (ISO_File)that->filePtr); */
    __size length = System_Syscall_write(that->filePtr, value, count);
    that->position += length;
}

void  base_System_File_seek(__File that, __ssize offset, enum_origin origin) {
/*  ISO_fseek((ISO_File)that->filePtr, offset, origin); */
    that->position = System_Syscall_lseek(that->filePtr, offset, origin);
}

__intptr  base_System_File_get_Position(__File that) {
/*  return ISO_ftell((ISO_File)that->filePtr); */
    return that->position;
}
void  base_System_File_set_Position(__File that, __size value) {
    base_System_File_seek(that, value, __origin_Begin);
}

void  base_System_File_sync(__File that) {
/*  ISO_fflush((ISO_File)that->filePtr); */
    System_Syscall_fsync(that->filePtr);
}

struct_System_String  STRING_System_File = const_System_String("System.File");

struct_System_Type_FunctionInfo  System_FileTypeFunctions[] = {
    /* [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_File_init }, */
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_File_free },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_write, .value = base_System_File_write },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_sync, .value = base_System_File_sync },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_read, .value = base_System_File_read },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_seek, .value = base_System_File_seek },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_get_Position, .value = base_System_File_get_Position },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_set_Position, .value = base_System_File_set_Position },
};

struct_System_Type_InterfaceInfo  System_FileTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IStreamType },
};

struct_System_Type  System_FileType = {
    .base = stack_System_Object(System_Type),
	.name = &STRING_System_File,
    .size = sizeof(struct_System_File),
	.baseType = &System_ObjectType,
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&System_FileTypeFunctions), .value = &System_FileTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(&System_FileTypeInterfaces), .value = &System_FileTypeInterfaces
    },
};

#endif
