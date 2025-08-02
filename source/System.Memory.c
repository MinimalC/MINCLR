/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_UInt8)
#include <min/System.Integers.auto.h>
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
#if !defined(have_System_Directory)
#include <min/System.Directory.h>
System_String8 System_Directory_current;
#endif
#if !defined(code_System_Memory)
#define code_System_Memory

/** class System_Memory  **/

struct System_Type System_MemoryType = { .base = { .type = typeof(System_Type) }, .name = "Memory" };

SSize System_Memory_indexOf(Var ptr, Char8 needle, Size count) {

    SSize i = 0;
    String8 ptrBytes = (String8)ptr;
    do {
        if (*ptrBytes++ == needle) return i;
    } while (++i < count);
    return -1;
}

void System_Memory_clear(Var dest, Size count) {

    Size n = count;
    String8 destBytes = (String8)dest;
    do {
        *destBytes++ = 0;
    } while (--n);
}

void System_Memory_copyTo(Var src, Size count, Var dest) {
    Size n = count;
    String8 destBytes = (String8)dest;
    String8 srcBytes = (String8)src;
    if ( srcBytes < destBytes ) {
        destBytes += (n - 1);
        srcBytes += (n - 1);
        while (n--) *destBytes-- = *srcBytes--;
    }
    else
        while (n--) *destBytes++ = *srcBytes++;
}

void System_Memory_moveTo(Var src, Size count, Var dest) {
    Size n = count;
    String8 destBytes = (String8)dest;
    String8 srcBytes = (String8)src;
    if ( srcBytes < destBytes ) {
        destBytes += (n - 1);
        srcBytes += (n - 1);
        while (n--) { *destBytes-- = *srcBytes; *srcBytes-- = 0; }
    }
    else
        while (n--) { *destBytes++ = *srcBytes; *srcBytes++ = 0; }
}

void System_Memory_set(Var dest, Char8 src, Size length) {

    Size n = length;
    String8 destBytes = (String8)dest;
    do {
        *destBytes++ = src;
    } while (--n);
}

Size System_Memory_compare(Var ptr0, Var ptr1, Size length) {

    Size count = 0;
    Size n = length;
    String8 ptr0Bytes = (String8)ptr0;
    String8 ptr1Bytes = (String8)ptr1;
    do {
        if (*ptr0Bytes != *ptr1Bytes) return count;
        ++count;
        ++ptr0Bytes;
        ++ptr1Bytes;
    } while (--n);

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

    UInt refCount;

    Type elementType;

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

export System_Var  System_Memory_ProcessVars[] = { 0, 0, 0, 0 };

export thread System_Var  System_Memory_ThreadVars[] = { 0, 0, 0, 0 };

System_Var  System_Memory_alloc__internal_min_i_max(System_Type type, System_Size length, System_Size min, System_Size index, System_Size max) {

    System_Size real_size = sizeof(struct System_Memory_Header) + type->size * length;

    System_Var map;
    System_VarArray mem64k;
    mem64k = System_Memory_ProcessVars[index];
    if (!mem64k) {
        map = System_Syscall_mmap(min, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous);
        if (!map) return null;

        mem64k = (System_VarArray)map;
        mem64k->base.type = typeof(System_VarArray);
        mem64k->length = (min - sizeof(struct System_VarArray)) / sizeof(System_Var);
        mem64k->value = ((System_Var)mem64k + sizeof(struct System_VarArray));
        System_Memory_ProcessVars[index] = mem64k;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("System_Memory_ProcessVars({0:uint}): new length {1:uint}", 2, index, mem64k->length);
#endif
    }
    System_Memory_Page mem64h = null;
    for (System_Size i = 0; i < mem64k->length; ++i) {
        mem64h = (System_Memory_Page)array(mem64k->value)[i];
        if (!mem64h) {
            map = System_Syscall_mmap(max, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous);
            if (!map) return null;

            mem64h = (System_Memory_Page)map;
#if DEBUG == DEBUG_System_Memory
            System_Size payload;
            System_Size pageSize = System_UInt64_divRem(max - sizeof(struct System_Memory_Page), sizeof(struct System_Memory_Header) + sizeof(struct System_Object), &payload);
#endif
            mem64h->length = max;
            array(mem64k->value)[i] = mem64h;
#if DEBUG == DEBUG_System_Memory
            mem64h->type = typeof(System_Memory_Page);
System_Console_writeLine("System_Memory_Page({0:uint}): new length {1:uint}, pageSize {2:uint}, payload {3:uint}", 4, i, max, pageSize, payload);
#endif
        }

        /* NOW lookup for freedom */

#if DEBUG == DEBUG_System_Memory
        System_Size index1 = 0;
#endif
        System_Var var, position = ((System_Var)mem64h + sizeof(struct System_Memory_Page));
        while (position < ((System_Var)mem64h + mem64h->length)) {
            System_Memory_Header header = (System_Memory_Header)position;

            /* expect first if this is unfree, move next */
            if (header->length && header->refCount) {
#if DEBUG == DEBUG_System_Memory
                Console_assert(header->type == typeof(System_Memory_Header));
#endif
                Console_assert(header->elementType);
                position += header->length;
#if DEBUG == DEBUG_System_Memory
                ++index1;
#endif
                continue;
            }
            /* expect second if this is free, if there is not enough space, move next */
            if (header->length && !header->elementType) {
                if (header->length != real_size && header->length < real_size + sizeof(struct System_Memory_Header)) {
                    position += header->length;
#if DEBUG == DEBUG_System_Memory
                    ++index1;
#endif
                    continue;
                }
                /* create a new free header for empty space, change lengths */
                header->elementType = type;
                header->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("System_Memory_Header({0:uint}): using typeof({1:string}), length {2:uint}", 3, index1, header->elementType->name, header->length);
#endif
                var = (position + sizeof(struct System_Memory_Header));
                if (System_Type_isAssignableFrom(type, typeof(System_Object))) {
#if DEBUG == DEBUG_System_Memory
                    System_Console_writeLine("System_Type_isAssignableFrom({0:string}, System_Object)", 1, type->name);
#endif
                    for (System_Size vi = 0; vi < length; ++vi)
                        ((System_Object)(var + vi * type->size))->type = type;
                }
                return var;
            }
            /* expect null, if there is not enough space, move next */
            Console_assert(!header->length);
            if (((System_Var)mem64h + mem64h->length) - position < real_size) break;
            header->length = real_size;
            header->elementType = type;
            header->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
            Console_assert(!header->type);
            header->type = typeof(System_Memory_Header);
System_Console_writeLine("System_Memory_Header({0:uint}): new typeof({1:string}), length {2:uint}", 4, index1, header->elementType->name, header->length);
#endif
            var = (position + sizeof(struct System_Memory_Header));
            if (System_Type_isAssignableFrom(type, typeof(System_Object))) {
#if DEBUG == DEBUG_System_Memory
                System_Console_writeLine("System_Type_isAssignableFrom({0:string}, System_Object)", 1, type->name);
#endif
                for (System_Size vi = 0; vi < length; ++vi)
                    ((System_Object)(var + vi * type->size))->type = type;
            }
            return var;
        }
    }

    return null; /* TODO */
}

System_Var  System_Memory_alloc__internal(System_Type type, System_Size length) {

    System_Size real_size = sizeof(struct System_Memory_Header) + type->size * length;

    if (real_size <= 4194304 - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max(type, length, 1024, 0, 4194304);
    if (real_size <= 8388608 - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max(type, length, 512, 1, 8388608);
    if (real_size <= 0xFFFFFFFFU - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max(type, length, 64, 2, 0xFFFFFFFFU);

    return null; /* TODO */
}

System_Size System_Memory_debug__min_i_max(System_Size min, System_Size index, System_Size max) {
    System_Size unfree = 0;

    System_VarArray mem64k;
    mem64k = System_Memory_ProcessVars[index];
    if (!mem64k) return 0;

    System_Memory_Page mem64h = null;
    for (System_Size i = 0; i < mem64k->length; ++i) {
        mem64h = (System_Memory_Page)array(mem64k->value)[i];
        if (!mem64h) continue;

        /* NOW lookup for unfreed */

        System_Size index1 = 0;
        Var position = ((System_Var)mem64h + sizeof(struct System_Memory_Page));
        while (position < ((System_Var)mem64h + mem64h->length)) {
            System_Memory_Header header = (System_Memory_Header)position;
            System_Var item = position + sizeof(struct System_Memory_Header);

            if (header->refCount && header->elementType) {

                /* LIE about that */
                if (System_Exception_current) {
                    if (item == System_Exception_current) goto continue_position;
                    if (item == System_Exception_current->message) goto continue_position;
                }
                if (System_Directory_current)
                    if (item == System_Directory_current) goto continue_position;

                ++unfree;
                System_Console_write__string(header->elementType->name);
                if (header->length > sizeof(struct System_Memory_Header) + header->elementType->size * 1) 
                    System_Console_write__string("[]");
                System_Console_write__string(", ");

                goto continue_position;
            }
            if (header->length && !header->elementType)
                goto continue_position;

            Console_assert(!header->length);
            break;

        continue_position:
            position += header->length;
            ++index1;
        }
    }
    return unfree;
}

void System_Memory_debug(void) {
    System_Size unfree = 0;
    unfree += System_Memory_debug__min_i_max(1024, 0, 4194304);
    unfree += System_Memory_debug__min_i_max(512, 1, 8388608);
    unfree += System_Memory_debug__min_i_max(64, 2, 0xFFFFFFFFU);
    if (unfree) System_Console_writeLine("System_Memory_debug: {0:uint} unfreed.", 1, unfree);
}

System_Var  System_Memory_allocClass(System_Type type) {
	Console_assert(type);
    Console_assert(type->size);

    #if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocClass: type {0:string}, size {1:uint}", 2, type->name, type->size);
    #endif

	System_Object that = System_Memory_alloc__internal(type, 1);
    if (System_Type_isAssignableFrom(type, typeof(System_Object)))
        that->type = type;
	return that;
}

System_Var  System_Memory_allocArray(System_Type type, System_Size count) {
	Console_assert(type);
    Console_assert(type->size);

    #if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocArray: type {0:string}, size {1:uint}, count {2:uint}", 3, type->name, type->size, count);
    #endif

	return System_Memory_alloc__internal(type, count);
}

System_Bool System_Memory_isAllocated(System_Var that) {
    Console_assert(that);

    static System_Size indexL = sizeof_array(System_Memory_ProcessVars);

    System_Var * vars;
    vars = System_Memory_ProcessVars;

    for (System_Size index = 0; index < indexL; ++index) {
        System_VarArray mem64k = vars[index];
        if (!mem64k) continue;

        for (System_Size i = 0; i < mem64k->length; ++i) {
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
	Console_assert(thatPtr);
    if (!thatPtr) return;
    System_Var that = *thatPtr;
	Console_assert(that);
    if (!that) return;

    if (!Memory_isAllocated(that)) {
        #if DEBUG == DEBUG_System_Memory
        System_Console_writeLine__string("System_Memory_freeClass: not Memory_isAllocated, try using System_Memory_freeStruct instead");
        #endif
        goto return_free; 
    }

    System_Memory_Header header = ((System_Var)that - sizeof(struct System_Memory_Header));
    #if DEBUG == DEBUG_System_Memory
	Console_assert(header->type == typeof(System_Memory_Header));
    #endif

	if (header->refCount < System_Memory_ReferenceState_Used) {
        #if DEBUG
        System_Console_writeLine("System_Memory_freeClass: typeof({0:string}): header->refCount < System_Memory_ReferenceState_Used", 1, header->elementType->name);
        #endif
        goto return_free;
    }
	if (--header->refCount >= System_Memory_ReferenceState_Used)
        goto return_free;

    header->refCount = System_Memory_ReferenceState_Disposing;
    System_Memory_freeStruct(that, header->elementType);
    header->refCount = System_Memory_ReferenceState_Disposed;

    /* if MultiThreading, this should be done by System_GC */

    System_Size length = header->length;
    System_Memory_clear(header, length);
    header->length = length;
    #if DEBUG == DEBUG_System_Memory
    header->type = typeof(System_Memory_Header);
    #endif

return_free:
    *thatPtr = null;
}

void  System_Memory_freeStruct(System_Var that, System_Type type) {
	Console_assert(that);
    if (!that) return;
	Console_assert(type);
    if (!type) return;

    function_System_Object_free free = (function_System_Object_free)Type_tryMethod(type, base_System_Object_free);
    if (free && free != base_System_Object_free) {
        #if DEBUG == DEBUG_System_Memory
        System_Console_writeLine("System_Memory_freeStruct: {0:string} typeof({1:string})", 2, 
            System_Type_isAssignableFrom(type, typeof(System_Object)) ? "class" : "struct",
            type->name);
        #endif
        free((System_Object)that);
    }
    #if DEBUG == DEBUG_System_Memory
    else System_Console_writeLine("System_Memory_freeStruct: {0:string} typeof({1:string}): function_System_Object_free not found", 2, 
        System_Type_isAssignableFrom(type, typeof(System_Object)) ? "class" : "struct",
        type->name);
    #endif
}

#endif
