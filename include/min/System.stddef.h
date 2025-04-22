/*  Gemeinfrei. Public Domain. */
#if defined(__ASSEMBLER__)
#error "Use include System.asm.h instead."
#endif
#if !defined(have_System_asm)
#include "System.asm.h"
#endif
#if !defined(have_System_stddef)
#define have_System_stddef

/* This is the truth made by God, like the DNA of a Great Stinging Nettle */

enum { null } ;

enum { false, true } ;

typedef _Bool  System_Bool;

#if defined(using_System)
#define Bool  System_Bool
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
#define align(x)  __declspec(align(x))
#define artificial /* artificial */
#define asm /* asm */
#define deprecated(msg)  __declspec(deprecated(msg))
#define used  /* used */
#define noreturn  __declspec(noreturn)
#define nothrow  __declspec(nothrow)
#define weak  __declspec(weak)
#define thread  __declspec(thread)
#define atomic  /* _Atomic */

#else /* if GNUCC */
#define import  extern
#define align(x)  __attribute__((aligned(x)))
#define artificial  __attribute__((artificial))
#define asm  __asm__
#define deprecated(msg)  __attribute__((deprecated(msg)))
#define used  __attribute__((used))
#define noreturn  __attribute__((noreturn))
#define nothrow  __attribute__((nothrow))
#define weak  __attribute__((weak))
#define thread  _Thread_local
#define volatile  __volatile__
#define atomic  _Atomic
#endif

#if !defined(export)
#define export  import
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

#if defined(System_internal)
#define System_fixed  /* noconst */
#else
#define System_fixed  const
#endif

#define unused(names)  (void)(names)

#if defined(have_ARM)
#define breakpoint  asm("bkpt")
#elif defined(have_AMD64) || defined(have_X86)
#define breakpoint  asm("int $3")
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

#define delegate(name)  (* ff(function,name) )
#define function(name)  ff(function,name)
#define base(name)  ff(base,name)

#define ref  *
#define out  *

#define array(instance)  (* (instance))
#define array_item(instance, item)  ( *(array(instance) + item) )

#if defined(__builtin_offsetof)
#define offsetof(TYPE,MEMBER)  __builtin_offsetof(TYPE,MEMBER)
#else
#define offsetof(TYPE,MEMBER)  ((System_Size) &((TYPE *)0)->MEMBER)
#endif
#define offsetof_class(TYPE,MEMBER)  ((System_Size) &((TYPE)0)->MEMBER)

#define instancein(OBJECT,MEMBER,TYPE)  ((TYPE *)OBJECT->MEMBER)

#define sizeof_class(CLASS) sizeof(struct ##CLASS)

#define sizeof_item(ARRAY)  sizeof(ARRAY[0])

#define sizeof_array(ARRAY)  (sizeof(ARRAY) / sizeof_item(ARRAY))

#define nameof(TYPE)  (#TYPE)

#define typeof(name)  (&name##Type)

/* You don't want to do while (i < 0), instead you would use while (i < -1). */

typedef void  System_Void;
typedef void  * System_Var; /* Var is not unsafe in C */
typedef __SIZE_TYPE__  System_Size;
typedef __SIZE_TYPE__  System_IntPtr;
typedef __PTRDIFF_TYPE__  System_SSize;
typedef __PTRDIFF_TYPE__  System_SIntPtr;

#if defined(using_System)
#define Var  System_Var
#define Size  System_Size
#define IntPtr  System_IntPtr
#define SSize  System_SSize
#define SIntPtr  System_SIntPtr
#endif

typedef unsigned char  System_UInt8;
#if defined(have_vscode)
#define System_UInt8  unsigned char
#endif
typedef unsigned short  System_UInt16;
typedef unsigned int  System_UInt32;
#if defined(__LP64__)
typedef unsigned long int  System_UInt64;
#else
typedef unsigned long long int  System_UInt64;
#endif
typedef signed char  System_Int8;
typedef signed short  System_Int16;
typedef signed int  System_Int32;
#if defined(__LP64__)
typedef signed long int  System_Int64;
#else
typedef signed long long int  System_Int64;
#endif

#if defined(using_System)
#define UInt8  System_UInt8
#define UInt16  System_UInt16
#define UInt32  System_UInt32
#define UInt64  System_UInt64

#define Int8  System_Int8
#define Int16  System_Int16
#define Int32  System_Int32
#define Int64  System_Int64
#endif

#define System_Byte  System_UInt8
#define System_UShort  System_UInt16
#define System_UInt  System_UInt32
#define System_ULong  System_UInt64

#define System_SByte  System_Int8
#define System_Short  System_Int16
#define System_Int  System_Int32
#define System_Long  System_Int64

#if defined(using_System)
#define Byte  System_Byte
#define UShort  System_UShort
#define UInt  System_UInt
#define ULong  System_ULong

#define SByte  System_SByte
#define Short  System_Short
#define Int  System_Int
#define Long  System_Long
#endif

typedef char  System_Char8,  * System_String8,  System_STRING8[];

export System_Char8  System_String8_Empty[1];

#define System_Stack_clear(VAR) for (System_Size ff(VAR,Z) = 0; ff(VAR,Z) < sizeof(VAR); ++ff(VAR,Z)) ((System_Char8 *)&VAR)[ff(VAR,Z)] = 0
#define System_Stack_clearType(VAR,TYPE) for (System_Size ff(VAR,Z) = 0; ff(VAR,Z) < sizeof(VAR); ++ff(VAR,Z)) ((System_Char8 *)&VAR)[ff(VAR,Z)] = 0; ((System_Object)&VAR)->type = TYPE
#define System_Stack_clearArray(VAR,TYPE):
    for (System_Size ff(VAR,Z) = 0; ff(VAR,Z) < sizeof(VAR); ++ff(VAR,Z)) 
        ((System_Char8 *)&VAR)[ff(VAR,Z)] = 0; 
    for (System_Size ff(VAR,Z) = 0; ff(VAR,Z) < sizeof_array(VAR); ++ff(VAR,Z)) 
        ((System_Object)&VAR[ff(VAR,Z)])->type = TYPE
#end

typedef System_Char8 System_TypeCode;
enum {
    System_TypeCode_Null,
    System_TypeCode_Boolean,
    System_TypeCode_String,
    System_TypeCode_Object,
    System_TypeCode_Int8,
    System_TypeCode_SInt8,
    System_TypeCode_Int16,
    System_TypeCode_SInt16,
    System_TypeCode_Int32,
    System_TypeCode_SInt32,
    System_TypeCode_Int64,
    System_TypeCode_SInt64,
    System_TypeCode_DateTime,
    System_TypeCode_Decimal,
    System_TypeCode_Float32,
    System_TypeCode_Float64,
};

#if defined(using_System)
#define Char8  System_Char8
#define String8  System_String8
#define STRING8  System_STRING8
#define String8_Empty  System_String8_Empty
#define Stack_clear  System_Stack_clear
#define Stack_clearType  System_Stack_clearType
#endif
#endif