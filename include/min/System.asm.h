/* Gemeinfrei. Public Domain. */
#if !defined(have_System_asm)
#define have_System_asm

/*  Now you can easily do #if DEBUG.
    You need to #define DEBUG 0 for yourself, for example
#if !defined(NODEBUG) || !defined(RELEASE)
#define DEBUG 0
#else
#define DEBUG 1
#endif
*/
#if !defined(DEBUG)
#define DEBUG 1
#endif

/* Compiler: MSVCC */
#if defined(_MSC_VER)
#define MSVCC
#endif

/* Compiler: GNUCC */
#if defined(__GNUC__)
#define GNUCC
#endif

/* Compiler: TinyCC */
#if defined(__TINYC__)
#define TinyCC
#endif

/* Platform: Windows */
#if defined(_WIN32) || defined(__OS2__)
#define have_Windows
#define have_Windows32
#elif defined(_WIN64)
#define have_Windows
#define have_Windows64
#endif

/* Platform: Apple
#if defined(APPLE) */

/* Platform: Linux/Unix */
#if defined(linux) || defined(__linux)
#undef  linux
#define have_Linux
#endif

#if defined(unix) || defined(__unix)
#undef  unix
#define have_Unix
#endif


/* Architecture, on Unix: arm, x86_64 or else i386 */
#if defined(have_Linux) || defined(have_Unix)

#if defined(__arm__)
#define have_ARM

#elif defined(__x86_64__)
#define have_AMD64
#if defined(__ILP32__)
#define have_X86
#endif

#elif defined(__i386__)
#define have_X86

#else
#error Architecture not implemented.
#endif

/* Architecture, on Windows: arm?, ia64/ia32?, amd64 or else x86 */
#elif defined(have_Windows)

#if defined(_M_ARM)
#define have_ARM

#elif defined(_M_X64) || defined(_M_AMD64)
#define have_AMD64
#if defined(_M_IX86)
#define have_X86
#endif

#else
#error Architecture not implemented.
#endif

#else
#error Platform not implemented.
#endif

#if defined(__ASSEMBLER__)
#define have_ASSEMBLER
#endif

#if defined(__PIC__)
#define have_PIC
#endif
#endif
