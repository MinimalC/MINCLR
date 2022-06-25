#define using_System
#include <min/System.values.auto.h>
#include <min/System.Console.h>

// __main(test50_System_values, args) {
int main(int argc, char * argv[]) {

    __size i;
    __char8 scratch[100] = { };
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;


    __uint8 uint8 = 127;
    __Console_writeLine("uint8: {0:uint} on stack", 1, uint8);

    System_uint8_tostring8base2__stack(uint8, scratch);
    __Console_writeLine("uint8 to binary base2:       {0:string}", 1, scratch);
    System_uint8_tostring8base4__stack(uint8, scratch);
    __Console_writeLine("uint8 to quadral base4:      {0:string}", 1, scratch);
    System_uint8_tostring8base8__stack(uint8, scratch);
    __Console_writeLine("uint8 to octal base8:        {0:string}", 1, scratch);
    System_uint8_tostring8base10__stack(uint8, scratch);
    __Console_writeLine("uint8 to decimal base10:     {0:string}", 1, scratch);
    System_uint8_tostring8base16__stack(uint8, scratch);
    __Console_writeLine("uint8 to hexadecimal base16: {0:string}", 1, scratch);


    __uint16 uint16 = 32767;
    __Console_writeLine("uint16: {0:uint} on stack", 1, uint16);

    System_uint16_tostring8base2__stack(uint16, scratch);
    __Console_writeLine("uint16 to binary base2:       {0:string}", 1, scratch);
    System_uint16_tostring8base4__stack(uint16, scratch);
    __Console_writeLine("uint16 to quadral base4:      {0:string}", 1, scratch);
    System_uint16_tostring8base8__stack(uint16, scratch);
    __Console_writeLine("uint16 to octal base8:        {0:string}", 1, scratch);
    System_uint16_tostring8base10__stack(uint16, scratch);
    __Console_writeLine("uint16 to decimal base10:     {0:string}", 1, scratch);
    System_uint16_tostring8base16__stack(uint16, scratch);
    __Console_writeLine("uint16 to hexadecimal base16: {0:string}", 1, scratch);



    __uint32 uint32 = 2147483647UL;
    __Console_writeLine("uint32: {0:uint} on stack", 1, uint32);

    System_uint32_tostring8base2__stack(uint32, scratch);
    __Console_writeLine("uint32 to binary base2:       {0:string}", 1, scratch);
    System_uint32_tostring8base4__stack(uint32, scratch);
    __Console_writeLine("uint32 to quadral base4:      {0:string}", 1, scratch);
    System_uint32_tostring8base8__stack(uint32, scratch);
    __Console_writeLine("uint32 to octal base8:        {0:string}", 1, scratch);
    System_uint32_tostring8base10__stack(uint32, scratch);
    __Console_writeLine("uint32 to decimal base10:     {0:string}", 1, scratch);
    System_uint32_tostring8base16__stack(uint32, scratch);
    __Console_writeLine("uint32 to hexadecimal base16: {0:string}", 1, scratch);


    __uint64 uint64 = 0xFFFFFFFFFFFFFFFFULL;
    __Console_writeLine("uint64: {0:uint} on stack", 1, uint64);

    System_uint64_tostring8base2__stack(uint64, scratch);
    __Console_writeLine("uint64 to binary base2:       {0:string}", 1, scratch);
    System_uint64_tostring8base4__stack(uint64, scratch);
    __Console_writeLine("uint64 to quadral base4:      {0:string}", 1, scratch);
    System_uint64_tostring8base8__stack(uint64, scratch);
    __Console_writeLine("uint64 to octal base8:        {0:string}", 1, scratch);
    System_uint64_tostring8base10__stack(uint64, scratch);
    __Console_writeLine("uint64 to decimal base10:     {0:string}", 1, scratch);
    System_uint64_tostring8base16__stack(uint64, scratch);
    __Console_writeLine("uint64 to hexadecimal base16: {0:string}", 1, scratch);

    __Console_writeLineEmpty(); /* this was System_uint */


    __int8 int8 = -0x7F;
    __Console_writeLine("int8: {0:int8} on stack", 1, int8);

    System_int8_tostring8base2__stack(int8, scratch);
    __Console_writeLine("int8 to binary base2:       {0:string}", 1, scratch);
    System_int8_tostring8base4__stack(int8, scratch);
    __Console_writeLine("int8 to quadral base4:      {0:string}", 1, scratch);
    System_int8_tostring8base8__stack(int8, scratch);
    __Console_writeLine("int8 to octal base8:        {0:string}", 1, scratch);
    System_int8_tostring8base10__stack(int8, scratch);
    __Console_writeLine("int8 to decimal base10:     {0:string}", 1, scratch);
    System_int8_tostring8base16__stack(int8, scratch);
    __Console_writeLine("int8 to hexadecimal base16: {0:string}", 1, scratch);


    __int16 int16 = -0x7FFF;
    __Console_writeLine("int16: {0:int16} on stack", 1, int16);

    System_int16_tostring8base2__stack(int16, scratch);
    __Console_writeLine("int16 to binary base2:       {0:string}", 1, scratch);
    System_int16_tostring8base4__stack(int16, scratch);
    __Console_writeLine("int16 to quadral base4:      {0:string}", 1, scratch);
    System_int16_tostring8base8__stack(int16, scratch);
    __Console_writeLine("int16 to octal base8:        {0:string}", 1, scratch);
    System_int16_tostring8base10__stack(int16, scratch);
    __Console_writeLine("int16 to decimal base10:     {0:string}", 1, scratch);
    System_int16_tostring8base16__stack(int16, scratch);
    __Console_writeLine("int16 to hexadecimal base16: {0:string}", 1, scratch);


    __int32 int32 = -0x7FFFFFFFL;
    __Console_writeLine("int32: {0:int32} on stack", 1, int32);

    System_int32_tostring8base2__stack(int32, scratch);
    __Console_writeLine("int32 to binary base2:       {0:string}", 1, scratch);
    System_int32_tostring8base4__stack(int32, scratch);
    __Console_writeLine("int32 to quadral base4:      {0:string}", 1, scratch);
    System_int32_tostring8base8__stack(int32, scratch);
    __Console_writeLine("int32 to octal base8:        {0:string}", 1, scratch);
    System_int32_tostring8base10__stack(int32, scratch);
    __Console_writeLine("int32 to decimal base10:     {0:string}", 1, scratch);
    System_int32_tostring8base16__stack(int32, scratch);
    __Console_writeLine("int32 to hexadecimal base16: {0:string}", 1, scratch);


    __int64 int64 = -0x7FFFFFFFFFFFFFFFLL;
    __Console_writeLine("int64: {0:int64} on stack", 1, int64);

    System_int64_tostring8base2__stack(int64, scratch);
    __Console_writeLine("int64 to binary base2:       {0:string}", 1, scratch);
    System_int64_tostring8base4__stack(int64, scratch);
    __Console_writeLine("int64 to quadral base4:      {0:string}", 1, scratch);
    System_int64_tostring8base8__stack(int64, scratch);
    __Console_writeLine("int64 to octal base8:        {0:string}", 1, scratch);
    System_int64_tostring8base10__stack(int64, scratch);
    __Console_writeLine("int64 to decimal base10:     {0:string}", 1, scratch);
    System_int64_tostring8base16__stack(int64, scratch);
    __Console_writeLine("int64 to hexadecimal base16: {0:string}", 1, scratch);


    return __true;
}
