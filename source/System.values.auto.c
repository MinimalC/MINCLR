/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_uint8)
#define code_auto_System_uint8
/*# System_uint8 #*/
struct_System_String  STRING_System_uint8 = const_System_String("System.uint8");
struct_System_Type  System_uint8Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_uint8, .size = sizeof(System_uint8) };
System_size  System_uint8_string8base2Length = System_uint8_string8base2Length_DEFAULT;
System_size  System_uint8_string8base4Length = System_uint8_string8base4Length_DEFAULT;
System_size  System_uint8_string8base8Length = System_uint8_string8base8Length_DEFAULT;
System_size  System_uint8_string8base10Length = System_uint8_string8base10Length_DEFAULT;
System_size  System_uint8_string8base16Length = System_uint8_string8base16Length_DEFAULT;
System_boolean  System_uint8_isPrintable(System_uint8 that) {
    return inline_System_uint8_isPrintable(that);
}
System_void  System_uint8_tostring8base2__stack(System_uint8 that, System_char8 array[System_uint8_string8base2Length_DEFAULT]) {
    System_string8 string = array + System_uint8_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint8_string8base2Length_DEFAULT - 1; ++i) {
        charN = (that >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint8_tostring8base4__stack(System_uint8 that, System_char8 array[System_uint8_string8base4Length_DEFAULT]) {
    System_string8 string = array + System_uint8_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint8_string8base4Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint8_tostring8base8__stack(System_uint8 that, System_char8 array[System_uint8_string8base8Length_DEFAULT]) {
    System_string8 string = array + System_uint8_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint8_string8base8Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint8_tostring8base16__stack(System_uint8 that, System_char8 array[System_uint8_string8base16Length_DEFAULT]) {
    System_string8 string = array + System_uint8_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint8_string8base16Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_uint8_tostring8base10__stack(System_uint8 that, System_char8 array[System_uint8_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint8(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_uint8_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_uint8_string8base10Length_DEFAULT - 1; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    for (System_size l = 0; l < System_uint8_string8base10Length_DEFAULT - 2; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_uint16)
#define code_auto_System_uint16
/*# System_uint16 #*/
struct_System_String  STRING_System_uint16 = const_System_String("System.uint16");
struct_System_Type  System_uint16Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_uint16, .size = sizeof(System_uint16) };
System_size  System_uint16_string8base2Length = System_uint16_string8base2Length_DEFAULT;
System_size  System_uint16_string8base4Length = System_uint16_string8base4Length_DEFAULT;
System_size  System_uint16_string8base8Length = System_uint16_string8base8Length_DEFAULT;
System_size  System_uint16_string8base10Length = System_uint16_string8base10Length_DEFAULT;
System_size  System_uint16_string8base16Length = System_uint16_string8base16Length_DEFAULT;
System_boolean  System_uint16_isPrintable(System_uint16 that) {
    return inline_System_uint16_isPrintable(that);
}
System_void  System_uint16_tostring8base2__stack(System_uint16 that, System_char8 array[System_uint16_string8base2Length_DEFAULT]) {
    System_string8 string = array + System_uint16_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint16_string8base2Length_DEFAULT - 1; ++i) {
        charN = (that >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint16_tostring8base4__stack(System_uint16 that, System_char8 array[System_uint16_string8base4Length_DEFAULT]) {
    System_string8 string = array + System_uint16_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint16_string8base4Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint16_tostring8base8__stack(System_uint16 that, System_char8 array[System_uint16_string8base8Length_DEFAULT]) {
    System_string8 string = array + System_uint16_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint16_string8base8Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint16_tostring8base16__stack(System_uint16 that, System_char8 array[System_uint16_string8base16Length_DEFAULT]) {
    System_string8 string = array + System_uint16_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint16_string8base16Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_uint16_tostring8base10__stack(System_uint16 that, System_char8 array[System_uint16_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint16(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_uint16_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_uint16_string8base10Length_DEFAULT - 1; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    for (System_size l = 0; l < System_uint16_string8base10Length_DEFAULT - 2; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_uint32)
#define code_auto_System_uint32
/*# System_uint32 #*/
struct_System_String  STRING_System_uint32 = const_System_String("System.uint32");
struct_System_Type  System_uint32Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_uint32, .size = sizeof(System_uint32) };
System_size  System_uint32_string8base2Length = System_uint32_string8base2Length_DEFAULT;
System_size  System_uint32_string8base4Length = System_uint32_string8base4Length_DEFAULT;
System_size  System_uint32_string8base8Length = System_uint32_string8base8Length_DEFAULT;
System_size  System_uint32_string8base10Length = System_uint32_string8base10Length_DEFAULT;
System_size  System_uint32_string8base16Length = System_uint32_string8base16Length_DEFAULT;
System_boolean  System_uint32_isPrintable(System_uint32 that) {
    return inline_System_uint32_isPrintable(that);
}
System_void  System_uint32_tostring8base2__stack(System_uint32 that, System_char8 array[System_uint32_string8base2Length_DEFAULT]) {
    System_string8 string = array + System_uint32_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint32_string8base2Length_DEFAULT - 1; ++i) {
        charN = (that >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint32_tostring8base4__stack(System_uint32 that, System_char8 array[System_uint32_string8base4Length_DEFAULT]) {
    System_string8 string = array + System_uint32_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint32_string8base4Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint32_tostring8base8__stack(System_uint32 that, System_char8 array[System_uint32_string8base8Length_DEFAULT]) {
    System_string8 string = array + System_uint32_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint32_string8base8Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint32_tostring8base16__stack(System_uint32 that, System_char8 array[System_uint32_string8base16Length_DEFAULT]) {
    System_string8 string = array + System_uint32_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint32_string8base16Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_uint32_tostring8base10__stack(System_uint32 that, System_char8 array[System_uint32_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint32(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_uint32_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_uint32_string8base10Length_DEFAULT - 1; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    for (System_size l = 0; l < System_uint32_string8base10Length_DEFAULT - 2; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_uint64)
#define code_auto_System_uint64
/*# System_uint64 #*/
struct_System_String  STRING_System_uint64 = const_System_String("System.uint64");
struct_System_Type  System_uint64Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_uint64, .size = sizeof(System_uint64) };
System_size  System_uint64_string8base2Length = System_uint64_string8base2Length_DEFAULT;
System_size  System_uint64_string8base4Length = System_uint64_string8base4Length_DEFAULT;
System_size  System_uint64_string8base8Length = System_uint64_string8base8Length_DEFAULT;
System_size  System_uint64_string8base10Length = System_uint64_string8base10Length_DEFAULT;
System_size  System_uint64_string8base16Length = System_uint64_string8base16Length_DEFAULT;
System_boolean  System_uint64_isPrintable(System_uint64 that) {
    return inline_System_uint64_isPrintable(that);
}
System_void  System_uint64_tostring8base2__stack(System_uint64 that, System_char8 array[System_uint64_string8base2Length_DEFAULT]) {
    System_string8 string = array + System_uint64_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint64_string8base2Length_DEFAULT - 1; ++i) {
        charN = (that >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint64_tostring8base4__stack(System_uint64 that, System_char8 array[System_uint64_string8base4Length_DEFAULT]) {
    System_string8 string = array + System_uint64_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint64_string8base4Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint64_tostring8base8__stack(System_uint64 that, System_char8 array[System_uint64_string8base8Length_DEFAULT]) {
    System_string8 string = array + System_uint64_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint64_string8base8Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_uint64_tostring8base16__stack(System_uint64 that, System_char8 array[System_uint64_string8base16Length_DEFAULT]) {
    System_string8 string = array + System_uint64_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_uint64_string8base16Length_DEFAULT - 1; ++i) {
        charN = (that >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_uint64_tostring8base10__stack(System_uint64 that, System_char8 array[System_uint64_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__uint64(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_uint64_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_uint64_string8base10Length_DEFAULT - 1; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    for (System_size l = 0; l < System_uint64_string8base10Length_DEFAULT - 2; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_int8)
#define code_auto_System_int8
/*# System_int8 #*/
struct_System_String  STRING_System_int8 = const_System_String("System.int8");
struct_System_Type  System_int8Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_int8, .size = sizeof(System_int8) };
System_size  System_int8_string8base2Length = System_int8_string8base2Length_DEFAULT;
System_size  System_int8_string8base4Length = System_int8_string8base4Length_DEFAULT;
System_size  System_int8_string8base8Length = System_int8_string8base8Length_DEFAULT;
System_size  System_int8_string8base10Length = System_int8_string8base10Length_DEFAULT;
System_size  System_int8_string8base16Length = System_int8_string8base16Length_DEFAULT;
System_boolean  System_int8_isPrintable(System_int8 that) {
    return inline_System_int8_isPrintable(that);
}
System_void  System_int8_tostring8base2__stack(System_int8 that, System_char8 array[System_int8_string8base2Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint8 charU = isNegative ? ~that + 1 : that;
    string += System_int8_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int8_string8base2Length_DEFAULT - 2; ++i) {
        charN = (charU >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int8_tostring8base4__stack(System_int8 that, System_char8 array[System_int8_string8base4Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint8 charU = isNegative ? ~that + 1 : that;
    string += System_int8_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int8_string8base4Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int8_tostring8base8__stack(System_int8 that, System_char8 array[System_int8_string8base8Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint8 charU = isNegative ? ~that + 1 : that;
    string += System_int8_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int8_string8base8Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int8_tostring8base16__stack(System_int8 that, System_char8 array[System_int8_string8base16Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint8 charU = isNegative ? ~that + 1 : that;
    string += System_int8_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int8_string8base16Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_int8_tostring8base10__stack(System_int8 that, System_char8 array[System_int8_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__int8(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_int8_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_int8_string8base10Length_DEFAULT - 2; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    System_boolean isNegative = that < 0;
    if (isNegative) *(string) = '-';
    else *(string) = ' ';
    for (System_size l = 0; l < System_int8_string8base10Length_DEFAULT - 3; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_int16)
#define code_auto_System_int16
/*# System_int16 #*/
struct_System_String  STRING_System_int16 = const_System_String("System.int16");
struct_System_Type  System_int16Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_int16, .size = sizeof(System_int16) };
System_size  System_int16_string8base2Length = System_int16_string8base2Length_DEFAULT;
System_size  System_int16_string8base4Length = System_int16_string8base4Length_DEFAULT;
System_size  System_int16_string8base8Length = System_int16_string8base8Length_DEFAULT;
System_size  System_int16_string8base10Length = System_int16_string8base10Length_DEFAULT;
System_size  System_int16_string8base16Length = System_int16_string8base16Length_DEFAULT;
System_boolean  System_int16_isPrintable(System_int16 that) {
    return inline_System_int16_isPrintable(that);
}
System_void  System_int16_tostring8base2__stack(System_int16 that, System_char8 array[System_int16_string8base2Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint16 charU = isNegative ? ~that + 1 : that;
    string += System_int16_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int16_string8base2Length_DEFAULT - 2; ++i) {
        charN = (charU >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int16_tostring8base4__stack(System_int16 that, System_char8 array[System_int16_string8base4Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint16 charU = isNegative ? ~that + 1 : that;
    string += System_int16_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int16_string8base4Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int16_tostring8base8__stack(System_int16 that, System_char8 array[System_int16_string8base8Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint16 charU = isNegative ? ~that + 1 : that;
    string += System_int16_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int16_string8base8Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int16_tostring8base16__stack(System_int16 that, System_char8 array[System_int16_string8base16Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint16 charU = isNegative ? ~that + 1 : that;
    string += System_int16_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int16_string8base16Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_int16_tostring8base10__stack(System_int16 that, System_char8 array[System_int16_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__int16(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_int16_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_int16_string8base10Length_DEFAULT - 2; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    System_boolean isNegative = that < 0;
    if (isNegative) *(string) = '-';
    else *(string) = ' ';
    for (System_size l = 0; l < System_int16_string8base10Length_DEFAULT - 3; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_int32)
#define code_auto_System_int32
/*# System_int32 #*/
struct_System_String  STRING_System_int32 = const_System_String("System.int32");
struct_System_Type  System_int32Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_int32, .size = sizeof(System_int32) };
System_size  System_int32_string8base2Length = System_int32_string8base2Length_DEFAULT;
System_size  System_int32_string8base4Length = System_int32_string8base4Length_DEFAULT;
System_size  System_int32_string8base8Length = System_int32_string8base8Length_DEFAULT;
System_size  System_int32_string8base10Length = System_int32_string8base10Length_DEFAULT;
System_size  System_int32_string8base16Length = System_int32_string8base16Length_DEFAULT;
System_boolean  System_int32_isPrintable(System_int32 that) {
    return inline_System_int32_isPrintable(that);
}
System_void  System_int32_tostring8base2__stack(System_int32 that, System_char8 array[System_int32_string8base2Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint32 charU = isNegative ? ~that + 1 : that;
    string += System_int32_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int32_string8base2Length_DEFAULT - 2; ++i) {
        charN = (charU >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int32_tostring8base4__stack(System_int32 that, System_char8 array[System_int32_string8base4Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint32 charU = isNegative ? ~that + 1 : that;
    string += System_int32_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int32_string8base4Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int32_tostring8base8__stack(System_int32 that, System_char8 array[System_int32_string8base8Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint32 charU = isNegative ? ~that + 1 : that;
    string += System_int32_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int32_string8base8Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int32_tostring8base16__stack(System_int32 that, System_char8 array[System_int32_string8base16Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint32 charU = isNegative ? ~that + 1 : that;
    string += System_int32_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int32_string8base16Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_int32_tostring8base10__stack(System_int32 that, System_char8 array[System_int32_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__int32(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_int32_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_int32_string8base10Length_DEFAULT - 2; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    System_boolean isNegative = that < 0;
    if (isNegative) *(string) = '-';
    else *(string) = ' ';
    for (System_size l = 0; l < System_int32_string8base10Length_DEFAULT - 3; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
/* Gemeinfrei. Public Domain. */
/* AUTOGEN */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_auto_System_int64)
#define code_auto_System_int64
/*# System_int64 #*/
struct_System_String  STRING_System_int64 = const_System_String("System.int64");
struct_System_Type  System_int64Type  = { .base = stack_System_Object(System_Type), .name = &STRING_System_int64, .size = sizeof(System_int64) };
System_size  System_int64_string8base2Length = System_int64_string8base2Length_DEFAULT;
System_size  System_int64_string8base4Length = System_int64_string8base4Length_DEFAULT;
System_size  System_int64_string8base8Length = System_int64_string8base8Length_DEFAULT;
System_size  System_int64_string8base10Length = System_int64_string8base10Length_DEFAULT;
System_size  System_int64_string8base16Length = System_int64_string8base16Length_DEFAULT;
System_boolean  System_int64_isPrintable(System_int64 that) {
    return inline_System_int64_isPrintable(that);
}
System_void  System_int64_tostring8base2__stack(System_int64 that, System_char8 array[System_int64_string8base2Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint64 charU = isNegative ? ~that + 1 : that;
    string += System_int64_string8base2Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int64_string8base2Length_DEFAULT - 2; ++i) {
        charN = (charU >> i) & 1;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int64_tostring8base4__stack(System_int64 that, System_char8 array[System_int64_string8base4Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint64 charU = isNegative ? ~that + 1 : that;
    string += System_int64_string8base4Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int64_string8base4Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 2)) & 3;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int64_tostring8base8__stack(System_int64 that, System_char8 array[System_int64_string8base8Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint64 charU = isNegative ? ~that + 1 : that;
    string += System_int64_string8base8Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int64_string8base8Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 3)) & 7;
        *(string - i) = '0' + charN;
    }
}
System_void  System_int64_tostring8base16__stack(System_int64 that, System_char8 array[System_int64_string8base16Length_DEFAULT]) {
    System_string8 string = array;
    System_boolean isNegative = that < 0;
    *(string) = isNegative ? '-' : ' ';
    System_uint64 charU = isNegative ? ~that + 1 : that;
    string += System_int64_string8base16Length_DEFAULT - 2;
    System_uint8 charN;
    for (System_size i = 0; i < System_int64_string8base16Length_DEFAULT - 2; ++i) {
        charN = (charU >> (i * 4)) & 0xF;
        *(string - i) = charN > 9 ? 'A' + (charN - 10) : '0' + charN;
    }
}
System_void  System_int64_tostring8base10__stack(System_int64 that, System_char8 array[System_int64_string8base10Length_DEFAULT]) {
    System_decimal decimal = stack_System_decimal();
    System_decimal_init__int64(&decimal, that);
    System_uint8 * decimal_string = decimal.value + System_decimal_Capacity_DEFAULT - 2;
    System_string8 string = array + System_int64_string8base10Length_DEFAULT - 2;
    for (System_size i = 0; i < System_int64_string8base10Length_DEFAULT - 2; ++i) {
        *(string - i) = '0' + *(decimal_string - i);
    }
    string = array;
    System_boolean isNegative = that < 0;
    if (isNegative) *(string) = '-';
    else *(string) = ' ';
    for (System_size l = 0; l < System_int64_string8base10Length_DEFAULT - 3; ++l) {
        if (*(string + l) != '0') break;
        *(string + l) = ' ';
    }
}
#endif
