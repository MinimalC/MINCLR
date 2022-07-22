/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt8)
#include "System.UInt8.h"
#endif
#if !defined(have_System_UInt8Array)
#define have_System_UInt8Array


typedef fixed struct System_UInt8Array {
    struct System_Object base;

    System_Size  length;

    System_UInt8  (* value)[];

}  * System_UInt8Array;

#define stack_System_UInt8Array(LENGTH)  { .base = stack_System_Object(System_UInt8Array), .length = LENGTH }
#define new_System_UInt8Array(LENGTH)  (base_System_UInt8Array_init((System_UInt8Array)System_Memory_allocClass(typeof(System_UInt8Array)), LENGTH))

export struct System_Type  System_UInt8ArrayType;

typedef void delegate(System_UInt8Array_free)(System_UInt8Array that);
typedef System_UInt8Array delegate(System_UInt8Array_init)(System_UInt8Array that, System_Size length);
typedef System_Size  delegate(System_UInt8Array_get_Length)(System_UInt8Array that);
typedef System_UInt8  delegate(System_UInt8Array_get_index)(System_UInt8Array that, System_Size index);
typedef void  delegate(System_UInt8Array_set_index)(System_UInt8Array that, System_Size index, System_UInt8 value);
typedef void delegate(System_UInt8Array_copyTo)(System_UInt8Array that, System_UInt8Array other, System_Size offset);
typedef void delegate(System_UInt8Array_resize)(System_UInt8Array that, System_Size length);
typedef System_IEnumerator  delegate(System_UInt8Array_getEnumerator)(System_UInt8Array that);

export System_UInt8Array  base_System_UInt8Array_init(System_UInt8Array that, System_Size length);
export void  base_System_UInt8Array_free(System_UInt8Array that);
export System_Size  base_System_UInt8Array_get_Length(System_UInt8Array that);
export System_UInt8  base_System_UInt8Array_get_index(System_UInt8Array that, System_Size index);
export void  base_System_UInt8Array_set_index(System_UInt8Array that, System_Size index, System_UInt8 value);
export void  base_System_UInt8Array_copyTo(System_UInt8Array that, System_UInt8Array other, System_Size offset);
export void  base_System_UInt8Array_resize(System_UInt8Array that, System_Size length);
export System_IEnumerator  base_System_UInt8Array_getEnumerator(System_UInt8Array that);

#define System_UInt8Array_init(o,...)  ((function_System_UInt8Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt8Array_init))(o, __VA_ARGS__)
#define System_UInt8Array_free(o)  ((function_System_UInt8Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt8Array_get_Length(o)  ((function_System_UInt8Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_UInt8Array_get_index(o,...)  ((function_System_UInt8Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_UInt8Array_set_index(o,...)  ((function_System_UInt8Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_UInt8Array_copyTo(o,...)  ((function_System_UInt8Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_UInt8Array_resize(o,...)  ((function_System_UInt8Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt8Array_resize))(o,__VA_ARGS__)
#define System_UInt8Array_getEnumerator(o)  ((function_System_UInt8Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define UInt8Array  System_UInt8Array
#define UInt8ArrayType  System_UInt8ArrayType
#define stack_UInt8Array  stack_System_UInt8Array
#define new_UInt8Array  new_System_UInt8Array
#define UInt8Array_init  System_UInt8Array_init
#define UInt8Array_free  System_UInt8Array_free
#define UInt8Array_get_Length  System_UInt8Array_get_Length
#define UInt8Array_get_index  System_UInt8Array_get_index
#define UInt8Array_set_index  System_UInt8Array_set_index
#define UInt8Array_resize  System_UInt8Array_resize
#define base_UInt8Array_init  base_System_UInt8Array_init
#define base_UInt8Array_free  base_System_UInt8Array_free
#define base_UInt8Array_get_Length  base_System_UInt8Array_get_Length
#define base_UInt8Array_get_index  base_System_UInt8Array_get_index
#define base_UInt8Array_set_index  base_System_UInt8Array_set_index
#define base_UInt8Array_resize  base_System_UInt8Array_resize
#define base_UInt8Array_getEnumerator  base_System_UInt8Array_getEnumerator
#define function_UInt8Array_init  function_System_UInt8Array_init
#define function_UInt8Array_free  function_System_UInt8Array_free
#define function_UInt8Array_get_Length  function_System_UInt8Array_get_Length
#define function_UInt8Array_get_index  function_System_UInt8Array_get_index
#define function_UInt8Array_set_index  function_System_UInt8Array_set_index
#define function_UInt8Array_resize  function_System_UInt8Array_resize
#define function_UInt8Array_getEnumerator  function_System_UInt8Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt16)
#include "System.UInt16.h"
#endif
#if !defined(have_System_UInt16Array)
#define have_System_UInt16Array


typedef fixed struct System_UInt16Array {
    struct System_Object base;

    System_Size  length;

    System_UInt16  (* value)[];

}  * System_UInt16Array;

#define stack_System_UInt16Array(LENGTH)  { .base = stack_System_Object(System_UInt16Array), .length = LENGTH }
#define new_System_UInt16Array(LENGTH)  (base_System_UInt16Array_init((System_UInt16Array)System_Memory_allocClass(typeof(System_UInt16Array)), LENGTH))

export struct System_Type  System_UInt16ArrayType;

typedef void delegate(System_UInt16Array_free)(System_UInt16Array that);
typedef System_UInt16Array delegate(System_UInt16Array_init)(System_UInt16Array that, System_Size length);
typedef System_Size  delegate(System_UInt16Array_get_Length)(System_UInt16Array that);
typedef System_UInt16  delegate(System_UInt16Array_get_index)(System_UInt16Array that, System_Size index);
typedef void  delegate(System_UInt16Array_set_index)(System_UInt16Array that, System_Size index, System_UInt16 value);
typedef void delegate(System_UInt16Array_copyTo)(System_UInt16Array that, System_UInt16Array other, System_Size offset);
typedef void delegate(System_UInt16Array_resize)(System_UInt16Array that, System_Size length);
typedef System_IEnumerator  delegate(System_UInt16Array_getEnumerator)(System_UInt16Array that);

export System_UInt16Array  base_System_UInt16Array_init(System_UInt16Array that, System_Size length);
export void  base_System_UInt16Array_free(System_UInt16Array that);
export System_Size  base_System_UInt16Array_get_Length(System_UInt16Array that);
export System_UInt16  base_System_UInt16Array_get_index(System_UInt16Array that, System_Size index);
export void  base_System_UInt16Array_set_index(System_UInt16Array that, System_Size index, System_UInt16 value);
export void  base_System_UInt16Array_copyTo(System_UInt16Array that, System_UInt16Array other, System_Size offset);
export void  base_System_UInt16Array_resize(System_UInt16Array that, System_Size length);
export System_IEnumerator  base_System_UInt16Array_getEnumerator(System_UInt16Array that);

#define System_UInt16Array_init(o,...)  ((function_System_UInt16Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt16Array_init))(o, __VA_ARGS__)
#define System_UInt16Array_free(o)  ((function_System_UInt16Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt16Array_get_Length(o)  ((function_System_UInt16Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_UInt16Array_get_index(o,...)  ((function_System_UInt16Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_UInt16Array_set_index(o,...)  ((function_System_UInt16Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_UInt16Array_copyTo(o,...)  ((function_System_UInt16Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_UInt16Array_resize(o,...)  ((function_System_UInt16Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt16Array_resize))(o,__VA_ARGS__)
#define System_UInt16Array_getEnumerator(o)  ((function_System_UInt16Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define UInt16Array  System_UInt16Array
#define UInt16ArrayType  System_UInt16ArrayType
#define stack_UInt16Array  stack_System_UInt16Array
#define new_UInt16Array  new_System_UInt16Array
#define UInt16Array_init  System_UInt16Array_init
#define UInt16Array_free  System_UInt16Array_free
#define UInt16Array_get_Length  System_UInt16Array_get_Length
#define UInt16Array_get_index  System_UInt16Array_get_index
#define UInt16Array_set_index  System_UInt16Array_set_index
#define UInt16Array_resize  System_UInt16Array_resize
#define base_UInt16Array_init  base_System_UInt16Array_init
#define base_UInt16Array_free  base_System_UInt16Array_free
#define base_UInt16Array_get_Length  base_System_UInt16Array_get_Length
#define base_UInt16Array_get_index  base_System_UInt16Array_get_index
#define base_UInt16Array_set_index  base_System_UInt16Array_set_index
#define base_UInt16Array_resize  base_System_UInt16Array_resize
#define base_UInt16Array_getEnumerator  base_System_UInt16Array_getEnumerator
#define function_UInt16Array_init  function_System_UInt16Array_init
#define function_UInt16Array_free  function_System_UInt16Array_free
#define function_UInt16Array_get_Length  function_System_UInt16Array_get_Length
#define function_UInt16Array_get_index  function_System_UInt16Array_get_index
#define function_UInt16Array_set_index  function_System_UInt16Array_set_index
#define function_UInt16Array_resize  function_System_UInt16Array_resize
#define function_UInt16Array_getEnumerator  function_System_UInt16Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt32)
#include "System.UInt32.h"
#endif
#if !defined(have_System_UInt32Array)
#define have_System_UInt32Array


typedef fixed struct System_UInt32Array {
    struct System_Object base;

    System_Size  length;

    System_UInt32  (* value)[];

}  * System_UInt32Array;

#define stack_System_UInt32Array(LENGTH)  { .base = stack_System_Object(System_UInt32Array), .length = LENGTH }
#define new_System_UInt32Array(LENGTH)  (base_System_UInt32Array_init((System_UInt32Array)System_Memory_allocClass(typeof(System_UInt32Array)), LENGTH))

export struct System_Type  System_UInt32ArrayType;

typedef void delegate(System_UInt32Array_free)(System_UInt32Array that);
typedef System_UInt32Array delegate(System_UInt32Array_init)(System_UInt32Array that, System_Size length);
typedef System_Size  delegate(System_UInt32Array_get_Length)(System_UInt32Array that);
typedef System_UInt32  delegate(System_UInt32Array_get_index)(System_UInt32Array that, System_Size index);
typedef void  delegate(System_UInt32Array_set_index)(System_UInt32Array that, System_Size index, System_UInt32 value);
typedef void delegate(System_UInt32Array_copyTo)(System_UInt32Array that, System_UInt32Array other, System_Size offset);
typedef void delegate(System_UInt32Array_resize)(System_UInt32Array that, System_Size length);
typedef System_IEnumerator  delegate(System_UInt32Array_getEnumerator)(System_UInt32Array that);

export System_UInt32Array  base_System_UInt32Array_init(System_UInt32Array that, System_Size length);
export void  base_System_UInt32Array_free(System_UInt32Array that);
export System_Size  base_System_UInt32Array_get_Length(System_UInt32Array that);
export System_UInt32  base_System_UInt32Array_get_index(System_UInt32Array that, System_Size index);
export void  base_System_UInt32Array_set_index(System_UInt32Array that, System_Size index, System_UInt32 value);
export void  base_System_UInt32Array_copyTo(System_UInt32Array that, System_UInt32Array other, System_Size offset);
export void  base_System_UInt32Array_resize(System_UInt32Array that, System_Size length);
export System_IEnumerator  base_System_UInt32Array_getEnumerator(System_UInt32Array that);

#define System_UInt32Array_init(o,...)  ((function_System_UInt32Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt32Array_init))(o, __VA_ARGS__)
#define System_UInt32Array_free(o)  ((function_System_UInt32Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt32Array_get_Length(o)  ((function_System_UInt32Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_UInt32Array_get_index(o,...)  ((function_System_UInt32Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_UInt32Array_set_index(o,...)  ((function_System_UInt32Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_UInt32Array_copyTo(o,...)  ((function_System_UInt32Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_UInt32Array_resize(o,...)  ((function_System_UInt32Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt32Array_resize))(o,__VA_ARGS__)
#define System_UInt32Array_getEnumerator(o)  ((function_System_UInt32Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define UInt32Array  System_UInt32Array
#define UInt32ArrayType  System_UInt32ArrayType
#define stack_UInt32Array  stack_System_UInt32Array
#define new_UInt32Array  new_System_UInt32Array
#define UInt32Array_init  System_UInt32Array_init
#define UInt32Array_free  System_UInt32Array_free
#define UInt32Array_get_Length  System_UInt32Array_get_Length
#define UInt32Array_get_index  System_UInt32Array_get_index
#define UInt32Array_set_index  System_UInt32Array_set_index
#define UInt32Array_resize  System_UInt32Array_resize
#define base_UInt32Array_init  base_System_UInt32Array_init
#define base_UInt32Array_free  base_System_UInt32Array_free
#define base_UInt32Array_get_Length  base_System_UInt32Array_get_Length
#define base_UInt32Array_get_index  base_System_UInt32Array_get_index
#define base_UInt32Array_set_index  base_System_UInt32Array_set_index
#define base_UInt32Array_resize  base_System_UInt32Array_resize
#define base_UInt32Array_getEnumerator  base_System_UInt32Array_getEnumerator
#define function_UInt32Array_init  function_System_UInt32Array_init
#define function_UInt32Array_free  function_System_UInt32Array_free
#define function_UInt32Array_get_Length  function_System_UInt32Array_get_Length
#define function_UInt32Array_get_index  function_System_UInt32Array_get_index
#define function_UInt32Array_set_index  function_System_UInt32Array_set_index
#define function_UInt32Array_resize  function_System_UInt32Array_resize
#define function_UInt32Array_getEnumerator  function_System_UInt32Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt64)
#include "System.UInt64.h"
#endif
#if !defined(have_System_UInt64Array)
#define have_System_UInt64Array


typedef fixed struct System_UInt64Array {
    struct System_Object base;

    System_Size  length;

    System_UInt64  (* value)[];

}  * System_UInt64Array;

#define stack_System_UInt64Array(LENGTH)  { .base = stack_System_Object(System_UInt64Array), .length = LENGTH }
#define new_System_UInt64Array(LENGTH)  (base_System_UInt64Array_init((System_UInt64Array)System_Memory_allocClass(typeof(System_UInt64Array)), LENGTH))

export struct System_Type  System_UInt64ArrayType;

typedef void delegate(System_UInt64Array_free)(System_UInt64Array that);
typedef System_UInt64Array delegate(System_UInt64Array_init)(System_UInt64Array that, System_Size length);
typedef System_Size  delegate(System_UInt64Array_get_Length)(System_UInt64Array that);
typedef System_UInt64  delegate(System_UInt64Array_get_index)(System_UInt64Array that, System_Size index);
typedef void  delegate(System_UInt64Array_set_index)(System_UInt64Array that, System_Size index, System_UInt64 value);
typedef void delegate(System_UInt64Array_copyTo)(System_UInt64Array that, System_UInt64Array other, System_Size offset);
typedef void delegate(System_UInt64Array_resize)(System_UInt64Array that, System_Size length);
typedef System_IEnumerator  delegate(System_UInt64Array_getEnumerator)(System_UInt64Array that);

export System_UInt64Array  base_System_UInt64Array_init(System_UInt64Array that, System_Size length);
export void  base_System_UInt64Array_free(System_UInt64Array that);
export System_Size  base_System_UInt64Array_get_Length(System_UInt64Array that);
export System_UInt64  base_System_UInt64Array_get_index(System_UInt64Array that, System_Size index);
export void  base_System_UInt64Array_set_index(System_UInt64Array that, System_Size index, System_UInt64 value);
export void  base_System_UInt64Array_copyTo(System_UInt64Array that, System_UInt64Array other, System_Size offset);
export void  base_System_UInt64Array_resize(System_UInt64Array that, System_Size length);
export System_IEnumerator  base_System_UInt64Array_getEnumerator(System_UInt64Array that);

#define System_UInt64Array_init(o,...)  ((function_System_UInt64Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt64Array_init))(o, __VA_ARGS__)
#define System_UInt64Array_free(o)  ((function_System_UInt64Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt64Array_get_Length(o)  ((function_System_UInt64Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_UInt64Array_get_index(o,...)  ((function_System_UInt64Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_UInt64Array_set_index(o,...)  ((function_System_UInt64Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_UInt64Array_copyTo(o,...)  ((function_System_UInt64Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_UInt64Array_resize(o,...)  ((function_System_UInt64Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt64Array_resize))(o,__VA_ARGS__)
#define System_UInt64Array_getEnumerator(o)  ((function_System_UInt64Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define UInt64Array  System_UInt64Array
#define UInt64ArrayType  System_UInt64ArrayType
#define stack_UInt64Array  stack_System_UInt64Array
#define new_UInt64Array  new_System_UInt64Array
#define UInt64Array_init  System_UInt64Array_init
#define UInt64Array_free  System_UInt64Array_free
#define UInt64Array_get_Length  System_UInt64Array_get_Length
#define UInt64Array_get_index  System_UInt64Array_get_index
#define UInt64Array_set_index  System_UInt64Array_set_index
#define UInt64Array_resize  System_UInt64Array_resize
#define base_UInt64Array_init  base_System_UInt64Array_init
#define base_UInt64Array_free  base_System_UInt64Array_free
#define base_UInt64Array_get_Length  base_System_UInt64Array_get_Length
#define base_UInt64Array_get_index  base_System_UInt64Array_get_index
#define base_UInt64Array_set_index  base_System_UInt64Array_set_index
#define base_UInt64Array_resize  base_System_UInt64Array_resize
#define base_UInt64Array_getEnumerator  base_System_UInt64Array_getEnumerator
#define function_UInt64Array_init  function_System_UInt64Array_init
#define function_UInt64Array_free  function_System_UInt64Array_free
#define function_UInt64Array_get_Length  function_System_UInt64Array_get_Length
#define function_UInt64Array_get_index  function_System_UInt64Array_get_index
#define function_UInt64Array_set_index  function_System_UInt64Array_set_index
#define function_UInt64Array_resize  function_System_UInt64Array_resize
#define function_UInt64Array_getEnumerator  function_System_UInt64Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int8)
#include "System.Int8.h"
#endif
#if !defined(have_System_Int8Array)
#define have_System_Int8Array


typedef fixed struct System_Int8Array {
    struct System_Object base;

    System_Size  length;

    System_Int8  (* value)[];

}  * System_Int8Array;

#define stack_System_Int8Array(LENGTH)  { .base = stack_System_Object(System_Int8Array), .length = LENGTH }
#define new_System_Int8Array(LENGTH)  (base_System_Int8Array_init((System_Int8Array)System_Memory_allocClass(typeof(System_Int8Array)), LENGTH))

export struct System_Type  System_Int8ArrayType;

typedef void delegate(System_Int8Array_free)(System_Int8Array that);
typedef System_Int8Array delegate(System_Int8Array_init)(System_Int8Array that, System_Size length);
typedef System_Size  delegate(System_Int8Array_get_Length)(System_Int8Array that);
typedef System_Int8  delegate(System_Int8Array_get_index)(System_Int8Array that, System_Size index);
typedef void  delegate(System_Int8Array_set_index)(System_Int8Array that, System_Size index, System_Int8 value);
typedef void delegate(System_Int8Array_copyTo)(System_Int8Array that, System_Int8Array other, System_Size offset);
typedef void delegate(System_Int8Array_resize)(System_Int8Array that, System_Size length);
typedef System_IEnumerator  delegate(System_Int8Array_getEnumerator)(System_Int8Array that);

export System_Int8Array  base_System_Int8Array_init(System_Int8Array that, System_Size length);
export void  base_System_Int8Array_free(System_Int8Array that);
export System_Size  base_System_Int8Array_get_Length(System_Int8Array that);
export System_Int8  base_System_Int8Array_get_index(System_Int8Array that, System_Size index);
export void  base_System_Int8Array_set_index(System_Int8Array that, System_Size index, System_Int8 value);
export void  base_System_Int8Array_copyTo(System_Int8Array that, System_Int8Array other, System_Size offset);
export void  base_System_Int8Array_resize(System_Int8Array that, System_Size length);
export System_IEnumerator  base_System_Int8Array_getEnumerator(System_Int8Array that);

#define System_Int8Array_init(o,...)  ((function_System_Int8Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int8Array_init))(o, __VA_ARGS__)
#define System_Int8Array_free(o)  ((function_System_Int8Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int8Array_get_Length(o)  ((function_System_Int8Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_Int8Array_get_index(o,...)  ((function_System_Int8Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_Int8Array_set_index(o,...)  ((function_System_Int8Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_Int8Array_copyTo(o,...)  ((function_System_Int8Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_Int8Array_resize(o,...)  ((function_System_Int8Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int8Array_resize))(o,__VA_ARGS__)
#define System_Int8Array_getEnumerator(o)  ((function_System_Int8Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define Int8Array  System_Int8Array
#define Int8ArrayType  System_Int8ArrayType
#define stack_Int8Array  stack_System_Int8Array
#define new_Int8Array  new_System_Int8Array
#define Int8Array_init  System_Int8Array_init
#define Int8Array_free  System_Int8Array_free
#define Int8Array_get_Length  System_Int8Array_get_Length
#define Int8Array_get_index  System_Int8Array_get_index
#define Int8Array_set_index  System_Int8Array_set_index
#define Int8Array_resize  System_Int8Array_resize
#define base_Int8Array_init  base_System_Int8Array_init
#define base_Int8Array_free  base_System_Int8Array_free
#define base_Int8Array_get_Length  base_System_Int8Array_get_Length
#define base_Int8Array_get_index  base_System_Int8Array_get_index
#define base_Int8Array_set_index  base_System_Int8Array_set_index
#define base_Int8Array_resize  base_System_Int8Array_resize
#define base_Int8Array_getEnumerator  base_System_Int8Array_getEnumerator
#define function_Int8Array_init  function_System_Int8Array_init
#define function_Int8Array_free  function_System_Int8Array_free
#define function_Int8Array_get_Length  function_System_Int8Array_get_Length
#define function_Int8Array_get_index  function_System_Int8Array_get_index
#define function_Int8Array_set_index  function_System_Int8Array_set_index
#define function_Int8Array_resize  function_System_Int8Array_resize
#define function_Int8Array_getEnumerator  function_System_Int8Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int16)
#include "System.Int16.h"
#endif
#if !defined(have_System_Int16Array)
#define have_System_Int16Array


typedef fixed struct System_Int16Array {
    struct System_Object base;

    System_Size  length;

    System_Int16  (* value)[];

}  * System_Int16Array;

#define stack_System_Int16Array(LENGTH)  { .base = stack_System_Object(System_Int16Array), .length = LENGTH }
#define new_System_Int16Array(LENGTH)  (base_System_Int16Array_init((System_Int16Array)System_Memory_allocClass(typeof(System_Int16Array)), LENGTH))

export struct System_Type  System_Int16ArrayType;

typedef void delegate(System_Int16Array_free)(System_Int16Array that);
typedef System_Int16Array delegate(System_Int16Array_init)(System_Int16Array that, System_Size length);
typedef System_Size  delegate(System_Int16Array_get_Length)(System_Int16Array that);
typedef System_Int16  delegate(System_Int16Array_get_index)(System_Int16Array that, System_Size index);
typedef void  delegate(System_Int16Array_set_index)(System_Int16Array that, System_Size index, System_Int16 value);
typedef void delegate(System_Int16Array_copyTo)(System_Int16Array that, System_Int16Array other, System_Size offset);
typedef void delegate(System_Int16Array_resize)(System_Int16Array that, System_Size length);
typedef System_IEnumerator  delegate(System_Int16Array_getEnumerator)(System_Int16Array that);

export System_Int16Array  base_System_Int16Array_init(System_Int16Array that, System_Size length);
export void  base_System_Int16Array_free(System_Int16Array that);
export System_Size  base_System_Int16Array_get_Length(System_Int16Array that);
export System_Int16  base_System_Int16Array_get_index(System_Int16Array that, System_Size index);
export void  base_System_Int16Array_set_index(System_Int16Array that, System_Size index, System_Int16 value);
export void  base_System_Int16Array_copyTo(System_Int16Array that, System_Int16Array other, System_Size offset);
export void  base_System_Int16Array_resize(System_Int16Array that, System_Size length);
export System_IEnumerator  base_System_Int16Array_getEnumerator(System_Int16Array that);

#define System_Int16Array_init(o,...)  ((function_System_Int16Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int16Array_init))(o, __VA_ARGS__)
#define System_Int16Array_free(o)  ((function_System_Int16Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int16Array_get_Length(o)  ((function_System_Int16Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_Int16Array_get_index(o,...)  ((function_System_Int16Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_Int16Array_set_index(o,...)  ((function_System_Int16Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_Int16Array_copyTo(o,...)  ((function_System_Int16Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_Int16Array_resize(o,...)  ((function_System_Int16Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int16Array_resize))(o,__VA_ARGS__)
#define System_Int16Array_getEnumerator(o)  ((function_System_Int16Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define Int16Array  System_Int16Array
#define Int16ArrayType  System_Int16ArrayType
#define stack_Int16Array  stack_System_Int16Array
#define new_Int16Array  new_System_Int16Array
#define Int16Array_init  System_Int16Array_init
#define Int16Array_free  System_Int16Array_free
#define Int16Array_get_Length  System_Int16Array_get_Length
#define Int16Array_get_index  System_Int16Array_get_index
#define Int16Array_set_index  System_Int16Array_set_index
#define Int16Array_resize  System_Int16Array_resize
#define base_Int16Array_init  base_System_Int16Array_init
#define base_Int16Array_free  base_System_Int16Array_free
#define base_Int16Array_get_Length  base_System_Int16Array_get_Length
#define base_Int16Array_get_index  base_System_Int16Array_get_index
#define base_Int16Array_set_index  base_System_Int16Array_set_index
#define base_Int16Array_resize  base_System_Int16Array_resize
#define base_Int16Array_getEnumerator  base_System_Int16Array_getEnumerator
#define function_Int16Array_init  function_System_Int16Array_init
#define function_Int16Array_free  function_System_Int16Array_free
#define function_Int16Array_get_Length  function_System_Int16Array_get_Length
#define function_Int16Array_get_index  function_System_Int16Array_get_index
#define function_Int16Array_set_index  function_System_Int16Array_set_index
#define function_Int16Array_resize  function_System_Int16Array_resize
#define function_Int16Array_getEnumerator  function_System_Int16Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int32)
#include "System.Int32.h"
#endif
#if !defined(have_System_Int32Array)
#define have_System_Int32Array


typedef fixed struct System_Int32Array {
    struct System_Object base;

    System_Size  length;

    System_Int32  (* value)[];

}  * System_Int32Array;

#define stack_System_Int32Array(LENGTH)  { .base = stack_System_Object(System_Int32Array), .length = LENGTH }
#define new_System_Int32Array(LENGTH)  (base_System_Int32Array_init((System_Int32Array)System_Memory_allocClass(typeof(System_Int32Array)), LENGTH))

export struct System_Type  System_Int32ArrayType;

typedef void delegate(System_Int32Array_free)(System_Int32Array that);
typedef System_Int32Array delegate(System_Int32Array_init)(System_Int32Array that, System_Size length);
typedef System_Size  delegate(System_Int32Array_get_Length)(System_Int32Array that);
typedef System_Int32  delegate(System_Int32Array_get_index)(System_Int32Array that, System_Size index);
typedef void  delegate(System_Int32Array_set_index)(System_Int32Array that, System_Size index, System_Int32 value);
typedef void delegate(System_Int32Array_copyTo)(System_Int32Array that, System_Int32Array other, System_Size offset);
typedef void delegate(System_Int32Array_resize)(System_Int32Array that, System_Size length);
typedef System_IEnumerator  delegate(System_Int32Array_getEnumerator)(System_Int32Array that);

export System_Int32Array  base_System_Int32Array_init(System_Int32Array that, System_Size length);
export void  base_System_Int32Array_free(System_Int32Array that);
export System_Size  base_System_Int32Array_get_Length(System_Int32Array that);
export System_Int32  base_System_Int32Array_get_index(System_Int32Array that, System_Size index);
export void  base_System_Int32Array_set_index(System_Int32Array that, System_Size index, System_Int32 value);
export void  base_System_Int32Array_copyTo(System_Int32Array that, System_Int32Array other, System_Size offset);
export void  base_System_Int32Array_resize(System_Int32Array that, System_Size length);
export System_IEnumerator  base_System_Int32Array_getEnumerator(System_Int32Array that);

#define System_Int32Array_init(o,...)  ((function_System_Int32Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int32Array_init))(o, __VA_ARGS__)
#define System_Int32Array_free(o)  ((function_System_Int32Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int32Array_get_Length(o)  ((function_System_Int32Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_Int32Array_get_index(o,...)  ((function_System_Int32Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_Int32Array_set_index(o,...)  ((function_System_Int32Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_Int32Array_copyTo(o,...)  ((function_System_Int32Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_Int32Array_resize(o,...)  ((function_System_Int32Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int32Array_resize))(o,__VA_ARGS__)
#define System_Int32Array_getEnumerator(o)  ((function_System_Int32Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define Int32Array  System_Int32Array
#define Int32ArrayType  System_Int32ArrayType
#define stack_Int32Array  stack_System_Int32Array
#define new_Int32Array  new_System_Int32Array
#define Int32Array_init  System_Int32Array_init
#define Int32Array_free  System_Int32Array_free
#define Int32Array_get_Length  System_Int32Array_get_Length
#define Int32Array_get_index  System_Int32Array_get_index
#define Int32Array_set_index  System_Int32Array_set_index
#define Int32Array_resize  System_Int32Array_resize
#define base_Int32Array_init  base_System_Int32Array_init
#define base_Int32Array_free  base_System_Int32Array_free
#define base_Int32Array_get_Length  base_System_Int32Array_get_Length
#define base_Int32Array_get_index  base_System_Int32Array_get_index
#define base_Int32Array_set_index  base_System_Int32Array_set_index
#define base_Int32Array_resize  base_System_Int32Array_resize
#define base_Int32Array_getEnumerator  base_System_Int32Array_getEnumerator
#define function_Int32Array_init  function_System_Int32Array_init
#define function_Int32Array_free  function_System_Int32Array_free
#define function_Int32Array_get_Length  function_System_Int32Array_get_Length
#define function_Int32Array_get_index  function_System_Int32Array_get_index
#define function_Int32Array_set_index  function_System_Int32Array_set_index
#define function_Int32Array_resize  function_System_Int32Array_resize
#define function_Int32Array_getEnumerator  function_System_Int32Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int64)
#include "System.Int64.h"
#endif
#if !defined(have_System_Int64Array)
#define have_System_Int64Array


typedef fixed struct System_Int64Array {
    struct System_Object base;

    System_Size  length;

    System_Int64  (* value)[];

}  * System_Int64Array;

#define stack_System_Int64Array(LENGTH)  { .base = stack_System_Object(System_Int64Array), .length = LENGTH }
#define new_System_Int64Array(LENGTH)  (base_System_Int64Array_init((System_Int64Array)System_Memory_allocClass(typeof(System_Int64Array)), LENGTH))

export struct System_Type  System_Int64ArrayType;

typedef void delegate(System_Int64Array_free)(System_Int64Array that);
typedef System_Int64Array delegate(System_Int64Array_init)(System_Int64Array that, System_Size length);
typedef System_Size  delegate(System_Int64Array_get_Length)(System_Int64Array that);
typedef System_Int64  delegate(System_Int64Array_get_index)(System_Int64Array that, System_Size index);
typedef void  delegate(System_Int64Array_set_index)(System_Int64Array that, System_Size index, System_Int64 value);
typedef void delegate(System_Int64Array_copyTo)(System_Int64Array that, System_Int64Array other, System_Size offset);
typedef void delegate(System_Int64Array_resize)(System_Int64Array that, System_Size length);
typedef System_IEnumerator  delegate(System_Int64Array_getEnumerator)(System_Int64Array that);

export System_Int64Array  base_System_Int64Array_init(System_Int64Array that, System_Size length);
export void  base_System_Int64Array_free(System_Int64Array that);
export System_Size  base_System_Int64Array_get_Length(System_Int64Array that);
export System_Int64  base_System_Int64Array_get_index(System_Int64Array that, System_Size index);
export void  base_System_Int64Array_set_index(System_Int64Array that, System_Size index, System_Int64 value);
export void  base_System_Int64Array_copyTo(System_Int64Array that, System_Int64Array other, System_Size offset);
export void  base_System_Int64Array_resize(System_Int64Array that, System_Size length);
export System_IEnumerator  base_System_Int64Array_getEnumerator(System_Int64Array that);

#define System_Int64Array_init(o,...)  ((function_System_Int64Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int64Array_init))(o, __VA_ARGS__)
#define System_Int64Array_free(o)  ((function_System_Int64Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int64Array_get_Length(o)  ((function_System_Int64Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_Int64Array_get_index(o,...)  ((function_System_Int64Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_Int64Array_set_index(o,...)  ((function_System_Int64Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_Int64Array_copyTo(o,...)  ((function_System_Int64Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_Int64Array_resize(o,...)  ((function_System_Int64Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int64Array_resize))(o,__VA_ARGS__)
#define System_Int64Array_getEnumerator(o)  ((function_System_Int64Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#if defined(using_System)
#define Int64Array  System_Int64Array
#define Int64ArrayType  System_Int64ArrayType
#define stack_Int64Array  stack_System_Int64Array
#define new_Int64Array  new_System_Int64Array
#define Int64Array_init  System_Int64Array_init
#define Int64Array_free  System_Int64Array_free
#define Int64Array_get_Length  System_Int64Array_get_Length
#define Int64Array_get_index  System_Int64Array_get_index
#define Int64Array_set_index  System_Int64Array_set_index
#define Int64Array_resize  System_Int64Array_resize
#define base_Int64Array_init  base_System_Int64Array_init
#define base_Int64Array_free  base_System_Int64Array_free
#define base_Int64Array_get_Length  base_System_Int64Array_get_Length
#define base_Int64Array_get_index  base_System_Int64Array_get_index
#define base_Int64Array_set_index  base_System_Int64Array_set_index
#define base_Int64Array_resize  base_System_Int64Array_resize
#define base_Int64Array_getEnumerator  base_System_Int64Array_getEnumerator
#define function_Int64Array_init  function_System_Int64Array_init
#define function_Int64Array_free  function_System_Int64Array_free
#define function_Int64Array_get_Length  function_System_Int64Array_get_Length
#define function_Int64Array_get_index  function_System_Int64Array_get_index
#define function_Int64Array_set_index  function_System_Int64Array_set_index
#define function_Int64Array_resize  function_System_Int64Array_resize
#define function_Int64Array_getEnumerator  function_System_Int64Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt8Array)
#include "System.UInt8Array.h"
#endif
#if !defined(have_System_UInt8ArrayEnumerator)
#define have_System_UInt8ArrayEnumerator

typedef fixed struct System_UInt8ArrayEnumerator {
    struct System_Object base;

    System_UInt8Array array;

    System_Size index;

}  * System_UInt8ArrayEnumerator;

#define stack_System_UInt8ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_UInt8ArrayEnumerator), .array = ARRAY, }
#define new_System_UInt8ArrayEnumerator(ARRAY)  (base_System_UInt8ArrayEnumerator_init((System_UInt8ArrayEnumerator)System_Memory_allocClass(typeof(System_UInt8ArrayEnumerator)), ARRAY))

export struct System_Type  System_UInt8ArrayEnumeratorType;

typedef void delegate(System_UInt8ArrayEnumerator_free)(System_UInt8ArrayEnumerator that);
typedef System_UInt8ArrayEnumerator delegate(System_UInt8ArrayEnumerator_init)(System_UInt8ArrayEnumerator that, System_UInt8Array array);
typedef System_UInt8 delegate(System_UInt8ArrayEnumerator_get_current)(System_UInt8ArrayEnumerator that);
typedef System_Bool delegate(System_UInt8ArrayEnumerator_moveNext)(System_UInt8ArrayEnumerator that);

export System_UInt8ArrayEnumerator  base_System_UInt8ArrayEnumerator_init(System_UInt8ArrayEnumerator that, System_UInt8Array array);
export void  base_System_UInt8ArrayEnumerator_free(System_UInt8ArrayEnumerator that);
export System_UInt8  base_System_UInt8ArrayEnumerator_get_current(System_UInt8ArrayEnumerator that);
export System_Bool  base_System_UInt8ArrayEnumerator_moveNext(System_UInt8ArrayEnumerator that);

#define System_UInt8ArrayEnumerator_init(o,...)  ((function_System_UInt8ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt8ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_UInt8ArrayEnumerator_free(o)  ((function_System_UInt8ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt8ArrayEnumerator_get_current(o)  ((function_System_UInt8ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_UInt8ArrayEnumerator_moveNext(o)  ((function_System_UInt8ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define UInt8ArrayEnumerator  System_UInt8ArrayEnumerator
#define UInt8ArrayEnumeratorType  System_UInt8ArrayEnumeratorType
#define stack_UInt8ArrayEnumerator  stack_System_UInt8ArrayEnumerator
#define new_UInt8ArrayEnumerator  new_System_UInt8ArrayEnumerator
#define function_UInt8ArrayEnumerator_init  function_System_UInt8ArrayEnumerator_init
#define function_UInt8ArrayEnumerator_free  function_System_UInt8ArrayEnumerator_free
#define base_UInt8ArrayEnumerator_init  base_System_UInt8ArrayEnumerator_init
#define base_UInt8ArrayEnumerator_free  base_System_UInt8ArrayEnumerator_free
#define UInt8ArrayEnumerator_init  System_UInt8ArrayEnumerator_init
#define UInt8ArrayEnumerator_free  System_UInt8ArrayEnumerator_free
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt16Array)
#include "System.UInt16Array.h"
#endif
#if !defined(have_System_UInt16ArrayEnumerator)
#define have_System_UInt16ArrayEnumerator

typedef fixed struct System_UInt16ArrayEnumerator {
    struct System_Object base;

    System_UInt16Array array;

    System_Size index;

}  * System_UInt16ArrayEnumerator;

#define stack_System_UInt16ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_UInt16ArrayEnumerator), .array = ARRAY, }
#define new_System_UInt16ArrayEnumerator(ARRAY)  (base_System_UInt16ArrayEnumerator_init((System_UInt16ArrayEnumerator)System_Memory_allocClass(typeof(System_UInt16ArrayEnumerator)), ARRAY))

export struct System_Type  System_UInt16ArrayEnumeratorType;

typedef void delegate(System_UInt16ArrayEnumerator_free)(System_UInt16ArrayEnumerator that);
typedef System_UInt16ArrayEnumerator delegate(System_UInt16ArrayEnumerator_init)(System_UInt16ArrayEnumerator that, System_UInt16Array array);
typedef System_UInt16 delegate(System_UInt16ArrayEnumerator_get_current)(System_UInt16ArrayEnumerator that);
typedef System_Bool delegate(System_UInt16ArrayEnumerator_moveNext)(System_UInt16ArrayEnumerator that);

export System_UInt16ArrayEnumerator  base_System_UInt16ArrayEnumerator_init(System_UInt16ArrayEnumerator that, System_UInt16Array array);
export void  base_System_UInt16ArrayEnumerator_free(System_UInt16ArrayEnumerator that);
export System_UInt16  base_System_UInt16ArrayEnumerator_get_current(System_UInt16ArrayEnumerator that);
export System_Bool  base_System_UInt16ArrayEnumerator_moveNext(System_UInt16ArrayEnumerator that);

#define System_UInt16ArrayEnumerator_init(o,...)  ((function_System_UInt16ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt16ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_UInt16ArrayEnumerator_free(o)  ((function_System_UInt16ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt16ArrayEnumerator_get_current(o)  ((function_System_UInt16ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_UInt16ArrayEnumerator_moveNext(o)  ((function_System_UInt16ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define UInt16ArrayEnumerator  System_UInt16ArrayEnumerator
#define UInt16ArrayEnumeratorType  System_UInt16ArrayEnumeratorType
#define stack_UInt16ArrayEnumerator  stack_System_UInt16ArrayEnumerator
#define new_UInt16ArrayEnumerator  new_System_UInt16ArrayEnumerator
#define function_UInt16ArrayEnumerator_init  function_System_UInt16ArrayEnumerator_init
#define function_UInt16ArrayEnumerator_free  function_System_UInt16ArrayEnumerator_free
#define base_UInt16ArrayEnumerator_init  base_System_UInt16ArrayEnumerator_init
#define base_UInt16ArrayEnumerator_free  base_System_UInt16ArrayEnumerator_free
#define UInt16ArrayEnumerator_init  System_UInt16ArrayEnumerator_init
#define UInt16ArrayEnumerator_free  System_UInt16ArrayEnumerator_free
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt32Array)
#include "System.UInt32Array.h"
#endif
#if !defined(have_System_UInt32ArrayEnumerator)
#define have_System_UInt32ArrayEnumerator

typedef fixed struct System_UInt32ArrayEnumerator {
    struct System_Object base;

    System_UInt32Array array;

    System_Size index;

}  * System_UInt32ArrayEnumerator;

#define stack_System_UInt32ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_UInt32ArrayEnumerator), .array = ARRAY, }
#define new_System_UInt32ArrayEnumerator(ARRAY)  (base_System_UInt32ArrayEnumerator_init((System_UInt32ArrayEnumerator)System_Memory_allocClass(typeof(System_UInt32ArrayEnumerator)), ARRAY))

export struct System_Type  System_UInt32ArrayEnumeratorType;

typedef void delegate(System_UInt32ArrayEnumerator_free)(System_UInt32ArrayEnumerator that);
typedef System_UInt32ArrayEnumerator delegate(System_UInt32ArrayEnumerator_init)(System_UInt32ArrayEnumerator that, System_UInt32Array array);
typedef System_UInt32 delegate(System_UInt32ArrayEnumerator_get_current)(System_UInt32ArrayEnumerator that);
typedef System_Bool delegate(System_UInt32ArrayEnumerator_moveNext)(System_UInt32ArrayEnumerator that);

export System_UInt32ArrayEnumerator  base_System_UInt32ArrayEnumerator_init(System_UInt32ArrayEnumerator that, System_UInt32Array array);
export void  base_System_UInt32ArrayEnumerator_free(System_UInt32ArrayEnumerator that);
export System_UInt32  base_System_UInt32ArrayEnumerator_get_current(System_UInt32ArrayEnumerator that);
export System_Bool  base_System_UInt32ArrayEnumerator_moveNext(System_UInt32ArrayEnumerator that);

#define System_UInt32ArrayEnumerator_init(o,...)  ((function_System_UInt32ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt32ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_UInt32ArrayEnumerator_free(o)  ((function_System_UInt32ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt32ArrayEnumerator_get_current(o)  ((function_System_UInt32ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_UInt32ArrayEnumerator_moveNext(o)  ((function_System_UInt32ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define UInt32ArrayEnumerator  System_UInt32ArrayEnumerator
#define UInt32ArrayEnumeratorType  System_UInt32ArrayEnumeratorType
#define stack_UInt32ArrayEnumerator  stack_System_UInt32ArrayEnumerator
#define new_UInt32ArrayEnumerator  new_System_UInt32ArrayEnumerator
#define function_UInt32ArrayEnumerator_init  function_System_UInt32ArrayEnumerator_init
#define function_UInt32ArrayEnumerator_free  function_System_UInt32ArrayEnumerator_free
#define base_UInt32ArrayEnumerator_init  base_System_UInt32ArrayEnumerator_init
#define base_UInt32ArrayEnumerator_free  base_System_UInt32ArrayEnumerator_free
#define UInt32ArrayEnumerator_init  System_UInt32ArrayEnumerator_init
#define UInt32ArrayEnumerator_free  System_UInt32ArrayEnumerator_free
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_UInt64Array)
#include "System.UInt64Array.h"
#endif
#if !defined(have_System_UInt64ArrayEnumerator)
#define have_System_UInt64ArrayEnumerator

typedef fixed struct System_UInt64ArrayEnumerator {
    struct System_Object base;

    System_UInt64Array array;

    System_Size index;

}  * System_UInt64ArrayEnumerator;

#define stack_System_UInt64ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_UInt64ArrayEnumerator), .array = ARRAY, }
#define new_System_UInt64ArrayEnumerator(ARRAY)  (base_System_UInt64ArrayEnumerator_init((System_UInt64ArrayEnumerator)System_Memory_allocClass(typeof(System_UInt64ArrayEnumerator)), ARRAY))

export struct System_Type  System_UInt64ArrayEnumeratorType;

typedef void delegate(System_UInt64ArrayEnumerator_free)(System_UInt64ArrayEnumerator that);
typedef System_UInt64ArrayEnumerator delegate(System_UInt64ArrayEnumerator_init)(System_UInt64ArrayEnumerator that, System_UInt64Array array);
typedef System_UInt64 delegate(System_UInt64ArrayEnumerator_get_current)(System_UInt64ArrayEnumerator that);
typedef System_Bool delegate(System_UInt64ArrayEnumerator_moveNext)(System_UInt64ArrayEnumerator that);

export System_UInt64ArrayEnumerator  base_System_UInt64ArrayEnumerator_init(System_UInt64ArrayEnumerator that, System_UInt64Array array);
export void  base_System_UInt64ArrayEnumerator_free(System_UInt64ArrayEnumerator that);
export System_UInt64  base_System_UInt64ArrayEnumerator_get_current(System_UInt64ArrayEnumerator that);
export System_Bool  base_System_UInt64ArrayEnumerator_moveNext(System_UInt64ArrayEnumerator that);

#define System_UInt64ArrayEnumerator_init(o,...)  ((function_System_UInt64ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_UInt64ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_UInt64ArrayEnumerator_free(o)  ((function_System_UInt64ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_UInt64ArrayEnumerator_get_current(o)  ((function_System_UInt64ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_UInt64ArrayEnumerator_moveNext(o)  ((function_System_UInt64ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define UInt64ArrayEnumerator  System_UInt64ArrayEnumerator
#define UInt64ArrayEnumeratorType  System_UInt64ArrayEnumeratorType
#define stack_UInt64ArrayEnumerator  stack_System_UInt64ArrayEnumerator
#define new_UInt64ArrayEnumerator  new_System_UInt64ArrayEnumerator
#define function_UInt64ArrayEnumerator_init  function_System_UInt64ArrayEnumerator_init
#define function_UInt64ArrayEnumerator_free  function_System_UInt64ArrayEnumerator_free
#define base_UInt64ArrayEnumerator_init  base_System_UInt64ArrayEnumerator_init
#define base_UInt64ArrayEnumerator_free  base_System_UInt64ArrayEnumerator_free
#define UInt64ArrayEnumerator_init  System_UInt64ArrayEnumerator_init
#define UInt64ArrayEnumerator_free  System_UInt64ArrayEnumerator_free
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int8Array)
#include "System.Int8Array.h"
#endif
#if !defined(have_System_Int8ArrayEnumerator)
#define have_System_Int8ArrayEnumerator

typedef fixed struct System_Int8ArrayEnumerator {
    struct System_Object base;

    System_Int8Array array;

    System_Size index;

}  * System_Int8ArrayEnumerator;

#define stack_System_Int8ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_Int8ArrayEnumerator), .array = ARRAY, }
#define new_System_Int8ArrayEnumerator(ARRAY)  (base_System_Int8ArrayEnumerator_init((System_Int8ArrayEnumerator)System_Memory_allocClass(typeof(System_Int8ArrayEnumerator)), ARRAY))

export struct System_Type  System_Int8ArrayEnumeratorType;

typedef void delegate(System_Int8ArrayEnumerator_free)(System_Int8ArrayEnumerator that);
typedef System_Int8ArrayEnumerator delegate(System_Int8ArrayEnumerator_init)(System_Int8ArrayEnumerator that, System_Int8Array array);
typedef System_Int8 delegate(System_Int8ArrayEnumerator_get_current)(System_Int8ArrayEnumerator that);
typedef System_Bool delegate(System_Int8ArrayEnumerator_moveNext)(System_Int8ArrayEnumerator that);

export System_Int8ArrayEnumerator  base_System_Int8ArrayEnumerator_init(System_Int8ArrayEnumerator that, System_Int8Array array);
export void  base_System_Int8ArrayEnumerator_free(System_Int8ArrayEnumerator that);
export System_Int8  base_System_Int8ArrayEnumerator_get_current(System_Int8ArrayEnumerator that);
export System_Bool  base_System_Int8ArrayEnumerator_moveNext(System_Int8ArrayEnumerator that);

#define System_Int8ArrayEnumerator_init(o,...)  ((function_System_Int8ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int8ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_Int8ArrayEnumerator_free(o)  ((function_System_Int8ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int8ArrayEnumerator_get_current(o)  ((function_System_Int8ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_Int8ArrayEnumerator_moveNext(o)  ((function_System_Int8ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define Int8ArrayEnumerator  System_Int8ArrayEnumerator
#define Int8ArrayEnumeratorType  System_Int8ArrayEnumeratorType
#define stack_Int8ArrayEnumerator  stack_System_Int8ArrayEnumerator
#define new_Int8ArrayEnumerator  new_System_Int8ArrayEnumerator
#define function_Int8ArrayEnumerator_init  function_System_Int8ArrayEnumerator_init
#define function_Int8ArrayEnumerator_free  function_System_Int8ArrayEnumerator_free
#define base_Int8ArrayEnumerator_init  base_System_Int8ArrayEnumerator_init
#define base_Int8ArrayEnumerator_free  base_System_Int8ArrayEnumerator_free
#define Int8ArrayEnumerator_init  System_Int8ArrayEnumerator_init
#define Int8ArrayEnumerator_free  System_Int8ArrayEnumerator_free
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int16Array)
#include "System.Int16Array.h"
#endif
#if !defined(have_System_Int16ArrayEnumerator)
#define have_System_Int16ArrayEnumerator

typedef fixed struct System_Int16ArrayEnumerator {
    struct System_Object base;

    System_Int16Array array;

    System_Size index;

}  * System_Int16ArrayEnumerator;

#define stack_System_Int16ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_Int16ArrayEnumerator), .array = ARRAY, }
#define new_System_Int16ArrayEnumerator(ARRAY)  (base_System_Int16ArrayEnumerator_init((System_Int16ArrayEnumerator)System_Memory_allocClass(typeof(System_Int16ArrayEnumerator)), ARRAY))

export struct System_Type  System_Int16ArrayEnumeratorType;

typedef void delegate(System_Int16ArrayEnumerator_free)(System_Int16ArrayEnumerator that);
typedef System_Int16ArrayEnumerator delegate(System_Int16ArrayEnumerator_init)(System_Int16ArrayEnumerator that, System_Int16Array array);
typedef System_Int16 delegate(System_Int16ArrayEnumerator_get_current)(System_Int16ArrayEnumerator that);
typedef System_Bool delegate(System_Int16ArrayEnumerator_moveNext)(System_Int16ArrayEnumerator that);

export System_Int16ArrayEnumerator  base_System_Int16ArrayEnumerator_init(System_Int16ArrayEnumerator that, System_Int16Array array);
export void  base_System_Int16ArrayEnumerator_free(System_Int16ArrayEnumerator that);
export System_Int16  base_System_Int16ArrayEnumerator_get_current(System_Int16ArrayEnumerator that);
export System_Bool  base_System_Int16ArrayEnumerator_moveNext(System_Int16ArrayEnumerator that);

#define System_Int16ArrayEnumerator_init(o,...)  ((function_System_Int16ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int16ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_Int16ArrayEnumerator_free(o)  ((function_System_Int16ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int16ArrayEnumerator_get_current(o)  ((function_System_Int16ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_Int16ArrayEnumerator_moveNext(o)  ((function_System_Int16ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define Int16ArrayEnumerator  System_Int16ArrayEnumerator
#define Int16ArrayEnumeratorType  System_Int16ArrayEnumeratorType
#define stack_Int16ArrayEnumerator  stack_System_Int16ArrayEnumerator
#define new_Int16ArrayEnumerator  new_System_Int16ArrayEnumerator
#define function_Int16ArrayEnumerator_init  function_System_Int16ArrayEnumerator_init
#define function_Int16ArrayEnumerator_free  function_System_Int16ArrayEnumerator_free
#define base_Int16ArrayEnumerator_init  base_System_Int16ArrayEnumerator_init
#define base_Int16ArrayEnumerator_free  base_System_Int16ArrayEnumerator_free
#define Int16ArrayEnumerator_init  System_Int16ArrayEnumerator_init
#define Int16ArrayEnumerator_free  System_Int16ArrayEnumerator_free
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int32Array)
#include "System.Int32Array.h"
#endif
#if !defined(have_System_Int32ArrayEnumerator)
#define have_System_Int32ArrayEnumerator

typedef fixed struct System_Int32ArrayEnumerator {
    struct System_Object base;

    System_Int32Array array;

    System_Size index;

}  * System_Int32ArrayEnumerator;

#define stack_System_Int32ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_Int32ArrayEnumerator), .array = ARRAY, }
#define new_System_Int32ArrayEnumerator(ARRAY)  (base_System_Int32ArrayEnumerator_init((System_Int32ArrayEnumerator)System_Memory_allocClass(typeof(System_Int32ArrayEnumerator)), ARRAY))

export struct System_Type  System_Int32ArrayEnumeratorType;

typedef void delegate(System_Int32ArrayEnumerator_free)(System_Int32ArrayEnumerator that);
typedef System_Int32ArrayEnumerator delegate(System_Int32ArrayEnumerator_init)(System_Int32ArrayEnumerator that, System_Int32Array array);
typedef System_Int32 delegate(System_Int32ArrayEnumerator_get_current)(System_Int32ArrayEnumerator that);
typedef System_Bool delegate(System_Int32ArrayEnumerator_moveNext)(System_Int32ArrayEnumerator that);

export System_Int32ArrayEnumerator  base_System_Int32ArrayEnumerator_init(System_Int32ArrayEnumerator that, System_Int32Array array);
export void  base_System_Int32ArrayEnumerator_free(System_Int32ArrayEnumerator that);
export System_Int32  base_System_Int32ArrayEnumerator_get_current(System_Int32ArrayEnumerator that);
export System_Bool  base_System_Int32ArrayEnumerator_moveNext(System_Int32ArrayEnumerator that);

#define System_Int32ArrayEnumerator_init(o,...)  ((function_System_Int32ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int32ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_Int32ArrayEnumerator_free(o)  ((function_System_Int32ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int32ArrayEnumerator_get_current(o)  ((function_System_Int32ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_Int32ArrayEnumerator_moveNext(o)  ((function_System_Int32ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define Int32ArrayEnumerator  System_Int32ArrayEnumerator
#define Int32ArrayEnumeratorType  System_Int32ArrayEnumeratorType
#define stack_Int32ArrayEnumerator  stack_System_Int32ArrayEnumerator
#define new_Int32ArrayEnumerator  new_System_Int32ArrayEnumerator
#define function_Int32ArrayEnumerator_init  function_System_Int32ArrayEnumerator_init
#define function_Int32ArrayEnumerator_free  function_System_Int32ArrayEnumerator_free
#define base_Int32ArrayEnumerator_init  base_System_Int32ArrayEnumerator_init
#define base_Int32ArrayEnumerator_free  base_System_Int32ArrayEnumerator_free
#define Int32ArrayEnumerator_init  System_Int32ArrayEnumerator_init
#define Int32ArrayEnumerator_free  System_Int32ArrayEnumerator_free
#endif
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Int64Array)
#include "System.Int64Array.h"
#endif
#if !defined(have_System_Int64ArrayEnumerator)
#define have_System_Int64ArrayEnumerator

typedef fixed struct System_Int64ArrayEnumerator {
    struct System_Object base;

    System_Int64Array array;

    System_Size index;

}  * System_Int64ArrayEnumerator;

#define stack_System_Int64ArrayEnumerator(ARRAY)  { .base = stack_System_Object(System_Int64ArrayEnumerator), .array = ARRAY, }
#define new_System_Int64ArrayEnumerator(ARRAY)  (base_System_Int64ArrayEnumerator_init((System_Int64ArrayEnumerator)System_Memory_allocClass(typeof(System_Int64ArrayEnumerator)), ARRAY))

export struct System_Type  System_Int64ArrayEnumeratorType;

typedef void delegate(System_Int64ArrayEnumerator_free)(System_Int64ArrayEnumerator that);
typedef System_Int64ArrayEnumerator delegate(System_Int64ArrayEnumerator_init)(System_Int64ArrayEnumerator that, System_Int64Array array);
typedef System_Int64 delegate(System_Int64ArrayEnumerator_get_current)(System_Int64ArrayEnumerator that);
typedef System_Bool delegate(System_Int64ArrayEnumerator_moveNext)(System_Int64ArrayEnumerator that);

export System_Int64ArrayEnumerator  base_System_Int64ArrayEnumerator_init(System_Int64ArrayEnumerator that, System_Int64Array array);
export void  base_System_Int64ArrayEnumerator_free(System_Int64ArrayEnumerator that);
export System_Int64  base_System_Int64ArrayEnumerator_get_current(System_Int64ArrayEnumerator that);
export System_Bool  base_System_Int64ArrayEnumerator_moveNext(System_Int64ArrayEnumerator that);

#define System_Int64ArrayEnumerator_init(o,...)  ((function_System_Int64ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Int64ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_Int64ArrayEnumerator_free(o)  ((function_System_Int64ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_Int64ArrayEnumerator_get_current(o)  ((function_System_Int64ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_Int64ArrayEnumerator_moveNext(o)  ((function_System_Int64ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#if defined(using_System)
#define Int64ArrayEnumerator  System_Int64ArrayEnumerator
#define Int64ArrayEnumeratorType  System_Int64ArrayEnumeratorType
#define stack_Int64ArrayEnumerator  stack_System_Int64ArrayEnumerator
#define new_Int64ArrayEnumerator  new_System_Int64ArrayEnumerator
#define function_Int64ArrayEnumerator_init  function_System_Int64ArrayEnumerator_init
#define function_Int64ArrayEnumerator_free  function_System_Int64ArrayEnumerator_free
#define base_Int64ArrayEnumerator_init  base_System_Int64ArrayEnumerator_init
#define base_Int64ArrayEnumerator_free  base_System_Int64ArrayEnumerator_free
#define Int64ArrayEnumerator_init  System_Int64ArrayEnumerator_init
#define Int64ArrayEnumerator_free  System_Int64ArrayEnumerator_free
#endif
#endif
