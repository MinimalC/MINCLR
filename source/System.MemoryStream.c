/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_MemoryStream)
#include <min/System.MemoryStream.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_MemoryStream)
#define code_System_MemoryStream

/** struct System_MemoryStream */

System_MemoryStream  new_System_MemoryStream() {
     return (System_MemoryStream)System_Memory_allocClass(typeof(System_MemoryStream));
}

String8  System_MemoryStream_final(MemoryStream that) { 
    System_Size size = 0;
    return System_MemoryStream_final__size(that, &size);
}

String8  System_MemoryStream_final__size(MemoryStream that, System_Size out size) { 
    
    *size = that->size;
    String8 reture = that->buffer;
    if (reture) Memory_reallocArray((System_Var ref)&reture, that->size);
    that->buffer = null;
    that->capacity = that->size = that->position = 0;
    return reture;
}

String8  System_MemoryStream_snapshot(MemoryStream that) { 
    
    String8 reture = Memory_allocArray(typeof(Char8), that->size);
    Memory_copyTo(that->buffer, that->size, reture);
    return reture;
}

void  System_MemoryStream_close(MemoryStream that) {
    if (that->buffer) { 
        Memory_free(that->buffer);
        that->capacity = that->size = that->position = 0;
    }
}

void  System_MemoryStream_free(MemoryStream that) {
    System_MemoryStream_close(that);
}

Size  System_MemoryStream_read(MemoryStream that, String8 value, Size count) {
    SSize count1 = count;
    if (that->position + count1 > that->size)
        count1 = that->size - that->position;
    if (count1 > 0) {
        Memory_copyTo(that->buffer + that->position, count1, value);
        that->position += count1;
    }
    return count1;
}

Size  System_MemoryStream_write__string_size(MemoryStream that, String8 value, Size count) {
    if (that->position + count >= that->capacity) {
        Size count1 = ROUND(that->position + count, System_MemoryStream_Capacity);  
        if (!that->buffer) that->buffer = Memory_allocArray(typeof(Char8), count1);
        else Memory_reallocArray((System_Var ref)&that->buffer, count1);
        that->capacity = count1;
    }
    Memory_copyTo(value, count, that->buffer + that->position);
    that->position += count;
    if (that->position > that->size) 
        that->size = that->position;
    return count;
}

void  System_MemoryStream_set_Length(MemoryStream that, Size length) {
    Size length1 = ROUND(length, System_MemoryStream_Capacity);
    if (that->capacity != length1) {
        if (!that->buffer) that->buffer = Memory_allocArray(typeof(Char8), length1);
        else Memory_reallocArray((System_Var ref)&that->buffer, length1);
        that->capacity = length1;
    }
    else 
        Memory_clear(that->buffer + length, that->capacity - length);

    that->size = length;
    if (that->position > that->size) 
        that->position = that->size;
}

Size  System_MemoryStream_write__string(MemoryStream that, String8 string) {
    Size length = String8_get_Length(string);
    System_MemoryStream_write__string_size(that, string, length);
    return length;
}

Size  System_MemoryStream_write__char(MemoryStream that, Char8 character) {
    System_MemoryStream_write__string_size(that, &character, 1);
    return 1;
}

Size  System_MemoryStream_writeLineEmpty(MemoryStream that) {
    System_MemoryStream_write__string_size(that, "\n", 1);
    return 1;
}

Size  System_MemoryStream_write(MemoryStream that, String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_MemoryStream_writeEnd__arguments(that, format, 0, argc, argv);
}

Size  System_MemoryStream_writeLine__string(MemoryStream that, String8 string) {
    return System_MemoryStream_writeLine(that, string, 0);
}

Size  System_MemoryStream_writeLine(MemoryStream that, String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_MemoryStream_writeEnd__arguments(that, format, '\n', argc, argv);
}

Size  System_MemoryStream_writeEnd__arguments(MemoryStream stream, String8 format, Char8 suffix, Size argc, Var argv[]) {
    Char8  message[System_String8_FormatLimit_VALUE]; System_Stack_clear(message);
    Size message_length = stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
    return System_MemoryStream_write__string_size(stream, message, message_length);
}

Size  System_MemoryStream_seek(MemoryStream that, SSize offset, Origin origin) {
    switch (origin) {
    case Origin_Begin:
        if (offset < 0 || offset > that->size) return false;
        return that->position = offset;
    case Origin_Current:
        if (that->position + offset < 0 || that->position + offset > that->size) return false;
        return that->position += offset;
    case Origin_End:
        if (that->size + offset < 0 || that->size + offset > that->size) return false;
        return that->position = that->size + offset;
    default:
        return false; // throw
    }
}

Size  System_MemoryStream_get_Position(MemoryStream that) {
    return System_MemoryStream_seek(that, 0, Origin_Current);
}
void  System_MemoryStream_set_Position(MemoryStream that, Size value) {
    System_MemoryStream_seek(that, value, Origin_Begin);
}

Size  System_MemoryStream_get_Length(MemoryStream that) {
    return that->size;
}

void  System_MemoryStream_sync(MemoryStream that) { }

struct System_Type_FunctionInfo  System_MemoryStreamTypeFunctions[] = {
    { .function = base_System_Object_free, .value = System_MemoryStream_free },
    { .function = base_System_IStream_write__string_size, .value = System_MemoryStream_write__string_size },
    { .function = base_System_IStream_sync, .value = System_MemoryStream_sync },
    { .function = base_System_IStream_read, .value = System_MemoryStream_read },
    { .function = base_System_IStream_seek, .value = System_MemoryStream_seek },
    { .function = base_System_IStream_get_Position, .value = System_MemoryStream_get_Position },
    { .function = base_System_IStream_set_Position, .value = System_MemoryStream_set_Position },
};

struct System_Type_InterfaceInfo  System_MemoryStreamTypeInterfaces[] = {
    { .interfaceType = &System_IStreamType },
};

struct System_Type System_MemoryStreamType = {
    .base = { .type = typeof(System_Type) },
	.name = "MemoryStream",
    .size = sizeof(struct System_MemoryStream),
	.baseType = typeof(System_Object),
    .functions = { .length = sizeof_array(System_MemoryStreamTypeFunctions), .value = &System_MemoryStreamTypeFunctions },
    .interfaces = { .length = sizeof_array(System_MemoryStreamTypeInterfaces), .value = &System_MemoryStreamTypeInterfaces },
};

#endif
