/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
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


System_size stack_System_arguments_get(arguments args, System_var argv[System_arguments_Limit_VALUE]) {
    return stack_System_arguments_get__limit(args, argv, System_arguments_Limit_VALUE);
}

export System_size stack_System_arguments_get__limit(System_arguments args, System_var argv[], System_size limit) {
    Console_assert(argv);
    /* this is expecting a size as first argument or null */
    size argc = !args ? 0 : argument(args, size);
    if (argc > limit) { argc = 0;
#if DEBUG
    System_Console_write__string8("WARNING: stack_System_arguments");
#endif
    }
    for (size i = 0; i < argc; ++i) {
        argv[i] = argument(args, var);
    }
    return argc;    
}