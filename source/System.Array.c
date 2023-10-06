#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Array)
#include <min/System.Array.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_Array)
#define code_System_Array

/*# System_Array #*/

/* class System_Array */

System_Array  base_System_Array_init(System_Array that, System_Size capacity) {
	base_System_Object_init((Object)that);

    that->value =  Memory_allocArray(typeof(Var), capacity);

    that->capacity = capacity;

    return that;
}

void  base_System_Array_free(System_Array that) {
	Debug_assert(that);

#if DEBUG == DEBUG_System_Object
	System_Type type = ((System_Object)that)->type;
    Size start_null = 0;
#endif

    /* * TODO: Array_get_index, Array_set_index and Array_hasValue */
    System_Object * array = (* that->value);

    for (Size i = 0; i < that->length; ++i) {
        Object object = *(array + i);

        if (object) {

#if DEBUG == DEBUG_System_Object
            if (start_null > 0) {
                if (start_null == i - 1)
                     Console_writeLine("{0:string}_free: [{1:uint}] is null", 2, type->name, start_null);
                else Console_writeLine("{0:string}_free: [{1:uint}..{2:uint}] are null", 3, type->name, start_null, i - 1);
                start_null = 0;
            }
            /* Console_writeLine("{0:string}_free: [{1:uint}]: {2:string}_free", 3, type->name, i, object->type->name); */
#endif

            Memory_free(object);
            *(array + i) = null;
        }

#if DEBUG == DEBUG_System_Object
			else if (start_null == 0) start_null = i;
#endif
    }

#if DEBUG == DEBUG_System_Object
    if (start_null > 0) {
        if (start_null == i - 1) Console_writeLine("{0:string}_free: [{1:uint}] is null", 2, type->name, start_null);
        else Console_writeLine("{0:string}_free: [{1:uint}..{2:uint}] are null", 3, type->name, start_null, i - 1);
        start_null = 0;
    }
#endif

    Memory_free(that->value);

	base_System_Object_free((Object)that);
}

System_Size  base_System_Array_get_Length(System_Array that) {
    return that->length;
}

System_Object  base_System_Array_get_index(System_Array that, Size index) {
	Debug_assert(that);
	return array(that->value)[index];
}

void  base_System_Array_set_index(System_Array that, Size index, System_Object value) {
	Debug_assert(that);
    System_Object item = array(that->value)[index];
    if (item) Memory_free(item);
	array(that->value)[index] = !value ? null : Memory_addReference(value);
}

void  base_System_Array_resize(System_Array that, System_Size capacity) {
    System_Memory_reallocArray((System_Var)that, capacity);
    that->capacity = capacity;
}

System_IEnumerator base_System_Array_getEnumerator(System_Array that) {
    return (System_IEnumerator)new_System_ArrayEnumerator(that);
}

struct System_Type_FunctionInfo System_ArrayTypeFunctions[] = {
    [0] = { .function = base_System_Object_free, .value = base_System_Array_free },
    [1] = { .function = base_System_Array_init, .value = base_System_Array_init },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_Array_set_index },
    [5] = { .function = base_System_Array_resize, .value = base_System_Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_Array_getEnumerator },
};

struct System_Type_InterfaceInfo System_ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_ArrayType = {
    .base = { .type = typeof(System_Type) },
	.name = "Array",
	.size = sizeof(struct System_Array),
	.baseType = &System_ObjectType,
    .functions = { 
        .length = sizeof_array(System_ArrayTypeFunctions), .value = &System_ArrayTypeFunctions,
    },
    .interfaces = {
        .length = sizeof_array(System_ArrayTypeInterfaces), .value = &System_ArrayTypeInterfaces,
    },
};

#endif
#if !defined(code_System_ArrayEnumerator)
#define code_System_ArrayEnumerator

/*# System_ArrayEnumerator #*/

System_ArrayEnumerator  base_System_ArrayEnumerator_init(System_ArrayEnumerator that, System_Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_ArrayEnumerator_free(System_ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Object  base_System_ArrayEnumerator_get_current(System_ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_Array_get_index(that->array, that->index);
}

System_Bool  base_System_ArrayEnumerator_moveNext(System_ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_ArrayEnumerator_init, .value = base_System_ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_ArrayEnumerator_moveNext },
};

struct System_Type System_ArrayEnumeratorType = {
    .base = { .type = typeof(System_Type) },
    .name = "ArrayEnumerator",
    .size = sizeof(struct System_ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_ArrayEnumeratorTypeFunctions), .value = &System_ArrayEnumeratorTypeFunctions
    },
};

#endif
