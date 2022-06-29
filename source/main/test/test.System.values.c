#define using_System
#include <min/System.values.auto.h>
#include <min/System.Console.h>

// main(test50_System_values, args) {
int main(int argc, char * argv[]) {

    size i;
    char8 scratch[100] = { };
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;


    uint8 the_uint8 = 127;
    Console_writeLine("uint8: {0:uint} on stack", 1, the_uint8);

    uint8_tostring8base2__stack(the_uint8, scratch);
    Console_writeLine("uint8 to binary base2:       {0:string}", 1, scratch);
    uint8_tostring8base4__stack(the_uint8, scratch);
    Console_writeLine("uint8 to quadral base4:      {0:string}", 1, scratch);
    uint8_tostring8base8__stack(the_uint8, scratch);
    Console_writeLine("uint8 to octal base8:        {0:string}", 1, scratch);
    uint8_tostring8base10__stack(the_uint8, scratch);
    Console_writeLine("uint8 to decimal base10:     {0:string}", 1, scratch);
    uint8_tostring8base16__stack(the_uint8, scratch);
    Console_writeLine("uint8 to hexadecimal base16: {0:string}", 1, scratch);


    uint16 the_uint16 = 32767;
    Console_writeLine("uint16: {0:uint} on stack", 1, the_uint16);

    uint16_tostring8base2__stack(the_uint16, scratch);
    Console_writeLine("uint16 to binary base2:       {0:string}", 1, scratch);
    uint16_tostring8base4__stack(the_uint16, scratch);
    Console_writeLine("uint16 to quadral base4:      {0:string}", 1, scratch);
    uint16_tostring8base8__stack(the_uint16, scratch);
    Console_writeLine("uint16 to octal base8:        {0:string}", 1, scratch);
    uint16_tostring8base10__stack(the_uint16, scratch);
    Console_writeLine("uint16 to decimal base10:     {0:string}", 1, scratch);
    uint16_tostring8base16__stack(the_uint16, scratch);
    Console_writeLine("uint16 to hexadecimal base16: {0:string}", 1, scratch);



    uint32 the_uint32 = 2147483647UL;
    Console_writeLine("uint32: {0:uint} on stack", 1, the_uint32);

    uint32_tostring8base2__stack(the_uint32, scratch);
    Console_writeLine("uint32 to binary base2:       {0:string}", 1, scratch);
    uint32_tostring8base4__stack(the_uint32, scratch);
    Console_writeLine("uint32 to quadral base4:      {0:string}", 1, scratch);
    uint32_tostring8base8__stack(the_uint32, scratch);
    Console_writeLine("uint32 to octal base8:        {0:string}", 1, scratch);
    uint32_tostring8base10__stack(the_uint32, scratch);
    Console_writeLine("uint32 to decimal base10:     {0:string}", 1, scratch);
    uint32_tostring8base16__stack(the_uint32, scratch);
    Console_writeLine("uint32 to hexadecimal base16: {0:string}", 1, scratch);


    uint64 the_uint64 = 0xFFFFFFFFFFFFFFFFULL;
    Console_writeLine("uint64: {0:uint} on stack", 1, the_uint64);

    uint64_tostring8base2__stack(the_uint64, scratch);
    Console_writeLine("uint64 to binary base2:       {0:string}", 1, scratch);
    uint64_tostring8base4__stack(the_uint64, scratch);
    Console_writeLine("uint64 to quadral base4:      {0:string}", 1, scratch);
    uint64_tostring8base8__stack(the_uint64, scratch);
    Console_writeLine("uint64 to octal base8:        {0:string}", 1, scratch);
    uint64_tostring8base10__stack(the_uint64, scratch);
    Console_writeLine("uint64 to decimal base10:     {0:string}", 1, scratch);
    uint64_tostring8base16__stack(the_uint64, scratch);
    Console_writeLine("uint64 to hexadecimal base16: {0:string}", 1, scratch);

    Console_writeLineEmpty(); /* this was uint */


    int8 the_int8 = -0x7F;
    Console_writeLine("int8: {0:int8} on stack", 1, the_int8);

    int8_tostring8base2__stack(the_int8, scratch);
    Console_writeLine("int8 to binary base2:       {0:string}", 1, scratch);
    int8_tostring8base4__stack(the_int8, scratch);
    Console_writeLine("int8 to quadral base4:      {0:string}", 1, scratch);
    int8_tostring8base8__stack(the_int8, scratch);
    Console_writeLine("int8 to octal base8:        {0:string}", 1, scratch);
    int8_tostring8base10__stack(the_int8, scratch);
    Console_writeLine("int8 to decimal base10:     {0:string}", 1, scratch);
    int8_tostring8base16__stack(the_int8, scratch);
    Console_writeLine("int8 to hexadecimal base16: {0:string}", 1, scratch);


    int16 the_int16 = -0x7FFF;
    Console_writeLine("int16: {0:int16} on stack", 1, the_int16);

    int16_tostring8base2__stack(the_int16, scratch);
    Console_writeLine("int16 to binary base2:       {0:string}", 1, scratch);
    int16_tostring8base4__stack(the_int16, scratch);
    Console_writeLine("int16 to quadral base4:      {0:string}", 1, scratch);
    int16_tostring8base8__stack(the_int16, scratch);
    Console_writeLine("int16 to octal base8:        {0:string}", 1, scratch);
    int16_tostring8base10__stack(the_int16, scratch);
    Console_writeLine("int16 to decimal base10:     {0:string}", 1, scratch);
    int16_tostring8base16__stack(the_int16, scratch);
    Console_writeLine("int16 to hexadecimal base16: {0:string}", 1, scratch);


    int32 the_int32 = -0x7FFFFFFFL;
    Console_writeLine("int32: {0:int32} on stack", 1, the_int32);

    int32_tostring8base2__stack(the_int32, scratch);
    Console_writeLine("int32 to binary base2:       {0:string}", 1, scratch);
    int32_tostring8base4__stack(the_int32, scratch);
    Console_writeLine("int32 to quadral base4:      {0:string}", 1, scratch);
    int32_tostring8base8__stack(the_int32, scratch);
    Console_writeLine("int32 to octal base8:        {0:string}", 1, scratch);
    int32_tostring8base10__stack(the_int32, scratch);
    Console_writeLine("int32 to decimal base10:     {0:string}", 1, scratch);
    int32_tostring8base16__stack(the_int32, scratch);
    Console_writeLine("int32 to hexadecimal base16: {0:string}", 1, scratch);


    int64 the_int64 = -0x7FFFFFFFFFFFFFFFLL;
    Console_writeLine("int64: {0:int64} on stack", 1, the_int64);

    int64_tostring8base2__stack(the_int64, scratch);
    Console_writeLine("int64 to binary base2:       {0:string}", 1, scratch);
    int64_tostring8base4__stack(the_int64, scratch);
    Console_writeLine("int64 to quadral base4:      {0:string}", 1, scratch);
    int64_tostring8base8__stack(the_int64, scratch);
    Console_writeLine("int64 to octal base8:        {0:string}", 1, scratch);
    int64_tostring8base10__stack(the_int64, scratch);
    Console_writeLine("int64 to decimal base10:     {0:string}", 1, scratch);
    int64_tostring8base16__stack(the_int64, scratch);
    Console_writeLine("int64 to hexadecimal base16: {0:string}", 1, scratch);


    return true;
}
