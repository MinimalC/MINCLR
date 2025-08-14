/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_List)
#include <min/System.List.h>
#endif
#if !defined(code_System_List)
#define code_System_List

/** struct System_List  **/

System_List  new_System_List() {
    System_List that = (System_List)System_Memory_allocClass(typeof(System_List));
    base_System_List_init(that);
    return that;
}

void  base_System_List_init(System_List that) {
    that->capacity = System_Array_DefaultCapacity;
    that->items = new_System_Array(that->capacity);
}

void  base_System_List_free(System_List that) {
    System_Memory_free(that->items);
}

System_Size  base_System_List_get_Length(System_List that) {
    return that->length;
}

System_Object  base_System_List_get_index(System_List that, Size index) {
	Console_assert(that);
	return Array_get_index(that->items, index);
}

void  base_System_List_set_index(System_List that, Size index, System_Object value) {
	Console_assert(that);
    if (value && base_System_List_contains(that, value)) throw(new_Exception("InvalidOperationException: System_List: System_Object already added"))
    Array_set_index(that->items, index, value);
}

System_IEnumerator base_System_List_getEnumerator(System_List that) {
    return (System_IEnumerator)new_System_ListEnumerator(that);
}

System_Bool  base_System_List_contains(System_List that, System_Object object) {
    UInt64 other_siphash, object_siphash = Object_getSipHash(object);
    for (Size i = 0; i < that->length; ++i) {
        other_siphash = System_Object_getSipHash(&that->items[i]);
        if (object_siphash == other_siphash) return true;
    }
    return false;
}

void  base_System_List_add(System_List that, System_Object object) {
    Console_assert(object);

    if (base_System_List_contains(that, object)) throw(new_Exception("InvalidOperationException: System.List: System_Object already added."))

    Size new_i = that->length;
    if (new_i >= that->capacity) {
        Size new_capacity = that->capacity + System_Array_DefaultCapacity;
        Array_resize(that->items, new_capacity);
        that->capacity = new_capacity;
    }

    Array_set_index(that->items, new_i, object);
    ++that->length;
}

struct System_Type_FunctionInfo  System_ListTypeFunctions[] = {
    [0] = { .function = base_System_Object_init, .value = base_System_List_init },
    [1] = { .function = base_System_Object_free, .value = base_System_List_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_List_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_List_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_List_set_index },
    [5] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_List_getEnumerator },
    [6] = { .function = base_System_List_contains, .value = base_System_List_contains },
    [7] = { .function = base_System_List_add, .value = base_System_List_add },
};

struct System_Type_InterfaceInfo  System_ListTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_ListType = { .base = { .type = typeof(System_Type) },
    .name = "List",
    .size = sizeof(struct System_List),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_ListTypeFunctions), .value = &System_ListTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_ListTypeInterfaces), .value = &System_ListTypeInterfaces
    },
};

#endif
