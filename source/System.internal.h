#if defined(have_System_Internal)
#error "Multiple inclusion of System.internal.h !"
#endif
#define have_System_Internal
#define using_System

#define DEBUG_System_Object  2
#define DEBUG_System_String8_format  3
#define DEBUG_System_Memory 4

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
