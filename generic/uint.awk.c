/* Gemeinfrei. Public Domain. */
#define Generic_T0  System_UInt8
/* GENERIC */
/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_Generic_T0)
#include <min/System.values.auto.h>
#endif
#if !defined(code_Generic_T0)
#define code_Generic_T0

/*# Generic_T0 #*/

struct System_Type Generic_T0Type  = { .base = stack_System_Object(System_Type), .name = "Generic.T0", .size = sizeof(Generic_T0) };

System_Bool  Generic_T0_isPrintable(Generic_T0 that) {
    return inline_Generic_T0_isPrintable(that);
}

System_Size  stack_Generic_T0_toString8base2(Generic_T0 that, System_Char8 array[Generic_T0_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + Generic_T0_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < Generic_T0_String8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = Generic_T0_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  stack_Generic_T0_toString8base4(Generic_T0 that, System_Char8 array[Generic_T0_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + Generic_T0_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < Generic_T0_String8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = Generic_T0_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  stack_Generic_T0_toString8base8(Generic_T0 that, System_Char8 array[Generic_T0_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + Generic_T0_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < Generic_T0_String8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = Generic_T0_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  stack_Generic_T0_toString8base16(Generic_T0 that, System_Char8 array[Generic_T0_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + Generic_T0_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < Generic_T0_String8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = Generic_T0_String8base16Length_DEFAULT - zeroes;
    if (!numbers) { numbers = 1; --zeroes; }
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  stack_Generic_T0_toString8base10(Generic_T0 that, System_Char8 array[Generic_T0_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__T0(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + Generic_T0_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < Generic_T0_String8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = Generic_T0_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_String8base10Length_DEFAULT) = 0;
    return numbers;
}

Generic_T0  Generic_T0_parsebase10(System_String8 that) {

    Generic_T0 reture = 0;
    if (!Char8_isNumber(that[0])) return reture;

    System_Size count = 1, n = 0;
    while (count < 5 && Char8_isNumber(that[count])) ++count;
##if Type == "UInt64"
    if (count == 20){ reture += (that[n++] - 0x30) * (0x8AC7230489E80000); --count; }
    if (count == 19){ reture += (that[n++] - 0x30) * (1000000000000000000); --count; }
    if (count == 18){ reture += (that[n++] - 0x30) * (100000000000000000); --count; }
    if (count == 17){ reture += (that[n++] - 0x30) * (10000000000000000); --count; }
    if (count == 16){ reture += (that[n++] - 0x30) * (1000000000000000); --count; }
    if (count == 15){ reture += (that[n++] - 0x30) * (100000000000000); --count; }
    if (count == 14){ reture += (that[n++] - 0x30) * (10000000000000); --count; }
    if (count == 13){ reture += (that[n++] - 0x30) * (1000000000000); --count; }
    if (count == 12){ reture += (that[n++] - 0x30) * (100000000000); --count; }
    if (count == 11){ reture += (that[n++] - 0x30) * (10000000000); --count; }
    if (count == 10){ reture += (that[n++] - 0x30) * (1000000000); --count; }
    if (count == 9) { reture += (that[n++] - 0x30) * (100000000); --count; }
    if (count == 8) { reture += (that[n++] - 0x30) * (10000000); --count; }
    if (count == 7) { reture += (that[n++] - 0x30) * (1000000); --count; }
    if (count == 6) { reture += (that[n++] - 0x30) * (100000); --count; }
    if (count == 5) { reture += (that[n++] - 0x30) * (10000); --count; }
    if (count == 4) { reture += (that[n++] - 0x30) * (1000); --count; }
##endif
##if Type == "UInt32"
    if (count == 10){ reture += (that[n++] - 0x30) * (1000000000); --count; }
    if (count == 9) { reture += (that[n++] - 0x30) * (100000000); --count; }
    if (count == 8) { reture += (that[n++] - 0x30) * (10000000); --count; }
    if (count == 7) { reture += (that[n++] - 0x30) * (1000000); --count; }
    if (count == 6) { reture += (that[n++] - 0x30) * (100000); --count; }
    if (count == 5) { reture += (that[n++] - 0x30) * (10000); --count; }
    if (count == 4) { reture += (that[n++] - 0x30) * (1000); --count; }
##endif
##if Type == "UInt16"
    if (count == 5) { reture += (that[n++] - 0x30) * (10000); --count; }
    if (count == 4) { reture += (that[n++] - 0x30) * (1000); --count; }
##endif
    if (count == 3) { reture += (that[n++] - 0x30) * (100); --count; }
    if (count == 2) { reture += (that[n++] - 0x30) * (10); --count; }
    if (count == 1) { reture += (that[n++] - 0x30); --count; }

    return reture;
}

#endif
