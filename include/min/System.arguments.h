#if !defined(have_System_stdarg)
#define have_System_stdarg

/*  WARNING: Using ellipsis ..., va_list and va_arg is unsafe!
    There should be at least one System_size count argument,
    which is the count of arguments following. */

#if defined(__GNUCC)
typedef __builtin_va_list  System_arguments;

#define System_argument  __builtin_va_arg
#define System_arguments_copy  __builtin_va_copy
#define System_arguments_start  __builtin_va_start
#define System_arguments_end  __builtin_va_end

#else /* if __TinyCC */

#include <stdarg.h>

#define System_arguments  va_list

#define System_argument  va_arg
#define System_arguments_copy  va_copy
#define System_arguments_start  va_start
#define System_arguments_end  va_end
#endif

#if defined(using_System)
#define __argument  System_argument
#define __arguments  System_arguments
#define __arguments_copy  System_arguments_copy
#define __arguments_start  System_arguments_start
#define __arguments_end  System_arguments_end
#endif

#endif
