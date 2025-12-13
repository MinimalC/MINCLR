/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Thread)
#include "System.Thread.h"
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
    System_Memory_ReferenceState_Free,
    System_Memory_ReferenceState_Disposed,
    System_Memory_ReferenceState_Disposing,
    /* reserved */
    System_Memory_ReferenceState_Used = 11,
};

export struct System_Type  System_MemoryType;

/* void * memchr ( const void * var, int value, size_t num ); */
export System_SSize  System_Memory_indexOf(System_Var var, System_Size count, System_Char8 needle);
export System_SSize  System_Memory_indexOf__other(System_Var var, System_Size count, System_Var needle, System_Size needle_count);

/* void bzero(void *dest, size_t count) */
export void  System_Memory_clear(System_Var dest, System_Size n);

/* void * memcpy ( void * destination, const void * source, size_t num ); */
export void  System_Memory_copyTo(System_Var src, System_Size n, System_Var dest);

/* void *memmove (void *dest, const void *src, size_t n) */
export void  System_Memory_moveTo(System_Var src, System_Size n, System_Var dest);

/* void *memset (void *s, int c, size_t n) */
export void  System_Memory_set(System_Var dest, System_Size n, System_Char8 src);

/* int memcmp ( const void * var1, const void * var2, size_t num ); */
export System_Size  System_Memory_compare(System_Var var0, System_Var var1, System_Size length);

export System_Bool  System_Memory_equals(System_Var var0, System_Var var1, System_Size length);

typedef System_SSize  delegate(System_Memory_comparison)(System_Var memory0, System_Var memory1, System_Size itemSize);
export void  System_Memory_sort(System_Var memory, System_Size itemsCount, System_Size itemSize, function(System_Memory_comparison) comparison);
export System_SSize  System_Memory_alphacompare(System_Var memory0, System_Var memory1, System_Size itemSize);
export System_SSize  System_Memory_alphacomparedescending(System_Var memory0, System_Var memory1, System_Size itemSize);

export System_Var  System_Memory_allocClass(System_Type type);
export System_Var  System_Memory_allocStaticClass(System_Type type);
export System_Var  System_Memory_allocClass__threadId(System_Type type, System_Thread_ID threadId);
export System_Var  System_Memory_allocArray(System_Type type, System_Size count);
export System_Var  System_Memory_allocStaticArray(System_Type type, System_Size count);
export System_Var  System_Memory_allocArray__threadId(System_Type type, System_Size count, System_Thread_ID threadId);
export void System_Memory_reallocArray(System_Var ref that, System_Size count);
export System_Var System_Memory_isAllocated(System_Var that);
export System_Var System_Memory_addReference(System_Var that);
export void  System_Memory_freeClass(System_Var ref that);
export void  System_Memory_freeStruct(System_Var that, System_Type type);
export void  System_Memory_debug(void);
export void  System_Memory_debug__threadId(System_Thread_ID threadId);
export void  System_Memory_cleanup(void);
export void  System_Memory_cleanup__threadId(System_Thread_ID threadId);

#define System_Memory_free(THAT) System_Memory_freeClass((System_Var ref)&THAT)

#define inline_System_Memory_equals(VAR0, VAR1, N)  (N == System_Memory_compare(VAR0, VAR1, N))

#if defined(using_System)
#define MemoryType  System_MemoryType

#define Memory_indexOf  System_Memory_indexOf
#define Memory_indexOf__other  System_Memory_indexOf__other
#define Memory_clear  System_Memory_clear
#define Memory_copyTo  System_Memory_copyTo
#define Memory_moveTo  System_Memory_moveTo
#define Memory_set  System_Memory_set
#define Memory_compare  System_Memory_compare
#define Memory_equals  System_Memory_equals
#define function_Memory_comparison  function_System_Memory_comparison
#define Memory_sort  System_Memory_sort
#define Memory_alphacompare  System_Memory_alphacompare
#define Memory_alphacomparedescending  System_Memory_alphacomparedescending

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
