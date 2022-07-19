/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_varArray)
#include <min/System.varArray.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_varArray)
#define code_System_varArray

/*# System_varArray #*/

System_varArray base_System_varArray_init(System_varArray that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_var (* array)[] = System_Memory_allocArray(typeof(System_var), length);
    that->value = array;

    return that;
}

void  base_System_varArray_free(System_varArray that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_varArray_get_Length(System_varArray that) {
    return that->length;
}

System_var  base_System_varArray_get_index(System_varArray that, System_size index) {
    return array(that->value)[index];
}

void  base_System_varArray_set_index(System_varArray that, System_size index, System_var value) {
    array(that->value)[index] = value;
}

void  base_System_varArray_resize(System_varArray that, System_size length) {
    System_size element_size = sizeof(System_var);
    System_Memory_reallocArray((System_var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_varArray_getEnumerator(System_varArray that) {
    return (System_IEnumerator)new_System_varArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_varArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_varArray_init, .value = base_System_varArray_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_varArray_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_varArray_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_varArray_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_varArray_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_varArray_resize, .value = base_System_varArray_resize },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_System_varArray_getEnumerator },
};

struct System_Type_InterfaceInfo  System_varArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct System_Type  System_varArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.varArray",
    .size = sizeof(struct System_varArray),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&System_varArrayTypeFunctions), .value = &System_varArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(&System_varArrayTypeInterfaces), .value = &System_varArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(code_System_varArrayEnumerator)
#define code_System_varArrayEnumerator

/*# System_varArrayEnumerator #*/

System_varArrayEnumerator  base_System_varArrayEnumerator_init(System_varArrayEnumerator that, System_varArray array) {
    base_System_Object_init((System_Object)that);

    if (!array) throw_terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_varArray)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_varArrayEnumerator_free(System_varArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_var  base_System_varArrayEnumerator_get_current(System_varArrayEnumerator that) {

    if (that->index == -2) throw_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_varArray_get_index(that->array, that->index);
}

System_boolean  base_System_varArrayEnumerator_moveNext(System_varArrayEnumerator that) {

    if (that->index == -2) throw_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct System_Type_FunctionInfo  System_varArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_varArrayEnumerator_init, .value = base_System_varArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_varArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_varArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_varArrayEnumerator_moveNext },
};

struct System_Type  System_varArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.varArrayEnumerator",
    .size = sizeof(struct System_varArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&System_varArrayEnumeratorTypeFunctions), .value = &System_varArrayEnumeratorTypeFunctions
    },
};

#endif
