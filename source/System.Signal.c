/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Signal)
#include <min/System.Signal.h>
#endif
#if !defined(code_System_Signal)
#define code_System_Signal

/*# System_Signal #*/

struct System_Type System_SignalType = { .base = stack_System_Object(System_Type), .name = "Signal", };

#define __sigmask(sig) (((unsigned long) 1) << ((unsigned)((sig) - 1) % (8 * sizeof (unsigned long))))
#define __sigword(sig) ((unsigned)((sig) - 1) / (8 * sizeof (unsigned long)))

#define SA_INTERRUPT 0x20000000 /* Historical no-op.  */

#define	SA_NOCLDSTOP  1		 /* Don't send SIGCHLD when children stop.  */
#define SA_NOCLDWAIT  2		 /* Don't create zombie on child death.  */
#define SA_NODEFER   0x40000000 /* Don't automatically block the signal when its handler is being executed.  */
#define SA_NOMASK    SA_NODEFER

#define SA_ONSTACK   0x08000000 /* Use signal stack by using `sa_restorer'. */
#define SA_ONESHOT   SA_RESETHAND
#define SA_RESTART   0x10000000 /* Restart syscall on signal return.  */
#define SA_RESETHAND 0x80000000 /* Reset to SIG_DFL on entry to handler.  */

#define SA_RESTORER  0x04000000
#define SA_SIGINFO    4		 /* Invoke signal-catching function with three arguments instead of one.  */

void System_Signal_signal(System_Signal_Code signal, function_System_Signal_handler handler) {

    struct System_Signal_Action new; System_Stack_free(new);
    new.handler = handler; 
    new.flags = 0; // SA_RESTORER SA_RESTART SA_NODEFER
    //new.restorer = &System_Syscall_sigreturn;

    /*unsigned __word = __sigword (signal);
    unsigned long __mask = __sigmask (signal);
    //System_Console_writeLine("SIGWORD: {0:uint}, SIGMASK: {1:uint}", 2, __word, __mask);
    new.mask.signal[__word] |= __mask;*/

    System_Syscall_sigaction(signal, &new, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_signal Code: {0:uint:hex} Error: {1:string}", 2, signal, enum_getName(typeof(System_ErrorCode), errno));
}

/* Values for the HOW argument to `sigprocmask'.
#define  SIG_BLOCK     0     // Block signals.
#define  SIG_UNBLOCK   1     // Unblock signals.
#define  SIG_SETMASK   2     // Set the set of blocked signals.
*/

void System_Signal_getProcMask(System_Signal_Set old) {

    for (System_Size i = 0; i < System_Signal_Set_LENGTH; ++i) old->signal[i] = 0;

    System_Syscall_sigprocmask(0, null, old, sizeof(struct System_Signal_Set));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_getProcMask Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_setProcMask(System_Signal_Set new) {

    System_Syscall_sigprocmask(2, new, null, sizeof(struct System_Signal_Set));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_setProcMask Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_block(System_Signal_Set new) {

    System_Syscall_sigprocmask(0, new, null, sizeof(struct System_Signal_Set));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_setProcMask Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_unblock(System_Signal_Set new) {

    System_Syscall_sigprocmask(1, new, null, sizeof(struct System_Signal_Set));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_setProcMask Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

#endif
