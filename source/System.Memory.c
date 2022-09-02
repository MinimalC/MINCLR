/* Gemeinfrei. Public Domain. */
#if !defined(internal_System)
#include "internal.System.h"
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
#if !defined(have_System_VarArray)
#include <min/System.VarArray.h>
#endif
/* WARNING: DEBUG: TODO */
#if !defined(have_ISO)
#define using_ISO
#include <min/ISO.h>
#endif
#if !defined(code_System_Memory)
#define code_System_Memory

/*# System_Memory #*/

struct System_Type  System_MemoryType = { .base = stack_System_Object(System_Type),
	.name = "Memory",
};

Size System_Memory_indexOf(Var ptr, Char8 needle, Size count) {
    Debug_assert(count);

    Size i = 0;
    Char8 *ptrBytes = (Char8 *)ptr;
    do {
        ++i;
        if (*ptrBytes == needle) return i;
        if (--count == 0) break;
        ++ptrBytes;
    } while (true);

    return 0;
}

void System_Memory_zero(Var dest, Size n) {
    Debug_assert(n);

    Char8 *destBytes = (Char8 *)dest;
    do {
        *destBytes = 0x00;
        if (--n == 0) break;
        ++destBytes;
    } while (true);
}

void System_Memory_copyTo(Var src, Size n, Var dest) {
    Char8 *destBytes = (Char8 *)dest;
    Char8 *srcBytes = (Char8 *)src;
    if ( srcBytes < destBytes ) {
        destBytes += (n - 1);
        srcBytes += (n - 1);
        while (n--) *destBytes-- = *srcBytes--;
    }
    else
        while (n--) *destBytes++ = *srcBytes++;
}

void System_Memory_moveTo(Var src, Size n, Var dest) {
    Char8 *destBytes = (Char8 *)dest;
    Char8 *srcBytes = (Char8 *)src;
    if ( srcBytes < destBytes ) {
        destBytes += (n - 1);
        srcBytes += (n - 1);
        while (n--) { *destBytes-- = *srcBytes; *srcBytes-- = 0; }
    }
    else
        while (n--) { *destBytes++ = *srcBytes; *srcBytes++ = 0; }
}

void System_Memory_set(Var dest, Char8 src, Size length) {
    Debug_assert(length);

    Char8 *destBytes = (Char8 *)dest;
    do {
        *destBytes = src;
        if (--length == 0) break;
        ++destBytes;
    } while (true);
}

Size System_Memory_compare(Var ptr0, Var ptr1, Size length) {
    Debug_assert(length);

    Size count = 0;
    Char8 *ptr0Bytes = (Char8 *)ptr0;
    Char8 *ptr1Bytes = (Char8 *)ptr1;
    do {
        if (*ptr0Bytes != *ptr1Bytes) return count;
        ++count;
        if (--length == 0) break;
        ++ptr0Bytes;
        ++ptr1Bytes;
    } while (true);

    return count;
}

Bool System_Memory_equals(Var ptr0, Var ptr1, Size length) {
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

internal System_Var  System_Memory_ProcessVars[] = { 0, 0, 0, 0 };

typedef struct System_Memory_Page {
#if DEBUG == DEBUG_System_Memory
    System_Type type;
#endif

    UInt pageSize;

    UInt payload;

}  * System_Memory_Page;

typedef struct System_Memory_Header {
#if DEBUG == DEBUG_System_Memory
    System_Type type;
#endif

    UInt length;

    Type elementType;

    UInt refCount;

} * System_Memory_Header;

#if DEBUG == DEBUG_System_Memory
struct System_Type System_Memory_PageType = {
    .base = { .type = typeof(System_Type) },
    .name = "Memory.Page",
};
struct System_Type System_Memory_HeaderType = {
    .base = { .type = typeof(System_Type) },
    .name = "Memory.Header",
};
#endif

System_Var  System_Memory_alloc__internal(System_Type type, System_Size length) {

    Size real_size = sizeof(struct System_Memory_Header) + type->size * length;

    if (real_size <= 1048576 - sizeof(struct System_Memory_Page)) {
        System_Var map;
        System_VarArray mem64k = System_Memory_ProcessVars[0];
        if (!mem64k) {
            map = System_Syscall_mmap(4096, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
            if (!map) return null;

            mem64k = (System_VarArray)map;
            mem64k->base.type = typeof(System_VarArray);
            mem64k->length = (4096 - sizeof(struct System_VarArray)) / sizeof(System_Var);
            mem64k->value = ((System_Var)mem64k + sizeof(struct System_VarArray));
            System_Memory_ProcessVars[0] = mem64k;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("new System_VarArray: length {0:uint}", 1, mem64k->length);
#endif
        }
        System_Memory_Page mem64h = null;
        for (Size i = 0; i < mem64k->length; ++i) {
            mem64h = (System_Memory_Page)array(mem64k->value)[i];
            if (!mem64h) {
                map = System_Syscall_mmap(1048576, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous, null, 0);
                if (!map) return null;

                mem64h = (System_Memory_Page)map;
                Size payload;
                Size pageSize = System_Math_divRem__UInt64(1048576 - sizeof(struct System_Memory_Page), sizeof(struct System_Memory_Header) + sizeof(struct System_Object), &payload);
                mem64h->pageSize = (UInt)pageSize;
                mem64h->payload = (UInt)payload;
                array(mem64k->value)[i] = mem64h;
#if DEBUG == DEBUG_System_Memory
                mem64h->type = typeof(System_Memory_Page);
System_Console_writeLine("new System_Memory_Page: pageSize {0:uint}, payload {1:uint}", 2, mem64h->pageSize, mem64h->payload);
            }
            else {
System_Console_writeLine("using System_Memory_Page: pageSize {0:uint}, payload {1:uint}", 2, mem64h->pageSize, mem64h->payload);
#endif
            }

            /* NOW lookup for freedom */

            Size index = 0;
            Var position = ((System_Var)mem64h + sizeof(struct System_Memory_Page));
            while (++index, position < ((System_Var)mem64h + (1048576 - mem64h->payload))) {
                System_Memory_Header header = (System_Memory_Header)position;

                /* expect first if this is unfree, move next */
                if (header->refCount) {
#if DEBUG == DEBUG_System_Memory
                    Debug_assert(header->type == typeof(System_Memory_Header));
#endif
                    Debug_assert(header->length);
                    Debug_assert(header->elementType);
                    position += header->length;
                    continue;
                }
                /* expect second if this is free, if there is not enough space, move next */
                if (header->length && !header->elementType) {
                    if (header->length != real_size && header->length < real_size + sizeof(struct System_Memory_Header)) {
                        position += header->length;
                        continue;
                    }
                    /* create a new free header for empty space, change lengths */
                    header->elementType = type;
                    header->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("using System_Memory_Header({0:uint}): length {1:uint}, refCount {2:uint}, elementType {3:string}", 4, index, header->length, header->refCount, header->elementType->name);
#endif
                    return (position + sizeof(struct System_Memory_Header));
                }
                /* expect null, if there is not enough space, move next */
                Debug_assert(!header->length);
                header->length = real_size;
                header->elementType = type;
                header->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
                Debug_assert(!header->type);
                header->type = typeof(System_Memory_Header);
System_Console_writeLine("new System_Memory_Header({0:uint}): length {1:uint}, refCount {2:uint}, elementType {3:string}", 4, index, header->length, header->refCount, header->elementType->name);
#endif
                return (position + sizeof(struct System_Memory_Header));
            }
        }
    }

    return null; /* TODO */
}

System_Var  System_Memory_allocClass(System_Type type) {
	Debug_assert(type);
    Debug_assert(type->size);

#if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocClass: type {0:string}, size {1:uint}", 2, type->name, type->size);
#endif

	Var that = System_Memory_alloc__internal(type, 1);
    if (System_Type_isAssignableFrom(type, typeof(System_Object))) {
        System_Object object = (System_Object)that;
        object->type = type;
    }
	return that;
}

System_Var  System_Memory_allocArray(System_Type type, System_Size count) {
	Debug_assert(type);
    Debug_assert(type->size);

#if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocArray: type {0:string}, size {1:uint}, count {2:uint}", 3, type->name, type->size, count);
#endif

	return System_Memory_alloc__internal(type, count);
}

Bool System_Memory_isAllocated(Var that) {
    Debug_assert(that);

    static const Size memory_length = sizeof_array(System_Memory_ProcessVars);

    System_VarArray memory;
    for (Size i = 0; i < memory_length; ++i) {
        memory = System_Memory_ProcessVars[i];
        if (memory) {
            Var page = 0;
            for (Size i = 0; i < memory->length; ++i) {
                page = array(memory->value)[i];
                if (page && that >= page && that < page + 1048576) return true;
            }
        }
    }
    return false;
}


System_Var  System_Memory_addReference(System_Var that) {
    if (!Memory_isAllocated(that)) return that;

    System_Memory_Header header = ((System_Var)that - sizeof(struct System_Memory_Header));
	++header->refCount;
    return that;
}

void System_Memory_reallocArray(System_Var ref that, System_Size count) {
    /* TODO */
}

void  System_Memory_freeClass(System_Var ref thatPtr) {
	Debug_assert(thatPtr);
    Var that = *thatPtr;
	Debug_assert(that);

    if (!Memory_isAllocated(that)) return;

    System_Memory_Header header = ((System_Var)that - sizeof(struct System_Memory_Header));
#if DEBUG == DEBUG_System_Memory
	Debug_assert(header->type == typeof(System_Memory_Header));
#endif

	Debug_assert(header->refCount >= System_Memory_ReferenceState_Used);
	if (--header->refCount >= System_Memory_ReferenceState_Used) goto return_free;

    if (System_Type_isAssignableFrom(header->elementType, typeof(System_Object))) {

        header->refCount = System_Memory_ReferenceState_Disposing;

        Object object = (Object)that;
        function_Object_free free = (function_Object_free)Type_getMethod(object->type, base_System_Object_free);
        if (free) free(object);

        header->refCount = System_Memory_ReferenceState_Disposed;
	}

    /* if MultiThreading, this should be done by System_GC */

    Size length = header->length;
    System_Memory_zero(header, length);
    header->length = length;
#if DEBUG == DEBUG_System_Memory
    header->type = typeof(System_Memory_Header);
#endif

return_free:
    *thatPtr = null;
}


/* OLD

System_Var  System_Memory_alloc(Size length) {

    void *thatPtr = ISO_malloc(length);
    UInt8 *that = (UInt8 *)thatPtr;
    System_Memory_set(that, 0x00, length);
    return thatPtr;
}

void  System_Memory_realloc(void  ** that, Size oldLength, Size newLength) {

    UInt8  * that1 = (UInt8 *)ISO_realloc(*that, newLength);
    if (newLength > oldLength) {
        System_Memory_set(that1 + oldLength, 0x00, newLength - oldLength);
    }

    if (*that != that1) {
        *that = that1;
    }
}

void System_Memory_freeStruct(void *that) {
    Debug_assert(that);
    ISO_free(that);
}

void System_Memory_free(void **thatPtr) {
    Debug_assert(thatPtr);
    void *that = *thatPtr;
    Debug_assert(that);
    System_Memory_freeStruct(that);
    *thatPtr = null;
}
*/

#endif
