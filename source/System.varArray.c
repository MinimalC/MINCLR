#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_varArray)
#define code_System_varArray

/*# System_varArray #*/

/* class System_varArray */

System_varArray  System_varArray_new(System_size length) {
    return inline_System_varArray_new(length);
}

System_varArray  base_System_varArray_init(System_varArray that, System_size length) {
	base_System_Object_init((__Object)that);

    that->length = length;

    __size element_size = sizeof(__var);

    that->value =  __Memory_alloc(length * element_size);

    return that;
}

System_void  base_System_varArray_free(System_varArray that) {
	__assert(that)
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_varArray_get_Length(System_varArray that) {
    return that->length;
}

System_Object  base_System_varArray_get_index(System_varArray that, __size index) {
	__assert(that)
	return __array(that->value)[index];
}

void  base_System_varArray_set_index(System_varArray that, __size index, System_Object value) {
    __array(that->value)[index] = value;
}

void  base_System_varArray_resize(System_varArray that, System_size length) {
    __size element_size = sizeof(__var);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator base_System_varArray_getEnumerator(System_varArray that) {
    return (System_IEnumerator)inline_System_varArrayEnumerator_new(that);
}

struct_System_String  STRING_System_varArray = const_System_String("System.varArray");

struct_System_Type_FunctionInfo System_varArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_varArray_free },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_varArray_init, .value = base_System_varArray_init },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_varArray_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_varArray_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_varArray_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_varArray_resize, .value = base_System_varArray_resize },
    [6] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerable_getEnumerator, .value = base_System_varArray_getEnumerator },
};

struct_System_Type_InterfaceInfo System_varArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_varArrayType = {
    .base = stack_System_Object(System_Type),
	.name = &STRING_System_varArray,
	.size = sizeof(struct_System_varArray),
	.baseType = &System_varArrayType,
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&System_varArrayTypeFunctions), .value = &System_varArrayTypeFunctions,
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(&System_varArrayTypeInterfaces), .value = &System_varArrayTypeInterfaces,
    },
};

#endif
