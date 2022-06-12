#define using_System
#include <min/System.h>

__main(test50_System_integers, args) {


    __uint8 uint8 = 127;
    __Console_printLine("uint8: %u on stack", uint8);

    __char8 uint8_dual[System_uint8_string8base2Length_DEFAULT] = { };
    __char8 uint8_quadral[System_uint8_string8base4Length_DEFAULT] = { };
    __char8 uint8_octal[System_uint8_string8base8Length_DEFAULT] = { };
    __char8 uint8_decimal[System_uint8_string8base10Length_DEFAULT] = { };
    __char8 uint8_hexadecimal[System_uint8_string8base16Length_DEFAULT] = { };

    System_uint8_tostring8base2__stack(uint8, uint8_dual);
    System_uint8_tostring8base4__stack(uint8, uint8_quadral);
    System_uint8_tostring8base8__stack(uint8, uint8_octal);
    System_uint8_tostring8base10__stack(uint8, uint8_decimal);
    System_uint8_tostring8base16__stack(uint8, uint8_hexadecimal);

    __Console_printLine("uint8 to dual base2:         %s", uint8_dual);
    __Console_printLine("uint8 to quadral base4:      %s", uint8_quadral);
    __Console_printLine("uint8 to octal base8:        %s", uint8_octal);
    __Console_printLine("uint8 to decimal base10:     %s", uint8_decimal);
    __Console_printLine("uint8 to hexadecimal base16: %s", uint8_hexadecimal);


    __uint16 uint16 = 32767;
    __Console_printLine("uint16: %u on stack", uint16);

    __char8 uint16_dual[System_uint16_string8base2Length_DEFAULT] = { };
    __char8 uint16_quadral[System_uint16_string8base4Length_DEFAULT] = { };
    __char8 uint16_octal[System_uint16_string8base8Length_DEFAULT] = { };
    __char8 uint16_decimal[System_uint16_string8base10Length_DEFAULT] = { };
    __char8 uint16_hexadecimal[System_uint16_string8base16Length_DEFAULT] = { };

    System_uint16_tostring8base2__stack(uint16, uint16_dual);
    System_uint16_tostring8base4__stack(uint16, uint16_quadral);
    System_uint16_tostring8base8__stack(uint16, uint16_octal);
    System_uint16_tostring8base10__stack(uint16, uint16_decimal);
    System_uint16_tostring8base16__stack(uint16, uint16_hexadecimal);

    __Console_printLine("uint16 to dual base2:         %s", uint16_dual);
    __Console_printLine("uint16 to quadral base4:      %s", uint16_quadral);
    __Console_printLine("uint16 to octal base8:        %s", uint16_octal);
    __Console_printLine("uint16 to decimal base10:     %s", uint16_decimal);
    __Console_printLine("uint16 to hexadecimal base16: %s", uint16_hexadecimal);


    __uint32 uint32 = 2147483647;
    __Console_printLine("uint32: %lu on stack", uint32);

    __char8 uint32_dual[System_uint32_string8base2Length_DEFAULT] = { };
    __char8 uint32_quadral[System_uint32_string8base4Length_DEFAULT] = { };
    __char8 uint32_octal[System_uint32_string8base8Length_DEFAULT] = { };
    __char8 uint32_decimal[System_uint32_string8base10Length_DEFAULT] = { };
    __char8 uint32_hexadecimal[System_uint32_string8base16Length_DEFAULT] = { };

    System_uint32_tostring8base2__stack(uint32, uint32_dual);
    System_uint32_tostring8base4__stack(uint32, uint32_quadral);
    System_uint32_tostring8base8__stack(uint32, uint32_octal);
    System_uint32_tostring8base10__stack(uint32, uint32_decimal);
    System_uint32_tostring8base16__stack(uint32, uint32_hexadecimal);

    __Console_printLine("uint32 to dual base2:         %s", uint32_dual);
    __Console_printLine("uint32 to quadral base4:      %s", uint32_quadral);
    __Console_printLine("uint32 to octal base8:        %s", uint32_octal);
    __Console_printLine("uint32 to decimal base10:     %s", uint32_decimal);
    __Console_printLine("uint32 to hexadecimal base16: %s", uint32_hexadecimal);


    __uint64 uint64 = 0xFFFFFFFFFFFFFFFF;
    __Console_printLine("uint64: %llu on stack", uint64);

    __char8 uint64_dual[System_uint64_string8base2Length_DEFAULT] = { };
    __char8 uint64_quadral[System_uint64_string8base4Length_DEFAULT] = { };
    __char8 uint64_octal[System_uint64_string8base8Length_DEFAULT] = { };
    __char8 uint64_decimal[System_uint64_string8base10Length_DEFAULT] = { };
    __char8 uint64_hexadecimal[System_uint64_string8base16Length_DEFAULT] = { };

    System_uint64_tostring8base2__stack(uint64, uint64_dual);
    System_uint64_tostring8base4__stack(uint64, uint64_quadral);
    System_uint64_tostring8base8__stack(uint64, uint64_octal);
    System_uint64_tostring8base10__stack(uint64, uint64_decimal);
    System_uint64_tostring8base16__stack(uint64, uint64_hexadecimal);

    __Console_printLine("uint64 to dual base2:         %s", uint64_dual);
    __Console_printLine("uint64 to quadral base4:      %s", uint64_quadral);
    __Console_printLine("uint64 to octal base8:        %s", uint64_octal);
    __Console_printLine("uint64 to decimal base10:     %s", uint64_decimal);
    __Console_printLine("uint64 to hexadecimal base16: %s", uint64_hexadecimal);

    __Console_printLineEmpty(); /* this was System_uint */


    __int8 int8 = -0x7F;
    __Console_printLine("int8: %i on stack", int8);

    __char8 int8_dual[System_int8_string8base2Length_DEFAULT] = { };
    __char8 int8_quadral[System_int8_string8base4Length_DEFAULT] = { };
    __char8 int8_octal[System_int8_string8base8Length_DEFAULT] = { };
    __char8 int8_decimal[System_int8_string8base10Length_DEFAULT] = { };
    __char8 int8_hexadecimal[System_int8_string8base16Length_DEFAULT] = { };

    System_int8_tostring8base2__stack(int8, int8_dual);
    System_int8_tostring8base4__stack(int8, int8_quadral);
    System_int8_tostring8base8__stack(int8, int8_octal);
    System_int8_tostring8base10__stack(int8, int8_decimal);
    System_int8_tostring8base16__stack(int8, int8_hexadecimal);

    __Console_printLine("int8 to dual base2:         %s", int8_dual);
    __Console_printLine("int8 to quadral base4:      %s", int8_quadral);
    __Console_printLine("int8 to octal base8:        %s", int8_octal);
    __Console_printLine("int8 to decimal base10:     %s", int8_decimal);
    __Console_printLine("int8 to hexadecimal base16: %s", int8_hexadecimal);


    __int16 int16 = -0x7FFF;
    __Console_printLine("int16: %i on stack", int16);

    __char8 int16_dual[System_int16_string8base2Length_DEFAULT] = { };
    __char8 int16_quadral[System_int16_string8base4Length_DEFAULT] = { };
    __char8 int16_octal[System_int16_string8base8Length_DEFAULT] = { };
    __char8 int16_decimal[System_int16_string8base10Length_DEFAULT] = { };
    __char8 int16_hexadecimal[System_int16_string8base16Length_DEFAULT] = { };

    System_int16_tostring8base2__stack(int16, int16_dual);
    System_int16_tostring8base4__stack(int16, int16_quadral);
    System_int16_tostring8base8__stack(int16, int16_octal);
    System_int16_tostring8base10__stack(int16, int16_decimal);
    System_int16_tostring8base16__stack(int16, int16_hexadecimal);

    __Console_printLine("int16 to dual base2:         %s", int16_dual);
    __Console_printLine("int16 to quadral base4:      %s", int16_quadral);
    __Console_printLine("int16 to octal base8:        %s", int16_octal);
    __Console_printLine("int16 to decimal base10:     %s", int16_decimal);
    __Console_printLine("int16 to hexadecimal base16: %s", int16_hexadecimal);


    __int32 int32 = -0x7FFFFFFF;
    __Console_printLine("int32: %li on stack", int32);

    __char8 int32_dual[System_int32_string8base2Length_DEFAULT] = { };
    __char8 int32_quadral[System_int32_string8base4Length_DEFAULT] = { };
    __char8 int32_octal[System_int32_string8base8Length_DEFAULT] = { };
    __char8 int32_decimal[System_int32_string8base10Length_DEFAULT] = { };
    __char8 int32_hexadecimal[System_int32_string8base16Length_DEFAULT] = { };

    System_int32_tostring8base2__stack(int32, int32_dual);
    System_int32_tostring8base4__stack(int32, int32_quadral);
    System_int32_tostring8base8__stack(int32, int32_octal);
    System_int32_tostring8base10__stack(int32, int32_decimal);
    System_int32_tostring8base16__stack(int32, int32_hexadecimal);

    __Console_printLine("int32 to dual base2:         %s", int32_dual);
    __Console_printLine("int32 to quadral base4:      %s", int32_quadral);
    __Console_printLine("int32 to octal base8:        %s", int32_octal);
    __Console_printLine("int32 to decimal base10:     %s", int32_decimal);
    __Console_printLine("int32 to hexadecimal base16: %s", int32_hexadecimal);


    __int64 int64 = -0x7FFFFFFFFFFFFFFFLL;
    __Console_printLine("int64: %lli on stack", int64);

    __char8 int64_dual[System_int64_string8base2Length_DEFAULT] = { };
    __char8 int64_quadral[System_int64_string8base4Length_DEFAULT] = { };
    __char8 int64_octal[System_int64_string8base8Length_DEFAULT] = { };
    __char8 int64_decimal[System_int64_string8base10Length_DEFAULT] = { };
    __char8 int64_hexadecimal[System_int64_string8base16Length_DEFAULT] = { };

    System_int64_tostring8base2__stack(int64, int64_dual);
    System_int64_tostring8base4__stack(int64, int64_quadral);
    System_int64_tostring8base8__stack(int64, int64_octal);
    System_int64_tostring8base10__stack(int64, int64_decimal);
    System_int64_tostring8base16__stack(int64, int64_hexadecimal);

    __Console_printLine("int64 to dual base2:         %s", int64_dual);
    __Console_printLine("int64 to quadral base4:      %s", int64_quadral);
    __Console_printLine("int64 to octal base8:        %s", int64_octal);
    __Console_printLine("int64 to decimal base10:     %s", int64_decimal);
    __Console_printLine("int64 to hexadecimal base16: %s", int64_hexadecimal);


    return __true;
}
