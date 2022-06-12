/* Gemeinfrei. Public Domain. */

#if !defined(have_System_Type)
#include "System.internal.h"
#endif
#if !defined(code_System_ListEnumerator)
#define code_System_ListEnumerator

/*# System_ListEnumerator #*/

System_ListEnumerator  System_ListEnumerator_new(System_List array) {
    return inline_System_ListEnumerator_new(array);
}

System_ListEnumerator  base_System_ListEnumerator_init(System_ListEnumerator that, System_List array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_List)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_ListEnumerator_free(System_ListEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Object  base_System_ListEnumerator_get_current(System_ListEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_List_get_index(that->array, that->index);
}

System_boolean  base_System_ListEnumerator_moveNext(System_ListEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return __true;
    }
    return __false;
}

struct_System_String  STRING_System_ListEnumerator = const_System_String("System.ListEnumerator");

struct_System_Type_FunctionInfo  System_ListEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ListEnumerator_init, .value = base_System_ListEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_ListEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_ListEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_ListEnumerator_moveNext },
};

struct_System_Type  System_ListEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_ListEnumerator,
    .size = sizeof(struct_System_ListEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&System_ListEnumeratorTypeFunctions), .value = &System_ListEnumeratorTypeFunctions
    },
};

#endif
