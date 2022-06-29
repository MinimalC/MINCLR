/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_List)
#include <min/System.List.h>
#endif
#if !defined(code_System_List)
#define code_System_List

/*# System_List #*/

const System_size  System_List_Capacity = System_List_Capacity_DEFAULT;

System_List  System_List_new() {
    return inline_System_List_new();
}

System_List  base_System_List_init(System_List that) {
    base_System_Object_init((System_Object)that);

    that->capacity = System_List_Capacity;
    that->hashes = System_uint64Array_new(that->capacity);
    that->items = System_Array_new(that->capacity);

    return that;
}

void  base_System_List_free(System_List that) {

    inline_System_Object_freeClass(&that->hashes);
    inline_System_Object_freeClass(&that->items);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_List_get_Length(System_List that) {
    return that->length;
}

System_Object  base_System_List_get_index(System_List that, size index) {
	assert(that)
	return Array_get_index(that->items, index);
}

void  base_System_List_set_index(System_List that, size index, System_Object value) {
	assert(that)
    if (value) {
        if (base_System_List_contains(that, value)) throw(inline_Exception_new("InvalidOperationException_new: System_List: System_Object already added"))
        uint64Array_set_index(that->hashes, index, Object_getSipHash(value));
    }
    Array_set_index(that->items, index, value);
}

System_IEnumerator base_System_List_getEnumerator(System_List that) {
    return (System_IEnumerator)inline_System_ListEnumerator_new(that);
}

System_boolean  base_System_List_contains(System_List that, System_Object object) {

    uint64 object_siphash = Object_getSipHash(object);

    for (size i = 0; i < that->length; ++i) {
        if (object_siphash == uint64Array_get_index(that->hashes, i)) return true;
    }
    return false;
}

void  base_System_List_add(System_List that, System_Object object) {
    assert(object)

    if (base_System_List_contains(that, object)) throw(inline_Exception_new("InvalidOperationException_new: System.List: System_Object already added."))

    size new_i = that->length;
    if (new_i >= that->capacity) {
        size new_capacity = that->capacity * 2;
        uint64Array_resize(that->hashes, new_capacity);
        Array_resize(that->items, new_capacity);
        that->capacity = new_capacity;
    }

    uint64Array_set_index(that->hashes, new_i, Object_getSipHash(object));
    Array_set_index(that->items, new_i, object);
    ++that->length;
}

struct_System_Type_FunctionInfo  System_ListTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_List_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_List_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_List_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_List_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_List_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_System_List_getEnumerator },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_List_contains, .value = base_System_List_contains },
    [7] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_List_add, .value = base_System_List_add },
};

struct_System_Type_InterfaceInfo  System_ListTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_ListType = { .base = { .type = typeof(System_Type) },
    .name = "System.List",
    .size = sizeof(struct_System_List),
    .baseType = typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_ListTypeFunctions), .value = &System_ListTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(System_ListTypeInterfaces), .value = &System_ListTypeInterfaces
    },
};

#endif
