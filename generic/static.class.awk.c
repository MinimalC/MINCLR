/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array

#define Generic_T0ArrayType  System_ArrayType
#endif
/* GENERIC */
#if !defined(have_Generic)
#warning "Generic.h not included"
#include "Generic.internal.h"
#endif
#if !defined(code_auto_Generic_T0)
#define code_auto_Generic_T0

struct System_String  STRING_Generic_T0 = const_System_String("Generic.T0");

struct System_Type  Generic_T0Type = { .base = { .type = typeof(System_Type), }, .name = &STRING_Generic_T0, };

#endif

