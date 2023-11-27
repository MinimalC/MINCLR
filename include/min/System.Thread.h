/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Thread)
#define have_System_Thread

typedef System_Int32  System_Thread_TID;

enum {
    System_Thread_MemoryOrder_Relaxed,   // relaxed
    System_Thread_MemoryOrder_Consume,   // consume
    System_Thread_MemoryOrder_Acquire,   // acquire
    System_Thread_MemoryOrder_Release,   // release
    System_Thread_MemoryOrder_Acquire_Release,   // acquire/release
    System_Thread_MemoryOrder_Sequentially_Consistent    // sequentially consistent
};

typedef System_fixed struct System_Thread {
	struct System_Object  base;

    atomic System_Thread_TID threadId;

    atomic System_Int32 returnValue;

}  * System_Thread;

export struct System_Type  System_ThreadType;

#if !defined(System_internal)
import thread System_Thread System_Thread_Current;
#endif

typedef System_IntPtr delegate(System_Thread_main)(System_Size argc, System_Var argv[]);

export System_Thread System_Thread_create(function_System_Thread_main function, ...);
export System_Thread System_Thread_create__arguments(function_System_Thread_main function, System_Size argc, System_Var argv[]);
export void System_Thread_sleep(System_Size seconds);
export void System_Thread_yield(void);
import void System_Thread_boot(void);
export System_Var System_Thread_createStorage(void);
export System_Var __tls_get_addr(System_Var index);
export System_Bool System_Thread_join(System_Thread that);
export System_Bool System_Thread_join__dontwait(System_Thread that, System_Bool dontwait);
export System_Bool System_Thread_join2(System_Thread that);
export System_Bool System_Thread_join2__dontwait(System_Thread that, System_Bool dontwait);

#endif
