/* Gemeinfrei. Public Domain. */
#define Generic_T0  System_Int8
/* GENERIC */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_Generic_T0)
#include <min/System.Integers.auto.h>
#endif
#if !defined(code_Generic_T0)
#define code_Generic_T0

/*# Generic_T0 #*/

##if Type == "Int64"
##set Generic_uT = "System_UInt64"
##else if Type == "Int32"
##set Generic_uT = "System_UInt32"
##else if Type == "Int16"
##set Generic_uT = "System_UInt16"
##else if Type == "Int8"
##set Generic_uT = "System_UInt8"
##else
##error "Unknown Type. System.int.awk implements Int8, Int16, Int32 and Int64."
##endif

struct System_Type Generic_T0Type  = { .base = { .type = typeof(System_Type) }, .name = "Generic.T0", .size = sizeof(Generic_T0) };

System_Bool  Generic_T0_isPrintable(Generic_T0 that) {
    return inline_Generic_T0_isPrintable(that);
}

System_Size  stack_Generic_T0_toString8base2(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base2 + 1]) {
    System_String8 string = array + Generic_T0_String8Capacity_base2 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    #Generic_uT u = isNegative ? ~that + 1 : that;
    for (i = 0; i < Generic_T0_String8Capacity_base2 - 1; ++i) {
        n = (u >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = Generic_T0_String8Capacity_base2 - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8Capacity_base2; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + Generic_T0_String8Capacity_base2) = 0;
    return numbers;
}

System_String8  Generic_T0_toString8base2(Generic_T0 that) {
    System_Char8 array[Generic_T0_String8Capacity_base2 + 1];
    System_Size length = stack_Generic_T0_toString8base2(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_Generic_T0_toString8base4(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base4 + 1]) {
    System_String8 string = array + Generic_T0_String8Capacity_base4 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    #Generic_uT u = isNegative ? ~that + 1 : that;
    for (i = 0; i < Generic_T0_String8Capacity_base4 - 1; ++i) {
        n = (u >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = Generic_T0_String8Capacity_base4 - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8Capacity_base4; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + Generic_T0_String8Capacity_base4) = 0;
    return numbers;
}

System_String8  Generic_T0_toString8base4(Generic_T0 that) {
    System_Char8 array[Generic_T0_String8Capacity_base4 + 1];
    System_Size length = stack_Generic_T0_toString8base4(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_Generic_T0_toString8base8(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base8 + 1]) {
    System_String8 string = array + Generic_T0_String8Capacity_base8 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    #Generic_uT u = isNegative ? ~that + 1 : that;
    for (i = 0; i < Generic_T0_String8Capacity_base8 - 1; ++i) {
        n = (u >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = Generic_T0_String8Capacity_base8 - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8Capacity_base8; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + Generic_T0_String8Capacity_base8) = 0;
    return numbers;
}

System_String8  Generic_T0_toString8base8(Generic_T0 that) {
    System_Char8 array[Generic_T0_String8Capacity_base8 + 1];
    System_Size length = stack_Generic_T0_toString8base8(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_Generic_T0_toString8base16(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base16 + 1]) {
    System_String8 string = array + Generic_T0_String8Capacity_base16 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    #Generic_uT u = isNegative ? ~that + 1 : that;
    for (i = 0; i < Generic_T0_String8Capacity_base16 - 1; ++i) {
        n = (u >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = Generic_T0_String8Capacity_base16 - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8Capacity_base16; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + Generic_T0_String8Capacity_base16) = 0;
    return numbers;
}

System_String8  Generic_T0_toString8base16(Generic_T0 that) {
    System_Char8 array[Generic_T0_String8Capacity_base16 + 1];
    System_Size length = stack_Generic_T0_toString8base16(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

System_Size  stack_Generic_T0_toString8base10(Generic_T0 that, System_Char8 array[Generic_T0_String8Capacity_base10 + 1]) {
    struct System_Decimal decimal; System_Stack_clear(decimal);
    System_Decimal_init__T0(&decimal, that);
    System_String8 decimal_string = decimal.value + System_Decimal_Capacity_DEFAULT - 1;
    System_String8 string = array + Generic_T0_String8Capacity_base10 - 1;
    System_Char8 n;
    System_Size i, zeroes = 0;
    System_Bool isNegative = that < 0;
    for (i = 0; i < Generic_T0_String8Capacity_base10 - 1; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    if (!isNegative) ++zeroes;
    System_Size numbers = Generic_T0_String8Capacity_base10 - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_String8Capacity_base10; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    if (isNegative) *(string) = '-';
    *(array + Generic_T0_String8Capacity_base10) = 0;
    return numbers;
}

System_String8  Generic_T0_toString8base10(Generic_T0 that) {
    System_Char8 array[Generic_T0_String8Capacity_base10 + 1];
    System_Size length = stack_Generic_T0_toString8base10(that, array);
    System_String8 reture = (System_String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(array, reture);
    return reture;
}

#endif
