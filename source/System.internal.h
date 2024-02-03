#if defined(System_internal)
#error "Multiple inclusion of System.internal.h !"
#endif
#define System_internal
#define using_System

#define DEBUG_System_Type  2
#define DEBUG_System_Object  4
#define DEBUG_System_String8_format  8
#define DEBUG_System_Memory 16
#define DEBUG_System_Console_Environment_Arguments 32
#define DEBUG_System_Exception 64
#define DEBUG_System_Syscall_mmap 128
#define DEBUG_System_ELFAssembly 256
#define DEBUG_System_Thread 512

#if defined(NDEBUG)
#undef NDEBUG
#define RELEASE
#endif
#if !defined(RELEASE)
/* for developers */
#define DEBUG  1
#else
/* for users: release */
#define DEBUG  0
#endif

/* #include <System.config.h>
#if !defined(have_System_config)
#warning have_System_config is undefined. Run make.sh to implicitly build this project using config.sh and including config.h.
#endif */

#include <min/import.h>
