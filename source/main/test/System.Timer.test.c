#define using_System
#include <min/System.h>

Bool System_Runtime_CTRLC = false;

void System_Runtime_ALARM(System_Signal_Number number, System_Signal_Info info, System_Var context) {

	System_Runtime_CTRLC = !System_Runtime_CTRLC;
	Console_writeLine__string("ALARM");
}

IntPtr System_Runtime_thread(Size argc, Var argv[]) {

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
    return true;
}

int System_Runtime_main(int argc, char * argv[]) {

    System_Thread thread0 = System_Thread_create(System_Runtime_thread, 0, null);
    
	UInt16 i = 0;
    while (!System_Thread_join__dontwait(thread0, true)) {
		if (++i == 0) { Console_writeLine__string("overrun"); break; }

		System_Thread_sleep(1);
        
        System_Runtime_ALARM(System_Signal_Number_SIGALARM, null, null);
    }
    System_Memory_free(thread0);

	Console_writeLine__string("THE END");
	return true;
}
