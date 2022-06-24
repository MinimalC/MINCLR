/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array
#define struct_Generic_T0Array  struct_System_Array
#define Generic_T0ArrayType  System_ArrayType
#endif
/* GENERIC */
#if !defined(have_Generic)
#warning "Generic.h not included"
#include "Generic.internal.h"
#endif
#if !defined(code_auto_Generic_T0)
#define code_auto_Generic_T0

/*# Generic_T0 #*/

Generic_T0  Generic_T0_new() {
    return inline_Generic_T0_new();
}

Generic_T0  base_Generic_T0_init(Generic_T0 that) {
    base_System_Object_init((System_Object)that);

    return that;
}

System_void  base_Generic_T0_free(Generic_T0 that) {

    base_System_Object_free((System_Object)that);
}

struct_System_String  STRING_Generic_T0 = const_System_String("Generic.T0");

struct_System_Type_FunctionInfo  Generic_T0TypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_Generic_T0_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_Generic_T0_free },
};

struct_System_Type  Generic_T0Type = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_Generic_T0,
    .size = sizeof(struct_Generic_T0),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&Generic_T0TypeFunctions), .value = &Generic_T0TypeFunctions
    },
};

#endif

