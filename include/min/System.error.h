/* Gemeinfrei. Public Domain. */
#if !defined(have_System_error)
#define have_System_error

typedef System_intptr  System_error;

export struct System_Type  System_errorType;

#if defined(using_System)
#define Error  System_error
#define ErrorType  System_errorType
#endif

#include "System.error.generic.asm.h"

#endif
