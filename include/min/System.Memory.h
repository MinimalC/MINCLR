/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Memory)
#define have_System_Memory

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
    System_Memory_MapFlags_Fixed         = 0x10,
    System_Memory_MapFlags_Anonymous     = 0x20,
    System_Memory_MapFlags_GrowsDown    = 0x100,
    System_Memory_MapFlags_Locked      = 0x2000,
    System_Memory_MapFlags_Stack      = 0x20000,
};

typedef unsigned System_Memory_ReMapFlags;
enum {
    System_Memory_ReMapFlags_MayMove = 1,
    System_Memory_ReMapFlags_Fixed,
    System_Memory_ReMapFlags_DontUnmap = 4,
};

typedef unsigned System_Memory_ReferenceState;
enum {
    System_Memory_ReferenceState_Freed,
    System_Memory_ReferenceState_Disposed,
    System_Memory_ReferenceState_Disposing,
    /* reserved */
    System_Memory_ReferenceState_Used = 11,
};

export struct System_Type  System_MemoryType;

/* void *memset (void *s, int c, size_t n) */
export void  System_Memory_set(System_Var dest, System_Char8 src, System_Size n);

/* void bzero(void *dest, size_t count) */
export void  System_Memory_clear(System_Var dest, System_Size n);

/* void * memcpy ( void * destination, const void * source, size_t num ); */
export void  System_Memory_copyTo(System_Var src, System_Size n, System_Var dest);

/* void *memmove (void *dest, const void *src, size_t n) */
export void  System_Memory_moveTo(System_Var src, System_Size n, System_Var dest);

/* int memcmp ( const void * var1, const void * var2, size_t num ); */
export System_Size  System_Memory_compare(System_Var var0, System_Var var1, System_Size length);

export System_Bool  System_Memory_equals(System_Var var0, System_Var var1, System_Size length);

/* void * memchr ( const void * var, int value, size_t num ); */
export System_SSize  System_Memory_indexOf(System_Var var, System_Char8 needle, System_Size count);

export System_Var  System_Memory_allocClass(System_Type type);
export System_Var  System_Memory_allocArray(System_Type type, System_Size count);
export void System_Memory_reallocArray(System_Var ref that, System_Size count);
export System_Bool System_Memory_isAllocated(System_Var that);
export System_Var System_Memory_addReference(System_Var that);
export void  System_Memory_freeClass(System_Var ref that);
export void  System_Memory_freeStruct(System_Var that, System_Type type);
export void  System_Memory_debug(void);

#define System_Memory_free(THAT) System_Memory_freeClass((System_Var ref)&THAT)

#define inline_System_Memory_equals(VAR0, VAR1, N)  (N == System_Memory_compare(VAR0, VAR1, N))

#if defined(using_System)
#define MemoryType  System_MemoryType

#define Memory_set  System_Memory_set
#define Memory_clear  System_Memory_clear
#define Memory_copyTo  System_Memory_copyTo
#define Memory_moveTo  System_Memory_moveTo
#define Memory_compare  System_Memory_compare
#define Memory_equals  System_Memory_equals
#define Memory_indexOf  System_Memory_indexOf

#define Memory_allocClass  System_Memory_allocClass
#define Memory_allocArray  System_Memory_allocArray
#define Memory_reallocArray  System_Memory_reallocArray
#define Memory_isAllocated  System_Memory_isAllocated
#define Memory_addReference  System_Memory_addReference
#define Memory_freeClass  System_Memory_freeClass
#define Memory_freeStruct  System_Memory_freeStruct
#define Memory_free  System_Memory_free

#define inline_Memory_equals  inline_System_Memory_equals
#endif
#endif
