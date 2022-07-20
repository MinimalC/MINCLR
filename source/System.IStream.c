/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_IStream)
#include <min/System.IStream.h>
#endif
#if !defined(have_System_string8)
#include <min/System.string8.h>
#endif
#if !defined(code_System_IStream)
#define code_System_IStream

/*# System_IStream #*/

void  base_System_IStream_write__string8(IStream that, string8 value, size count) { }

void  base_System_IStream_sync(IStream that) {  }

System_size  base_System_IStream_read(IStream that, string8 value, size count) { return 0; }

void  base_System_IStream_seek(IStream that, ssize offset, origin origin) { }

System_size  base_System_IStream_get_Position(IStream that) { return 0; }

void  base_System_IStream_set_Position(IStream that, size value) { }

struct System_Type_FunctionInfo  System_IStreamTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .name = "base_System_IStream_write__string8", .function = base_System_IStream_write__string8, .value = null },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_sync, .value = null },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_read, .value = null },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_seek, .value = null },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_get_Position, .value = null },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_set_Position, .value = null },
};

struct System_Type  System_IStreamType = { .base = stack_System_Object(System_Type),
	.name = "System.IStream",
    .size = sizeof(struct System_IStream),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_IStreamTypeFunctions), .value = &System_IStreamTypeFunctions
    },
};

void  System_IStream_write(IStream stream, string8 format, ...) {
    arguments args;
    arguments_start(args, format);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeEnd__arguments(stream, format, 0, argc, argv);
}

void  System_IStream_write__arguments(IStream stream, string8 format, size argc, var argv[]) {
    System_IStream_writeEnd__arguments(stream, format, 0, argc, argv);
}

void  System_IStream_writeLine(IStream stream, string8 format, ...) {
    arguments args;
    arguments_start(args, format);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeEnd__arguments(stream, format, '\n', argc, argv);
}

void  System_IStream_writeLine__arguments(IStream stream, string8 format, size argc, var argv[]) {
    System_IStream_writeEnd__arguments(stream, format, '\n', argc, argv);
}

void  System_IStream_writeEnd(IStream stream, string8 format, char8 suffix, ...) {
    arguments args;
    arguments_start(args, suffix);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_writeEnd__arguments(stream, format, suffix, argc, argv);
}

void  System_IStream_writeEnd__arguments(IStream stream, string8 format, char8 suffix, size argc, var argv[]) {
    char8  message[System_string8_formatLimit_VALUE] = { 0 };
    for (size i = 0; i < sizeof(message); ++i) message[i] = 0;
    size message_length = stack_System_string8_formatEnd__arguments(format, suffix, message, argc, argv);
    System_IStream_write__string8(stream, message, message_length);
}

#endif