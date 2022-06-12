/* Gemeinfrei. Public Domain. */
#if !defined(have_System_asm)
#define have_System_asm

#if defined(__DEBUG)
#if defined(__RELEASE)
#warning __DEBUG was defined
#undef __DEBUG
/* default */
#define __DEBUG  0
#endif
#else
#define __DEBUG  0
#endif


/* Compiler: __MSVCC */
#if defined(_MSC_VER)
#define __MSVCC  _MSC_VER
#endif

/* Compiler: __GNUCC */
#if defined(__GNUC__)
#define __GNUCC  __GNUC__
#endif

/* Compiler: __TinyCC */
#if defined(__TINYC__)
#define __TinyCC  __TINYC__
#endif

/* Platform: Windows */
#if defined(_WIN32) || defined(__OS2__)
#define have_Windows  _WIN32
#define have_Windows32  _WIN32
#elif defined(_WIN64)
#define have_Windows  _WIN64
#define have_Windows64  _WIN64
#endif

/* Platform: Apple
#if defined(APPLE) */

/* Platform: Linux/Unix */
#if defined(linux) || defined(__linux)
#undef  linux
#define have_Linux  __linux
#endif

#if defined(unix) || defined(__unix)
#undef  unix
#define have_unix  __unix
#endif


/* Architecture, on Unix: arm, x86_64 or else i386 */
#if defined(have_Linux) || defined(have_unix)

#if defined(__arm__)
#define have_ARM  1

#elif defined(__x86_64__)
#define have_AMD64  1
#if defined(__ILP32__)
#define have_X86  1
#endif

#elif defined(__i386__)
#define have_X86  1

#else
#error Architecture not implemented.
#endif

/* Architecture, on Windows: arm?, ia64/ia32?, amd64 or else x86 */
#elif defined(have_Windows)

#if defined(_M_ARM)
#define have_ARM  1

#elif defined(_M_X64) || defined(_M_AMD64)
#define have_AMD64  1
#if defined(_M_IX86)
#define have_X86  1
#endif

#else
#error Architecture not implemented.
#endif

#else
#error Platform not implemented.
#endif

#if defined(__ASSEMBLER__)
#define have_ASSEMBLER  1
#endif

#if defined(__PIC__)
#define have_PIC  1
#endif

#if defined(have_AMD64)
#if defined(have_AMD64_32)
#define System_wordsize  32
#define System_bytesize  4
#else
#define System_wordsize  64
#define System_bytesize  8
#endif

#else
#define System_wordsize  32
#define System_bytesize  4
#endif

#endif
