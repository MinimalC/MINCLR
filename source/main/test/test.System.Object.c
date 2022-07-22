#define using_System
#include <min/System.h>
/* #include "../../crypto_blake2b.h" */

STRING8  String8_System_Object = "System.Object";

//main(test02_System_Object, args) {
int main(int argc, char * argv[]) {

    Object object = new_Object();
    if (!object)
        Console_writeLine__String8("Test01: ERROR: new_Object");
    else
        Console_writeLine__String8("Test01: SUCCESS: new_Object");


    Type type = Object_get_Type(object);
    if (!type || !String8_equals(String8_System_Object, type->name))
        Console_writeLine__String8("Test02: ERROR: Object_get_Type");
    else
        Console_writeLine__String8("Test02: SUCCESS: Object_get_Type");


    Memory_free(object);
    if (object)
        Console_writeLine__String8("Test03: ERROR: Memory_free");
    else
        Console_writeLine__String8("Test03: SUCCESS: Memory_free");

    return true;
}
