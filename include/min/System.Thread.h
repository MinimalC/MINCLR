/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Thread)
#define have_System_Thread

typedef System_Int32  System_Thread_ID;

typedef System_fixed struct System_Thread {
	struct System_Object  base;

    atomic System_Thread_ID threadId;

    atomic System_Int32 returnValue;

    System_Var stack;

    System_Var tls;

}  * System_Thread;

export struct System_Type  System_ThreadType;

#if !defined(System_internal)
import thread System_Thread System_Thread_Current;
import thread System_Thread_ID System_Thread_TID;
#endif

typedef System_IntPtr delegate(System_Thread_main)(System_Size argc, System_Var argv[]);

export System_Thread System_Thread_create(function_System_Thread_main function, ...);
export System_Thread System_Thread_create__arguments(function_System_Thread_main function, System_Size argc, System_Var argv[]);
export void System_Thread_sleep(System_Size seconds);
export void System_Thread_nanosleep(System_Size nanoseconds);
export void System_Thread_microsleep(System_Size microseconds);
export void System_Thread_millisleep(System_Size milliseconds);
export void System_Thread_yield(void);
import void System_Thread_boot(void) noreturn;
import void System_Thread_terminate(System_Thread that, System_IntPtr returnValue) noreturn;
export System_Var System_Thread_getRegister(void);
export void System_Thread_setRegister(System_Var fs);
/* export System_Var __tls_get_addr(System_Var index); */
export System_Bool System_Thread_join(System_Thread that);
export System_Bool System_Thread_join__dontwait(System_Thread that, System_Bool dontwait);

#endif
