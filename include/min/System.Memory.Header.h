/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Memory_Header)
#define have_System_Memory_Header

typedef enum System_Memory_Design {
    System_Memory_Design_Freedom,
    System_Memory_Design_Object,
    System_Memory_Design_Array,
} System_Memory_Design;

typedef enum System_Memory_PageFlags {
    System_Memory_PageFlags_None,    /* Page can not be accessed.  */
    System_Memory_PageFlags_Read,    /* Page can be read.  */
    System_Memory_PageFlags_Write,   /* Page can be written.  */
    System_Memory_PageFlags_Execute = 4   /* Page can be executed.  */
} System_Memory_PageFlags;

typedef enum System_Memory_MapFlags {
    System_Memory_MapFlags_Shared = 1,
    System_Memory_MapFlags_Private,
    System_Memory_MapFlags_Anonymous = 0x20,
} System_Memory_MapFlags;

#define System_Memory_MapFailed  ((System_var) -1)

typedef enum System_Memory_ReferenceState {
    System_Memory_ReferenceState_Freed,
    System_Memory_ReferenceState_Disposed,
    System_Memory_ReferenceState_Disposing,
    System_Memory_ReferenceState___reserved0,
    System_Memory_ReferenceState___reserved1,
    System_Memory_ReferenceState___reserved2,
    System_Memory_ReferenceState___reserved3,
    System_Memory_ReferenceState___reserved4,
    System_Memory_ReferenceState___reserved5,
    System_Memory_ReferenceState___reserved6,
    System_Memory_ReferenceState___reserved7,
    System_Memory_ReferenceState_Used,
} System_Memory_ReferenceState;

#define struct_System_Memory_Header  struct class_System_Memory_Header
typedef fixed struct_System_Memory_Header {
    struct_System_Object base;

    System_Memory_Design design;

    System_Type type;

    System_uint refCount;

    System_size length;

}  * System_Memory_Header;

#define stack_System_Memory_Header()  { .base = stack_System_Object(System_Memory_Header) }

export struct_System_Type  System_Memory_HeaderType;

typedef System_Memory_Header delegate(System_Memory_Header_init)(System_Memory_Header that);
typedef void delegate(System_Memory_Header_free)(System_Memory_Header that);

export System_Memory_Header  System_Memory_Header_new();
export System_Memory_Header  base_System_Memory_Header_init(System_Memory_Header that);
export void  base_System_Memory_Header_free(System_Memory_Header that);

#define System_Memory_Header_init(o)  ((function_System_Memory_Header_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_Memory_Header_free(o)  ((function_System_Memory_Header_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define inline_System_Memory_Header_new()  (base_System_Memory_Header_init(inline_System_Object_allocClass(System_Memory_Header)))

#if defined(using_System)
#define struct_MemoryHeader  struct_System_Memory_Header
#define stack_MemoryHeader  stack_System_Memory_Header
#define Memory_Header  System_Memory_Header
#define Memory_HeaderType  System_Memory_HeaderType

#define Memory_Header_new  System_Memory_Header_new

#define Memory_Header_init  System_Memory_Header_init
#define Memory_Header_free  System_Memory_Header_free
#define base_MemoryHeader_init  base_System_Memory_Header_init
#define base_MemoryHeader_free  base_System_Memory_Header_free
#define function_MemoryHeader_init  function_System_Memory_Header_init
#define function_MemoryHeader_free  function_System_Memory_Header_free
#endif

#endif
