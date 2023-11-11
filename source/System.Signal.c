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

String8 System_Signal_Number_toString(System_Signal_Number value) {
    switch (value) {
    case System_Signal_Number_SIGILL: return "SIGILL";
    case System_Signal_Number_SIGFPE: return "SIGFPE";
    case System_Signal_Number_SIGSEGV: return "SIGSEGV";
    case System_Signal_Number_SIGBUS: return "SIGBUS";
    case System_Signal_Number_SIGINT: return "SIGINT";
    }
    return "UNKNOWN";
}

/*# System_Signal #*/

struct System_Type System_SignalType = { .base = { .type = typeof(System_Type) }, .name = "Signal", };

/*#define __sigmask(sig) (((unsigned long) 1) << ((unsigned)((sig) - 1) % (8 * sizeof (unsigned long))))
#define __sigword(sig) ((unsigned)((sig) - 1) / (8 * sizeof (unsigned long)))*/

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

void System_Signal_handle(System_Signal_Number number, function_System_Signal_handler handler) {

    struct System_Signal_Action new; System_Stack_clear(new);
    new.handler = handler; 
    new.flags = SA_RESTORER; // | SA_RESTART | SA_NODEFER
    new.restorer = &System_Syscall_sigreturn;

    /*unsigned __word = __sigword (number);
    unsigned long __mask = __sigmask (number);
    //System_Console_writeLine("SIGWORD: {0:uint}, SIGMASK: {1:uint}", 2, __word, __mask);
    new.signal.mask[__word] |= __mask;*/

    new.signal.mask[0] |= (1 << (number - 1));

    System_Syscall_sigaction(number, &new, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_handle Code: {0:uint:hex} Error: {1:string}", 2, number, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_act(System_Signal_Number number, function_System_Signal_action action) {

    struct System_Signal_Action new; System_Stack_clear(new);
    new.action = action; 
    new.flags = SA_RESTORER | SA_SIGINFO; // | SA_RESTART | SA_NODEFER
    new.restorer = &System_Syscall_sigreturn;

    /*unsigned __word = __sigword (number);
    unsigned long __mask = __sigmask (number);
    //System_Console_writeLine("SIGWORD: {0:uint}, SIGMASK: {1:uint}", 2, __word, __mask);
    new.signal.mask[__word] |= __mask;*/

    new.signal.mask[0] |= (1 << (number - 1));

    System_Syscall_sigaction(number, &new, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_act Code: {0:uint:hex} Error: {1:string}", 2, number, enum_getName(typeof(System_ErrorCode), errno));
}

/* Values for the HOW argument to `sigprocmask'. */
enum {
    SIG_BLOCK,      // Block signals.
    SIG_UNBLOCK,    // Unblock signals.
    SIG_SETMASK,    // Set the set of blocked signals.
};

System_Bool System_Signal_get__number(System_Signal_Number number) {

    struct System_Signal sigset; System_Stack_clear(sigset);
    System_Syscall_sigprocmask(SIG_SETMASK, null, &sigset, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_get__number Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));

    return sigset.mask[0] & ((System_Signal_Number)1 << (number - 1));
}

void System_Signal_set__number(System_Signal_Number number) {

    struct System_Signal sigset; System_Stack_clear(sigset);
    sigset.mask[0] |= ((System_Signal_Number)1 << (number - 1));
    System_Syscall_sigprocmask(SIG_SETMASK, &sigset, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_set__number Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_block__number(System_Signal_Number number) {

    struct System_Signal sigset; System_Stack_clear(sigset);
    sigset.mask[0] |= ((System_Signal_Number)1 << (number - 1));
    System_Syscall_sigprocmask(SIG_BLOCK, &sigset, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_block__number Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_unblock__number(System_Signal_Number number) {

    struct System_Signal sigset; System_Stack_clear(sigset);
    sigset.mask[0] |= ((System_Signal_Number)1 << (number - 1));
    System_Syscall_sigprocmask(SIG_UNBLOCK, &sigset, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_unblock__number Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_add(System_Signal that, System_Signal_Number number) {
    that->mask[0] |= ((System_Signal_Number)1 << (number - 1));
}

void System_Signal_remove(System_Signal that, System_Signal_Number number) {
    that->mask[0] &= ~((System_Signal_Number)1 << (number - 1));
}

void System_Signal_get(System_Signal that) {

    System_Syscall_sigprocmask(SIG_SETMASK, null, that, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_get Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_set(System_Signal that) {

    System_Syscall_sigprocmask(SIG_SETMASK, that, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_set Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_block(System_Signal that) {

    System_Syscall_sigprocmask(SIG_BLOCK, that, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_block Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Signal_unblock(System_Signal that) {

    System_Syscall_sigprocmask(SIG_UNBLOCK, that, null, sizeof(struct System_Signal));

    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Signal_unblock Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

#endif
