/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_ListEnumerator)
#include <min/System.ListEnumerator.h>
#endif
#if !defined(code_System_ListEnumerator)
#define code_System_ListEnumerator

/*# System_ListEnumerator #*/

System_ListEnumerator  base_System_ListEnumerator_init(System_ListEnumerator that, System_List array) {
    base_System_Object_init((System_Object)that);

    if (!array) throw_terminate(new_System_Exception("ArgumentNullException_new: array is null"));

    that->array = (System_List)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_ListEnumerator_free(System_ListEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Object  base_System_ListEnumerator_get_current(System_ListEnumerator that) {

    if (that->index == -2) throw_terminate(new_System_Exception("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_List_get_index(that->array, that->index);
}

System_boolean  base_System_ListEnumerator_moveNext(System_ListEnumerator that) {

    if (that->index == -2) throw_terminate(new_System_Exception("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct_System_Type_FunctionInfo  System_ListEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ListEnumerator_init, .value = base_System_ListEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_ListEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_ListEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_ListEnumerator_moveNext },
};

struct_System_Type  System_ListEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.ListEnumerator",
    .size = sizeof(struct_System_ListEnumerator),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_ListEnumeratorTypeFunctions), .value = &System_ListEnumeratorTypeFunctions
    },
};

#endif
