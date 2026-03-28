/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Autex)
#include <min/System.Autex.h>
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
#endif
#if !defined(have_System_Thread)
#include <min/System.Thread.h>
#endif

/** struct System_Autex  **/

System_Bool System_Autex_wait(atomic System_Int32 * address) {
    Size rounds = 0;
    System_Thread_ID tid = System_Thread_TID;

    System_Atomic_fence();
    while (!System_Int32_atomic_expect(address, 0, tid)) {
        #if DEBUG
        if (++rounds == 0) System_Console_writeLine("Autex wait overrun. TID {0:int32}", 1, tid);
        #endif
        System_Atomic_pause();
        System_Atomic_fence();
    }
    System_Thread_ID tid_1 = System_Int32_atomic_negation(address);
    return true;
}

System_Bool System_Autex_wake(atomic System_Int32 * address) {
    Size rounds = 0;

    System_Thread_ID tid_1 = System_Int32_atomic_exchange(address, 0);
    
    System_Atomic_fence();
    while (!System_Int32_atomic_await(address, 0)) {
        #if DEBUG
        if (++rounds == 0) System_Console_writeLine("Autex wake overrun. TID {0:int32}", 1, -1 * tid_1);
        #endif
        System_Atomic_pause();
        System_Atomic_fence();
    }
    return true;
}

struct System_Type System_AutexType = {
    .base = { .type = typeof(System_Type) },
    .name = "Autex",
};
