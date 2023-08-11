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

#define SA_NODEFER	0x00000008
#define SA_RESTART  0x10000000 

function_System_Signal_handler System_Signal_signal(System_Signal_Code signal, function_System_Signal_handler handler) {

    struct System_Signal_Action new;
    new.handler = handler; 
    new.flags = 0; // SA_RESTART SA_NODEFER
    new.restorer = null;
    for (System_Size i = 0; i < System_Signal_Set_LENGTH; ++i) new.mask.signal[i] = 0;

	unsigned __word = __sigword (signal);
    unsigned long __mask = __sigmask (signal);
    //System_Console_writeLine("SIGWORD: {0:uint}, SIGMASK: {1:uint}", 2, __word, __mask);
    new.mask.signal[__word] |= __mask;

    System_Syscall_sigaction(signal, &new, null);
    System_Error errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_signal Error: {0:uint}", 1, errno);

    return null;
}

/* Values for the HOW argument to `sigprocmask'.  */
#define	SIG_BLOCK     0		 /* Block signals.  */
#define	SIG_UNBLOCK   1		 /* Unblock signals.  */
#define	SIG_SETMASK   2		 /* Set the set of blocked signals.  */

void System_Signal_getProcMask(System_Signal_Set old) {

    for (System_Size i = 0; i < System_Signal_Set_LENGTH; ++i) old->signal[i] = 0;

    System_Syscall_sigprocmask(0, null, old, sizeof(struct System_Signal_Set));

    System_Error errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_getProcMask Error: {0:uint}", 1, errno);
}

void System_Signal_setProcMask(System_IntPtr how, System_Signal_Set new) {

    System_Syscall_sigprocmask(how, new, null, sizeof(struct System_Signal_Set));

    System_Error errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_setProcMask Error: {0:uint}", 1, errno);
}

#endif
