#define using_System
#include <min/System.h>

STRING8  STRING8_Hallo = "Hallo";

int System_Runtime_main(int argc, char * argv[]) {
    Size i = 0, length = 0, good = 0, good1 = 0, good2 = 0;

    UInt8Array uint8s = new_UInt8Array(64);
    length = uint8Array_get_Length(uint8s);
    for (good = 0, i = 0; i < length; ++i) {
        UInt8 uint8 = UInt8Array_get_index(uint8s, i);
        if (uint8 != 0) continue;
        uint8Array_set_index(uint8s, i, 1);
        uint8 = UInt8Array_get_index(uint8s, i);
        if (uint8 != 1) continue;
        ++good;
    }
    /* good1 = 0;
    inline_System_foreach(System_UInt8,uint81, uint8s, {
        if (uint81) ++good1;
    }) */
    good2 = 0;
    stack_System_foreach(System_UInt8,uint82, System_UInt8Array,uint8s, {
       if (uint82) ++good2;
    })
    if (uint8s && good == 64 /* && good1 == 64 */ && good2 == 64)
         Console_writeLine("Test01: SUCCESS: uint8Array({0:uint})", 1, i);
    else Console_writeLine("Test01: ERROR: uint8Array({0:uint), {1:uint} failed", 2, i, i - good);
    Memory_free(uint8s);

    UInt16Array uint16s = new_UInt16Array(64);
    length = uint16Array_get_Length(uint16s);
    for (good = 0, i = 0; i < length; ++i) {
        UInt16 uint16 = UInt16Array_get_index(uint16s, i);
        if (uint16 != 0) continue;
        UInt16Array_set_index(uint16s, i, 1);
        uint16 = UInt16Array_get_index(uint16s, i);
        if (uint16 != 1) continue;
        ++good;
    }
    if (uint16s && good == i)
         Console_writeLine("Test02: SUCCESS: uint16Array({0:uint})", 1, i);
    else Console_writeLine("Test02: ERROR: uint16Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(uint16s);

    UInt32Array uint32s = new_UInt32Array(64);
    length = UInt32Array_get_Length(uint32s);
    for (good = 0, i = 0; i < length; ++i) {
        UInt32 uint32 = UInt32Array_get_index(uint32s, i);
        if (uint32 != 0) continue;
        UInt32Array_set_index(uint32s, i, 1);
        uint32 = UInt32Array_get_index(uint32s, i);
        if (uint32 != 1) continue;
        ++good;
    }
    if (uint32s && good == i) Console_writeLine("Test03: SUCCESS: uint32Array({0:uint})", 1, i);
    else Console_writeLine("Test03: ERROR: uint32Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(uint32s);

    UInt64Array uint64s = new_UInt64Array(64);
    length = UInt64Array_get_Length(uint64s);
    for (good = 0, i = 0; i < length; ++i) {
        UInt64 uint64 = UInt64Array_get_index(uint64s, i);
        if (uint64 != 0) continue;
        UInt64Array_set_index(uint64s, i, 1);
        uint64 = UInt64Array_get_index(uint64s, i);
        if (uint64 != 1) continue;
        ++good;
    }
    if (uint64s && good == i) Console_writeLine("Test04: SUCCESS: uint64Array({0:uint})", 1, i);
    else Console_writeLine("Test04: ERROR: uint64Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(uint64s);

    Int8Array int8s = new_Int8Array(64);
    length = Int8Array_get_Length(int8s);
    for (good = 0, i = 0; i < length; ++i) {
        Int8 int8 = Int8Array_get_index(int8s, i);
        if (int8 != 0) continue;
        Int8Array_set_index(int8s, i, -1);
        int8 = Int8Array_get_index(int8s, i);
        if (int8 != -1) continue;
        ++good;
    }
    if (int8s && good == i) Console_writeLine("Test05: SUCCESS: int8Array({0:uint})", 1, i);
    else Console_writeLine("Test05: ERROR: int8Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(int8s);

    Int16Array int16s = new_Int16Array(64);
    length = Int16Array_get_Length(int16s);
    for (good = 0, i = 0; i < length; ++i) {
        Int16 int16 = Int16Array_get_index(int16s, i);
        if (int16 != 0) continue;
        Int16Array_set_index(int16s, i, 1);
        int16 = Int16Array_get_index(int16s, i);
        if (int16 != 1) continue;
        ++good;
    }
    if (int16s && good == i) Console_writeLine("Test06: SUCCESS: int16Array({0:uint})", 1, i);
    else Console_writeLine("Test06: ERROR: int16Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(int16s);

    Int32Array int32s = new_Int32Array(64);
    length = Int32Array_get_Length(int32s);
    for (good = 0, i = 0; i < length; ++i) {
        Int32 int32 = Int32Array_get_index(int32s, i);
        if (int32 != 0) continue;
        Int32Array_set_index(int32s, i, 1);
        int32 = Int32Array_get_index(int32s, i);
        if (int32 != 1) continue;
        ++good;
    }
    if (int32s && good == i) Console_writeLine("Test07: SUCCESS: int32Array({0:uint})", 1, i);
    else Console_writeLine("Test07: ERROR: int32Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(int32s);

    Int64Array int64s = new_Int64Array(64);
    length = Int64Array_get_Length(int64s);
    for (good = 0, i = 0; i < length; ++i) {
        Int64 int64 = Int64Array_get_index(int64s, i);
        if (int64 != 0) continue;
        Int64Array_set_index(int64s, i, 1);
        int64 = Int64Array_get_index(int64s, i);
        if (int64 != 1) continue;
        ++good;
    }
    if (int64s && good == i) Console_writeLine("Test08: SUCCESS: int64Array({0:uint})", 1, i);
    else Console_writeLine("Test08: ERROR: int64Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(int64s);

    String8Array String8s = new_String8Array(64);
    length = String8Array_get_Length(String8s);
    for (good = 0, i = 0; i < length; ++i) {
        String8 String8 = String8Array_get_index(String8s, i);
        if (String8) continue;
        String8Array_set_index(String8s, i, STRING8_Hallo);
        String8 = String8Array_get_index(String8s, i);
        if (!String8_equals(String8, STRING8_Hallo)) continue;
        ++good;
    }
    if (String8s && good == i) Console_writeLine("Test09: SUCCESS: String8Array({0:uint})", 1, i);
    else Console_writeLine("Test09: ERROR: String8Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(String8s);

    /* Test11: Use System_Object with for and foreach */
    Array Objects = new_Array(64);
    length = Array_get_Length(Objects);
    for (good = 0, i = 0; i < length; ++i) {
        Object object = Array_get_index(Objects, i);
        if (object) continue;
        object = new_Object();
        Array_set_index(Objects, i, object);
        Memory_free(object);
        Object = Array_get_index(Objects, i);
        if (!object || !System_Object_get_Type(object)) continue;
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
    if (Objects && good == 64 && good1 == 64 && good2 == 64) Console_writeLine("Test10: SUCCESS: new_Array({0:uint})", 1, i);
    else Console_writeLine("Test10: ERROR: new_Array({0:uint}), {1:uint} failed", 2, i, i - good);
    Memory_free(Objects);

    return true;
}
