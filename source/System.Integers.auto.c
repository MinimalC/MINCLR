/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt8)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_UInt8)
#define code_System_UInt8

/*# System_UInt8 #*/

struct System_Type System_UInt8Type  = { .base = { .type = typeof(System_Type) }, .name = "System.UInt8", .size = sizeof(System_UInt8) };

System_Bool  System_UInt8_isPrintable(System_UInt8 that) {
    return inline_System_UInt8_isPrintable(that);
}

System_Size  stack_System_UInt8_toString8base2(System_UInt8 that, System_Char8 array[System_UInt8_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_UInt8_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8Capacity_base2; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_UInt8_toString8base2(System_UInt8 that) {
    System_Char8 array[System_UInt8_String8Capacity_base2 + 1];
    System_Size length = stack_System_UInt8_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt8_toString8base4(System_UInt8 that, System_Char8 array[System_UInt8_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_UInt8_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8Capacity_base4; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_UInt8_toString8base4(System_UInt8 that) {
    System_Char8 array[System_UInt8_String8Capacity_base4 + 1];
    System_Size length = stack_System_UInt8_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt8_toString8base8(System_UInt8 that, System_Char8 array[System_UInt8_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_UInt8_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8Capacity_base8; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_UInt8_toString8base8(System_UInt8 that) {
    System_Char8 array[System_UInt8_String8Capacity_base8 + 1];
    System_Size length = stack_System_UInt8_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt8_toString8base16(System_UInt8 that, System_Char8 array[System_UInt8_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_UInt8_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8Capacity_base16; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8Capacity_base16 - zeroes;
    if (!numbers) { numbers = 1; --zeroes; }
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_UInt8_toString8base16(System_UInt8 that) {
    System_Char8 array[System_UInt8_String8Capacity_base16 + 1];
    System_Size length = stack_System_UInt8_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt8_toString8base10(System_UInt8 that, System_Char8 array[System_UInt8_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__UInt8(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt8_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt8_String8Capacity_base10; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt8_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt8_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt8_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_UInt8_toString8base10(System_UInt8 that) {
    System_Char8 array[System_UInt8_String8Capacity_base10 + 1];
    System_Size length = stack_System_UInt8_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
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

#if defined(have_AMD64)
#else
System_UInt8  System_UInt8_divRem(System_UInt8 divident, System_UInt8 divisor, System_UInt8 ref remainder) {
    *remainder = divident % divisor;
    return divident / divisor;
}
#endif

System_UInt8  System_UInt8_toNetworkOrder(System_UInt8 that) {
    return inline_System_UInt8_toNetworkOrder(that);
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt16)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_UInt16)
#define code_System_UInt16

/*# System_UInt16 #*/

struct System_Type System_UInt16Type  = { .base = { .type = typeof(System_Type) }, .name = "System.UInt16", .size = sizeof(System_UInt16) };

System_Bool  System_UInt16_isPrintable(System_UInt16 that) {
    return inline_System_UInt16_isPrintable(that);
}

System_Size  stack_System_UInt16_toString8base2(System_UInt16 that, System_Char8 array[System_UInt16_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_UInt16_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8Capacity_base2; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_UInt16_toString8base2(System_UInt16 that) {
    System_Char8 array[System_UInt16_String8Capacity_base2 + 1];
    System_Size length = stack_System_UInt16_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt16_toString8base4(System_UInt16 that, System_Char8 array[System_UInt16_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_UInt16_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8Capacity_base4; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_UInt16_toString8base4(System_UInt16 that) {
    System_Char8 array[System_UInt16_String8Capacity_base4 + 1];
    System_Size length = stack_System_UInt16_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt16_toString8base8(System_UInt16 that, System_Char8 array[System_UInt16_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_UInt16_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8Capacity_base8; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_UInt16_toString8base8(System_UInt16 that) {
    System_Char8 array[System_UInt16_String8Capacity_base8 + 1];
    System_Size length = stack_System_UInt16_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt16_toString8base16(System_UInt16 that, System_Char8 array[System_UInt16_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_UInt16_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8Capacity_base16; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8Capacity_base16 - zeroes;
    if (!numbers) { numbers = 1; --zeroes; }
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_UInt16_toString8base16(System_UInt16 that) {
    System_Char8 array[System_UInt16_String8Capacity_base16 + 1];
    System_Size length = stack_System_UInt16_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt16_toString8base10(System_UInt16 that, System_Char8 array[System_UInt16_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__UInt16(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt16_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt16_String8Capacity_base10; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt16_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt16_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt16_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_UInt16_toString8base10(System_UInt16 that) {
    System_Char8 array[System_UInt16_String8Capacity_base10 + 1];
    System_Size length = stack_System_UInt16_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
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

#if defined(have_AMD64)
#else
System_UInt16  System_UInt16_divRem(System_UInt16 divident, System_UInt16 divisor, System_UInt16 ref remainder) {
    *remainder = divident % divisor;
    return divident / divisor;
}
#endif

System_UInt16  System_UInt16_toNetworkOrder(System_UInt16 that) {
    return inline_System_UInt16_toNetworkOrder(that);
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt32)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_UInt32)
#define code_System_UInt32

/*# System_UInt32 #*/

struct System_Type System_UInt32Type  = { .base = { .type = typeof(System_Type) }, .name = "System.UInt32", .size = sizeof(System_UInt32) };

System_Bool  System_UInt32_isPrintable(System_UInt32 that) {
    return inline_System_UInt32_isPrintable(that);
}

System_Size  stack_System_UInt32_toString8base2(System_UInt32 that, System_Char8 array[System_UInt32_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_UInt32_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8Capacity_base2; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_UInt32_toString8base2(System_UInt32 that) {
    System_Char8 array[System_UInt32_String8Capacity_base2 + 1];
    System_Size length = stack_System_UInt32_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt32_toString8base4(System_UInt32 that, System_Char8 array[System_UInt32_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_UInt32_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8Capacity_base4; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_UInt32_toString8base4(System_UInt32 that) {
    System_Char8 array[System_UInt32_String8Capacity_base4 + 1];
    System_Size length = stack_System_UInt32_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt32_toString8base8(System_UInt32 that, System_Char8 array[System_UInt32_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_UInt32_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8Capacity_base8; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_UInt32_toString8base8(System_UInt32 that) {
    System_Char8 array[System_UInt32_String8Capacity_base8 + 1];
    System_Size length = stack_System_UInt32_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt32_toString8base16(System_UInt32 that, System_Char8 array[System_UInt32_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_UInt32_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8Capacity_base16; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8Capacity_base16 - zeroes;
    if (!numbers) { numbers = 1; --zeroes; }
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_UInt32_toString8base16(System_UInt32 that) {
    System_Char8 array[System_UInt32_String8Capacity_base16 + 1];
    System_Size length = stack_System_UInt32_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt32_toString8base10(System_UInt32 that, System_Char8 array[System_UInt32_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__UInt32(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt32_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt32_String8Capacity_base10; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt32_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt32_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt32_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_UInt32_toString8base10(System_UInt32 that) {
    System_Char8 array[System_UInt32_String8Capacity_base10 + 1];
    System_Size length = stack_System_UInt32_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
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

#if defined(have_AMD64)
#else
System_UInt32  System_UInt32_divRem(System_UInt32 divident, System_UInt32 divisor, System_UInt32 ref remainder) {
    *remainder = divident % divisor;
    return divident / divisor;
}
#endif

System_UInt32  System_UInt32_toNetworkOrder(System_UInt32 that) {
    return inline_System_UInt32_toNetworkOrder(that);
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Char8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_UInt64)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_UInt64)
#define code_System_UInt64

/*# System_UInt64 #*/

struct System_Type System_UInt64Type  = { .base = { .type = typeof(System_Type) }, .name = "System.UInt64", .size = sizeof(System_UInt64) };

System_Bool  System_UInt64_isPrintable(System_UInt64 that) {
    return inline_System_UInt64_isPrintable(that);
}

System_Size  stack_System_UInt64_toString8base2(System_UInt64 that, System_Char8 array[System_UInt64_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_UInt64_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8Capacity_base2; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_UInt64_toString8base2(System_UInt64 that) {
    System_Char8 array[System_UInt64_String8Capacity_base2 + 1];
    System_Size length = stack_System_UInt64_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt64_toString8base4(System_UInt64 that, System_Char8 array[System_UInt64_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_UInt64_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8Capacity_base4; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_UInt64_toString8base4(System_UInt64 that) {
    System_Char8 array[System_UInt64_String8Capacity_base4 + 1];
    System_Size length = stack_System_UInt64_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt64_toString8base8(System_UInt64 that, System_Char8 array[System_UInt64_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_UInt64_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8Capacity_base8; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_UInt64_toString8base8(System_UInt64 that) {
    System_Char8 array[System_UInt64_String8Capacity_base8 + 1];
    System_Size length = stack_System_UInt64_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt64_toString8base16(System_UInt64 that, System_Char8 array[System_UInt64_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_UInt64_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8Capacity_base16; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8Capacity_base16 - zeroes;
    if (!numbers) { numbers = 1; --zeroes; }
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_UInt64_toString8base16(System_UInt64 that) {
    System_Char8 array[System_UInt64_String8Capacity_base16 + 1];
    System_Size length = stack_System_UInt64_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_UInt64_toString8base10(System_UInt64 that, System_Char8 array[System_UInt64_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__UInt64(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_UInt64_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    for (i = 0; i < System_UInt64_String8Capacity_base10; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_Size numbers = System_UInt64_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_UInt64_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + System_UInt64_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_UInt64_toString8base10(System_UInt64 that) {
    System_Char8 array[System_UInt64_String8Capacity_base10 + 1];
    System_Size length = stack_System_UInt64_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
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

#if defined(have_AMD64)
#else
System_UInt64  System_UInt64_divRem(System_UInt64 divident, System_UInt64 divisor, System_UInt64 ref remainder) {
    *remainder = divident % divisor;
    return divident / divisor;
}
#endif

System_UInt64  System_UInt64_toNetworkOrder(System_UInt64 that) {
    return inline_System_UInt64_toNetworkOrder(that);
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int8)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_Int8)
#define code_System_Int8

/*# System_Int8 #*/


struct System_Type System_Int8Type  = { .base = { .type = typeof(System_Type) }, .name = "System.Int8", .size = sizeof(System_Int8) };

System_Bool  System_Int8_isPrintable(System_Int8 that) {
    return inline_System_Int8_isPrintable(that);
}

System_Size  stack_System_Int8_toString8base2(System_Int8 that, System_Char8 array[System_Int8_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_Int8_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8Capacity_base2 - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_Int8_toString8base2(System_Int8 that) {
    System_Char8 array[System_Int8_String8Capacity_base2 + 1];
    System_Size length = stack_System_Int8_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int8_toString8base4(System_Int8 that, System_Char8 array[System_Int8_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_Int8_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8Capacity_base4 - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_Int8_toString8base4(System_Int8 that) {
    System_Char8 array[System_Int8_String8Capacity_base4 + 1];
    System_Size length = stack_System_Int8_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int8_toString8base8(System_Int8 that, System_Char8 array[System_Int8_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_Int8_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8Capacity_base8 - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_Int8_toString8base8(System_Int8 that) {
    System_Char8 array[System_Int8_String8Capacity_base8 + 1];
    System_Size length = stack_System_Int8_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int8_toString8base16(System_Int8 that, System_Char8 array[System_Int8_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_Int8_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt8 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int8_String8Capacity_base16 - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8Capacity_base16 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_Int8_toString8base16(System_Int8 that) {
    System_Char8 array[System_Int8_String8Capacity_base16 + 1];
    System_Size length = stack_System_Int8_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int8_toString8base10(System_Int8 that, System_Char8 array[System_Int8_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__Int8(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int8_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int8_String8Capacity_base10 - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int8_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int8_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int8_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_Int8_toString8base10(System_Int8 that) {
    System_Char8 array[System_Int8_String8Capacity_base10 + 1];
    System_Size length = stack_System_Int8_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int16)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_Int16)
#define code_System_Int16

/*# System_Int16 #*/


struct System_Type System_Int16Type  = { .base = { .type = typeof(System_Type) }, .name = "System.Int16", .size = sizeof(System_Int16) };

System_Bool  System_Int16_isPrintable(System_Int16 that) {
    return inline_System_Int16_isPrintable(that);
}

System_Size  stack_System_Int16_toString8base2(System_Int16 that, System_Char8 array[System_Int16_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_Int16_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8Capacity_base2 - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_Int16_toString8base2(System_Int16 that) {
    System_Char8 array[System_Int16_String8Capacity_base2 + 1];
    System_Size length = stack_System_Int16_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int16_toString8base4(System_Int16 that, System_Char8 array[System_Int16_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_Int16_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8Capacity_base4 - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_Int16_toString8base4(System_Int16 that) {
    System_Char8 array[System_Int16_String8Capacity_base4 + 1];
    System_Size length = stack_System_Int16_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int16_toString8base8(System_Int16 that, System_Char8 array[System_Int16_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_Int16_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8Capacity_base8 - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_Int16_toString8base8(System_Int16 that) {
    System_Char8 array[System_Int16_String8Capacity_base8 + 1];
    System_Size length = stack_System_Int16_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int16_toString8base16(System_Int16 that, System_Char8 array[System_Int16_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_Int16_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt16 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int16_String8Capacity_base16 - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8Capacity_base16 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_Int16_toString8base16(System_Int16 that) {
    System_Char8 array[System_Int16_String8Capacity_base16 + 1];
    System_Size length = stack_System_Int16_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int16_toString8base10(System_Int16 that, System_Char8 array[System_Int16_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__Int16(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int16_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int16_String8Capacity_base10 - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int16_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int16_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int16_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_Int16_toString8base10(System_Int16 that) {
    System_Char8 array[System_Int16_String8Capacity_base10 + 1];
    System_Size length = stack_System_Int16_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int32)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_Int32)
#define code_System_Int32

/*# System_Int32 #*/


struct System_Type System_Int32Type  = { .base = { .type = typeof(System_Type) }, .name = "System.Int32", .size = sizeof(System_Int32) };

System_Bool  System_Int32_isPrintable(System_Int32 that) {
    return inline_System_Int32_isPrintable(that);
}

System_Size  stack_System_Int32_toString8base2(System_Int32 that, System_Char8 array[System_Int32_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_Int32_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8Capacity_base2 - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_Int32_toString8base2(System_Int32 that) {
    System_Char8 array[System_Int32_String8Capacity_base2 + 1];
    System_Size length = stack_System_Int32_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int32_toString8base4(System_Int32 that, System_Char8 array[System_Int32_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_Int32_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8Capacity_base4 - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_Int32_toString8base4(System_Int32 that) {
    System_Char8 array[System_Int32_String8Capacity_base4 + 1];
    System_Size length = stack_System_Int32_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int32_toString8base8(System_Int32 that, System_Char8 array[System_Int32_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_Int32_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8Capacity_base8 - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_Int32_toString8base8(System_Int32 that) {
    System_Char8 array[System_Int32_String8Capacity_base8 + 1];
    System_Size length = stack_System_Int32_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int32_toString8base16(System_Int32 that, System_Char8 array[System_Int32_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_Int32_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt32 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int32_String8Capacity_base16 - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8Capacity_base16 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_Int32_toString8base16(System_Int32 that) {
    System_Char8 array[System_Int32_String8Capacity_base16 + 1];
    System_Size length = stack_System_Int32_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int32_toString8base10(System_Int32 that, System_Char8 array[System_Int32_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__Int32(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int32_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int32_String8Capacity_base10 - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int32_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int32_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int32_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_Int32_toString8base10(System_Int32 that) {
    System_Char8 array[System_Int32_String8Capacity_base10 + 1];
    System_Size length = stack_System_Int32_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Int64)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_System_Int64)
#define code_System_Int64

/*# System_Int64 #*/


struct System_Type System_Int64Type  = { .base = { .type = typeof(System_Type) }, .name = "System.Int64", .size = sizeof(System_Int64) };

System_Bool  System_Int64_isPrintable(System_Int64 that) {
    return inline_System_Int64_isPrintable(that);
}

System_Size  stack_System_Int64_toString8base2(System_Int64 that, System_Char8 array[System_Int64_String8Capacity_base2 + 1]) {
    System_String8 string = array + System_Int64_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8Capacity_base2 - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  System_Int64_toString8base2(System_Int64 that) {
    System_Char8 array[System_Int64_String8Capacity_base2 + 1];
    System_Size length = stack_System_Int64_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int64_toString8base4(System_Int64 that, System_Char8 array[System_Int64_String8Capacity_base4 + 1]) {
    System_String8 string = array + System_Int64_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8Capacity_base4 - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  System_Int64_toString8base4(System_Int64 that) {
    System_Char8 array[System_Int64_String8Capacity_base4 + 1];
    System_Size length = stack_System_Int64_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int64_toString8base8(System_Int64 that, System_Char8 array[System_Int64_String8Capacity_base8 + 1]) {
    System_String8 string = array + System_Int64_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8Capacity_base8 - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  System_Int64_toString8base8(System_Int64 that) {
    System_Char8 array[System_Int64_String8Capacity_base8 + 1];
    System_Size length = stack_System_Int64_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int64_toString8base16(System_Int64 that, System_Char8 array[System_Int64_String8Capacity_base16 + 1]) {
    System_String8 string = array + System_Int64_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    System_UInt64 u = isNegative ? ~that + 1 : that;
    for (i = 0; i < System_Int64_String8Capacity_base16 - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8Capacity_base16 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  System_Int64_toString8base16(System_Int64 that) {
    System_Char8 array[System_Int64_String8Capacity_base16 + 1];
    System_Size length = stack_System_Int64_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_System_Int64_toString8base10(System_Int64 that, System_Char8 array[System_Int64_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__Int64(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + System_Int64_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < System_Int64_String8Capacity_base10 - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = System_Int64_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < System_Int64_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + System_Int64_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  System_Int64_toString8base10(System_Int64 that) {
    System_Char8 array[System_Int64_String8Capacity_base10 + 1];
    System_Size length = stack_System_Int64_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

#endif
