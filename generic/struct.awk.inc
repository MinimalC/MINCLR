/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define struct_Generic_T0  struct_System_decimal
#define Generic_T0  System_decimal
#endif
/* Type1 required */
/* GENERIC */
#if !defined(have_Generic)
#warning "Generic.h not included"
#include "Generic.internal.h"
#endif
#if !defined(code_auto_Generic_T0)
#define code_auto_Generic_T0

/*# Generic_T0 #*/

struct_System_String  STRING_Generic_T0 = const_System_String("Generic.T0");

struct_System_Type  Generic_T0Type = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_Generic_T0,
    .size = sizeof(struct_Generic_T0),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = 0, .value = {
        },
    },
};

#endif
#if !defined(code_auto_Generic1_T1)
#define code_auto_Generic1_T1

Generic1_T1  Generic1_T1_new(Generic_T0 value) {
    return inline_Generic1_T1_new(value);
}

Generic1_T1  base_Generic1_T1_init(Generic1_T1 that, Generic_T0 value) {
    base_System_Object_init((System_Object)that);

    that->value = value;

    return that;
}

System_void  base_Generic1_T1_free(Generic1_T1 that) {

    base_System_Object_free((System_Object)that);
}

struct_System_String  STRING_Generic1_T1 = const_System_String("Generic1.T1");

struct_System_Type_FunctionInfo  Generic1_T1TypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic1_T1_init, .value = base_Generic1_T1_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_Generic1_T1_free },
};

struct_System_Type  Generic1_T1Type = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_Generic1_T1,
    .size = sizeof(struct_Generic1_T1),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&Generic1_T1TypeFunctions), .value = &Generic1_T1TypeFunctions
    },
};

#endif
