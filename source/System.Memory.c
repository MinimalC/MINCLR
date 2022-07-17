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
#if !defined(have_System_Math)
#include <min/System.Math.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_varArray)
#include <min/System.varArray.h>
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
    Look, this is the root.

    There is
    one for 64KB
    one reserved, for 1MB
    one reserved, for 64MB
    one for everything else
*/

internal System_var  System_Memory_ProcessVars[] = { 0, 0, 0, 0 };

typedef struct System_Memory_Page {
    /* System_Type type; */

    System_uint pageSize;

    System_uint payload;

}  * System_Memory_Page;

/* struct_System_Type System_Memory_PageType = {
    .base = { .type = typeof(System_Type) },
    .name = "System.Memory.Page",
}; */

typedef struct System_Memory_Header {
    /* System_Type type; */

    uint length;

    uint refCount;

    Type elementType;

} * System_Memory_Header;

/* struct_System_Type System_Memory_HeaderType = {
    .base = { .type = typeof(System_Type) },
    .name = "System.Memory.Header",
}; */

System_var  System_Memory_alloc__internal(System_Type type, System_size length) {

    size real_size = sizeof(struct System_Memory_Header) + type->size * length;

    if (real_size <= 1048576 - sizeof(struct System_Memory_Page)) {
        System_var map;
        System_varArray mem64k = System_Memory_ProcessVars[0];
        if (!mem64k) {
            map = System_Syscall_mmap(4096, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
            if (!map) return null;

            mem64k = (System_varArray)map;
            mem64k->base.type = typeof(System_varArray);
            mem64k->length = (4096 - sizeof(struct_System_varArray)) / sizeof(System_var);
            mem64k->value = ((System_var)mem64k + sizeof(struct_System_varArray));
            System_Memory_ProcessVars[0] = mem64k;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("new System_varArray: length {0:uint}", 1, mem64k->length);
#endif
        }
        System_Memory_Page mem64h = null;
        for (size i = 0; i < mem64k->length; ++i) {
            mem64h = (System_Memory_Page)array(mem64k->value)[i];
            if (!mem64h) {
                map = System_Syscall_mmap(1048576, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
                if (!map) return null;

                mem64h = (System_Memory_Page)map;
                /* mem64h->type = typeof(System_Memory_Page); */
                size payload;
                size pageSize = System_Math_divideRemain__uint64(1048576 - sizeof(struct System_Memory_Page), sizeof(struct System_Memory_Header) + sizeof(struct_System_Object), &payload);
                mem64h->pageSize = (uint)pageSize;
                mem64h->payload = (uint)payload;
                array(mem64k->value)[i] = mem64h;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("new System_Memory_Page: pageSize {0:uint}, payload {1:uint}", 2, mem64h->pageSize, mem64h->payload);
#endif
            }
            else {
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("using System_Memory_Page: pageSize {0:uint}, payload {1:uint}", 2, mem64h->pageSize, mem64h->payload);
#endif
            }

            /* NOW lookup for freedom */

            System_Memory_Header item = (System_Memory_Header)((System_var)mem64h + sizeof(struct System_Memory_Page));

            size index = 0;
            while (++index, (System_var)item < ((System_var)mem64h + (1048576 - mem64h->payload))) {

                /* expect first if this is unfree, move next */
                if (item->refCount) {
                    item += item->length;
                    continue;
                }
                /* expect second if this is free, if there is not enough space, move next */
                if (item->length && !item->elementType) {
                    if (item->length != real_size && item->length < real_size + sizeof(struct System_Memory_Header)) {
                        item += item->length;
                        continue;
                    }
                    /* create a new free header for empty space, change lengths */
                    item->elementType = type;
                    item->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("using System_Memory_Header({0:uint}): length {1:uint}, refCount {2:uint}, elementType {3:string}", 4, index, item->length, item->refCount, item->elementType->name);
#endif
                    return ((System_var)item + sizeof(struct System_Memory_Header));
                }
                /* expect null, if there is not enough space, move next */
                assert(!item->length)
                /* item->type = typeof(System_Memory_Header); */
                item->length = real_size;
                item->elementType = type;
                item->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("new System_Memory_Header({0:uint}): length {1:uint}, refCount {2:uint}, elementType {3:string}", 4, index, item->length, item->refCount, item->elementType->name);
#endif
                return ((System_var)item + sizeof(struct System_Memory_Header));
            }
        }
    }

    return null; /* TODO */
}

System_Object  System_Memory_allocClass(System_Type type) {
	assert(type)
    assert(type->size);

#if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocClass: type {0:string}, size {1:uint}", 2, type->name, type->size);
#endif

	System_Object that = (System_Object)System_Memory_alloc__internal(type, 1);
	that->type = type;
	that->bitConfig.isAllocated = true;

	return that;
}

System_Object  System_Memory_addReference(System_Object that) {
    if (!that->bitConfig.isAllocated) return that;

    System_Memory_Header header = ((System_var)that - sizeof(struct System_Memory_Header));
	++header->refCount;
    return that;
}

void  System_Memory_freeClass(System_Object * thatPtr) {
	assert(thatPtr)
	Object that = *thatPtr;
	assert(that)

	System_Type type = that->type;
    System_Memory_Header header = ((System_var)that - sizeof(struct System_Memory_Header));

	assert(header->refCount >= System_Memory_ReferenceState_Used)
	if (--header->refCount >= System_Memory_ReferenceState_Used) goto return_free;

	header->refCount = System_Memory_ReferenceState_Disposing;

    /* System_Object_free(that): */
    function_Object_free free = (function_Object_free)Type_getMethod(type, base_System_Object_free);
	if (free) free(that);

	header->refCount = System_Memory_ReferenceState_Disposed;

	if (that->bitConfig.isAllocated) {
#if DEBUG == DEBUG_System_Memory
		if (that->bitConfig.isValueAllocated)
			Console_writeLine("System_Memory_freeClass: type {0:string}, bitConfig.isAllocated, bitConfig.isValueAllocated", 1, type->name);
		else
			Console_writeLine("System_Memory_freeClass: type {0:string}, bitConfig.isAllocated", 1, type->name);
#endif

		/* if MultiThreading, this should be done by System_GC */

        size length = header->length;
        System_Memory_zero(header, sizeof(struct System_Memory_Header) + type->size);
        /* header->type = typeof(System_Memory_Header); */
        header->length = length;

        /* TODO cleanup here? */
	}

#if DEBUG == DEBUG_System_Memory
	else {
		if (that->bitConfig.isValueAllocated)
			Console_writeLine("System_Memory_freeClass: type {0:string}, bitConfig.isValueAllocated", 1, type->name);
		else
			Console_writeLine("System_Memory_freeClass: type {0:string}", 1, type->name);
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
