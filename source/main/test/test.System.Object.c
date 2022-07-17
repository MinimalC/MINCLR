#define using_System
#include <min/System.h>
/* #include "../../crypto_blake2b.h" */

struct_string8  string8_System_Object = "System.Object";

//main(test02_System_Object, args) {
int main(int argc, char * argv[]) {

    Object object = Object_new();
    if (!object)
        Console_writeLine__string8("Test01: ERROR: Object_new");
    else
        Console_writeLine__string8("Test01: SUCCESS: Object_new");


    Type type = Object_get_Type(object);
    if (!type || !string8_equals(string8_System_Object, type->name))
        Console_writeLine__string8("Test02: ERROR: Object_get_Type");
    else
        Console_writeLine__string8("Test02: SUCCESS: Object_get_Type");


    System_Memory_freeClass(&object);
    if (object)
        Console_writeLine__string8("Test03: ERROR: Object_freeClass");
    else
        Console_writeLine__string8("Test03: SUCCESS: Object_freeClass");

    return true;
}
