/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_Object
#define Generic_T0Array  System_Array

#define Generic_T0ArrayType  System_ArrayType
#endif
/* GENERIC */
#if !defined(Generic_internal)
#include "Generic.internal.h"
#endif
#if !defined(have_Generic_T0)
#include <min/Generic.T0.h>
#endif
#if !defined(code_Generic_T0)
#define code_Generic_T0

struct System_Type  Generic_T0Type = { .base = { .type = typeof(System_Type), }, .name = "Generic.T0", };

#endif

