/* Gemeinfrei. Public Domain. */
#if !defined(have_System_stddef)
#include <min/System.stddef.h>
#endif
#if !defined(have_System_Runtime)
#define have_System_Runtime

import int System_Runtime_main(int argc, char * argv[]);

export void System_Runtime_start(System_Var  * stack);

#endif
