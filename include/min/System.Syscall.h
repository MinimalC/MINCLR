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

export thread System_ErrorCode System_Syscall_error;

export void  System_Syscall_set_Error(System_ErrorCode error);
export System_ErrorCode  System_Syscall_get_Error();
export void  System_Syscall_terminate(System_Size code)  noreturn;


typedef struct System_Syscall_timespec {

    System_Int64 sec;
    System_Int64 nsec;

} * System_Syscall_timespec;

typedef struct System_Syscall_stat {

    System_UInt64 deviceId;
    System_UInt64 iNodeId;
    System_UInt64 hardlinks;
    System_UInt32 mode;
    System_UInt32 userId;
    System_UInt32 groupId;
    System_UInt32 __padding1;

    System_UInt64 isDevice;
    System_Int64 size;
    System_Int64 bulkSize;
    System_Int64 blocks;
    struct System_Syscall_timespec accessTime;
    struct System_Syscall_timespec modifyTime;
    struct System_Syscall_timespec changeTime;
    System_IntPtr __reserved[3];

} * System_Syscall_stat;

typedef System_Var  System_Syscall_StandardFile;

#define System_Syscall_StandardFile_STDIN   ((System_Var)0)
#define System_Syscall_StandardFile_STDOUT  ((System_Var)1)
#define System_Syscall_StandardFile_STDERR  ((System_Var)2)
#define System_Syscall_StandardFile_CurrentWorkingDirectory  ((System_Var)-100)

export System_Var  System_Syscall_open(System_String8 fileName, System_IntPtr flags, System_IntPtr mode);
export System_Var  System_Syscall_openat(System_Var directoryPtr, System_String8 fileName, System_IntPtr flags, System_IntPtr mode);
export System_Size  System_Syscall_read(System_Var filePtr, const System_Var buffer, System_Size count);
export System_Size  System_Syscall_write(System_Var filePtr, const System_Var buffer, System_Size count);
export System_Size  System_Syscall_lseek(System_Var filePtr, System_Size offset, System_IntPtr whence);
export void  System_Syscall_fsync(System_Var filePtr);
export void  System_Syscall_close(System_Var filePtr);
export void  System_Syscall_fstatat(System_Var directoryPtr, const System_String8 pathName, System_Syscall_stat that, System_IntPtr flags);

export System_Var  System_Syscall_mmap(System_Size length, System_IntPtr pageflags, System_IntPtr mapflags);
export System_Var  System_Syscall_mmap__file(System_Size length, System_IntPtr pageflags, System_IntPtr mapflags, System_Var file, System_IntPtr offset);
export System_Var  System_Syscall_mmap__full(System_IntPtr initialAddress, System_Size length, System_IntPtr pageflags, System_IntPtr mapflags, System_Var file, System_IntPtr offset);
export void  System_Syscall_munmap(System_Var address, System_Size length);
export void  System_Syscall_mprotect(System_Var address, System_Size length, System_IntPtr flags);

export void  System_Syscall_nanosleep(System_Syscall_timespec request, System_Syscall_timespec remain);

export System_SIntPtr  System_Syscall_clone(System_IntPtr flags, System_Var stack);
export System_SIntPtr  System_Syscall_wait(System_SIntPtr id, System_IntPtr * status, System_IntPtr flags, System_Var usage);
export void  System_Syscall_sched_yield(void);

export void  System_Syscall_sigaction(System_SIntPtr signal, System_Var action, System_Var old);
export void  System_Syscall_sigprocmask(System_SIntPtr how, System_Var set, System_Var old, System_IntPtr setsize);

export System_IntPtr  System_Syscall_socket(System_IntPtr addressFamily, System_IntPtr socketType, System_IntPtr protocol);
export void  System_Syscall_bind(System_IntPtr socketId, System_Var socketAddress, System_Size socketAddressLength);
export void  System_Syscall_listen(System_IntPtr socketId, System_Size backlog);
export System_IntPtr  System_Syscall_accept(System_IntPtr socketId, System_Var socketAddress, System_Size * addressLength, System_IntPtr flags);
export void  System_Syscall_getsockname(System_IntPtr socketId, System_Var socketAddress, System_Size * addressLength);
export void  System_Syscall_getpeername(System_IntPtr socketId, System_Var socketAddress, System_Size * addressLength);
export void  System_Syscall_getsockopt(System_IntPtr socketId, System_IntPtr level, System_IntPtr optionName, System_Var optionValue, System_Size * optionLength);
export void  System_Syscall_setsockopt(System_IntPtr socketId, System_IntPtr level, System_IntPtr optionName, System_Var optionValue, System_Size optionLength);
export void  System_Syscall_send(System_IntPtr socketId, System_Var buffer, System_Size length, System_IntPtr flags);
export void  System_Syscall_sendto(System_IntPtr socketId, System_Var buffer, System_Size length, System_IntPtr flags, System_Var socketAddress, System_Size addressLength);
export void  System_Syscall_sendmsg(System_IntPtr socketId, System_Var messageHeader, System_IntPtr flags);
export System_IntPtr  System_Syscall_recv(System_IntPtr socketId, System_Var buffer, System_Size length, System_IntPtr flags);
export System_IntPtr  System_Syscall_recvfrom(System_IntPtr socketId, System_Var buffer, System_Size length, System_IntPtr flags, System_Var socketAddress, System_Size addressLength);
export System_Size  System_Syscall_recvmsg(System_IntPtr socketId, System_Var messageHeader, System_IntPtr flags);
export System_Size  System_Syscall_ppoll(System_Var pds, System_Size count, System_Syscall_timespec timeout, System_Var sigmask);

#if defined(using_System)
#define SyscallType  System_SyscallType
#define Syscall_error  System_Syscall_error
#define Syscall_terminate  System_Syscall_terminate
#define Syscall_open  System_Syscall_open
#define Syscall_openat  System_Syscall_openat
#define Syscall_read  System_Syscall_read
#define Syscall_write  System_Syscall_write
#define Syscall_lseek  System_Syscall_lseek
#define Syscall_fsync  System_Syscall_fsync
#define Syscall_close  System_Syscall_close
#define Syscall_mmap  System_Syscall_mmap
#define Syscall_munmap  System_Syscall_munmap

#define Syscall_StandardFile  System_Syscall_StandardFile
#define Syscall_StandardFile_STDIN  System_Syscall_StandardFile_STDIN
#define Syscall_StandardFile_STDOUT  System_Syscall_StandardFile_STDOUT
#define Syscall_StandardFile_STDERR  System_Syscall_StandardFile_STDERR
#endif
#endif
