/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array

#define Generic_T0ArrayType  System_ArrayType
#endif
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

Generic_T0  base_Generic_T0_init(Generic_T0 that) {
    base_System_Object_init((System_Object)that);

    return that;
}

void  base_Generic_T0_free(Generic_T0 that) {

    base_System_Object_free((System_Object)that);
}

struct System_Type_FunctionInfo  Generic_T0TypeFunctions[] = {
    [0] = { .function = base_System_Object_init, .value = base_Generic_T0_init },
    [1] = { .function = base_System_Object_free, .value = base_Generic_T0_free },
};

struct System_Type Generic_T0Type = { .base = { .type = typeof(System_Type) },
    .name = "Generic.T0",
    .size = sizeof(struct Generic_T0),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(&Generic_T0TypeFunctions), .value = &Generic_T0TypeFunctions
    },
};

#endif
