/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Memory_Header)
#include <min/System.Memory.Header.h>
#endif
#if !defined(code_System_Memory_Header)
#define code_System_Memory_Header

/*# System_Memory_Header #*/

System_Memory_Header  System_Memory_Header_new() {
    return inline_System_Memory_Header_new();
}

System_Memory_Header  base_System_Memory_Header_init(System_Memory_Header that) {
    base_System_Object_init((System_Object)that);

    return that;
}

void  base_System_Memory_Header_free(System_Memory_Header that) {

    base_System_Object_free((System_Object)that);
}

struct_System_Type_FunctionInfo  System_Memory_HeaderTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Memory_Header_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Memory_Header_free },
};

struct_System_Type  System_Memory_HeaderType = { .base = { .type = typeof(System_Type) },
    .name = "System.MemoryHeader",
    .size = sizeof(struct_System_Memory_Header),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&System_Memory_HeaderTypeFunctions), .value = &System_Memory_HeaderTypeFunctions
    },
};

#endif
