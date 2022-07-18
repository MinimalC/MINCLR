/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_char8)
#include <min/System.string8.h>
#endif
#if !defined(have_System_uint8)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_uint8)
#define code_System_uint8

/*# System_uint8 #*/

struct System_Type  System_uint8Type  = { .base = stack_System_Object(System_Type), .name = "System.uint8", .size = sizeof(System_uint8) };

System_boolean  System_uint8_isPrintable(System_uint8 that) {
    return inline_System_uint8_isPrintable(that);
}

System_size  System_uint8_tostring8base2__stack(System_uint8 that, System_char8 array[System_uint8_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint8_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint8_string8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint8_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint8_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint8_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint8_tostring8base4__stack(System_uint8 that, System_char8 array[System_uint8_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint8_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint8_string8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint8_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint8_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint8_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint8_tostring8base8__stack(System_uint8 that, System_char8 array[System_uint8_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint8_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint8_string8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint8_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint8_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint8_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint8_tostring8base16__stack(System_uint8 that, System_char8 array[System_uint8_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint8_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint8_string8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint8_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint8_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint8_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint8_tostring8base10__stack(System_uint8 that, System_char8 array[System_uint8_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint8(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_uint8_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint8_string8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint8_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint8_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint8_string8base10Length_DEFAULT) = 0;
    return numbers;
}

System_uint8  System_uint8_parsebase10(System_string8 that) {

    System_uint8 reture = 0;
    if (!char8_isNumber(that[0])) return reture;

    size count = 1, n = 0;
    while (count < 5 && char8_isNumber(that[count])) ++count;
    if (count == 3) { reture += (that[n++] - 0x30) * (100); --count; }
    if (count == 2) { reture += (that[n++] - 0x30) * (10); --count; }
    if (count == 1) { reture += (that[n++] - 0x30); --count; }

    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_char8)
#include <min/System.string8.h>
#endif
#if !defined(have_System_uint16)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_uint16)
#define code_System_uint16

/*# System_uint16 #*/

struct System_Type  System_uint16Type  = { .base = stack_System_Object(System_Type), .name = "System.uint16", .size = sizeof(System_uint16) };

System_boolean  System_uint16_isPrintable(System_uint16 that) {
    return inline_System_uint16_isPrintable(that);
}

System_size  System_uint16_tostring8base2__stack(System_uint16 that, System_char8 array[System_uint16_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint16_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint16_string8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint16_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint16_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint16_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint16_tostring8base4__stack(System_uint16 that, System_char8 array[System_uint16_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint16_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint16_string8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint16_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint16_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint16_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint16_tostring8base8__stack(System_uint16 that, System_char8 array[System_uint16_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint16_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint16_string8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint16_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint16_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint16_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint16_tostring8base16__stack(System_uint16 that, System_char8 array[System_uint16_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint16_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint16_string8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint16_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint16_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint16_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint16_tostring8base10__stack(System_uint16 that, System_char8 array[System_uint16_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint16(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_uint16_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint16_string8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint16_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint16_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint16_string8base10Length_DEFAULT) = 0;
    return numbers;
}

System_uint16  System_uint16_parsebase10(System_string8 that) {

    System_uint16 reture = 0;
    if (!char8_isNumber(that[0])) return reture;

    size count = 1, n = 0;
    while (count < 5 && char8_isNumber(that[count])) ++count;
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
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_char8)
#include <min/System.string8.h>
#endif
#if !defined(have_System_uint32)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_uint32)
#define code_System_uint32

/*# System_uint32 #*/

struct System_Type  System_uint32Type  = { .base = stack_System_Object(System_Type), .name = "System.uint32", .size = sizeof(System_uint32) };

System_boolean  System_uint32_isPrintable(System_uint32 that) {
    return inline_System_uint32_isPrintable(that);
}

System_size  System_uint32_tostring8base2__stack(System_uint32 that, System_char8 array[System_uint32_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint32_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint32_string8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint32_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint32_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint32_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint32_tostring8base4__stack(System_uint32 that, System_char8 array[System_uint32_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint32_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint32_string8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint32_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint32_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint32_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint32_tostring8base8__stack(System_uint32 that, System_char8 array[System_uint32_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint32_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint32_string8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint32_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint32_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint32_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint32_tostring8base16__stack(System_uint32 that, System_char8 array[System_uint32_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint32_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint32_string8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint32_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint32_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint32_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint32_tostring8base10__stack(System_uint32 that, System_char8 array[System_uint32_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint32(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_uint32_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint32_string8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint32_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint32_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint32_string8base10Length_DEFAULT) = 0;
    return numbers;
}

System_uint32  System_uint32_parsebase10(System_string8 that) {

    System_uint32 reture = 0;
    if (!char8_isNumber(that[0])) return reture;

    size count = 1, n = 0;
    while (count < 5 && char8_isNumber(that[count])) ++count;
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
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_char8)
#include <min/System.string8.h>
#endif
#if !defined(have_System_uint64)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_uint64)
#define code_System_uint64

/*# System_uint64 #*/

struct System_Type  System_uint64Type  = { .base = stack_System_Object(System_Type), .name = "System.uint64", .size = sizeof(System_uint64) };

System_boolean  System_uint64_isPrintable(System_uint64 that) {
    return inline_System_uint64_isPrintable(that);
}

System_size  System_uint64_tostring8base2__stack(System_uint64 that, System_char8 array[System_uint64_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint64_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint64_string8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint64_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint64_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint64_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint64_tostring8base4__stack(System_uint64 that, System_char8 array[System_uint64_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint64_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint64_string8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint64_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint64_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint64_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint64_tostring8base8__stack(System_uint64 that, System_char8 array[System_uint64_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint64_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint64_string8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint64_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint64_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint64_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint64_tostring8base16__stack(System_uint64 that, System_char8 array[System_uint64_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_uint64_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint64_string8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint64_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint64_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint64_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_uint64_tostring8base10__stack(System_uint64 that, System_char8 array[System_uint64_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint64(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_uint64_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < System_uint64_string8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = System_uint64_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_uint64_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_uint64_string8base10Length_DEFAULT) = 0;
    return numbers;
}

System_uint64  System_uint64_parsebase10(System_string8 that) {

    System_uint64 reture = 0;
    if (!char8_isNumber(that[0])) return reture;

    size count = 1, n = 0;
    while (count < 5 && char8_isNumber(that[count])) ++count;
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
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_int8)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_int8)
#define code_System_int8

/*# System_int8 #*/


struct System_Type  System_int8Type  = { .base = stack_System_Object(System_Type), .name = "System.int8", .size = sizeof(System_int8) };

System_boolean  System_int8_isPrintable(System_int8 that) {
    return inline_System_int8_isPrintable(that);
}

System_size  System_int8_tostring8base2__stack(System_int8 that, System_char8 array[System_int8_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_int8_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int8_string8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int8_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int8_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int8_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int8_tostring8base4__stack(System_int8 that, System_char8 array[System_int8_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_int8_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int8_string8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int8_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int8_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int8_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int8_tostring8base8__stack(System_int8 that, System_char8 array[System_int8_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_int8_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int8_string8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int8_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int8_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int8_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int8_tostring8base16__stack(System_int8 that, System_char8 array[System_int8_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_int8_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int8_string8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int8_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int8_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int8_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int8_tostring8base10__stack(System_int8 that, System_char8 array[System_int8_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__int8(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_int8_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    for (i = 0; i < System_int8_string8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int8_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int8_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int8_string8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_int16)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_int16)
#define code_System_int16

/*# System_int16 #*/


struct System_Type  System_int16Type  = { .base = stack_System_Object(System_Type), .name = "System.int16", .size = sizeof(System_int16) };

System_boolean  System_int16_isPrintable(System_int16 that) {
    return inline_System_int16_isPrintable(that);
}

System_size  System_int16_tostring8base2__stack(System_int16 that, System_char8 array[System_int16_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_int16_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int16_string8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int16_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int16_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int16_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int16_tostring8base4__stack(System_int16 that, System_char8 array[System_int16_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_int16_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int16_string8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int16_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int16_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int16_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int16_tostring8base8__stack(System_int16 that, System_char8 array[System_int16_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_int16_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int16_string8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int16_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int16_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int16_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int16_tostring8base16__stack(System_int16 that, System_char8 array[System_int16_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_int16_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int16_string8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int16_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int16_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int16_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int16_tostring8base10__stack(System_int16 that, System_char8 array[System_int16_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__int16(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_int16_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    for (i = 0; i < System_int16_string8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int16_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int16_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int16_string8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_int32)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_int32)
#define code_System_int32

/*# System_int32 #*/


struct System_Type  System_int32Type  = { .base = stack_System_Object(System_Type), .name = "System.int32", .size = sizeof(System_int32) };

System_boolean  System_int32_isPrintable(System_int32 that) {
    return inline_System_int32_isPrintable(that);
}

System_size  System_int32_tostring8base2__stack(System_int32 that, System_char8 array[System_int32_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_int32_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int32_string8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int32_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int32_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int32_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int32_tostring8base4__stack(System_int32 that, System_char8 array[System_int32_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_int32_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int32_string8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int32_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int32_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int32_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int32_tostring8base8__stack(System_int32 that, System_char8 array[System_int32_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_int32_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int32_string8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int32_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int32_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int32_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int32_tostring8base16__stack(System_int32 that, System_char8 array[System_int32_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_int32_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int32_string8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int32_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int32_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int32_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int32_tostring8base10__stack(System_int32 that, System_char8 array[System_int32_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__int32(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_int32_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    for (i = 0; i < System_int32_string8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int32_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int32_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int32_string8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_int64)
#include <min/System.values.auto.h>
#endif
#if !defined(code_System_int64)
#define code_System_int64

/*# System_int64 #*/


struct System_Type  System_int64Type  = { .base = stack_System_Object(System_Type), .name = "System.int64", .size = sizeof(System_int64) };

System_boolean  System_int64_isPrintable(System_int64 that) {
    return inline_System_int64_isPrintable(that);
}

System_size  System_int64_tostring8base2__stack(System_int64 that, System_char8 array[System_int64_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + System_int64_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int64_string8base2Length_DEFAULT - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int64_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int64_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int64_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int64_tostring8base4__stack(System_int64 that, System_char8 array[System_int64_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + System_int64_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int64_string8base4Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int64_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int64_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int64_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int64_tostring8base8__stack(System_int64 that, System_char8 array[System_int64_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + System_int64_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int64_string8base8Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int64_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int64_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int64_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int64_tostring8base16__stack(System_int64 that, System_char8 array[System_int64_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + System_int64_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    System_uint64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_int64_string8base16Length_DEFAULT - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int64_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int64_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int64_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  System_int64_tostring8base10__stack(System_int64 that, System_char8 array[System_int64_string8base10Length_DEFAULT + 1]) {
    struct System_decimal decimal = stack_System_decimal();
    System_decimal_init__int64(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + System_int64_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    System_boolean isNegative = that < 0;
    for (i = 0; i < System_int64_string8base10Length_DEFAULT - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_size numbers = System_int64_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < System_int64_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_int64_string8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
