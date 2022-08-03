#define using_System
#include <min/System.h>

STRING8  STRING8_Hallo = "Hallo";

#define main  System_Runtime_main

//main(test05_System_ListT, args) {
int main(int argc, char * argv[]) {
    Size i = 0, length = 128, good = 0, good1 = 0, good2 = 0;

    List objects = new_List();
    for (good = 0, i = 0; i < length; ++i) {
        Object object = new_Object();
        List_add(objects, object);
        Memory_free(object);
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
         Console_writeLine("Test10: SUCCESS: new_List({0:uint})", 1, i);
    else Console_writeLine("Test10: ERROR: new_List({0:uint})", 1, i);
    Memory_free(objects);

    return true;
}
