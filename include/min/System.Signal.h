/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Signal)
#define have_System_Signal

typedef System_IntPtr System_Signal_Number;
enum {
    System_Signal_Number_SIGHUP = 1,
    System_Signal_Number_SIGINT = 2,
    System_Signal_Number_SIGQUIT = 3,
    System_Signal_Number_SIGILL = 4,
    System_Signal_Number_SIGTRAP = 5,
    System_Signal_Number_SIGABORT = 6,
    System_Signal_Number_SIGIOT = System_Signal_Number_SIGABORT,
    System_Signal_Number_SIGFPE = 8,
    System_Signal_Number_SIGKILL = 9,
    System_Signal_Number_SIGSEGV = 11,
    System_Signal_Number_SIGPIPE = 13,
    System_Signal_Number_SIGALARM = 14,
    System_Signal_Number_SIGTERM = 15,

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__)
    System_Signal_Number_SIGBUS = 7,
    System_Signal_Number_SIGUSR1 = 10,
    System_Signal_Number_SIGUSR2 = 12,
    System_Signal_Number_SIGSTKFLT = 16,
    System_Signal_Number_SIGCHILD = 17,
    System_Signal_Number_SIGCONTINUE = 18,
    System_Signal_Number_SIGSTOP = 19,
    System_Signal_Number_SIGTSTP = 20,
    System_Signal_Number_SIGTTIN = 21,
    System_Signal_Number_SIGTTOU = 22,
    System_Signal_Number_SIGURG = 23,
    System_Signal_Number_SIGXCPU = 24,
    System_Signal_Number_SIGXFSZ = 25,
    System_Signal_Number_SIGVTALRM = 26,
    System_Signal_Number_SIGPROF = 27,
    System_Signal_Number_SIGWINCH = 28,
    System_Signal_Number_SIGIO = 29,
    System_Signal_Number_SIGPWR = 30,
    System_Signal_Number_SIGSYS = 31,

#else
#error Unknown Processor Architecture
#endif
};

export System_String8 System_Signal_Number_toString(System_Signal_Number value);


typedef struct System_Signal {
#if System_Size_Bits == 32
    unsigned long mask[2];
#else /* if System_Size_Bits == 64 */
    unsigned long mask[1];
#endif
} * System_Signal;

typedef struct System_Signal_Info {
    System_UInt32 number; /* Signal number.  */
    System_UInt32 errno; /* If non-zero, an errno value associated with this signal, as defined in <errno.h>.  */
    System_UInt32 code; /* Signal code.  */

    union {

        /* kill  */
        struct {
            System_Int32 pid;    /* Sending process ID.  */
            System_UInt32 uid;    /* Real user ID of sending process.  */
        } kill;

        /* POSIX.1b timers.  */
        struct {
            System_Int32 tid;        /* Timer ID.  */
            System_Int32 overrun;    /* Overrun count.  */
            System_IntPtr value;    /* Signal value.  */
        } timer;

        /* POSIX.1b signals.  */
        struct {
            System_Int32 pid;    /* Sending process ID.  */
            System_UInt32 uid;    /* Real user ID of sending process.  */
            System_IntPtr value;    /* Signal value.  */
        } realtime;

        /* SIGCHILD.  */
        struct {
            System_Int32 pid;    /* Which child.  */
            System_UInt32 uid;    /* Real user ID of sending process.  */
            System_Int32 status;    /* Exit value or signal.  */
            System_Int64 utime;
            System_Int64 stime;
        } sigchild;

        /* SIGILL, SIGFPE, SIGSEGV, SIGBUS.  */
        struct {
            System_Var address;    /* Faulting instruction  */
        } sigfault;

        /* SIGPOLL.  */
        struct {
            System_Int64 band;    /* Band event for SIGPOLL.  */
            System_Int32 fd;
        } sigpoll;

        /* SIGSYS.  */
        struct {
            System_Var address;   /* Calling user instruction  */
            System_Int32 syscall; /* Triggering system call number.  */
            System_UInt32 arch;   /* AUDIT_ARCH_* of syscall.  */
        } sigsys;
    };
    
} * System_Signal_Info;

typedef void delegate(System_Signal_handler)(System_Signal_Number number);
typedef void delegate(System_Signal_action)(System_Signal_Number number, System_Signal_Info info, System_Var context);

#define function_System_Signal_handler_DEFAULT ((function_System_Signal_handler)0UL)
#define function_System_Signal_handler_IGNORE ((function_System_Signal_handler)1UL)
#define function_System_Signal_handler_ERROR ((function_System_Signal_handler)-1UL)

typedef struct System_Signal_Action {
    union {
        function_System_Signal_handler handler;
        function_System_Signal_action action;
    };
    unsigned long flags;
    void (*restorer)(void);
    struct System_Signal signal;
} * System_Signal_Action;

export void System_Signal_handle(System_Signal_Number number, function_System_Signal_handler handler);
export void System_Signal_act(System_Signal_Number number, function_System_Signal_action action);
export System_Bool System_Signal_get__number(System_Signal_Number number);
export void System_Signal_set__number(System_Signal_Number number);
export void System_Signal_block__number(System_Signal_Number number);
export void System_Signal_unblock__number(System_Signal_Number number);
export void System_Signal_add(System_Signal that, System_Signal_Number number);
export void System_Signal_remove(System_Signal that, System_Signal_Number number);
export void System_Signal_get(System_Signal that);
export void System_Signal_set(System_Signal that);
export void System_Signal_block(System_Signal that);
export void System_Signal_unblock(System_Signal that);

export struct System_Type  System_SignalType;

#endif
