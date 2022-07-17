/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint8)
#warning "System.uint8.h not included"
#include "System.uint8.h"
#endif */
#if !defined(have_auto_System_uint8Array)
#define have_auto_System_uint8Array

#define struct_System_uint8Array  struct System_uint8Array
typedef fixed struct_System_uint8Array {
    struct_System_Object base;

    System_size  length;

    System_uint8  (* value)[];

}  * System_uint8Array;

#define stack_System_uint8Array(LENGTH,...)  (struct_System_uint8Array){ .base = { .base = stack_System_Object(System_uint8Array), .length = LENGTH, .value = &(System_uint8 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_uint8ArrayType;

typedef void delegate(System_uint8Array_free)(System_uint8Array that);
typedef System_uint8Array delegate(System_uint8Array_init)(System_uint8Array that);
typedef System_size  delegate(System_uint8Array_get_Length)(System_uint8Array that);
typedef System_uint8  delegate(System_uint8Array_get_index)(System_uint8Array that, System_size index);
typedef void  delegate(System_uint8Array_set_index)(System_uint8Array that, System_size index, System_uint8 value);
typedef void delegate(System_uint8Array_copyTo)(System_uint8Array that, System_uint8Array other, System_size offset);
typedef void delegate(System_uint8Array_resize)(System_uint8Array that, System_size length);
typedef System_IEnumerator  delegate(System_uint8Array_getEnumerator)(System_uint8Array that);

#define System_uint8Array_new  System_uint8Array_new__01

export System_uint8Array  System_uint8Array_new(System_size length);
export System_uint8Array  base_System_uint8Array_init(System_uint8Array that, System_size length);
export void  base_System_uint8Array_free(System_uint8Array that);
export System_size  base_System_uint8Array_get_Length(System_uint8Array that);
export System_uint8  base_System_uint8Array_get_index(System_uint8Array that, System_size index);
export void  base_System_uint8Array_set_index(System_uint8Array that, System_size index, System_uint8 value);
export void  base_System_uint8Array_copyTo(System_uint8Array that, System_uint8Array other, System_size offset);
export void  base_System_uint8Array_resize(System_uint8Array that, System_size length);
export System_IEnumerator  base_System_uint8Array_getEnumerator(System_uint8Array that);

#define System_uint8Array_init(o,...)  ((function_System_uint8Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint8Array_init))(o, __VA_ARGS__)
#define System_uint8Array_free(o)  ((function_System_uint8Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint8Array_get_Length(o)  ((function_System_uint8Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_uint8Array_get_index(o,...)  ((function_System_uint8Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_uint8Array_set_index(o,...)  ((function_System_uint8Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_uint8Array_copyTo(o,...)  ((function_System_uint8Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_uint8Array_resize(o,...)  ((function_System_uint8Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint8Array_resize))(o,__VA_ARGS__)
#define System_uint8Array_getEnumerator(o)  ((function_System_uint8Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_uint8Array_new(LENGTH)  (base_System_uint8Array_init(inline_System_Object_allocClass(System_uint8Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_uint8Array_new
#define System_uint8Array_new  inline_System_uint8Array_new
#endif

#if defined(using_System)
#define struct_uint8Array  struct System_uint8Array
#define stack_uint8Array  stack_System_uint8Array
#define uint8Array  System_uint8Array
#define uint8ArrayType  System_uint8ArrayType

#define uint8Array_new  System_uint8Array_new

#define uint8Array_init  System_uint8Array_init
#define uint8Array_free  System_uint8Array_free
#define uint8Array_get_Length  System_uint8Array_get_Length
#define uint8Array_get_index  System_uint8Array_get_index
#define uint8Array_set_index  System_uint8Array_set_index
#define uint8Array_resize  System_uint8Array_resize
#define base_uint8Array_init  base_System_uint8Array_init
#define base_uint8Array_free  base_System_uint8Array_free
#define base_uint8Array_get_Length  base_System_uint8Array_get_Length
#define base_uint8Array_get_index  base_System_uint8Array_get_index
#define base_uint8Array_set_index  base_System_uint8Array_set_index
#define base_uint8Array_resize  base_System_uint8Array_resize
#define base_uint8Array_getEnumerator  base_System_uint8Array_getEnumerator
#define function_uint8Array_init  function_System_uint8Array_init
#define function_uint8Array_free  function_System_uint8Array_free
#define function_uint8Array_get_Length  function_System_uint8Array_get_Length
#define function_uint8Array_get_index  function_System_uint8Array_get_index
#define function_uint8Array_set_index  function_System_uint8Array_set_index
#define function_uint8Array_resize  function_System_uint8Array_resize
#define function_uint8Array_getEnumerator  function_System_uint8Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint8)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_uint8ArrayEnumerator)
#define have_auto_System_uint8ArrayEnumerator

#define struct_System_uint8ArrayEnumerator  struct System_uint8ArrayEnumerator
typedef fixed struct_System_uint8ArrayEnumerator {
    struct_System_Object base;

    System_uint8Array array;

    System_size index;

}  * System_uint8ArrayEnumerator;

#define stack_System_uint8ArrayEnumerator()  (struct_System_uint8ArrayEnumerator){ .base = stack_System_Object(System_uint8ArrayEnumerator), .array = null, }

export struct_System_Type  System_uint8ArrayEnumeratorType;

typedef void delegate(System_uint8ArrayEnumerator_free)(System_uint8ArrayEnumerator that);
typedef System_uint8ArrayEnumerator delegate(System_uint8ArrayEnumerator_init)(System_uint8ArrayEnumerator that, System_uint8Array array);
typedef System_uint8 delegate(System_uint8ArrayEnumerator_get_current)(System_uint8ArrayEnumerator that);
typedef System_boolean delegate(System_uint8ArrayEnumerator_moveNext)(System_uint8ArrayEnumerator that);

#define System_uint8ArrayEnumerator_new  System_uint8ArrayEnumerator_new__00

export System_uint8ArrayEnumerator  System_uint8ArrayEnumerator_new(System_uint8Array array);
export System_uint8ArrayEnumerator  base_System_uint8ArrayEnumerator_init(System_uint8ArrayEnumerator that, System_uint8Array array);
export void  base_System_uint8ArrayEnumerator_free(System_uint8ArrayEnumerator that);
export System_uint8  base_System_uint8ArrayEnumerator_get_current(System_uint8ArrayEnumerator that);
export System_boolean  base_System_uint8ArrayEnumerator_moveNext(System_uint8ArrayEnumerator that);

#define System_uint8ArrayEnumerator_init(o,...)  ((function_System_uint8ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint8ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_uint8ArrayEnumerator_free(o)  ((function_System_uint8ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint8ArrayEnumerator_get_current(o)  ((function_System_uint8ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_uint8ArrayEnumerator_moveNext(o)  ((function_System_uint8ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_uint8ArrayEnumerator_new(a)  (base_System_uint8ArrayEnumerator_init(inline_System_Object_allocClass(System_uint8ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_uint8ArrayEnumerator_new
#define System_uint8ArrayEnumerator_new  inline_System_uint8ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_uint8ArrayEnumerator  struct_System_uint8ArrayEnumerator
#define uint8ArrayEnumerator  System_uint8ArrayEnumerator
#define uint8ArrayEnumeratorType  System_uint8ArrayEnumeratorType
#define function_uint8ArrayEnumerator_init  function_System_uint8ArrayEnumerator_init
#define function_uint8ArrayEnumerator_free  function_System_uint8ArrayEnumerator_free
#define base_uint8ArrayEnumerator_init  base_System_uint8ArrayEnumerator_init
#define base_uint8ArrayEnumerator_free  base_System_uint8ArrayEnumerator_free
#define uint8ArrayEnumerator_new  System_uint8ArrayEnumerator_new
#define uint8ArrayEnumerator_init  System_uint8ArrayEnumerator_init
#define uint8ArrayEnumerator_free  System_uint8ArrayEnumerator_free
#endif


#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint16)
#warning "System.uint16.h not included"
#include "System.uint16.h"
#endif */
#if !defined(have_auto_System_uint16Array)
#define have_auto_System_uint16Array

#define struct_System_uint16Array  struct System_uint16Array
typedef fixed struct_System_uint16Array {
    struct_System_Object base;

    System_size  length;

    System_uint16  (* value)[];

}  * System_uint16Array;

#define stack_System_uint16Array(LENGTH,...)  (struct_System_uint16Array){ .base = { .base = stack_System_Object(System_uint16Array), .length = LENGTH, .value = &(System_uint16 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_uint16ArrayType;

typedef void delegate(System_uint16Array_free)(System_uint16Array that);
typedef System_uint16Array delegate(System_uint16Array_init)(System_uint16Array that);
typedef System_size  delegate(System_uint16Array_get_Length)(System_uint16Array that);
typedef System_uint16  delegate(System_uint16Array_get_index)(System_uint16Array that, System_size index);
typedef void  delegate(System_uint16Array_set_index)(System_uint16Array that, System_size index, System_uint16 value);
typedef void delegate(System_uint16Array_copyTo)(System_uint16Array that, System_uint16Array other, System_size offset);
typedef void delegate(System_uint16Array_resize)(System_uint16Array that, System_size length);
typedef System_IEnumerator  delegate(System_uint16Array_getEnumerator)(System_uint16Array that);

#define System_uint16Array_new  System_uint16Array_new__01

export System_uint16Array  System_uint16Array_new(System_size length);
export System_uint16Array  base_System_uint16Array_init(System_uint16Array that, System_size length);
export void  base_System_uint16Array_free(System_uint16Array that);
export System_size  base_System_uint16Array_get_Length(System_uint16Array that);
export System_uint16  base_System_uint16Array_get_index(System_uint16Array that, System_size index);
export void  base_System_uint16Array_set_index(System_uint16Array that, System_size index, System_uint16 value);
export void  base_System_uint16Array_copyTo(System_uint16Array that, System_uint16Array other, System_size offset);
export void  base_System_uint16Array_resize(System_uint16Array that, System_size length);
export System_IEnumerator  base_System_uint16Array_getEnumerator(System_uint16Array that);

#define System_uint16Array_init(o,...)  ((function_System_uint16Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint16Array_init))(o, __VA_ARGS__)
#define System_uint16Array_free(o)  ((function_System_uint16Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint16Array_get_Length(o)  ((function_System_uint16Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_uint16Array_get_index(o,...)  ((function_System_uint16Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_uint16Array_set_index(o,...)  ((function_System_uint16Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_uint16Array_copyTo(o,...)  ((function_System_uint16Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_uint16Array_resize(o,...)  ((function_System_uint16Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint16Array_resize))(o,__VA_ARGS__)
#define System_uint16Array_getEnumerator(o)  ((function_System_uint16Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_uint16Array_new(LENGTH)  (base_System_uint16Array_init(inline_System_Object_allocClass(System_uint16Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_uint16Array_new
#define System_uint16Array_new  inline_System_uint16Array_new
#endif

#if defined(using_System)
#define struct_uint16Array  struct System_uint16Array
#define stack_uint16Array  stack_System_uint16Array
#define uint16Array  System_uint16Array
#define uint16ArrayType  System_uint16ArrayType

#define uint16Array_new  System_uint16Array_new

#define uint16Array_init  System_uint16Array_init
#define uint16Array_free  System_uint16Array_free
#define uint16Array_get_Length  System_uint16Array_get_Length
#define uint16Array_get_index  System_uint16Array_get_index
#define uint16Array_set_index  System_uint16Array_set_index
#define uint16Array_resize  System_uint16Array_resize
#define base_uint16Array_init  base_System_uint16Array_init
#define base_uint16Array_free  base_System_uint16Array_free
#define base_uint16Array_get_Length  base_System_uint16Array_get_Length
#define base_uint16Array_get_index  base_System_uint16Array_get_index
#define base_uint16Array_set_index  base_System_uint16Array_set_index
#define base_uint16Array_resize  base_System_uint16Array_resize
#define base_uint16Array_getEnumerator  base_System_uint16Array_getEnumerator
#define function_uint16Array_init  function_System_uint16Array_init
#define function_uint16Array_free  function_System_uint16Array_free
#define function_uint16Array_get_Length  function_System_uint16Array_get_Length
#define function_uint16Array_get_index  function_System_uint16Array_get_index
#define function_uint16Array_set_index  function_System_uint16Array_set_index
#define function_uint16Array_resize  function_System_uint16Array_resize
#define function_uint16Array_getEnumerator  function_System_uint16Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint16)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_uint16ArrayEnumerator)
#define have_auto_System_uint16ArrayEnumerator

#define struct_System_uint16ArrayEnumerator  struct System_uint16ArrayEnumerator
typedef fixed struct_System_uint16ArrayEnumerator {
    struct_System_Object base;

    System_uint16Array array;

    System_size index;

}  * System_uint16ArrayEnumerator;

#define stack_System_uint16ArrayEnumerator()  (struct_System_uint16ArrayEnumerator){ .base = stack_System_Object(System_uint16ArrayEnumerator), .array = null, }

export struct_System_Type  System_uint16ArrayEnumeratorType;

typedef void delegate(System_uint16ArrayEnumerator_free)(System_uint16ArrayEnumerator that);
typedef System_uint16ArrayEnumerator delegate(System_uint16ArrayEnumerator_init)(System_uint16ArrayEnumerator that, System_uint16Array array);
typedef System_uint16 delegate(System_uint16ArrayEnumerator_get_current)(System_uint16ArrayEnumerator that);
typedef System_boolean delegate(System_uint16ArrayEnumerator_moveNext)(System_uint16ArrayEnumerator that);

#define System_uint16ArrayEnumerator_new  System_uint16ArrayEnumerator_new__00

export System_uint16ArrayEnumerator  System_uint16ArrayEnumerator_new(System_uint16Array array);
export System_uint16ArrayEnumerator  base_System_uint16ArrayEnumerator_init(System_uint16ArrayEnumerator that, System_uint16Array array);
export void  base_System_uint16ArrayEnumerator_free(System_uint16ArrayEnumerator that);
export System_uint16  base_System_uint16ArrayEnumerator_get_current(System_uint16ArrayEnumerator that);
export System_boolean  base_System_uint16ArrayEnumerator_moveNext(System_uint16ArrayEnumerator that);

#define System_uint16ArrayEnumerator_init(o,...)  ((function_System_uint16ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint16ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_uint16ArrayEnumerator_free(o)  ((function_System_uint16ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint16ArrayEnumerator_get_current(o)  ((function_System_uint16ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_uint16ArrayEnumerator_moveNext(o)  ((function_System_uint16ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_uint16ArrayEnumerator_new(a)  (base_System_uint16ArrayEnumerator_init(inline_System_Object_allocClass(System_uint16ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_uint16ArrayEnumerator_new
#define System_uint16ArrayEnumerator_new  inline_System_uint16ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_uint16ArrayEnumerator  struct_System_uint16ArrayEnumerator
#define uint16ArrayEnumerator  System_uint16ArrayEnumerator
#define uint16ArrayEnumeratorType  System_uint16ArrayEnumeratorType
#define function_uint16ArrayEnumerator_init  function_System_uint16ArrayEnumerator_init
#define function_uint16ArrayEnumerator_free  function_System_uint16ArrayEnumerator_free
#define base_uint16ArrayEnumerator_init  base_System_uint16ArrayEnumerator_init
#define base_uint16ArrayEnumerator_free  base_System_uint16ArrayEnumerator_free
#define uint16ArrayEnumerator_new  System_uint16ArrayEnumerator_new
#define uint16ArrayEnumerator_init  System_uint16ArrayEnumerator_init
#define uint16ArrayEnumerator_free  System_uint16ArrayEnumerator_free
#endif


#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint32)
#warning "System.uint32.h not included"
#include "System.uint32.h"
#endif */
#if !defined(have_auto_System_uint32Array)
#define have_auto_System_uint32Array

#define struct_System_uint32Array  struct System_uint32Array
typedef fixed struct_System_uint32Array {
    struct_System_Object base;

    System_size  length;

    System_uint32  (* value)[];

}  * System_uint32Array;

#define stack_System_uint32Array(LENGTH,...)  (struct_System_uint32Array){ .base = { .base = stack_System_Object(System_uint32Array), .length = LENGTH, .value = &(System_uint32 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_uint32ArrayType;

typedef void delegate(System_uint32Array_free)(System_uint32Array that);
typedef System_uint32Array delegate(System_uint32Array_init)(System_uint32Array that);
typedef System_size  delegate(System_uint32Array_get_Length)(System_uint32Array that);
typedef System_uint32  delegate(System_uint32Array_get_index)(System_uint32Array that, System_size index);
typedef void  delegate(System_uint32Array_set_index)(System_uint32Array that, System_size index, System_uint32 value);
typedef void delegate(System_uint32Array_copyTo)(System_uint32Array that, System_uint32Array other, System_size offset);
typedef void delegate(System_uint32Array_resize)(System_uint32Array that, System_size length);
typedef System_IEnumerator  delegate(System_uint32Array_getEnumerator)(System_uint32Array that);

#define System_uint32Array_new  System_uint32Array_new__01

export System_uint32Array  System_uint32Array_new(System_size length);
export System_uint32Array  base_System_uint32Array_init(System_uint32Array that, System_size length);
export void  base_System_uint32Array_free(System_uint32Array that);
export System_size  base_System_uint32Array_get_Length(System_uint32Array that);
export System_uint32  base_System_uint32Array_get_index(System_uint32Array that, System_size index);
export void  base_System_uint32Array_set_index(System_uint32Array that, System_size index, System_uint32 value);
export void  base_System_uint32Array_copyTo(System_uint32Array that, System_uint32Array other, System_size offset);
export void  base_System_uint32Array_resize(System_uint32Array that, System_size length);
export System_IEnumerator  base_System_uint32Array_getEnumerator(System_uint32Array that);

#define System_uint32Array_init(o,...)  ((function_System_uint32Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint32Array_init))(o, __VA_ARGS__)
#define System_uint32Array_free(o)  ((function_System_uint32Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint32Array_get_Length(o)  ((function_System_uint32Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_uint32Array_get_index(o,...)  ((function_System_uint32Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_uint32Array_set_index(o,...)  ((function_System_uint32Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_uint32Array_copyTo(o,...)  ((function_System_uint32Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_uint32Array_resize(o,...)  ((function_System_uint32Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint32Array_resize))(o,__VA_ARGS__)
#define System_uint32Array_getEnumerator(o)  ((function_System_uint32Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_uint32Array_new(LENGTH)  (base_System_uint32Array_init(inline_System_Object_allocClass(System_uint32Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_uint32Array_new
#define System_uint32Array_new  inline_System_uint32Array_new
#endif

#if defined(using_System)
#define struct_uint32Array  struct System_uint32Array
#define stack_uint32Array  stack_System_uint32Array
#define uint32Array  System_uint32Array
#define uint32ArrayType  System_uint32ArrayType

#define uint32Array_new  System_uint32Array_new

#define uint32Array_init  System_uint32Array_init
#define uint32Array_free  System_uint32Array_free
#define uint32Array_get_Length  System_uint32Array_get_Length
#define uint32Array_get_index  System_uint32Array_get_index
#define uint32Array_set_index  System_uint32Array_set_index
#define uint32Array_resize  System_uint32Array_resize
#define base_uint32Array_init  base_System_uint32Array_init
#define base_uint32Array_free  base_System_uint32Array_free
#define base_uint32Array_get_Length  base_System_uint32Array_get_Length
#define base_uint32Array_get_index  base_System_uint32Array_get_index
#define base_uint32Array_set_index  base_System_uint32Array_set_index
#define base_uint32Array_resize  base_System_uint32Array_resize
#define base_uint32Array_getEnumerator  base_System_uint32Array_getEnumerator
#define function_uint32Array_init  function_System_uint32Array_init
#define function_uint32Array_free  function_System_uint32Array_free
#define function_uint32Array_get_Length  function_System_uint32Array_get_Length
#define function_uint32Array_get_index  function_System_uint32Array_get_index
#define function_uint32Array_set_index  function_System_uint32Array_set_index
#define function_uint32Array_resize  function_System_uint32Array_resize
#define function_uint32Array_getEnumerator  function_System_uint32Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint32)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_uint32ArrayEnumerator)
#define have_auto_System_uint32ArrayEnumerator

#define struct_System_uint32ArrayEnumerator  struct System_uint32ArrayEnumerator
typedef fixed struct_System_uint32ArrayEnumerator {
    struct_System_Object base;

    System_uint32Array array;

    System_size index;

}  * System_uint32ArrayEnumerator;

#define stack_System_uint32ArrayEnumerator()  (struct_System_uint32ArrayEnumerator){ .base = stack_System_Object(System_uint32ArrayEnumerator), .array = null, }

export struct_System_Type  System_uint32ArrayEnumeratorType;

typedef void delegate(System_uint32ArrayEnumerator_free)(System_uint32ArrayEnumerator that);
typedef System_uint32ArrayEnumerator delegate(System_uint32ArrayEnumerator_init)(System_uint32ArrayEnumerator that, System_uint32Array array);
typedef System_uint32 delegate(System_uint32ArrayEnumerator_get_current)(System_uint32ArrayEnumerator that);
typedef System_boolean delegate(System_uint32ArrayEnumerator_moveNext)(System_uint32ArrayEnumerator that);

#define System_uint32ArrayEnumerator_new  System_uint32ArrayEnumerator_new__00

export System_uint32ArrayEnumerator  System_uint32ArrayEnumerator_new(System_uint32Array array);
export System_uint32ArrayEnumerator  base_System_uint32ArrayEnumerator_init(System_uint32ArrayEnumerator that, System_uint32Array array);
export void  base_System_uint32ArrayEnumerator_free(System_uint32ArrayEnumerator that);
export System_uint32  base_System_uint32ArrayEnumerator_get_current(System_uint32ArrayEnumerator that);
export System_boolean  base_System_uint32ArrayEnumerator_moveNext(System_uint32ArrayEnumerator that);

#define System_uint32ArrayEnumerator_init(o,...)  ((function_System_uint32ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint32ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_uint32ArrayEnumerator_free(o)  ((function_System_uint32ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint32ArrayEnumerator_get_current(o)  ((function_System_uint32ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_uint32ArrayEnumerator_moveNext(o)  ((function_System_uint32ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_uint32ArrayEnumerator_new(a)  (base_System_uint32ArrayEnumerator_init(inline_System_Object_allocClass(System_uint32ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_uint32ArrayEnumerator_new
#define System_uint32ArrayEnumerator_new  inline_System_uint32ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_uint32ArrayEnumerator  struct_System_uint32ArrayEnumerator
#define uint32ArrayEnumerator  System_uint32ArrayEnumerator
#define uint32ArrayEnumeratorType  System_uint32ArrayEnumeratorType
#define function_uint32ArrayEnumerator_init  function_System_uint32ArrayEnumerator_init
#define function_uint32ArrayEnumerator_free  function_System_uint32ArrayEnumerator_free
#define base_uint32ArrayEnumerator_init  base_System_uint32ArrayEnumerator_init
#define base_uint32ArrayEnumerator_free  base_System_uint32ArrayEnumerator_free
#define uint32ArrayEnumerator_new  System_uint32ArrayEnumerator_new
#define uint32ArrayEnumerator_init  System_uint32ArrayEnumerator_init
#define uint32ArrayEnumerator_free  System_uint32ArrayEnumerator_free
#endif


#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint64)
#warning "System.uint64.h not included"
#include "System.uint64.h"
#endif */
#if !defined(have_auto_System_uint64Array)
#define have_auto_System_uint64Array

#define struct_System_uint64Array  struct System_uint64Array
typedef fixed struct_System_uint64Array {
    struct_System_Object base;

    System_size  length;

    System_uint64  (* value)[];

}  * System_uint64Array;

#define stack_System_uint64Array(LENGTH,...)  (struct_System_uint64Array){ .base = { .base = stack_System_Object(System_uint64Array), .length = LENGTH, .value = &(System_uint64 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_uint64ArrayType;

typedef void delegate(System_uint64Array_free)(System_uint64Array that);
typedef System_uint64Array delegate(System_uint64Array_init)(System_uint64Array that);
typedef System_size  delegate(System_uint64Array_get_Length)(System_uint64Array that);
typedef System_uint64  delegate(System_uint64Array_get_index)(System_uint64Array that, System_size index);
typedef void  delegate(System_uint64Array_set_index)(System_uint64Array that, System_size index, System_uint64 value);
typedef void delegate(System_uint64Array_copyTo)(System_uint64Array that, System_uint64Array other, System_size offset);
typedef void delegate(System_uint64Array_resize)(System_uint64Array that, System_size length);
typedef System_IEnumerator  delegate(System_uint64Array_getEnumerator)(System_uint64Array that);

#define System_uint64Array_new  System_uint64Array_new__01

export System_uint64Array  System_uint64Array_new(System_size length);
export System_uint64Array  base_System_uint64Array_init(System_uint64Array that, System_size length);
export void  base_System_uint64Array_free(System_uint64Array that);
export System_size  base_System_uint64Array_get_Length(System_uint64Array that);
export System_uint64  base_System_uint64Array_get_index(System_uint64Array that, System_size index);
export void  base_System_uint64Array_set_index(System_uint64Array that, System_size index, System_uint64 value);
export void  base_System_uint64Array_copyTo(System_uint64Array that, System_uint64Array other, System_size offset);
export void  base_System_uint64Array_resize(System_uint64Array that, System_size length);
export System_IEnumerator  base_System_uint64Array_getEnumerator(System_uint64Array that);

#define System_uint64Array_init(o,...)  ((function_System_uint64Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint64Array_init))(o, __VA_ARGS__)
#define System_uint64Array_free(o)  ((function_System_uint64Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint64Array_get_Length(o)  ((function_System_uint64Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_uint64Array_get_index(o,...)  ((function_System_uint64Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_uint64Array_set_index(o,...)  ((function_System_uint64Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_uint64Array_copyTo(o,...)  ((function_System_uint64Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_uint64Array_resize(o,...)  ((function_System_uint64Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint64Array_resize))(o,__VA_ARGS__)
#define System_uint64Array_getEnumerator(o)  ((function_System_uint64Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_uint64Array_new(LENGTH)  (base_System_uint64Array_init(inline_System_Object_allocClass(System_uint64Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_uint64Array_new
#define System_uint64Array_new  inline_System_uint64Array_new
#endif

#if defined(using_System)
#define struct_uint64Array  struct System_uint64Array
#define stack_uint64Array  stack_System_uint64Array
#define uint64Array  System_uint64Array
#define uint64ArrayType  System_uint64ArrayType

#define uint64Array_new  System_uint64Array_new

#define uint64Array_init  System_uint64Array_init
#define uint64Array_free  System_uint64Array_free
#define uint64Array_get_Length  System_uint64Array_get_Length
#define uint64Array_get_index  System_uint64Array_get_index
#define uint64Array_set_index  System_uint64Array_set_index
#define uint64Array_resize  System_uint64Array_resize
#define base_uint64Array_init  base_System_uint64Array_init
#define base_uint64Array_free  base_System_uint64Array_free
#define base_uint64Array_get_Length  base_System_uint64Array_get_Length
#define base_uint64Array_get_index  base_System_uint64Array_get_index
#define base_uint64Array_set_index  base_System_uint64Array_set_index
#define base_uint64Array_resize  base_System_uint64Array_resize
#define base_uint64Array_getEnumerator  base_System_uint64Array_getEnumerator
#define function_uint64Array_init  function_System_uint64Array_init
#define function_uint64Array_free  function_System_uint64Array_free
#define function_uint64Array_get_Length  function_System_uint64Array_get_Length
#define function_uint64Array_get_index  function_System_uint64Array_get_index
#define function_uint64Array_set_index  function_System_uint64Array_set_index
#define function_uint64Array_resize  function_System_uint64Array_resize
#define function_uint64Array_getEnumerator  function_System_uint64Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_uint64)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_uint64ArrayEnumerator)
#define have_auto_System_uint64ArrayEnumerator

#define struct_System_uint64ArrayEnumerator  struct System_uint64ArrayEnumerator
typedef fixed struct_System_uint64ArrayEnumerator {
    struct_System_Object base;

    System_uint64Array array;

    System_size index;

}  * System_uint64ArrayEnumerator;

#define stack_System_uint64ArrayEnumerator()  (struct_System_uint64ArrayEnumerator){ .base = stack_System_Object(System_uint64ArrayEnumerator), .array = null, }

export struct_System_Type  System_uint64ArrayEnumeratorType;

typedef void delegate(System_uint64ArrayEnumerator_free)(System_uint64ArrayEnumerator that);
typedef System_uint64ArrayEnumerator delegate(System_uint64ArrayEnumerator_init)(System_uint64ArrayEnumerator that, System_uint64Array array);
typedef System_uint64 delegate(System_uint64ArrayEnumerator_get_current)(System_uint64ArrayEnumerator that);
typedef System_boolean delegate(System_uint64ArrayEnumerator_moveNext)(System_uint64ArrayEnumerator that);

#define System_uint64ArrayEnumerator_new  System_uint64ArrayEnumerator_new__00

export System_uint64ArrayEnumerator  System_uint64ArrayEnumerator_new(System_uint64Array array);
export System_uint64ArrayEnumerator  base_System_uint64ArrayEnumerator_init(System_uint64ArrayEnumerator that, System_uint64Array array);
export void  base_System_uint64ArrayEnumerator_free(System_uint64ArrayEnumerator that);
export System_uint64  base_System_uint64ArrayEnumerator_get_current(System_uint64ArrayEnumerator that);
export System_boolean  base_System_uint64ArrayEnumerator_moveNext(System_uint64ArrayEnumerator that);

#define System_uint64ArrayEnumerator_init(o,...)  ((function_System_uint64ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_uint64ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_uint64ArrayEnumerator_free(o)  ((function_System_uint64ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_uint64ArrayEnumerator_get_current(o)  ((function_System_uint64ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_uint64ArrayEnumerator_moveNext(o)  ((function_System_uint64ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_uint64ArrayEnumerator_new(a)  (base_System_uint64ArrayEnumerator_init(inline_System_Object_allocClass(System_uint64ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_uint64ArrayEnumerator_new
#define System_uint64ArrayEnumerator_new  inline_System_uint64ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_uint64ArrayEnumerator  struct_System_uint64ArrayEnumerator
#define uint64ArrayEnumerator  System_uint64ArrayEnumerator
#define uint64ArrayEnumeratorType  System_uint64ArrayEnumeratorType
#define function_uint64ArrayEnumerator_init  function_System_uint64ArrayEnumerator_init
#define function_uint64ArrayEnumerator_free  function_System_uint64ArrayEnumerator_free
#define base_uint64ArrayEnumerator_init  base_System_uint64ArrayEnumerator_init
#define base_uint64ArrayEnumerator_free  base_System_uint64ArrayEnumerator_free
#define uint64ArrayEnumerator_new  System_uint64ArrayEnumerator_new
#define uint64ArrayEnumerator_init  System_uint64ArrayEnumerator_init
#define uint64ArrayEnumerator_free  System_uint64ArrayEnumerator_free
#endif


#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int8)
#warning "System.int8.h not included"
#include "System.int8.h"
#endif */
#if !defined(have_auto_System_int8Array)
#define have_auto_System_int8Array

#define struct_System_int8Array  struct System_int8Array
typedef fixed struct_System_int8Array {
    struct_System_Object base;

    System_size  length;

    System_int8  (* value)[];

}  * System_int8Array;

#define stack_System_int8Array(LENGTH,...)  (struct_System_int8Array){ .base = { .base = stack_System_Object(System_int8Array), .length = LENGTH, .value = &(System_int8 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_int8ArrayType;

typedef void delegate(System_int8Array_free)(System_int8Array that);
typedef System_int8Array delegate(System_int8Array_init)(System_int8Array that);
typedef System_size  delegate(System_int8Array_get_Length)(System_int8Array that);
typedef System_int8  delegate(System_int8Array_get_index)(System_int8Array that, System_size index);
typedef void  delegate(System_int8Array_set_index)(System_int8Array that, System_size index, System_int8 value);
typedef void delegate(System_int8Array_copyTo)(System_int8Array that, System_int8Array other, System_size offset);
typedef void delegate(System_int8Array_resize)(System_int8Array that, System_size length);
typedef System_IEnumerator  delegate(System_int8Array_getEnumerator)(System_int8Array that);

#define System_int8Array_new  System_int8Array_new__01

export System_int8Array  System_int8Array_new(System_size length);
export System_int8Array  base_System_int8Array_init(System_int8Array that, System_size length);
export void  base_System_int8Array_free(System_int8Array that);
export System_size  base_System_int8Array_get_Length(System_int8Array that);
export System_int8  base_System_int8Array_get_index(System_int8Array that, System_size index);
export void  base_System_int8Array_set_index(System_int8Array that, System_size index, System_int8 value);
export void  base_System_int8Array_copyTo(System_int8Array that, System_int8Array other, System_size offset);
export void  base_System_int8Array_resize(System_int8Array that, System_size length);
export System_IEnumerator  base_System_int8Array_getEnumerator(System_int8Array that);

#define System_int8Array_init(o,...)  ((function_System_int8Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int8Array_init))(o, __VA_ARGS__)
#define System_int8Array_free(o)  ((function_System_int8Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int8Array_get_Length(o)  ((function_System_int8Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_int8Array_get_index(o,...)  ((function_System_int8Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_int8Array_set_index(o,...)  ((function_System_int8Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_int8Array_copyTo(o,...)  ((function_System_int8Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_int8Array_resize(o,...)  ((function_System_int8Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int8Array_resize))(o,__VA_ARGS__)
#define System_int8Array_getEnumerator(o)  ((function_System_int8Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_int8Array_new(LENGTH)  (base_System_int8Array_init(inline_System_Object_allocClass(System_int8Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_int8Array_new
#define System_int8Array_new  inline_System_int8Array_new
#endif

#if defined(using_System)
#define struct_int8Array  struct System_int8Array
#define stack_int8Array  stack_System_int8Array
#define int8Array  System_int8Array
#define int8ArrayType  System_int8ArrayType

#define int8Array_new  System_int8Array_new

#define int8Array_init  System_int8Array_init
#define int8Array_free  System_int8Array_free
#define int8Array_get_Length  System_int8Array_get_Length
#define int8Array_get_index  System_int8Array_get_index
#define int8Array_set_index  System_int8Array_set_index
#define int8Array_resize  System_int8Array_resize
#define base_int8Array_init  base_System_int8Array_init
#define base_int8Array_free  base_System_int8Array_free
#define base_int8Array_get_Length  base_System_int8Array_get_Length
#define base_int8Array_get_index  base_System_int8Array_get_index
#define base_int8Array_set_index  base_System_int8Array_set_index
#define base_int8Array_resize  base_System_int8Array_resize
#define base_int8Array_getEnumerator  base_System_int8Array_getEnumerator
#define function_int8Array_init  function_System_int8Array_init
#define function_int8Array_free  function_System_int8Array_free
#define function_int8Array_get_Length  function_System_int8Array_get_Length
#define function_int8Array_get_index  function_System_int8Array_get_index
#define function_int8Array_set_index  function_System_int8Array_set_index
#define function_int8Array_resize  function_System_int8Array_resize
#define function_int8Array_getEnumerator  function_System_int8Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int8)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_int8ArrayEnumerator)
#define have_auto_System_int8ArrayEnumerator

#define struct_System_int8ArrayEnumerator  struct System_int8ArrayEnumerator
typedef fixed struct_System_int8ArrayEnumerator {
    struct_System_Object base;

    System_int8Array array;

    System_size index;

}  * System_int8ArrayEnumerator;

#define stack_System_int8ArrayEnumerator()  (struct_System_int8ArrayEnumerator){ .base = stack_System_Object(System_int8ArrayEnumerator), .array = null, }

export struct_System_Type  System_int8ArrayEnumeratorType;

typedef void delegate(System_int8ArrayEnumerator_free)(System_int8ArrayEnumerator that);
typedef System_int8ArrayEnumerator delegate(System_int8ArrayEnumerator_init)(System_int8ArrayEnumerator that, System_int8Array array);
typedef System_int8 delegate(System_int8ArrayEnumerator_get_current)(System_int8ArrayEnumerator that);
typedef System_boolean delegate(System_int8ArrayEnumerator_moveNext)(System_int8ArrayEnumerator that);

#define System_int8ArrayEnumerator_new  System_int8ArrayEnumerator_new__00

export System_int8ArrayEnumerator  System_int8ArrayEnumerator_new(System_int8Array array);
export System_int8ArrayEnumerator  base_System_int8ArrayEnumerator_init(System_int8ArrayEnumerator that, System_int8Array array);
export void  base_System_int8ArrayEnumerator_free(System_int8ArrayEnumerator that);
export System_int8  base_System_int8ArrayEnumerator_get_current(System_int8ArrayEnumerator that);
export System_boolean  base_System_int8ArrayEnumerator_moveNext(System_int8ArrayEnumerator that);

#define System_int8ArrayEnumerator_init(o,...)  ((function_System_int8ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int8ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_int8ArrayEnumerator_free(o)  ((function_System_int8ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int8ArrayEnumerator_get_current(o)  ((function_System_int8ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_int8ArrayEnumerator_moveNext(o)  ((function_System_int8ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_int8ArrayEnumerator_new(a)  (base_System_int8ArrayEnumerator_init(inline_System_Object_allocClass(System_int8ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_int8ArrayEnumerator_new
#define System_int8ArrayEnumerator_new  inline_System_int8ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_int8ArrayEnumerator  struct_System_int8ArrayEnumerator
#define int8ArrayEnumerator  System_int8ArrayEnumerator
#define int8ArrayEnumeratorType  System_int8ArrayEnumeratorType
#define function_int8ArrayEnumerator_init  function_System_int8ArrayEnumerator_init
#define function_int8ArrayEnumerator_free  function_System_int8ArrayEnumerator_free
#define base_int8ArrayEnumerator_init  base_System_int8ArrayEnumerator_init
#define base_int8ArrayEnumerator_free  base_System_int8ArrayEnumerator_free
#define int8ArrayEnumerator_new  System_int8ArrayEnumerator_new
#define int8ArrayEnumerator_init  System_int8ArrayEnumerator_init
#define int8ArrayEnumerator_free  System_int8ArrayEnumerator_free
#endif


#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int16)
#warning "System.int16.h not included"
#include "System.int16.h"
#endif */
#if !defined(have_auto_System_int16Array)
#define have_auto_System_int16Array

#define struct_System_int16Array  struct System_int16Array
typedef fixed struct_System_int16Array {
    struct_System_Object base;

    System_size  length;

    System_int16  (* value)[];

}  * System_int16Array;

#define stack_System_int16Array(LENGTH,...)  (struct_System_int16Array){ .base = { .base = stack_System_Object(System_int16Array), .length = LENGTH, .value = &(System_int16 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_int16ArrayType;

typedef void delegate(System_int16Array_free)(System_int16Array that);
typedef System_int16Array delegate(System_int16Array_init)(System_int16Array that);
typedef System_size  delegate(System_int16Array_get_Length)(System_int16Array that);
typedef System_int16  delegate(System_int16Array_get_index)(System_int16Array that, System_size index);
typedef void  delegate(System_int16Array_set_index)(System_int16Array that, System_size index, System_int16 value);
typedef void delegate(System_int16Array_copyTo)(System_int16Array that, System_int16Array other, System_size offset);
typedef void delegate(System_int16Array_resize)(System_int16Array that, System_size length);
typedef System_IEnumerator  delegate(System_int16Array_getEnumerator)(System_int16Array that);

#define System_int16Array_new  System_int16Array_new__01

export System_int16Array  System_int16Array_new(System_size length);
export System_int16Array  base_System_int16Array_init(System_int16Array that, System_size length);
export void  base_System_int16Array_free(System_int16Array that);
export System_size  base_System_int16Array_get_Length(System_int16Array that);
export System_int16  base_System_int16Array_get_index(System_int16Array that, System_size index);
export void  base_System_int16Array_set_index(System_int16Array that, System_size index, System_int16 value);
export void  base_System_int16Array_copyTo(System_int16Array that, System_int16Array other, System_size offset);
export void  base_System_int16Array_resize(System_int16Array that, System_size length);
export System_IEnumerator  base_System_int16Array_getEnumerator(System_int16Array that);

#define System_int16Array_init(o,...)  ((function_System_int16Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int16Array_init))(o, __VA_ARGS__)
#define System_int16Array_free(o)  ((function_System_int16Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int16Array_get_Length(o)  ((function_System_int16Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_int16Array_get_index(o,...)  ((function_System_int16Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_int16Array_set_index(o,...)  ((function_System_int16Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_int16Array_copyTo(o,...)  ((function_System_int16Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_int16Array_resize(o,...)  ((function_System_int16Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int16Array_resize))(o,__VA_ARGS__)
#define System_int16Array_getEnumerator(o)  ((function_System_int16Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_int16Array_new(LENGTH)  (base_System_int16Array_init(inline_System_Object_allocClass(System_int16Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_int16Array_new
#define System_int16Array_new  inline_System_int16Array_new
#endif

#if defined(using_System)
#define struct_int16Array  struct System_int16Array
#define stack_int16Array  stack_System_int16Array
#define int16Array  System_int16Array
#define int16ArrayType  System_int16ArrayType

#define int16Array_new  System_int16Array_new

#define int16Array_init  System_int16Array_init
#define int16Array_free  System_int16Array_free
#define int16Array_get_Length  System_int16Array_get_Length
#define int16Array_get_index  System_int16Array_get_index
#define int16Array_set_index  System_int16Array_set_index
#define int16Array_resize  System_int16Array_resize
#define base_int16Array_init  base_System_int16Array_init
#define base_int16Array_free  base_System_int16Array_free
#define base_int16Array_get_Length  base_System_int16Array_get_Length
#define base_int16Array_get_index  base_System_int16Array_get_index
#define base_int16Array_set_index  base_System_int16Array_set_index
#define base_int16Array_resize  base_System_int16Array_resize
#define base_int16Array_getEnumerator  base_System_int16Array_getEnumerator
#define function_int16Array_init  function_System_int16Array_init
#define function_int16Array_free  function_System_int16Array_free
#define function_int16Array_get_Length  function_System_int16Array_get_Length
#define function_int16Array_get_index  function_System_int16Array_get_index
#define function_int16Array_set_index  function_System_int16Array_set_index
#define function_int16Array_resize  function_System_int16Array_resize
#define function_int16Array_getEnumerator  function_System_int16Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int16)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_int16ArrayEnumerator)
#define have_auto_System_int16ArrayEnumerator

#define struct_System_int16ArrayEnumerator  struct System_int16ArrayEnumerator
typedef fixed struct_System_int16ArrayEnumerator {
    struct_System_Object base;

    System_int16Array array;

    System_size index;

}  * System_int16ArrayEnumerator;

#define stack_System_int16ArrayEnumerator()  (struct_System_int16ArrayEnumerator){ .base = stack_System_Object(System_int16ArrayEnumerator), .array = null, }

export struct_System_Type  System_int16ArrayEnumeratorType;

typedef void delegate(System_int16ArrayEnumerator_free)(System_int16ArrayEnumerator that);
typedef System_int16ArrayEnumerator delegate(System_int16ArrayEnumerator_init)(System_int16ArrayEnumerator that, System_int16Array array);
typedef System_int16 delegate(System_int16ArrayEnumerator_get_current)(System_int16ArrayEnumerator that);
typedef System_boolean delegate(System_int16ArrayEnumerator_moveNext)(System_int16ArrayEnumerator that);

#define System_int16ArrayEnumerator_new  System_int16ArrayEnumerator_new__00

export System_int16ArrayEnumerator  System_int16ArrayEnumerator_new(System_int16Array array);
export System_int16ArrayEnumerator  base_System_int16ArrayEnumerator_init(System_int16ArrayEnumerator that, System_int16Array array);
export void  base_System_int16ArrayEnumerator_free(System_int16ArrayEnumerator that);
export System_int16  base_System_int16ArrayEnumerator_get_current(System_int16ArrayEnumerator that);
export System_boolean  base_System_int16ArrayEnumerator_moveNext(System_int16ArrayEnumerator that);

#define System_int16ArrayEnumerator_init(o,...)  ((function_System_int16ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int16ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_int16ArrayEnumerator_free(o)  ((function_System_int16ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int16ArrayEnumerator_get_current(o)  ((function_System_int16ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_int16ArrayEnumerator_moveNext(o)  ((function_System_int16ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_int16ArrayEnumerator_new(a)  (base_System_int16ArrayEnumerator_init(inline_System_Object_allocClass(System_int16ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_int16ArrayEnumerator_new
#define System_int16ArrayEnumerator_new  inline_System_int16ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_int16ArrayEnumerator  struct_System_int16ArrayEnumerator
#define int16ArrayEnumerator  System_int16ArrayEnumerator
#define int16ArrayEnumeratorType  System_int16ArrayEnumeratorType
#define function_int16ArrayEnumerator_init  function_System_int16ArrayEnumerator_init
#define function_int16ArrayEnumerator_free  function_System_int16ArrayEnumerator_free
#define base_int16ArrayEnumerator_init  base_System_int16ArrayEnumerator_init
#define base_int16ArrayEnumerator_free  base_System_int16ArrayEnumerator_free
#define int16ArrayEnumerator_new  System_int16ArrayEnumerator_new
#define int16ArrayEnumerator_init  System_int16ArrayEnumerator_init
#define int16ArrayEnumerator_free  System_int16ArrayEnumerator_free
#endif


#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int32)
#warning "System.int32.h not included"
#include "System.int32.h"
#endif */
#if !defined(have_auto_System_int32Array)
#define have_auto_System_int32Array

#define struct_System_int32Array  struct System_int32Array
typedef fixed struct_System_int32Array {
    struct_System_Object base;

    System_size  length;

    System_int32  (* value)[];

}  * System_int32Array;

#define stack_System_int32Array(LENGTH,...)  (struct_System_int32Array){ .base = { .base = stack_System_Object(System_int32Array), .length = LENGTH, .value = &(System_int32 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_int32ArrayType;

typedef void delegate(System_int32Array_free)(System_int32Array that);
typedef System_int32Array delegate(System_int32Array_init)(System_int32Array that);
typedef System_size  delegate(System_int32Array_get_Length)(System_int32Array that);
typedef System_int32  delegate(System_int32Array_get_index)(System_int32Array that, System_size index);
typedef void  delegate(System_int32Array_set_index)(System_int32Array that, System_size index, System_int32 value);
typedef void delegate(System_int32Array_copyTo)(System_int32Array that, System_int32Array other, System_size offset);
typedef void delegate(System_int32Array_resize)(System_int32Array that, System_size length);
typedef System_IEnumerator  delegate(System_int32Array_getEnumerator)(System_int32Array that);

#define System_int32Array_new  System_int32Array_new__01

export System_int32Array  System_int32Array_new(System_size length);
export System_int32Array  base_System_int32Array_init(System_int32Array that, System_size length);
export void  base_System_int32Array_free(System_int32Array that);
export System_size  base_System_int32Array_get_Length(System_int32Array that);
export System_int32  base_System_int32Array_get_index(System_int32Array that, System_size index);
export void  base_System_int32Array_set_index(System_int32Array that, System_size index, System_int32 value);
export void  base_System_int32Array_copyTo(System_int32Array that, System_int32Array other, System_size offset);
export void  base_System_int32Array_resize(System_int32Array that, System_size length);
export System_IEnumerator  base_System_int32Array_getEnumerator(System_int32Array that);

#define System_int32Array_init(o,...)  ((function_System_int32Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int32Array_init))(o, __VA_ARGS__)
#define System_int32Array_free(o)  ((function_System_int32Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int32Array_get_Length(o)  ((function_System_int32Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_int32Array_get_index(o,...)  ((function_System_int32Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_int32Array_set_index(o,...)  ((function_System_int32Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_int32Array_copyTo(o,...)  ((function_System_int32Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_int32Array_resize(o,...)  ((function_System_int32Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int32Array_resize))(o,__VA_ARGS__)
#define System_int32Array_getEnumerator(o)  ((function_System_int32Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_int32Array_new(LENGTH)  (base_System_int32Array_init(inline_System_Object_allocClass(System_int32Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_int32Array_new
#define System_int32Array_new  inline_System_int32Array_new
#endif

#if defined(using_System)
#define struct_int32Array  struct System_int32Array
#define stack_int32Array  stack_System_int32Array
#define int32Array  System_int32Array
#define int32ArrayType  System_int32ArrayType

#define int32Array_new  System_int32Array_new

#define int32Array_init  System_int32Array_init
#define int32Array_free  System_int32Array_free
#define int32Array_get_Length  System_int32Array_get_Length
#define int32Array_get_index  System_int32Array_get_index
#define int32Array_set_index  System_int32Array_set_index
#define int32Array_resize  System_int32Array_resize
#define base_int32Array_init  base_System_int32Array_init
#define base_int32Array_free  base_System_int32Array_free
#define base_int32Array_get_Length  base_System_int32Array_get_Length
#define base_int32Array_get_index  base_System_int32Array_get_index
#define base_int32Array_set_index  base_System_int32Array_set_index
#define base_int32Array_resize  base_System_int32Array_resize
#define base_int32Array_getEnumerator  base_System_int32Array_getEnumerator
#define function_int32Array_init  function_System_int32Array_init
#define function_int32Array_free  function_System_int32Array_free
#define function_int32Array_get_Length  function_System_int32Array_get_Length
#define function_int32Array_get_index  function_System_int32Array_get_index
#define function_int32Array_set_index  function_System_int32Array_set_index
#define function_int32Array_resize  function_System_int32Array_resize
#define function_int32Array_getEnumerator  function_System_int32Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int32)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_int32ArrayEnumerator)
#define have_auto_System_int32ArrayEnumerator

#define struct_System_int32ArrayEnumerator  struct System_int32ArrayEnumerator
typedef fixed struct_System_int32ArrayEnumerator {
    struct_System_Object base;

    System_int32Array array;

    System_size index;

}  * System_int32ArrayEnumerator;

#define stack_System_int32ArrayEnumerator()  (struct_System_int32ArrayEnumerator){ .base = stack_System_Object(System_int32ArrayEnumerator), .array = null, }

export struct_System_Type  System_int32ArrayEnumeratorType;

typedef void delegate(System_int32ArrayEnumerator_free)(System_int32ArrayEnumerator that);
typedef System_int32ArrayEnumerator delegate(System_int32ArrayEnumerator_init)(System_int32ArrayEnumerator that, System_int32Array array);
typedef System_int32 delegate(System_int32ArrayEnumerator_get_current)(System_int32ArrayEnumerator that);
typedef System_boolean delegate(System_int32ArrayEnumerator_moveNext)(System_int32ArrayEnumerator that);

#define System_int32ArrayEnumerator_new  System_int32ArrayEnumerator_new__00

export System_int32ArrayEnumerator  System_int32ArrayEnumerator_new(System_int32Array array);
export System_int32ArrayEnumerator  base_System_int32ArrayEnumerator_init(System_int32ArrayEnumerator that, System_int32Array array);
export void  base_System_int32ArrayEnumerator_free(System_int32ArrayEnumerator that);
export System_int32  base_System_int32ArrayEnumerator_get_current(System_int32ArrayEnumerator that);
export System_boolean  base_System_int32ArrayEnumerator_moveNext(System_int32ArrayEnumerator that);

#define System_int32ArrayEnumerator_init(o,...)  ((function_System_int32ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int32ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_int32ArrayEnumerator_free(o)  ((function_System_int32ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int32ArrayEnumerator_get_current(o)  ((function_System_int32ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_int32ArrayEnumerator_moveNext(o)  ((function_System_int32ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_int32ArrayEnumerator_new(a)  (base_System_int32ArrayEnumerator_init(inline_System_Object_allocClass(System_int32ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_int32ArrayEnumerator_new
#define System_int32ArrayEnumerator_new  inline_System_int32ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_int32ArrayEnumerator  struct_System_int32ArrayEnumerator
#define int32ArrayEnumerator  System_int32ArrayEnumerator
#define int32ArrayEnumeratorType  System_int32ArrayEnumeratorType
#define function_int32ArrayEnumerator_init  function_System_int32ArrayEnumerator_init
#define function_int32ArrayEnumerator_free  function_System_int32ArrayEnumerator_free
#define base_int32ArrayEnumerator_init  base_System_int32ArrayEnumerator_init
#define base_int32ArrayEnumerator_free  base_System_int32ArrayEnumerator_free
#define int32ArrayEnumerator_new  System_int32ArrayEnumerator_new
#define int32ArrayEnumerator_init  System_int32ArrayEnumerator_init
#define int32ArrayEnumerator_free  System_int32ArrayEnumerator_free
#endif


#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int64)
#warning "System.int64.h not included"
#include "System.int64.h"
#endif */
#if !defined(have_auto_System_int64Array)
#define have_auto_System_int64Array

#define struct_System_int64Array  struct System_int64Array
typedef fixed struct_System_int64Array {
    struct_System_Object base;

    System_size  length;

    System_int64  (* value)[];

}  * System_int64Array;

#define stack_System_int64Array(LENGTH,...)  (struct_System_int64Array){ .base = { .base = stack_System_Object(System_int64Array), .length = LENGTH, .value = &(System_int64 []){ __VA_ARGS__ }, }, }

export struct_System_Type  System_int64ArrayType;

typedef void delegate(System_int64Array_free)(System_int64Array that);
typedef System_int64Array delegate(System_int64Array_init)(System_int64Array that);
typedef System_size  delegate(System_int64Array_get_Length)(System_int64Array that);
typedef System_int64  delegate(System_int64Array_get_index)(System_int64Array that, System_size index);
typedef void  delegate(System_int64Array_set_index)(System_int64Array that, System_size index, System_int64 value);
typedef void delegate(System_int64Array_copyTo)(System_int64Array that, System_int64Array other, System_size offset);
typedef void delegate(System_int64Array_resize)(System_int64Array that, System_size length);
typedef System_IEnumerator  delegate(System_int64Array_getEnumerator)(System_int64Array that);

#define System_int64Array_new  System_int64Array_new__01

export System_int64Array  System_int64Array_new(System_size length);
export System_int64Array  base_System_int64Array_init(System_int64Array that, System_size length);
export void  base_System_int64Array_free(System_int64Array that);
export System_size  base_System_int64Array_get_Length(System_int64Array that);
export System_int64  base_System_int64Array_get_index(System_int64Array that, System_size index);
export void  base_System_int64Array_set_index(System_int64Array that, System_size index, System_int64 value);
export void  base_System_int64Array_copyTo(System_int64Array that, System_int64Array other, System_size offset);
export void  base_System_int64Array_resize(System_int64Array that, System_size length);
export System_IEnumerator  base_System_int64Array_getEnumerator(System_int64Array that);

#define System_int64Array_init(o,...)  ((function_System_int64Array_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int64Array_init))(o, __VA_ARGS__)
#define System_int64Array_free(o)  ((function_System_int64Array_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int64Array_get_Length(o)  ((function_System_int64Array_get_Length)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_Length))(o)
#define System_int64Array_get_index(o,...)  ((function_System_int64Array_get_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_get_index))(o, __VA_ARGS__)
#define System_int64Array_set_index(o,...)  ((function_System_int64Array_set_index)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_set_index))(o, __VA_ARGS__)
#define System_int64Array_copyTo(o,...)  ((function_System_int64Array_copyTo)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_ICollection_copyTo))(o,__VA_ARGS__)
#define System_int64Array_resize(o,...)  ((function_System_int64Array_resize)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int64Array_resize))(o,__VA_ARGS__)
#define System_int64Array_getEnumerator(o)  ((function_System_int64Array_getEnumerator)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerable_getEnumerator))(o)

#define inline_System_int64Array_new(LENGTH)  (base_System_int64Array_init(inline_System_Object_allocClass(System_int64Array), LENGTH))

#if !defined(have_System_internal)
#undef  System_int64Array_new
#define System_int64Array_new  inline_System_int64Array_new
#endif

#if defined(using_System)
#define struct_int64Array  struct System_int64Array
#define stack_int64Array  stack_System_int64Array
#define int64Array  System_int64Array
#define int64ArrayType  System_int64ArrayType

#define int64Array_new  System_int64Array_new

#define int64Array_init  System_int64Array_init
#define int64Array_free  System_int64Array_free
#define int64Array_get_Length  System_int64Array_get_Length
#define int64Array_get_index  System_int64Array_get_index
#define int64Array_set_index  System_int64Array_set_index
#define int64Array_resize  System_int64Array_resize
#define base_int64Array_init  base_System_int64Array_init
#define base_int64Array_free  base_System_int64Array_free
#define base_int64Array_get_Length  base_System_int64Array_get_Length
#define base_int64Array_get_index  base_System_int64Array_get_index
#define base_int64Array_set_index  base_System_int64Array_set_index
#define base_int64Array_resize  base_System_int64Array_resize
#define base_int64Array_getEnumerator  base_System_int64Array_getEnumerator
#define function_int64Array_init  function_System_int64Array_init
#define function_int64Array_free  function_System_int64Array_free
#define function_int64Array_get_Length  function_System_int64Array_get_Length
#define function_int64Array_get_index  function_System_int64Array_get_index
#define function_int64Array_set_index  function_System_int64Array_set_index
#define function_int64Array_resize  function_System_int64Array_resize
#define function_int64Array_getEnumerator  function_System_int64Array_getEnumerator
#endif

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#warning "System.Type.h not included"
#include "System.Type.h"
#endif
/* #if !defined(have_System_int64)
#warning "System.T.h not included"
#include "System.T.h"
#endif */
#if !defined(have_auto_System_int64ArrayEnumerator)
#define have_auto_System_int64ArrayEnumerator

#define struct_System_int64ArrayEnumerator  struct System_int64ArrayEnumerator
typedef fixed struct_System_int64ArrayEnumerator {
    struct_System_Object base;

    System_int64Array array;

    System_size index;

}  * System_int64ArrayEnumerator;

#define stack_System_int64ArrayEnumerator()  (struct_System_int64ArrayEnumerator){ .base = stack_System_Object(System_int64ArrayEnumerator), .array = null, }

export struct_System_Type  System_int64ArrayEnumeratorType;

typedef void delegate(System_int64ArrayEnumerator_free)(System_int64ArrayEnumerator that);
typedef System_int64ArrayEnumerator delegate(System_int64ArrayEnumerator_init)(System_int64ArrayEnumerator that, System_int64Array array);
typedef System_int64 delegate(System_int64ArrayEnumerator_get_current)(System_int64ArrayEnumerator that);
typedef System_boolean delegate(System_int64ArrayEnumerator_moveNext)(System_int64ArrayEnumerator that);

#define System_int64ArrayEnumerator_new  System_int64ArrayEnumerator_new__00

export System_int64ArrayEnumerator  System_int64ArrayEnumerator_new(System_int64Array array);
export System_int64ArrayEnumerator  base_System_int64ArrayEnumerator_init(System_int64ArrayEnumerator that, System_int64Array array);
export void  base_System_int64ArrayEnumerator_free(System_int64ArrayEnumerator that);
export System_int64  base_System_int64ArrayEnumerator_get_current(System_int64ArrayEnumerator that);
export System_boolean  base_System_int64ArrayEnumerator_moveNext(System_int64ArrayEnumerator that);

#define System_int64ArrayEnumerator_init(o,...)  ((function_System_int64ArrayEnumerator_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_int64ArrayEnumerator_init))(o,__VA_ARGS__)
#define System_int64ArrayEnumerator_free(o)  ((function_System_int64ArrayEnumerator_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)
#define System_int64ArrayEnumerator_get_current(o)  ((function_System_int64ArrayEnumerator_get_current)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_get_current))(o)
#define System_int64ArrayEnumerator_moveNext(o)  ((function_System_int64ArrayEnumerator_moveNext)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_IEnumerator_moveNext))(o)

#define inline_System_int64ArrayEnumerator_new(a)  (base_System_int64ArrayEnumerator_init(inline_System_Object_allocClass(System_int64ArrayEnumerator), a))

#if !defined(have_System_internal)
#undef  System_int64ArrayEnumerator_new
#define System_int64ArrayEnumerator_new  inline_System_int64ArrayEnumerator_new
#endif

#if defined(using_System)
#define struct_int64ArrayEnumerator  struct_System_int64ArrayEnumerator
#define int64ArrayEnumerator  System_int64ArrayEnumerator
#define int64ArrayEnumeratorType  System_int64ArrayEnumeratorType
#define function_int64ArrayEnumerator_init  function_System_int64ArrayEnumerator_init
#define function_int64ArrayEnumerator_free  function_System_int64ArrayEnumerator_free
#define base_int64ArrayEnumerator_init  base_System_int64ArrayEnumerator_init
#define base_int64ArrayEnumerator_free  base_System_int64ArrayEnumerator_free
#define int64ArrayEnumerator_new  System_int64ArrayEnumerator_new
#define int64ArrayEnumerator_init  System_int64ArrayEnumerator_init
#define int64ArrayEnumerator_free  System_int64ArrayEnumerator_free
#endif


#endif
