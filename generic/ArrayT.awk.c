/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array
#define Generic_T0ArrayType  System_ArrayType
#endif
/* FileName Generic.T0Array */
/* GENERIC */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(code_Generic_T0Array)
#define code_Generic_T0Array

/*# Generic_T0Array #*/

struct System_Type  Generic_T0ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "Generic.T0Array",
    .size = sizeof(struct Generic_T0Array),
    .baseType = typeof(System_Array),
};

#endif
