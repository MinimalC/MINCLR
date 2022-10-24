/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array
#define Generic_T0ArrayEnumerator  System_ArrayEnumerator

#define Generic_T0ArrayEnumeratorType  System_ArrayEnumeratorType
#endif
/* FileName Generic.T0ArrayEnumerator */
/* GENERIC */
#if !defined(Generic_internal)
#include "Generic.internal.h"
#endif
#if !defined(have_Generic_T0ArrayEnumerator)
#include <min/Generic.T0ArrayEnumerator.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_Generic_T0ArrayEnumerator)
#define code_Generic_T0ArrayEnumerator

/*# Generic_T0ArrayEnumerator #*/

Generic_T0ArrayEnumerator  base_Generic_T0ArrayEnumerator_init(Generic_T0ArrayEnumerator that, Generic_T0Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (Generic_T0Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_Generic_T0ArrayEnumerator_free(Generic_T0ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

Generic_T0  base_Generic_T0ArrayEnumerator_get_current(Generic_T0ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return Generic_T0Array_get_index(that->array, that->index);
}

System_Bool  base_Generic_T0ArrayEnumerator_moveNext(Generic_T0ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  Generic_T0ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic_T0ArrayEnumerator_init, .value = base_Generic_T0ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_Generic_T0ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_Generic_T0ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_Generic_T0ArrayEnumerator_moveNext },
};

struct System_Type  Generic_T0ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "Generic.T0ArrayEnumerator",
    .Size = sizeof(struct Generic_T0ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&Generic_T0ArrayEnumeratorTypeFunctions), .value = &Generic_T0ArrayEnumeratorTypeFunctions
    },
};

#endif
