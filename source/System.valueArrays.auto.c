/* Gemeinfrei. Public Domain. */

#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_uint8Array)
#include <min/System.valueArrays.auto.h>
#endif
#if !defined(code_auto_System_uint8Array)
#define code_auto_System_uint8Array

/*# System_uint8Array #*/

System_uint8Array  System_uint8Array_new(System_size length) {
    return inline_System_uint8Array_new(length);
}

System_uint8Array base_System_uint8Array_init(System_uint8Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_uint8);
    System_uint8 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_uint8Array_free(System_uint8Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_uint8Array_get_Length(System_uint8Array that) {
    return that->length;
}

System_uint8  base_System_uint8Array_get_index(System_uint8Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_uint8Array_set_index(System_uint8Array that, System_size index, System_uint8 value) {
    __array(that->value)[index] = value;
}

void  base_System_uint8Array_resize(System_uint8Array that, System_size length) {
    System_size element_size = sizeof(System_uint8);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_uint8Array_getEnumerator(System_uint8Array that) {
    return (System_IEnumerator)inline_System_uint8ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_uint8ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint8Array_init, .value = base_System_uint8Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint8Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_uint8Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_uint8Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_uint8Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint8Array_resize, .value = base_System_uint8Array_resize },
};

struct_System_Type_InterfaceInfo  System_uint8ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_uint8ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint8Array",
    .size = sizeof(struct_System_uint8Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint8ArrayTypeFunctions), .value = &System_uint8ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_uint8ArrayTypeInterfaces), .value = &System_uint8ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_uint8ArrayEnumerator)
#define code_auto_System_uint8ArrayEnumerator

/*# System_uint8ArrayEnumerator #*/

System_uint8ArrayEnumerator  System_uint8ArrayEnumerator_new(System_uint8Array array) {
    return inline_System_uint8ArrayEnumerator_new(array);
}

System_uint8ArrayEnumerator  base_System_uint8ArrayEnumerator_init(System_uint8ArrayEnumerator that, System_uint8Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_uint8Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_uint8ArrayEnumerator_free(System_uint8ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_uint8  base_System_uint8ArrayEnumerator_get_current(System_uint8ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_uint8Array_get_index(that->array, that->index);
}

System_boolean  base_System_uint8ArrayEnumerator_moveNext(System_uint8ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_uint8ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint8ArrayEnumerator_init, .value = base_System_uint8ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint8ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_uint8ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_uint8ArrayEnumerator_moveNext },
};

struct_System_Type  System_uint8ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint8ArrayEnumerator",
    .size = sizeof(struct_System_uint8ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint8ArrayEnumeratorTypeFunctions), .value = &System_uint8ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_uint16Array)
#define code_auto_System_uint16Array

/*# System_uint16Array #*/

System_uint16Array  System_uint16Array_new(System_size length) {
    return inline_System_uint16Array_new(length);
}

System_uint16Array base_System_uint16Array_init(System_uint16Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_uint16);
    System_uint16 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_uint16Array_free(System_uint16Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_uint16Array_get_Length(System_uint16Array that) {
    return that->length;
}

System_uint16  base_System_uint16Array_get_index(System_uint16Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_uint16Array_set_index(System_uint16Array that, System_size index, System_uint16 value) {
    __array(that->value)[index] = value;
}

void  base_System_uint16Array_resize(System_uint16Array that, System_size length) {
    System_size element_size = sizeof(System_uint16);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_uint16Array_getEnumerator(System_uint16Array that) {
    return (System_IEnumerator)inline_System_uint16ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_uint16ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint16Array_init, .value = base_System_uint16Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint16Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_uint16Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_uint16Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_uint16Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint16Array_resize, .value = base_System_uint16Array_resize },
};

struct_System_Type_InterfaceInfo  System_uint16ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_uint16ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint16Array",
    .size = sizeof(struct_System_uint16Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint16ArrayTypeFunctions), .value = &System_uint16ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_uint16ArrayTypeInterfaces), .value = &System_uint16ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_uint16ArrayEnumerator)
#define code_auto_System_uint16ArrayEnumerator

/*# System_uint16ArrayEnumerator #*/

System_uint16ArrayEnumerator  System_uint16ArrayEnumerator_new(System_uint16Array array) {
    return inline_System_uint16ArrayEnumerator_new(array);
}

System_uint16ArrayEnumerator  base_System_uint16ArrayEnumerator_init(System_uint16ArrayEnumerator that, System_uint16Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_uint16Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_uint16ArrayEnumerator_free(System_uint16ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_uint16  base_System_uint16ArrayEnumerator_get_current(System_uint16ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_uint16Array_get_index(that->array, that->index);
}

System_boolean  base_System_uint16ArrayEnumerator_moveNext(System_uint16ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_uint16ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint16ArrayEnumerator_init, .value = base_System_uint16ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint16ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_uint16ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_uint16ArrayEnumerator_moveNext },
};

struct_System_Type  System_uint16ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint16ArrayEnumerator",
    .size = sizeof(struct_System_uint16ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint16ArrayEnumeratorTypeFunctions), .value = &System_uint16ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_uint32Array)
#define code_auto_System_uint32Array

/*# System_uint32Array #*/

System_uint32Array  System_uint32Array_new(System_size length) {
    return inline_System_uint32Array_new(length);
}

System_uint32Array base_System_uint32Array_init(System_uint32Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_uint32);
    System_uint32 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_uint32Array_free(System_uint32Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_uint32Array_get_Length(System_uint32Array that) {
    return that->length;
}

System_uint32  base_System_uint32Array_get_index(System_uint32Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_uint32Array_set_index(System_uint32Array that, System_size index, System_uint32 value) {
    __array(that->value)[index] = value;
}

void  base_System_uint32Array_resize(System_uint32Array that, System_size length) {
    System_size element_size = sizeof(System_uint32);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_uint32Array_getEnumerator(System_uint32Array that) {
    return (System_IEnumerator)inline_System_uint32ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_uint32ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint32Array_init, .value = base_System_uint32Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint32Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_uint32Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_uint32Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_uint32Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint32Array_resize, .value = base_System_uint32Array_resize },
};

struct_System_Type_InterfaceInfo  System_uint32ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_uint32ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint32Array",
    .size = sizeof(struct_System_uint32Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint32ArrayTypeFunctions), .value = &System_uint32ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_uint32ArrayTypeInterfaces), .value = &System_uint32ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_uint32ArrayEnumerator)
#define code_auto_System_uint32ArrayEnumerator

/*# System_uint32ArrayEnumerator #*/

System_uint32ArrayEnumerator  System_uint32ArrayEnumerator_new(System_uint32Array array) {
    return inline_System_uint32ArrayEnumerator_new(array);
}

System_uint32ArrayEnumerator  base_System_uint32ArrayEnumerator_init(System_uint32ArrayEnumerator that, System_uint32Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_uint32Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_uint32ArrayEnumerator_free(System_uint32ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_uint32  base_System_uint32ArrayEnumerator_get_current(System_uint32ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_uint32Array_get_index(that->array, that->index);
}

System_boolean  base_System_uint32ArrayEnumerator_moveNext(System_uint32ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_uint32ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint32ArrayEnumerator_init, .value = base_System_uint32ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint32ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_uint32ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_uint32ArrayEnumerator_moveNext },
};

struct_System_Type  System_uint32ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint32ArrayEnumerator",
    .size = sizeof(struct_System_uint32ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint32ArrayEnumeratorTypeFunctions), .value = &System_uint32ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_uint64Array)
#define code_auto_System_uint64Array

/*# System_uint64Array #*/

System_uint64Array  System_uint64Array_new(System_size length) {
    return inline_System_uint64Array_new(length);
}

System_uint64Array base_System_uint64Array_init(System_uint64Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_uint64);
    System_uint64 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_uint64Array_free(System_uint64Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_uint64Array_get_Length(System_uint64Array that) {
    return that->length;
}

System_uint64  base_System_uint64Array_get_index(System_uint64Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_uint64Array_set_index(System_uint64Array that, System_size index, System_uint64 value) {
    __array(that->value)[index] = value;
}

void  base_System_uint64Array_resize(System_uint64Array that, System_size length) {
    System_size element_size = sizeof(System_uint64);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_uint64Array_getEnumerator(System_uint64Array that) {
    return (System_IEnumerator)inline_System_uint64ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_uint64ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint64Array_init, .value = base_System_uint64Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint64Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_uint64Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_uint64Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_uint64Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint64Array_resize, .value = base_System_uint64Array_resize },
};

struct_System_Type_InterfaceInfo  System_uint64ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_uint64ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint64Array",
    .size = sizeof(struct_System_uint64Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint64ArrayTypeFunctions), .value = &System_uint64ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_uint64ArrayTypeInterfaces), .value = &System_uint64ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_uint64ArrayEnumerator)
#define code_auto_System_uint64ArrayEnumerator

/*# System_uint64ArrayEnumerator #*/

System_uint64ArrayEnumerator  System_uint64ArrayEnumerator_new(System_uint64Array array) {
    return inline_System_uint64ArrayEnumerator_new(array);
}

System_uint64ArrayEnumerator  base_System_uint64ArrayEnumerator_init(System_uint64ArrayEnumerator that, System_uint64Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_uint64Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_uint64ArrayEnumerator_free(System_uint64ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_uint64  base_System_uint64ArrayEnumerator_get_current(System_uint64ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_uint64Array_get_index(that->array, that->index);
}

System_boolean  base_System_uint64ArrayEnumerator_moveNext(System_uint64ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_uint64ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_uint64ArrayEnumerator_init, .value = base_System_uint64ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_uint64ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_uint64ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_uint64ArrayEnumerator_moveNext },
};

struct_System_Type  System_uint64ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.uint64ArrayEnumerator",
    .size = sizeof(struct_System_uint64ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_uint64ArrayEnumeratorTypeFunctions), .value = &System_uint64ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int8Array)
#define code_auto_System_int8Array

/*# System_int8Array #*/

System_int8Array  System_int8Array_new(System_size length) {
    return inline_System_int8Array_new(length);
}

System_int8Array base_System_int8Array_init(System_int8Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_int8);
    System_int8 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_int8Array_free(System_int8Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_int8Array_get_Length(System_int8Array that) {
    return that->length;
}

System_int8  base_System_int8Array_get_index(System_int8Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_int8Array_set_index(System_int8Array that, System_size index, System_int8 value) {
    __array(that->value)[index] = value;
}

void  base_System_int8Array_resize(System_int8Array that, System_size length) {
    System_size element_size = sizeof(System_int8);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_int8Array_getEnumerator(System_int8Array that) {
    return (System_IEnumerator)inline_System_int8ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_int8ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int8Array_init, .value = base_System_int8Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int8Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_int8Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_int8Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_int8Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int8Array_resize, .value = base_System_int8Array_resize },
};

struct_System_Type_InterfaceInfo  System_int8ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_int8ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int8Array",
    .size = sizeof(struct_System_int8Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int8ArrayTypeFunctions), .value = &System_int8ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_int8ArrayTypeInterfaces), .value = &System_int8ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int8ArrayEnumerator)
#define code_auto_System_int8ArrayEnumerator

/*# System_int8ArrayEnumerator #*/

System_int8ArrayEnumerator  System_int8ArrayEnumerator_new(System_int8Array array) {
    return inline_System_int8ArrayEnumerator_new(array);
}

System_int8ArrayEnumerator  base_System_int8ArrayEnumerator_init(System_int8ArrayEnumerator that, System_int8Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_int8Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_int8ArrayEnumerator_free(System_int8ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_int8  base_System_int8ArrayEnumerator_get_current(System_int8ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_int8Array_get_index(that->array, that->index);
}

System_boolean  base_System_int8ArrayEnumerator_moveNext(System_int8ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_int8ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int8ArrayEnumerator_init, .value = base_System_int8ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int8ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_int8ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_int8ArrayEnumerator_moveNext },
};

struct_System_Type  System_int8ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int8ArrayEnumerator",
    .size = sizeof(struct_System_int8ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int8ArrayEnumeratorTypeFunctions), .value = &System_int8ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int16Array)
#define code_auto_System_int16Array

/*# System_int16Array #*/

System_int16Array  System_int16Array_new(System_size length) {
    return inline_System_int16Array_new(length);
}

System_int16Array base_System_int16Array_init(System_int16Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_int16);
    System_int16 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_int16Array_free(System_int16Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_int16Array_get_Length(System_int16Array that) {
    return that->length;
}

System_int16  base_System_int16Array_get_index(System_int16Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_int16Array_set_index(System_int16Array that, System_size index, System_int16 value) {
    __array(that->value)[index] = value;
}

void  base_System_int16Array_resize(System_int16Array that, System_size length) {
    System_size element_size = sizeof(System_int16);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_int16Array_getEnumerator(System_int16Array that) {
    return (System_IEnumerator)inline_System_int16ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_int16ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int16Array_init, .value = base_System_int16Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int16Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_int16Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_int16Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_int16Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int16Array_resize, .value = base_System_int16Array_resize },
};

struct_System_Type_InterfaceInfo  System_int16ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_int16ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int16Array",
    .size = sizeof(struct_System_int16Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int16ArrayTypeFunctions), .value = &System_int16ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_int16ArrayTypeInterfaces), .value = &System_int16ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int16ArrayEnumerator)
#define code_auto_System_int16ArrayEnumerator

/*# System_int16ArrayEnumerator #*/

System_int16ArrayEnumerator  System_int16ArrayEnumerator_new(System_int16Array array) {
    return inline_System_int16ArrayEnumerator_new(array);
}

System_int16ArrayEnumerator  base_System_int16ArrayEnumerator_init(System_int16ArrayEnumerator that, System_int16Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_int16Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_int16ArrayEnumerator_free(System_int16ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_int16  base_System_int16ArrayEnumerator_get_current(System_int16ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_int16Array_get_index(that->array, that->index);
}

System_boolean  base_System_int16ArrayEnumerator_moveNext(System_int16ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_int16ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int16ArrayEnumerator_init, .value = base_System_int16ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int16ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_int16ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_int16ArrayEnumerator_moveNext },
};

struct_System_Type  System_int16ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int16ArrayEnumerator",
    .size = sizeof(struct_System_int16ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int16ArrayEnumeratorTypeFunctions), .value = &System_int16ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int32Array)
#define code_auto_System_int32Array

/*# System_int32Array #*/

System_int32Array  System_int32Array_new(System_size length) {
    return inline_System_int32Array_new(length);
}

System_int32Array base_System_int32Array_init(System_int32Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_int32);
    System_int32 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_int32Array_free(System_int32Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_int32Array_get_Length(System_int32Array that) {
    return that->length;
}

System_int32  base_System_int32Array_get_index(System_int32Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_int32Array_set_index(System_int32Array that, System_size index, System_int32 value) {
    __array(that->value)[index] = value;
}

void  base_System_int32Array_resize(System_int32Array that, System_size length) {
    System_size element_size = sizeof(System_int32);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_int32Array_getEnumerator(System_int32Array that) {
    return (System_IEnumerator)inline_System_int32ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_int32ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int32Array_init, .value = base_System_int32Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int32Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_int32Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_int32Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_int32Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int32Array_resize, .value = base_System_int32Array_resize },
};

struct_System_Type_InterfaceInfo  System_int32ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_int32ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int32Array",
    .size = sizeof(struct_System_int32Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int32ArrayTypeFunctions), .value = &System_int32ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_int32ArrayTypeInterfaces), .value = &System_int32ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int32ArrayEnumerator)
#define code_auto_System_int32ArrayEnumerator

/*# System_int32ArrayEnumerator #*/

System_int32ArrayEnumerator  System_int32ArrayEnumerator_new(System_int32Array array) {
    return inline_System_int32ArrayEnumerator_new(array);
}

System_int32ArrayEnumerator  base_System_int32ArrayEnumerator_init(System_int32ArrayEnumerator that, System_int32Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_int32Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_int32ArrayEnumerator_free(System_int32ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_int32  base_System_int32ArrayEnumerator_get_current(System_int32ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_int32Array_get_index(that->array, that->index);
}

System_boolean  base_System_int32ArrayEnumerator_moveNext(System_int32ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_int32ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int32ArrayEnumerator_init, .value = base_System_int32ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int32ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_int32ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_int32ArrayEnumerator_moveNext },
};

struct_System_Type  System_int32ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int32ArrayEnumerator",
    .size = sizeof(struct_System_int32ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int32ArrayEnumeratorTypeFunctions), .value = &System_int32ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int64Array)
#define code_auto_System_int64Array

/*# System_int64Array #*/

System_int64Array  System_int64Array_new(System_size length) {
    return inline_System_int64Array_new(length);
}

System_int64Array base_System_int64Array_init(System_int64Array that, System_size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_size element_size = sizeof(System_int64);
    System_int64 (* array)[] =  System_Memory_alloc(length * element_size);
    that->value = array;

    return that;
}

void  base_System_int64Array_free(System_int64Array that) {
    System_Memory_free((void **)&that->value);

    base_System_Object_free((System_Object)that);
}

System_size  base_System_int64Array_get_Length(System_int64Array that) {
    return that->length;
}

System_int64  base_System_int64Array_get_index(System_int64Array that, System_size index) {
    return __array(that->value)[index];
}

void  base_System_int64Array_set_index(System_int64Array that, System_size index, System_int64 value) {
    __array(that->value)[index] = value;
}

void  base_System_int64Array_resize(System_int64Array that, System_size length) {
    System_size element_size = sizeof(System_int64);
    System_Memory_realloc((void **)&that->value, (that->length * element_size), (length * element_size));
    that->length = length;
}

System_IEnumerator  base_System_int64Array_getEnumerator(System_int64Array that) {
    return (System_IEnumerator)inline_System_int64ArrayEnumerator_new(that);
}

struct_System_Type_FunctionInfo  System_int64ArrayTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int64Array_init, .value = base_System_int64Array_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int64Array_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_Length, .value = base_System_int64Array_get_Length },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_get_index, .value = base_System_int64Array_get_index },
    [4] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_ICollection_set_index, .value = base_System_int64Array_set_index },
    [5] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int64Array_resize, .value = base_System_int64Array_resize },
};

struct_System_Type_InterfaceInfo  System_int64ArrayTypeInterfaces[] = {
    [0] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_ICollectionType },
    [1] = { .base = stack_System_Object(System_Type_InterfaceInfo), .interfaceType = &System_IEnumerableType },
};

struct_System_Type  System_int64ArrayType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int64Array",
    .size = sizeof(struct_System_int64Array),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int64ArrayTypeFunctions), .value = &System_int64ArrayTypeFunctions
    },
    .interfaces = { .base = stack_System_Object(System_Type_InterfaceInfoArray),
        .length = __sizeof_array(System_int64ArrayTypeInterfaces), .value = &System_int64ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include <min/System.Type.h>
#endif
#if !defined(code_auto_System_int64ArrayEnumerator)
#define code_auto_System_int64ArrayEnumerator

/*# System_int64ArrayEnumerator #*/

System_int64ArrayEnumerator  System_int64ArrayEnumerator_new(System_int64Array array) {
    return inline_System_int64ArrayEnumerator_new(array);
}

System_int64ArrayEnumerator  base_System_int64ArrayEnumerator_init(System_int64ArrayEnumerator that, System_int64Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) __throw_terminate(inline_System_Exception_new("ArgumentNullException_new: array is null"));

    that->array = (System_int64Array)System_Object_addReference((System_Object)array);
    that->index = -1;

    return that;
}

System_void  base_System_int64ArrayEnumerator_free(System_int64ArrayEnumerator that) {

    inline_System_Object_freeClass(&that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_int64  base_System_int64ArrayEnumerator_get_current(System_int64ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));
    if (that->index == -1) __throw_return(inline_System_Exception_new("InvalidOperationException_new: Index Out of Range. No items to enumerate"));

    return System_int64Array_get_index(that->array, that->index);
}

System_boolean  base_System_int64ArrayEnumerator_moveNext(System_int64ArrayEnumerator that) {

    if (that->index == -2) __throw_terminate(inline_System_Exception_new("InvalidOperationException_new: Enumerator already free"));

    System_size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return System_true;
    }
    return System_false;
}

struct_System_Type_FunctionInfo  System_int64ArrayEnumeratorTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_int64ArrayEnumerator_init, .value = base_System_int64ArrayEnumerator_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_int64ArrayEnumerator_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_get_current, .value = base_System_int64ArrayEnumerator_get_current },
    [3] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_IEnumerator_moveNext, .value = base_System_int64ArrayEnumerator_moveNext },
};

struct_System_Type  System_int64ArrayEnumeratorType = { .base = { .Type = __typeof(System_Type) },
    .name = "System.int64ArrayEnumerator",
    .size = sizeof(struct_System_int64ArrayEnumerator),
    .baseType = __typeof(System_Object),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_int64ArrayEnumeratorTypeFunctions), .value = &System_int64ArrayEnumeratorTypeFunctions
    },
};

#endif
