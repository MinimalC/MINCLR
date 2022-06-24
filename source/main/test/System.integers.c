#define using_System
#include <min/System.h>

// __main(test50_System_integers, args) {
int main(int argc, char * argv[]) {

    __char8 scratch[100] = { };


    __uint8 uint8 = 127;
    __Console_printLine("uint8: %u on stack", uint8);

    System_uint8_tostring8base2__stack(uint8, scratch);
    __Console_printLine("uint8 to dual base2:         %s", scratch);
    System_uint8_tostring8base4__stack(uint8, scratch);
    __Console_printLine("uint8 to quadral base4:      %s", scratch);
    System_uint8_tostring8base8__stack(uint8, scratch);
    __Console_printLine("uint8 to octal base8:        %s", scratch);
    System_uint8_tostring8base10__stack(uint8, scratch);
    __Console_printLine("uint8 to decimal base10:     %s", scratch);
    System_uint8_tostring8base16__stack(uint8, scratch);
    __Console_printLine("uint8 to hexadecimal base16: %s", scratch);


    __uint16 uint16 = 32767;
    __Console_printLine("uint16: %u on stack", uint16);

    System_uint16_tostring8base2__stack(uint16, scratch);
    __Console_printLine("uint16 to dual base2:         %s", scratch);
    System_uint16_tostring8base4__stack(uint16, scratch);
    __Console_printLine("uint16 to quadral base4:      %s", scratch);
    System_uint16_tostring8base8__stack(uint16, scratch);
    __Console_printLine("uint16 to octal base8:        %s", scratch);
    System_uint16_tostring8base10__stack(uint16, scratch);
    __Console_printLine("uint16 to decimal base10:     %s", scratch);
    System_uint16_tostring8base16__stack(uint16, scratch);
    __Console_printLine("uint16 to hexadecimal base16: %s", scratch);



    __uint32 uint32 = 2147483647UL;
    __Console_printLine("uint32: %lu on stack", uint32);

    System_uint32_tostring8base2__stack(uint32, scratch);
    __Console_printLine("uint32 to dual base2:         %s", scratch);
    System_uint32_tostring8base4__stack(uint32, scratch);
    __Console_printLine("uint32 to quadral base4:      %s", scratch);
    System_uint32_tostring8base8__stack(uint32, scratch);
    __Console_printLine("uint32 to octal base8:        %s", scratch);
    System_uint32_tostring8base10__stack(uint32, scratch);
    __Console_printLine("uint32 to decimal base10:     %s", scratch);
    System_uint32_tostring8base16__stack(uint32, scratch);
    __Console_printLine("uint32 to hexadecimal base16: %s", scratch);


    __uint64 uint64 = 0xFFFFFFFFFFFFFFFFULL;
    __Console_printLine("uint64: %llu on stack", uint64);

    System_uint64_tostring8base2__stack(uint64, scratch);
    __Console_printLine("uint64 to dual base2:         %s", scratch);
    System_uint64_tostring8base4__stack(uint64, scratch);
    __Console_printLine("uint64 to quadral base4:      %s", scratch);
    System_uint64_tostring8base8__stack(uint64, scratch);
    __Console_printLine("uint64 to octal base8:        %s", scratch);
    System_uint64_tostring8base10__stack(uint64, scratch);
    __Console_printLine("uint64 to decimal base10:     %s", scratch);
    System_uint64_tostring8base16__stack(uint64, scratch);
    __Console_printLine("uint64 to hexadecimal base16: %s", scratch);

    __Console_printLineEmpty(); /* this was System_uint */


    __int8 int8 = -0x7F;
    __Console_printLine("int8: %i on stack", int8);

    System_int8_tostring8base2__stack(int8, scratch);
    __Console_printLine("int8 to dual base2:         %s", scratch);
    System_int8_tostring8base4__stack(int8, scratch);
    __Console_printLine("int8 to quadral base4:      %s", scratch);
    System_int8_tostring8base8__stack(int8, scratch);
    __Console_printLine("int8 to octal base8:        %s", scratch);
    System_int8_tostring8base10__stack(int8, scratch);
    __Console_printLine("int8 to decimal base10:     %s", scratch);
    System_int8_tostring8base16__stack(int8, scratch);
    __Console_printLine("int8 to hexadecimal base16: %s", scratch);


    __int16 int16 = -0x7FFF;
    __Console_printLine("int16: %i on stack", int16);

    System_int16_tostring8base2__stack(int16, scratch);
    __Console_printLine("int16 to dual base2:         %s", scratch);
    System_int16_tostring8base4__stack(int16, scratch);
    __Console_printLine("int16 to quadral base4:      %s", scratch);
    System_int16_tostring8base8__stack(int16, scratch);
    __Console_printLine("int16 to octal base8:        %s", scratch);
    System_int16_tostring8base10__stack(int16, scratch);
    __Console_printLine("int16 to decimal base10:     %s", scratch);
    System_int16_tostring8base16__stack(int16, scratch);
    __Console_printLine("int16 to hexadecimal base16: %s", scratch);


    __int32 int32 = -0x7FFFFFFFL;
    __Console_printLine("int32: %li on stack", int32);

    System_int32_tostring8base2__stack(int32, scratch);
    __Console_printLine("int32 to dual base2:         %s", scratch);
    System_int32_tostring8base4__stack(int32, scratch);
    __Console_printLine("int32 to quadral base4:      %s", scratch);
    System_int32_tostring8base8__stack(int32, scratch);
    __Console_printLine("int32 to octal base8:        %s", scratch);
    System_int32_tostring8base10__stack(int32, scratch);
    __Console_printLine("int32 to decimal base10:     %s", scratch);
    System_int32_tostring8base16__stack(int32, scratch);
    __Console_printLine("int32 to hexadecimal base16: %s", scratch);


    __int64 int64 = -0x7FFFFFFFFFFFFFFFLL;
    __Console_printLine("int64: %lli on stack", int64);

    System_int64_tostring8base2__stack(int64, scratch);
    __Console_printLine("int64 to dual base2:         %s", scratch);
    System_int64_tostring8base4__stack(int64, scratch);
    __Console_printLine("int64 to quadral base4:      %s", scratch);
    System_int64_tostring8base8__stack(int64, scratch);
    __Console_printLine("int64 to octal base8:        %s", scratch);
    System_int64_tostring8base10__stack(int64, scratch);
    __Console_printLine("int64 to decimal base10:     %s", scratch);
    System_int64_tostring8base16__stack(int64, scratch);
    __Console_printLine("int64 to hexadecimal base16: %s", scratch);


    return __true;
}
