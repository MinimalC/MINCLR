/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_UInt8Array)
#include <min/System.valueArrays.auto.h>
#endif
#if !defined(code_System_UInt8Array)
#define code_System_UInt8Array

/*# System_UInt8Array #*/

System_UInt8Array base_System_UInt8Array_init(System_UInt8Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_UInt8 (* array)[] = System_Memory_allocArray(typeof(System_Char8), length);
    that->value = array;

    return that;
}

void  base_System_UInt8Array_free(System_UInt8Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_UInt8Array_get_Length(System_UInt8Array that) {
    return that->length;
}

System_UInt8  base_System_UInt8Array_get_index(System_UInt8Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_UInt8Array_set_index(System_UInt8Array that, System_Size index, System_UInt8 value) {
    array(that->value)[index] = value;
}

void  base_System_UInt8Array_resize(System_UInt8Array that, System_Size length) {
    System_Size element_size = sizeof(System_UInt8);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_UInt8Array_getEnumerator(System_UInt8Array that) {
    return (System_IEnumerator)new_System_UInt8ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_UInt8ArrayTypeFunctions[] = {
    [0] = { .function = base_System_UInt8Array_init, .value = base_System_UInt8Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt8Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_UInt8Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_UInt8Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_UInt8Array_set_index },
    [5] = { .function = base_System_UInt8Array_resize, .value = base_System_UInt8Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_UInt8Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_UInt8ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_UInt8ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt8Array",
    .size = sizeof(struct System_UInt8Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt8ArrayTypeFunctions), .value = &System_UInt8ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_UInt8ArrayTypeInterfaces), .value = &System_UInt8ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_UInt16Array)
#include <min/System.UInt16Array.h>
#endif
#if !defined(code_System_UInt16Array)
#define code_System_UInt16Array

/*# System_UInt16Array #*/

System_UInt16Array base_System_UInt16Array_init(System_UInt16Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_UInt16 (* array)[] = System_Memory_allocArray(typeof(System_UInt16), length);
    that->value = array;

    return that;
}

void  base_System_UInt16Array_free(System_UInt16Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_UInt16Array_get_Length(System_UInt16Array that) {
    return that->length;
}

System_UInt16  base_System_UInt16Array_get_index(System_UInt16Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_UInt16Array_set_index(System_UInt16Array that, System_Size index, System_UInt16 value) {
    array(that->value)[index] = value;
}

void  base_System_UInt16Array_resize(System_UInt16Array that, System_Size length) {
    System_Size element_size = sizeof(System_UInt16);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_UInt16Array_getEnumerator(System_UInt16Array that) {
    return (System_IEnumerator)new_System_UInt16ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_UInt16ArrayTypeFunctions[] = {
    [0] = { .function = base_System_UInt16Array_init, .value = base_System_UInt16Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt16Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_UInt16Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_UInt16Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_UInt16Array_set_index },
    [5] = { .function = base_System_UInt16Array_resize, .value = base_System_UInt16Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_UInt16Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_UInt16ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_UInt16ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt16Array",
    .size = sizeof(struct System_UInt16Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt16ArrayTypeFunctions), .value = &System_UInt16ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_UInt16ArrayTypeInterfaces), .value = &System_UInt16ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_UInt32Array)
#include <min/System.UInt32Array.h>
#endif
#if !defined(code_System_UInt32Array)
#define code_System_UInt32Array

/*# System_UInt32Array #*/

System_UInt32Array base_System_UInt32Array_init(System_UInt32Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_UInt32 (* array)[] = System_Memory_allocArray(typeof(System_UInt32), length);
    that->value = array;

    return that;
}

void  base_System_UInt32Array_free(System_UInt32Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_UInt32Array_get_Length(System_UInt32Array that) {
    return that->length;
}

System_UInt32  base_System_UInt32Array_get_index(System_UInt32Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_UInt32Array_set_index(System_UInt32Array that, System_Size index, System_UInt32 value) {
    array(that->value)[index] = value;
}

void  base_System_UInt32Array_resize(System_UInt32Array that, System_Size length) {
    System_Size element_size = sizeof(System_UInt32);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_UInt32Array_getEnumerator(System_UInt32Array that) {
    return (System_IEnumerator)new_System_UInt32ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_UInt32ArrayTypeFunctions[] = {
    [0] = { .function = base_System_UInt32Array_init, .value = base_System_UInt32Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt32Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_UInt32Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_UInt32Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_UInt32Array_set_index },
    [5] = { .function = base_System_UInt32Array_resize, .value = base_System_UInt32Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_UInt32Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_UInt32ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_UInt32ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt32Array",
    .size = sizeof(struct System_UInt32Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt32ArrayTypeFunctions), .value = &System_UInt32ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_UInt32ArrayTypeInterfaces), .value = &System_UInt32ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_UInt64Array)
#include <min/System.UInt64Array.h>
#endif
#if !defined(code_System_UInt64Array)
#define code_System_UInt64Array

/*# System_UInt64Array #*/

System_UInt64Array base_System_UInt64Array_init(System_UInt64Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_UInt64 (* array)[] = System_Memory_allocArray(typeof(System_UInt64), length);
    that->value = array;

    return that;
}

void  base_System_UInt64Array_free(System_UInt64Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_UInt64Array_get_Length(System_UInt64Array that) {
    return that->length;
}

System_UInt64  base_System_UInt64Array_get_index(System_UInt64Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_UInt64Array_set_index(System_UInt64Array that, System_Size index, System_UInt64 value) {
    array(that->value)[index] = value;
}

void  base_System_UInt64Array_resize(System_UInt64Array that, System_Size length) {
    System_Size element_size = sizeof(System_UInt64);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_UInt64Array_getEnumerator(System_UInt64Array that) {
    return (System_IEnumerator)new_System_UInt64ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_UInt64ArrayTypeFunctions[] = {
    [0] = { .function = base_System_UInt64Array_init, .value = base_System_UInt64Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt64Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_UInt64Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_UInt64Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_UInt64Array_set_index },
    [5] = { .function = base_System_UInt64Array_resize, .value = base_System_UInt64Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_UInt64Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_UInt64ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_UInt64ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt64Array",
    .size = sizeof(struct System_UInt64Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt64ArrayTypeFunctions), .value = &System_UInt64ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_UInt64ArrayTypeInterfaces), .value = &System_UInt64ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int8Array)
#include <min/System.Int8Array.h>
#endif
#if !defined(code_System_Int8Array)
#define code_System_Int8Array

/*# System_Int8Array #*/

System_Int8Array base_System_Int8Array_init(System_Int8Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_Int8 (* array)[] = System_Memory_allocArray(typeof(System_Int8), length);
    that->value = array;

    return that;
}

void  base_System_Int8Array_free(System_Int8Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_Int8Array_get_Length(System_Int8Array that) {
    return that->length;
}

System_Int8  base_System_Int8Array_get_index(System_Int8Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_Int8Array_set_index(System_Int8Array that, System_Size index, System_Int8 value) {
    array(that->value)[index] = value;
}

void  base_System_Int8Array_resize(System_Int8Array that, System_Size length) {
    System_Size element_size = sizeof(System_Int8);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_Int8Array_getEnumerator(System_Int8Array that) {
    return (System_IEnumerator)new_System_Int8ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_Int8ArrayTypeFunctions[] = {
    [0] = { .function = base_System_Int8Array_init, .value = base_System_Int8Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int8Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_Int8Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_Int8Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_Int8Array_set_index },
    [5] = { .function = base_System_Int8Array_resize, .value = base_System_Int8Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_Int8Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_Int8ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_Int8ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int8Array",
    .size = sizeof(struct System_Int8Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int8ArrayTypeFunctions), .value = &System_Int8ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_Int8ArrayTypeInterfaces), .value = &System_Int8ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int16Array)
#include <min/System.Int16Array.h>
#endif
#if !defined(code_System_Int16Array)
#define code_System_Int16Array

/*# System_Int16Array #*/

System_Int16Array base_System_Int16Array_init(System_Int16Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_Int16 (* array)[] = System_Memory_allocArray(typeof(System_Int16), length);
    that->value = array;

    return that;
}

void  base_System_Int16Array_free(System_Int16Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_Int16Array_get_Length(System_Int16Array that) {
    return that->length;
}

System_Int16  base_System_Int16Array_get_index(System_Int16Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_Int16Array_set_index(System_Int16Array that, System_Size index, System_Int16 value) {
    array(that->value)[index] = value;
}

void  base_System_Int16Array_resize(System_Int16Array that, System_Size length) {
    System_Size element_size = sizeof(System_Int16);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_Int16Array_getEnumerator(System_Int16Array that) {
    return (System_IEnumerator)new_System_Int16ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_Int16ArrayTypeFunctions[] = {
    [0] = { .function = base_System_Int16Array_init, .value = base_System_Int16Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int16Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_Int16Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_Int16Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_Int16Array_set_index },
    [5] = { .function = base_System_Int16Array_resize, .value = base_System_Int16Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_Int16Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_Int16ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_Int16ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int16Array",
    .size = sizeof(struct System_Int16Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int16ArrayTypeFunctions), .value = &System_Int16ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_Int16ArrayTypeInterfaces), .value = &System_Int16ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int32Array)
#include <min/System.Int32Array.h>
#endif
#if !defined(code_System_Int32Array)
#define code_System_Int32Array

/*# System_Int32Array #*/

System_Int32Array base_System_Int32Array_init(System_Int32Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_Int32 (* array)[] = System_Memory_allocArray(typeof(System_Int32), length);
    that->value = array;

    return that;
}

void  base_System_Int32Array_free(System_Int32Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_Int32Array_get_Length(System_Int32Array that) {
    return that->length;
}

System_Int32  base_System_Int32Array_get_index(System_Int32Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_Int32Array_set_index(System_Int32Array that, System_Size index, System_Int32 value) {
    array(that->value)[index] = value;
}

void  base_System_Int32Array_resize(System_Int32Array that, System_Size length) {
    System_Size element_size = sizeof(System_Int32);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_Int32Array_getEnumerator(System_Int32Array that) {
    return (System_IEnumerator)new_System_Int32ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_Int32ArrayTypeFunctions[] = {
    [0] = { .function = base_System_Int32Array_init, .value = base_System_Int32Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int32Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_Int32Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_Int32Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_Int32Array_set_index },
    [5] = { .function = base_System_Int32Array_resize, .value = base_System_Int32Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_Int32Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_Int32ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_Int32ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int32Array",
    .size = sizeof(struct System_Int32Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int32ArrayTypeFunctions), .value = &System_Int32ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_Int32ArrayTypeInterfaces), .value = &System_Int32ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int64Array)
#include <min/System.Int64Array.h>
#endif
#if !defined(code_System_Int64Array)
#define code_System_Int64Array

/*# System_Int64Array #*/

System_Int64Array base_System_Int64Array_init(System_Int64Array that, System_Size length) {
    base_System_Object_init((System_Object)that);

    that->length = length;

    System_Int64 (* array)[] = System_Memory_allocArray(typeof(System_Int64), length);
    that->value = array;

    return that;
}

void  base_System_Int64Array_free(System_Int64Array that) {
    System_Memory_free(that->value);

    base_System_Object_free((System_Object)that);
}

System_Size  base_System_Int64Array_get_Length(System_Int64Array that) {
    return that->length;
}

System_Int64  base_System_Int64Array_get_index(System_Int64Array that, System_Size index) {
    return array(that->value)[index];
}

void  base_System_Int64Array_set_index(System_Int64Array that, System_Size index, System_Int64 value) {
    array(that->value)[index] = value;
}

void  base_System_Int64Array_resize(System_Int64Array that, System_Size length) {
    System_Size element_size = sizeof(System_Int64);
    System_Memory_reallocArray((System_Var)that->value, length);
    that->length = length;
}

System_IEnumerator  base_System_Int64Array_getEnumerator(System_Int64Array that) {
    return (System_IEnumerator)new_System_Int64ArrayEnumerator(that);
}

struct System_Type_FunctionInfo  System_Int64ArrayTypeFunctions[] = {
    [0] = { .function = base_System_Int64Array_init, .value = base_System_Int64Array_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int64Array_free },
    [2] = { .function = base_System_ICollection_get_Length, .value = base_System_Int64Array_get_Length },
    [3] = { .function = base_System_ICollection_get_index, .value = base_System_Int64Array_get_index },
    [4] = { .function = base_System_ICollection_set_index, .value = base_System_Int64Array_set_index },
    [5] = { .function = base_System_Int64Array_resize, .value = base_System_Int64Array_resize },
    [6] = { .function = base_System_IEnumerable_getEnumerator, .value = base_System_Int64Array_getEnumerator },
};

struct System_Type_InterfaceInfo  System_Int64ArrayTypeInterfaces[] = {
    [0] = { .interfaceType = &System_ICollectionType },
    [1] = { .interfaceType = &System_IEnumerableType },
};

struct System_Type System_Int64ArrayType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int64Array",
    .size = sizeof(struct System_Int64Array),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int64ArrayTypeFunctions), .value = &System_Int64ArrayTypeFunctions
    },
    .interfaces = {
        .length = sizeof_array(System_Int64ArrayTypeInterfaces), .value = &System_Int64ArrayTypeInterfaces
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt8ArrayEnumerator)
#include <min/System.UInt8ArrayEnumerator.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_UInt8ArrayEnumerator)
#define code_System_UInt8ArrayEnumerator

/*# System_UInt8ArrayEnumerator #*/

System_UInt8ArrayEnumerator  base_System_UInt8ArrayEnumerator_init(System_UInt8ArrayEnumerator that, System_UInt8Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_UInt8Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_UInt8ArrayEnumerator_free(System_UInt8ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_UInt8  base_System_UInt8ArrayEnumerator_get_current(System_UInt8ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_UInt8Array_get_index(that->array, that->index);
}

System_Bool  base_System_UInt8ArrayEnumerator_moveNext(System_UInt8ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_UInt8ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_UInt8ArrayEnumerator_init, .value = base_System_UInt8ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt8ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_UInt8ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_UInt8ArrayEnumerator_moveNext },
};

struct System_Type System_UInt8ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt8ArrayEnumerator",
    .size = sizeof(struct System_UInt8ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt8ArrayEnumeratorTypeFunctions), .value = &System_UInt8ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt16ArrayEnumerator)
#include <min/System.UInt16ArrayEnumerator.h>
#endif
#if !defined(code_System_UInt16ArrayEnumerator)
#define code_System_UInt16ArrayEnumerator

/*# System_UInt16ArrayEnumerator #*/

System_UInt16ArrayEnumerator  base_System_UInt16ArrayEnumerator_init(System_UInt16ArrayEnumerator that, System_UInt16Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_UInt16Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_UInt16ArrayEnumerator_free(System_UInt16ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_UInt16  base_System_UInt16ArrayEnumerator_get_current(System_UInt16ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_UInt16Array_get_index(that->array, that->index);
}

System_Bool  base_System_UInt16ArrayEnumerator_moveNext(System_UInt16ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_UInt16ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_UInt16ArrayEnumerator_init, .value = base_System_UInt16ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt16ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_UInt16ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_UInt16ArrayEnumerator_moveNext },
};

struct System_Type System_UInt16ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt16ArrayEnumerator",
    .size = sizeof(struct System_UInt16ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt16ArrayEnumeratorTypeFunctions), .value = &System_UInt16ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt32ArrayEnumerator)
#include <min/System.UInt32ArrayEnumerator.h>
#endif
#if !defined(code_System_UInt32ArrayEnumerator)
#define code_System_UInt32ArrayEnumerator

/*# System_UInt32ArrayEnumerator #*/

System_UInt32ArrayEnumerator  base_System_UInt32ArrayEnumerator_init(System_UInt32ArrayEnumerator that, System_UInt32Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_UInt32Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_UInt32ArrayEnumerator_free(System_UInt32ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_UInt32  base_System_UInt32ArrayEnumerator_get_current(System_UInt32ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_UInt32Array_get_index(that->array, that->index);
}

System_Bool  base_System_UInt32ArrayEnumerator_moveNext(System_UInt32ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_UInt32ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_UInt32ArrayEnumerator_init, .value = base_System_UInt32ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt32ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_UInt32ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_UInt32ArrayEnumerator_moveNext },
};

struct System_Type System_UInt32ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt32ArrayEnumerator",
    .size = sizeof(struct System_UInt32ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt32ArrayEnumeratorTypeFunctions), .value = &System_UInt32ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt64ArrayEnumerator)
#include <min/System.UInt64ArrayEnumerator.h>
#endif
#if !defined(code_System_UInt64ArrayEnumerator)
#define code_System_UInt64ArrayEnumerator

/*# System_UInt64ArrayEnumerator #*/

System_UInt64ArrayEnumerator  base_System_UInt64ArrayEnumerator_init(System_UInt64ArrayEnumerator that, System_UInt64Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_UInt64Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_UInt64ArrayEnumerator_free(System_UInt64ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_UInt64  base_System_UInt64ArrayEnumerator_get_current(System_UInt64ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_UInt64Array_get_index(that->array, that->index);
}

System_Bool  base_System_UInt64ArrayEnumerator_moveNext(System_UInt64ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_UInt64ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_UInt64ArrayEnumerator_init, .value = base_System_UInt64ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_UInt64ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_UInt64ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_UInt64ArrayEnumerator_moveNext },
};

struct System_Type System_UInt64ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.UInt64ArrayEnumerator",
    .size = sizeof(struct System_UInt64ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_UInt64ArrayEnumeratorTypeFunctions), .value = &System_UInt64ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int8ArrayEnumerator)
#include <min/System.Int8ArrayEnumerator.h>
#endif
#if !defined(code_System_Int8ArrayEnumerator)
#define code_System_Int8ArrayEnumerator

/*# System_Int8ArrayEnumerator #*/

System_Int8ArrayEnumerator  base_System_Int8ArrayEnumerator_init(System_Int8ArrayEnumerator that, System_Int8Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_Int8Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_Int8ArrayEnumerator_free(System_Int8ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Int8  base_System_Int8ArrayEnumerator_get_current(System_Int8ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_Int8Array_get_index(that->array, that->index);
}

System_Bool  base_System_Int8ArrayEnumerator_moveNext(System_Int8ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_Int8ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_Int8ArrayEnumerator_init, .value = base_System_Int8ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int8ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_Int8ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_Int8ArrayEnumerator_moveNext },
};

struct System_Type System_Int8ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int8ArrayEnumerator",
    .size = sizeof(struct System_Int8ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int8ArrayEnumeratorTypeFunctions), .value = &System_Int8ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int16ArrayEnumerator)
#include <min/System.Int16ArrayEnumerator.h>
#endif
#if !defined(code_System_Int16ArrayEnumerator)
#define code_System_Int16ArrayEnumerator

/*# System_Int16ArrayEnumerator #*/

System_Int16ArrayEnumerator  base_System_Int16ArrayEnumerator_init(System_Int16ArrayEnumerator that, System_Int16Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_Int16Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_Int16ArrayEnumerator_free(System_Int16ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Int16  base_System_Int16ArrayEnumerator_get_current(System_Int16ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_Int16Array_get_index(that->array, that->index);
}

System_Bool  base_System_Int16ArrayEnumerator_moveNext(System_Int16ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_Int16ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_Int16ArrayEnumerator_init, .value = base_System_Int16ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int16ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_Int16ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_Int16ArrayEnumerator_moveNext },
};

struct System_Type System_Int16ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int16ArrayEnumerator",
    .size = sizeof(struct System_Int16ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int16ArrayEnumeratorTypeFunctions), .value = &System_Int16ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int32ArrayEnumerator)
#include <min/System.Int32ArrayEnumerator.h>
#endif
#if !defined(code_System_Int32ArrayEnumerator)
#define code_System_Int32ArrayEnumerator

/*# System_Int32ArrayEnumerator #*/

System_Int32ArrayEnumerator  base_System_Int32ArrayEnumerator_init(System_Int32ArrayEnumerator that, System_Int32Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_Int32Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_Int32ArrayEnumerator_free(System_Int32ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Int32  base_System_Int32ArrayEnumerator_get_current(System_Int32ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_Int32Array_get_index(that->array, that->index);
}

System_Bool  base_System_Int32ArrayEnumerator_moveNext(System_Int32ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_Int32ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_Int32ArrayEnumerator_init, .value = base_System_Int32ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int32ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_Int32ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_Int32ArrayEnumerator_moveNext },
};

struct System_Type System_Int32ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int32ArrayEnumerator",
    .size = sizeof(struct System_Int32ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int32ArrayEnumeratorTypeFunctions), .value = &System_Int32ArrayEnumeratorTypeFunctions
    },
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int64ArrayEnumerator)
#include <min/System.Int64ArrayEnumerator.h>
#endif
#if !defined(code_System_Int64ArrayEnumerator)
#define code_System_Int64ArrayEnumerator

/*# System_Int64ArrayEnumerator #*/

System_Int64ArrayEnumerator  base_System_Int64ArrayEnumerator_init(System_Int64ArrayEnumerator that, System_Int64Array array) {
    base_System_Object_init((System_Object)that);

    if (!array) terminate(new_System_Exception("ArgumentNullException: array is null"));

    that->array = (System_Int64Array)System_Memory_addReference((System_Object)array);
    that->index = -1;

    return that;
}

void  base_System_Int64ArrayEnumerator_free(System_Int64ArrayEnumerator that) {

    System_Memory_free(that->array);
    that->index = -2;

    base_System_Object_free((System_Object)that);
}

System_Int64  base_System_Int64ArrayEnumerator_get_current(System_Int64ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));
    if (that->index == -1) throw_return(new_System_Exception("InvalidOperationException: Index Out of Range. No items to enumerate"));

    return System_Int64Array_get_index(that->array, that->index);
}

System_Bool  base_System_Int64ArrayEnumerator_moveNext(System_Int64ArrayEnumerator that) {

    if (that->index == -2) terminate(new_System_Exception("InvalidOperationException: Enumerator already free"));

    System_Size new_index = ++(that->index);
    if (new_index < that->array->length) {
        that->index = new_index;
        return true;
    }
    return false;
}

struct System_Type_FunctionInfo  System_Int64ArrayEnumeratorTypeFunctions[] = {
    [0] = { .function = base_System_Int64ArrayEnumerator_init, .value = base_System_Int64ArrayEnumerator_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Int64ArrayEnumerator_free },
    [2] = { .function = base_System_IEnumerator_get_current, .value = base_System_Int64ArrayEnumerator_get_current },
    [3] = { .function = base_System_IEnumerator_moveNext, .value = base_System_Int64ArrayEnumerator_moveNext },
};

struct System_Type System_Int64ArrayEnumeratorType = { .base = { .type = typeof(System_Type) },
    .name = "System.Int64ArrayEnumerator",
    .size = sizeof(struct System_Int64ArrayEnumerator),
    .baseType = typeof(System_Object),
    .functions = { 
        .length = sizeof_array(System_Int64ArrayEnumeratorTypeFunctions), .value = &System_Int64ArrayEnumeratorTypeFunctions
    },
};

#endif
