/* Gemeinfrei. Public Domain. */
/* GENERIC */
#if !defined(have_Generic)
#warning "Generic.h not included"
#include "Generic.internal.h"
#endif
#if !defined(code_auto_Generic_T0)
#define code_auto_Generic_T0

/*# interface Generic.T0 #*/

struct_System_String  STRING_Generic_T0 = const_System_String("Generic.T0");

struct_System_Type_FunctionInfo  Generic_T0TypeFunctions[] = {
/*    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic_T0_method, .value = base_Generic_T0_method }, */
};

struct_System_Type  Generic_T0Type = { .base = stack_System_Object(System_Type),
	.name = &STRING_Generic_T0,
    .size = sizeof(struct_Generic_T0),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&Generic_T0TypeFunctions), .value = &Generic_T0TypeFunctions
    },
};

/* System_void  base_Generic_T0_method(Generic_T0 that, System_String arg1) {  } */
#endif
