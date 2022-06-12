/*  Gemeinfrei. Public Domain. */

#if !defined(have_System_limits)
#define have_System_limits

#define System_int8_Min  (-0x80)
#define System_int16_Min  (-0x8000)
#define System_int32_Min  (-0x80000000L)
/* # define System_int64_Min  (-__INT64_C(9223372036854775807)-1) */
#define System_int8_Max  (0x7F)
#define System_int16_Max  (0x7FFF)
#define System_int32_Max  (0x7FFFFFFFL)
/* # define System_unt64_Max  (__INT64_C(9223372036854775807)) */
#define System_uint8_Max  (0xFF)
#define System_uint16_Max  (0xFFFF)
#define System_uint32_Max  (0xFFFFFFFFU)
/* # define System_uint64_max  (__UINT64_C(18446744073709551615)) */

#if defined(using_System)
#define __int8_Min  System_int8_Min
#define __int16_Min  System_int16_Min
#define __int32_Min  System_int32_Min
#define __int64_Min  System_int64_Min
#define __int8_Max  System_int8_Max
#define __int16_Max  System_int16_Max
#define __int32_Max  System_int32_Max
#define __int64_Max  System_int64_Max
#define __uint8_Max  System_uint8_Max
#define __uint16_Max  System_uint16_Max
#define __uint32_Max  System_uint32_Max
#define __uint64_Max  System_uint64_Max
#endif


#endif