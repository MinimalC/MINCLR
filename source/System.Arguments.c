/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_stddef)
#include <min/System.stddef.h>
#endif
#if !defined(have_System_Arguments)
#include <min/System.Arguments.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif

System_Size stack_System_Arguments_get(Arguments args, System_Var argv[System_Arguments_Limit]) {
    return stack_System_Arguments_get__limit(args, argv, System_Arguments_Limit);
}

System_Size stack_System_Arguments_get__limit(System_Arguments args, System_Var argv[], System_Size limit) {
    Console_assert(argv);
    /* this is expecting a Size as first argument or null */
    Size argc = !args ? 0 : Argument(args,Size);
    if (argc && argc > limit) { 
        argc = 0;
#if DEBUG
    System_Console_writeLine__string("WARNING: stack_System_Arguments limit");
#endif
    }
    for (Size i = 0; i < limit; ++i) {
        if (i < argc) argv[i] = Argument(args, Var);
        else argv[i] = 0;
    }
    return argc;    
}