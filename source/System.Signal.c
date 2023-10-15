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

struct System_Type System_SignalType = { .base = { .type = typeof(System_Type) }, .name = "Signal", };

#define __sigmask(sig) (((unsigned long) 1) << ((unsigned)((sig) - 1) % (8 * sizeof (unsigned long))))
#define __sigword(sig) ((unsigned)((sig) - 1) / (8 * sizeof (unsigned long)))

enum {
    SA_INTERRUPT = 0x20000000, /* Historical no-op.  */

    SA_NOCLDSTOP = 1, /* Don't send SIGCHLD when children stop.  */
    SA_NOCLDWAIT = 2, /* Don't create zombie on child death.  */
    SA_NODEFER = 0x40000000, /* Don't automatically block the signal when its handler is being executed.  */
    SA_NOMASK = SA_NODEFER,

    SA_ONSTACK = 0x08000000, /* Use signal stack by using `sa_restorer'. */
    SA_RESTART = 0x10000000, /* Restart syscall on signal return.  */
    SA_RESETHAND = 0x80000000, /* Reset to SIG_DFL on entry to handler.  */
    SA_ONESHOT = SA_RESETHAND,

    SA_RESTORER = 0x04000000,
    SA_SIGINFO = 4,  /* Invoke signal-catching function with three arguments instead of one.  */
};

void System_Signal_signal(System_Signal_Code code, function_System_Signal_handler handler) {

    struct System_Signal_Action new; System_Stack_zero(new);
    new.handler = handler; 
    new.flags = SA_RESTORER; // | SA_RESTART | SA_NODEFER
    new.restorer = &System_Syscall_sigreturn;

    /*unsigned __word = __sigword (code);
    unsigned long __mask = __sigmask (code);
    //System_Console_writeLine("SIGWORD: {0:uint}, SIGMASK: {1:uint}", 2, __word, __mask);
    new.signal.mask[__word] |= __mask;*/

    new.signal.mask[0] |= (1 << (code - 1));

    System_Syscall_sigaction(code, &new, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_signal Code: {0:uint:hex} Error: {1:string}", 2, code, enum_getName(typeof(System_ErrorCode), errno));
}

/* Values for the HOW argument to `sigprocmask'. */
enum {
    SIG_BLOCK,      // Block signals.
    SIG_UNBLOCK,    // Unblock signals.
    SIG_SETMASK,    // Set the set of blocked signals.
};

System_Bool System_Signal_get__code(System_Signal_Code code) {

    struct System_Signal sigset; System_Stack_zero(sigset);
    System_Syscall_sigprocmask(SIG_SETMASK, null, &sigset, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_get__code Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));

    return sigset.mask[0] & ((System_Signal_Code)1 << (code - 1));
}

void System_Signal_set__code(System_Signal_Code code) {

    struct System_Signal sigset; System_Stack_zero(sigset);
    sigset.mask[0] |= ((System_Signal_Code)1 << (code - 1));
    System_Syscall_sigprocmask(SIG_SETMASK, &sigset, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_set__code Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_block__code(System_Signal_Code code) {

    struct System_Signal sigset; System_Stack_zero(sigset);
    sigset.mask[0] |= ((System_Signal_Code)1 << (code - 1));
    System_Syscall_sigprocmask(SIG_BLOCK, &sigset, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_block__code Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_unblock__code(System_Signal_Code code) {

    struct System_Signal sigset; System_Stack_zero(sigset);
    sigset.mask[0] |= ((System_Signal_Code)1 << (code - 1));
    System_Syscall_sigprocmask(SIG_UNBLOCK, &sigset, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_unblock__code Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

#endif
