/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_stddef)
#include <min/System.stddef.h>
#endif
#if !defined(have_System_arguments)
#include <min/System.arguments.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif


System_Size stack_System_arguments_get(arguments args, System_Var argv[System_arguments_Limit_VALUE]) {
    return stack_System_arguments_get__limit(args, argv, System_arguments_Limit_VALUE);
}

export System_Size stack_System_arguments_get__limit(System_arguments args, System_Var argv[], System_Size limit) {
    Debug_assert(argv);
    /* this is expecting a Size as first argument or null */
    Size argc = !args ? 0 : argument(args, Size);
    if (argc > limit) { argc = 0;
#if DEBUG
    System_Console_write__String8("WARNING: stack_System_arguments");
#endif
    }
    for (Size i = 0; i < limit; ++i) {
        if (i < argc) argv[i] = argument(args, Var);
        else argv[i] = 0;
    }
    return argc;    
}