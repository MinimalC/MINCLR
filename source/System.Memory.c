/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
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
#if !defined(have_System_VarArray)
#include <min/System.VarArray.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(code_System_Memory)
#define code_System_Memory

/*# System_Memory #*/

struct System_Type System_MemoryType = { .base = { .type = typeof(System_Type) }, .name = "Memory" };

SSize System_Memory_indexOf(Var ptr, Char8 needle, Size count) {
    Debug_assert(count);

    SSize i = 0;
    Char8 *ptrBytes = (Char8 *)ptr;
    do {
        ++i;
        if (*ptrBytes++ == needle) return i;

    } while (--count);
    return -1;
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

typedef struct System_Memory_Page {
#if DEBUG == DEBUG_System_Memory
    System_Type type;
#endif

    Size length;

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
struct System_Type  System_Memory_PageType = {
    .base = { .type = typeof(System_Type) },
    .name = "Memory.Page",
    .size = sizeof(struct System_Memory_Page),
};
struct System_Type  System_Memory_HeaderType = {
    .base = { .type = typeof(System_Type) },
    .name = "Memory.Header",
    .size = sizeof(struct System_Memory_Header),
};
#endif

internal System_Var  System_Memory_ProcessVars[] = { 0, 0, 0, 0 };

System_Var  System_Memory_alloc__internal_min_i_max(System_Type type, System_Size length, System_Size min, System_Size index, System_Size max) {

    Size real_size = sizeof(struct System_Memory_Header) + type->size * length;

    System_Var map;
    System_VarArray mem64k = System_Memory_ProcessVars[index];
    if (!mem64k) {
        map = System_Syscall_mmap(min, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous);
        if (!map) return null;

        mem64k = (System_VarArray)map;
        mem64k->base.type = typeof(System_VarArray);
        mem64k->length = (min - sizeof(struct System_VarArray)) / sizeof(System_Var);
        mem64k->value = ((System_Var)mem64k + sizeof(struct System_VarArray));
        System_Memory_ProcessVars[index] = mem64k;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("new System_Memory_ProcessVars({0:uint}): length {1:uint}", 2, index, mem64k->length);
#endif
    }
    System_Memory_Page mem64h = null;
    for (Size i = 0; i < mem64k->length; ++i) {
        mem64h = (System_Memory_Page)array(mem64k->value)[i];
        if (!mem64h) {
            map = System_Syscall_mmap(max, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous);
            if (!map) return null;

            mem64h = (System_Memory_Page)map;
            Size payload;
            Size pageSize = System_Math_divRem__UInt64(max - sizeof(struct System_Memory_Page), sizeof(struct System_Memory_Header) + sizeof(struct System_Object), &payload);
            mem64h->length = max;
            array(mem64k->value)[i] = mem64h;
#if DEBUG == DEBUG_System_Memory
            mem64h->type = typeof(System_Memory_Page);
System_Console_writeLine("new System_Memory_Page({0:uint}): pageSize {1:uint}, payload {2:uint}", 3, i, pageSize, payload);
        }
        else {
System_Console_writeLine("using System_Memory_Page({0:uint}): pageSize {1:uint}, payload {2:uint}", 3, i, pageSize, payload);
#endif
        }

        /* NOW lookup for freedom */

        Size index1 = 0;
        Var position = ((System_Var)mem64h + sizeof(struct System_Memory_Page));
        while (position < ((System_Var)mem64h + mem64h->length)) {
            System_Memory_Header header = (System_Memory_Header)position;

            /* expect first if this is unfree, move next */
            if (header->refCount) {
#if DEBUG == DEBUG_System_Memory
                Debug_assert(header->type == typeof(System_Memory_Header));
#endif
                Debug_assert(header->length);
                Debug_assert(header->elementType);
                position += header->length;
                ++index1;
                continue;
            }
            /* expect second if this is free, if there is not enough space, move next */
            if (header->length && !header->elementType) {
                if (header->length != real_size && header->length < real_size + sizeof(struct System_Memory_Header)) {
                    position += header->length;
                    ++index1;
                    continue;
                }
                /* create a new free header for empty space, change lengths */
                header->elementType = type;
                header->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("using System_Memory_Header({0:uint}): length {1:uint}, refCount {2:uint}, elementType {3:string}", 4, index1, header->length, header->refCount, header->elementType->name);
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
System_Console_writeLine("new System_Memory_Header({0:uint}): length {1:uint}, refCount {2:uint}, elementType {3:string}", 4, index1, header->length, header->refCount, header->elementType->name);
#endif
            return (position + sizeof(struct System_Memory_Header));
        }
    }

    return null; /* TODO */
}

System_Var  System_Memory_alloc__internal(System_Type type, System_Size length) {

    Size real_size = sizeof(struct System_Memory_Header) + type->size * length;

    if (real_size <= 4194304 - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max(type, length, 1024, 0, 4194304);
    if (real_size <= 8388608 - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max(type, length, 512, 1, 8388608);
    if (real_size <= 0xFFFFFFFFU - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max(type, length, 64, 2, 0xFFFFFFFFU);

    return null; /* TODO */
}

Size System_Memory_debug__min_i_max(System_Size min, System_Size index, System_Size max) {
    Size unfree = 0;

    System_VarArray mem64k = System_Memory_ProcessVars[index];
    if (!mem64k) return 0;

    System_Memory_Page mem64h = null;
    for (Size i = 0; i < mem64k->length; ++i) {
        mem64h = (System_Memory_Page)array(mem64k->value)[i];
        if (!mem64h) continue;

        /* NOW lookup for unfreed */

        Size index1 = 0;
        Var position = ((System_Var)mem64h + sizeof(struct System_Memory_Page));
        while (position < ((System_Var)mem64h + mem64h->length)) {
            System_Memory_Header header = (System_Memory_Header)position;
            System_Var item = position + sizeof(struct System_Memory_Header);

            if (header->refCount && header->elementType) {

                if (item != System_Exception_current) {
                    /* LIE about that one */
                    ++unfree;
                    System_Console_write("{0:string}", 1, header->elementType->name);
                    if (header->length > sizeof(struct System_Memory_Header) + header->elementType->size * 1) 
                        System_Console_write__string("[]");
                    System_Console_write__string(", ");
                }

                position += header->length;
                ++index1;
                continue;
            }
            if (header->length && !header->elementType) {
                position += header->length;
                ++index1;
                continue;
            }
            Debug_assert(!header->length);
            break;
        }
    }
    return unfree;
}

void System_Memory_debug(void) {
    Size unfree = 0;
    unfree += System_Memory_debug__min_i_max(1024, 0, 4194304);
    unfree += System_Memory_debug__min_i_max(512, 1, 8388608);
    unfree += System_Memory_debug__min_i_max(64, 2, 0xFFFFFFFFU);
    if (unfree) System_Console_writeLine("System_Memory_debug: {0:uint} unfreed.", 1, unfree);
}

System_Var  System_Memory_allocClass(System_Type type) {
	Debug_assert(type);
    Debug_assert(type->size);

#if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocClass: type {0:string}, size {1:uint}", 2, type->name, type->size);
#endif

	System_Object that = System_Memory_alloc__internal(type, 1);
    if (System_Type_isAssignableFrom(type, typeof(System_Object)))
        that->type = type;
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

    static Size indexL = sizeof_array(System_Memory_ProcessVars);

    for (Size index = 0; index < indexL; ++index) {
        System_VarArray mem64k = System_Memory_ProcessVars[index];
        if (!mem64k) continue;

        for (Size i = 0; i < mem64k->length; ++i) {
            System_Memory_Page mem64h = (System_Memory_Page)array(mem64k->value)[i];
            if (!mem64h) continue;

            if (that >= (System_Var)mem64h && (System_Size)that < (System_Size)mem64h + mem64h->length) return true;
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
    System_Console_writeLine__string("System_Memory_reallocArray not implemented");
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
        function_System_Object_free free = (function_System_Object_free)Type_tryMethod(object->type, base_System_Object_free);
        if (free) free(object);
#if DEBUG
        else System_Console_writeLine("System_Memory_freeClass: function_System_Object_free not found in typeof({0:string}).", 1, header->elementType->name);
#endif

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

#endif
