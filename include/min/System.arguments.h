#if !defined(have_System_arguments)
#define have_System_arguments

/*  WARNING: Using ellipsis ..., va_list and va_arg is unsafe!
    There should be at least one System_Size count argument,
    which is the count of arguments following. */

#if defined(GNUCC)
typedef __builtin_va_list  System_arguments;
#define System_argument  __builtin_va_arg
#define System_arguments_copy  __builtin_va_copy
#define System_arguments_start  __builtin_va_start
#define System_arguments_end  __builtin_va_end

#else /* if TinyCC */
#include <stdarg.h>
#define System_arguments  va_list
#define System_argument  va_arg
#define System_arguments_copy  va_copy
#define System_arguments_start  va_start
#define System_arguments_end  va_end
#endif

#define System_arguments_Limit_VALUE 16

export System_Size stack_System_arguments_get(System_arguments args, System_Var argv[System_arguments_Limit_VALUE]);
export System_Size stack_System_arguments_get__limit(System_arguments args, System_Var argv[], System_Size limit);

#if defined(using_System)
#define argument  System_argument
#define arguments  System_arguments
#define arguments_copy  System_arguments_copy
#define arguments_start  System_arguments_start
#define arguments_end  System_arguments_end
#define arguments_Limit_VALUE  System_arguments_Limit_VALUE
#define stack_arguments_get  stack_System_arguments_get
#define stack_arguments_get__limit  stack_System_arguments_get__limit
#endif
#endif
