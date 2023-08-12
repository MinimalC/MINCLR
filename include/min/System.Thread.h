/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Thread)
#define have_System_Thread

export struct System_Type  System_ThreadType;

typedef void delegate(System_Thread_main)(System_Size argc, System_Var argv[]);

export System_SIntPtr System_Thread_create(function_System_Thread_main function, System_Size argc, System_Var argv[]);
export void System_Thread_sleep(System_Size seconds);
export void System_Thread_yield(void);
export System_Bool System_Thread_join(System_SIntPtr id);
export System_Bool System_Thread_join__dontwait(System_SIntPtr id, System_Bool dontwait);
import void System_Thread_start(void);

#endif
