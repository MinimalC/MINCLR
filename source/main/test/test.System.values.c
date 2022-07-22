#define using_System
#include <min/System.values.auto.h>
#include <min/System.Console.h>

// main(test50_System_values, args) {
int main(int argc, char * argv[]) {

    Size i;
    Char8 scratch[100] = { };
    for (i = 0; i < sizeof(scratch); ++i) scratch[i] = 0;


    UInt8 the_uint8 = 127;
    Console_writeLine("UInt8: {0:uint} on stack", 1, the_uint8);

    UInt8_toString8base2__stack(the_uint8, scratch);
    Console_writeLine("UInt8 to binary base2:       {0:string}", 1, scratch);
    UInt8_toString8base4__stack(the_uint8, scratch);
    Console_writeLine("UInt8 to quadral base4:      {0:string}", 1, scratch);
    UInt8_toString8base8__stack(the_uint8, scratch);
    Console_writeLine("UInt8 to octal base8:        {0:string}", 1, scratch);
    UInt8_toString8base10__stack(the_uint8, scratch);
    Console_writeLine("UInt8 to decimal base10:     {0:string}", 1, scratch);
    UInt8_toString8base16__stack(the_uint8, scratch);
    Console_writeLine("UInt8 to hexadecimal base16: {0:string}", 1, scratch);


    UInt16 the_uint16 = 32767;
    Console_writeLine("UInt16: {0:uint} on stack", 1, the_uint16);

    UInt16_toString8base2__stack(the_uint16, scratch);
    Console_writeLine("UInt16 to binary base2:       {0:string}", 1, scratch);
    UInt16_toString8base4__stack(the_uint16, scratch);
    Console_writeLine("UInt16 to quadral base4:      {0:string}", 1, scratch);
    UInt16_toString8base8__stack(the_uint16, scratch);
    Console_writeLine("UInt16 to octal base8:        {0:string}", 1, scratch);
    UInt16_toString8base10__stack(the_uint16, scratch);
    Console_writeLine("UInt16 to decimal base10:     {0:string}", 1, scratch);
    UInt16_toString8base16__stack(the_uint16, scratch);
    Console_writeLine("UInt16 to hexadecimal base16: {0:string}", 1, scratch);



    UInt32 the_uint32 = 2147483647UL;
    Console_writeLine("UInt32: {0:uint} on stack", 1, the_uint32);

    UInt32_toString8base2__stack(the_uint32, scratch);
    Console_writeLine("UInt32 to binary base2:       {0:string}", 1, scratch);
    UInt32_toString8base4__stack(the_uint32, scratch);
    Console_writeLine("UInt32 to quadral base4:      {0:string}", 1, scratch);
    UInt32_toString8base8__stack(the_uint32, scratch);
    Console_writeLine("UInt32 to octal base8:        {0:string}", 1, scratch);
    UInt32_toString8base10__stack(the_uint32, scratch);
    Console_writeLine("UInt32 to decimal base10:     {0:string}", 1, scratch);
    UInt32_toString8base16__stack(the_uint32, scratch);
    Console_writeLine("UInt32 to hexadecimal base16: {0:string}", 1, scratch);


    UInt64 the_uint64 = 0xFFFFFFFFFFFFFFFFULL;
    Console_writeLine("UInt64: {0:uint} on stack", 1, the_uint64);

    UInt64_toString8base2__stack(the_uint64, scratch);
    Console_writeLine("UInt64 to binary base2:       {0:string}", 1, scratch);
    UInt64_toString8base4__stack(the_uint64, scratch);
    Console_writeLine("UInt64 to quadral base4:      {0:string}", 1, scratch);
    UInt64_toString8base8__stack(the_uint64, scratch);
    Console_writeLine("UInt64 to octal base8:        {0:string}", 1, scratch);
    UInt64_toString8base10__stack(the_uint64, scratch);
    Console_writeLine("UInt64 to decimal base10:     {0:string}", 1, scratch);
    UInt64_toString8base16__stack(the_uint64, scratch);
    Console_writeLine("UInt64 to hexadecimal base16: {0:string}", 1, scratch);

    Console_writeLineEmpty(); /* this was uint */


    Int8 the_int8 = -0x7F;
    Console_writeLine("Int8: {0:int8} on stack", 1, the_int8);

    Int8_toString8base2__stack(the_int8, scratch);
    Console_writeLine("Int8 to binary base2:       {0:string}", 1, scratch);
    Int8_toString8base4__stack(the_int8, scratch);
    Console_writeLine("Int8 to quadral base4:      {0:string}", 1, scratch);
    Int8_toString8base8__stack(the_int8, scratch);
    Console_writeLine("Int8 to octal base8:        {0:string}", 1, scratch);
    Int8_toString8base10__stack(the_int8, scratch);
    Console_writeLine("Int8 to decimal base10:     {0:string}", 1, scratch);
    Int8_toString8base16__stack(the_int8, scratch);
    Console_writeLine("Int8 to hexadecimal base16: {0:string}", 1, scratch);


    Int16 the_int16 = -0x7FFF;
    Console_writeLine("Int16: {0:int16} on stack", 1, the_int16);

    Int16_toString8base2__stack(the_int16, scratch);
    Console_writeLine("Int16 to binary base2:       {0:string}", 1, scratch);
    Int16_toString8base4__stack(the_int16, scratch);
    Console_writeLine("Int16 to quadral base4:      {0:string}", 1, scratch);
    Int16_toString8base8__stack(the_int16, scratch);
    Console_writeLine("Int16 to octal base8:        {0:string}", 1, scratch);
    Int16_toString8base10__stack(the_int16, scratch);
    Console_writeLine("Int16 to decimal base10:     {0:string}", 1, scratch);
    Int16_toString8base16__stack(the_int16, scratch);
    Console_writeLine("Int16 to hexadecimal base16: {0:string}", 1, scratch);


    Int32 the_int32 = -0x7FFFFFFFL;
    Console_writeLine("Int32: {0:int32} on stack", 1, the_int32);

    Int32_toString8base2__stack(the_int32, scratch);
    Console_writeLine("Int32 to binary base2:       {0:string}", 1, scratch);
    Int32_toString8base4__stack(the_int32, scratch);
    Console_writeLine("Int32 to quadral base4:      {0:string}", 1, scratch);
    Int32_toString8base8__stack(the_int32, scratch);
    Console_writeLine("Int32 to octal base8:        {0:string}", 1, scratch);
    Int32_toString8base10__stack(the_int32, scratch);
    Console_writeLine("Int32 to decimal base10:     {0:string}", 1, scratch);
    Int32_toString8base16__stack(the_int32, scratch);
    Console_writeLine("Int32 to hexadecimal base16: {0:string}", 1, scratch);


    Int64 the_int64 = -0x7FFFFFFFFFFFFFFFLL;
    Console_writeLine("Int64: {0:int64} on stack", 1, the_int64);

    Int64_toString8base2__stack(the_int64, scratch);
    Console_writeLine("Int64 to binary base2:       {0:string}", 1, scratch);
    Int64_toString8base4__stack(the_int64, scratch);
    Console_writeLine("Int64 to quadral base4:      {0:string}", 1, scratch);
    Int64_toString8base8__stack(the_int64, scratch);
    Console_writeLine("Int64 to octal base8:        {0:string}", 1, scratch);
    Int64_toString8base10__stack(the_int64, scratch);
    Console_writeLine("Int64 to decimal base10:     {0:string}", 1, scratch);
    Int64_toString8base16__stack(the_int64, scratch);
    Console_writeLine("Int64 to hexadecimal base16: {0:string}", 1, scratch);


    return true;
}
