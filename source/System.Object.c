/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Object)
#include <min/System.Type.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_Crypto_SipHash48)
#include <min/Crypto.SipHash48.h>
#endif
#if !defined(code_System_Object)
#define code_System_Object

/*# System_Object #*/

Type  System_Object_get_Type(Object that) {
    Debug_assert(that);
    Debug_assert(that->type);
    return that->type;
}

System_Bool  System_Object_isInstanceof(System_Object that, System_Type type) {
    Debug_assert(that);
    Debug_assert(type);
    return System_Type_isAssignableFrom(System_Object_get_Type(that), type);
}

System_Object  System_Object_asInstanceof(System_Object that, System_Type type) {
    Debug_assert(that);
    Debug_assert(type);
    return System_Object_isInstanceof(that, type) ? that : null;
}

void  base_System_Object_free(Object that) {
	unused(that)
}

void  base_System_Object_init(Object that) {
	unused(that)
}

Object  new_System_Object() {
    System_Object that = (System_Object)System_Memory_allocClass(typeof(System_Object));
    /* base_System_Object_init(that); */
    return that;
}

System_UInt64 base_System_Object_getSipHash(System_Object that) {
    struct Crypto_SipHash48 sipHash48; System_Stack_zero(sipHash48);
    Crypto_SipHash48_init(&sipHash48);
    System_IntPtr that_intptr = (System_IntPtr)that;
    Crypto_SipHash48_update(&sipHash48, &that_intptr, System_Size_Bytes);
    return Crypto_SipHash48_final(&sipHash48);
}

struct System_Type_FunctionInfo  System_ObjectTypeFunctions[] = {
    [0] = { .function = base_System_Object_init, .value = base_System_Object_init },
    [1] = { .function = base_System_Object_free, .value = base_System_Object_free },
    [2] = { .function = base_System_Object_getSipHash, .value = base_System_Object_getSipHash },
};

struct System_Type System_ObjectType = { .base = { .type = typeof(System_Type) },
	.name = "Object",
	.size = sizeof(struct System_Object),
	.baseType = null, /* this is System_Object */
	.functions  = { 
        .length = sizeof_array(System_ObjectTypeFunctions), .value = &System_ObjectTypeFunctions
    },
};

#endif
