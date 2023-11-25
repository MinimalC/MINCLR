#define using_System
#include <min/System.h>

import thread System_Var __Storage;
import thread System_Size __ErrorCode;
import thread System_Exception __Exception;
import thread struct System_Thread __Current;

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
    return 0;
}
void Dummy3(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(2);
    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);

    System_Console_writeLine("System_Thread_Storage: {0:uint}", 1, __Storage);
    System_Console_writeLine("System_Thread_ErrorCode: {0:uint}", 1, __ErrorCode);
    System_Size errorCode = System_Thread_Storage_getErrorCode();
    System_Thread_Storage_setErrorCode(++errorCode);
    System_Console_writeLine("System_Thread_Exception: {0:uint}", 1, __Exception);
    System_Console_writeLine("System_Thread_Current: base.type 0x{0:uint:hex}, threadId {1:uint}, returnValue {2:uint}", 3, __Current.base.type, __Current.threadId, __Current.returnValue);
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

    System_Thread dummy0 = System_Thread_create((function_System_Thread_main)Dummy0, 1, 0);
    System_Thread dummy1 = System_Thread_create(Dummy1, 1, 1);
    System_Thread dummy2 = System_Thread_create(Dummy2, 1, 2);
    System_Thread dummy3 = System_Thread_create((function_System_Thread_main)Dummy3, 1, 3);
    System_Thread dummy4 = System_Thread_create((function_System_Thread_main)Dummy3, 1, 4);

    /*System_Console_writeLine__string("Wait on Child0");
    System_Bool reture = System_Thread_join(dummy0);*/

    while (1) {
        System_Bool reture0 = false, reture1 = false, reture2 = false;

        if (dummy0->threadId) {
            reture0 = System_Thread_join__dontwait(dummy0, true);
            if (!reture0) System_Console_writeLine__string("Wait on Child0");
            else System_Console_writeLine("Wait on Child0. Returning {0:uint:hex}", 1, dummy0->returnValue);
        }

        if (dummy1->threadId) {
            reture1 = System_Thread_join__dontwait(dummy1, true);
            if (!reture1) System_Console_writeLine__string("Wait on Child1");
            else System_Console_writeLine("Wait on Child1. Returning {0:uint:hex}", 1, dummy1->returnValue);
        }

        if (dummy2->threadId) {
            reture2 = System_Thread_join__dontwait(dummy2, true);
            if (!reture2) System_Console_writeLine__string("Wait on Child2");
            else System_Console_writeLine("Wait on Child2. Returning {0:uint:hex}", 1, dummy2->returnValue);
        }

        if (!dummy0->threadId && !dummy1->threadId && !dummy2->threadId) break;

        System_Thread_sleep(1);
    }

    System_Memory_free(dummy0);
    System_Memory_free(dummy1);
    System_Memory_free(dummy2);
    System_Memory_free(dummy3);
    System_Memory_free(dummy4);
    
    System_Console_writeLine__string("This is Parent");

    return true;
}

