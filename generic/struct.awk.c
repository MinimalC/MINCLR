/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"

#define Generic_T0  System_Decimal
#endif
/* Type1 required */
/* GENERIC */
#if !defined(Generic_internal)
#include "Generic.internal.h"
#endif
#if !defined(have_Generic_T0)
#include <min/Generic.T0.h>
#endif
#if !defined(code_Generic_T0)
#define code_Generic_T0

/*# Generic_T0 #*/

struct System_Type Generic_T0Type = { .base = { .type = typeof(System_Type) },
    .name = "Generic.T0",
    .size = sizeof(struct Generic_T0),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = 0, .value = {
        },
    },
};

#endif
#if !defined(code_Generic1_T1)
#define code_Generic1_T1

Generic1_T1  base_Generic1_T1_init(Generic1_T1 that, Generic_T0 value) {

    that->value = value;

    return that;
}

void  base_Generic1_T1_free(Generic1_T1 that) {

}

struct System_Type_FunctionInfo  Generic1_T1TypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic1_T1_init, .value = base_Generic1_T1_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_Generic1_T1_free },
};

struct System_Type Generic1_T1Type = { .base = { .type = typeof(System_Type) },
    .name = "Generic1.T1",
    .size = sizeof(struct Generic1_T1),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&Generic1_T1TypeFunctions), .value = &Generic1_T1TypeFunctions
    },
};

#endif
