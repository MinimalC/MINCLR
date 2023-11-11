#define using_System
#include <min/System.h>

IntPtr runSIGSEGV(Size argc, Var argv[]) {

    void (* run)() = (Var)65535;
    run();
}

IntPtr runSIGILL(Size argc, Var argv[]) {

    __builtin_trap();
}

IntPtr runSIGFPE(Size argc, Var argv[]) {

    int divident = 5;
    int divisor = 0;
    float quotient = divident / divisor;
}

const System_STRING8 bus = "F       ";

IntPtr runSIGBUS(Size argc, Var argv[]) {

    __asm__("pushf\norl $0x40000,(%rsp)\npopf");
    
    System_Char8 * charbus = (System_Char8 *)&bus;
    System_IntPtr * intbus = (System_IntPtr *)++charbus;

    * intbus = 42;

    return 0;
}

void System_Runtime_sigfault(System_Signal_Number number, System_Signal_Info info, System_Var context) {
    System_Console_writeLine("{0:string}: number {1:uint32}, errno {2:uint32}, code {3:uint32}, sigfault.address {4:uint:hex}", 5,
        System_Signal_Number_toString(number), info->number, info->errno, info->code, info->sigfault.address);
    System_Syscall_terminate(false);
}

int System_Runtime_main(int argc, char * argv[]) {

    System_Signal_unblock__number(System_Signal_Number_SIGILL);
    System_Signal_unblock__number(System_Signal_Number_SIGFPE);
    System_Signal_unblock__number(System_Signal_Number_SIGSEGV);
    System_Signal_unblock__number(System_Signal_Number_SIGBUS);
    System_Signal_act(System_Signal_Number_SIGILL, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Number_SIGFPE, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Number_SIGSEGV, System_Runtime_sigfault);
    System_Signal_act(System_Signal_Number_SIGBUS, System_Runtime_sigfault);

    System_Thread thread1 = System_Thread_create(runSIGSEGV, 0);
    System_Thread_join(thread1);
    System_Memory_free(thread1);

    System_Thread thread2 = System_Thread_create(runSIGILL, 0);
    System_Thread_join(thread2);
    System_Memory_free(thread2);

    System_Thread thread3 = System_Thread_create(runSIGFPE, 0);
    System_Thread_join(thread3);
    System_Memory_free(thread3);

    System_Console_writeLine__string("SUCCESS");

    System_Thread thread4 = System_Thread_create(runSIGBUS, 0);
    System_Thread_join(thread4);
    System_Memory_free(thread4);

    return true;
}
