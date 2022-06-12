#if !defined(have_System_syscall_asm_linux_arm)
#define have_System_syscall_asm_linux_arm

#include "enum System.Syscall.command.asm.h"

/* The __ARM_ARCH define is provided by gcc 4.8.  Construct it otherwise.  */
#ifndef __ARM_ARCH
# ifdef __ARM_ARCH_2__
#  define __ARM_ARCH 2
# elif defined (__ARM_ARCH_3__) || defined (__ARM_ARCH_3M__)
#  define __ARM_ARCH 3
# elif defined (__ARM_ARCH_4__) || defined (__ARM_ARCH_4T__)
#  define __ARM_ARCH 4
# elif defined (__ARM_ARCH_5__) || defined (__ARM_ARCH_5E__) \
       || defined(__ARM_ARCH_5T__) || defined(__ARM_ARCH_5TE__) \
       || defined(__ARM_ARCH_5TEJ__)
#  define __ARM_ARCH 5
# elif defined (__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) \
       || defined (__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__) \
       || defined (__ARM_ARCH_6K__) || defined(__ARM_ARCH_6T2__)
#  define __ARM_ARCH 6
# elif defined (__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) \
       || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) \
       || defined(__ARM_ARCH_7EM__)
#  define __ARM_ARCH 7
# else
#  error unknown arm architecture
# endif
#endif

#if __ARM_ARCH > 4 || defined (__ARM_ARCH_4T__)
# define ARCH_HAS_BX
#endif
#if __ARM_ARCH > 4
# define ARCH_HAS_BLX
#endif
#if __ARM_ARCH > 6 || defined (__ARM_ARCH_6K__) || defined (__ARM_ARCH_6ZK__)
# define ARCH_HAS_HARD_TP
#endif
#if __ARM_ARCH > 6 || defined (__ARM_ARCH_6T2__)
# define ARCH_HAS_T2
#endif

/* Syntactic details of assembler.  */

#define ASM_ALIGN(log2) .align log2;
#define ASM_SIZE(name) .size name,.-name;

#ifdef ARCH_HAS_BX
#define BX(R)     bx  R;
#define BXC(C,R)  bx##C  R;
#ifdef ARCH_HAS_BLX
#define BLX(R)    blx  R;
#else
#define BLX(R)    mov  lr, pc; bx R;
#endif
#else
#define BX(R)     mov  pc, R;
#define BXC(C,R)  mov##C  pc, R;
#define BLX(R)    mov  lr, pc; mov pc, R;
#endif

/* Define an entry point visible from C.  */
#define  __function(name) \
    .global  name; \
    .type  name,%function; \
    ASM_ALIGN(2) \
name:

#define  __hidden_function(name) \
    .hidden  name; \
    .type  name,%function; \
    ASM_ALIGN(2) \
name:

#define __end_function(name) \
    ASM_SIZE(name)


/* This number is the offset from the pc at the current location.  */
#ifdef __thumb__
#define PC_OFFSET  4
#else
#define PC_OFFSET  8
#endif

#endif