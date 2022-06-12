/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#include <min/System.h>
#endif
#if !defined(code_auto_System_StringArray)
#define code_auto_System_StringArray

struct_System_String  STRING_System_StringArray = const_System_String("System.StringArray");

struct_System_Type  System_StringArrayType = {
    .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_StringArray,
    .size = sizeof(struct_System_StringArray),
    .baseType = __typeof(System_Array),
};

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_TypeArray)
#define code_auto_System_TypeArray

struct_System_String  STRING_System_TypeArray = const_System_String("System.TypeArray");

struct_System_Type  System_TypeArrayType = {
    .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_TypeArray,
    .size = sizeof(struct_System_TypeArray),
    .baseType = __typeof(System_Array),
};

#endif
