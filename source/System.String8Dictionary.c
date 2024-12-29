/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_String8Dictionary)
#include <min/System.String8Dictionary.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_String8Dictionary)
#define code_System_String8Dictionary

/** class System_String8Dictionary  **/

System_String8Dictionary  new_System_String8Dictionary(System_Size capacity) {
    System_String8Dictionary that = (System_String8Dictionary)System_Memory_allocClass(typeof(System_String8Dictionary));
    base_System_String8Dictionary_init(that, capacity);
    return that;
}

void base_System_String8Dictionary_init(System_String8Dictionary that, System_Size capacity) {
    that->key = System_Memory_allocArray(typeof(System_String8), capacity);
    that->value = System_Memory_allocArray(typeof(System_String8), capacity);
    that->capacity = capacity;
}

void  base_System_String8Dictionary_free(System_String8Dictionary that) {
    for (System_Size i = 0; i < that->length; ++i) {
        System_Memory_free(array_item(that->key, i));
        System_Memory_free(array_item(that->value, i));
    }
    System_Memory_free(that->key);
    System_Memory_free(that->value);
}

System_Size base_System_String8Dictionary_add(System_String8Dictionary that, System_String8 key, System_String8 value) {
    /* TODO: if System_String8Dictionary_contains key, throw */
    System_Size index = that->length++;
    array(that->key)[index] = key;
    array(that->value)[index] = value;
    return index;
}

void base_System_String8Dictionary_remove(System_String8Dictionary that, System_String8 key) {
    /* TODO: say key is null, move all other, then say --length */
    System_Console_writeLine__string("System_String8Dictionary_remove not implemented");
}

System_Size  base_System_String8Dictionary_get_Length(System_String8Dictionary that) {
    return that->length;
}

System_String8  base_System_String8Dictionary_get_index(System_String8Dictionary that, System_Size index) {
    return array(that->key)[index];
}

System_Size  base_System_String8Dictionary_get_key(System_String8Dictionary that, System_String8 key) {
    for (Size i = 0; i < that->length; ++i)
        if (String8_equals(array_item(that->key, i), key))
            return i;
    return -1;
}

System_String8  base_System_String8Dictionary_get_value(System_String8Dictionary that, System_String8 key) {
    System_Size index = base_System_String8Dictionary_get_key(that, key);
    if (index == -1) return null;
    return array(that->value)[index];
}

void  base_System_String8Dictionary_set_index(System_String8Dictionary that, System_Size index, System_String8 value) {
    array(that->value)[index] = value;
}

void  base_System_String8Dictionary_set_key(System_String8Dictionary that, System_String8 old, System_String8 new) {
    System_Size index = base_System_String8Dictionary_get_key(that, old);
    array(that->key)[index] = new;
}

void  base_System_String8Dictionary_set_value(System_String8Dictionary that, System_String8 key, System_String8 value) {
    System_Size index = base_System_String8Dictionary_get_key(that, key);
    array(that->value)[index] = value;
}

void  base_System_String8Dictionary_resize(System_String8Dictionary that, System_Size capacity) {
    System_Memory_reallocArray((System_Var)that->value, capacity);
    System_Memory_reallocArray((System_Var)that->key, capacity);
    that->capacity = capacity;
}

System_IEnumerator  base_System_String8Dictionary_getEnumerator(System_String8Dictionary that) {
    return (System_IEnumerator)new_System_String8DictionaryEnumerator(that);
}

struct System_Type_FunctionInfo  System_String8DictionaryTypeFunctions[] = {
    [0] = { .function = base_System_String8Dictionary_init, .value = base_System_String8Dictionary_init },
    [1] = { .function = base_System_Object_free, .value = base_System_String8Dictionary_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_String8Dictionary_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_String8Dictionary_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_String8Dictionary_set_index },
    [5] = { .function = base_System_String8Dictionary_resize, .value = base_System_String8Dictionary_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_String8Dictionary_getEnumerator },
};

struct System_Type_InterfaceInfo  System_String8DictionaryTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_String8DictionaryType = { .base = { .type = typeof(System_Type) },
    .name = "String8Dictionary",
    .size = sizeof(struct System_String8Dictionary),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_String8DictionaryTypeFunctions), .value = &System_String8DictionaryTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_String8DictionaryTypeInterfaces), .value = &System_String8DictionaryTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(code_System_String8DictionaryEnumerator)
#define code_System_String8DictionaryEnumerator

/** class System_String8DictionaryEnumerator  **/

System_String8DictionaryEnumerator  new_System_String8DictionaryEnumerator(System_String8Dictionary array) {
    System_String8DictionaryEnumerator that = (System_String8DictionaryEnumerator)System_Memory_allocClass(typeof(System_String8DictionaryEnumerator));
    base_System_String8DictionaryEnumerator_init(that, array);
    return that;
}

void  base_System_String8DictionaryEnumerator_init(System_String8DictionaryEnumerator that, System_String8Dictionary array) {

    if (!array) System_Exception_terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_String8Dictionary)System_Memory_addReference((System_Object)array);
    that->index = -1;
}

void  base_System_String8DictionaryEnumerator_free(System_String8DictionaryEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;
}

System_String8  base_System_String8DictionaryEnumerator_get_current(System_String8DictionaryEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) { System_Exception_throw(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate")); return false; }

    return System_String8Dictionary_get_index(that->array, that->index);
}

System_Bool  base_System_String8DictionaryEnumerator_moveNext(System_String8DictionaryEnumerator that) {

    if (that->index == -2) System_Exception_terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_String8DictionaryEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_String8DictionaryEnumerator_init, .value = base_System_String8DictionaryEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_String8DictionaryEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_String8DictionaryEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_String8DictionaryEnumerator_moveNext },
};

struct System_Type System_String8DictionaryEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "String8DictionaryEnumerator",
    .size = sizeof(struct System_String8DictionaryEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_String8DictionaryEnumeratorTypeFunctions), .value = &System_String8DictionaryEnumeratorTypeFunctions
    },
};

#endif
