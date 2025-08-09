/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_IStream)
#include <min/System.IStream.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(code_System_IStream)
#define code_System_IStream

/** class System_IStream  **/

System_Size  base_System_IStream_write__string_size(IStream that, String8 value, Size count) { }

void  base_System_IStream_sync(IStream that) {  }

System_Size  base_System_IStream_read(IStream that, String8 value, Size count) { return 0; }

System_Size  base_System_IStream_seek(IStream that, SSize offset, Origin origin) { }

System_Size  base_System_IStream_get_Position(IStream that) { return 0; }

void  base_System_IStream_set_Position(IStream that, Size value) { }

struct System_Type_FunctionInfo  System_IStreamTypeFunctions[] = {
    { .function = base_System_IStream_write__string_size, .value = null },
    { .function = base_System_IStream_sync, .value = null },
    { .function = base_System_IStream_read, .value = null },
    { .function = base_System_IStream_seek, .value = null },
    { .function = base_System_IStream_get_Position, .value = null },
    { .function = base_System_IStream_set_Position, .value = null },
};

struct System_Type System_IStreamType = { .base = { .type = typeof(System_Type) },
	.name = "IStream",
    .size = sizeof(struct System_IStream),
    .functions = { 
        .length = sizeof_array(System_IStreamTypeFunctions), .value = &System_IStreamTypeFunctions
    },
};

void  System_IStream_write(IStream stream, String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_IStream_writeEnd__arguments(stream, format, 0, argc, argv);
}

void  System_IStream_write__arguments(IStream stream, String8 format, Size argc, Var argv[]) {
    System_IStream_writeEnd__arguments(stream, format, 0, argc, argv);
}

void  System_IStream_writeLine(IStream stream, String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_IStream_writeEnd__arguments(stream, format, '\n', argc, argv);
}

void  System_IStream_writeLine__arguments(IStream stream, String8 format, Size argc, Var argv[]) {
    System_IStream_writeEnd__arguments(stream, format, '\n', argc, argv);
}

void  System_IStream_writeEnd(IStream stream, String8 format, Char8 suffix, ...) {
    Arguments args;
    Arguments_start(args, suffix);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_IStream_writeEnd__arguments(stream, format, suffix, argc, argv);
}

void  System_IStream_writeEnd__arguments(IStream stream, String8 format, Char8 suffix, Size argc, Var argv[]) {

    Char8  message[System_String8_FormatLimit_VALUE]; System_Stack_clear(message);

    Size message_length = stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
    System_IStream_write__string_size(stream, message, message_length);
}

#endif
