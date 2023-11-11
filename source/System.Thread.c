/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Thread)
#include <min/System.Thread.h>
#endif
#if !defined(code_System_Thread)
#define code_System_Thread

struct System_Type System_ThreadType = { .base = { .type = typeof(System_Type) }, .name = "Thread", .size = sizeof(struct System_Thread) };

enum {
    STACK_SIZE = (8 * 1024 * 1024)
};

enum {
    CLONE_VM = 0x00000100,
    CLONE_FS = 0x00000200,
    CLONE_FILES = 0x00000400,
    CLONE_SIGHAND = 0x00000800,
    CLONE_PARENT = 0x00008000,
    CLONE_THREAD = 0x00010000,
    CLONE_IO = 0x80000000,
};

System_Bool System_Thread_sigiset = false;

System_Thread System_Thread_create(function_System_Thread_main function, ...) {
    System_arguments args;
    System_arguments_start(args, function);
    System_Var argv[System_arguments_Limit_VALUE];
    System_Size argc = stack_System_arguments_get(args, argv);
    System_arguments_end(args);
    return System_Thread_create__arguments(function, argc, argv);
}

System_Thread System_Thread_create__arguments(function_System_Thread_main function, System_Size argc, System_Var argv[]) {

    System_Var stack = System_Syscall_mmap(STACK_SIZE, System_Memory_PageFlags_Read | System_Memory_PageFlags_Write, 
        System_Memory_MapFlags_Private | System_Memory_MapFlags_Anonymous | System_Memory_MapFlags_Stack | System_Memory_MapFlags_GrowsDown);

    if (!stack) return 0; // throw

    System_Size * stack_top = stack + STACK_SIZE;

    if (!argc) --stack_top;
    else
        for (System_Size i = argc; i > 0; --i)
            *(--stack_top) = (System_Size)argv[i - 1];

    *(--stack_top) = (System_Size)argc;
    *(--stack_top) = (System_Size)function;
    *(--stack_top) = (System_Size)System_Thread_boot;

    if (!System_Thread_sigiset) {
        System_Signal_unblock__number(System_Signal_Number_SIGCHILD);
        System_Signal_handle(System_Signal_Number_SIGCHILD, function_System_Signal_handler_DEFAULT);
        System_Thread_sigiset = true;
    }

    System_SIntPtr reture = System_Syscall_clone(CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_IO | System_Signal_Number_SIGCHILD, stack_top);
    System_ErrorCode errno = System_Syscall_get_Error();
    if (errno) {
        System_Console_writeLine("System_Thread_create Error: {0:uint}", 1, errno);
        return null;
    }
    System_Thread that = System_Memory_allocClass(typeof(System_Thread));
    that->threadId = reture;
    that->isRunning = true;
    return that;
}

void System_Thread_sleep(System_Size seconds) {
    struct System_TimeSpan time = { .sec = seconds, .usec = 0, };
    System_Syscall_nanosleep(&time, &time);
}

enum {
    WNOHANG = 1, /* Don't block waiting.  */
    WSTOPPED = 2, /* Report stopped child (same as WUNTRACED). */
    WCONTINUED = 8, /* Report continued child.  */
    WALL = 0x40000000,   /* Wait for any child.  */
    WCLONE = 0x80000000, /* Wait for cloned process.  */
};

System_Bool System_Thread_join(System_Thread that) {
    return System_Thread_join__dontwait(that, false);
}

/* Now look, in System_Thread, if you join one, you want to wait until this ends. */

System_Bool System_Thread_join__dontwait(System_Thread that, System_Bool dontwait) {
    Debug_assert(that);

    if (that->threadId) {
        System_IntPtr status = 0;
        System_SIntPtr reture = System_Syscall_wait(that->threadId, &status, dontwait, null);
        that->returnValue = status >> 8;
        System_ErrorCode errno = System_Syscall_get_Error();
        if (errno) {
            System_Console_writeLine("System_Thread_join Error: {0:string}", 1, enum_getName(typeof(System_ErrorCode), errno));
            that->isRunning = false;
            that->threadId = 0;
            return true;
        }
        return reture ? true : false;
    }
    that->isRunning = false;
    that->threadId = 0;
    /*System_Console_writeLine("System_Thread_join status {0:uint:hex}, reture {1:uint:hex}, isRunning {2:bool}, returnValue: {3:uint:hex}", 4, 
        status, reture, that->isRunning, that->returnValue);*/
    return true;
}

void System_Thread_yield(void) {
    System_Syscall_sched_yield();
}

#endif