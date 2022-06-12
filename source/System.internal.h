#if defined(have_System_internal)
#error "Multiple inclusion of System.internal.h !"
#endif
#define have_System_internal

/* SQLITE
const int System_byteOrder_check = 1; */

#define DEBUG_assert  1
#define DEBUG_System_Object  2

/* default, for developers */
#define __DEBUG  DEBUG_assert

/* #include <System.config.h>
#if !defined(have_System_config)
#warning have_System_config is undefined. Run make.sh to implicitly build this project using config.sh and including config.h.
#endif */

#define using_System
#include <min/System.h>

#include <min/ISO.h>
