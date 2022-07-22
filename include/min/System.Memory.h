/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Memory)
#define have_System_Memory

export struct System_Type  System_MemoryType;

/* void *memset (void *s, int c, size_t n) */
export void  System_Memory_set(System_Var dest, System_Char8 src, System_Size n);

/* void bzero(void *dest, size_t count) */
export void  System_Memory_zero(System_Var dest, System_Size n);

/* void * memcpy ( void * destination, const void * source, size_t num ); */
export void  System_Memory_copyTo(System_Var src, System_Size n, System_Var dest);

/* void *memmove (void *dest, const void *src, size_t n) */
export void  System_Memory_moveTo(System_Var src, System_Size n, System_Var dest);

/* int memcmp ( const void * var1, const void * var2, size_t num ); */
export System_Size  System_Memory_compare(System_Var var0, System_Var var1, System_Size length);

export System_Bool  System_Memory_equals(System_Var var0, System_Var var1, System_Size length);

/* void * memchr ( const void * var, int value, size_t num ); */
export System_Size  System_Memory_indexof(System_Var var, System_Char8 needle, System_Size count);


typedef unsigned System_Memory_PageFlags;
enum {
    System_Memory_PageFlags_None,    /* Page can not be accessed.  */
    System_Memory_PageFlags_Read,    /* Page can be read.  */
    System_Memory_PageFlags_Write,   /* Page can be written.  */
    System_Memory_PageFlags_Execute = 4   /* Page can be executed.  */
};

typedef unsigned System_Memory_MapFlags;
enum {
    System_Memory_MapFlags_Shared = 1,
    System_Memory_MapFlags_Private,
    System_Memory_MapFlags_Anonymous = 0x20,
};

typedef unsigned System_Memory_ReferenceState;
enum {
    System_Memory_ReferenceState_Freed,
    System_Memory_ReferenceState_Disposed,
    System_Memory_ReferenceState_Disposing,
    /* reserved */
    System_Memory_ReferenceState_Used = 11,
};

/* oldies:
export void  * System_Memory_alloc(System_Size length);
export void  System_Memory_realloc(void  ** that, System_Size oldLength, System_Size newLength);
export void  System_Memory_freeStruct(void *that);
export void  System_Memory_free(void **thatPtr);
*/

#define inline_System_Memory_equals(VAR0, VAR1, N)  (N == System_Memory_compare(VAR0, VAR1, N))

#if defined(using_System)
#define MemoryType  System_MemoryType

#define Memory_set  System_Memory_set
#define Memory_zero  System_Memory_zero
#define Memory_copyTo  System_Memory_copyTo
#define Memory_moveTo  System_Memory_moveTo
#define Memory_compare  System_Memory_compare
#define Memory_equals  System_Memory_equals
#define Memory_indexof  System_Memory_indexof

#define inline_Memory_equals  inline_System_Memory_equals
#endif
#endif
