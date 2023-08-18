#define using_System
#include <min/System.h>


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

    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
}


int System_Runtime_main(int argc, char * argv[]) {


    System_Thread dummy0 = System_Thread_create((function_System_Thread_main)Dummy0, 1, 0);
    System_Thread dummy1 = System_Thread_create(Dummy1, 1, 1);
    System_Thread dummy2 = System_Thread_create(Dummy2, 1, 2);
    System_Thread dummy3 = System_Thread_create((function_System_Thread_main)Dummy3, 1, 3);
    System_Thread dummy4 = System_Thread_create((function_System_Thread_main)Dummy3, 1, 4);

    /*System_Console_writeLine__string("Wait on Child0");
    System_Bool reture = System_Thread_join(dummy0);*/

    System_IntPtr reture0 = false, reture1 = false,reture2 = false;
    while (1) {
        if (!reture0) reture0 = System_Thread_join__dontwait(dummy0, true);
        if (!reture0) System_Console_writeLine__string("Wait on Child0");

        if (!reture1) reture1 = System_Thread_join__dontwait(dummy1, true);
        if (!reture1) System_Console_writeLine__string("Wait on Child1");

        if (!reture2) reture2 = System_Thread_join__dontwait(dummy2, true);
        if (!reture2) System_Console_writeLine__string("Wait on Child2");

        if (reture0 && reture1 && reture2) break;

        System_Thread_sleep(1);
    }

    if (reture0) System_Console_writeLine("Wait on Child0. Returning {0:uint:hex}", 1, reture0);
    if (reture1) System_Console_writeLine("Wait on Child1. Returning {0:uint:hex}", 1, reture1);
    if (reture2) System_Console_writeLine("Wait on Child2. Returning {0:uint:hex}", 1, reture2);
    
    System_Console_writeLine("This is Parent: {0:bool}", 1, reture0);

    return true;
}

