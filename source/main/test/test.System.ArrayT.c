#define using_System
#include <min/System.h>

struct_string8  STRING8_Hallo = "Hallo";

//main(test04_System_ArrayT, args) {
int main(int argc, char * argv[]) {
    size i = 0, length = 0, good = 0, good1 = 0, good2 = 0;

    uint8Array uint8s = uint8Array_new(64);
    length = uint8Array_get_Length(uint8s);
    for (good = 0, i = 0; i < length; ++i) {
        uint8 uint8 = uint8Array_get_index(uint8s, i);
        if (uint8 != 0) continue;
        uint8Array_set_index(uint8s, i, 1);
        uint8 = uint8Array_get_index(uint8s, i);
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
         Console_writeLine("Test01: SUCCESS: uint8Array_new({0:uint})", 1, i);
    else Console_writeLine("Test01: ERROR: uint8Array_new({0:uint), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&uint8s);

    uint16Array uint16s = uint16Array_new(64);
    length = uint16Array_get_Length(uint16s);
    for (good = 0, i = 0; i < length; ++i) {
        uint16 uint16 = uint16Array_get_index(uint16s, i);
        if (uint16 != 0) continue;
        uint16Array_set_index(uint16s, i, 1);
        uint16 = uint16Array_get_index(uint16s, i);
        if (uint16 != 1) continue;
        ++good;
    }
    if (uint16s && good == i)
         Console_writeLine("Test02: SUCCESS: uint16Array_new({0:uint})", 1, i);
    else Console_writeLine("Test02: ERROR: uint16Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&uint16s);

    uint32Array uint32s = uint32Array_new(64);
    length = uint32Array_get_Length(uint32s);
    for (good = 0, i = 0; i < length; ++i) {
        uint32 uint32 = uint32Array_get_index(uint32s, i);
        if (uint32 != 0) continue;
        uint32Array_set_index(uint32s, i, 1);
        uint32 = uint32Array_get_index(uint32s, i);
        if (uint32 != 1) continue;
        ++good;
    }
    if (uint32s && good == i) Console_writeLine("Test03: SUCCESS: uint32Array_new({0:uint})", 1, i);
    else Console_writeLine("Test03: ERROR: uint32Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&uint32s);

    uint64Array uint64s = uint64Array_new(64);
    length = uint64Array_get_Length(uint64s);
    for (good = 0, i = 0; i < length; ++i) {
        uint64 uint64 = uint64Array_get_index(uint64s, i);
        if (uint64 != 0) continue;
        uint64Array_set_index(uint64s, i, 1);
        uint64 = uint64Array_get_index(uint64s, i);
        if (uint64 != 1) continue;
        ++good;
    }
    if (uint64s && good == i) Console_writeLine("Test04: SUCCESS: uint64Array_new({0:uint})", 1, i);
    else Console_writeLine("Test04: ERROR: uint64Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&uint64s);

    int8Array int8s = int8Array_new(64);
    length = int8Array_get_Length(int8s);
    for (good = 0, i = 0; i < length; ++i) {
        int8 int8 = int8Array_get_index(int8s, i);
        if (int8 != 0) continue;
        int8Array_set_index(int8s, i, -1);
        int8 = int8Array_get_index(int8s, i);
        if (int8 != -1) continue;
        ++good;
    }
    if (int8s && good == i) Console_writeLine("Test05: SUCCESS: int8Array_new({0:uint})", 1, i);
    else Console_writeLine("Test05: ERROR: int8Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&int8s);

    int16Array int16s = int16Array_new(64);
    length = int16Array_get_Length(int16s);
    for (good = 0, i = 0; i < length; ++i) {
        int16 int16 = int16Array_get_index(int16s, i);
        if (int16 != 0) continue;
        int16Array_set_index(int16s, i, 1);
        int16 = int16Array_get_index(int16s, i);
        if (int16 != 1) continue;
        ++good;
    }
    if (int16s && good == i) Console_writeLine("Test06: SUCCESS: int16Array_new({0:uint})", 1, i);
    else Console_writeLine("Test06: ERROR: int16Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&int16s);

    int32Array int32s = int32Array_new(64);
    length = int32Array_get_Length(int32s);
    for (good = 0, i = 0; i < length; ++i) {
        int32 int32 = int32Array_get_index(int32s, i);
        if (int32 != 0) continue;
        int32Array_set_index(int32s, i, 1);
        int32 = int32Array_get_index(int32s, i);
        if (int32 != 1) continue;
        ++good;
    }
    if (int32s && good == i) Console_writeLine("Test07: SUCCESS: int32Array_new({0:uint})", 1, i);
    else Console_writeLine("Test07: ERROR: int32Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&int32s);

    int64Array int64s = int64Array_new(64);
    length = int64Array_get_Length(int64s);
    for (good = 0, i = 0; i < length; ++i) {
        int64 int64 = int64Array_get_index(int64s, i);
        if (int64 != 0) continue;
        int64Array_set_index(int64s, i, 1);
        int64 = int64Array_get_index(int64s, i);
        if (int64 != 1) continue;
        ++good;
    }
    if (int64s && good == i) Console_writeLine("Test08: SUCCESS: int64Array_new({0:uint})", 1, i);
    else Console_writeLine("Test08: ERROR: int64Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&int64s);

    string8Array string8s = string8Array_new(64);
    length = string8Array_get_Length(string8s);
    for (good = 0, i = 0; i < length; ++i) {
        string8 string8 = string8Array_get_index(string8s, i);
        if (string8) continue;
        string8Array_set_index(string8s, i, STRING8_Hallo);
        string8 = string8Array_get_index(string8s, i);
        if (!string8_equals(string8, STRING8_Hallo)) continue;
        ++good;
    }
    if (string8s && good == i) Console_writeLine("Test09: SUCCESS: string8Array_new({0:uint})", 1, i);
    else Console_writeLine("Test09: ERROR: string8Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&string8s);

    /* Test11: Use System_Object with for and foreach */
    Array Objects = Array_new(64);
    length = Array_get_Length(Objects);
    for (good = 0, i = 0; i < length; ++i) {
        Object Object = Array_get_index(Objects, i);
        if (Object) continue;
        Object = Object_new();
        Array_set_index(Objects, i, Object);
        Object_freeClass(&Object);
        Object = Array_get_index(Objects, i);
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
    if (Objects && good == 64 && good1 == 64 && good2 == 64) Console_writeLine("Test10: SUCCESS: Array_new({0:uint})", 1, i);
    else Console_writeLine("Test10: ERROR: Array_new({0:uint}), {1:uint} failed", 2, i, i - good);
    Object_freeClass(&Objects);

    return true;
}
