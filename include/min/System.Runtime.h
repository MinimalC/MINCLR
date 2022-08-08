/* Gemeinfrei. Public Domain. */
#if !defined(have_System_stddef)
#include <min/System.stddef.h>
#endif
#if !defined(have_System_Runtime)
#define have_System_Runtime

typedef int delegate(System_Runtime_main)(int argc, char * argv[]);

import function(System_Runtime_main) System_Runtime_main;

export void System_Runtime_start(System_Var  * stack);

#endif
