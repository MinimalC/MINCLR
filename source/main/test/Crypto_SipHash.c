#define using_System
#define using_Crypto
#include <min/System.h>

struct_string8  HalloWelt = "HelloWorld";
__uint64 SipHash48_HalloWelt = 0x1648223A11BB3707;

__main(test21_Crypto_SipHash, args) {

    __uint64 hash_value;

    __string8 hash_sourcecode = HalloWelt;
    __size hash_sourcecode_length = __string8_get_Length(HalloWelt);

    struct_SipHash48 sipHash48 = stack_SipHash48();
    __SipHash48_init(&sipHash48);

    if (args->length > 1) {
        __string8 arg1 = __string8Array_get_index(args, 1);
        hash_sourcecode = arg1;
        hash_sourcecode_length = __string8_get_Length(arg1);

        __SipHash48_update(&sipHash48, hash_sourcecode, hash_sourcecode_length);
        hash_value = __SipHash48_final(&sipHash48);

        if (!hash_value)
            __Console_writeLine("Test01: ERROR:        Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);
        else
            __Console_writeLine("Test01: SUCCESS:        Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);

    } else {
        __SipHash48_update(&sipHash48, hash_sourcecode, hash_sourcecode_length);
        __uint64 hash_value = __SipHash48_final(&sipHash48);

        if (!hash_value || hash_value != SipHash48_HalloWelt)
            __Console_writeLine("Test01: ERROR:         Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);
        else
            __Console_writeLine("Test01: SUCCESS:         Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);
    }

    __String object1 = __String_new(HalloWelt);
    hash_value = __String_getSipHash(object1);
    if (!hash_value || hash_value != SipHash48_HalloWelt)
        __Console_writeLine("Test02: ERROR: System_String_getSipHash: 0x{0:uint:hex}", 1, hash_value);
    else
        __Console_writeLine("Test02: SUCCESS: System_String_getSipHash: 0x{0:uint:hex}", 1, hash_value);
    __Object_freeClass(&object1);

    __Object object0 = __Object_new();
    hash_value = __Object_getSipHash(object0);
    if (!hash_value)
        __Console_writeLine("Test03: ERROR: System_Object_getSipHash: 0x{0:uint:hex}", 1, hash_value);
    else
        __Console_writeLine("Test03: SUCCESS: System_Object_getSipHash: 0x{0:uint:hex}", 1, hash_value);
    __Object_freeClass(&object0);

    return __true;
}
