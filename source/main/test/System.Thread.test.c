#define using_System
#include <min/System.h>

atomic System_Size  number = 0;

System_IntPtr Dummy0(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("Child{0:uint}", 1, argv[0]);

    System_Size i = 0;
    while (!System_Size_atomic_expect(&number, 0, (System_Size)argv[0])) {
        if (i != System_Size_Max) ++i;
        System_Atomic_fence();
    }
    System_Console_writeLine("Child{0:uint}: {1:uint}. wrote number {2:uint:bin}.", 3, argv[0], i, number);
    System_Thread_microsleep(330);
    System_Console_writeLine("System_Thread_TID: {0:uint32} System_Thread_getRegister: {1:uint:hex}", 2, System_Thread_TID, System_Thread_getRegister());
    if (!System_Thread_Current)
        System_Console_write__string("System_Thread_Current: 0x0\n");
    else
        System_Console_writeLine("System_Thread_Current: 0x{0:uint:hex}, base.type 0x{1:uint:hex}, threadId {2:int32}, returnValue {3:uint32}", 4, 
            System_Thread_Current, System_Thread_Current->base.type, System_Thread_Current->threadId, System_Thread_Current->returnValue);

    i = 0;
    while (!System_Size_atomic_expect(&number, (System_Size)argv[0], 0)) {
        if (i != System_Size_Max) ++i;
        System_Atomic_fence();
    }
    return (System_IntPtr)argv[0];
}

System_IntPtr Dummy3(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("Child{0:uint}", 1, argv[0]);

    System_Size i = 0;
    while (!System_Size_atomic_expect(&number, 0, (System_Size)argv[0])) {
        if (i != System_Size_Max) ++i;
        System_Atomic_fence();
    }
    System_Console_writeLine("Child{0:uint}: {1:uint}. wrote number {2:uint:bin}.", 3, argv[0], i, number);
    System_Thread_microsleep(330);

    i = 0;
    while (!System_Size_atomic_expect(&number, (System_Size)argv[0], 0)) {
        if (i != System_Size_Max) ++i;
        System_Atomic_fence();
    }
    return (System_IntPtr)argv[0];
}

System_IntPtr Dummy4(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("Child{0:uint}", 1, argv[0]);

    System_Size i = 0;
    while (!System_Size_atomic_expect(&number, 0, (System_Size)argv[0])) {
        if (i != System_Size_Max) ++i;
        System_Atomic_fence();
    }
    System_Console_writeLine("Child{0:uint}: {1:uint}. wrote number {2:uint:bin}.", 3, argv[0], i, number);
    System_Exception_throw(new_System_IOException("TestException"));
    System_Thread_microsleep(330);

    i = 0;
    while (!System_Size_atomic_expect(&number, (System_Size)argv[0], 0)) {
        if (i != System_Size_Max) ++i;
        System_Atomic_fence();
    }
    return (System_IntPtr)argv[0];
}

void System_Runtime_sigfault(System_Signal_Number number, System_Signal_Info info, System_Var context) {
    System_Console_writeLine("{0:string}: number {1:uint32}, errno {2:uint32}, code {3:uint32}, sigfault.address {4:uint:hex}", 5,
        System_Signal_Number_toString(number), info->number, info->errno, info->code, info->sigfault.address);
    System_Thread_terminate(false);
}

int System_Runtime_main(int argc, char * argv[]) {

    struct System_Signal signal; System_Stack_clear(signal);
    System_Signal_add(&signal, System_Signal_Number_SIGILL);
    System_Signal_add(&signal, System_Signal_Number_SIGFPE);
    System_Signal_add(&signal, System_Signal_Number_SIGSEGV);
    System_Signal_unblock(&signal);
    System_Signal_act(System_Signal_Number_SIGILL, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Number_SIGFPE, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Number_SIGSEGV, System_Runtime_sigfault);

    System_Console_writeLine("System_Thread_PID: {0:uint32}, System_Thread_TID: {1:uint32}", 2, System_Thread_PID, System_Thread_TID);

    System_Size dummyC = 0;
    System_Thread dummys[64]; System_Stack_clear(dummys);

    dummys[dummyC++] = System_Thread_create(Dummy0, 1, 1);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 2);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 4);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 8);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 16);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 32);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 64);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 128);
    dummys[dummyC++] = System_Thread_create(Dummy4, 1, 256);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 512);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 1024);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 2048);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 4096);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 8192);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 16384);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 32768);

    System_Bool retures[64]; System_Stack_clear(retures);

    while (true) {

        for (System_Size i = 0; i < dummyC; ++i)
            if (!retures[i]) {
                retures[i] = System_Thread_join__dontwait(dummys[i], true);
                if (dummys[i]->runtime) System_Console_writeLine("Wait on Child{0:uint}, threadId {1:int32}", 2, (1 << i), dummys[i]->threadId);
                else System_Console_writeLine("Child{0:uint} return number {1:uint:bin}.", 2, (1 << i), dummys[i]->returnValue);
            }

        System_Size r = 0;
        for (System_Size i = 0; i < dummyC; ++i)
            if (retures[i]) ++r;
        if (r == dummyC) break;

        System_Thread_sleep(1);
    }
    
    System_Stack_clear(retures);

    for (; dummyC; --dummyC) 
        System_Memory_free(dummys[dummyC - 1]);

    System_Console_writeLine__string("This is Parent");
    return true;
}

