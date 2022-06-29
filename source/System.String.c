/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_String)
#include <min/System.String.h>
#endif
#if !defined(code_System_String)
#define code_System_String

/*# System_String #*/

System_String  System_String_new(System_string8 string) {
    return inline_System_String_new(string);
}

/* class System_String */

void base_System_String_free(String that) {
    assert(that)

    if (that->value && that->base.bitConfig.isValueAllocated) {
        Memory_free((void **)&(that->value));
    }

    base_System_Object_free((Object)that);
}

String  base_System_String_init(String that, string8 string) {
    base_System_Object_init((Object)that);

    /* that->base.bitConfig.isValueAllocated = true; */
    that->codepage = System_encoding_DEFAULT;
    that->length = System_string8_get_Length(string);
    that->value = string;
    return that;
}

System_uint64 base_System_String_getSipHash(System_String that) {
    struct_Crypto_SipHash48 sipHash48 = stack_Crypto_SipHash48();
    Crypto_SipHash48_init(&sipHash48);
    Crypto_SipHash48_update(&sipHash48, (System_var)that->value, that->length);
    return Crypto_SipHash48_final(&sipHash48);
}

struct_System_Type_FunctionInfo  System_StringTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_String_free },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_String_init, .value = base_System_String_init },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_getSipHash, .value = base_System_String_getSipHash },
};

struct_System_Type  System_StringType = { .base = stack_System_Object(System_Type),
    .name = "System.String",
    .size = sizeof(struct_System_String),
    .baseType = typeof(System_Object),
	.functions  = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_StringTypeFunctions), .value = &System_StringTypeFunctions
    },
};

#endif
