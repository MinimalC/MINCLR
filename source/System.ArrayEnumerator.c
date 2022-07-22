/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_ArrayEnumerator)
#include <min/System.ArrayEnumerator.h>
#endif
#if !defined(code_System_ArrayEnumerator)
#define code_System_ArrayEnumerator

/*# System_ArrayEnumerator #*/

System_ArrayEnumerator  base_System_ArrayEnumerator_init(System_ArrayEnumerator that, System_Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_ArrayEnumerator_free(System_ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Object  base_System_ArrayEnumerator_get_current(System_ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_Array_get_index(that->array, that->index);
}

System_Bool  base_System_ArrayEnumerator_moveNext(System_ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ArrayEnumerator_init, .value = base_System_ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_ArrayEnumerator_moveNext },
};

struct System_Type  System_ArrayEnumeratorType = {
    .base = { .type = typeof(System_Type) },
    .name = "System.ArrayEnumerator",
    .size = sizeof(struct System_ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_ArrayEnumeratorTypeFunctions), .value = &System_ArrayEnumeratorTypeFunctions
    },
};

#endif
