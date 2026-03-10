#define using_System
#include <min/System.h>

Bool System_Runtime_CTRLC = false;

void System_Runtime_ALARM(System_Signal_Number number, System_Signal_Info info, System_Var context) {

	System_Runtime_CTRLC = !System_Runtime_CTRLC;
	Console_writeLine__string("ALARM");
}

enum {
    SIG_BLOCK,      // Block signals.
    SIG_UNBLOCK,    // Unblock signals.
    SIG_SETMASK,    // Set the set of blocked signals.
};

enum {  _SIGSET_NWORDS =	(64 / (8 * sizeof (unsigned long))), };
enum {  _SIGEV_PAD_SIZE =	((64 / sizeof(int)) - 4), };

IntPtr System_Runtime_thread(Size argc, Var argv[]) {

    return true;
}

int System_Runtime_main(int argc, char * argv[]) {

    Console_writeLine("SIGSET_NWORDS: {0:uint}", 1, _SIGSET_NWORDS);
    Console_writeLine("SIGEV_PAD_SIZE: {0:uint}", 1, _SIGEV_PAD_SIZE);
    Console_writeLine("sizeof (unsigned long): {0:uint}", 1, sizeof (unsigned long));
    Console_writeLine("sizeof (unsigned int): {0:uint}", 1, sizeof (unsigned int));

    /*System_Thread thread0 = System_Thread_create(System_Runtime_thread, 0, null);
    System_Thread_join(thread0);
    System_Memory_free(thread0);*/


    System_Signal_Number signal; System_Stack_clear(signal);
    signal |= ((System_Signal_Number)1 << (System_Signal_Number_SIGALARM - 1));
    System_Syscall_sigprocmask(SIG_UNBLOCK, &signal, null, sizeof(System_Signal_Number));
	System_Signal_act(System_Signal_Number_SIGALARM, System_Runtime_ALARM);

	IntPtr timerId = 0;
	
    struct System_Signal_Event sigevent; Stack_clear(sigevent);
    sigevent.value = 0;
    sigevent.number = System_Signal_Number_SIGALARM;
    sigevent.notify = System_Signal_Notify_Signal;
    System_Syscall_timer_create(0 /* CLOCK_REALTIME */, &sigevent, &timerId);

    struct System_IntervalTimeSpan itimespan; Stack_clear(itimespan);
    itimespan.interval.sec = 2;
    itimespan.value.sec = 2;
    System_Syscall_timer_settime(timerId, 0 /* flags TIMER_ABSTIME */, &itimespan, null);


	/* work something */
	UInt16 i = 0;
    while (!System_Runtime_CTRLC) {
		if (++i == 0) { Console_writeLine__string("overrun"); break; }

		System_Thread_sleep(1);
	}

	i = 0;
    while (System_Runtime_CTRLC) {
		if (++i == 0) { Console_writeLine__string("overrun"); break; }

		System_Thread_sleep(1);
	}

	struct System_Signal_Info siginfo; Stack_clear(siginfo);
    System_Syscall_sigprocmask(SIG_SETMASK, &signal, null, sizeof(System_Signal_Number));
	System_Syscall_sigwaitinfo((System_Var)&signal, &siginfo);
	System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) {
        System_Console_writeLine("System_Syscall_sigwaitinfo Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
        return false;
    }

	Console_writeLine__string("THE END");
	return true;
}
