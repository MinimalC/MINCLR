#define using_System
#define using_Crypto
#include <min/System.h>

struct_string8  HalloWelt = "HelloWorld";
uint64 SipHash48_HalloWelt = 0x1648223A11BB3707;

//main(test21_Crypto_SipHash, args) {
int main(int argc, char * argv[]) {

    uint64 hash_value;

    string8 hash_sourcecode = HalloWelt;
    size hash_sourcecode_length = string8_get_Length(HalloWelt);

    struct_SipHash48 sipHash48 = stack_SipHash48();
    SipHash48_init(&sipHash48);

    if (argc > 1) {
        string8 arg1 = argv[1];
        hash_sourcecode = arg1;
        hash_sourcecode_length = string8_get_Length(arg1);

        SipHash48_update(&sipHash48, hash_sourcecode, hash_sourcecode_length);
        hash_value = SipHash48_final(&sipHash48);

        if (!hash_value)
            Console_writeLine("Test01: ERROR:        Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);
        else
            Console_writeLine("Test01: SUCCESS:        Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);

    } else {
        SipHash48_update(&sipHash48, hash_sourcecode, hash_sourcecode_length);
        uint64 hash_value = SipHash48_final(&sipHash48);

        if (!hash_value || hash_value != SipHash48_HalloWelt)
            Console_writeLine("Test02: ERROR:         Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);
        else
            Console_writeLine("Test02: SUCCESS:         Crypto_SipHash48: 0x{0:uint:hex}", 1, hash_value);
    }

    Object object0 = Object_new();
    hash_value = Object_getSipHash(object0);
    if (!hash_value)
        Console_writeLine("Test03: ERROR: System_Object_getSipHash: 0x{0:uint:hex}", 1, hash_value);
    else
        Console_writeLine("Test03: SUCCESS: System_Object_getSipHash: 0x{0:uint:hex}", 1, hash_value);
    Object_freeClass(&object0);

    return true;
}
