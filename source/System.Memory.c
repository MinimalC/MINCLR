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
#if !defined(have_System_Thread)
#include <min/System.Thread.h>
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
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
extern thread System_Exception System_Exception_current;
#endif
#if !defined(have_System_Directory)
#include <min/System.Directory.h>
#endif
#if !defined(code_System_Memory)
#define code_System_Memory

/** struct System_Memory  **/

struct System_Type System_MemoryType = { .base = { .type = typeof(System_Type) }, .name = "Memory" };

SSize System_Memory_indexOf(Var ptr, Size count, Char8 needle) {

    SSize i = 0;
    String8 ptrBytes = (String8)ptr;
    do {
        if (*ptrBytes++ == needle) return i;
    } while (++i < count);
    return -1;
}

SSize System_Memory_indexOf__other(Var ptr, Size count, Var needle, Size needle_count) {

    SSize i = 0;
    String8 ptrBytes = (String8)ptr;
    do {
        if (Memory_equals(ptrBytes++, needle, needle_count)) return i;
    } while (++i < count);
    return -1;
}

void System_Memory_clear(Var dest, Size count) {

    Size n = count;
    String8 destBytes = (String8)dest;
    while (n--) *destBytes++ = 0;
}

void System_Memory_copyTo(Var src, Size count, Var dest) {
    Size n = count;
    String8 destBytes = (String8)dest;
    String8 srcBytes = (String8)src;
    while (n--) *destBytes++ = *srcBytes++;
}

void System_Memory_moveTo(Var src, Size count, Var dest) {
    Size n = count;
    String8 destBytes = (String8)dest;
    String8 srcBytes = (String8)src;
    Char8 destByte = 0;
    while (n--) { destByte = *destBytes; *destBytes++ = *srcBytes; *srcBytes++ = destByte; }
}

void System_Memory_set(Var dest, Size length, Char8 src) {

    Size n = length;
    String8 destBytes = (String8)dest;
    while (n--) *destBytes++ = src;
}

Size System_Memory_compare(Var ptr0, Var ptr1, Size length) {

    Size count = 0;
    Size n = length;
    String8 ptr0Bytes = (String8)ptr0;
    String8 ptr1Bytes = (String8)ptr1;
    while (n--) {
        if (*ptr0Bytes != *ptr1Bytes) return count;
        ++count;
        ++ptr0Bytes;
        ++ptr1Bytes;
    }
    return count;
}

Bool System_Memory_equals(Var ptr0, Var ptr1, Size length) {
    return (length == System_Memory_compare(ptr0, ptr1, length));
}

void System_Memory_sort(System_Var memory, System_Size itemsCount, System_Size itemSize, function(System_Memory_comparison) comparison) {
    if (!memory) return; // throw new_NullReferenceException ?
    for (Size position = 1; position < itemsCount; ++position)
        for (Size position1 = position; position1; --position1) {
            Var position_var = memory + (position1 - 1) * itemSize;
            Var position1_var = memory + position1 * itemSize;
            SSize what = comparison(position_var, position1_var, itemSize);
            if (what <= 0) break;
            System_Memory_moveTo(position_var, itemSize, position1_var);
        }
}

System_SSize System_Memory_alphacompare(System_Var memory0, System_Var memory1, System_Size itemSize) {
    System_Size length = System_Memory_compare(memory0, memory1, itemSize);
    if (length == itemSize) return 0;
    System_String8 memory0_string = (System_String8)memory0;
    System_String8 memory1_string = (System_String8)memory1;
    System_Char8 c0 = memory0_string[length];
    System_Char8 c1 = memory1_string[length];
    return c0 - c1;
}

System_SSize System_Memory_alphacomparedescending(System_Var memory0, System_Var memory1, System_Size itemSize) {
    System_Size length = System_Memory_compare(memory0, memory1, itemSize);
    if (length == itemSize) return 0;
    System_String8 memory0_string = (System_String8)memory0;
    System_String8 memory1_string = (System_String8)memory1;
    System_Char8 c0 = memory0_string[length];
    System_Char8 c1 = memory1_string[length];
    return c1 - c0;
}

typedef struct System_Memory_Page {
#if DEBUG == DEBUG_System_Memory
    System_Type type;
#endif

    Size length;

    System_Thread_ID threadId;

    struct System_Atomic lock;

}  * System_Memory_Page;

typedef struct System_Memory_Header {
    System_Type type;

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
#endif
struct System_Type  System_Memory_HeaderType = {
    .base = { .type = typeof(System_Type) },
    .name = "Memory.Header",
    .size = sizeof(struct System_Memory_Header),
};

System_Var  System_Memory_ProcessVars[] = { 0, 0, 0, 0 };

struct System_Atomic  System_Memory_ProcessLock = { 0, 0 };

#define ROUND(X,ALIGN)  (((X) + (ALIGN - 1)) & ~(ALIGN - 1))

System_Var  System_Memory_alloc__internal_min_i_max_threadId(System_Type type, System_Size length, System_Size min, System_Size index, System_Size max, System_Thread_ID threadId) {

    System_Size real_size = ROUND(type->size * length, 8) + sizeof(struct System_Memory_Header);

    System_Bool lock = threadId != System_Thread_TID;
    System_VarArray mem64k = System_Memory_ProcessVars[index];

    System_Var map = null;
    if (!mem64k) {
        map = System_Syscall_mmap(min, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous);
        if (!map) return null; // throw

        if (lock) System_Atomic_writeLock(&System_Memory_ProcessLock);
        mem64k = (System_VarArray)map;
        mem64k->base.type = typeof(System_VarArray);
        mem64k->length = (min - sizeof(struct System_VarArray)) / sizeof(System_Var);
        mem64k->value = ((System_Var)mem64k + sizeof(struct System_VarArray));
        System_Memory_ProcessVars[index] = mem64k;
        if (lock) System_Atomic_writeUnlock(&System_Memory_ProcessLock);
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("{2:string}({0:uint}): new length {1:uint}", 3, index, mem64k->length, globally ? "System_Memory_ProcessVars" : "System_Memory_ThreadVars");
#endif
    }
    System_Memory_Page mem64h = null;
    for (System_Size i = 0; i < mem64k->length; ++i) {
        mem64h = (System_Memory_Page)array(mem64k->value)[i];
        if (mem64h && mem64h->threadId != threadId) continue;
        if (!mem64h) {
            map = System_Syscall_mmap(max, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous);
            if (!map) return null; // throw

            if (lock) System_Atomic_writeLock(&System_Memory_ProcessLock);
            mem64h = (System_Memory_Page)map;
#if DEBUG == DEBUG_System_Memory
            System_Size payload;
            System_Size pageSize = System_UInt64_divRem(max - sizeof(struct System_Memory_Page), sizeof(struct System_Memory_Header) + sizeof(System_Var), &payload);
            mem64h->type = typeof(System_Memory_Page);
#endif
            mem64h->length = max;
            mem64h->threadId = threadId;
            array(mem64k->value)[i] = mem64h;
            if (lock) System_Atomic_writeUnlock(&System_Memory_ProcessLock);
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("System_Memory_Page({0:uint}): new length {1:uint}, pageSize {2:uint}, payload {3:uint}", 4, i, max, pageSize, payload);
#endif
        }

        /* now lookup for freedom */

#if DEBUG == DEBUG_System_Memory
        System_Size index1 = 0, header1_length = 0;
#endif
        System_Var position = ((System_Var)mem64h + sizeof(struct System_Memory_Page));
        while (position + real_size < ((System_Var)mem64h + mem64h->length)) {
            System_Memory_Header header = (System_Memory_Header)position;
#if DEBUG
            if (header->type) Console_assert(header->type == typeof(System_Memory_Header));
#endif
            /* expect first if this is unfree, move next */
            if (header->length && header->refCount) {
                Console_assert(header->type == typeof(System_Memory_Header));
                Console_assert(header->elementType);
                position += sizeof(struct System_Memory_Header) + header->length;
#if DEBUG == DEBUG_System_Memory
                ++index1;
#endif
                continue;
            }
            if (header->length && !header->elementType) {
                /* collect free space */
                if (lock) System_Atomic_writeLock(&mem64h->lock);
                System_Var position2 = position + sizeof(struct System_Memory_Header) + header->length;
                while (position2 + sizeof(struct System_Memory_Header) < ((System_Var)mem64h + mem64h->length)) {
                    System_Memory_Header header2 = (System_Memory_Header)position2;
                    if (!header2->type) break;
#if DEBUG
                    Console_assert(header2->type == typeof(System_Memory_Header));
#endif
                    if (header2->length && !header2->elementType) {
                        header->length += sizeof(struct System_Memory_Header) + header2->length;
                        System_Memory_clear(header2, sizeof(struct System_Memory_Header));
                        position2 = position + sizeof(struct System_Memory_Header) + header->length;
                        continue;
                    }
                    break;
                } 
                /* expect second if this is free, if there is not enough space, move next */
                if (sizeof(struct System_Memory_Header) + header->length <= real_size + sizeof(struct System_Memory_Header) + sizeof(System_Var)) {
                    position += sizeof(struct System_Memory_Header) + header->length;
#if DEBUG == DEBUG_System_Memory
                    ++index1;
#endif
                    if (lock) System_Atomic_writeUnlock(&mem64h->lock);
                    continue;
                }
                /* create a new free header */
                System_Var position1 = position + real_size;
                if (position1 + sizeof(struct System_Memory_Header) < ((System_Var)mem64h + mem64h->length)) {
                    System_Memory_Header header1 = (System_Memory_Header)position1;
                    header1->type = typeof(System_Memory_Header);
                    header1->length = header->length - real_size;
#if DEBUG == DEBUG_System_Memory
                    header1_length = header1->length;
#endif
                }
                /* reset header */
                header->length = real_size - sizeof(struct System_Memory_Header);
                header->elementType = type;
                header->refCount = System_Memory_ReferenceState_Used;
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("System_Memory_Header({0:uint}): old {1:string} typeof({2:string}), length {3:uint}, free space {4:uint}", 5, index1, 
    System_Type_isAssignableFrom(type, typeof(System_Object)) ? "class" : "struct", header->elementType->name, header->length, header1_length);
#endif
                System_Var var1 = (position + sizeof(struct System_Memory_Header));
                if (System_Type_isAssignableFrom(type, typeof(System_Object))) {
                    for (System_Size vi = 0; vi < length; ++vi)
                        ((System_Object)(var1 + vi * type->size))->type = type;
                }
                if (lock) System_Atomic_writeUnlock(&mem64h->lock);
                return var1;
            }
            /* expect null */
            Console_assert(!header->length);

            /* create a new header */
            if (lock) System_Atomic_writeLock(&mem64h->lock);
            header->length = real_size - sizeof(struct System_Memory_Header);
            header->elementType = type;
            header->refCount = System_Memory_ReferenceState_Used;
            header->type = typeof(System_Memory_Header);
         // System_Syscall_mprotect(header, sizeof(System_Var), System_Memory_PageFlags_Read);
#if DEBUG == DEBUG_System_Memory
System_Console_writeLine("System_Memory_Header({0:uint}): new {1:string} typeof({2:string}), length {3:uint}", 4, index1, 
    System_Type_isAssignableFrom(type, typeof(System_Object)) ? "class" : "struct", header->elementType->name, header->length);
#endif
            System_Var var0 = (position + sizeof(struct System_Memory_Header));
            if (System_Type_isAssignableFrom(type, typeof(System_Object))) {
                for (System_Size vi = 0; vi < length; ++vi)
                    ((System_Object)(var0 + vi * type->size))->type = type;
            }
            if (lock) System_Atomic_writeUnlock(&mem64h->lock);
            return var0;
        }
    }

    return null; /* TODO: throw */
}

System_Var  System_Memory_alloc__internal_threadId(System_Type type, System_Size length, System_Thread_ID threadId) {

    System_Size real_size = ROUND(type->size * length, 8) + sizeof(struct System_Memory_Header);
    
    if (real_size <= 4194304 - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max_threadId(type, length, 1024, 0, 4194304, threadId);
    if (real_size <= 8388608 - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max_threadId(type, length, 512, 1, 8388608, threadId);
    if (real_size <= 0xFFFFFFFFU - sizeof(struct System_Memory_Page))
        return System_Memory_alloc__internal_min_i_max_threadId(type, length, 64, 2, 0xFFFFFFFFU, threadId);

    return null; /* TODO: throw */
}

System_Var  System_Memory_allocClass__threadId(System_Type type, System_Thread_ID threadId) {
	Console_assert(type);
    Console_assert(type->size);

    #if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocClass: typeof({0:string}), sizeof({1:uint}), threadId {2:int32}", 3, type->name, type->size, threadId);
    #endif

	return System_Memory_alloc__internal_threadId(type, 1, threadId);
}

System_Var  System_Memory_allocClass(System_Type type) {
	return System_Memory_allocClass__threadId(type, System_Thread_TID);
}

System_Var  System_Memory_allocStaticClass(System_Type type, System_Size count) {
	return System_Memory_allocClass__threadId(type, System_Thread_PID);
}

System_Var  System_Memory_allocArray__threadId(System_Type type, System_Size count, System_Thread_ID threadId) {
	Console_assert(type);
    Console_assert(type->size);

    #if DEBUG == DEBUG_System_Memory
	Console_writeLine("System_Memory_allocArray: typeof({0:string}), sizeof({1:uint}), count {2:uint}, threadId {3:int32}", 4, type->name, type->size, count, threadId);
    #endif

	return System_Memory_alloc__internal_threadId(type, count, threadId);
}

System_Var  System_Memory_allocArray(System_Type type, System_Size count) {
	return System_Memory_allocArray__threadId(type, count, System_Thread_TID);
}

System_Var  System_Memory_allocStaticArray(System_Type type, System_Size count) {
	return System_Memory_allocArray__threadId(type, count, System_Thread_PID);
}

System_Size System_Memory_debug__min_i_max_threadId(System_Size min, System_Size index, System_Size max, System_Thread_ID threadId) {
    System_Size unfree = 0;

    System_VarArray mem64k = System_Memory_ProcessVars[index];
    if (!mem64k) return 0;

    System_Memory_Page mem64h = null;
    for (System_Size i = 0; i < mem64k->length; ++i) {
        mem64h = (System_Memory_Page)array(mem64k->value)[i];
        if (!mem64h || mem64h->threadId != threadId) continue;

        /* NOW lookup for unfreed */

        Var position = ((System_Var)mem64h + sizeof(struct System_Memory_Page));
        while (position + sizeof(struct System_Memory_Header) < ((System_Var)mem64h + mem64h->length)) {
            System_Memory_Header header = (System_Memory_Header)position;
            if (!header->length || !header->type) break;
#if DEBUG
            Console_assert(header->type == typeof(System_Memory_Header));
#endif
            if (header->type != typeof(System_Memory_Header)) break;

            System_Var item = position + sizeof(struct System_Memory_Header);

            if (header->refCount && header->elementType) {

                /* LIE about that */
                if (System_Exception_current) {
                    if (item == System_Exception_current) goto continue_position;
                    if (item == System_Exception_current->message) goto continue_position;
                }

                ++unfree;
                if (header->elementType == typeof(System_Char8)) {
                    System_Console_write__string("\"");
                    System_Console_write__string(item);
                    System_Console_write__string("\", ");
                }
                else {
                    System_Console_write__string(header->elementType->name);
                    if (header->length > header->elementType->size * 1) 
                        System_Console_write__string("[]");
                    System_Console_write__string(", ");
                }
            }

#if DEBUG == DEBUG_System_Memory
            Console_assert(header->length);
#endif

        continue_position:
            if (!header->length) break;
            position += sizeof(struct System_Memory_Header) + header->length;
        }
    }
    return unfree;
}

void System_Memory_debug__threadId(System_Thread_ID threadId) {
    System_Size unfree = 0;
    unfree += System_Memory_debug__min_i_max_threadId(1024, 0, 4194304, threadId);
    unfree += System_Memory_debug__min_i_max_threadId(512, 1, 8388608, threadId);
    unfree += System_Memory_debug__min_i_max_threadId(64, 2, 0xFFFFFFFFU, threadId);
    if (unfree) System_Console_debugLine("System_Memory_debug: {0:uint} unfreed, threadId {1:int32}.", 2, unfree, threadId);
}

void System_Memory_cleanup__min_i_max_threadId(System_Size min, System_Size index, System_Size max, System_Thread_ID threadId) {
    System_Bool lock = threadId != System_Thread_TID;
    System_VarArray mem64k = System_Memory_ProcessVars[index];
    if (!mem64k) return;

    System_Memory_Page mem64h = null;
    for (System_Size i = 0; i < mem64k->length; ++i) {
        mem64h = (System_Memory_Page)array(mem64k->value)[i];
        if (!mem64h || mem64h->threadId != threadId) continue;

        if (lock) System_Atomic_writeLock(&System_Memory_ProcessLock);
        System_Syscall_munmap(mem64h, max);
        array(mem64k->value)[i] = null;
        if (lock) System_Atomic_writeUnlock(&System_Memory_ProcessLock);
    }
    /* if (threadId == System_Thread_PID) {
        System_Syscall_munmap(mem64k, min);
        System_Memory_ProcessVars[index] = null;
    } */
}

void System_Memory_cleanup__threadId(System_Thread_ID threadId) {
#if DEBUG
    System_Memory_debug__threadId(System_Thread_TID);
#endif
    System_Memory_cleanup__min_i_max_threadId(1024, 0, 4194304, threadId);
    System_Memory_cleanup__min_i_max_threadId(512, 1, 8388608, threadId);
    System_Memory_cleanup__min_i_max_threadId(64, 2, 0xFFFFFFFFU, threadId);
}

System_Bool System_Memory_isAllocated(System_Var that) {
    Console_assert(that);

    static System_Size indexL = sizeof_array(System_Memory_ProcessVars);

    System_Var * vars = System_Memory_ProcessVars;

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
#if DEBUG == DEBUG_System_Memory
    Console_assert(header->type == typeof(System_Memory_Header));
#endif
    if (header->type != typeof(System_Memory_Header)) return that;

    ++header->refCount;
    return that;
}

void System_Memory_reallocArray(System_Var ref thatPtr, System_Size count) {
    if (!thatPtr) return; // throw
    System_Var that = *thatPtr;
    Console_assert(that);
    if (!Memory_isAllocated(that)) return;

    System_Memory_Header header = ((System_Var)that - sizeof(struct System_Memory_Header));
#if DEBUG
	Console_assert(header->type == typeof(System_Memory_Header));
#endif
    if (header->type != typeof(System_Memory_Header)) return;

    System_Size new_size = count * header->elementType->size;
    if (new_size == header->length) {
#if DEBUG == DEBUG_System_Memory
    System_Console_writeLine("System_Memory_reallocArray, not: using System_Memory_Header typeof({0:string}), sizeof({1:uint}), old length {2:uint} => new length {3:uint}", 4, 
        header->elementType->name, header->elementType->size, header->length, new_size);
#endif
        return;
    }
#if DEBUG == DEBUG_System_Memory
    System_Console_writeLine("System_Memory_reallocArray, reallocating: using System_Memory_Header typeof({0:string}), sizeof({1:uint}), old length {2:uint} => new length {3:uint}", 4, 
        header->elementType->name, header->elementType->size, header->length, new_size);
#endif
    System_Var that_new = System_Memory_allocArray(header->elementType, count);
    if (new_size < header->length)
        Memory_moveTo(that, new_size, that_new);
    else
        Memory_moveTo(that, header->length, that_new);
    Memory_free(that);
    *thatPtr = that_new;
}

void  System_Memory_freeClass(System_Var ref thatPtr) {
	Console_assert(thatPtr);
    if (!thatPtr) return;
    System_Var that = *thatPtr;
#if DEBUG == DEBUG_System_Memory
	Console_assert(that);
#endif
    if (!that) return;

    if (!Memory_isAllocated(that)) {
#if DEBUG == DEBUG_System_Memory
        System_Console_writeLine__string("System_Memory_freeClass: not Memory_isAllocated, try using System_Memory_freeStruct instead");
#endif
        goto return_free; 
    }

    System_Memory_Header header = ((System_Var)that - sizeof(struct System_Memory_Header));
#if DEBUG
	Console_assert(header->type == typeof(System_Memory_Header));
#endif
    if (header->type != typeof(System_Memory_Header)) return;

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

    System_Memory_clear(that, header->length);
    header->elementType = null;
    header->refCount = System_Memory_ReferenceState_Free;

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
    else if (System_Type_isAssignableFrom(type, typeof(System_Object))) 
        System_Console_writeLine("System_Memory_freeStruct: class typeof({0:string}): function_System_Object_free not found", 1, type->name);
    #endif
}

#endif
