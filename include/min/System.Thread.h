/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Thread)
#define have_System_Thread

export struct System_Type  System_ThreadType;

export System_SIntPtr System_Thread_create(System_Var function, System_Size argc, System_Var argv[]);
export void System_Thread_sleep(System_Size seconds);
export System_Bool System_Thread_join(System_SIntPtr id);
import void System_Thread_start(void);

#endif
