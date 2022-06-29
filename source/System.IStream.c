/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_IStream)
#include <min/System.IStream.h>
#endif
#if !defined(code_System_IStream)
#define code_System_IStream

/*# System_IStream #*/

void  base_System_IStream_write(IStream that, size count, string8 value) { }

void  base_System_IStream_sync(IStream that) {  }

System_size  base_System_IStream_read(IStream that, size count, string8 value) { return 0; }

void  base_System_IStream_seek(IStream that, ssize offset, origin origin) { }

System_size  base_System_IStream_get_Position(IStream that) { return 0; }

void  base_System_IStream_set_Position(IStream that, size value) { }

struct_System_Type_FunctionInfo  System_IStreamTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .name = "base_System_IStream_write", .function = base_System_IStream_write, .value = base_System_IStream_write },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_sync, .value = base_System_IStream_sync },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_read, .value = base_System_IStream_read },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_seek, .value = base_System_IStream_seek },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_get_Position, .value = base_System_IStream_get_Position },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_set_Position, .value = base_System_IStream_set_Position },
};

struct_System_Type  System_IStreamType = { .base = stack_System_Object(System_Type),
	.name = "System.IStream",
    .size = sizeof(struct_System_IStream),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_IStreamTypeFunctions), .value = &System_IStreamTypeFunctions
    },
};

#endif
