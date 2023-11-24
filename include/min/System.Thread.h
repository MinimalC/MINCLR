/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Thread)
#define have_System_Thread

typedef System_Int32 System_ProcessId;

typedef System_fixed struct System_Thread {
	struct System_Object  base;

    System_ProcessId threadId;

    System_IntPtr returnValue;

}  * System_Thread;

export struct System_Type  System_ThreadType;

typedef System_IntPtr delegate(System_Thread_main)(System_Size argc, System_Var argv[]);

export System_Thread System_Thread_create(function_System_Thread_main function, ...);
export System_Thread System_Thread_create__arguments(function_System_Thread_main function, System_Size argc, System_Var argv[]);
export void System_Thread_sleep(System_Size seconds);
export void System_Thread_yield(void);
export System_Bool System_Thread_join(System_Thread that);
export System_Bool System_Thread_join__dontwait(System_Thread that, System_Bool dontwait);
import void System_Thread_boot(void);

export System_Var System_Thread_createStorageImage();

export System_Var __tls_get_addr(System_Var index);

#endif
