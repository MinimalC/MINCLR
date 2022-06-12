#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_IStream)
#define code_System_IStream

/*# System_IStream #*/

System_void  base_System_IStream_write(__IStream that, __size count, __string8 value) { }

System_void  base_System_IStream_sync(__IStream that) {  }

System_size  base_System_IStream_read(__IStream that, __size count, __string8 value) { return 0; }

System_void  base_System_IStream_seek(__IStream that, __ssize offset, enum_origin origin) { }

System_size  base_System_IStream_get_Position(__IStream that) { return 0; }

System_void  base_System_IStream_set_Position(__IStream that, __size value) { }

struct_System_String  STRING_System_IStream = const_System_String("System.IStream");

struct_System_Type_FunctionInfo  System_IStreamTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_write, .value = base_System_IStream_write },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_sync, .value = base_System_IStream_sync },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_read, .value = base_System_IStream_read },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_seek, .value = base_System_IStream_seek },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_get_Position, .value = base_System_IStream_get_Position },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IStream_set_Position, .value = base_System_IStream_set_Position },
};

struct_System_Type  System_IStreamType = { .base = stack_System_Object(System_Type),
	.name = &STRING_System_IStream,
    .size = sizeof(struct_System_IStream),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_IStreamTypeFunctions), .value = &System_IStreamTypeFunctions
    },
};

#endif
