#if defined(have_System_internal)
#error "Multiple inclusion of System.internal.h !"
#endif
#define have_System_internal
#define using_System

#define DEBUG_System_Object  2
#define DEBUG_System_string8_formatTo  3

/* for developers */
#define DEBUG  DEBUG_System_string8_formatTo

/* #include <System.config.h>
#if !defined(have_System_config)
#warning have_System_config is undefined. Run make.sh to implicitly build this project using config.sh and including config.h.
#endif */
