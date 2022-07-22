/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt8)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_UInt8)
#define code_System_UInt8

/*# System_UInt8 #*/

struct System_Type  System_UInt8Type  = { .base = stack_System_Object(System_Type), .name = "System.UInt8", .size = sizeof(System_UInt8) };

System_Bool  System_UInt8_isPrintable(System_UInt8 that) {
    return inline_System_UInt8_isPrintable(that);
}

System_Size  System_UInt8_toString8base2__stack(System_UInt8 that, System_Char8 array[System_UInt8_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt8_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt8_toString8base4__stack(System_UInt8 that, System_Char8 array[System_UInt8_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt8_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt8_toString8base8__stack(System_UInt8 that, System_Char8 array[System_UInt8_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt8_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt8_toString8base16__stack(System_UInt8 that, System_Char8 array[System_UInt8_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt8_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt8_toString8base10__stack(System_UInt8 that, System_Char8 array[System_UInt8_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__UInt8(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt8_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8base10Length_DEFAULT) = 0;
    return numbers;
}

System_UInt8  System_UInt8_parsebase10(System_String8 that) {

    System_UInt8 reture = 0;
    if (!Char8_isNumber(that[0])) return reture;

    System_Size count = 1, n = 0;
    while (count < 5 && Char8_isNumber(that[count])) ++count;
    if (count == 3) { reture += (that[n++] - 0x30) * (100); --count; }
    if (count == 2) { reture += (that[n++] - 0x30) * (10); --count; }
    if (count == 1) { reture += (that[n++] - 0x30); --count; }

    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt16)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_UInt16)
#define code_System_UInt16

/*# System_UInt16 #*/

struct System_Type  System_UInt16Type  = { .base = stack_System_Object(System_Type), .name = "System.UInt16", .size = sizeof(System_UInt16) };

System_Bool  System_UInt16_isPrintable(System_UInt16 that) {
    return inline_System_UInt16_isPrintable(that);
}

System_Size  System_UInt16_toString8base2__stack(System_UInt16 that, System_Char8 array[System_UInt16_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt16_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt16_toString8base4__stack(System_UInt16 that, System_Char8 array[System_UInt16_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt16_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt16_toString8base8__stack(System_UInt16 that, System_Char8 array[System_UInt16_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt16_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt16_toString8base16__stack(System_UInt16 that, System_Char8 array[System_UInt16_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt16_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt16_toString8base10__stack(System_UInt16 that, System_Char8 array[System_UInt16_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__UInt16(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt16_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8base10Length_DEFAULT) = 0;
    return numbers;
}

System_UInt16  System_UInt16_parsebase10(System_String8 that) {

    System_UInt16 reture = 0;
    if (!Char8_isNumber(that[0])) return reture;

    System_Size count = 1, n = 0;
    while (count < 5 && Char8_isNumber(that[count])) ++count;
    if (count == 5) { reture += (that[n++] - 0x30) * (10000); --count; }
    if (count == 4) { reture += (that[n++] - 0x30) * (1000); --count; }
    if (count == 3) { reture += (that[n++] - 0x30) * (100); --count; }
    if (count == 2) { reture += (that[n++] - 0x30) * (10); --count; }
    if (count == 1) { reture += (that[n++] - 0x30); --count; }

    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt32)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_UInt32)
#define code_System_UInt32

/*# System_UInt32 #*/

struct System_Type  System_UInt32Type  = { .base = stack_System_Object(System_Type), .name = "System.UInt32", .size = sizeof(System_UInt32) };

System_Bool  System_UInt32_isPrintable(System_UInt32 that) {
    return inline_System_UInt32_isPrintable(that);
}

System_Size  System_UInt32_toString8base2__stack(System_UInt32 that, System_Char8 array[System_UInt32_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt32_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt32_toString8base4__stack(System_UInt32 that, System_Char8 array[System_UInt32_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt32_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt32_toString8base8__stack(System_UInt32 that, System_Char8 array[System_UInt32_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt32_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt32_toString8base16__stack(System_UInt32 that, System_Char8 array[System_UInt32_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt32_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt32_toString8base10__stack(System_UInt32 that, System_Char8 array[System_UInt32_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__UInt32(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt32_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8base10Length_DEFAULT) = 0;
    return numbers;
}

System_UInt32  System_UInt32_parsebase10(System_String8 that) {

    System_UInt32 reture = 0;
    if (!Char8_isNumber(that[0])) return reture;

    System_Size count = 1, n = 0;
    while (count < 5 && Char8_isNumber(that[count])) ++count;
    if (count == 10){ reture += (that[n++] - 0x30) * (1000000000); --count; }
    if (count == 9) { reture += (that[n++] - 0x30) * (100000000); --count; }
    if (count == 8) { reture += (that[n++] - 0x30) * (10000000); --count; }
    if (count == 7) { reture += (that[n++] - 0x30) * (1000000); --count; }
    if (count == 6) { reture += (that[n++] - 0x30) * (100000); --count; }
    if (count == 5) { reture += (that[n++] - 0x30) * (10000); --count; }
    if (count == 4) { reture += (that[n++] - 0x30) * (1000); --count; }
    if (count == 3) { reture += (that[n++] - 0x30) * (100); --count; }
    if (count == 2) { reture += (that[n++] - 0x30) * (10); --count; }
    if (count == 1) { reture += (that[n++] - 0x30); --count; }

    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt64)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_UInt64)
#define code_System_UInt64

/*# System_UInt64 #*/

struct System_Type  System_UInt64Type  = { .base = stack_System_Object(System_Type), .name = "System.UInt64", .size = sizeof(System_UInt64) };

System_Bool  System_UInt64_isPrintable(System_UInt64 that) {
    return inline_System_UInt64_isPrintable(that);
}

System_Size  System_UInt64_toString8base2__stack(System_UInt64 that, System_Char8 array[System_UInt64_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt64_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt64_toString8base4__stack(System_UInt64 that, System_Char8 array[System_UInt64_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt64_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt64_toString8base8__stack(System_UInt64 that, System_Char8 array[System_UInt64_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt64_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt64_toString8base16__stack(System_UInt64 that, System_Char8 array[System_UInt64_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_UInt64_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_UInt64_toString8base10__stack(System_UInt64 that, System_Char8 array[System_UInt64_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__UInt64(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt64_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8base10Length_DEFAULT) = 0;
    return numbers;
}

System_UInt64  System_UInt64_parsebase10(System_String8 that) {

    System_UInt64 reture = 0;
    if (!Char8_isNumber(that[0])) return reture;

    System_Size count = 1, n = 0;
    while (count < 5 && Char8_isNumber(that[count])) ++count;
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
    if (count == 3) { reture += (that[n++] - 0x30) * (100); --count; }
    if (count == 2) { reture += (that[n++] - 0x30) * (10); --count; }
    if (count == 1) { reture += (that[n++] - 0x30); --count; }

    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int8)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_Int8)
#define code_System_Int8

/*# System_Int8 #*/


struct System_Type  System_Int8Type  = { .base = stack_System_Object(System_Type), .name = "System.Int8", .size = sizeof(System_Int8) };

System_Bool  System_Int8_isPrintable(System_Int8 that) {
    return inline_System_Int8_isPrintable(that);
}

System_Size  System_Int8_toString8base2__stack(System_Int8 that, System_Char8 array[System_Int8_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int8_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int8_toString8base4__stack(System_Int8 that, System_Char8 array[System_Int8_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int8_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int8_toString8base8__stack(System_Int8 that, System_Char8 array[System_Int8_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int8_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int8_toString8base16__stack(System_Int8 that, System_Char8 array[System_Int8_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int8_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int8_toString8base10__stack(System_Int8 that, System_Char8 array[System_Int8_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__Int8(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int8_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int8_String8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int16)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_Int16)
#define code_System_Int16

/*# System_Int16 #*/


struct System_Type  System_Int16Type  = { .base = stack_System_Object(System_Type), .name = "System.Int16", .size = sizeof(System_Int16) };

System_Bool  System_Int16_isPrintable(System_Int16 that) {
    return inline_System_Int16_isPrintable(that);
}

System_Size  System_Int16_toString8base2__stack(System_Int16 that, System_Char8 array[System_Int16_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int16_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int16_toString8base4__stack(System_Int16 that, System_Char8 array[System_Int16_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int16_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int16_toString8base8__stack(System_Int16 that, System_Char8 array[System_Int16_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int16_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int16_toString8base16__stack(System_Int16 that, System_Char8 array[System_Int16_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int16_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int16_toString8base10__stack(System_Int16 that, System_Char8 array[System_Int16_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__Int16(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int16_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int16_String8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int32)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_Int32)
#define code_System_Int32

/*# System_Int32 #*/


struct System_Type  System_Int32Type  = { .base = stack_System_Object(System_Type), .name = "System.Int32", .size = sizeof(System_Int32) };

System_Bool  System_Int32_isPrintable(System_Int32 that) {
    return inline_System_Int32_isPrintable(that);
}

System_Size  System_Int32_toString8base2__stack(System_Int32 that, System_Char8 array[System_Int32_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int32_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int32_toString8base4__stack(System_Int32 that, System_Char8 array[System_Int32_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int32_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int32_toString8base8__stack(System_Int32 that, System_Char8 array[System_Int32_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int32_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int32_toString8base16__stack(System_Int32 that, System_Char8 array[System_Int32_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int32_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int32_toString8base10__stack(System_Int32 that, System_Char8 array[System_Int32_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__Int32(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int32_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int32_String8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int64)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_Int64)
#define code_System_Int64

/*# System_Int64 #*/


struct System_Type  System_Int64Type  = { .base = stack_System_Object(System_Type), .name = "System.Int64", .size = sizeof(System_Int64) };

System_Bool  System_Int64_isPrintable(System_Int64 that) {
    return inline_System_Int64_isPrintable(that);
}

System_Size  System_Int64_toString8base2__stack(System_Int64 that, System_Char8 array[System_Int64_String8base2Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int64_String8base2Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8base2Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int64_toString8base4__stack(System_Int64 that, System_Char8 array[System_Int64_String8base4Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int64_String8base4Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8base4Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int64_toString8base8__stack(System_Int64 that, System_Char8 array[System_Int64_String8base8Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int64_String8base8Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8base8Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int64_toString8base16__stack(System_Int64 that, System_Char8 array[System_Int64_String8base16Length_DEFAULT + 1]) {
    System_String8 string = array + System_Int64_String8base16Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8base16Length_DEFAULT) = 0;
    return numbers;
}

System_Size  System_Int64_toString8base10__stack(System_Int64 that, System_Char8 array[System_Int64_String8base10Length_DEFAULT + 1]) {
    struct System_Decimal decimal = stack_System_Decimal();
    System_Decimal_init__Int64(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int64_String8base10Length_DEFAULT - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int64_String8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
