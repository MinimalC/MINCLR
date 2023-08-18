#define using_System
#include <min/System.h>


void Dummy0(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);
    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
}
void Dummy1(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
}

int System_Runtime_main(int argc, char * argv[]) {


    System_Thread dummy0 = System_Thread_create(Dummy0, 1, 0);
    System_Thread_create(Dummy1, 1, 1);
    System_Thread_create(Dummy1, 1, 2);
    System_Thread_create(Dummy1, 1, 3);
    System_Thread_create(Dummy1, 1, 4);

    /*System_Console_writeLine__string("Wait on Child0");
    System_Bool reture = System_Thread_join(dummy0);*/

    System_Bool reture = false;
    while (!(reture = System_Thread_join__dontwait(dummy0, true))) {
        System_Console_writeLine__string("Wait on Child0");
        System_Thread_sleep(1);
    }
    
    System_Console_writeLine("This is Parent: {0:bool}", 1, reture);

    return true;
}

