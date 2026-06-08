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
    if (*address == tid) {
        #if DEBUG
        System_Console_writeLine("Autex wait AGAIN. TID {0:int32}", 1, tid);
        #endif
        return true;
    }

    System_Atomic_fence();
    while (!System_Int32_atomic_expect(address, 0, tid)) {
        #if DEBUG
        if (++rounds == 0) System_Console_writeLine("Autex wait overrun. TID {0:int32}", 1, tid);
        #endif
        System_Atomic_pause();
        System_Atomic_fence();
    }
    return true;
}

System_Bool System_Autex_wake(atomic System_Int32 * address) {
    Size rounds = 0;
    System_Thread_ID tid = System_Thread_TID;
    System_Thread_ID tid1 = *address;

    System_Atomic_fence();
    if (!tid1) {
        #if DEBUG
        System_Console_writeLine("Autex wake WRONG. TID {0:int32}", 1, tid);
        #endif
        return false;
    }
    if (tid1 != tid) {
        #if DEBUG
        System_Console_writeLine("Autex wake WRONG ThreadID. TID {0:int32}, other TID {1:int32}", 2, tid, tid1);
        #endif
        return false;
    }

    System_Atomic_fence();
    System_Int32_atomic_exchange(address, 0);

    System_Atomic_fence();
    while (!System_Int32_atomic_await(address, 0)) {
        #if DEBUG
        if (++rounds == 0) System_Console_writeLine("Autex wake overrun. TID {0:int32}", 1, tid);
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
