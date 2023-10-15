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
};

#endif
#if !defined(code_Generic1_T1)
#define code_Generic1_T1

Generic1_T1  new_Generic1_T1(Generic_T0 value) {
    Generic1_T1 that = (Generic1_T1)System_Memory_allocClass(typeof(Generic1_T1));
    base_Generic1_T1_init(that, value);
    return that;
}

void  base_Generic1_T1_init(Generic1_T1 that, Generic_T0 value) {

    that->value = value;
}

void  base_Generic1_T1_free(Generic1_T1 that) {

}

struct System_Type_FunctionInfo  Generic1_T1TypeFunctions[] = {
    { .function = base_Generic1_T1_init, .value = base_Generic1_T1_init },
    { .function = base_System_Object_free, .value = base_Generic1_T1_free },
};

struct System_Type Generic1_T1Type = { .base = { .type = typeof(System_Type) },
    .name = "Generic1.T1",
    .size = sizeof(struct Generic1_T1),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(Generic1_T1TypeFunctions), .value = &Generic1_T1TypeFunctions
    },
};

#endif
