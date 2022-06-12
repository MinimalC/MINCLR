/* Gemeinfrei. Public Domain. */
#if !defined(have_System_error)
#define have_System_error

typedef System_intptr  System_error;

__export struct_System_Type  System_errorType;

#if defined(using_System)
#define error  System_error
#define __errorType  System_errorType
#endif

#include "System.error.generic.asm.h"

#endif
