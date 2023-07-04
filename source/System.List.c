/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_List)
#include <min/System.List.h>
#endif
#if !defined(code_System_List)
#define code_System_List

/*# System_List #*/

const System_Size  System_List_Capacity = System_List_Capacity_DEFAULT;

System_List  base_System_List_init(System_List that) {
    base_System_Object_init((System_Object)that);

    that->capacity = System_List_Capacity;
    that->hashes = new_System_UInt64Array(that->capacity);
    that->items = new_System_Array(that->capacity);

    return that;
}

void  base_System_List_free(System_List that) {

    System_Memory_free(that->hashes);
    System_Memory_free(that->items);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_List_get_Length(System_List that) {
    return that->length;
}

System_Object  base_System_List_get_index(System_List that, Size index) {
	Debug_assert(that);
	return Array_get_index(that->items, index);
}

void  base_System_List_set_index(System_List that, Size index, System_Object value) {
	Debug_assert(that);
    if (value) {
        if (base_System_List_contains(that, value)) throw(new_Exception("InvalidOperationException: System_List: System_Object already added"))
        UInt64Array_set_index(that->hashes, index, Object_getSipHash(value));
    }
    Array_set_index(that->items, index, value);
}

System_IEnumerator base_System_List_getEnumerator(System_List that) {
    return (System_IEnumerator)new_System_ListEnumerator(that);
}

System_Bool  base_System_List_contains(System_List that, System_Object object) {

    UInt64 object_siphash = Object_getSipHash(object);

    for (Size i = 0; i < that->length; ++i) {
        if (object_siphash == UInt64Array_get_index(that->hashes, i)) return true;
    }
    return false;
}

void  base_System_List_add(System_List that, System_Object object) {
    Debug_assert(object);

    if (base_System_List_contains(that, object)) throw(new_Exception("InvalidOperationException: System.List: System_Object already added."))

    Size new_i = that->length;
    if (new_i >= that->capacity) {
        Size new_capacity = that->capacity * 2;
        UInt64Array_resize(that->hashes, new_capacity);
        Array_resize(that->items, new_capacity);
        that->capacity = new_capacity;
    }

    UInt64Array_set_index(that->hashes, new_i, Object_getSipHash(object));
    Array_set_index(that->items, new_i, object);
    ++that->length;
}

struct System_Type_FunctionInfo  System_ListTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_List_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_List_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_List_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_List_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_List_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_System_List_getEnumerator },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_List_contains, .value = base_System_List_contains },
    [7] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_List_add, .value = base_System_List_add },
};

struct System_Type_InterfaceInfo  System_ListTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct System_Type System_ListType = { .base = { .type = typeof(System_Type) },
    .name = "List",
    .size = sizeof(struct System_List),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_ListTypeFunctions), .value = &System_ListTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(System_ListTypeInterfaces), .value = &System_ListTypeInterfaces
    },
};

#endif
