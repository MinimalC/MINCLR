/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array
#define class_Generic_T0Array  class_System_Array
#define Generic_T0ArrayType  System_ArrayType
#endif
/* FileName Generic.T0Array */
/* GENERIC */
#if !defined(have_System)
#warning "System.h not included"
#include <meta/System.h>
#endif
#if !defined(code_auto_Generic_T0Array)
#define code_auto_Generic_T0Array

/*# Generic_T0Array #*/

Generic_T0Array  Generic_T0Array_new(System_size length) {
    return inline_Generic_T0Array_new(length);
}

struct_System_String  STRING_Generic_T0Array = const_System_String("Generic.T0Array");

struct_System_Type  Generic_T0ArrayType = { .base = { .type = typeof(System_Type) },
    .name = &STRING_Generic_T0Array,
    .size = sizeof(struct_Generic_T0Array),
    .baseType = typeof(System_Array),
};

#endif
