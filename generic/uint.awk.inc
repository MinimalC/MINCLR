/* Gemeinfrei. Public Domain. */
#define Generic_T0  System_uint8
/* GENERIC */
/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_auto_Generic_T0)
#include <min/System.values.auto.h>
#endif
#if !defined(code_auto_Generic_T0)
#define code_auto_Generic_T0

/*# Generic_T0 #*/

struct_System_Type  Generic_T0Type  = { .base = stack_System_Object(System_Type), .name = "Generic.T0", .size = sizeof(Generic_T0) };

System_boolean  Generic_T0_isPrintable(Generic_T0 that) {
    return inline_Generic_T0_isPrintable(that);
}

System_size  Generic_T0_tostring8base2__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base2Length_DEFAULT + 1]) {
    System_string8 string = array + Generic_T0_string8base2Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < Generic_T0_string8base2Length_DEFAULT; ++i) {
        n = (that >> i) & 1;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = Generic_T0_string8base2Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_string8base2Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_string8base2Length_DEFAULT) = 0;
    return numbers;
}

System_size  Generic_T0_tostring8base4__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base4Length_DEFAULT + 1]) {
    System_string8 string = array + Generic_T0_string8base4Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < Generic_T0_string8base4Length_DEFAULT; ++i) {
        n = (that >> (i * 2)) & 3;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = Generic_T0_string8base4Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_string8base4Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_string8base4Length_DEFAULT) = 0;
    return numbers;
}

System_size  Generic_T0_tostring8base8__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base8Length_DEFAULT + 1]) {
    System_string8 string = array + Generic_T0_string8base8Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < Generic_T0_string8base8Length_DEFAULT; ++i) {
        n = (that >> (i * 3)) & 7;
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = Generic_T0_string8base8Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_string8base8Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_string8base8Length_DEFAULT) = 0;
    return numbers;
}

System_size  Generic_T0_tostring8base16__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base16Length_DEFAULT + 1]) {
    System_string8 string = array + Generic_T0_string8base16Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < Generic_T0_string8base16Length_DEFAULT; ++i) {
        n = (that >> (i * 4)) & 0xF;
        *(string - i) = n > 9 ? 'A' + (n - 10) : '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = Generic_T0_string8base16Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_string8base16Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_string8base16Length_DEFAULT) = 0;
    return numbers;
}

System_size  Generic_T0_tostring8base10__stack(Generic_T0 that, System_char8 array[Generic_T0_string8base10Length_DEFAULT + 1]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__T0(&decimal, that);
    System_string8 decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 1;
    System_string8 string = array + Generic_T0_string8base10Length_DEFAULT - 1;
    System_char8 n;
    System_size i, zeroes = 0;
    for (i = 0; i < Generic_T0_string8base10Length_DEFAULT; ++i) {
        n = *(decimal_string - i);
        *(string - i) = '0' + n;
        if (!n && i > 0) ++zeroes;
        else zeroes = 0;
    }
    string = array;
    System_size numbers = Generic_T0_string8base10Length_DEFAULT - zeroes;
    if (zeroes) {
        for (i = 0; i < Generic_T0_string8base10Length_DEFAULT; ++i) {
            if (i < numbers) *(string + i) = *(string + i + zeroes);
//            else *(string + i) = 'x';
            else *(string + i) = 0;
        }
    }
    *(array + Generic_T0_string8base10Length_DEFAULT) = 0;
    return numbers;
}

#endif
