/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
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

/* static class System_Object */

System_Object  System_Object_allocClass(System_Type type) {
	__assert(type)
    __assert(type->size);

	__size size = type->size;

#if __DEBUG == DEBUG_System_Object
	__Console_printLine("System_Object_allocClass %s: .size: %u", type->name->value, size);
#endif

	System_Object that = __Memory_alloc(size);
	that->Type = type;
	that->bitConfig.isAllocated = __true;
	that->refCount = 4;

	return that;
}

void  System_Object_freeClass(System_Object * thatPtr) {
	__assert(thatPtr)
	__Object that = *thatPtr;
	__assert(that)

	System_Type type = System_Object_get_Type(that);

	if (0 == that->refCount) {
        /* this is stack aligned */
#if __DEBUG == DEBUG_System_Object
	__Console_print("__%s_freeClass: .size: %iB ... static\n", type->name->value, type->size);
#endif
		goto return_free;
	}
	__assert(that->refCount > 3)
	if (--that->refCount > 3) goto return_free;

	that->refCount = 2;

    /* System_Object_free(that): */
    function_Object_free free = (function_Object_free)__Type_getMethod(type, base_System_Object_free);
	if (free) free(that);

	that->refCount = 1;

	if (that->bitConfig.isAllocated) {
#if __DEBUG == DEBUG_System_Object
		if (that->bitConfig.isValueAllocated)
			__Console_print("__%s_freeClass: .size: %iB, .bitConfig.isAllocated, .bitConfig.isValueAllocated\n", type->name->value, type->size);
		else
			__Console_print("__%s_freeClass: .size: %iB, .bitConfig.isAllocated\n", type->name->value, type->size);
#endif

		/* TODO: if MultiThreading, this should be done by System_GC */
		__Memory_free((void **)thatPtr);
	}

#if __DEBUG == DEBUG_System_Object
	else {
		if (that->bitConfig.isValueAllocated)
			__Console_print("__%s_freeClass: .size: %iB, .bitConfig.isValueAllocated\n", type->name->value, type->size);
		else
			__Console_print("__%s_freeClass: .size: %iB\n", type->name->value, type->size);
	}
#endif

return_free:
	*thatPtr = __null;
}


/* class System_Object */

void  base_System_Object_free(__Object that) {
	__unused(that)

#if __DEBUG == DEBUG_System_Object
	__Console_print("__%s_free\n", that->Type->name->value);
#endif
}

__Object  base_System_Object_init(__Object that) {

#if __DEBUG == DEBUG_System_Object
	__Console_print("__%s_init\n", that->Type->name->value);
#endif

    return that;
}

__Object  System_Object_new() {
    return inline_System_Object_new();
}

__Object  System_Object_addReference(__Object that) {
	return ((((__Object)that)->refCount == 0) ? that : (++(((__Object)that)->refCount), that));
}

__Type  System_Object_get_Type(__Object that) {
    __assert(that)
    __assert(that->Type)
    return that->Type;
}

System_boolean  System_Object_isInstanceOf(System_Object that, System_Type type) {
    __assert(that)
    __assert(type)
    return System_Type_isAssignableFrom(System_Object_get_Type(that), type);
}

System_Object  System_Object_asInstanceOf(System_Object that, System_Type type) {
    __assert(that)
    __assert(type)
    return System_Object_isInstanceOf(that, type) ? that : __null;
}

System_uint64 base_System_Object_getSipHash(System_Object that) {
    struct_Crypto_SipHash48 sipHash48 = stack_Crypto_SipHash48();
    Crypto_SipHash48_init(&sipHash48);
    System_intptr that_intptr = (System_intptr)that;
    Crypto_SipHash48_update(&sipHash48, &that_intptr, System_bytesize);
    return Crypto_SipHash48_final(&sipHash48);
}

System_boolean System_Object_referenceEquals(System_Object that, System_Object other) {
    return that == other;
}

struct_System_Type_FunctionInfo  System_ObjectTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Object_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Object_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_getSipHash, .value = base_System_Object_getSipHash },
};

struct_System_Type  System_ObjectType = { .base = { .Type = __typeof(System_Type) },
	.name = "System.Object",
	.size = sizeof(struct_System_Object),
	.baseType = __null, /* this is System_Object */
	.functions  = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(System_ObjectTypeFunctions), .value = &System_ObjectTypeFunctions
    },
};

#endif
