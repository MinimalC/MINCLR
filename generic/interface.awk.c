/* Gemeinfrei. Public Domain. */
/* GENERIC */
#if !defined(Generic_internal)
#include "Generic.internal.h"
#endif
#if !defined(have_Generic_T0)
#include <min/Generic.T0.h>
#endif
#if !defined(code_Generic_T0)
#define code_Generic_T0

/*# interface Generic.T0 #*/

struct System_Type_FunctionInfo  Generic_T0TypeFunctions[] = {
/*    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic_T0_method, .value = base_Generic_T0_method }, */
};

struct System_Type Generic_T0Type = { .base = stack_System_Object(System_Type),
	.name = "Generic.T0",
    .size = sizeof(struct Generic_T0),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&Generic_T0TypeFunctions), .value = &Generic_T0TypeFunctions
    },
};

/* void  base_Generic_T0_method(Generic_T0 that, System_String arg1) {  } */

#endif
