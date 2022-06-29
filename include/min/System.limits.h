/*  Gemeinfrei. Public Domain. */

#if !defined(have_System_limits)
#define have_System_limits

#define System_int8_Min  (-0x80)
#define System_int16_Min  (-0x8000)
#define System_int32_Min  (-0x80000000L)
/* # define System_int64_Min  (-9223372036854775807LL-1) */
#define System_int8_Max  (0x7F)
#define System_int16_Max  (0x7FFF)
#define System_int32_Max  (0x7FFFFFFFL)
/* # define System_int64_Max  (9223372036854775807LL) */
#define System_uint8_Max  (0xFF)
#define System_uint16_Max  (0xFFFF)
#define System_uint32_Max  (0xFFFFFFFFU)
/* # define System_uint64_Max  (18446744073709551615ULL) */

#if defined(using_System)
#define int8_Min  System_int8_Min
#define int16_Min  System_int16_Min
#define int32_Min  System_int32_Min
#define int64_Min  System_int64_Min
#define int8_Max  System_int8_Max
#define int16_Max  System_int16_Max
#define int32_Max  System_int32_Max
#define int64_Max  System_int64_Max
#define uint8_Max  System_uint8_Max
#define uint16_Max  System_uint16_Max
#define uint32_Max  System_uint32_Max
#define uint64_Max  System_uint64_Max
#endif


#endif