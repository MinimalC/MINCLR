#define using_System
#include <min/System.h>

STRING8  prefix  = "main_";
STRING8  name  = "test01_System_String8";
STRING8  final_name  = "main_test01_System_String8";
STRING8  command  = "./home/test01_System_String8";
STRING8  empty  = " \t";
STRING8  lorem_ipsum = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed eiusmod tempor incidunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquid ex ea commodi consequat. Quis aute iure reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint obcaecat cupiditat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.";
STRING8  base64 = "TG9yZW0gaXBzdW0gZG9sb3Igc2l0IGFtZXQsIGNvbnNlY3RldHVyIGFkaXBpc2NpbmcgZWxpdCwgc2VkIGVpdXNtb2QgdGVtcG9yIGluY2lkdW50IHV0IGxhYm9yZSBldCBkb2xvcmUgbWFnbmEgYWxpcXVhLiBVdCBlbmltIGFkIG1pbmltIHZlbmlhbSwgcXVpcyBub3N0cnVkIGV4ZXJjaXRhdGlvbiB1bGxhbWNvIGxhYm9yaXMgbmlzaSB1dCBhbGlxdWlkIGV4IGVhIGNvbW1vZGkgY29uc2VxdWF0LiBRdWlzIGF1dGUgaXVyZSByZXByZWhlbmRlcml0IGluIHZvbHVwdGF0ZSB2ZWxpdCBlc3NlIGNpbGx1bSBkb2xvcmUgZXUgZnVnaWF0IG51bGxhIHBhcmlhdHVyLiBFeGNlcHRldXIgc2ludCBvYmNhZWNhdCBjdXBpZGl0YXQgbm9uIHByb2lkZW50LCBzdW50IGluIGN1bHBhIHF1aSBvZmZpY2lhIGRlc2VydW50IG1vbGxpdCBhbmltIGlkIGVzdCBsYWJvcnVtLg==";

STRING8 System_String8_Base64EncodeTable
    = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
        'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
        'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
        'w', 'x', 'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '+', '/', };

int System_Runtime_main(int argc, char * argv[]) {

    if (String8_isNullOrEmpty(null) && String8_isNullOrEmpty(empty) && !String8_isNullOrEmpty(prefix))
        Console_writeLine__string("Test00: SUCCESS: String8_isNullOrEmpty");
    else
        Console_writeLine__string("Test00: ERROR: String8_isNullOrEmpty");


    Size command_length = String8_get_Length(command);
    if (command_length != 28)
        Console_writeLine__string("Test01: ERROR: String8_get_Length");
    else
        Console_writeLine__string("Test01: SUCCESS: String8_get_Length");

    SSize  command_i0 = String8_indexOf__char(command, '/');
    if (command_i0 != 1)
        Console_writeLine__string("Test02: ERROR: String8_indexOf__char");
    else
        Console_writeLine__string("Test02: SUCCESS: String8_indexOf__char");

    SSize  command_i1 = String8_indexOf(command, "test01");
    if (command_i1 != 7)
        Console_writeLine__string("Test03: ERROR: String8_indexOf");
    else
        Console_writeLine__string("Test03: SUCCESS: String8_indexOf");

    SSize  command_i2 = String8_lastIndexOf__char(command, '/');
    if (command_i2 != 6)
        Console_writeLine__string("Test04: ERROR: String8_lastIndexOf__char");
    else
        Console_writeLine__string("Test04: SUCCESS: String8_lastIndexOf__char");

    SSize  command_i3 = String8_lastIndexOf(command, "System");
    if (command_i3 != 14)
        Console_writeLine__string("Test05: ERROR: String8_lastIndexOf");
    else
        Console_writeLine__string("Test05: SUCCESS: String8_lastIndexOf");

    String8 prefix_name = System_String8_concat2(prefix, name);
    if (!String8_equals(prefix_name, final_name))
        Console_writeLine("Test06: ERROR: String8_concat2: {0:string}", 1, prefix_name);
    else
        Console_writeLine__string("Test06: SUCCESS: String8_concat2");
    Memory_free(prefix_name);

    String8 concatN = System_String8_concat("main", 6, "_", "test01", "_", "System", "_", "String8");
    if (!String8_equals(concatN, final_name))
        Console_writeLine("Test07: ERROR: String8_concatN: {0:string}", 1, concatN);
    else
        Console_writeLine__string("Test07: SUCCESS: String8_concat__arguments");
    Memory_free(concatN);

    String8 base64_encoded = System_String8_encodeBase64(lorem_ipsum);
    if (!String8_equals(base64_encoded, base64))
        Console_writeLine("Test08: ERROR: String8_encodeBase64: {0:string}", 1, base64_encoded);
    else
        Console_writeLine__string("Test08: SUCCESS: System_String8_encodeBase64");

    String8 base64_decoded = System_String8_decodeBase64(base64_encoded);
    if (!String8_equals(base64_decoded, lorem_ipsum))
        Console_writeLine("Test09: ERROR: String8_decodeBase64: {0:string}", 1, base64_decoded);
    else
        Console_writeLine__string("Test09: SUCCESS: System_String8_decodeBase64");
    Memory_free(base64_encoded);
    Memory_free(base64_decoded);

    return true;
}
