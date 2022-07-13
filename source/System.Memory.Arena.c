/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Memory_Arena)
#include <min/System.Memory.Arena.h>
#endif
#if !defined(code_System_Memory_Arena)
#define code_System_Memory_Arena

/*# System_Memory_Arena #*/

System_Memory_Arena  System_Memory_Arena_new() {
    return inline_System_Memory_Arena_new(length);
}

void  base_System_Memory_Arena_init(System_Memory_Arena that) {
    base_System_Object_init((System_Object)that);

}

void  base_System_Memory_Arena_free(System_Memory_Arena that) {

    base_System_Object_free((System_Object)that);
}

struct_System_Type_FunctionInfo  System_Memory_ArenaTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Memory_Arena_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Memory_Arena_free },
};

struct_System_Type_InterfaceInfo  System_Memory_ArenaTypeInterfaces[] = { };

struct_System_Type  System_Memory_ArenaType = { .base = { .type = typeof(System_Type) },
    .name = "System.Memory.Arena",
    .size = sizeof(struct_System_Memory_Arena),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&System_Memory_ArenaTypeFunctions), .value = &System_Memory_ArenaTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(&System_Memory_ArenaTypeInterfaces), .value = &System_Memory_ArenaTypeInterfaces
    },
};

#endif
