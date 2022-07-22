/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Error)
#define have_System_Error

typedef System_IntPtr  System_Error;

export struct System_Type  System_ErrorType;

#if defined(using_System)
#define Error  System_Error
#define ErrorType  System_ErrorType
#endif

#include "System.Error.generic.asm.h"

#endif
