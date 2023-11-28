/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_ListEnumerator)
#include <min/System.ListEnumerator.h>
#endif
#if !defined(code_System_ListEnumerator)
#define code_System_ListEnumerator

/*# System_ListEnumerator #*/

System_ListEnumerator  new_System_ListEnumerator(System_List array) {
    System_ListEnumerator that = (System_ListEnumerator)System_Memory_allocClass(typeof(System_ListEnumerator));
    base_System_ListEnumerator_init(that, array);
    return that;
}

void  base_System_ListEnumerator_init(System_ListEnumerator that, System_List array) {

    if (!array) System_Exception_terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_List)System_Memory_addReference((System_Object)array);
    that->index = -1;
}

void  base_System_ListEnumerator_free(System_ListEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;
}

System_Object  base_System_ListEnumerator_get_current(System_ListEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) { System_Exception_throw(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate")); return false; }

    return System_List_get_index(that->array, that->index);
}

System_Bool  base_System_ListEnumerator_moveNext(System_ListEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_ListEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_ListEnumerator_init, .value = base_System_ListEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_ListEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_ListEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_ListEnumerator_moveNext },
};

struct System_Type System_ListEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "ListEnumerator",
    .size = sizeof(struct System_ListEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_ListEnumeratorTypeFunctions), .value = &System_ListEnumeratorTypeFunctions
    },
};

#endif
