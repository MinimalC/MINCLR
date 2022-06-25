#define using_System
#include <min/System.h>
/* #include "../../crypto_blake2b.h" */

struct_string8  string8_System_Object = "System.Object";

//__main(test02_System_Object, args) {
int main(int argc, char * argv[]) {

    __Object object = __Object_new();
    if (!object)
        __Console_writeLine__string8("Test01: ERROR: __Object_new");
    else
        __Console_writeLine__string8("Test01: SUCCESS: __Object_new");


    __Type type = __Object_get_Type(object);
    if (!type || !__string8_equals(string8_System_Object, type->name))
        __Console_writeLine__string8("Test02: ERROR: __Object_get_Type");
    else
        __Console_writeLine__string8("Test02: SUCCESS: __Object_get_Type");


    __Object_freeClass(&object);
    if (object)
        __Console_writeLine__string8("Test03: ERROR: __Object_freeClass");
    else
        __Console_writeLine__string8("Test03: SUCCESS: __Object_freeClass");

    return __true;
}
