/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Atomic)
#include <min/System.Atomic.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(code_System_Syscall_Command)
#define code_System_Syscall_Command

/** struct System_Syscall_Command  **/

struct System_Type_FieldInfo  System_Syscall_CommandTypeFields[] = {
#if defined(have_Linux)

#if defined(have_ARM)
#include <min/ARM/GNU.Linux/System.Syscall.Command.asm.h>

#elif defined(have_AMD64)
#include <min/AMD64/GNU.Linux/System.Syscall.Command.asm.h>

#elif defined(have_X86)
#include <min/X86/GNU.Linux/System.Syscall.Command.asm.h>

#else
#error Architecture not implemented
#endif

#else
#error Platform not implemented
#endif
};

struct System_Type System_Syscall_CommandType = { .base = { .type = typeof(System_Type) },
    .name = "Syscall.Command",
    .size = sizeof(System_Syscall_Command),
	.fields = {
        .value = &System_Syscall_CommandTypeFields, .length = sizeof_array(System_Syscall_CommandTypeFields),
    },
};

#endif
#if !defined(code_System_ErrorCode)
#define code_System_ErrorCode

/** struct System_ErrorCode  **/

struct System_Type_FieldInfo  System_ErrorCodeTypeFields[] = {
#include <min/System.ErrorCode.generic.asm.h>
};

struct System_Type System_ErrorCodeType = { .base = { .type = typeof(System_Type) },
    .name = "ErrorCode",
    .size = sizeof(System_ErrorCode),
	.fields = {
        .value = &System_ErrorCodeTypeFields, .length = sizeof_array(System_ErrorCodeTypeFields),
    },
};

#endif
#if !defined(code_System_Syscall)
#define code_System_Syscall

/** struct System_Syscall  **/

struct System_Type System_SyscallType = { .base = { .type = typeof(System_Type) }, .name = "Syscall", };

System_ErrorCode System_Syscall_error = 0;

void System_Syscall_set_Error(const System_ErrorCode error) {
    System_Syscall_error = error;
}

System_ErrorCode System_Syscall_get_Error() {
    System_ErrorCode error = System_Syscall_error;
    System_Syscall_error = 0;
    return error;
}

void  System_Syscall_terminate(System_Size code)  {
    (void)System_Syscall_call01(System_Syscall_Command_exit, code);
    /* inline_unreachable... for noreturn just repeat: */
    (void)System_Syscall_terminate(code);
}

void  System_Syscall_gettimeofday(System_TimeSpan value, System_TimeZone zone) {
#if defined(use_System_Syscall_gettimeofday)
    (void)System_Syscall_call02(System_Syscall_Command_gettimeofday, (System_IntPtr)value, (System_IntPtr)zone);
#else
    extern int __vdso_gettimeofday(System_TimeSpan value, System_TimeZone zone) weak; __vdso_gettimeofday(value, zone);
#endif
}

System_SSize  System_Syscall_time(void) {
#if defined(use_System_Syscall_time)
    return System_Syscall_call01(System_Syscall_Command_time, null);
#else
    extern System_SSize __vdso_time(System_Var value) weak; return __vdso_time(null);
#endif
}

System_IntPtr  System_Syscall_open(System_String8 fileName, System_IntPtr flags, System_IntPtr mode) {
    return System_Syscall_call03(System_Syscall_Command_open, (System_IntPtr)fileName, flags, mode);
}

System_IntPtr  System_Syscall_openat(System_IntPtr directoryId, System_String8 fileName, System_IntPtr flags, System_IntPtr mode) {
    return System_Syscall_call04(System_Syscall_Command_openat, directoryId, (System_IntPtr)fileName, flags, mode);
}

System_Size  System_Syscall_read(System_IntPtr fileId, const System_Var buf, System_Size count) {
    return System_Syscall_call03(System_Syscall_Command_read, fileId, (System_IntPtr)buf, count);
}

System_Size  System_Syscall_write(System_IntPtr fileId, const System_Var buf, System_Size count) {
    return System_Syscall_call03(System_Syscall_Command_write, fileId, (System_IntPtr)buf, count);
}

System_Size  System_Syscall_lseek(System_IntPtr fileId, System_Size offset, System_IntPtr whence) {
    return System_Syscall_call03(System_Syscall_Command_lseek, fileId, offset, whence);
}

void  System_Syscall_ftruncate(System_IntPtr fileId, System_Size length) {
    (void)System_Syscall_call02(System_Syscall_Command_ftruncate, fileId, length);
}

void  System_Syscall_fsync(System_IntPtr fileId) {
    (void)System_Syscall_call01(System_Syscall_Command_fsync, fileId);
}

void  System_Syscall_close(System_IntPtr fileId) {
    (void)System_Syscall_call01(System_Syscall_Command_close, fileId);
}

void  System_Syscall_fstat(System_IntPtr fileId, System_Var stat) {
    (void)System_Syscall_call03(System_Syscall_Command_fstat, fileId, (System_IntPtr)stat, 0);
}

void  System_Syscall_fstatat(System_IntPtr directoryId, const System_String8 pathName, System_Var stat, System_IntPtr flags) {
    (void)System_Syscall_call04(System_Syscall_Command_fstatat, directoryId, (System_IntPtr)pathName, (System_IntPtr)stat, flags);
}

void System_Syscall_getcwd(System_String8 buffer, System_Size length) {
    (void)System_Syscall_call02(System_Syscall_Command_getcwd, (System_IntPtr)buffer, length);
}

void System_Syscall_chdir(System_String8 path) {
    (void)System_Syscall_call01(System_Syscall_Command_chdir, (System_IntPtr)path);
}

System_IntPtr System_Syscall_mkdir(System_String8 path, System_IntPtr mode) {
    return System_Syscall_call02(System_Syscall_Command_mkdir, (System_IntPtr)path, mode);
}

System_Size System_Syscall_getdents64(System_IntPtr directoryId, System_String8 buffer, System_Size length) {
    return System_Syscall_call03(System_Syscall_Command_getdents64, directoryId, (System_IntPtr)buffer, length);
}


__volatile__ System_SSize System_Syscall_mmapCount = 0;

System_Var  System_Syscall_mmap(System_Size length, System_IntPtr page, System_IntPtr map) {
    ++System_Syscall_mmapCount;
    return (System_Var)System_Syscall_call06(System_Syscall_Command_mmap, null, length, page, map, -1, 0);
}

System_Var  System_Syscall_mmap__file(System_Size length, System_IntPtr page, System_IntPtr map, System_IntPtr file, System_IntPtr offset) {
    ++System_Syscall_mmapCount;
    return (System_Var)System_Syscall_call06(System_Syscall_Command_mmap, null, length, page, map, file, offset);
}

System_Var  System_Syscall_mmap__full(System_Var hint, System_Size length, System_IntPtr page, System_IntPtr map, System_IntPtr file, System_IntPtr offset) {
    ++System_Syscall_mmapCount;
    return (System_Var)System_Syscall_call06(System_Syscall_Command_mmap, (System_IntPtr)hint, length, page, map, file, offset);
}

void  System_Syscall_munmap(System_Var address, System_Size length) {
    --System_Syscall_mmapCount;
    (void)System_Syscall_call02(System_Syscall_Command_munmap, (System_IntPtr)address, length);
}

void System_Syscall_mmap__debug(void) {
    if (System_Syscall_mmapCount) System_Console_debugLine("System_Syscall_mmap called {0:int} times without munmap.", 1, System_Syscall_mmapCount);
}

void  System_Syscall_mprotect(System_Var address, System_Size length, System_IntPtr flags) {
    (void)System_Syscall_call03(System_Syscall_Command_mprotect, (System_IntPtr)address, length, flags);
}

System_Var  System_Syscall_mremap(System_Var old_address, System_Size old_length, System_Size new_length, System_IntPtr flags) {
    return (System_Var)System_Syscall_call04(System_Syscall_Command_mremap, (System_IntPtr)old_address, (System_IntPtr)old_length, (System_IntPtr)new_length, flags);
}

void  System_Syscall_msync__flags(System_Var address, System_Size length, System_IntPtr flags) {
    (void)System_Syscall_call03(System_Syscall_Command_msync, (System_IntPtr)address, length, flags);
}


void  System_Syscall_nanosleep(System_TimeSpan request, System_TimeSpan remain) {
    (void)System_Syscall_call02(System_Syscall_Command_nanosleep, (System_IntPtr)request, (System_IntPtr)remain);
}


System_Thread_TID  System_Syscall_clone(System_IntPtr flags, System_Var stack) {
    return (System_Thread_TID)System_Syscall_call02(System_Syscall_Command_clone, flags, (System_IntPtr)stack);
}

System_Thread_TID  System_Syscall_clone__tls(System_IntPtr flags, System_Var stack, System_Var tls) {
    return (System_Thread_TID)System_Syscall_call05(System_Syscall_Command_clone, flags, (System_IntPtr)stack, null, (System_IntPtr)tls, null);
}

System_Thread_TID  System_Syscall_clone__full(System_IntPtr flags, System_Var stack, System_Var parent_threadId, System_Var tls, System_Var child_threadId) {
    return (System_Thread_TID)System_Syscall_call05(System_Syscall_Command_clone, flags, (System_IntPtr)stack, (System_IntPtr)parent_threadId, (System_IntPtr)tls, (System_IntPtr)child_threadId);
}

System_Thread_TID  System_Syscall_wait(System_Thread_TID id, System_IntPtr * status, System_IntPtr flags) {
    return System_Syscall_call04(System_Syscall_Command_wait4, id, (System_IntPtr)status, flags, null);
}

System_Thread_TID  System_Syscall_waitid(System_IntPtr idType, System_Thread_TID id, System_Var siginfo, System_IntPtr options) {
    return System_Syscall_call04(System_Syscall_Command_waitid, idType, id, (System_IntPtr)siginfo, options);
}

System_Thread_TID  System_Syscall_fork(void) {
    return System_Syscall_call00(System_Syscall_Command_fork);
}

void  System_Syscall_execve(System_String8 filename, System_String8 * argv, System_String8 * envv) {
    (void)System_Syscall_call03(System_Syscall_Command_execve, (System_IntPtr)filename, (System_IntPtr)argv, (System_IntPtr)envv);
}

void  System_Syscall_execveat(System_IntPtr dirId, System_String8 pathname, System_String8 * argv, System_String8 * envv, System_IntPtr flags) {
    (void)System_Syscall_call05(System_Syscall_Command_execveat, dirId, (System_IntPtr)pathname, (System_IntPtr)argv, (System_IntPtr)envv, flags);
}


void  System_Syscall_sigaction(System_IntPtr signal, System_Var action, System_Var old) {
    (void)System_Syscall_call03(System_Syscall_Command_rt_sigaction, signal, (System_IntPtr)action, (System_IntPtr)old);
}

void  System_Syscall_sigprocmask(System_IntPtr how, System_Var set, System_Var old, System_IntPtr setsize) {
    (void)System_Syscall_call04(System_Syscall_Command_rt_sigprocmask, how, (System_IntPtr)set, (System_IntPtr)old, setsize);
}

void  System_Syscall_sigqueue(System_Thread_TID id, System_IntPtr signal, System_IntPtr value) {
    (void)System_Syscall_call03(System_Syscall_Command_rt_sigqueueinfo, (System_IntPtr)id, signal, value);
}

System_IntPtr System_Syscall_sigwait(System_Var set, System_Var info, System_TimeSpan timeout) {
    return System_Syscall_call03(System_Syscall_Command_rt_sigtimedwait, (System_IntPtr)set, (System_IntPtr)info, (System_IntPtr)timeout);
}

void  System_Syscall_sched_yield(void) {
    (void)System_Syscall_call00(System_Syscall_Command_sched_yield);
}

System_Thread_TID  System_Thread_PID = 0;

System_Thread_TID  System_Syscall_getpid(void) {
    return (System_Thread_TID)System_Syscall_call00(System_Syscall_Command_getpid);
}

System_Thread_TID  System_Syscall_gettid(void) {
    return (System_Thread_TID)System_Syscall_call00(System_Syscall_Command_gettid);
}

void  System_Syscall_prctl(System_IntPtr option, System_IntPtr arg1) {
    (void)System_Syscall_prctl4(option, arg1, 0, 0, 0);
}
void  System_Syscall_prctl2(System_IntPtr option, System_IntPtr arg1, System_IntPtr arg2) {
    (void)System_Syscall_prctl4(option, arg1, arg2, 0, 0);
}
void  System_Syscall_prctl3(System_IntPtr option, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3) {
    (void)System_Syscall_prctl4(option, arg1, arg2, arg3, 0);
}
void  System_Syscall_prctl4(System_IntPtr option, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4) {
    (void)System_Syscall_call05(System_Syscall_Command_prctl, option, arg1, arg2, arg3, arg4);
}

void  System_Syscall_arch_prctl(System_IntPtr option, System_IntPtr arg1) {
    (void)System_Syscall_call02(System_Syscall_Command_arch_prctl, option, arg1);
}


System_IntPtr  System_Syscall_fcntl(System_IntPtr fileId, System_IntPtr command) {
    return (System_IntPtr)System_Syscall_call03(System_Syscall_Command_fcntl, fileId, command, 0);
}
System_IntPtr  System_Syscall_fcntl1(System_IntPtr fileId, System_IntPtr command, System_Var arg1) {
    return (System_IntPtr)System_Syscall_call03(System_Syscall_Command_fcntl, fileId, command, (System_IntPtr)arg1);
}
System_IntPtr  System_Syscall_fcntl2(System_IntPtr fileId, System_IntPtr command, System_IntPtr arg1, System_Var arg2) {
    return (System_IntPtr)System_Syscall_call04(System_Syscall_Command_fcntl, fileId, command, arg1, (System_IntPtr)arg2);
}

System_IntPtr  System_Syscall_ioctl(System_IntPtr fileId, System_IntPtr request) {
    return (System_IntPtr)System_Syscall_call03(System_Syscall_Command_ioctl, fileId, request, 0);
}
System_IntPtr  System_Syscall_ioctl1(System_IntPtr fileId, System_IntPtr request, System_Var arg1) {
    return (System_IntPtr)System_Syscall_call03(System_Syscall_Command_ioctl, fileId, request, (System_IntPtr)arg1);
}
System_IntPtr  System_Syscall_ioctl2(System_IntPtr fileId, System_IntPtr request, System_IntPtr arg1, System_Var arg2) {
    return (System_IntPtr)System_Syscall_call04(System_Syscall_Command_ioctl, fileId, request, arg1, (System_IntPtr)arg2);
}


Network_Socket_SID  System_Syscall_socket(System_IntPtr addressFamily, System_IntPtr socketType, System_IntPtr protocol) {
    return (System_IntPtr)System_Syscall_call03(System_Syscall_Command_socket, addressFamily, socketType, protocol);
}

void  System_Syscall_bind(Network_Socket_SID socketId, System_Var socketAddress, System_Size addressLength) {
    (void)System_Syscall_call03(System_Syscall_Command_bind, (System_IntPtr)socketId, (System_IntPtr)socketAddress, addressLength);
}

void  System_Syscall_listen(Network_Socket_SID socketId, System_Size backlog) {
    (void)System_Syscall_call02(System_Syscall_Command_listen, (System_IntPtr)socketId, backlog);
}

Network_Socket_SID  System_Syscall_accept(Network_Socket_SID socketId, System_Var socketAddress, System_Size * addressLength, System_IntPtr flags) {
    return (System_IntPtr)System_Syscall_call04(System_Syscall_Command_accept4, (System_IntPtr)socketId, (System_IntPtr)socketAddress, (System_IntPtr)addressLength, flags);
}

void  System_Syscall_getsockname(Network_Socket_SID socketId, System_Var socketAddress, System_Size * addressLength) {
    (void)System_Syscall_call03(System_Syscall_Command_getsockname, (System_IntPtr)socketId, (System_IntPtr)socketAddress, (System_IntPtr)addressLength);
}

void  System_Syscall_getpeername(Network_Socket_SID socketId, System_Var socketAddress, System_Size * addressLength) {
    (void)System_Syscall_call03(System_Syscall_Command_getpeername, (System_IntPtr)socketId, (System_IntPtr)socketAddress, (System_IntPtr)addressLength);
}

void  System_Syscall_getsockopt(Network_Socket_SID socketId, System_IntPtr level, System_IntPtr optionName, System_Var optionValue, System_Size * optionLength) {
    (void)System_Syscall_call05(System_Syscall_Command_getsockopt, (System_IntPtr)socketId, level, optionName, (System_IntPtr)optionValue, (System_IntPtr)optionLength);
}

void  System_Syscall_setsockopt(Network_Socket_SID socketId, System_IntPtr level, System_IntPtr optionName, System_Var optionValue, System_Size optionLength) {
    (void)System_Syscall_call05(System_Syscall_Command_setsockopt, (System_IntPtr)socketId, level, optionName, (System_IntPtr)optionValue, optionLength);
}

void  System_Syscall_send(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags) {
    (void)System_Syscall_sendto(socketId, buffer, length, flags, null, 0);
}

void  System_Syscall_sendto(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags, System_Var socketAddress, System_Size addressLength) {
    (void)System_Syscall_call06(System_Syscall_Command_sendto, (System_IntPtr)socketId, (System_IntPtr)buffer, length, flags, (System_IntPtr)socketAddress, addressLength);
}

void  System_Syscall_sendmsg(Network_Socket_SID socketId, System_Var messageHeader, System_IntPtr flags) {
    (void)System_Syscall_call03(System_Syscall_Command_sendmsg, (System_IntPtr)socketId, (System_IntPtr)messageHeader, flags);
}

System_Size  System_Syscall_recv(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags) {
    return System_Syscall_recvfrom(socketId, buffer, length, flags, null, 0);
}

System_Size  System_Syscall_recvfrom(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags, System_Var socketAddress, System_Size addressLength) {
    return System_Syscall_call06(System_Syscall_Command_recvfrom, (System_IntPtr)socketId, (System_IntPtr)buffer, length, flags, (System_IntPtr)socketAddress, addressLength);
}

System_Size  System_Syscall_recvmsg(Network_Socket_SID socketId, System_Var messageHeader, System_IntPtr flags) {
    return System_Syscall_call03(System_Syscall_Command_recvmsg, (System_IntPtr)socketId, (System_IntPtr)messageHeader, flags);
}

System_Size  System_Syscall_pselect(System_Size count, System_Var read, System_Var write, System_Var except, System_TimeSpan timeout, System_Var sigmask) {
    return System_Syscall_call06(System_Syscall_Command_pselect6, count, (System_IntPtr)read, (System_IntPtr)write, (System_IntPtr)except, (System_IntPtr)timeout, (System_IntPtr)sigmask);
}

System_Size  System_Syscall_ppoll(System_Var pds, System_Size count, System_TimeSpan timeout, System_Var sigmask) {
    return System_Syscall_call04(System_Syscall_Command_ppoll, (System_IntPtr)pds, count, (System_IntPtr)timeout, (System_IntPtr)sigmask);
}

#endif
