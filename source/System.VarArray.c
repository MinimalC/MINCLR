/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_VarArray)
#include <min/System.VarArray.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_VarArray)
#define code_System_VarArray

/*# System_VarArray #*/

System_VarArray base_System_VarArray_init(System_VarArray that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_Var (* array)[] = System_Memory_allocArray(typeof(System_Var), length);
    that->value = array;

    return that;
}

void  base_System_VarArray_free(System_VarArray that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_VarArray_get_Length(System_VarArray that) {
    return that->length;
}

System_Var  base_System_VarArray_get_index(System_VarArray that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_VarArray_set_index(System_VarArray that, System_Size index, System_Var value) {
    array(that->value)[index] = value;
}

void  base_System_VarArray_resize(System_VarArray that, System_Size length) {
    System_Size element_size = sizeof(System_Var);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_VarArray_getEnumerator(System_VarArray that) {
    return (System_IEnumerator)new_System_VarArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_VarArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_VarArray_init, .value = base_System_VarArray_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_VarArray_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_VarArray_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_VarArray_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_VarArray_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_VarArray_resize, .value = base_System_VarArray_resize },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_System_VarArray_getEnumerator },
};

struct System_Type_InterfaceInfo  System_VarArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct System_Type  System_VarArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.VarArray",
    .size = sizeof(struct System_VarArray),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&System_VarArrayTypeFunctions), .value = &System_VarArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(&System_VarArrayTypeInterfaces), .value = &System_VarArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(code_System_VarArrayEnumerator)
#define code_System_VarArrayEnumerator

/*# System_VarArrayEnumerator #*/

System_VarArrayEnumerator  base_System_VarArrayEnumerator_init(System_VarArrayEnumerator that, System_VarArray array) {
    base_System_Object_init((System_Object)that);

    if (!array) throw_terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_VarArray)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_VarArrayEnumerator_free(System_VarArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Var  base_System_VarArrayEnumerator_get_current(System_VarArrayEnumerator that) {

    if (that->index == -2) throw_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_VarArray_get_index(that->array, that->index);
}

System_Bool  base_System_VarArrayEnumerator_moveNext(System_VarArrayEnumerator that) {

    if (that->index == -2) throw_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_VarArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_VarArrayEnumerator_init, .value = base_System_VarArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_VarArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_VarArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_VarArrayEnumerator_moveNext },
};

struct System_Type  System_VarArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.VarArrayEnumerator",
    .size = sizeof(struct System_VarArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(&System_VarArrayEnumeratorTypeFunctions), .value = &System_VarArrayEnumeratorTypeFunctions
    },
};

#endif
