/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_ErrorCode)
#include "System.ErrorCode.h"
#endif
#if !defined(have_System_Syscall_Command)
#include "System.Syscall.Command.h"
#endif
#if !defined(have_System_DateTime)
#include "System.DateTime.h"
#endif
#if !defined(have_System_Syscall)
#define have_System_Syscall

export struct System_Type  System_SyscallType;

import System_IntPtr  System_Syscall_call00(System_Syscall_Command number);
import System_IntPtr  System_Syscall_call01(System_Syscall_Command number, System_IntPtr arg1);
import System_IntPtr  System_Syscall_call02(System_Syscall_Command number, System_IntPtr arg1, System_IntPtr arg2);
import System_IntPtr  System_Syscall_call03(System_Syscall_Command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3);
import System_IntPtr  System_Syscall_call04(System_Syscall_Command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4);
import System_IntPtr  System_Syscall_call05(System_Syscall_Command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4, System_IntPtr arg5);
import System_IntPtr  System_Syscall_call06(System_Syscall_Command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4, System_IntPtr arg5, System_IntPtr arg6);

#if defined(using_System)
#define Syscall_call00  System_Syscall_call00
#define Syscall_call01  System_Syscall_call01
#define Syscall_call02  System_Syscall_call02
#define Syscall_call03  System_Syscall_call03
#define Syscall_call04  System_Syscall_call04
#define Syscall_call05  System_Syscall_call05
#define Syscall_call06  System_Syscall_call06
#endif

export System_ErrorCode  System_Syscall_error;

export void  System_Syscall_set_Error(System_ErrorCode error);
export System_ErrorCode  System_Syscall_get_Error();

export void  System_Syscall_terminate(System_Size code)  noreturn;

export void  System_Syscall_gettimeofday(System_TimeSpan value, System_TimeZone zone);
export System_Time  System_Syscall_time(void);

typedef System_IntPtr  System_Syscall_StandardFile;
enum {
    System_Syscall_StandardFile_STDIN,
    System_Syscall_StandardFile_STDOUT,
    System_Syscall_StandardFile_STDERR,
    System_Syscall_StandardFile_CurrentWorkingDirectory = -100,
};

typedef struct System_Syscall_status {
    System_UInt64 containerId;
    System_UInt64 iNodeId;
    System_UInt64 hardlinks;
    System_UInt32 mode;
    System_UInt32 userId;
    System_UInt32 groupId;
    System_UInt32 __padding1;

    System_UInt64 deviceId;
    System_Int64 size;
    System_Int64 bulkSize;
    System_Int64 blocks;
    struct System_TimeSpan accessTime;
    struct System_TimeSpan modifyTime;
    struct System_TimeSpan changeTime;

    System_IntPtr __reserved[3];
} * System_Syscall_status;

export System_IntPtr  System_Syscall_open(System_String8 fileName, System_IntPtr flags, System_IntPtr mode);
export System_IntPtr  System_Syscall_openat(System_IntPtr directoryId, System_String8 fileName, System_IntPtr flags, System_IntPtr mode);
export System_IntPtr  System_Syscall_dup2(System_IntPtr fileId, System_IntPtr newId);
export System_Size  System_Syscall_read(System_IntPtr fileId, const System_Var buffer, System_Size count);
export System_Size  System_Syscall_write(System_IntPtr fileId, const System_Var buffer, System_Size count);
export System_Size  System_Syscall_lseek(System_IntPtr fileId, System_Size offset, System_IntPtr whence);
export void  System_Syscall_ftruncate(System_IntPtr fileId, System_Size length);
export void  System_Syscall_fsync(System_IntPtr fileId);
export void  System_Syscall_close(System_IntPtr fileId);
export void  System_Syscall_fstat(System_IntPtr fileId, System_Var stat);
export void  System_Syscall_fstatat(System_IntPtr directoryId, const System_String8 pathName, System_Var stat, System_IntPtr flags);
export void  System_Syscall_unlink(System_String8 fileName);
export void  System_Syscall_rmdir(System_String8 directoryName);
export void  System_Syscall_getcwd(System_String8 buffer, System_Size length);
export void  System_Syscall_readlink(System_String8 linkName, System_String8 buffer, System_Size length);
export void  System_Syscall_chdir(System_String8 path);
export void  System_Syscall_mkdir(System_String8 path, System_IntPtr mode);
export System_Size  System_Syscall_getdents64(System_IntPtr directoryId, System_String8 buffer, System_Size length);

typedef System_IntPtr  System_Syscall_MSync;
enum {
    System_Syscall_MSync_Async = 1,
    System_Syscall_MSync_Invalidate = 2,
    System_Syscall_MSync_Sync = 4,
};

typedef System_IntPtr  System_Syscall_MRemap;
enum {
    System_Syscall_MRemap_MayMove = 1,
    System_Syscall_MRemap_Fixed = 2,
    System_Syscall_MRemap_DontUnmap = 4,
};

export System_Var  System_Syscall_mmap(System_Size length, System_IntPtr pageflags, System_IntPtr mapflags);
export System_Var  System_Syscall_mmap__file(System_Size length, System_IntPtr pageflags, System_IntPtr mapflags, System_IntPtr file, System_IntPtr offset);
export System_Var  System_Syscall_mmap__full(System_Var hint, System_Size length, System_IntPtr pageflags, System_IntPtr mapflags, System_IntPtr file, System_IntPtr offset);
export void  System_Syscall_mmap__debug(void);
export void  System_Syscall_munmap(System_Var address, System_Size length);
export void  System_Syscall_mprotect(System_Var address, System_Size length, System_IntPtr flags);
export System_Var  System_Syscall_mremap(System_Var old_address, System_Size old_length, System_Size new_length, System_IntPtr flags);
export void  System_Syscall_msync__flags(System_Var address, System_Size length, System_IntPtr flags);

export void  System_Syscall_nanosleep(System_TimeSpan request, System_TimeSpan remain);

typedef System_Int32  System_Thread_TID;
export System_Thread_TID  System_Syscall_clone(System_IntPtr flags, System_Var stack);
export System_Thread_TID  System_Syscall_clone__tls(System_IntPtr flags, System_Var stack, System_Var tls);
export System_Thread_TID  System_Syscall_clone__full(System_IntPtr flags, System_Var stack, System_Var parent_threadId, System_Var tls, System_Var child_threadId);
export System_Thread_TID  System_Syscall_wait(System_Thread_TID id, System_IntPtr * status, System_IntPtr flags);
export System_Thread_TID  System_Syscall_waitid(System_IntPtr idType, System_Thread_TID id, System_Var siginfo, System_IntPtr options);
export System_Thread_TID  System_Syscall_fork(void);
export void  System_Syscall_execve(System_String8 filename, System_String8 * argv, System_String8 * envv);
export void  System_Syscall_execveat(System_IntPtr dirId, System_String8 pathname, System_String8 * argv, System_String8 * envv, System_IntPtr flags);

export void  System_Syscall_sigaction(System_IntPtr signal, System_Var action, System_Var old);
export void  System_Syscall_sigprocmask(System_IntPtr how, System_Var set, System_Var old, System_IntPtr setsize);
import void  System_Syscall_sigreturn(void);
export void  System_Syscall_sigqueue(System_Thread_TID id, System_IntPtr signal, System_IntPtr value);
export System_IntPtr  System_Syscall_sigwait(System_Var set, System_Var info, System_TimeSpan timeout);
export void  System_Syscall_sched_yield(void);

export System_Thread_TID  System_Thread_PID;
export System_Thread_TID  System_Syscall_getpid(void);
export System_Thread_TID  System_Syscall_gettid(void);
export void  System_Syscall_prctl(System_IntPtr option, System_IntPtr arg1);
export void  System_Syscall_prctl2(System_IntPtr option, System_IntPtr arg1, System_IntPtr arg2);
export void  System_Syscall_prctl3(System_IntPtr option, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3);
export void  System_Syscall_prctl4(System_IntPtr option, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4);
export void  System_Syscall_arch_prctl(System_IntPtr option, System_IntPtr arg);

typedef System_IntPtr System_File_ControlCommand;
enum {
    System_File_ControlCommand_DuplicateFileDescriptor = 0,
    System_File_ControlCommand_GetFileDescriptorFlags = 1,
    System_File_ControlCommand_SetFileDescriptorFlags = 2,
    System_File_ControlCommand_GetFileStatusFlags = 3,
    System_File_ControlCommand_SetFileStatusFlags = 4,
};

export System_IntPtr  System_Syscall_fcntl(System_IntPtr fileId, System_IntPtr command);
export System_IntPtr  System_Syscall_fcntl1(System_IntPtr fileId, System_IntPtr command, System_Var arg1);
export System_IntPtr  System_Syscall_fcntl2(System_IntPtr fileId, System_IntPtr command, System_IntPtr arg1, System_Var arg2);
export System_IntPtr  System_Syscall_ioctl(System_IntPtr fileId, System_IntPtr request);
export System_IntPtr  System_Syscall_ioctl1(System_IntPtr fileId, System_IntPtr request, System_Var arg1);
export System_IntPtr  System_Syscall_ioctl2(System_IntPtr fileId, System_IntPtr request, System_IntPtr arg1, System_Var arg2);

typedef System_Int32  Network_Socket_SID;
export Network_Socket_SID  System_Syscall_socket(System_IntPtr addressFamily, System_IntPtr socketType, System_IntPtr protocol);
export void  System_Syscall_bind(Network_Socket_SID socketId, System_Var socketAddress, System_Size socketAddressLength);
export void  System_Syscall_listen(Network_Socket_SID socketId, System_Size backlog);
export Network_Socket_SID  System_Syscall_accept(Network_Socket_SID socketId, System_Var socketAddress, System_Size * addressLength, System_IntPtr flags);
export void  System_Syscall_getsockname(Network_Socket_SID socketId, System_Var socketAddress, System_Size * addressLength);
export void  System_Syscall_getpeername(Network_Socket_SID socketId, System_Var socketAddress, System_Size * addressLength);
export void  System_Syscall_getsockopt(Network_Socket_SID socketId, System_IntPtr level, System_IntPtr optionName, System_Var optionValue, System_Size * optionLength);
export void  System_Syscall_setsockopt(Network_Socket_SID socketId, System_IntPtr level, System_IntPtr optionName, System_Var optionValue, System_Size optionLength);
export void  System_Syscall_send(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags);
export void  System_Syscall_sendto(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags, System_Var socketAddress, System_Size addressLength);
export void  System_Syscall_sendmsg(Network_Socket_SID socketId, System_Var messageHeader, System_IntPtr flags);
export System_Size  System_Syscall_recv(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags);
export System_Size  System_Syscall_recvfrom(Network_Socket_SID socketId, System_Var buffer, System_Size length, System_IntPtr flags, System_Var socketAddress, System_Size addressLength);
export System_Size  System_Syscall_recvmsg(Network_Socket_SID socketId, System_Var messageHeader, System_IntPtr flags);
export System_Size  System_Syscall_pselect(System_Size count, System_Var read, System_Var write, System_Var except, System_TimeSpan timeout, System_Var sigmask);
export System_Size  System_Syscall_ppoll(System_Var pds, System_Size count, System_TimeSpan timeout, System_Var sigmask);

#if defined(using_System)
#define SyscallType  System_SyscallType
#define Syscall_error  System_Syscall_error
#define Syscall_terminate  System_Syscall_terminate
#define Syscall_gettimeofday  System_Syscall_gettimeofday
#define Syscall_time  System_Syscall_time
#define Syscall_open  System_Syscall_open
#define Syscall_openat  System_Syscall_openat
#define Syscall_dup  System_Syscall_dup
#define Syscall_read  System_Syscall_read
#define Syscall_write  System_Syscall_write
#define Syscall_lseek  System_Syscall_lseek
#define Syscall_ftruncate  System_Syscall_ftruncate
#define Syscall_fsync  System_Syscall_fsync
#define Syscall_close  System_Syscall_close
#define Syscall_fstat  System_Syscall_fstat
#define Syscall_fstatat  System_Syscall_fstatat
#define Syscall_unlink  System_Syscall_unlink
#define Syscall_rmdir  System_Syscall_rmdir
#define Syscall_getcwd  System_Syscall_getcwd
#define Syscall_readlink  System_Syscall_readlink
#define Syscall_chdir  System_Syscall_chdir
#define Syscall_mkdir  System_Syscall_mkdir
#define Syscall_getdents64  System_Syscall_getdents64
#define Syscall_mmap  System_Syscall_mmap
#define Syscall_mmap__file  System_Syscall_mmap__file
#define Syscall_mmap__full  System_Syscall_mmap__full
#define Syscall_mmap__debug  System_Syscall_mmap__debug
#define Syscall_munmap  System_Syscall_munmap
#define Syscall_mprotect  System_Syscall_mprotect
#define Syscall_mremap  System_Syscall_mremap
#define Syscall_msync__flags  System_Syscall_msync__flags
#define Syscall_nanosleep  System_Syscall_nanosleep

#define Syscall_StandardFile  System_Syscall_StandardFile
#define Syscall_StandardFile_STDIN  System_Syscall_StandardFile_STDIN
#define Syscall_StandardFile_STDOUT  System_Syscall_StandardFile_STDOUT
#define Syscall_StandardFile_STDERR  System_Syscall_StandardFile_STDERR
#endif
#endif
