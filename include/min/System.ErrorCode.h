/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_ErrorCode)
#define have_System_ErrorCode

typedef System_IntPtr  System_ErrorCode;

export struct System_Type  System_ErrorCodeType;

#if defined(using_System)
#define ErrorCode  System_ErrorCode
#define ErrorCodeType  System_ErrorCodeType
#endif

#include "System.ErrorCode.generic.asm.h"

#endif
