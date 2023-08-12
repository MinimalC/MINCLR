#define using_System
#include <min/System.h>


void Dummy0(System_Size argc, System_Var argv[]) {

    System_Thread_sleep(4);
    System_Console_writeLine("This is Child{0:uint}", 1, argv[0]);
}
void Dummy1(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("This is Child{0:uint}", 1, argv[1]);
}
void Dummy2(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("This is Child{0:uint}", 1, argv[2]);
}
void Dummy3(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("This is Child{0:uint}", 1, argv[3]);
}
void Dummy4(System_Size argc, System_Var argv[]) {

    System_Console_writeLine("This is Child{0:uint}", 1, argv[4]);
}

int System_Runtime_main(int argc, char * argv[]) {

    System_Size argc1 = 10;
    System_Size argv1[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    System_IntPtr dummy0 = System_Thread_create(Dummy0, argc1, (System_Var *)argv1);
    System_Thread_create(Dummy1, argc1, (System_Var *)argv1);
    System_Thread_create(Dummy2, argc1, (System_Var *)argv1);
    System_Thread_create(Dummy3, argc1, (System_Var *)argv1);
    System_Thread_create(Dummy4, argc1, (System_Var *)argv1);

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

