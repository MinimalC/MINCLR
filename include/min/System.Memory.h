/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Memory)
#define have_System_Memory

export struct_System_Type  System_MemoryType;

/* void *memset (void *s, int c, size_t n) */
export void  System_Memory_set(System_var dest, System_char8 src, System_size n);

/* void bzero(void *dest, size_t count) */
export void  System_Memory_zero(System_var dest, System_size n);

/* void * memcpy ( void * destination, const void * source, size_t num ); */
export void  System_Memory_copy(System_var src, System_size n, System_var dest);

/* void *memmove (void *dest, const void *src, size_t n) */
export void  System_Memory_move(System_var src, System_size n, System_var dest);

/* int memcmp ( const void * var1, const void * var2, size_t num ); */
export System_size  System_Memory_compare(System_var var0, System_var var1, System_size length);

export System_boolean  System_Memory_equals(System_var var0, System_var var1, System_size length);

/* void * memchr ( const void * var, int value, size_t num ); */
export System_size  System_Memory_indexOf(System_var var, System_char8 needle, System_size count);

export void  * System_Memory_alloc(System_size length);

export void  System_Memory_realloc(void  ** that, System_size oldLength, System_size newLength);

export void  System_Memory_freeStruct(void *that);

export void  System_Memory_free(void **thatPtr);


#define inline_System_Memory_equals(VAR0, VAR1, N)  (0 == System_Memory_compare(VAR0, VAR1, N))
#define inline_System_Memory_free(VAR)  System_Memory_free((void **)VAR)

#if defined(using_System)
#define MemoryType  System_MemoryType

#define Memory_set  System_Memory_set
#define Memory_zero  System_Memory_zero
#define Memory_copy  System_Memory_copy
#define Memory_move  System_Memory_move
#define Memory_compare  System_Memory_compare
#define Memory_equals  System_Memory_equals
#define Memory_indexOf  System_Memory_indexOf
#define Memory_alloc  System_Memory_alloc
#define Memory_realloc  System_Memory_realloc
#define Memory_freeStruct  System_Memory_freeStruct
#define Memory_free  System_Memory_free

#define inline_Memory_equals  inline_System_Memory_equals
#define inline_Memory_free  inline_System_Memory_free
#endif
#endif
