/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_File)
#include <min/System.Decimal.h>
#endif
#if !defined(code_System_Decimal)
#define code_System_Decimal

/** class System_Decimal  **/

struct System_Type System_DecimalType = { .base = { .type = typeof(System_Type) },
    .name = "Decimal",
    .size = sizeof(struct System_Decimal),
};

void  System_Decimal_carryOver(System_Decimal that, System_UInt8 digits) {
    /* if digits > System_Decimal_Capacity_DEFAULT - 2 { throw Exception } */
    System_UInt8 * string = that->value + System_Decimal_Capacity_DEFAULT - 1;
    for (System_Size i = 0; i < digits; ++i) {
        while (*(string - i) > 9) {
            *(string - i - 1) += 1;
            *(string - i) -= 10;
        }
    }
}

void  System_Decimal_init__UInt8(System_Decimal that, System_UInt8 uinteger) {
    System_UInt8 * string = that->value + System_Decimal_Capacity_DEFAULT - 1;
    if (uinteger & 1) {
        *(string - 0) += 1;
    }
    if (uinteger & 2) {
        *(string - 0) += 2;
    }
    if (uinteger & 4) {
        *(string - 0) += 4;
    }
    if (uinteger & 8) {
        *(string - 0) += 8;
    }
    if (uinteger & 16) {
        *(string - 1) += 1;
        *(string - 0) += 6;
    }
    if (uinteger & 32) {
        *(string - 1) += 3;
        *(string - 0) += 2;
    }
    if (uinteger & 64) {
        *(string - 1) += 6;
        *(string - 0) += 4;
    }
    if (uinteger & 128) {
        *(string - 2) += 1;
        *(string - 1) += 2;
        *(string - 0) += 8;
    }
    inline_System_Decimal_carryOver(string,3)
}

void  System_Decimal_init__UInt16(System_Decimal that, System_UInt16 uinteger) {
    System_Decimal_init__UInt8(that, (System_UInt8)uinteger);

    System_UInt8 * string = that->value + System_Decimal_Capacity_DEFAULT - 1;
    if (uinteger & 256) {
        *(string - 2) += 2;
        *(string - 1) += 5;
        *(string - 0) += 6;
    }
    if (uinteger & 512) {
        *(string - 2) += 5;
        *(string - 1) += 1;
        *(string - 0) += 2;
    }
    if (uinteger & 1024) {
        *(string - 3) += 1;
        *(string - 2) += 0;
        *(string - 1) += 2;
        *(string - 0) += 4;
    }
    if (uinteger & 2048) {
        *(string - 3) += 2;
        *(string - 2) += 0;
        *(string - 1) += 4;
        *(string - 0) += 8;
    }
    if (uinteger & 4096) {
        *(string - 3) += 4;
        *(string - 2) += 0;
        *(string - 1) += 9;
        *(string - 0) += 6;
    }
    if (uinteger & 8192) {
        *(string - 3) += 8;
        *(string - 2) += 1;
        *(string - 1) += 9;
        *(string - 0) += 2;
    }
    if (uinteger & 16384) {
        *(string - 4) += 1;
        *(string - 3) += 6;
        *(string - 2) += 3;
        *(string - 1) += 8;
        *(string - 0) += 4;
    }
    if (uinteger & 32768) {
        *(string - 4) += 3;
        *(string - 3) += 2;
        *(string - 2) += 7;
        *(string - 1) += 6;
        *(string - 0) += 8;
    }
    inline_System_Decimal_carryOver(string,5)
}

void  System_Decimal_init__UInt32(System_Decimal that, System_UInt32 uinteger) {
    System_Decimal_init__UInt16(that, (System_UInt16)uinteger);

    System_UInt8 * string = that->value + System_Decimal_Capacity_DEFAULT - 1;
    if (uinteger & 65536) {
        *(string - 4) += 6;
        *(string - 3) += 5;
        *(string - 2) += 5;
        *(string - 1) += 3;
        *(string - 0) += 6;
    }
    if (uinteger & 131072) {
        *(string - 5) += 1;
        *(string - 4) += 3;
        *(string - 3) += 1;
        *(string - 2) += 0;
        *(string - 1) += 7;
        *(string - 0) += 2;
    }
    if (uinteger & 262144) {
        *(string - 5) += 2;
        *(string - 4) += 6;
        *(string - 3) += 2;
        *(string - 2) += 1;
        *(string - 1) += 4;
        *(string - 0) += 4;
    }
    if (uinteger & 524288) {
        *(string - 5) += 5;
        *(string - 4) += 2;
        *(string - 3) += 4;
        *(string - 2) += 2;
        *(string - 1) += 8;
        *(string - 0) += 8;
    }
    if (uinteger & 1048576) {
        *(string - 6) += 1;
        *(string - 5) += 0;
        *(string - 4) += 4;
        *(string - 3) += 8;
        *(string - 2) += 5;
        *(string - 1) += 7;
        *(string - 0) += 6;
    }
    if (uinteger & 2097152) {
        *(string - 6) += 2;
        *(string - 5) += 0;
        *(string - 4) += 9;
        *(string - 3) += 7;
        *(string - 2) += 1;
        *(string - 1) += 5;
        *(string - 0) += 2;
    }
    if (uinteger & 4194304) {
        *(string - 6) += 4;
        *(string - 5) += 1;
        *(string - 4) += 9;
        *(string - 3) += 4;
        *(string - 2) += 3;
        *(string - 1) += 0;
        *(string - 0) += 4;
    }
    if (uinteger & 8388608) {
        *(string - 6) += 8;
        *(string - 5) += 3;
        *(string - 4) += 8;
        *(string - 3) += 8;
        *(string - 2) += 6;
        *(string - 1) += 0;
        *(string - 0) += 8;
    }
    if (uinteger & 16777216) {
        *(string - 7) += 1;
        *(string - 6) += 6;
        *(string - 5) += 7;
        *(string - 4) += 7;
        *(string - 3) += 7;
        *(string - 2) += 2;
        *(string - 1) += 1;
        *(string - 0) += 6;
    }
    if (uinteger & 33554432) {
        *(string - 7) += 3;
        *(string - 6) += 3;
        *(string - 5) += 5;
        *(string - 4) += 5;
        *(string - 3) += 4;
        *(string - 2) += 4;
        *(string - 1) += 3;
        *(string - 0) += 2;
    }
    if (uinteger & 67108864) {
        *(string - 7) += 6;
        *(string - 6) += 7;
        *(string - 5) += 1;
        *(string - 4) += 0;
        *(string - 3) += 8;
        *(string - 2) += 8;
        *(string - 1) += 6;
        *(string - 0) += 4;
    }
    if (uinteger & 134217728) {
        *(string - 8) += 1;
        *(string - 7) += 3;
        *(string - 6) += 4;
        *(string - 5) += 2;
        *(string - 4) += 1;
        *(string - 3) += 7;
        *(string - 2) += 7;
        *(string - 1) += 2;
        *(string - 0) += 8;
    }
    if (uinteger & 268435456) {
        *(string - 8) += 2;
        *(string - 7) += 6;
        *(string - 6) += 8;
        *(string - 5) += 4;
        *(string - 4) += 3;
        *(string - 3) += 5;
        *(string - 2) += 4;
        *(string - 1) += 5;
        *(string - 0) += 6;
    }
    if (uinteger & 536870912) {
        *(string - 8) += 5;
        *(string - 7) += 3;
        *(string - 6) += 6;
        *(string - 5) += 8;
        *(string - 4) += 7;
        *(string - 3) += 0;
        *(string - 2) += 9;
        *(string - 1) += 1;
        *(string - 0) += 2;
    }
    if (uinteger & 1073741824) {
        *(string - 9) += 1;
        *(string - 8) += 0;
        *(string - 7) += 7;
        *(string - 6) += 3;
        *(string - 5) += 7;
        *(string - 4) += 4;
        *(string - 3) += 1;
        *(string - 2) += 8;
        *(string - 1) += 2;
        *(string - 0) += 4;
    }
    if (uinteger & 2147483648) {
        *(string - 9) += 2;
        *(string - 8) += 1;
        *(string - 7) += 4;
        *(string - 6) += 7;
        *(string - 5) += 4;
        *(string - 4) += 8;
        *(string - 3) += 3;
        *(string - 2) += 6;
        *(string - 1) += 4;
        *(string - 0) += 8;
    }
    inline_System_Decimal_carryOver(string,10)
}

void  System_Decimal_init__UInt64(System_Decimal that, System_UInt64 uinteger) {
    System_Decimal_init__UInt32(that, (System_UInt32)uinteger);

    System_UInt8 * string = that->value + System_Decimal_Capacity_DEFAULT - 1;

    if (uinteger & 4294967296) {
        *(string - 9) += 4;
        *(string - 8) += 2;
        *(string - 7) += 9;
        *(string - 6) += 4;
        *(string - 5) += 9;
        *(string - 4) += 6;
        *(string - 3) += 7;
        *(string - 2) += 2;
        *(string - 1) += 9;
        *(string - 0) += 6;
    }
    if (uinteger & 8589934592) {
        *(string - 9) += 8;
        *(string - 8) += 5;
        *(string - 7) += 8;
        *(string - 6) += 9;
        *(string - 5) += 9;
        *(string - 4) += 3;
        *(string - 3) += 4;
        *(string - 2) += 5;
        *(string - 1) += 9;
        *(string - 0) += 2;
    }
    if (uinteger & 17179869184) {
        *(string - 10) += 1;
        *(string - 9) += 7;
        *(string - 8) += 1;
        *(string - 7) += 7;
        *(string - 6) += 9;
        *(string - 5) += 8;
        *(string - 4) += 6;
        *(string - 3) += 9;
        *(string - 2) += 1;
        *(string - 1) += 8;
        *(string - 0) += 4;
    }
    if (uinteger & 34359738368) {
        *(string - 10) += 3;
        *(string - 9) += 4;
        *(string - 8) += 3;
        *(string - 7) += 5;
        *(string - 6) += 9;
        *(string - 5) += 7;
        *(string - 4) += 3;
        *(string - 3) += 8;
        *(string - 2) += 3;
        *(string - 1) += 6;
        *(string - 0) += 8;
    }
    if (uinteger & 68719476736) {
        *(string - 10) += 6;
        *(string - 9) += 8;
        *(string - 8) += 7;
        *(string - 7) += 1;
        *(string - 6) += 9;
        *(string - 5) += 4;
        *(string - 4) += 7;
        *(string - 3) += 6;
        *(string - 2) += 7;
        *(string - 1) += 3;
        *(string - 0) += 6;
    }
    if (uinteger & 137438953472) {
        *(string - 11) += 1;
        *(string - 10) += 3;
        *(string - 9) += 7;
        *(string - 8) += 4;
        *(string - 7) += 3;
        *(string - 6) += 8;
        *(string - 5) += 9;
        *(string - 4) += 5;
        *(string - 3) += 3;
        *(string - 2) += 4;
        *(string - 1) += 7;
        *(string - 0) += 2;
    }
    if (uinteger & 274877906944) {
        *(string - 11) += 2;
        *(string - 10) += 7;
        *(string - 9) += 4;
        *(string - 8) += 8;
        *(string - 7) += 7;
        *(string - 6) += 7;
        *(string - 5) += 9;
        *(string - 4) += 0;
        *(string - 3) += 6;
        *(string - 2) += 9;
        *(string - 1) += 4;
        *(string - 0) += 4;
    }
    if (uinteger & 0x8000000000) {
        *(string - 11) += 5;
        *(string - 10) += 4;
        *(string - 9) += 9;
        *(string - 8) += 7;
        *(string - 7) += 5;
        *(string - 6) += 5;
        *(string - 5) += 8;
        *(string - 4) += 1;
        *(string - 3) += 3;
        *(string - 2) += 8;
        *(string - 1) += 8;
        *(string - 0) += 8;
    }
    if (uinteger & 0x10000000000) {
        *(string - 12) += 1;
        *(string - 11) += 0;
        *(string - 10) += 9;
        *(string - 9) += 9;
        *(string - 8) += 5;
        *(string - 7) += 1;
        *(string - 6) += 1;
        *(string - 5) += 6;
        *(string - 4) += 2;
        *(string - 3) += 7;
        *(string - 2) += 7;
        *(string - 1) += 7;
        *(string - 0) += 6;
    }
    if (uinteger & 0x20000000000) {
        *(string - 12) += 2;
        *(string - 11) += 1;
        *(string - 10) += 9;
        *(string - 9) += 9;
        *(string - 8) += 0;
        *(string - 7) += 2;
        *(string - 6) += 3;
        *(string - 5) += 2;
        *(string - 4) += 5;
        *(string - 3) += 5;
        *(string - 2) += 5;
        *(string - 1) += 5;
        *(string - 0) += 2;
    }
    if (uinteger & 0x40000000000) {
        *(string - 12) += 4;
        *(string - 11) += 3;
        *(string - 10) += 9;
        *(string - 9) += 8;
        *(string - 8) += 0;
        *(string - 7) += 4;
        *(string - 6) += 6;
        *(string - 5) += 5;
        *(string - 4) += 1;
        *(string - 3) += 1;
        *(string - 2) += 1;
        *(string - 1) += 0;
        *(string - 0) += 4;
    }
    if (uinteger & 0x80000000000) {
        *(string - 12) += 8;
        *(string - 11) += 7;
        *(string - 10) += 9;
        *(string - 9) += 6;
        *(string - 8) += 0;
        *(string - 7) += 9;
        *(string - 6) += 3;
        *(string - 5) += 0;
        *(string - 4) += 2;
        *(string - 3) += 2;
        *(string - 2) += 2;
        *(string - 1) += 0;
        *(string - 0) += 8;
    }
    if (uinteger & 0x100000000000) {
        *(string - 13) += 1;
        *(string - 12) += 7;
        *(string - 11) += 5;
        *(string - 10) += 9;
        *(string - 9) += 2;
        *(string - 8) += 1;
        *(string - 7) += 8;
        *(string - 6) += 6;
        *(string - 5) += 0;
        *(string - 4) += 4;
        *(string - 3) += 4;
        *(string - 2) += 4;
        *(string - 1) += 1;
        *(string - 0) += 6;
    }
    if (uinteger & 0x200000000000) {
        *(string - 13) += 3;
        *(string - 12) += 5;
        *(string - 11) += 1;
        *(string - 10) += 8;
        *(string - 9) += 4;
        *(string - 8) += 3;
        *(string - 7) += 7;
        *(string - 6) += 2;
        *(string - 5) += 0;
        *(string - 4) += 8;
        *(string - 3) += 8;
        *(string - 2) += 8;
        *(string - 1) += 3;
        *(string - 0) += 2;
    }
    if (uinteger & 0x400000000000) {
        *(string - 13) += 7;
        *(string - 12) += 0;
        *(string - 11) += 3;
        *(string - 10) += 6;
        *(string - 9) += 8;
        *(string - 8) += 7;
        *(string - 7) += 4;
        *(string - 6) += 4;
        *(string - 5) += 1;
        *(string - 4) += 7;
        *(string - 3) += 7;
        *(string - 2) += 6;
        *(string - 1) += 6;
        *(string - 0) += 4;
    }
    if (uinteger & 0x800000000000) {
        *(string - 14) += 1;
        *(string - 13) += 4;
        *(string - 12) += 0;
        *(string - 11) += 7;
        *(string - 10) += 3;
        *(string - 9) += 7;
        *(string - 8) += 4;
        *(string - 7) += 8;
        *(string - 6) += 8;
        *(string - 5) += 3;
        *(string - 4) += 5;
        *(string - 3) += 5;
        *(string - 2) += 3;
        *(string - 1) += 2;
        *(string - 0) += 8;
    }
    if (uinteger & 0x1000000000000) {
        *(string - 14) += 2;
        *(string - 13) += 8;
        *(string - 12) += 1;
        *(string - 11) += 4;
        *(string - 10) += 7;
        *(string - 9) += 4;
        *(string - 8) += 9;
        *(string - 7) += 7;
        *(string - 6) += 6;
        *(string - 5) += 7;
        *(string - 4) += 1;
        *(string - 3) += 0;
        *(string - 2) += 6;
        *(string - 1) += 5;
        *(string - 0) += 6;
    }
    if (uinteger & 0x2000000000000) {
        *(string - 14) += 5;
        *(string - 13) += 6;
        *(string - 12) += 2;
        *(string - 11) += 9;
        *(string - 10) += 4;
        *(string - 9) += 9;
        *(string - 8) += 9;
        *(string - 7) += 5;
        *(string - 6) += 3;
        *(string - 5) += 4;
        *(string - 4) += 2;
        *(string - 3) += 1;
        *(string - 2) += 3;
        *(string - 1) += 1;
        *(string - 0) += 2;
    }
    if (uinteger & 0x4000000000000) {
        *(string - 15) += 1;
        *(string - 14) += 1;
        *(string - 13) += 2;
        *(string - 12) += 5;
        *(string - 11) += 8;
        *(string - 10) += 9;
        *(string - 9) += 9;
        *(string - 8) += 9;
        *(string - 7) += 0;
        *(string - 6) += 6;
        *(string - 5) += 8;
        *(string - 4) += 4;
        *(string - 3) += 2;
        *(string - 2) += 6;
        *(string - 1) += 2;
        *(string - 0) += 4;
    }
    if (uinteger & 0x8000000000000) {
        *(string - 15) += 2;
        *(string - 14) += 2;
        *(string - 13) += 5;
        *(string - 12) += 1;
        *(string - 11) += 7;
        *(string - 10) += 9;
        *(string - 9) += 9;
        *(string - 8) += 8;
        *(string - 7) += 1;
        *(string - 6) += 3;
        *(string - 5) += 6;
        *(string - 4) += 8;
        *(string - 3) += 5;
        *(string - 2) += 2;
        *(string - 1) += 4;
        *(string - 0) += 8;
    }
    if (uinteger & 0x10000000000000) {
        *(string - 15) += 4;
        *(string - 14) += 5;
        *(string - 13) += 0;
        *(string - 12) += 3;
        *(string - 11) += 5;
        *(string - 10) += 9;
        *(string - 9) += 9;
        *(string - 8) += 6;
        *(string - 7) += 2;
        *(string - 6) += 7;
        *(string - 5) += 3;
        *(string - 4) += 7;
        *(string - 3) += 0;
        *(string - 2) += 4;
        *(string - 1) += 9;
        *(string - 0) += 6;
    }
    if (uinteger & 0x20000000000000) {
        *(string - 15) += 9;
        *(string - 14) += 0;
        *(string - 13) += 0;
        *(string - 12) += 7;
        *(string - 11) += 1;
        *(string - 10) += 9;
        *(string - 9) += 9;
        *(string - 8) += 2;
        *(string - 7) += 5;
        *(string - 6) += 4;
        *(string - 5) += 7;
        *(string - 4) += 4;
        *(string - 3) += 0;
        *(string - 2) += 9;
        *(string - 1) += 9;
        *(string - 0) += 2;
    }
    if (uinteger & 0x40000000000000) {
        *(string - 16) += 1;
        *(string - 15) += 8;
        *(string - 14) += 0;
        *(string - 13) += 1;
        *(string - 12) += 4;
        *(string - 11) += 3;
        *(string - 10) += 9;
        *(string - 9) += 8;
        *(string - 8) += 5;
        *(string - 7) += 0;
        *(string - 6) += 9;
        *(string - 5) += 4;
        *(string - 4) += 8;
        *(string - 3) += 1;
        *(string - 2) += 9;
        *(string - 1) += 8;
        *(string - 0) += 4;
    }
    if (uinteger & 0x80000000000000) {
        *(string - 16) += 3;
        *(string - 15) += 6;
        *(string - 14) += 0;
        *(string - 13) += 2;
        *(string - 12) += 8;
        *(string - 11) += 7;
        *(string - 10) += 9;
        *(string - 9) += 7;
        *(string - 8) += 0;
        *(string - 7) += 1;
        *(string - 6) += 8;
        *(string - 5) += 9;
        *(string - 4) += 6;
        *(string - 3) += 3;
        *(string - 2) += 9;
        *(string - 1) += 6;
        *(string - 0) += 8;
    }
    if (uinteger & 0x100000000000000) {
        *(string - 16) += 7;
        *(string - 15) += 2;
        *(string - 14) += 0;
        *(string - 13) += 5;
        *(string - 12) += 7;
        *(string - 11) += 5;
        *(string - 10) += 9;
        *(string - 9) += 4;
        *(string - 8) += 0;
        *(string - 7) += 3;
        *(string - 6) += 7;
        *(string - 5) += 9;
        *(string - 4) += 2;
        *(string - 3) += 7;
        *(string - 2) += 9;
        *(string - 1) += 3;
        *(string - 0) += 6;
    }
    if (uinteger & 0x200000000000000) {
        *(string - 17) += 1;
        *(string - 16) += 4;
        *(string - 15) += 4;
        *(string - 14) += 1;
        *(string - 13) += 1;
        *(string - 12) += 5;
        *(string - 11) += 1;
        *(string - 10) += 8;
        *(string - 9) += 8;
        *(string - 8) += 0;
        *(string - 7) += 7;
        *(string - 6) += 5;
        *(string - 5) += 8;
        *(string - 4) += 5;
        *(string - 3) += 5;
        *(string - 2) += 8;
        *(string - 1) += 7;
        *(string - 0) += 2;
    }
    if (uinteger & 0x400000000000000) {
        *(string - 17) += 2;
        *(string - 16) += 8;
        *(string - 15) += 8;
        *(string - 14) += 2;
        *(string - 13) += 3;
        *(string - 12) += 0;
        *(string - 11) += 3;
        *(string - 10) += 7;
        *(string - 9) += 6;
        *(string - 8) += 1;
        *(string - 7) += 5;
        *(string - 6) += 1;
        *(string - 5) += 7;
        *(string - 4) += 1;
        *(string - 3) += 1;
        *(string - 2) += 7;
        *(string - 1) += 4;
        *(string - 0) += 4;
    }
    if (uinteger & 0x800000000000000) {
        *(string - 17) += 5;
        *(string - 16) += 7;
        *(string - 15) += 6;
        *(string - 14) += 4;
        *(string - 13) += 6;
        *(string - 12) += 0;
        *(string - 11) += 7;
        *(string - 10) += 5;
        *(string - 9) += 2;
        *(string - 8) += 3;
        *(string - 7) += 0;
        *(string - 6) += 3;
        *(string - 5) += 4;
        *(string - 4) += 2;
        *(string - 3) += 3;
        *(string - 2) += 4;
        *(string - 1) += 8;
        *(string - 0) += 8;
    }
    if (uinteger & 0x1000000000000000) {
        *(string - 18) += 1;
        *(string - 17) += 1;
        *(string - 16) += 5;
        *(string - 15) += 2;
        *(string - 14) += 9;
        *(string - 13) += 2;
        *(string - 12) += 1;
        *(string - 11) += 5;
        *(string - 10) += 0;
        *(string - 9) += 4;
        *(string - 8) += 6;
        *(string - 7) += 0;
        *(string - 6) += 6;
        *(string - 5) += 8;
        *(string - 4) += 4;
        *(string - 3) += 6;
        *(string - 2) += 9;
        *(string - 1) += 7;
        *(string - 0) += 6;
    }
    if (uinteger & 0x2000000000000000) {
        *(string - 18) += 2;
        *(string - 17) += 3;
        *(string - 16) += 0;
        *(string - 15) += 5;
        *(string - 14) += 8;
        *(string - 13) += 4;
        *(string - 12) += 3;
        *(string - 11) += 0;
        *(string - 10) += 0;
        *(string - 9) += 9;
        *(string - 8) += 2;
        *(string - 7) += 1;
        *(string - 6) += 3;
        *(string - 5) += 6;
        *(string - 4) += 9;
        *(string - 3) += 3;
        *(string - 2) += 9;
        *(string - 1) += 5;
        *(string - 0) += 2;
    }
    if (uinteger & 0x4000000000000000) {
        *(string - 18) += 4;
        *(string - 17) += 6;
        *(string - 16) += 1;
        *(string - 15) += 1;
        *(string - 14) += 6;
        *(string - 13) += 8;
        *(string - 12) += 6;
        *(string - 11) += 0;
        *(string - 10) += 1;
        *(string - 9) += 8;
        *(string - 8) += 4;
        *(string - 7) += 2;
        *(string - 6) += 7;
        *(string - 5) += 3;
        *(string - 4) += 8;
        *(string - 3) += 7;
        *(string - 2) += 9;
        *(string - 1) += 0;
        *(string - 0) += 4;
    }
    if (uinteger & 0x8000000000000000) {
        *(string - 18) += 9;
        *(string - 17) += 2;
        *(string - 16) += 2;
        *(string - 15) += 3;
        *(string - 14) += 3;
        *(string - 13) += 7;
        *(string - 12) += 2;
        *(string - 11) += 0;
        *(string - 10) += 3;
        *(string - 9) += 6;
        *(string - 8) += 8;
        *(string - 7) += 5;
        *(string - 6) += 4;
        *(string - 5) += 7;
        *(string - 4) += 7;
        *(string - 3) += 5;
        *(string - 2) += 8;
        *(string - 1) += 0;
        *(string - 0) += 8;
    }
    inline_System_Decimal_carryOver(string,19)
}

void  System_Decimal_set_Precision(System_Decimal that, System_Int8 precision) {
    that->precision = precision;
}
System_Int8  System_Decimal_get_Precision(System_Decimal that) {
    return that->precision;
}

void  System_Decimal_init__Int8(System_Decimal that, System_Int8 Int8) {
    System_Bool isNegative = Int8 < 0;
    if (isNegative) System_Decimal_set_Precision(that, -1);
    System_UInt8 uinteger = isNegative ? ~Int8 + 1 : Int8;
    System_Decimal_init__UInt8(that, uinteger);
}

void  System_Decimal_init__Int16(System_Decimal that, System_Int16 int16) {
    System_Bool isNegative = int16 < 0;
    if (isNegative) System_Decimal_set_Precision(that, -1);
    System_UInt16 uinteger = isNegative ? ~int16 + 1 : int16;
    System_Decimal_init__UInt16(that, uinteger);
}

void  System_Decimal_init__Int32(System_Decimal that, System_Int32 int32) {
    System_Bool isNegative = int32 < 0;
    if (isNegative) System_Decimal_set_Precision(that, -1);
    System_UInt32 uinteger = isNegative ? ~int32 + 1 : int32;
    System_Decimal_init__UInt32(that, uinteger);
}

void  System_Decimal_init__Int64(System_Decimal that, System_Int64 int64) {
    System_Bool isNegative = int64 < 0;
    if (isNegative) System_Decimal_set_Precision(that, -1);
    System_UInt64 uinteger = isNegative ? ~int64 + 1 : int64;
    System_Decimal_init__UInt64(that, uinteger);
}

void  stack_System_Decimal_toString8(System_Decimal that, System_Char8 array[System_Decimal_Capacity_DEFAULT + 1]) {
    System_UInt8 * string = that->value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 array_string = array + System_Decimal_Capacity_DEFAULT - 1;

    for (System_Size i = 0; i < System_Decimal_Capacity_DEFAULT; ++i) {
        *(array_string - i) = '0' + *(string - i);
    }
    array_string = array;
    for (System_Size l = 0; l < System_Decimal_Capacity_DEFAULT - 1; ++l) {
        if (*(array_string + l) != '0') break;
        *(array_string + l) = ' ';
    }
}

#endif
