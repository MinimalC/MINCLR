/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_IStream)
#include <min/System.IStream.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(code_System_IStream)
#define code_System_IStream

/*# System_IStream #*/

void  base_System_IStream_write__string_size(IStream that, String8 value, Size count) { }

void  base_System_IStream_sync(IStream that) {  }

System_Size  base_System_IStream_read(IStream that, String8 value, Size count) { return 0; }

System_Size  base_System_IStream_seek(IStream that, SSize offset, origin origin) { }

System_Size  base_System_IStream_get_Position(IStream that) { return 0; }

void  base_System_IStream_set_Position(IStream that, Size value) { }

struct System_Type_FunctionInfo  System_IStreamTypeFunctions[] = {
    [0] = { .name = "base_System_IStream_write__string_size", .function = base_System_IStream_write__string_size, .value = null },
    [1] = { .name = "base_System_IStream_writeEnd__arguments", .function = base_System_IStream_writeEnd__arguments, .value = null },
    [2] = { .function = base_System_IStream_sync, .value = null },
    [3] = { .function = base_System_IStream_read, .value = null },
    [4] = { .function = base_System_IStream_seek, .value = null },
    [5] = { .function = base_System_IStream_get_Position, .value = null },
    [6] = { .function = base_System_IStream_set_Position, .value = null },
};

struct System_Type System_IStreamType = { .base = stack_System_Object(System_Type),
	.name = "IStream",
    .size = sizeof(struct System_IStream),
    .functions = { 
        .length = sizeof_array(System_IStreamTypeFunctions), .value = &System_IStreamTypeFunctions
    },
};

void  System_IStream_write(IStream stream, String8 format, ...) {
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    base_System_IStream_writeEnd__arguments(stream, format, 0, argc, argv);
}

void  System_IStream_write__arguments(IStream stream, String8 format, Size argc, Var argv[]) {
    base_System_IStream_writeEnd__arguments(stream, format, 0, argc, argv);
}

void  System_IStream_writeLine(IStream stream, String8 format, ...) {
    arguments args;
    arguments_start(args, format);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    base_System_IStream_writeEnd__arguments(stream, format, '\n', argc, argv);
}

void  System_IStream_writeLine__arguments(IStream stream, String8 format, Size argc, Var argv[]) {
    base_System_IStream_writeEnd__arguments(stream, format, '\n', argc, argv);
}

void  System_IStream_writeEnd(IStream stream, String8 format, Char8 suffix, ...) {
    arguments args;
    arguments_start(args, suffix);
    Var argv[System_arguments_Limit_VALUE];
    Size argc = stack_System_arguments_get(args, argv);
    arguments_end(args);
    base_System_IStream_writeEnd__arguments(stream, format, suffix, argc, argv);
}

void  base_System_IStream_writeEnd__arguments(IStream stream, String8 format, Char8 suffix, Size argc, Var argv[]) {

    Char8  message[System_String8_formatLimit_VALUE]; for (Size i = 0; i < System_String8_formatLimit_VALUE; ++i) message[i] = 0;

    Size message_length = stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
    System_IStream_write__string_size(stream, message, message_length);
}

#endif
