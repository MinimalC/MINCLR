/*  Gemeinfrei. Public Domain. */
#if !defined(have_System_asm)
#include "System.asm.h"
#endif
#if !defined(have_System_stddef)
#define have_System_stddef

#if defined(__ASSEMBLER__)
#error "Use include System.asm.h instead."
#endif

enum /* noname */ { System_null } ;

#define System_default(class)  ((class)System_null)

#if defined(using_System)
#define null  System_null
#define default(class)  ((class)null)
#endif

/* ISO C boolean */

#if defined(__cplusplus)
typedef bool  System_boolean;
#else
typedef _Bool  System_boolean;
#endif

enum /* noname */ { System_false, System_true } ;

#if defined(using_System)
/* please don't use #if defined(bool) */
#define bool  System_boolean

#define false  System_false
#define true  System_true
#endif


/*#if defined(__builtin_alloca)
#define System_stackalloc  __builtin_alloca
#else
#warning System_stackalloc (__builtin_alloca) is undefined
#endif

#if defined(using_System)
#if defined(System_stackalloc)
#define stackalloc  System_stackalloc
#endif
#endif*/


#if defined(MSVCC)
#define import  extern __declspec(dllimport)
#if defined(have_System_internal)
#define export  __declspec(dllexport)
#else
#define export  import
#endif
#define align(x)  __declspec(align(x))
#define artificial /* artificial */
#define asm /* asm */
/* #define const  __declspec((const)) */
#define deprecated(msg)  __declspec(deprecated(msg))
#define used  /* used */
#define noreturn  __declspec(noreturn)
#define nothrow  __declspec(nothrow)
/* #define thread  __declspec(thread) */

#else /* if GNUCC */
#define import  extern
#if defined(have_System_internal)
#define export  __attribute__((visibility("default")))
#else
#define export  import
#endif
#define align(x)  __attribute__((__aligned__(x)))
#define artificial  __attribute__((__artificial__))
#define asm  __asm__
/* #define const  __attribute__ ((__const__)) */
#define deprecated(msg)  __attribute__((__deprecated__(msg)))
#define used  __attribute__((used))
#define noreturn  __attribute__((__noreturn__))
#define nothrow  __attribute__((__nothrow__))
/* #define thread  _Thread_local */
#endif


#if !defined(noreturn)
#define noreturn /* noreturn */
#endif

#define throws  /* throws */

#define unsafe  /* unsafe */

#define internal  static

#if !defined(thread)
#define thread  /* thread */
#endif

#define abstract  /* abstract */

#define final  /* final */

#if defined(have_System_internal)
#define fixed  /* noconst */
#else
#define fixed  const
#endif

#define unused(name)  (void)(name);


#if defined(have_ARM)
#define breakpoint  asm("bkpt");
#elif defined(have_AMD64) || defined(have_X86)
#define breakpoint  asm("int $3");
#else
#define breakpoint
#warning breakpoint: Architecture not supported
#endif


/* concat: SystemObjekt */
#define cc(a,b)    a##b
#define ccc(a,b,c)    cc(a##b,c)
#define cccc(a,b,c,d)    ccc(a##b,c,d)
/* namespace names: System.Objekt
#define nn(a,b)    a##.##b
#define nnn(a,b,c)    nn(a##.##b,c)
#define nnnn(a,b,c,d)    nnn(a##.##b,c,d) */
/* function names: System_Objekt */
#define ff(a,b)    a##_##b
#define fff(a,b,c)    ff(a##_##b,c)
#define ffff(a,b,c,d)    fff(a##_##b,c,d)


#define	System_enum_hasFlag(ENUM,FLAG)  (((ENUM) & FLAG) == FLAG)

#if defined(using_System)
#define enum_hasFlag  System_enum_hasFlag
#endif


/* Example: typedef void delegate(System_Object_init)(System_Object that);
   Use function(System_Object_init), write base(System_Object_init) */
#define delegate(name)  (* ff(function,name) )
#define function(name)  ff(function,name)
#define base(name)  ff(base,name)

/* Don't define base(name)  ff(base,name)
Do define base_MyProject_Product_init  base_MyProject_Product_init__02  instead. */

/* Example:  void System_Memory_freeClass(System_Object ref that); */
#define ref  *
#define out  *

#define array(instance)  (* (instance))
#define array_item(instance, item)  *(array(instance) + item)

/*
This is valid C, but C++ throws a compiler exception, also within extern "C":
:    typedef struct System_Object  * System_Object;
:    export struct System_Type  System_ObjectType;
:    struct System_Object { ... }

Actually, in your C .h you'd have to do:
:
:    typedef struct System_Object  * System_Object;
:    export struct System_Type  System_ObjectType;
:    struct System_Object { ... }
and in your C .c you do:
:    struct System_Type  System_ObjectType  = { ... }
*/

#if defined(__builtin_offsetof)
#define offsetof(TYPE,MEMBER)  __builtin_offsetof(TYPE,MEMBER)
#else
#define offsetof(TYPE,MEMBER)  ((System_size) &((TYPE *)0)->MEMBER)
#endif
#define offsetof_class(TYPE,MEMBER)  ((System_size) &((TYPE)0)->MEMBER)

#define instancein(OBJECT,MEMBER,TYPE)  ((TYPE *)OBJECT->MEMBER)

#define sizeof_array(OBJECT)  (sizeof(OBJECT) / sizeof(OBJECT[0]))

#define sizeof_class(CLASS) sizeof(struct ##CLASS)

#define nameof(TYPE)  (#TYPE)

#define typeof(name)  (&name##Type)


typedef void  System_void;
typedef void  * System_var; /* var is not unsafe in C */
typedef unsigned  System_unsigned;
typedef signed  System_signed;
typedef __SIZE_TYPE__  System_size;
typedef __SIZE_TYPE__  System_intptr;
typedef __PTRDIFF_TYPE__  System_ssize;
typedef __PTRDIFF_TYPE__  System_sintptr;

#define System_size_Max  __SIZE_MAX__
#if !defined(System_size_Width)
#define System_size_Width  __SIZE_WIDTH__
#endif
#if !defined(System_size_Bytes)
#define System_size_Bytes  __SIZEOF_POINTER__
#endif

#if defined(using_System)
#define var  System_var
#define size  System_size
#define size_Max  System_size_Max
#define size_Width  System_size_Width
#define intptr  System_intptr
#define ssize  System_ssize
#define sintptr  System_sintptr
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

#if defined(using_System)
#define uint8  System_uint8
#define uint16  System_uint16
#define uint32  System_uint32
#define uint64  System_uint64

#define int8  System_int8
#define int16  System_int16
#define int32  System_int32
#define int64  System_int64
#endif


#define System_byte  System_uint8
#define System_ushort  System_uint16
#define System_uint  System_uint32
#define System_ulong  System_uint64

#define System_sbyte  System_int8
#define System_short  System_int16
#define System_int  System_int32
#define System_long  System_int64

/* Look, this doesn't rewrite keyword type names in C. */
#if defined(using_System)
#define byte  System_byte
#define ushort  System_ushort
#define uint  System_uint
#define ulong  System_ulong

#define sbyte  System_sbyte
#define sshort  System_short
#define iint  System_int
#define llong  System_long
#endif


typedef char  System_char8,  * System_string8,  System_STRING8[];

export System_char8  System_string8_Empty[1];

#if defined(using_System)
#define char8  System_char8
#define string8  System_string8
#define STRING8  System_STRING8
#define string8_Empty  System_string8_Empty
#endif


export void  System_Console_assert__string8(const System_string8 expression, const System_string8 functionName, const System_string8 file, const System_uint32 line);
export void  System_Console_debug__format(const System_string8 expression, const System_string8 message, const System_string8 functionName, const System_string8 file, const System_uint32 line);

#if !DEBUG
#define System_Console_assert(expression) (void)(expression)
#define System_Console_debug(expression,message) (void)(expression);(void)(message)
#else
#define System_Console_assert(expression)  if (!(expression)) { System_Console_assert__string8((System_string8)(#expression), (System_string8)__func__, (System_string8)__FILE__, (System_uint32)__LINE__); }
#define System_Console_debug(expression,message)  { System_Console_debug__format((System_string8)(#expression), (System_string8)(message), (System_string8)__func__, (System_string8)__FILE__, (System_uint32)__LINE__); }
#endif

#if defined(using_System)
#define Console_assert  System_Console_assert
#define Console_debug  System_Console_debug
#endif
#endif
