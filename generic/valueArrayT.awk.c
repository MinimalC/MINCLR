/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array
#define Generic_T0ArrayType  System_ArrayType
#endif
/* FileName Generic.T0Array */
/* seeAlso valueArrayEnumeratorT */
/* GENERIC */
#if !defined(Generic_internal)
#include "Generic.internal.h"
#endif
#if !defined(have_Generic_T0Array)
#include <min/System.valueArrays.auto.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_Generic_T0Array)
#define code_Generic_T0Array

/*# Generic_T0Array #*/

Generic_T0Array base_Generic_T0Array_init(Generic_T0Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    Generic_T0 (* array)[] = System_Memory_allocArray(typeof(Generic_T0), length);
    that->value = array;

    return that;
}

void  base_Generic_T0Array_free(Generic_T0Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_Generic_T0Array_get_Length(Generic_T0Array that) {
    return that->length;
}

Generic_T0  base_Generic_T0Array_get_index(Generic_T0Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_Generic_T0Array_set_index(Generic_T0Array that, System_Size index, Generic_T0 value) {
    array(that->value)[index] = value;
}

void  base_Generic_T0Array_resize(Generic_T0Array that, System_Size length) {
    System_Size element_size = sizeof(Generic_T0);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_Generic_T0Array_getEnumerator(Generic_T0Array that) {
    return (System_IEnumerator)new_Generic_T0ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  Generic_T0ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic_T0Array_init, .value = base_Generic_T0Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_Generic_T0Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_Generic_T0Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_Generic_T0Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_Generic_T0Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic_T0Array_resize, .value = base_Generic_T0Array_resize },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_Generic_T0Array_getEnumerator },
};

struct System_Type_InterfaceInfo  Generic_T0ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct System_Type Generic_T0ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "Generic.T0Array",
    .size = sizeof(struct Generic_T0Array),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&Generic_T0ArrayTypeFunctions), .value = &Generic_T0ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(&Generic_T0ArrayTypeInterfaces), .value = &Generic_T0ArrayTypeInterfaces
    },
};

#endif
