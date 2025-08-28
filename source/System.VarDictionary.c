/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_VarDictionary)
#include <min/System.VarDictionary.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_VarDictionary)
#define code_System_VarDictionary

/** struct System_VarDictionary  **/

System_VarDictionary  new_System_VarDictionary() {
    System_VarDictionary that = (System_VarDictionary)System_Memory_allocClass(typeof(System_VarDictionary));
    System_VarDictionary_init(that);
    return that;
}

void System_VarDictionary_init(System_VarDictionary that) { }

void System_VarDictionary_free(System_VarDictionary that) {
    if (that->key && that->value) {
        for (System_Size i = 0; i < that->length; ++i) {
            System_Memory_free(array_item(that->key, i));
            System_Memory_free(array_item(that->value, i));
        }
        System_Memory_free(that->key);
        System_Memory_free(that->value);
    }
}

System_Size System_VarDictionary_add(System_VarDictionary that, System_String8 key, System_Var value) {
    /* TODO: if System_VarDictionary_contains key, throw */
    if (that->length + 1 > that->capacity) {
        System_VarDictionary_resize(that, that->capacity + System_VarDictionary_Capacity);
    }
    System_Size index = that->length++;
    array(that->key)[index] = key;
    array(that->value)[index] = value;
    return index;
}

void  System_VarDictionary_resize(System_VarDictionary that, System_Size capacity) {
    if (!that->key) that->key = System_Memory_allocArray(typeof(System_String8), capacity);
    else System_Memory_reallocArray((System_Var ref)&that->key, capacity);
    if (!that->value) that->value = System_Memory_allocArray(typeof(System_Var), capacity);
    else System_Memory_reallocArray((System_Var ref)&that->value, capacity);
    that->capacity = capacity;
}

void System_VarDictionary_remove(System_VarDictionary that, System_Var key) {
    /* TODO: say key is null, move all other, then say --length */
    System_Console_writeLine__string("System_VarDictionary_remove not implemented");
}

System_Size  System_VarDictionary_get_Length(System_VarDictionary that) {
    return that->length;
}

System_Var  System_VarDictionary_get_index(System_VarDictionary that, System_Size index) {
    return array(that->key)[index];
}

System_Size  System_VarDictionary_get_key(System_VarDictionary that, System_Var key) {
    for (Size i = 0; i < that->length; ++i)
        if (String8_equals(array_item(that->key, i), key))
            return i;
    return 0;
}

System_Var  System_VarDictionary_get_value(System_VarDictionary that, System_Var key) {
    System_Size index = System_VarDictionary_get_key(that, key);
    return array(that->value)[index];
}

void  System_VarDictionary_set_index(System_VarDictionary that, System_Size index, System_Var value) {
    array(that->value)[index] = value;
}

void  System_VarDictionary_set_key(System_VarDictionary that, System_Var old, System_Var new) {
    System_Size index = System_VarDictionary_get_key(that, old);
    array(that->key)[index] = new;
}

void  System_VarDictionary_set_value(System_VarDictionary that, System_Var key, System_Var value) {
    System_Size index = System_VarDictionary_get_key(that, key);
    array(that->value)[index] = value;
}

System_IEnumerator  System_VarDictionary_getEnumerator(System_VarDictionary that) {
    return (System_IEnumerator)new_System_VarDictionaryEnumerator(that);
}

struct System_Type_FunctionInfo  System_VarDictionaryTypeFunctions[] = {
    { .function = base_System_Object_init, .value = System_VarDictionary_init },
    { .function = base_System_Object_free, .value = System_VarDictionary_free },
    { .function = base_System_ICollection_get_Length, .value = System_VarDictionary_get_Length },
    { .function = base_System_ICollection_get_index, .value = System_VarDictionary_get_index },
    { .function = base_System_ICollection_set_index, .value = System_VarDictionary_set_index },
    { .function = base_System_IEnumerable_getEnumerator, .value = System_VarDictionary_getEnumerator },
};

struct System_Type_InterfaceInfo  System_VarDictionaryTypeInterfaces[] = {
    { .interfaceType = &System_ICollectionType },
    { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_VarDictionaryType = { .base = { .type = typeof(System_Type) },
    .name = "VarDictionary",
    .size = sizeof(struct System_VarDictionary),
    .baseType = typeof(System_Object),
    .functions = { .length = sizeof_array(System_VarDictionaryTypeFunctions), .value = &System_VarDictionaryTypeFunctions },
    .interfaces = { .length = sizeof_array(System_VarDictionaryTypeInterfaces), .value = &System_VarDictionaryTypeInterfaces },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(code_System_VarDictionaryEnumerator)
#define code_System_VarDictionaryEnumerator

/** struct System_VarDictionaryEnumerator  **/

System_VarDictionaryEnumerator  new_System_VarDictionaryEnumerator(System_VarDictionary array) {
    System_VarDictionaryEnumerator that = (System_VarDictionaryEnumerator)System_Memory_allocClass(typeof(System_VarDictionaryEnumerator));
    base_System_VarDictionaryEnumerator_init(that, array);
    return that;
}

void  base_System_VarDictionaryEnumerator_init(System_VarDictionaryEnumerator that, System_VarDictionary array) {

    if (!array) System_Exception_terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_VarDictionary)System_Memory_addReference((System_Object)array);
    that->index = -1;
}

void  base_System_VarDictionaryEnumerator_free(System_VarDictionaryEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;
}

System_Var  base_System_VarDictionaryEnumerator_get_current(System_VarDictionaryEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) { System_Exception_throw(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate")); return false; }

    return System_VarDictionary_get_index(that->array, that->index);
}

System_Bool  base_System_VarDictionaryEnumerator_moveNext(System_VarDictionaryEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_VarDictionaryEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_VarDictionaryEnumerator_init, .value = base_System_VarDictionaryEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_VarDictionaryEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_VarDictionaryEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_VarDictionaryEnumerator_moveNext },
};

struct System_Type System_VarDictionaryEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "VarDictionaryEnumerator",
    .size = sizeof(struct System_VarDictionaryEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_VarDictionaryEnumeratorTypeFunctions), .value = &System_VarDictionaryEnumeratorTypeFunctions
    },
};

#endif
