#define using_System
#include <min/System.h>

struct_string8  STRING8_Hallo = "Hallo";

//__main(test04_System_ArrayT, args) {
int main(int argc, char * argv[]) {
    __size i = 0, length = 0, good = 0, good1 = 0, good2 = 0;

    __uint8Array uint8s = __uint8Array_new(64);
    length = __uint8Array_get_Length(uint8s);
    for (good = 0, i = 0; i < length; ++i) {
        __uint8 uint8 = __uint8Array_get_index(uint8s, i);
        if (uint8 != 0) continue;
        __uint8Array_set_index(uint8s, i, 1);
        uint8 = __uint8Array_get_index(uint8s, i);
        if (uint8 != 1) continue;
        ++good;
    }
    /* good1 = 0;
    inline_System_foreach(System_uint8,uint81, uint8s, {
        if (uint81) ++good1;
    }) */
    good2 = 0;
    stack_System_foreach(System_uint8,uint82, System_uint8Array,uint8s, {
       if (uint82) ++good2;
    })
    if (uint8s && good == 64 /* && good1 == 64 */ && good2 == 64)
         __Console_writeLine("Test01: SUCCESS: __uint8Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test01: ERROR: __uint8Array_new({0:uint), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&uint8s);

    __uint16Array uint16s = __uint16Array_new(64);
    length = __uint16Array_get_Length(uint16s);
    for (good = 0, i = 0; i < length; ++i) {
        __uint16 uint16 = __uint16Array_get_index(uint16s, i);
        if (uint16 != 0) continue;
        __uint16Array_set_index(uint16s, i, 1);
        uint16 = __uint16Array_get_index(uint16s, i);
        if (uint16 != 1) continue;
        ++good;
    }
    if (uint16s && good == i)
         __Console_writeLine("Test02: SUCCESS: __uint16Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test02: ERROR: __uint16Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&uint16s);

    __uint32Array uint32s = __uint32Array_new(64);
    length = __uint32Array_get_Length(uint32s);
    for (good = 0, i = 0; i < length; ++i) {
        __uint32 uint32 = __uint32Array_get_index(uint32s, i);
        if (uint32 != 0) continue;
        __uint32Array_set_index(uint32s, i, 1);
        uint32 = __uint32Array_get_index(uint32s, i);
        if (uint32 != 1) continue;
        ++good;
    }
    if (uint32s && good == i) __Console_writeLine("Test03: SUCCESS: __uint32Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test03: ERROR: __uint32Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&uint32s);

    __uint64Array uint64s = __uint64Array_new(64);
    length = __uint64Array_get_Length(uint64s);
    for (good = 0, i = 0; i < length; ++i) {
        __uint64 uint64 = __uint64Array_get_index(uint64s, i);
        if (uint64 != 0) continue;
        __uint64Array_set_index(uint64s, i, 1);
        uint64 = __uint64Array_get_index(uint64s, i);
        if (uint64 != 1) continue;
        ++good;
    }
    if (uint64s && good == i) __Console_writeLine("Test04: SUCCESS: __uint64Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test04: ERROR: __uint64Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&uint64s);

    __int8Array int8s = __int8Array_new(64);
    length = __int8Array_get_Length(int8s);
    for (good = 0, i = 0; i < length; ++i) {
        __int8 int8 = __int8Array_get_index(int8s, i);
        if (int8 != 0) continue;
        __int8Array_set_index(int8s, i, -1);
        int8 = __int8Array_get_index(int8s, i);
        if (int8 != -1) continue;
        ++good;
    }
    if (int8s && good == i) __Console_writeLine("Test05: SUCCESS: __int8Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test05: ERROR: __int8Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&int8s);

    __int16Array int16s = __int16Array_new(64);
    length = __int16Array_get_Length(int16s);
    for (good = 0, i = 0; i < length; ++i) {
        __int16 int16 = __int16Array_get_index(int16s, i);
        if (int16 != 0) continue;
        __int16Array_set_index(int16s, i, 1);
        int16 = __int16Array_get_index(int16s, i);
        if (int16 != 1) continue;
        ++good;
    }
    if (int16s && good == i) __Console_writeLine("Test06: SUCCESS: __int16Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test06: ERROR: __int16Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&int16s);

    __int32Array int32s = __int32Array_new(64);
    length = __int32Array_get_Length(int32s);
    for (good = 0, i = 0; i < length; ++i) {
        __int32 int32 = __int32Array_get_index(int32s, i);
        if (int32 != 0) continue;
        __int32Array_set_index(int32s, i, 1);
        int32 = __int32Array_get_index(int32s, i);
        if (int32 != 1) continue;
        ++good;
    }
    if (int32s && good == i) __Console_writeLine("Test07: SUCCESS: __int32Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test07: ERROR: __int32Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&int32s);

    __int64Array int64s = __int64Array_new(64);
    length = __int64Array_get_Length(int64s);
    for (good = 0, i = 0; i < length; ++i) {
        __int64 int64 = __int64Array_get_index(int64s, i);
        if (int64 != 0) continue;
        __int64Array_set_index(int64s, i, 1);
        int64 = __int64Array_get_index(int64s, i);
        if (int64 != 1) continue;
        ++good;
    }
    if (int64s && good == i) __Console_writeLine("Test08: SUCCESS: __int64Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test08: ERROR: __int64Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&int64s);

    __string8Array string8s = __string8Array_new(64);
    length = __string8Array_get_Length(string8s);
    for (good = 0, i = 0; i < length; ++i) {
        __string8 string8 = __string8Array_get_index(string8s, i);
        if (string8) continue;
        __string8Array_set_index(string8s, i, STRING8_Hallo);
        string8 = __string8Array_get_index(string8s, i);
        if (!__string8_equals(string8, STRING8_Hallo)) continue;
        ++good;
    }
    if (string8s && good == i) __Console_writeLine("Test09: SUCCESS: __string8Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test09: ERROR: __string8Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&string8s);

    /* Test11: Use System_Object with for and __foreach */
    __Array Objects = __Array_new(64);
    length = __Array_get_Length(Objects);
    for (good = 0, i = 0; i < length; ++i) {
        __Object Object = __Array_get_index(Objects, i);
        if (Object) continue;
        Object = __Object_new();
        __Array_set_index(Objects, i, Object);
        __Object_freeClass(&Object);
        Object = __Array_get_index(Objects, i);
        if (!Object || !System_Object_get_Type(Object)) continue;
        ++good;
    }
    good1 = 0;
    inline_System_foreach__(System_Object,object1, Objects, {
        if (object1) ++good1;
    })
    good2 = 0;
    stack_System_foreach__(System_Object,object2, System_Array,Objects, {
       if (object2) ++good2;
    })
    if (Objects && good == 64 && good1 == 64 && good2 == 64) __Console_writeLine("Test10: SUCCESS: __Array_new({0:uint})", 1, i);
    else __Console_writeLine("Test10: ERROR: __Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    __Object_freeClass(&Objects);

    return __true;
}
