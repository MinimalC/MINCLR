/* Gemeinfrei. Public Domain. */
#if !defined(have_System)
#warning "System.h not included"
#include <min/System.h>
#endif
#if !defined(code_System_char8)
#define code_System_char8
/*# System_char8 #*/
System_boolean  System_char8_isNumber(System_char8 that) {
    return (that >= 0x30 && that <= 0x39);
}
System_boolean  System_char8_isUpper(System_char8 that) {
    return (that >= 0x41 && that <= 0x5A);
}
System_boolean  System_char8_isLower(System_char8 that) {
    return (that >= 0x61 && that <= 0x7A);
}
System_boolean  System_char8_isAlpha(System_char8 that) {
    return System_char8_isUpper(that) || System_char8_isLower(that);
}
System_boolean  System_char8_isAlphaNumeric(System_char8 that) {
    return System_char8_isAlpha(that) || System_char8_isNumber(that);
}
System_boolean  System_char8_isHexNumber(System_char8 that) {
    return (that >= 0x30 && that <= 0x39) || (that >= 0x41 && that <= 0x46) || (that >= 0x61 && that <= 0x66);
}
System_boolean  System_char8_isWhiteSpace(System_char8 that) {
    return that == 0x20 || that == 0x0c || that == 0x0a || that == 0x0d || that == 0x09 || that == 0x0b;
}
System_boolean  System_char8_isControl(System_char8 that) {
    return (that >= 0x00 && that <= 0x1F) || that == 0x7F;
}
System_boolean  System_char8_isPunctuation(System_char8 that) {
    return (that >= 0x21 && that <= 0x2F) || (that >= 0x3A && that <= 0x40) || (that >= 0x5B && that <= 0x60) || (that >= 0x7B && that <= 0x7E);
}
System_boolean  System_char8_isPrintable(System_char8 that) {
    return System_char8_isAlphaNumeric(that) || System_char8_isPunctuation(that);
}
#endif
