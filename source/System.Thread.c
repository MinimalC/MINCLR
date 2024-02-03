/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_ELFAssembly)
#include <min/System.ELFAssembly.h>
#endif
#if !defined(have_System_Signal)
#include <min/System.Signal.h>
#endif
#if !defined(have_System_Thread)
#include <min/System.Thread.h>
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
#endif
#if !defined(code_System_Thread)
#define code_System_Thread

struct System_Type System_ThreadType = { 
    .base = { .type = typeof(System_Type) }, 
    .name = "Thread", 
    .size = sizeof(struct System_Thread),
    .baseType = typeof(System_Object),
};

export thread System_Thread System_Thread_Current = null;

System_Var System_Thread_createStorage(void) {
    return System_ELF64Assembly_createThread();
}

enum {
    ARCH_SET_GS = 0x1001,
    ARCH_SET_FS = 0x1002,
    ARCH_GET_FS = 0x1003,
    ARCH_GET_GS = 0x1004,
};

System_Var System_Thread_getRegister(void) {
    System_Var fs = null;
    System_Syscall_arch_prctl(ARCH_GET_FS, (System_IntPtr)&fs);
    return fs;
}

void System_Thread_setRegister(System_Var fs) {
    if (fs) System_Syscall_arch_prctl(ARCH_SET_FS, (System_IntPtr)fs);
}

System_Var __tls_get_addr(System_Var index) {
    return null; // throw
}

void System_Thread_yield(void) {
    System_Syscall_sched_yield();
}

enum {
    STACK_SIZE = (8 * 1024 * 1024)
};

enum {
    CLONE_VM = 0x00000100,
    CLONE_FS = 0x00000200,
    CLONE_FILES = 0x00000400,
    CLONE_SIGHAND = 0x00000800,
    CLONE_PTRACE = 0x00002000,
    CLONE_VFORK = 0x00004000,
    CLONE_PARENT = 0x00008000,
    CLONE_THREAD = 0x00010000,
    CLONE_SYSVSEM = 0x00040000,
    CLONE_SETTLS = 0x00080000,
    CLONE_PARENT_SETTID = 0x00100000,
    CLONE_CHILD_CLEARTID = 0x00200000,
    CLONE_DETACHED = 0x00400000,
    CLONE_UNTRACED = 0x00800000,
    CLONE_CHILD_SETTID = 0x01000000,
    CLONE_IO = 0x80000000,
};

volatile System_Bool System_Thread_sigiset = false;

System_Thread System_Thread_create(function_System_Thread_main function, ...) {
    System_arguments args;
    System_arguments_start(args, function);
    System_Var argv[System_arguments_Limit_VALUE];
    System_Size argc = stack_System_arguments_get(args, argv);
    System_arguments_end(args);
    return System_Thread_create__arguments(function, argc, argv);
}

static void System_Thread_sigchild(System_Signal_Number number, System_Signal_Info info, System_Var context) {
    System_Console_writeLine("{0:string}: number {1:uint32}, errno {2:uint32}, code {3:uint32}"
        ", sigchild.pid {4:int32}, sigchild.status {5:int32}, sigchild.value0 {6:uint}, sigchild.value1 {7:uint}", 8,
        System_Signal_Number_toString(number), info->number, info->errno, info->code, 
        info->sigchild.pid, info->sigchild.status, info->sigchild.value, info->sigchild.value1);
}

System_Thread System_Thread_create__arguments(function_System_Thread_main function, System_Size argc, System_Var argv[]) {

    System_Var tls = System_Thread_createStorage();

    System_Var stack = System_Syscall_mmap(STACK_SIZE, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, 
        System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous | System_Memory_MapFlags_Stack | System_Memory_MapFlags_GrowsDown);

    if (!stack) return 0; // throw

    System_Thread that = System_Memory_allocClass(typeof(System_Thread));
    that->stack = stack;
    that->tls = tls;

    System_Size * stack_top = stack + STACK_SIZE;

    if (!argc) --stack_top;
    else
        for (System_Size i = argc; i > 0; --i)
            *(--stack_top) = (System_Size)argv[i - 1];

    *(--stack_top) = (System_Size)argc;
    *(--stack_top) = (System_Size)function;
    *(--stack_top) = (System_Size)that;
    *(--stack_top) = (System_Size)System_Thread_boot;

    if (!System_Thread_sigiset) {
        System_Signal_unblock__number(System_Signal_Number_SIGCHILD);
        System_IntPtr signal_flags = System_Signal_Flags_RESTART;
        #if !defined(use_System_Thread_SIGCHILD)
        signal_flags = System_Signal_Flags_NOCHILDSTOP | System_Signal_Flags_NOCHILDWAIT;
        #endif
        #if DEBUG == DEBUG_System_Thread
        System_Signal_act__flags(System_Signal_Number_SIGCHILD, System_Thread_sigchild, signal_flags);
        #else
        System_Signal_handle__flags(System_Signal_Number_SIGCHILD, function_System_Signal_handler_IGNORE, signal_flags);
        #endif
        System_Thread_sigiset = true;
    }

    System_IntPtr flags = CLONE_SIGHAND | CLONE_VM | CLONE_FS | CLONE_FILES | (!tls ? 0 : CLONE_SETTLS) | CLONE_PARENT_SETTID;
    #if defined(use_System_Thread_SIGCHILD)
    flags |= System_Signal_Number_SIGCHILD; /* CLONE_CHILD_CLEARTID */
    #else
    flags |= CLONE_THREAD;
    #endif
    System_Thread_TID reture = System_Syscall_clone__full(flags, stack_top, &that->threadId, !tls ? null : &tls, null);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) {
        System_Console_writeLine("System_Thread_create Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
        return null;
    }
    #if DEBUG == DEBUG_System_Thread
    System_Console_writeLine("System_Thread_create: {0:int32}", 1, that->threadId);
    #endif
    return that;
}

void System_Thread_sleep(System_Size seconds) {
    struct System_TimeSpan time = { .sec = seconds, .usec = 0, };
    System_Syscall_nanosleep(&time, &time);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Thread_sleep Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Thread_millisleep(System_Size milliseconds) {
    struct System_TimeSpan time = { .sec = 0, .usec = milliseconds * 1000 * 1000, };
    System_Syscall_nanosleep(&time, &time);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Thread_millisleep Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Thread_microsleep(System_Size microseconds) {
    struct System_TimeSpan time = { .sec = 0, .usec = microseconds * 1000, };
    System_Syscall_nanosleep(&time, &time);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Thread_microsleep Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

void System_Thread_nanosleep(System_Size nanoseconds) {
    struct System_TimeSpan time = { .sec = 0, .usec = nanoseconds, };
    System_Syscall_nanosleep(&time, &time);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) System_Console_writeLine("System_Thread_nanosleep Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
}

enum {
    WNOHANG = 1, /* Don't block waiting.  */
    WUNTRACED = 2,
    WSTOPPED = 2, /* Report stopped child (same as WUNTRACED). */
    WEXITED = 4,
    WCONTINUED = 8, /* Report continued child.  */
    WNOWAIT = 0x01000000,   /* Don't reap, just poll status.  */
    WTHREAD = 0x20000000,
    WALL = 0x40000000,   /* Wait for any child.  */
    WCLONE = 0x80000000, /* Wait for cloned process.  */
};

enum {
    WAITID_ALL, /* Wait for any child.  */
    WAITID_TID, /* Wait for specified process.  */
    WAITID_GID  /* Wait for members of process group.  */
};

System_Bool System_Thread_join(System_Thread that) {
    return System_Thread_join__dontwait(that, false);
}

System_Bool System_Thread_join__dontwait(System_Thread that, System_Bool dontwait) {

#if defined(use_System_Thread_SIGCHILD)

    if (that->threadId) {
        System_IntPtr status = 0;
        System_IntPtr reture = System_Syscall_wait(that->threadId, &status, dontwait);
        if (reture == that->threadId) that->returnValue = status >> 8;

        System_ErrorCode errno = System_Syscall_get_Error();
        if (errno) {
            System_Console_writeLine("System_Thread_join {0:uint} Error: {1:string}", 2, that->threadId, enum_getName(typeof(System_ErrorCode), errno));
            that->threadId = 0;
            return true;
        }
        if (reture == that->threadId) {
            that->threadId = 0;
            return true;
        }
        return false;
    }

#else /* if !defined(use_System_Thread_SIGCHILD) */

    System_Atomic_fence();
    while (!System_Atomic_expect__int32((atomic System_Int32 *)&that->threadId, 0, 0)) {
        if (dontwait) return false;
        System_Thread_yield();
        System_Atomic_fence();
    }

#endif

#if DEBUG == DEBUG_System_Thread
    System_Console_write__string("System_Thread_join: was terminated\n");
#endif
    return true;
}

#endif