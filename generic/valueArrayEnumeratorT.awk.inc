/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array
#define Generic_T0ArrayEnumerator  System_ArrayEnumerator
#define struct_Generic_T0ArrayEnumerator  struct_System_ArrayEnumerator
#define Generic_T0ArrayEnumeratorType  System_ArrayEnumeratorType
#endif
/* FileName Generic.T0ArrayEnumerator */
/* GENERIC */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <meta/System.Type.h>
#endif
#if !defined(code_auto_Generic_T0ArrayEnumerator)
#define code_auto_Generic_T0ArrayEnumerator

/*# Generic_T0ArrayEnumerator #*/

Generic_T0ArrayEnumerator  Generic_T0ArrayEnumerator_new(Generic_T0Array array) {
    return inline_Generic_T0ArrayEnumerator_new(array);
}

Generic_T0ArrayEnumerator  base_Generic_T0ArrayEnumerator_init(Generic_T0ArrayEnumerator that, Generic_T0Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (Generic_T0Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_Generic_T0ArrayEnumerator_free(Generic_T0ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

Generic_T0  base_Generic_T0ArrayEnumerator_get_current(Generic_T0ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return Generic_T0Array_get_index(that->array, that->index);
}

System_boolean  base_Generic_T0ArrayEnumerator_moveNext(Generic_T0ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_String  STRING_Generic_T0ArrayEnumerator = const_System_String("Generic.T0ArrayEnumerator");

struct_System_Type_FunctionInfo  Generic_T0ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_Generic_T0ArrayEnumerator_init, .value = base_Generic_T0ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_Generic_T0ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_Generic_T0ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_Generic_T0ArrayEnumerator_moveNext },
};

struct_System_Type  Generic_T0ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_Generic_T0ArrayEnumerator,
    .size = sizeof(struct_Generic_T0ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&Generic_T0ArrayEnumeratorTypeFunctions), .value = &Generic_T0ArrayEnumeratorTypeFunctions
    },
};

#endif
