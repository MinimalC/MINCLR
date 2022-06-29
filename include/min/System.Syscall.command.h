/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Syscall_command)
#define have_System_Syscall_command

typedef System_intptr  System_Syscall_command;

export struct_System_Type  System_Syscall_commandType;

#if defined(using_System)
#define Syscall_command  System_Syscall_command
#define Syscall_commandType  System_Syscall_commandType
#endif

#if defined(have_Linux)

#if defined(have_ARM)
#include "ARM32/GNU.Linux/System.Syscall.command.asm.h"

#elif defined(have_AMD64)
#include "AMD64/GNU.Linux/System.Syscall.command.asm.h"

#elif defined(have_X86)
#include "X86/GNU.Linux/System.Syscall.command.asm.h"

#else
#error Architecture not implemented
#endif

#else
#error Platform not implemented
#endif

#endif
