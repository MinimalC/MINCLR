#if !defined(have_System_syscall_asm_linux_x86_64)
#define have_System_syscall_asm_linux_x86_64

#include "enum System.Syscall.command.asm.h"

/* ELF uses byte-counts for .align, most others use log2 of count of bytes.  */
#define ASM_ALIGN(log2) .align 1<<log2;
#define ASM_SIZE(name) .size name,.-name;

/* Define an entry point visible from C.  */
#define	__function(name) \
    .global name; \
    .type name,@function; \
    ASM_ALIGN(4) \
name:

#define	__hidden_function(name) \
    .hidden name; \
    .type name,@function; \
    ASM_ALIGN(4) \
name:

#define __end_function(name) \
    ASM_SIZE(name)

#ifdef have_PIC
#ifdef BIND_NOW
#define __call(name)  call  *name##@GOTPCREL(%rip);
#else
#define __call(name)  call  name##@PLT;
#endif
#else
/* For static archives, branch to target directly.  */
#define __call(name)  call  name
#endif

/* Assembler address directive. */
#define ASM_ADDR  .quad

/* Registers to hold long and pointer.  */
#define RAX	 rax
#define RBP  rbp
#define RBX  rbx
#define RCX  rcx
#define RDI  rdi
#define RDX  rdx
#define RSI  rsi
#define RSP  rsp
#define R8  r8
#define R9  r9
#define R10  r10
#define R11  r11
#define R12  r12
#define R13  r13
#define R14  r14
#define R15  r15

#endif
