/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
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

size System_Memory_indexOf(var ptr, char8 needle, size count) {
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


void  * System_Memory_alloc(size length) {

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
