#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_IStream)
#include "System.IStream.h"
#endif
#if !defined(have_System_char8)
#define have_System_char8

export struct System_Type  System_char8Type;

export System_boolean  System_char8_isNumber(System_char8 that);
export System_boolean  System_char8_isUpper(System_char8 that);
export System_boolean  System_char8_isLower(System_char8 that);
export System_boolean  System_char8_isAlpha(System_char8 that);
export System_boolean  System_char8_isAlphaNumeric(System_char8 that);
export System_boolean  System_char8_isHexNumber(System_char8 that);
export System_boolean  System_char8_isWhiteSpace(System_char8 that);
export System_boolean  System_char8_isControl(System_char8 that);
export System_boolean  System_char8_isPunctuation(System_char8 that);
export System_boolean  System_char8_isPrintable(System_char8 that);

#if defined(using_System)
#define char8_isNumber  System_char8_isNumber
#define char8_isUpper  System_char8_isUpper
#define char8_isLower  System_char8_isLower
#define char8_isAlpha  System_char8_isAlpha
#define char8_isAlphaNumeric  System_char8_isAlphaNumeric
#define char8_isHexNumber  System_char8_isHexNumber
#define char8_isWhiteSpace  System_char8_isWhiteSpace
#define char8_isControl  System_char8_isControl
#define char8_isPunctuation  System_char8_isPunctuation
#define char8_isPrintable  System_char8_isPrintable
#endif

#endif
#if !defined(have_System_string8)
#define have_System_string8

export struct System_Type  System_string8Type;

export System_size  System_string8_indexOf(System_string8 that, System_uint8 character);
export System_size  System_string8_lastIndexOf(System_string8 that, System_uint8 character);
export System_size  System_string8_get_Length(System_string8 that);
export void  System_string8_copyTo(System_string8 src, System_string8 dest);
export void  System_string8_copyToAt(System_string8 src, System_string8 dest, System_size at);
export void  System_string8_copySubstringTo(System_string8 src, System_size count, System_string8 dest);
export void  System_string8_copySubstringToAt(System_string8 src, System_size count, System_string8 dest, System_size at);
export System_string8  System_string8_clone(System_string8 that);
export System_size  System_string8_compare(System_string8 that, System_string8 other);
export System_boolean  System_string8_equals(System_string8 that, System_string8 other);
export System_size  System_string8_compareSubstring(System_string8 that, System_string8 other, System_size count);
export System_boolean  System_string8_equalsSubstring(System_string8 that, System_string8 other, System_size count);
export System_boolean  System_string8_isNullOrEmpty(System_string8 that);
//export System_boolean  System_string8_startsWith(System_string8 that, String_string8 other);
export void  System_string8_formatTo(System_string8 that, System_IStream stream, ...);
export void  System_string8_formatLineTo(System_string8 that, System_IStream stream, ...);
export void  System_string8_formatEndTo(System_string8 that, System_char8 suffix, System_IStream stream, ...);
export void  System_string8_formatEndTo__arguments(System_string8 that, System_char8 suffix, System_IStream stream, System_arguments args);

#define inline_System_string8_equals(chars0, chars1)  (0 == System_string8_compare(chars0, chars1))
#define inline_System_string8_equalsSubstring(chars0, chars1, n)  (0 == System_string8_compareSubstring(chars0, chars1, n))

#if defined(using_System)
#define string8_lastIndexOf  System_string8_lastIndexOf
#define string8_indexOf  System_string8_indexOf
#define string8_get_Length  System_string8_get_Length
#define string8_copyTo  System_string8_copyTo
#define string8_copyToAt  System_string8_copyToAt
#define string8_copySubstringTo  System_string8_copySubstringTo
#define string8_copySubstringToAt  System_string8_copySubstringToAt
#define string8_clone  System_string8_clone
#define string8_compare  System_string8_compare
#define string8_equals  System_string8_equals
#define string8_equalsSubstring  System_string8_equalsSubstring
#define string8_compareIgnoreCase  System_string8_compareIgnoreCase
#define string8_compareSubstring  System_string8_compareSubstring
#define string8_isNullOrEmpty  System_string8_isNullOrEmpty
#define string8_formatTo  System_string8_formatTo
#define string8_formatLineTo  System_string8_formatLineTo
#define string8_formatEndTo  System_string8_formatEndTo
#define string8_formatEndTo__arguments  System_string8_formatEndTo__arguments
#endif
#endif
