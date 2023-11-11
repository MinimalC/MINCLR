/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_String)
#include <min/System.String.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_Crypto_SipHash48)
#include <min/Crypto.SipHash48.h>
#endif
#if !defined(code_System_String)
#define code_System_String

/*# System_String #*/

void  System_String_free(System_String that) {
    Debug_assert(that);
    if (!that) return;

	System_Memory_free(that->value);
}

System_UInt64 System_String_getSipHash(System_String that) {
    struct Crypto_SipHash48 sipHash48; System_Stack_clear(sipHash48);
    Crypto_SipHash48_init(&sipHash48);
    Crypto_SipHash48_update(&sipHash48, that->value, that->length);
    return Crypto_SipHash48_final(&sipHash48);
}

struct System_Type_FunctionInfo  System_StringTypeFunctions[] = {
    [0] = { .function = base_System_Object_free, .value = System_String_free },
    [1] = { .function = base_System_Object_getSipHash, .value = System_String_getSipHash },
};

struct System_Type System_StringType = { .base = { .type = typeof(System_Type) },
	.name = "String",
	.size = sizeof(struct System_String),
	.baseType = null, /* this is a struct */
	.functions  = { .length = sizeof_array(System_StringTypeFunctions), .value = &System_StringTypeFunctions },
};

#endif
