#define using_System
#include <min/System.h>

import thread System_Thread __Current;

void Dummy0(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);
    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
}
System_IntPtr Dummy1(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);
    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
    return 4;
}
System_IntPtr Dummy2(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);
    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
    return true;
}
void Dummy3(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(2);

    System_Console_writeLine("__Current: 0x{0:uint:hex}", 1, __Current);

    if (__Current)
        System_Console_writeLine("__Current: base.type 0x{0:uint:hex}, threadId {1:uint}, returnValue {2:uint}", 3, __Current->base.type, __Current->threadId, __Current->returnValue);

    return;
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

    System_Console_writeLine("System_Process_Id: {0:uint32}", 1, System_Process_Id);

    System_Size dummyC = 0;
    System_Thread dummys[64]; System_Stack_clear(dummys);

    dummys[dummyC++] = System_Thread_create((function_System_Thread_main)Dummy0, 1, 0);
    dummys[dummyC++] = System_Thread_create(Dummy1, 1, 1);
    dummys[dummyC++] = System_Thread_create(Dummy2, 1, 2);
    dummys[dummyC++] = System_Thread_create((function_System_Thread_main)Dummy3, 1, 3);
    dummys[dummyC++] = System_Thread_create((function_System_Thread_main)Dummy3, 1, 4);

    /*System_Console_writeLine__string("Wait on Child0");
    System_Bool reture = System_Thread_join(dummy0);*/

    System_Bool retures[64]; System_Stack_clear(retures);

    while (1) {

        for (System_Size i = 0; i < dummyC; ++i)
            if (dummys[i]->threadId) {
                retures[i] = System_Thread_join__dontwait(dummys[i], true);
                if (!retures[i]) System_Console_writeLine("Wait on Child{0:uint}", 1, i);
                else System_Console_writeLine("Wait on Child{0:uint}. Returning {1:uint:hex}", 2, i, dummys[i]->returnValue);
            }

        System_Size r = 0;
        for (System_Size i = 0; i < dummyC; ++i)
            if (retures[i]) ++r;
        if (r == dummyC) break;

        System_Thread_sleep(1);
    }

    for (System_Size i = 0; i < dummyC; ++i)
        System_Memory_free(dummys[i]);
    
    System_Console_writeLine__string("This is Parent");

    return true;
}

