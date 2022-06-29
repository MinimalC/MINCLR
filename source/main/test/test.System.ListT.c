#define using_System
#include <min/System.h>

struct_string8  STRING8_Hallo = "Hallo";

//main(test05_System_ListT, args) {
int main(int argc, char * argv[]) {
    size i = 0, length = 128, good = 0, good1 = 0, good2 = 0;

    List objects = List_new();
    for (good = 0, i = 0; i < length; ++i) {
        Object object = Object_new();
        List_add(objects, object);
        Object_freeClass(&object);
        ++good;
    }
    good1 = 0;
    inline_System_foreach(System_Object,object1, objects, {
        if (object1) ++good1;
    })
    good2 = 0;
    stack_System_foreach(System_Object,object2, System_List,objects, {
       if (object2) ++good2;
    })
    if (objects && good == 128 && good1 == 128 && good2 == 128)
         Console_writeLine("Test10: SUCCESS: List_new({0:uint})", 1, i);
    else Console_writeLine("Test10: ERROR: List_new({0:uint})", 1, i);
    Object_freeClass(&objects);

    return true;
}
