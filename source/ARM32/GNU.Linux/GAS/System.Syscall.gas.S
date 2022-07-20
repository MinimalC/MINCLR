/* Gemeinfrei. Public Domain. */

#include <min/linux/arm/System.gas.h>

/* Tag_ABI_align8_preserved: This code preserves 8-byte alignment in any callee.  */
/* .eabi_attribute 25, 1 */
/* Tag_ABI_align8_needed: This code may require 8-byte alignment from the caller.  */
/* .eabi_attribute 24, 1 */

.arm
.text
.syntax unified

/* The ARM EABI user interface passes the syscall number in r7, instead
   of in the swi.  This is more efficient, because the kernel does not need
   to fetch the swi from memory to find out the number; which can be painful
   with separate I-cache and D-cache.  Make sure to use 0 for the SWI
   argument; otherwise the (optional) compatibility code for APCS binaries
   may be invoked.  */

/* Linux takes system call args in registers:
	arg 1		r0
	arg 2		r1
	arg 3		r2
	arg 4		r3
	arg 5		r4	(this is different from the APCS convention)
	arg 6		r5
	arg 7		r6

   The compiler is going to form a call by coming here, through PSEUDO, with
   arguments
	syscall number	in the DO_CALL macro
	arg 1		r0
	arg 2		r1
	arg 3		r2
	arg 4		r3
	arg 5		[sp]
	arg 6		[sp+4]
	arg 7		[sp+8]

   We need to shuffle values between R4..R6 and the stack so that the
   caller's v1..v3 and stack frame are not corrupted, and the kernel
   sees the right arguments. */

/* Just like the APCS syscall convention, the EABI syscall convention uses
   r0 through r6 for up to seven syscall arguments.  None are ever passed to
   the kernel on the stack, although incoming arguments are on the stack for
   syscalls with four or more arguments.

   The assembler will convert the literal pool load to a move for most syscalls.  */

/* The code for Linux is almost identical to the canonical Unix
   code, except that the error number in R0 is negated. */

/* Linux uses a negative return value to indicate syscall errors,
   unlike most Unices, which use the condition codes' carry flag.

   Since version 2.1 the return value of a system call might be
   negative even if the call succeeded.  E.g., the `lseek' system call
   might return a large offset.  Therefore we must not anymore test
   for < 0, but test for a real error by making sure the value in R0
   is a real error number.  Linus said he will make sure the no syscall
   returns a value in -1 .. -4095 as a valid result so we can safely
   test with -4095.  */

__function(System_Syscall_call00)
    str   lr, [ sp, #-4 ]!  /* store link register */

    str   r7, [ sp, #-8 ]   /* store r7 */
    mov   r7, r0            /* enum_System_Syscall_command */
    swi   #0
    ldr   r7, [ sp, #-8 ]   /* load r7 */

    sub   sp, sp, #8
    str   r0, [ sp, #0 ]    /* store r0 */
    cmn   r0, $4096
    bcs   System_Syscall_failed
    b     System_Syscall_good
__end_function(System_Syscall_call00)

__function(System_Syscall_call01)
    str   lr, [ sp, #-4 ]!  /* push link register */

    str   r7, [ sp, #-8 ]   /* store r7 */
    mov   r7, r0            /* enum_System_Syscall_command */
    mov   r0, r1            /* arg1 */
    swi   #0
    ldr   r7, [ sp, #-8 ]   /* load r7 */

    sub   sp, sp, #8
    str   r0, [ sp, #0 ]    /* store r0 */
    cmn   r0, $4096
    bcs   System_Syscall_failed
    b     System_Syscall_good
__end_function(System_Syscall_call01)

__function(System_Syscall_call02)
    str   lr, [ sp, #-4 ]!  /* push link register */

    str   r7, [ sp, #-8 ]   /* store r7 */
    mov   r7, r0            /* enum_System_Syscall_command */
    mov   r0, r1            /* arg1 */
    mov   r1, r2            /* arg2 */
    swi   #0
    ldr   r7, [ sp, #-8 ]   /* load r7 */

    sub   sp, sp, #8
    str   r0, [ sp, #0 ]    /* store r0 */
    cmn   r0, $4096
    bcs   System_Syscall_failed
    b     System_Syscall_good
__end_function(System_Syscall_call02)

__function(System_Syscall_call03)
    str   lr, [ sp, #-4 ]!  /* push link register */

    str   r7, [ sp, #-8 ]   /* store r7 */
    mov   r7, r0            /* enum_System_Syscall_command */
    mov   r0, r1            /* arg1 */
    mov   r1, r2            /* arg2 */
    mov   r2, r3            /* arg3 */
    swi   #0
    ldr   r7, [ sp, #-8 ]   /* load r7 */

    sub   sp, sp, #8
    str   r0, [ sp, #0 ]    /* store r0 */
    cmn   r0, $4096
    bcs   System_Syscall_failed
    b     System_Syscall_good
__end_function(System_Syscall_call03)

__function(System_Syscall_call04)
    str   lr, [ sp, #-4 ]!  /* push link register */

    str   r7, [ sp, #-8 ]   /* store r7 */
    mov   r7, r0            /* enum_System_Syscall_command */
    mov   r0, r1            /* arg1 */
    mov   r1, r2            /* arg2 */
    mov   r2, r3            /* arg3 */
    ldr   r3, [ sp, #0 ]    /* arg4 */
    swi   #0
    ldr   r7, [ sp, #-8 ]   /* load r7 */

    sub   sp, sp, #8
    str   r0, [ sp, #0 ]    /* store r0 */
    cmn   r0, $4096
    bcs   System_Syscall_failed
    b     System_Syscall_good
__end_function(System_Syscall_call04)

__function(System_Syscall_call05)
    str   lr, [ sp, #-4 ]!  /* push link register */

    str   r7, [ sp, #-8 ]   /* store r7 */
    mov   r7, r0            /* enum_System_Syscall_command */
    mov   r0, r1            /* arg1 */
    mov   r1, r2            /* arg2 */
    mov   r2, r3            /* arg3 */
    ldr   r3, [ sp, #0 ]    /* arg4 */
    ldr   r4, [ sp, #4 ]    /* arg5 */
    swi   #0
    ldr   r7, [ sp, #-8 ]   /* load r7 */

    sub   sp, sp, #8
    str   r0, [ sp, #0 ]    /* store r0 */
    cmn   r0, $4096
    bcs   System_Syscall_failed
    b     System_Syscall_good
__end_function(System_Syscall_call05)

__function(System_Syscall_call06)
    str   lr, [ sp, #-4 ]!  /* push link register */

    str   r7, [ sp, #-8 ]   /* store r7 */
    mov   r7, r0            /* enum_System_Syscall_command */
    mov   r0, r1            /* arg1 */
    mov   r1, r2            /* arg2 */
    mov   r2, r3            /* arg3 */
    ldr   r3, [ sp, #0 ]    /* arg4 */
    ldr   r4, [ sp, #4 ]    /* arg5 */
    ldr   r5, [ sp, #8 ]    /* arg6 */
    swi   #0
    ldr   r7, [ sp, #-8 ]   /* load r7 */

    sub   sp, sp, #8
    str   r0, [ sp, #0 ]    /* store r0 */
    cmn   r0, $4096
    bcs   System_Syscall_failed
    b     System_Syscall_good
__end_function(System_Syscall_call06)

#define __return  \
    add   sp, sp, #8;\
    ldr   pc, [ sp ], #4;

__hidden_function(System_Syscall_good)
    mov   r0, #0
    bl    System_Syscall_set_error(PLT)
    ldr   r0, [ sp, #0 ]    /* load r0 */

    __return
__end_function(System_Syscall_good)

__hidden_function(System_Syscall_failed)
    neg   r0, r0
    bl    System_Syscall_set_error(PLT)
    mov   r0, #0            /* return 0 */

    __return
__end_function(System_Syscall_failed)
