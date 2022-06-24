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

void  * System_Memory_alloc(__size length) {

    void *thatPtr = ISO_malloc(length);
    __uint8 *that = (__uint8 *)thatPtr;
    System_Memory_set(that, 0x00, length);
    return thatPtr;
}

void  System_Memory_realloc(void  ** that, __size oldLength, __size newLength) {

    __uint8  * that1 = (__uint8 *)ISO_realloc(*that, newLength);
    if (newLength > oldLength) {
        System_Memory_set(that1 + oldLength, 0x00, newLength - oldLength);
    }

    if (*that != that1) {
        *that = that1;
    }
}

void System_Memory_freeStruct(void *that) {
    __assert(that)
    ISO_free(that);
}

void System_Memory_free(void **thatPtr) {
    __assert(thatPtr)
    void *that = *thatPtr;
    __assert(that)
    System_Memory_freeStruct(that);
    *thatPtr = __null;
}


__size System_Memory_indexOf(const void *ptr, __byte needle, __size count) {
    __assert(count > 0)

    __size i = 0;
    __byte *ptrBytes = (__byte *)ptr;
    do {
        if (*ptrBytes == needle) return i + 1;
        ++i;
        if (--count == 0) break;
        ++ptrBytes;
    } while (__true);

    return 0;
}

void *System_Memory_zero(void *dest, __size n) {
    __assert(n > 0)

    __byte *destBytes = (__byte *)dest;
    do {
        *destBytes = 0x00;
        if (--n == 0) break;
        ++destBytes;
    } while (__true);

    return dest;
}

void *System_Memory_copy(const void *src, __size n, void *dest) {
    __byte *destBytes = (__byte *)dest;
    const __byte *srcBytes = (__byte *)src;
    while (n--) *destBytes++ = *srcBytes++;
    return dest;
}

void *System_Memory_move(const void *src, __size n, void *dest) {
    __byte *destBytes = (__byte *)dest;
    const __byte *srcBytes = (__byte *)src;
    if ( srcBytes < destBytes )
        for (destBytes += n, srcBytes += n; n--; )
            *--destBytes = *--srcBytes;
    else
        while (n--) *destBytes++ = *srcBytes++;
    return dest;
}

void *System_Memory_set(void *dest, __byte src, __size n) {
    __assert(n > 0)

    __byte *destBytes = (__byte *)dest;
    do {
        *destBytes = src;
        if (--n == 0) break;
        ++destBytes;
    } while (__true);

    return dest;
}

__int System_Memory_compare(const void *ptr0, const void *ptr1, __size count) {
    __assert(count > 0)

    __byte *ptr0Bytes = (__byte *)ptr0;
    __byte *ptr1Bytes = (__byte *)ptr1;
    do {
        if (*ptr0Bytes < *ptr1Bytes) return -1;
        if (*ptr0Bytes > *ptr1Bytes) return 1;
        if (--count == 0) break;
        ++ptr0Bytes;
        ++ptr1Bytes;
    } while (__true);

    return 0;
}

__bool System_Memory_equals(const void *ptr0, const void *ptr1, __size count) {
    return (0 == System_Memory_compare(ptr0, ptr1, count));
}

#endif
