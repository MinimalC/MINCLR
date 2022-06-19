/* Gemeinfrei. Public Domain. */
#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_auto_System_StreamWriter)
#define code_auto_System_StreamWriter

/*# System_StreamWriter #*/

System_StreamWriter  System_StreamWriter_new(System_IStream stream) {
    return inline_System_StreamWriter_new(stream);
}
System_StreamWriter  base_System_StreamWriter_init(System_StreamWriter that, System_IStream stream) {
    base_System_Object_init((System_Object)that);

    that->stream = stream;
    return that;
}

System_void  base_System_StreamWriter_write(System_StreamWriter that, System_string8 format, ...) {
    __arguments args;
    __arguments_start(args, format);
    System_string8_formatSuffixTo__arguments(format, 0, that->stream, args);
    __arguments_end(args);
}

void  base_System_StreamWriter_free(System_StreamWriter that) {
    base_System_Object_free((System_Object)that);
}

struct_System_Type_FunctionInfo  System_StreamWriterTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_StreamWriter_init, .value = base_System_StreamWriter_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_StreamWriter_write, .value = base_System_StreamWriter_write },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_StreamWriter_free },
};

struct_System_Type  System_StreamWriterType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.StreamWriter",
    .size = sizeof(struct_System_StreamWriter),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_StreamWriterTypeFunctions), .value = &System_StreamWriterTypeFunctions
    },
};
#endif
