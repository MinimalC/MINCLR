/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_varArray)
#include "System.varArray.h"
#endif
#if !defined(have_System_Memory_Arena)
#define have_System_Memory_Arena

#define struct_System_Memory_Arena  struct class_System_Memory_Arena
typedef fixed struct_System_Memory_Arena {
    struct_System_varArray base;

    System_size  pageSize;

}  * System_Memory_Arena;

export struct_System_Type  System_Memory_ArenaType;

export System_Memory_Arena  base_System_Memory_Arena_init(System_Memory_Arena that, System_size length);
export void  base_System_Memory_Arena_free(System_Memory_Arena that);

#define System_Memory_Arena_init(o)  ((function_System_Memory_Arena_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_Memory_Arena_free(o)  ((function_System_Memory_Arena_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#if defined(using_System)
#define struct_Memory_Arena  struct class_System_Memory_Arena
#define stack_Memory_Arena  stack_System_Memory_Arena
#define Memory_Arena  System_Memory_Arena
#define Memory_ArenaType  System_Memory_ArenaType

#define Memory_Arena_init  System_Memory_Arena_init
#define Memory_Arena_free  System_Memory_Arena_free
#define base_Memory_Arena_init  base_System_Memory_Arena_init
#define base_Memory_Arena_free  base_System_Memory_Arena_free
#define function_Memory_Arena_init  function_System_Memory_Arena_init
#define function_Memory_Arena_free  function_System_Memory_Arena_free
#endif

#endif
