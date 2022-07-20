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

void  System_IStream_format(IStream stream, string8 format, ...) {
    arguments args;
    arguments_start(args, format);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_formatEnd__arguments(stream, format, 0, argc, argv);
}

void  System_IStream_formatLine(IStream stream, string8 format, ...) {
    arguments args;
    arguments_start(args, format);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_formatEnd__arguments(stream, format, '\n', argc, argv);
}

void  System_IStream_formatEnd(IStream stream, string8 format, char8 suffix, ...) {
    arguments args;
    arguments_start(args, suffix);
    var argv[System_arguments_Limit_VALUE] = { 0 };
    size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    System_IStream_formatEnd__arguments(stream, format, suffix, argc, argv);
}

void  System_IStream_formatEnd__arguments(IStream stream, string8 format, char8 suffix, size argc, var argv[]) {
    char8  message[System_string8_formatLimit_VALUE] = { 0 };
    for (size i = 0; i < sizeof(message); ++i) message[i] = 0;
    size message_length = stack_System_string8_formatEnd__arguments(format, suffix, message, argc, argv);
    System_IStream_write(stream, message_length, message);
}

void  base_System_IStream_write(IStream that, size count, string8 value) { }

void  base_System_IStream_sync(IStream that) {  }

System_size  base_System_IStream_read(IStream that, size count, string8 value) { return 0; }

void  base_System_IStream_seek(IStream that, ssize offset, origin origin) { }

System_size  base_System_IStream_get_Position(IStream that) { return 0; }

void  base_System_IStream_set_Position(IStream that, size value) { }

struct System_Type_FunctionInfo  System_IStreamTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .name = "base_System_IStream_write", .function = base_System_IStream_write, .value = base_System_IStream_write },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_sync, .value = base_System_IStream_sync },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_read, .value = base_System_IStream_read },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_seek, .value = base_System_IStream_seek },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_get_Position, .value = base_System_IStream_get_Position },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_set_Position, .value = base_System_IStream_set_Position },
};

struct System_Type  System_IStreamType = { .base = stack_System_Object(System_Type),
	.name = "System.IStream",
    .size = sizeof(struct System_IStream),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_IStreamTypeFunctions), .value = &System_IStreamTypeFunctions
    },
};

#endif
