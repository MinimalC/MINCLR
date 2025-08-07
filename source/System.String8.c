/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(have_System_String8Array)
#include <min/System.String8Array.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_Int64)
#include <min/System.Integers.auto.h>
#endif
#if !defined(have_Crypto_SipHash48)
#include <min/Crypto.SipHash48.h>
#endif
#if !defined(code_System_Char8)
#define code_System_Char8
/** class System_Char8  **/

struct System_Type System_Char8Type = { .base = { .type = typeof(System_Type) }, .name = "Char8", .size = 1 };

System_Bool  System_Char8_isNumber(System_Char8 that) {
    return (that >= 0x30 && that <= 0x39);
}
System_Bool  System_Char8_isUpper(System_Char8 that) {
    return (that >= 0x41 && that <= 0x5A);
}
System_Bool  System_Char8_isLower(System_Char8 that) {
    return (that >= 0x61 && that <= 0x7A);
}
System_Bool  System_Char8_isAlpha(System_Char8 that) {
    return System_Char8_isUpper(that) || System_Char8_isLower(that);
}
System_Bool  System_Char8_isAlphaNumeric(System_Char8 that) {
    return System_Char8_isAlpha(that) || System_Char8_isNumber(that);
}
System_Bool  System_Char8_isHexNumber(System_Char8 that) {
    return (that >= 0x30 && that <= 0x39) || (that >= 0x41 && that <= 0x46) || (that >= 0x61 && that <= 0x66);
}
System_Bool  System_Char8_isWhiteSpace(System_Char8 that) {
    return that == 0x20 || that == 0x09;
}
System_Bool  System_Char8_isControl(System_Char8 that) {
    return (that >= 0x00 && that <= 0x1F) || that == 0x7F;
}
System_Bool  System_Char8_isPunctuation(System_Char8 that) {
    return (that >= 0x21 && that <= 0x2F) || (that >= 0x3A && that <= 0x40) || (that >= 0x5B && that <= 0x60) || (that >= 0x7B && that <= 0x7E);
}
System_Bool  System_Char8_isPrintable(System_Char8 that) {
    return System_Char8_isWhiteSpace(that) || System_Char8_isAlphaNumeric(that) || System_Char8_isPunctuation(that);
}
#endif
#if !defined(code_System_String8)
#define code_System_String8

/** class System_String8 */

struct System_Type System_String8Type = { .base = { .type = typeof(System_Type) }, .name = "String8", .size = sizeof(System_Var) };

System_STRING8  System_String8_Empty = "";

String8  System_String8_exchange(String8 ref that, String8 other) {
    Console_assert(that);
    String8 old = *that;
    *that = other;
    if (old) Memory_free(old);
    return other;
}

UInt64 System_String8_getSipHash(String8 that) {
    struct Crypto_SipHash48 sipHash48; Stack_clear(sipHash48);
    Crypto_SipHash48_init(&sipHash48);
    Crypto_SipHash48_update(&sipHash48, that, String8_get_Length(that));
    return Crypto_SipHash48_final(&sipHash48);
}

SSize  System_String8_indexOf__size(String8 that, Char8 character, Size length) {
    SSize i = 0;
    if (length == 0) return -1;
    do {
        if (that[i] == character) return i;
    } while ( ++i < length );
    return -1;
}

SSize  System_String8_indexOf(String8 that, Char8 character){
    return System_String8_indexOf__size(that, character, String8_get_Length(that));
}

SSize  System_String8_lastIndexOf__size(String8 that, Char8 character, Size length) {
    SSize i = length;
    if (i == 0) return -1;
    do {
        if (that[--i] == character) return i;
    } while ( i );
    return -1;
}

SSize  System_String8_lastIndexOf(String8 that, Char8 character) {
    return System_String8_lastIndexOf__size(that, character, String8_get_Length(that));
}

Size  System_String8_get_Length(String8 that) {
    return System_String8_get_Length__max(that, System_String8_MaxLength_VALUE);
}

System_Size  System_String8_get_Length__max(System_String8 that, System_Size limit) {
    if (!that) return 0;
    Size i = 0;
    while (limit && that[i]) { --limit; ++i; }
#if DEBUG
    if (!limit) System_Console_writeLine__string("WARNING: System_String8_getLength exceeding String8_MaxLength");
#endif
    return i;
}

void  System_String8_copyTo(String8 src, String8 dest) {
    Size count = String8_get_Length(src);
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_String8_copyToAt(String8 src, String8 dest, Size at) {
    Size count = String8_get_Length(src);
    dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_String8_copySubstringTo(String8 src, Size count, String8 dest) {
    while ( count && ( *dest++ = *src++ ) ) --count;
}

void  System_String8_copySubstringToAt(String8 src, Size count, String8 dest, Size at) {
    dest += at;
    while ( count && ( *dest++ = *src++ ) ) --count;
}

String8  System_String8_copy(String8 that) {
    Size count = String8_get_Length(that);
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), count + 1);
    String8_copyTo(that, dest);
    return dest;
}

String8  System_String8_copyOf(String8 that, Size offset) {
    that += offset;
    Size count = String8_get_Length(that);
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), count + 1);
    String8_copyTo(that, dest);
    return dest;
}

String8  System_String8_copySubstring(String8 that, Size count) {
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), count + 1);
    String8_copySubstringTo(that, count, dest);
    return dest;
}

String8  System_String8_copyOfSubstring(String8 that, Size offset, Size count) {
    that += offset;
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), count + 1);
    String8_copySubstringTo(that, count, dest);
    return dest;
}

String8  System_String8_concat(String8 that, ...) {
    Arguments args;
    Arguments_start(args, that);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_String8_concat__arguments(that, argc, (System_String8 *)argv);
}

String8  System_String8_concat1(String8 that, String8 other) {
    Size length0 = System_String8_get_Length(that);
    Size length1 = System_String8_get_Length(other);
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), length0 + length1 + 1);
    String8_copyTo(that, dest);
    String8_copyToAt(other, dest, length0);
    return dest;
}

String8  System_String8_concat2(String8 that, String8 other0, String8 other1) {
    Size length0 = System_String8_get_Length(that);
    Size length1 = System_String8_get_Length(other0);
    Size length2 = System_String8_get_Length(other1);
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), length0 + length1 + length2 + 1);
    String8_copyTo(that, dest);
    String8_copyToAt(other0, dest, length0);
    String8_copyToAt(other1, dest, length0 + length1);
    return dest;
}

String8  System_String8_concat3(String8 that, String8 other0, String8 other1, String8 other2) {
    Size length0 = System_String8_get_Length(that);
    Size length1 = System_String8_get_Length(other0);
    Size length2 = System_String8_get_Length(other1);
    Size length3 = System_String8_get_Length(other2);
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), length0 + length1 + length2 + length3 + 1);
    String8_copyTo(that, dest);
    String8_copyToAt(other0, dest, length0);
    String8_copyToAt(other1, dest, length0 + length1);
    String8_copyToAt(other2, dest, length0 + length1 + length2);
    return dest;
}

String8  System_String8_concat4(String8 that, String8 other0, String8 other1, String8 other2, String8 other3) {
    Size length0 = System_String8_get_Length(that);
    Size length1 = System_String8_get_Length(other0);
    Size length2 = System_String8_get_Length(other1);
    Size length3 = System_String8_get_Length(other2);
    Size length4 = System_String8_get_Length(other3);
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), length0 + length1 + length2 + length3 + length4 + 1);
    String8_copyTo(that, dest);
    String8_copyToAt(other0, dest, length0);
    String8_copyToAt(other1, dest, length0 + length1);
    String8_copyToAt(other2, dest, length0 + length1 + length2);
    String8_copyToAt(other2, dest, length0 + length1 + length2 + length3);
    return dest;
}

String8  System_String8_concat__arguments(String8 that, Size argc, String8 argv[]) {
    Size sizes[System_Arguments_Limit + 2]; Stack_clear(sizes);
    Size length = sizes[0] = System_String8_get_Length(that);
    for (Size c = 0; c < argc; ++c)
        length += sizes[c + 1] = System_String8_get_Length(argv[c]);
    String8 dest = (String8)System_Memory_allocArray(typeof(System_Char8), length + 1);
    System_String8_copyTo(that, dest);
    Size position = sizes[0];
    for (Size c = 0; c < argc; ++c) {
        System_String8_copyTo(argv[c], dest + position);
        position += sizes[c + 1];
    }
    return dest;
}

Size  System_String8_compare(String8 that, String8 other) {
    Size count = 0;
    while ( ( *that ) && ( *that == *other ) ) {
        ++that; ++other; ++count;
    }
    return count;
}

Bool  System_String8_equals(String8 that, String8 other) {
    Size length0 = String8_get_Length(that);
    Size length1 = String8_get_Length(other);
    if (length0 != length1) return false;
    return length0 == String8_compare(that, other);
}

Size  System_String8_compareSubstring(String8 that, String8 other, Size length) {
    Size count = 0;
    while ( *that && length && ( *that == *other ) ) {
        ++that; ++other; --length; ++count;
    }
    return count;
}

Bool  System_String8_equalsSubstring(String8 that, String8 other, Size length) {
    return length == String8_compareSubstring(that, other, length);
}

Bool  System_String8_isNullOrEmpty(String8 that) {
    return !that || *that == '\0';
}

Bool  System_String8_startsWith(String8 that, String8 other) {
    Size length1 = String8_get_Length(other);
    return System_String8_equalsSubstring(that, other, length1);
}

Bool  System_String8_endsWith(String8 that, String8 other) {
    Size length1 = String8_get_Length(other);
    SSize diff = String8_get_Length(that) - length1;
    if (diff < 1) return false;
    return System_String8_equalsSubstring(that + diff, other, length1);
}

System_String8Array System_String8_split(System_String8 that, System_Char8 separator) {

    System_String8Array split = System_Memory_allocClass(typeof(System_String8Array));
    base_System_String8Array_init(split, 64);

    System_Size length = System_String8_get_Length(that);
    for (Size i = 0, start = 0; i < length; ++i) {
        if (i == length - 1)
            base_System_String8Array_add(split, System_String8_copyOfSubstring(that, start, 1 + i - start));
        else if (*(that + i) == separator) {
            base_System_String8Array_add(split, System_String8_copyOfSubstring(that, start, i - start));
            start = i + 1;
        }
    }
    return split;
}

System_String8  System_Char8_join(System_Char8 that, System_String8Array array) {
    Console_assert(array);
    if (!array->length) return String8_Empty;
    Size i = 0, length = 0, position = 0;
    Size arrayL = array->length - 1;
    String8 item = null;
    for (i = 0; i <= arrayL; ++i) {
        item = array(array->value)[i];
        if (item) length += String8_get_Length(item) + 1;
    }
    String8 string = System_Memory_allocArray(typeof(System_Char8), length + 1);
    for (i = 0; i < arrayL; ++i) {
        item = array(array->value)[i];
        if (item) {
            System_String8_copyToAt(item, string, position);
            position += String8_get_Length(item);
        }
        *(string + position++) = that;
    }
    item = array(array->value)[arrayL];
    if (item) {
        System_String8_copyToAt(item, string, position);
        /* position += String8_get_Length(item); */
    }
    return string;
}

String8  System_String8_format(String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_String8_format__arguments(format, argc, argv);
}

String8  System_String8_format__arguments(String8 format, Size argc, Var argv[]) {
    return System_String8_formatEnd__arguments(format, 0, argc, argv);
}

String8  System_String8_formatLine(String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_String8_formatLine__arguments(format, argc, argv);
}

String8  System_String8_formatLine__arguments(String8 format, Size argc, Var argv[]) {
    return System_String8_formatEnd__arguments(format, '\n', argc, argv);
}

String8  System_String8_formatEnd(String8 format, Char8 suffix, ...) {
    Arguments args;
    Arguments_start(args, suffix);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_String8_formatEnd__arguments(format, suffix, argc, argv);
}

String8  System_String8_formatEnd__arguments(String8 format, Char8 suffix, Size argc, Var argv[]) {
    Char8 message[System_String8_formatLimit_VALUE]; Stack_clear(message);
    Size length = stack_System_String8_formatEnd__limit_arguments(format, suffix, System_String8_formatLimit_VALUE, message, argc, argv);
    return System_String8_copy(message);
}

Size  stack_System_String8_format(String8 format, Char8 message[System_String8_formatLimit_VALUE], ...) {
    Arguments args;
    Arguments_start(args, message);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return stack_System_String8_formatEnd__arguments(format, 0, message, argc, argv);
}

Size  stack_System_String8_format__arguments(String8 format, Char8 message[System_String8_formatLimit_VALUE], Size argc, Var argv[]) {
    return stack_System_String8_formatEnd__arguments(format, 0, message, argc, argv);
}

Size  stack_System_String8_formatLine(String8 format, Char8 message[System_String8_formatLimit_VALUE], ...) {
    Arguments args;
    Arguments_start(args, message);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return stack_System_String8_formatEnd__arguments(format, '\n', message, argc, argv);
}

Size  stack_System_String8_formatLine__arguments(String8 format, Char8 message[System_String8_formatLimit_VALUE], Size argc, Var argv[]) {
    return stack_System_String8_formatEnd__arguments(format, '\n', message, argc, argv);
}

Size  stack_System_String8_formatEnd(String8 format, Char8 suffix, Char8 message[System_String8_formatLimit_VALUE], ...) {
    Arguments args;
    Arguments_start(args, message);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return stack_System_String8_formatEnd__arguments(format, suffix, message, argc, argv);
}

Size  stack_System_String8_formatEnd__arguments(String8 format, Char8 suffix, Char8 message[System_String8_formatLimit_VALUE], Size argc, Var argv[]) {
    return stack_System_String8_formatEnd__limit_arguments(format, suffix, System_String8_formatLimit_VALUE, message, argc, argv);
}

Size  stack_System_String8_formatEnd__limit_arguments(String8 format, Char8 suffix, Size limit, Char8 message[], Size argc, Var argv[]) {
    Console_assert(!argc || argv);

#if DEBUG
    STRING8 WARNING = "WARNING  ";
#endif

    Char8  scratch[72]; Stack_clear(scratch);

    // just don't write everything else

    Size format_length = String8_get_Length(format);
    if (format_length > limit - 5) { 
        format_length = limit - 5;
#if DEBUG
        WARNING[7] = '1';
        System_Console_write__string(WARNING);
#endif
    }

    String8 f = format;
    String8 m = message;
    Size message_length = 0, argi, argsize, target, numbers;
    while (1) {
        if (format_length == 0) break;

        String8_copySubstringToAt(format, format_length, message, message_length);
        if (format_length <= 4) {
            message_length += format_length;
            break;
        }

        /* Read { to } */
        String8 begin0 = 0, end0 = 0;
        for (; f < (format + format_length); ++f) {
            if (*f != '{') continue;
            if (f > format && *(f - 1) == '\\') continue;
            begin0 = f;
            for (; f < (format + format_length); ++f) {
                if (*f != '}') continue;
                end0 = f;
                break;
            }
            break;
        }
        if (!begin0) {
            message_length += format_length;
            break;
        }
        if (!end0) {
#if DEBUG == DEBUG_System_String8_format
            WARNING[7] = '2';
            System_Console_write__string(WARNING);
#endif
        }
        message_length += (begin0 - format);

        argi = System_UInt16_parsebase10(begin0 + 1);

        /* DEBUG
        stack_System_UInt16_toString8base10(argi, scratch);
        String8_copyToAt(scratch, message, message_length);
        message_length += System_UInt16_String8base10Length_DEFAULT; */

        if (argi >= argc) {
#if DEBUG == DEBUG_System_String8_format
            WARNING[7] = '3';
            System_Console_write__string(WARNING);
#endif
        }
        else {
            /* Read :obj :str :bool :char :int :uint :decimal :float :double */
            /* Also read 8, 16, 24, 32, 48, 64 */
            String8 begin1 = 0, begin2 = 0, end1 = 0, end2 = 0; argsize = 0;
            for (f = begin0 + 2; f < (format + format_length); ++f) {
                if (*f != ':') continue;
                for (begin1 = ++f; f < (format + format_length); ++f) {
                    if (!Char8_isAlpha(*f)) break;
                    end1 = f;
                }
                if (!end1) { begin1 = 0; break; }
                for (begin2 = f; f < (format + format_length); ++f) {
                    if (!Char8_isNumber(*f)) break;
                    end2 = f;
                }
                if (!end2) begin2 = 0;
                break;
            }
            /* Read :bin :oct :dec :hex */
            String8 begin3 = 0, end3 = 0; target = 10;
            if (!end2 && end1) end2 = end1;
            if (end2) {
                for (f = end2 + 1; f < (format + format_length); ++f) {
                    if (*f != ':') continue;
                    for (begin3 = ++f; f < (format + format_length); ++f) {
                        if (!Char8_isAlpha(*f)) break;
                        end3 = f;
                    }
                    if (!end3) begin3 = 0;
                    break;
                }
                if (begin3) {
                    if (String8_compareSubstring(begin3, "binary", sizeof("binary") - 1) >= 3) {
                        target = 2;
                        /* DEBUG
                        String8_copyToAt(":binary", message, message_length);
                        message_length += sizeof(":binary") - 1; */
                    }
                    else if (String8_compareSubstring(begin3, "octal", sizeof("octal") - 1) >= 3) {
                        target = 8;
                        /* DEBUG
                        String8_copyToAt(":octal", message, message_length);
                        message_length += sizeof(":octal") - 1; */
                    }
                    else if (String8_compareSubstring(begin3, "decimal", sizeof("decimal") - 1) >= 3) {
                        target = 10;
                        /* DEBUG
                        String8_copyToAt(":decimal", message, message_length);
                        message_length += sizeof(":decimal") - 1; */
                    }
                    else if (String8_compareSubstring(begin3, "hexadecimal", sizeof("hexadecimal") - 1) >= 3) {
                        target = 16;
                        /* DEBUG
                        String8_copyToAt(":hexadecimal", message, message_length);
                        message_length += sizeof(":hexadecimal") - 1; */
                    }
                }
            }
            if (!begin1) {
#if DEBUG == DEBUG_System_String8_format
                WARNING[7] = '4';
                System_Console_write__string(WARNING);
#endif
            }
            else {
                if (begin2) {
                    argsize = System_UInt16_parsebase10(begin2);

                    /* DEBUG: Write argsize
                    stack_System_UInt16_toString8base10(argsize, scratch);
                    String8_copyToAt(scratch, message, message_length);
                    message_length += System_UInt16_String8base10Length_DEFAULT; */
                }

                if (String8_compareSubstring(begin1, "object", sizeof("object") - 1) >= 3) {
                    /* DEBUG */
                    String8_copyToAt("object", message, message_length);
                    message_length += sizeof("object") - 1;
                }
                else if (String8_compareSubstring(begin1, "character", sizeof("character") - 1) >= 4) {
                    /* DEBUG */
                    String8_copyToAt("character", message, message_length);
                    message_length += sizeof("character") - 1;
                }
                else if (String8_compareSubstring(begin1, "string", sizeof("string") - 1) >= 3) {
                    if (!argv[argi]) {
                        String8_copyToAt("{null}", message, message_length);
                        message_length += sizeof("{null}") - 1;
                    }
                    else {
                        System_Size string_length = String8_get_Length((String8)argv[argi]);
                        if (string_length > limit - 5) { 
                            string_length = limit - 5;
#if DEBUG
                            WARNING[7] = '5';
                            System_Console_write__string(WARNING);
#endif
                            string_length = limit - message_length - 5;
                            String8_copySubstringToAt((String8)argv[argi], string_length, message, message_length);
                            message_length += string_length;
                        }
                        else {
                            String8_copyToAt((String8)argv[argi], message, message_length);
                            message_length += string_length;
                        }
                    }
                }
                else if (String8_compareSubstring(begin1, "decimal", sizeof("decimal") - 1) >= 3) {
                    /* DEBUG */
                    String8_copyToAt("decimal", message, message_length);
                    message_length += sizeof("decimal") - 1;
                }
                else if (String8_compareSubstring(begin1, "boolean", sizeof("boolean") - 1) >= 4) {

                    if (argv[argi]) {
                        String8_copyToAt("true", message, message_length);
                        message_length += sizeof("true") - 1;
                    }
                    else {
                        String8_copyToAt("false", message, message_length);
                        message_length += sizeof("false") - 1;
                    }
                }
                else if (String8_compareSubstring(begin1, "integer", sizeof("integer") - 1) >= 3) {

                    if (!argsize) argsize = System_Size_Bits;
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
#if DEBUG == DEBUG_System_String8_format
                        WARNING[7] = '6';
                        System_Console_write__string(WARNING);
#endif
                        argsize = System_Size_Bits;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = stack_System_Int64_toString8base16((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_Int64_toString8base10((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_Int64_toString8base8((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_Int64_toString8base2((Int64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = stack_System_Int32_toString8base16((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_Int32_toString8base10((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_Int32_toString8base8((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_Int32_toString8base2((Int32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = stack_System_Int16_toString8base16((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_Int16_toString8base10((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_Int16_toString8base8((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_Int16_toString8base2((Int16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = stack_System_Int8_toString8base16((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_Int8_toString8base10((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_Int8_toString8base8((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_Int8_toString8base2((Int8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else if (String8_compareSubstring(begin1, "uinteger", sizeof("uinteger") - 1) >= 4
                      || String8_equalsSubstring(begin1, "unsigned", sizeof("unsigned") - 1))
                {
                    if (!argsize) argsize = System_Size_Bits;
                    else if (argsize != 8 && argsize != 16 && argsize != 32 && argsize != 64) {
#if DEBUG == DEBUG_System_String8_format
                        WARNING[7] = '7';
                        System_Console_write__string(WARNING);
#endif
                        argsize = System_Size_Bits;
                    }
                    if (argsize == 64) {
                        if (target == 16) {
                            numbers = stack_System_UInt64_toString8base16((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_UInt64_toString8base10((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_UInt64_toString8base8((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_UInt64_toString8base2((UInt64)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 32) {
                        if (target == 16) {
                            numbers = stack_System_UInt32_toString8base16((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_UInt32_toString8base10((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_UInt32_toString8base8((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_UInt32_toString8base2((UInt32)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 16) {
                        if (target == 16) {
                            numbers = stack_System_UInt16_toString8base16((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_UInt16_toString8base10((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_UInt16_toString8base8((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_UInt16_toString8base2((UInt16)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                    else if (argsize == 8) {
                        if (target == 16) {
                            numbers = stack_System_UInt8_toString8base16((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 10) {
                            numbers = stack_System_UInt8_toString8base10((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 8) {
                            numbers = stack_System_UInt8_toString8base8((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                        else if (target == 2) {
                            numbers = stack_System_UInt8_toString8base2((UInt8)(Size)argv[argi], scratch);
                            String8_copyToAt(scratch, message, message_length);
                            message_length += numbers;
                        }
                    }
                }
                else {
#if DEBUG == DEBUG_System_String8_format
                    WARNING[7] = '8';
                    System_Console_write__string(WARNING);
#endif
                }

            }
        }

        if (end0) {
            format_length -= (end0 - format) + 1;
            f = format = end0 + 1;
            continue;
        }

        break;
    }

    if (suffix) message[message_length++] = suffix;

    message[message_length] = '\0';

    return message_length;
}

#endif
