#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_Array)
#define code_System_Array

/*# System_Array #*/

/* class System_Array */

System_Array  System_Array_new(System_size length) {
    return inline_System_Array_new(length);
}

System_Array  base_System_Array_init(System_Array that, System_size length) {
	base_System_Object_init((__Object)that);

    that->length = length;

    __size element_size = sizeof(__var);

    that->value =  __Memory_alloc(length * element_size);

    return that;
}

System_void  base_System_Array_free(System_Array that) {
	__assert(that)

	__size length = that->length;
    __size i;

#if __DEBUG == DEBUG_System_Object
	System_Type type = ((System_Object)that)->Type;
    __size start_null = 0;
#endif

    /* * TODO: __Array_get_index, __Array_set_index and __Array_hasValue */
    System_Object * array = (* that->value);

    for (i = 0; i < length; ++i) {
        __Object object = *(array + i);

        if (object) {

#if __DEBUG == DEBUG_System_Object
            if (start_null > 0) {
                if (start_null == i - 1) __Console_print("__%s_free: [%u] is null\n", type->name->value, start_null);
                else __Console_print("__%s_free: [%u..%u] are null\n", type->name->value, start_null, i - 1);
                start_null = 0;
            }
            /* __Console_print("__%s_free: [%u]: %s_free\n", type->name->value, i, object->Type->name->value); */
#endif

            __Object_freeClass(&object);
            *(array + i) = __null;
        }

#if __DEBUG == DEBUG_System_Object
			else if (start_null == 0) start_null = i;
#endif
    }

#if __DEBUG == DEBUG_System_Object
    if (start_null > 0) {
        if (start_null == i - 1) __Console_print("__%s_free: [%u] is null\n", type->name->value, start_null);
        else __Console_print("__%s_free: [%u..%u] are null\n", type->name->value, start_null, i - 1);
        start_null = 0;
    }
#endif

    __Memory_free((void **)&that->value);

	base_System_Object_free((__Object)that);
}

System_size  base_System_Array_get_Length(System_Array that) {
    return that->length;
}

System_Object  base_System_Array_get_index(System_Array that, __size index) {
	__assert(that)
	return __array(that->value)[index];
}

void  base_System_Array_set_index(System_Array that, __size index, System_Object value) {
	__assert(that)
    System_Object item = __array(that->value)[index];
    if (item) __Object_freeClass(&item);
	__array(that->value)[index] = !value ? __null : __Object_addReference(value);
}

void  base_System_Array_resize(System_Array that, System_size length) {
    __size element_size = sizeof(__var);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator base_System_Array_getEnumerator(System_Array that) {
    return (System_IEnumerator)inline_System_ArrayEnumerator_new(that);
}

struct_System_String  STRING_System_Array = const_System_String("System.Array");

struct_System_Type_FunctionInfo System_ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Array_free },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Array_init, .value = base_System_Array_init },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Array_resize, .value = base_System_Array_resize },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_System_Array_getEnumerator },
};

struct_System_Type_InterfaceInfo System_ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_ArrayType = {
    .base = stack_System_Object(System_Type),
	.name = &STRING_System_Array,
	.size = sizeof(struct_System_Array),
	.baseType = &System_ArrayType,
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&System_ArrayTypeFunctions), .value = &System_ArrayTypeFunctions,
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(&System_ArrayTypeInterfaces), .value = &System_ArrayTypeInterfaces,
    },
};

#endif
