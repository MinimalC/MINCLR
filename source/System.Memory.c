/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
/* WARNING: DEBUG: TODO */
#if !defined(have_ISO)
#define using_ISO
#include <min/ISO.h>
#endif
#if !defined(code_System_Memory)
#define code_System_Memory

/*# System_Memory #*/

struct_System_Type  System_MemoryType = { .base = stack_System_Object(System_Type),
	.name = "System.Memory",
};

size System_Memory_indexof(var ptr, char8 needle, size count) {
    assert(count)

    size i = 0;
    char8 *ptrBytes = (char8 *)ptr;
    do {
        ++i;
        if (*ptrBytes == needle) return i;
        if (--count == 0) break;
        ++ptrBytes;
    } while (true);

    return 0;
}

void System_Memory_zero(var dest, size n) {
    assert(n)

    char8 *destBytes = (char8 *)dest;
    do {
        *destBytes = 0x00;
        if (--n == 0) break;
        ++destBytes;
    } while (true);
}

void System_Memory_copy(var src, size n, var dest) {
    char8 *destBytes = (char8 *)dest;
    char8 *srcBytes = (char8 *)src;
    while (n--) *destBytes++ = *srcBytes++;
}

void System_Memory_move(var src, size n, var dest) {
    char8 *destBytes = (char8 *)dest;
    char8 *srcBytes = (char8 *)src;
    if ( srcBytes < destBytes ) {
        destBytes += n;
        srcBytes += n;
        while (n--) *destBytes-- = *srcBytes--;
    }
    else
        while (n--) *destBytes++ = *srcBytes++;
}

void System_Memory_set(var dest, char8 src, size length) {
    assert(length)

    char8 *destBytes = (char8 *)dest;
    do {
        *destBytes = src;
        if (--length == 0) break;
        ++destBytes;
    } while (true);
}

size System_Memory_compare(var ptr0, var ptr1, size length) {
    assert(length)

    size count = 0;
    char8 *ptr0Bytes = (char8 *)ptr0;
    char8 *ptr1Bytes = (char8 *)ptr1;
    do {
        if (*ptr0Bytes != *ptr1Bytes) return count;
        ++count;
        if (--length == 0) break;
        ++ptr0Bytes;
        ++ptr1Bytes;
    } while (true);

    return count;
}

bool System_Memory_equals(var ptr0, var ptr1, size length) {
    return (length == System_Memory_compare(ptr0, ptr1, length));
}

/*
    Look, this is the root of all Memory_Headers.

    There is
    one for 64KB
    one reserved, for 1MB
    one reserved, for 64MB
    one for everything else

    Use first Memory page for Memory_Header, and then reference future pages within this Memory_Header.
*/

internal System_var  System_Memory_ProcessVars[] = { 0, 0, 0, 0 };

struct_System_Memory_Arena  System_Memory_ProcessArena = {
    .base = {
        .base = stack_System_Object(System_Memory_Arena),
        .length = sizeof_array(System_Memory_ProcessVars),
        .value = &System_Memory_ProcessVars,
    },
};

System_var  System_Memory_alloc__internal(System_Type type, System_size length) {

    System_size real_length = sizeof(struct_System_Memory_Header) + type->size * length;

    if (real_length < 32768) {
        System_var map;
        System_Memory_Arena mem64k = System_Memory_ProcessVars[0];
        if (!mem64k) {
            map = System_Syscall_mmap(65536, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
            if (!map || map == System_Memory_MapFailed) return null;
            mem64k = (System_Memory_Arena)map;
            mem64k->base.base.type = typeof(System_Memory_Arena);
            mem64k->base.length = (65536 - sizeof(System_Memory_Arena)) / sizeof(System_var);
            mem64k->base.value = ((System_var)mem64k + sizeof(System_Memory_Arena));
            mem64k->pageSize = 65536;
            System_Memory_ProcessVars[0] = mem64k;
        }
        System_Memory_Header mem64h = null;
        for (size i = 0; i <= mem64k->base.length; ++i) {
            mem64h = (System_Memory_Header)array(mem64k->base.value)[i];
            if (!mem64h) {
                map = System_Syscall_mmap(65536, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
                if (!map || map == System_Memory_MapFailed) return null;
                mem64h = (System_Memory_Header)map;
                mem64h->base.type = typeof(System_Memory_Header);
                mem64h->design = length == 1 ? System_Memory_Design_Object : System_Memory_Design_Array;
                mem64h->type = type;
                mem64h->refCount = System_Memory_ReferenceState_Used;
                mem64h->length = length;
                array(mem64k->base.value)[i] = mem64h;
                return (System_var)mem64h + sizeof(System_Memory_Header);
            }
        }
    }
}

System_Object  System_Memory_allocClass(System_Type type) {
	assert(type)
    assert(type->size);

#if DEBUG == DEBUG_System_Object
	Console_writeLine("System_Object_allocClass {0:string}: .size: {1:uint}", 2, type->name->value, type->size);
#endif

	System_Object that = (System_Object)System_Memory_alloc__internal(type, 1);
	that->type = type;
	that->bitConfig.isAllocated = true;

	return that;
}

void  System_Memory_freeClass(System_Object * thatPtr) {
	assert(thatPtr)
	Object that = *thatPtr;
	assert(that)

	System_Type type = System_Object_get_Type(that);
    System_Memory_Header header = (System_var)that - sizeof(System_Memory_Header);

	if (0 == header->refCount) {
        /* this is stack aligned */
#if DEBUG == DEBUG_System_Object
	Console_writeLine("{0:string}_freeClass: .size: {1:int}B ... static", 2, type->name->value, type->size);
#endif
		goto return_free;
	}
	assert(header->refCount >= System_Memory_ReferenceState_Used)
	if (--header->refCount >= System_Memory_ReferenceState_Used) goto return_free;

	header->refCount = System_Memory_ReferenceState_Disposing;

    /* System_Object_free(that): */
    function_Object_free free = (function_Object_free)Type_getMethod(type, base_System_Object_free);
	if (free) free(that);

	header->refCount = System_Memory_ReferenceState_Disposed;

	if (that->bitConfig.isAllocated) {
#if DEBUG == DEBUG_System_Object
		if (that->bitConfig.isValueAllocated)
			Console_writeLine("{0:string}_freeClass: .size: {1:int}B, .bitConfig.isAllocated, .bitConfig.isValueAllocated", 2, type->name->value, type->size);
		else
			Console_writeLine("{0:string}_freeClass: .size: {1:int}B, .bitConfig.isAllocated", 2, type->name->value, type->size);
#endif

		/* TODO: if MultiThreading, this should be done by System_GC */

        /* TODO munmap here? */
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


/* OLD */

System_var  System_Memory_alloc(size length) {

    void *thatPtr = ISO_malloc(length);
    uint8 *that = (uint8 *)thatPtr;
    System_Memory_set(that, 0x00, length);
    return thatPtr;
}

void  System_Memory_realloc(void  ** that, size oldLength, size newLength) {

    uint8  * that1 = (uint8 *)ISO_realloc(*that, newLength);
    if (newLength > oldLength) {
        System_Memory_set(that1 + oldLength, 0x00, newLength - oldLength);
    }

    if (*that != that1) {
        *that = that1;
    }
}

void System_Memory_freeStruct(void *that) {
    assert(that)
    ISO_free(that);
}

void System_Memory_free(void **thatPtr) {
    assert(thatPtr)
    void *that = *thatPtr;
    assert(that)
    System_Memory_freeStruct(that);
    *thatPtr = null;
}

#endif
