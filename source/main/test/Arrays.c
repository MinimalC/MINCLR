#define using_System
#include <min/System.h>

__main(test_Arrays, args) {

    base_System_StreamWriter_write(__null, "Hallo {0} {1} {2}!", &(struct_System_Array)stack_System_Array( 3,
        (System_Object)&System_ObjectType, (System_Object)&System_TypeType, (System_Object)&System_ExceptionType ));

    return __true;
}
