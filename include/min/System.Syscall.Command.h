/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Syscall_Command)
#define have_System_Syscall_Command

typedef System_IntPtr  System_Syscall_Command;

export struct System_Type  System_Syscall_CommandType;

#if defined(using_System)
#define Syscall_Command  System_Syscall_Command
#define Syscall_CommandType  System_Syscall_CommandType
#endif

#if defined(have_Linux)

#if defined(have_ARM)
#include "ARM32/GNU.Linux/System.Syscall.Command.asm.h"

#elif defined(have_AMD64)
#include "AMD64/GNU.Linux/System.Syscall.Command.asm.h"

#elif defined(have_X86)
#include "X86/GNU.Linux/System.Syscall.Command.asm.h"

#else
#error Architecture not implemented
#endif

#else
#error Platform not implemented
#endif

#endif
