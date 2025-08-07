/*  Gemeinfrei. Public Domain. */

#if !defined(have_System_limits)
#define have_System_limits

/*  on AMD64
    System_Size_Max is 0xFFFFFFFFFFFFFFFFULL
    System_Size_Bits is 64
    System_Size_Bytes is 8
*/
#define System_Size_Max  __SIZE_MAX__
#define System_Size_Bits  __SIZE_WIDTH__
#define System_Size_Bytes  __SIZEOF_POINTER__
#define System_SSize_Max  __PTRDIFF_MAX__
#define System_SSize_Bits  __PTRDIFF_WIDTH__
#define System_SSize_Bytes  __SIZEOF_PTRDIFF_T__

#define System_Int8_Min  -0x80
#define System_Int16_Min  -0x8000
#define System_Int32_Min  -0x80000000L
#define System_Int64_Min  -0x8000000000000000LL
#define System_Int8_Max  0x7F
#define System_Int16_Max  0x7FFF
#define System_Int32_Max  0x7FFFFFFFL
#define System_Int64_Max  0x7FFFFFFFFFFFFFFFLL
#define System_UInt8_Max  0xFF
#define System_UInt16_Max  0xFFFF
#define System_UInt32_Max  0xFFFFFFFFU
#define System_UInt64_Max  0xFFFFFFFFFFFFFFFFULL

#if defined(using_System)
#define Size_Max  System_Size_Max
#define Size_Bits  System_Size_Bits
#define Size_Bytes  System_Size_Bytes
#define Int8_Min  System_Int8_Min
#define Int16_Min  System_Int16_Min
#define Int32_Min  System_Int32_Min
#define Int64_Min  System_Int64_Min
#define Int8_Max  System_Int8_Max
#define Int16_Max  System_Int16_Max
#define Int32_Max  System_Int32_Max
#define Int64_Max  System_Int64_Max
#define UInt8_Max  System_UInt8_Max
#define UInt16_Max  System_UInt16_Max
#define UInt32_Max  System_UInt32_Max
#define UInt64_Max  System_UInt64_Max
#endif
#endif