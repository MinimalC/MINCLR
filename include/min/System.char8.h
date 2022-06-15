/* Gemeinfrei. Public Domain. */
#if !defined(have_System_stddef)
#warning "System.stddef.h not included"
#include "System.stddef.h"
#endif
#if !defined(have_System_char8)
#define have_System_char8

__export System_boolean  System_char8_isNumber(System_char8 that);
__export System_boolean  System_char8_isUpper(System_char8 that);
__export System_boolean  System_char8_isLower(System_char8 that);
__export System_boolean  System_char8_isAlpha(System_char8 that);
__export System_boolean  System_char8_isAlphaNumeric(System_char8 that);
__export System_boolean  System_char8_isHexNumber(System_char8 that);
__export System_boolean  System_char8_isWhiteSpace(System_char8 that);
__export System_boolean  System_char8_isControl(System_char8 that);
__export System_boolean  System_char8_isPunctuation(System_char8 that);
__export System_boolean  System_char8_isPrintable(System_char8 that);

#if defined(using_System)
#define __char8_isNumber  System_char8_isNumber
#define __char8_isUpper  System_char8_isUpper
#define __char8_isLower  System_char8_isLower
#define __char8_isAlpha  System_char8_isAlpha
#define __char8_isAlphaNumeric  System_char8_isAlphaNumeric
#define __char8_isHexNumber  System_char8_isHexNumber
#define __char8_isWhiteSpace  System_char8_isWhiteSpace
#define __char8_isControl  System_char8_isControl
#define __char8_isPunctuation  System_char8_isPunctuation
#define __char8_isPrintable  System_char8_isPrintable
#endif

#endif
