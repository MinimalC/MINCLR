#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Array)
#include <min/System.Array.h>
#endif
#if !defined(code_System_Array)
#define code_System_Array

/*# System_Array #*/

/* class System_Array */

System_Array  base_System_Array_init(System_Array that, System_size length) {
	base_System_Object_init((Object)that);

    that->length = length;

    size element_size = sizeof(var);

    that->value =  Memory_allocClass(typeof(var), length);

    return that;
}

void  base_System_Array_free(System_Array that) {
	Console_assert(that);

	size length = that->length;
    size i;

#if DEBUG == DEBUG_System_Object
	System_Type type = ((System_Object)that)->Type;
    size start_null = 0;
#endif

    /* * TODO: Array_get_index, Array_set_index and Array_hasValue */
    System_Object * array = (* that->value);

    for (i = 0; i < length; ++i) {
        Object object = *(array + i);

        if (object) {

#if DEBUG == DEBUG_System_Object
            if (start_null > 0) {
                if (start_null == i - 1)
                     Console_writeLine("{0:string}_free: [{1:uint}] is null", 2, type->name->value, start_null);
                else Console_writeLine("{0:string}_free: [{1:uint}..{2:uint}] are null", 3, type->name->value, start_null, i - 1);
                start_null = 0;
            }
            /* Console_writeLine("{0:string}_free: [{1:uint}]: {2:string}_free", 3, type->name->value, i, object->Type->name->value); */
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
        if (start_null == i - 1) Console_writeLine("{0:string}_free: [{1:uint}] is null", 2, type->name->value, start_null);
        else Console_writeLine("{0:string}_free: [{1:uint}..{2:uint}] are null", 3, type->name->value, start_null, i - 1);
        start_null = 0;
    }
#endif

    Memory_free(that->value);

	base_System_Object_free((Object)that);
}

System_size  base_System_Array_get_Length(System_Array that) {
    return that->length;
}

System_Object  base_System_Array_get_index(System_Array that, size index) {
	Console_assert(that);
	return array(that->value)[index];
}

void  base_System_Array_set_index(System_Array that, size index, System_Object value) {
	Console_assert(that);
    System_Object item = array(that->value)[index];
    if (item) Memory_free(item);
	array(that->value)[index] = !value ? null : Object_addReference(value);
}

void  base_System_Array_resize(System_Array that, System_size length) {
    size element_size = sizeof(var);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator base_System_Array_getEnumerator(System_Array that) {
    return (System_IEnumerator)new_System_ArrayEnumerator(that);
}

struct System_Type_FunctionInfo System_ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Array_free },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Array_init, .value = base_System_Array_init },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Array_resize, .value = base_System_Array_resize },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_System_Array_getEnumerator },
};

struct System_Type_InterfaceInfo System_ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct System_Type  System_ArrayType = {
    .base = stack_System_Object(System_Type),
	.name = "System.Array",
	.size = sizeof(struct System_Array),
	.baseType = &System_ObjectType,
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_ArrayTypeFunctions), .value = &System_ArrayTypeFunctions,
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = sizeof_array(System_ArrayTypeInterfaces), .value = &System_ArrayTypeInterfaces,
    },
};

#endif
