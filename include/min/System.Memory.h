/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Memory)
#define have_System_Memory

__export struct_System_Type  System_MemoryType;

__export void  * System_Memory_alloc(System_size length);

__export void  System_Memory_realloc(void  ** that, System_size oldLength, System_size newLength);

__export void  System_Memory_freeStruct(void *that);

__export void  System_Memory_free(void **thatPtr);

/* void *memset (void *__s, int __c, size_t __n) */
/* #define System_Memory_set  memset */
__export void  * System_Memory_set(void *dest, System_uint8 src, System_size n);

/* void bzero(void *dest, size_t count) */
/* #define System_Memory_zero    bzero */
__export void  * System_Memory_zero(void *dest, System_size n);

/* void * memcpy ( void * destination, const void * source, size_t num ); */
/* #define System_Memory_copy  memcpy */
__export void  * System_Memory_copy(const void *src, System_size n, void *dest);

/* void *memmove (void *__dest, const void *__src, size_t __n) */
/* #define System_Memory_move    memmove */
__export void  * System_Memory_move(const void *src, System_size n, void *dest);

/* int memcmp ( const void * var1, const void * var2, size_t num ); */
/* #define System_Memory_compare    memcmp */
__export System_int32  System_Memory_compare(const void *var0, const void *var1, System_size n);

__export System_boolean  System_Memory_equals(const void *var0, const void *var1, System_size n);

/* void * memchr ( const void * var, int value, size_t num ); */
/* #define System_Memory_indexOf    memchr */
__export System_size  System_Memory_indexOf(const void *var, System_uint8 needle, System_size count);


/* inline */
#define inline_System_Memory_equals(var0, var1, n)  (0 == System_Memory_compare(var0, var1, n))
#define inline_System_Memory_free(var)  System_Memory_free((void **)var)

#if defined(using_System)
#define __MemoryType  System_MemoryType

#define __Memory_alloc  System_Memory_alloc
#define __Memory_realloc  System_Memory_realloc
#define __Memory_freeStruct  System_Memory_freeStruct
#define __Memory_free  System_Memory_free
#define __Memory_set  System_Memory_set
#define __Memory_zero  System_Memory_zero
#define __Memory_copy  System_Memory_copy
#define __Memory_move  System_Memory_move
#define __Memory_compare  System_Memory_compare
#define __Memory_equals  System_Memory_equals
#define __Memory_indexOf  System_Memory_indexOf

#define inline_Memory_equals  inline_System_Memory_equals
#define inline_Memory_free  inline_System_Memory_free
#endif
#endif
