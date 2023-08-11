/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Signal)
#define have_System_Signal

typedef System_IntPtr System_Signal_Code;
enum {
	System_Signal_Code_SIGHUP = 1,
	System_Signal_Code_SIGINT = 2,
	System_Signal_Code_SIGQUIT = 3,
	System_Signal_Code_SIGILL = 4,
	System_Signal_Code_SIGTRAP = 5,
	System_Signal_Code_SIGABORT = 6,
	System_Signal_Code_SIGIOT = System_Signal_Code_SIGABORT,
	System_Signal_Code_SIGFPE = 8,
	System_Signal_Code_SIGKILL = 9,
	System_Signal_Code_SIGSEGV = 11,
	System_Signal_Code_SIGPIPE = 13,
	System_Signal_Code_SIGALARM = 14,
	System_Signal_Code_SIGTERM = 15,

#if defined(__x86_64__) || defined(__arm__) || defined(__aarch64__)
	System_Signal_Code_SIGBUS = 7,
	System_Signal_Code_SIGUSR1 = 10,
	System_Signal_Code_SIGUSR2 = 12,
	System_Signal_Code_SIGSTKFLT = 16,
	System_Signal_Code_SIGCHILD = 17,
	System_Signal_Code_SIGCONTINUE = 18,
	System_Signal_Code_SIGSTOP = 19,
	System_Signal_Code_SIGTSTP = 20,
	System_Signal_Code_SIGTTIN = 21,
	System_Signal_Code_SIGTTOU = 22,
	System_Signal_Code_SIGURG = 23,
	System_Signal_Code_SIGXCPU = 24,
	System_Signal_Code_SIGXFSZ = 25,
	System_Signal_Code_SIGVTALRM = 26,
	System_Signal_Code_SIGPROF = 27,
	System_Signal_Code_SIGWINCH = 28,
	System_Signal_Code_SIGIO = 29,
	System_Signal_Code_SIGPWR = 30,
	System_Signal_Code_SIGSYS = 31,

#else
#error Unknown Processor Architecture
#endif
};

#define System_Signal_Set_LENGTH (64 / (8 * sizeof(unsigned long)))

typedef struct System_Signal_Set {
	unsigned long signal[System_Signal_Set_LENGTH];
} * System_Signal_Set;

typedef void delegate(System_Signal_handler)(System_SIntPtr code);
typedef void delegate(System_Signal_action)(System_SIntPtr code, System_Var info, System_Var context);

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
	struct System_Signal_Set mask;
} * System_Signal_Action;

export function_System_Signal_handler System_Signal_signal(System_Signal_Code signal, function_System_Signal_handler handler);

export struct System_Type  System_SignalType;

#endif
