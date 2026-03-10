/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Syscall)
#include "System.Syscall.h"
#endif
#if !defined(have_System_Autex)
#define have_System_Autex

/* This is Autex, the Atomic Userspace Mutual Exclusion */

export struct System_Type  System_AutexType;

export System_Bool System_Autex_wait(atomic System_Int32 * address);
export System_Bool System_Autex_wake(atomic System_Int32 * address);

#if defined(using_System)
#define Autex  System_Autex
#define AutexType  System_AutexType
#define Autex_wait  System_Autex_wait
#define Autex_wake  System_Autex_wake
#endif
#endif
