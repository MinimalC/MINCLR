#define using_System
#include <min/System.h>

typedef struct Parent {

    atomic System_Size  number;

} * Parent;

struct Parent Parent_current = {

    .number = 1

};

void Dummy0(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);
    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
}
System_IntPtr Dummy1(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);

    if (System_Atomic_expect(&Parent_current.number, 3, 4))
        System_Console_writeLine("Child{0:uint}: This was 3, now this is 4", 1, argv[0]);
    else
        System_Console_writeLine("Child{0:uint}: This wasn't 3", 1, argv[0]);

    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
    return 4;
}
System_IntPtr Dummy2(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);

    if (!System_Atomic_expect(&Parent_current.number, 2, 3))
        System_Console_writeLine("Child{0:uint}: This wasn't 2", 1, argv[0]);
    else
        System_Console_writeLine("Child{0:uint}: This was 2, now this is 3", 1, argv[0]);

    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
    return 2;
}
System_IntPtr Dummy3(System_Size argc, System_Var argv[]) {

    System_Size old_number = Parent_current.number;
    if (System_Atomic_expect(&Parent_current.number, 1, 2))
        System_Console_writeLine("Child{0:uint}: This was 1, now this is 2", 1, argv[0]);
    else
        System_Console_writeLine("Child{0:uint}: This wasn't 1", 1, argv[0]);

    System_Thread_sleep(2);

    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
    if (!System_Thread_Current)
        System_Console_write__string("System_Thread_Current: 0x0\n");
    else
        System_Console_writeLine("System_Thread_Current: 0x{0:uint:hex}, base.type 0x{1:uint:hex}, threadId {2:int32}, returnValue {3:uint32}", 4, System_Thread_Current, System_Thread_Current->base.type, System_Thread_Current->threadId, System_Thread_Current->returnValue);
    return true;
}

void System_Runtime_sigfault(System_Signal_Number number, System_Signal_Info info, System_Var context) {
    System_Console_writeLine("{0:string}: number {1:uint32}, errno {2:uint32}, code {3:uint32}, sigfault.address {4:uint:hex}", 5,
        System_Signal_Number_toString(number), info->number, info->errno, info->code, info->sigfault.address);
    System_Syscall_terminate(false);
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

    System_Console_writeLine("System_Thread_PID: {0:uint32}", 1, System_Thread_PID);

    System_Size dummyC = 0;
    System_Thread dummys[64]; System_Stack_clear(dummys);

    dummys[dummyC++] = System_Thread_create((function_System_Thread_main)Dummy0, 1, 0);
    dummys[dummyC++] = System_Thread_create(Dummy1, 1, 1);
    dummys[dummyC++] = System_Thread_create(Dummy2, 1, 2);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 3);
    dummys[dummyC++] = System_Thread_create(Dummy3, 1, 4);

    System_Bool retures[64]; System_Stack_clear(retures);

    while (true) {

        for (System_Size i = 0; i < dummyC; ++i)
            if (dummys[i]->threadId) {
                retures[i] = System_Thread_join__dontwait(dummys[i], true);
                if (!retures[i]) System_Console_writeLine("Wait on Child{0:uint}", 1, i);
                else System_Console_writeLine("This is Child{0:uint}, returning {1:uint:hex}", 2, i, dummys[i]->returnValue);
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

