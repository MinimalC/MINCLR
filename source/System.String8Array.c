/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_String8Array)
#include <min/System.String8Array.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_String8Array)
#define code_System_String8Array

/*# System_String8Array #*/

System_String8Array  new_System_String8Array(System_Size capacity) {
    System_String8Array that = (System_String8Array)System_Memory_allocClass(typeof(System_String8Array));
    base_System_String8Array_init(that, capacity);
    return that;
}

void base_System_String8Array_init(System_String8Array that, System_Size capacity) {
    that->value = System_Memory_allocArray(typeof(System_String8), capacity);
    that->capacity = capacity;
}

void  base_System_String8Array_free(System_String8Array that) {
    /*for (System_Size i = 0; i < that->length; ++i)
        System_Memory_free(array_item(that->value, i));*/
    System_Memory_free(that->value);
    System_Memory_free(that->buffer);
}

System_Size  base_System_String8Array_get_Length(System_String8Array that) {
    return that->length;
}

System_String8  base_System_String8Array_get_index(System_String8Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_String8Array_set_index(System_String8Array that, System_Size index, System_String8 value) {
    /* System_String8 old = array(that->value)[index];
    if (old) System_Memory_free(old); */
    array(that->value)[index] = value; // System_Memory_addReference(value);
}

void  base_System_String8Array_add(System_String8Array that, System_String8 item) {
    // TODO: check length and capacity
    base_System_String8Array_set_index(that, that->length, item);
    ++that->length;
}

void  base_System_String8Array_remove(System_String8Array that, System_Size index) {
    base_System_String8Array_set_index(that, index, null);
    System_Size length = that->length - 1;
    for (Size i = index; i < length; ++i)
        *(array(that->value) + i) = *(array(that->value) + i + 1);
    --that->length;
    *(array(that->value) + that->length) = null;
}

void  base_System_String8Array_resize(System_String8Array that, System_Size capacity) {
    System_Memory_reallocArray((System_Var)that->value, capacity);
    that->capacity = capacity;
}

System_IEnumerator  base_System_String8Array_getEnumerator(System_String8Array that) {
    return (System_IEnumerator)new_System_String8ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_String8ArrayTypeFunctions[] = {
    [0] = { .function = base_System_String8Array_init, .value = base_System_String8Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_String8Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_String8Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_String8Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_String8Array_set_index },
    [5] = { .function = base_System_String8Array_resize, .value = base_System_String8Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_String8Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_String8ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_String8ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "String8Array",
    .size = sizeof(struct System_String8Array),
    .baseType = typeof(System_Object),
    .functions = {
        .length = sizeof_array(System_String8ArrayTypeFunctions), .value = &System_String8ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_String8ArrayTypeInterfaces), .value = &System_String8ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(code_System_String8ArrayEnumerator)
#define code_System_String8ArrayEnumerator

/*# System_String8ArrayEnumerator #*/

System_String8ArrayEnumerator  new_System_String8ArrayEnumerator(System_String8Array array) {
    System_String8ArrayEnumerator that = (System_String8ArrayEnumerator)System_Memory_allocClass(typeof(System_String8ArrayEnumerator));
    base_System_String8ArrayEnumerator_init(that, array);
    return that;
}

void  base_System_String8ArrayEnumerator_init(System_String8ArrayEnumerator that, System_String8Array array) {

    if (!array) System_Exception_terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_String8Array)System_Memory_addReference((System_Object)array);
    that->index = -1;
}

void  base_System_String8ArrayEnumerator_free(System_String8ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;
}

System_String8  base_System_String8ArrayEnumerator_get_current(System_String8ArrayEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) { System_Exception_throw(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate")); return false; }

    return System_String8Array_get_index(that->array, that->index);
}

System_Bool  base_System_String8ArrayEnumerator_moveNext(System_String8ArrayEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_String8ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_String8ArrayEnumerator_init, .value = base_System_String8ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_String8ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_String8ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_String8ArrayEnumerator_moveNext },
};

struct System_Type System_String8ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "String8ArrayEnumerator",
    .size = sizeof(struct System_String8ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = {
        .length = sizeof_array(System_String8ArrayEnumeratorTypeFunctions), .value = &System_String8ArrayEnumeratorTypeFunctions
    },
};

#endif
