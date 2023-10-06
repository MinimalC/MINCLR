/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Char8)
#define have_System_Char8

export struct System_Type  System_Char8Type;

export System_Bool  System_Char8_isNumber(System_Char8 that);
export System_Bool  System_Char8_isUpper(System_Char8 that);
export System_Bool  System_Char8_isLower(System_Char8 that);
export System_Bool  System_Char8_isAlpha(System_Char8 that);
export System_Bool  System_Char8_isAlphaNumeric(System_Char8 that);
export System_Bool  System_Char8_isHexNumber(System_Char8 that);
export System_Bool  System_Char8_isWhiteSpace(System_Char8 that);
export System_Bool  System_Char8_isControl(System_Char8 that);
export System_Bool  System_Char8_isPunctuation(System_Char8 that);
export System_Bool  System_Char8_isPrintable(System_Char8 that);

#if defined(using_System)
#define Char8_isNumber  System_Char8_isNumber
#define Char8_isUpper  System_Char8_isUpper
#define Char8_isLower  System_Char8_isLower
#define Char8_isAlpha  System_Char8_isAlpha
#define Char8_isAlphaNumeric  System_Char8_isAlphaNumeric
#define Char8_isHexNumber  System_Char8_isHexNumber
#define Char8_isWhiteSpace  System_Char8_isWhiteSpace
#define Char8_isControl  System_Char8_isControl
#define Char8_isPunctuation  System_Char8_isPunctuation
#define Char8_isPrintable  System_Char8_isPrintable
#endif

#endif
#if !defined(have_System_String8)
#define have_System_String8

export struct System_Type  System_String8Type;

export System_Size  System_String8_indexOf__size(System_String8 that, System_Char8 character, System_Size length);
export System_Size  System_String8_indexOf(System_String8 that, System_Char8 character);
export System_Size  System_String8_lastIndexOf__size(System_String8 that, System_Char8 character, System_Size length);
export System_Size  System_String8_lastIndexOf(System_String8 that, System_Char8 character);
export System_Size  System_String8_get_Length(System_String8 that);
export System_Size  System_String8_get_Length__max(System_String8 that, System_Size limit);
export void  System_String8_copyTo(System_String8 src, System_String8 dest);
export void  System_String8_copyToAt(System_String8 src, System_String8 dest, System_Size at);
export void  System_String8_copySubstringTo(System_String8 src, System_Size count, System_String8 dest);
export void  System_String8_copySubstringToAt(System_String8 src, System_Size count, System_String8 dest, System_Size at);
export System_String8  System_String8_copy(System_String8 that);
export System_String8  System_String8_copyOf(System_String8 that, System_Size offset);
export System_String8  System_String8_copySubstring(System_String8 that, System_Size count);
export System_String8  System_String8_copyOfSubstring(System_String8 that, System_Size offset, System_Size count);
export System_String8  System_String8_concat(System_String8 that, System_String8 other);
export System_Size  System_String8_compare(System_String8 that, System_String8 other);
export System_Bool  System_String8_equals(System_String8 that, System_String8 other);
export System_Size  System_String8_compareSubstring(System_String8 that, System_String8 other, System_Size count);
export System_Bool  System_String8_equalsSubstring(System_String8 that, System_String8 other, System_Size count);
export System_Bool  System_String8_isNullOrEmpty(System_String8 that);
export System_Bool  System_String8_startsWith(System_String8 that, System_String8 other);
export System_Bool  System_String8_endsWith(System_String8 that, System_String8 other);

#define inline_System_String8_equals(chars0, chars1)  (0 == System_String8_compare(chars0, chars1))
#define inline_System_String8_equalsSubstring(chars0, chars1, n)  (0 == System_String8_compareSubstring(chars0, chars1, n))

#define System_String8_formatLimit_VALUE  System_UInt16_Max
#define System_String8_MaxLength_VALUE  System_UInt32_Max

export System_Size  stack_System_String8_format(System_String8 format, System_Char8 message[System_String8_formatLimit_VALUE], ...);
export System_Size  stack_System_String8_format__arguments(System_String8 format, System_Char8 message[System_String8_formatLimit_VALUE], System_Size argc, System_Var argv[]);
export System_Size  stack_System_String8_formatLine(System_String8 format, System_Char8 message[System_String8_formatLimit_VALUE], ...);
export System_Size  stack_System_String8_formatLine__arguments(System_String8 format, System_Char8 message[System_String8_formatLimit_VALUE], System_Size argc, System_Var argv[]);
export System_Size  stack_System_String8_formatEnd(System_String8 format, System_Char8 suffix, System_Char8 message[System_String8_formatLimit_VALUE], ...);
export System_Size  stack_System_String8_formatEnd__arguments(System_String8 format, System_Char8 suffix, System_Char8 message[System_String8_formatLimit_VALUE], System_Size argc, System_Var argv[]);
export System_Size  stack_System_String8_formatEnd__limit_arguments(System_String8 format, System_Char8 suffix, System_Size limit, System_Char8 message[], System_Size argc, System_Var argv[]);

#if defined(using_System)
#define String8_lastIndexOf  System_String8_lastIndexOf
#define String8_indexOf  System_String8_indexOf
#define String8_get_Length  System_String8_get_Length
#define String8_copyTo  System_String8_copyTo
#define String8_copyToAt  System_String8_copyToAt
#define String8_copySubstringTo  System_String8_copySubstringTo
#define String8_copySubstringToAt  System_String8_copySubstringToAt
#define String8_copy  System_String8_copy
#define String8_compare  System_String8_compare
#define String8_equals  System_String8_equals
#define String8_equalsSubstring  System_String8_equalsSubstring
#define String8_compareIgnoreCase  System_String8_compareIgnoreCase
#define String8_compareSubstring  System_String8_compareSubstring
#define String8_isNullOrEmpty  System_String8_isNullOrEmpty
#define String8_startsWith  System_String8_startsWith
#define String8_endsWith  System_String8_endsWith

#define String8_formatLimit_VALUE  System_String8_formatLimit_VALUE
#define String8_format  System_String8_format
#define String8_formatLine  System_String8_formatLine
#define String8_formatEnd  System_String8_formatEnd
#define String8_formatEnd__arguments  System_String8_formatEnd__arguments
#endif
#endif
