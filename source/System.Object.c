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
	assert(type)
    assert(type->size);

	size size = type->size;

#if DEBUG == DEBUG_System_Object
	Console_writeLine("System_Object_allocClass {0:string}: .size: {1:uint}", 2, type->name->value, size);
#endif

	System_Object that = Memory_alloc(size);
	that->type = type;
	that->bitConfig.isAllocated = true;
	that->refCount = 4;

	return that;
}

void  System_Object_freeClass(System_Object * thatPtr) {
	assert(thatPtr)
	Object that = *thatPtr;
	assert(that)

	System_Type type = System_Object_get_Type(that);

	if (0 == that->refCount) {
        /* this is stack aligned */
#if DEBUG == DEBUG_System_Object
	Console_writeLine("{0:string}_freeClass: .size: {1:int}B ... static", 2, type->name->value, type->size);
#endif
		goto return_free;
	}
	assert(that->refCount > 3)
	if (--that->refCount > 3) goto return_free;

	that->refCount = 2;

    /* System_Object_free(that): */
    function_Object_free free = (function_Object_free)Type_getMethod(type, base_System_Object_free);
	if (free) free(that);

	that->refCount = 1;

	if (that->bitConfig.isAllocated) {
#if DEBUG == DEBUG_System_Object
		if (that->bitConfig.isValueAllocated)
			Console_writeLine("{0:string}_freeClass: .size: {1:int}B, .bitConfig.isAllocated, .bitConfig.isValueAllocated", 2, type->name->value, type->size);
		else
			Console_writeLine("{0:string}_freeClass: .size: {1:int}B, .bitConfig.isAllocated", 2, type->name->value, type->size);
#endif

		/* TODO: if MultiThreading, this should be done by System_GC */
		Memory_free((void **)thatPtr);
	}

#if DEBUG == DEBUG_System_Object
	else {
		if (that->bitConfig.isValueAllocated)
			Console_writeLine("{0:string}_freeClass: .size: {1:int}B, .bitConfig.isValueAllocated", 2, type->name->value, type->size);
		else
			Console_writeLine("{0:string}_freeClass: .size: {1:int}B", 2, type->name->value, type->size);
	}
#endif

return_free:
	*thatPtr = null;
}


/* class System_Object */

void  base_System_Object_free(Object that) {
	unused(that)

#if DEBUG == DEBUG_System_Object
	Console_writeLine("{0:string}_free", 1, that->type->name->value);
#endif
}

Object  base_System_Object_init(Object that) {

#if DEBUG == DEBUG_System_Object
	Console_writeLine("{0:string}_init", 1, that->type->name->value);
#endif

    return that;
}

Object  System_Object_addReference(Object that) {
	return ((((Object)that)->refCount == 0) ? that : (++(((Object)that)->refCount), that));
}

Type  System_Object_get_Type(Object that) {
    assert(that)
    assert(that->type)
    return that->type;
}

System_boolean  System_Object_isInstanceof(System_Object that, System_Type type) {
    assert(that)
    assert(type)
    return System_Type_isAssignableFrom(System_Object_get_Type(that), type);
}

System_Object  System_Object_asInstanceof(System_Object that, System_Type type) {
    assert(that)
    assert(type)
    return System_Object_isInstanceof(that, type) ? that : null;
}

System_uint64 base_System_Object_getSipHash(System_Object that) {
    struct_Crypto_SipHash48 sipHash48 = stack_Crypto_SipHash48();
    Crypto_SipHash48_init(&sipHash48);
    System_intptr that_intptr = (System_intptr)that;
    Crypto_SipHash48_update(&sipHash48, &that_intptr, System_bytesize);
    return Crypto_SipHash48_final(&sipHash48);
}

struct_System_Type_FunctionInfo  System_ObjectTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_Object_init },
    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_Object_free },
    [2] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_getSipHash, .value = base_System_Object_getSipHash },
};

struct_System_Type  System_ObjectType = { .base = { .type = typeof(System_Type) },
	.name = "System.Object",
	.size = sizeof(struct_System_Object),
	.baseType = null, /* this is System_Object */
	.functions  = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = sizeof_array(System_ObjectTypeFunctions), .value = &System_ObjectTypeFunctions
    },
};

#endif
