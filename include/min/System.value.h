/* Gemeinfrei. Public Domain. */
#if !defined(have_System_value)
#define have_System_value

/* union_System_value: use System_value and choose any of them! */

#define union_System_value  union class_System_value
typedef union_System_value {
    void  * var;

    System_uint8  * u8;
    System_uint16  * u16;
    System_uint32  * u32;
    System_uint64  * u64;

    System_int8  * i8;
    System_int16  * i16;
    System_int32  * i32;
    System_int64  * i64;

    System_string8  string;
/*    char16_t  * string16; */
/*    char32_t  * string32; */

/*    wchar_t  * wideString; */
/*    wint_t  * wideInt; */
/*    wctype_t  * wideChar; */
/*    mbstate_t  * wideMultiByte; */

}  * System_value;

#if defined(using_System)
#define union_value  union_System_value
#define __value  System_value
#endif

#endif
