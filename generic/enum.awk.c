/* Gemeinfrei. Public Domain. */
/* GENERIC */
#if !defined(Generic_internal)
#include "Generic.internal.h"
#endif
#if !defined(have_Generic_T0)
#include <min/Generic.T0.h>
#endif
#if !defined(code_Generic_T0)

struct System_Type_FieldInfo  Generic_T0TypeFields[] = {
    [0] = { .name = "T0.Null", .value = Generic_T0_Null },
};

struct System_Type Generic_T0Type = { .base = { .type = typeof(System_Type) },
    .name = "Generic.T0",
    .size = sizeof(Generic_T0),
	.fields = { 
        .value = &Generic_T0TypeFields, .length = sizeof_array(Generic_T0TypeFields),
    },
};

#endif