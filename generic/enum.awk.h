/* Gemeinfrei. Public Domain. */
#if !defined(T)
#error "Usage: See make.GenericT.awk"
#define Generic_T0  System_enum
#endif
/* GENERIC */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_Generic_T0)
#define have_Generic_T0

typedef System_IntPtr  Generic_T0;
enum {
    Generic_T0_Null,
};

export struct System_Type  Generic_T0Type;

#if defined(using_System)
#define T0  Generic_T0
#define T0Type  Generic_T0Type
#endif
#endif
