#define using_System
#include <min/System.h>

struct_string8  STRING8_Hallo = "Hallo";

__main(test05_System_ListT, args) {
    __size i = 0, length = 128, good = 0, good1 = 0, good2 = 0;

    __List objects = __List_new();
    for (good = 0, i = 0; i < length; ++i) {
        __Object object = __Object_new();
        __List_add(objects, object);
        __Object_freeClass(&object);
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
    if (objects && good == 128 && good1 == 128 && good2 == 128) __Console_printLine("Test10: SUCCESS: __List_new(%u)", i);
    else __Console_printLine("Test10: ERROR: __List_new(%u)", i);
    __Object_freeClass(&objects);

    return __true;
}
