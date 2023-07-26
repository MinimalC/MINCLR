/* Gemeinfrei. Public Domain. */
#if !defined(have_System_stddef)
#include <min/System.stddef.h>
#endif
#if !defined(have_System_Runtime)
#define have_System_Runtime

typedef int delegate(System_Runtime_main)(int argc, char * argv[]);

import int System_Runtime_main(int argc, char * argv[]);

export void System_Runtime_start(System_Var  * stack);

export System_Var System_Runtime_stack;

#endif
