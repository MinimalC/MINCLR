/*  Gemeinfrei. Public Domain. */
#if !defined(have_System_stddef)
#define have_System_stddef

enum /* noname */ { System_null } ;

#define System_default(class)  ((class)System_null)

#if defined(using_System)
#define __null  System_null
#define __default(class)  ((class)__null)
#endif

/*#if defined(__builtin_alloca)
#define System_stackalloc  __builtin_alloca
#else
#warning System_stackalloc (__builtin_alloca) is undefined
#endif

#if defined(using_System)
#if defined(System_stackalloc)
#define __stackalloc  System_stackalloc
#endif
#endif*/


#if defined(have_ARM)
#define __breakpoint  __asm("bkpt");
#elif defined(have_AMD64) || defined(have_X86)
#define __breakpoint  __asm("int $3");
#else
#define __breakpoint
#warning __breakpoint: Architecture not supported
#endif


#if defined(__MSVCC) /*(?)*/
#define __public  extern __declspec(dllexport)
#define __import  extern __declspec(dllimport)
#define __export  extern __declspec(dllimport)
#define __align(x)  __declspec(align(x))
#define __artificial /* ? */
#define __asm /* ? */
/* #define __const  __declspec((const)) */
#define __deprecated(msg)  __declspec(deprecated(msg))
#define __used  /* ? */
#define __noreturn  __declspec(noreturn)
#define __nothrow  __declspec(nothrow)
/* #define __thread  __declspec(thread) */
#define __warning(text)  /* ? */

#else /* if __GNUCC */
#define __public  __attribute__((visibility("default")))
#define __import  extern
#define __export  extern
#define __align(x)  __attribute__((__aligned__(x)))
#define __artificial  __attribute__((__artificial__))
#define __asm(name)  __asm__(name)
/* #define __const  __attribute__ ((__const__)) */
#define __deprecated(msg)  __attribute__((__deprecated__(msg)))
#define __used  __attribute__((used))
#define __noreturn  __attribute__((__noreturn__))
#define __nothrow  __attribute__((__nothrow__))
/* #define __thread  _Thread_local */
#define __warning(text)  __attribute__((__warning__(text)))

#endif

/* #endif */

#if !defined(__noreturn)
#define __noreturn /* noreturn */
#endif

#if !defined(__export)
#define __export /* export */
#endif

#define __throws  /* throws */

#define __unsafe  /* unsafe */

#define __private  static

#if !defined(__thread)
#define __thread  /* thread */
#endif

#define __abstract  /* abstract */

#define __final  /* final */

#if defined(have_System_internal)
#define __fixed  /* noconst */
#else
#define __fixed  const
#endif

#define __unused(name)  (void)(name);

#define __enum(name)  __ff(enum,name)


/* concat: SystemObjekt */
#define __cc(a,b)    a##b
#define __ccc(a,b,c)    __cc(a##b,c)
#define __cccc(a,b,c,d)    __ccc(a##b,c,d)
/* namespace names: System.Objekt
#define __nn(a,b)    a##.##b
#define __nnn(a,b,c)    __nn(a##.##b,c)
#define __nnnn(a,b,c,d)    __nnn(a##.##b,c,d) */
/* function names: System_Objekt */
#define __ff(a,b)    a##_##b
#define __fff(a,b,c)    __ff(a##_##b,c)
#define __ffff(a,b,c,d)    __fff(a##_##b,c,d)


#define	System_enum_hasFlag(__ENUM,__FLAG)  (((__ENUM) & __FLAG) == __FLAG)

#if defined(using_System)
#define enum_hasFlag  System_enum_hasFlag
#endif


/* Example: typedef void __delegate(System_Object_init)(System_Object that);
   Use __function(System_Object_init) */
#define __delegate(__name)  (* __ff(function,__name) )
#define __function(__name)  __ff(function,__name)

/* Don't define __base(__name)  __ff(base,__name)
Do define base_MyProject_Product_init  base_MyProject_Product_init__02  instead. */

/* Example:  void System_Object_freeClass(System_Object __ref that); */
#define __ref  *

#define __array(__instance)  (* (__instance))
#define __array_item(___array, ___item)  *(__array(___array) + ___item)

/*
This is valid C. C++ throws a compiler exception, also within extern "C":
:    typedef struct System_Object  * System_Object;
:    __export struct System_Type  System_ObjectType;
:    struct System_Object { ... }

Actually, in your C .h you do:
:    #define struct_System_Object  struct class_System_Object
:    typedef struct_System_Object  * System_Object;
:    __export struct_System_Type  System_ObjectType;
:    struct_System_Object { ... }
and in your C .c you do:
:    struct_System_Type  System_ObjectType  = { ... }
*/

#define __struct(name)  struct __ff(struct,name)
#define __class(name)  struct __ff(class,name)
#define __union(name)  union __ff(union,name)
#define __interface(name)  struct __ff(interface,name)

#define __typedef_struct(name)  typedef __struct(name)  * (name);
#define __typedef_class(name)  typedef __class(name)  * (name);
#define __typedef_union(name)  typedef __union(name)  * (name);
#define __typedef_interface(name)  typedef __interface(name)  * (name);

#if defined(__builtin_offsetof)
#define __offsetof(__TYPE,__MEMBER)  __builtin_offsetof(__TYPE,__MEMBER)
#elif !defined(__offsetof)
#define __offsetof(__TYPE,__MEMBER)  ((System_size) &((__TYPE *)0)->__MEMBER)
#endif
#define __offsetof_class(__TYPE,__MEMBER)  ((System_size) &((__TYPE)0)->__MEMBER)

#define __instancein(__OBJECT,__MEMBER,__TYPE)  ((__TYPE *)__OBJECT->__MEMBER)

#define __sizeof_array(__OBJECT)  (sizeof(__OBJECT) / sizeof(__OBJECT[0]))

#define __nameof(class)  (#class)

/* TODO: #define __asm(name)  __asm__ ( __nameof(name) ) */

#define __valueof(__OBJECT)  (__OBJECT->value)

/* __typeof is &name##Type, __typeof_instance is System_Object_getType(System_Object that) */
#define __typeof(name)  (&name##Type)


#if defined(__cplusplus)
#warning "This doesn't work in C++. Use AWK and C !"
/* Because

1. C++Exceptions are using setjmp, to jump the stack. In META C Exceptions just return or return 0.

2. typedef struct Name Name; even in extern "C": C++ throws a compiler exception and doesn't allow me to do just
   typedef struct Name * Name;

*/
#define __extern_C  extern "C" {
#define __end_C  }
#else
#define __extern_C
#define __end_C
#endif

/* ISOC99 boolean */

#if defined(__cplusplus)
typedef bool  System_boolean;
#else
typedef _Bool  System_boolean;
#endif

enum /* noname */ { System_false, System_true } ;

#if defined(using_System)
/* now please ask */
/* #if defined(__bool) */
#define __bool  System_boolean

#define __false  System_false
#define __true  System_true
#endif


/* lowercased literals */
typedef void  System_void;
typedef void  * System_var; /* var is not unsafe */
typedef __SIZE_TYPE__  System_size;
typedef __SIZE_TYPE__  System_intptr;
typedef __PTRDIFF_TYPE__  System_ssize;
typedef __PTRDIFF_TYPE__  System_sintptr;

/* System_size_Max should be 0xFFFFFFFF on 32bit and 0xFFFFFFFFFFFFFFFF on 64bit  */
#define System_size_Max  __SIZE_MAX__

#if defined(using_System)
#define __void  System_void
#define __var  System_var
#define __size  System_size
#define __size_Max  System_size_Max
#define __intptr  System_intptr
#define __ssize  System_ssize
#define __sintptr  System_sintptr
#endif


typedef unsigned char  System_uint8;
#if defined(have_vscode)
#define System_uint8  unsigned char
#endif

typedef unsigned short  System_uint16;
typedef unsigned int  System_uint32;
#if defined(__LP64__)
typedef unsigned long int  System_uint64;
#else
typedef unsigned long long int  System_uint64;
#endif
typedef signed char  System_int8;
typedef signed short  System_int16;
typedef signed int  System_int32;
#if defined(__LP64__)
typedef signed long int  System_int64;
#else
typedef signed long long int  System_int64;
#endif

#define System_byte  System_uint8
#define System_ushort  System_uint16
#define System_uint  System_uint32
#define System_ulong  System_uint64

#define System_sbyte  System_int8
#define System_short  System_int16
#define System_int  System_int32
#define System_long  System_int64

#if defined(using_System)
#define __int8  System_int8
#define __int16  System_int16
#define __int32  System_int32
#define __int64  System_int64
#define __sbyte  System_sbyte
#define __short  System_short
#define __int  System_int
#define __long  System_long

#define __uint8  System_uint8
#define __uint16  System_uint16
#define __uint32  System_uint32
#define __uint64  System_uint64
#define __byte  System_byte
#define __ushort  System_ushort
#define __uint  System_uint
#define __ulong  System_ulong
#endif

/* static class System_string8 */

typedef char  System_char8,  * System_string8,  struct_System_string8[];

__export System_char8  System_string8_Empty[1];

#if defined(__CHAR16_TYPE__)
typedef __CHAR16_TYPE__  System_char16;
#endif

#if defined(__CHAR32_TYPE__)
typedef __CHAR32_TYPE__  System_char32;
#endif

#if defined(using_System)
#define struct_string8  struct_System_string8
#define __string8  System_string8
#define __string8_Empty  System_string8_Empty
#define __char8  System_char8
#define __char16  System_char16
#define __char32  System_char32
#endif


#if !defined(__UNICODE)
#define __UNICODE  8
#endif

/* #if __UNICODE == 32 */
/* #if __UNICODE == 16 */
#if __UNICODE == 8
#define System_char  System_char8
#define System_string  System_string8
#define literal_System_string  struct_System_string8
#define System_string_Empty  System_string8_Empty
#endif

#if defined(using_System)
#define __char  System_char
#define __string  System_string
#define struct_string  literal_System_string
#define __string_Empty  System_string_Empty
#endif

#endif
