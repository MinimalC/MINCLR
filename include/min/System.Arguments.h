#if !defined(have_System_Arguments)
#define have_System_Arguments

/*  WARNING: Using ellipsis ..., va_list and va_arg is unsafe!
    There should be at least one System_Size count argument,
    which is the count of Arguments following. */

enum {
    System_Arguments_Limit = 64
};

#if defined(GNUCC)
typedef __builtin_va_list  System_Arguments;
#define System_Argument  __builtin_va_arg
#define System_Arguments_copy  __builtin_va_copy
#define System_Arguments_start  __builtin_va_start
#define System_Arguments_end  __builtin_va_end

#else /* if TinyCC */
#include <stdarg.h>
#define System_Arguments  va_list
#define System_Argument  va_arg
#define System_Arguments_copy  va_copy
#define System_Arguments_start  va_start
#define System_Arguments_end  va_end
#endif

export System_Size stack_System_Arguments_get(System_Arguments args, System_Var argv[System_Arguments_Limit]);
export System_Size stack_System_Arguments_get__limit(System_Arguments args, System_Var argv[], System_Size limit);

#if defined(using_System)
#define Argument  System_Argument
#define Arguments  System_Arguments
#define Arguments_copy  System_Arguments_copy
#define Arguments_start  System_Arguments_start
#define Arguments_end  System_Arguments_end
#define Arguments_Limit  System_Arguments_Limit


#endif
#endif
