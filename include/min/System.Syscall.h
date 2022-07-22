/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Error)
#include "System.Error.h"
#endif
#if !defined(have_System_Syscall_command)
#include "System.Syscall.command.h"
#endif
#if !defined(have_System_Syscall)
#define have_System_Syscall

export struct System_Type  System_SyscallType;

import System_IntPtr  System_Syscall_call00(System_Syscall_command number);
import System_IntPtr  System_Syscall_call01(System_Syscall_command number, System_IntPtr arg1);
import System_IntPtr  System_Syscall_call02(System_Syscall_command number, System_IntPtr arg1, System_IntPtr arg2);
import System_IntPtr  System_Syscall_call03(System_Syscall_command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3);
import System_IntPtr  System_Syscall_call04(System_Syscall_command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4);
import System_IntPtr  System_Syscall_call05(System_Syscall_command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4, System_IntPtr arg5);
import System_IntPtr  System_Syscall_call06(System_Syscall_command number, System_IntPtr arg1, System_IntPtr arg2, System_IntPtr arg3, System_IntPtr arg4, System_IntPtr arg5, System_IntPtr arg6);

#if defined(using_System)
#define Syscall_call00  System_Syscall_call00
#define Syscall_call01  System_Syscall_call01
#define Syscall_call02  System_Syscall_call02
#define Syscall_call03  System_Syscall_call03
#define Syscall_call04  System_Syscall_call04
#define Syscall_call05  System_Syscall_call05
#define Syscall_call06  System_Syscall_call06
#endif

export thread System_Error System_Syscall_error;

export void  System_Syscall_set_Error(System_Error error);
export System_Error  System_Syscall_get_Error();
export void  System_Syscall_terminate(System_Size code)  noreturn;


struct System_Syscall_stat_timestamp {

    System_Int64 sec;
    System_IntPtr nsec;
};


struct System_Syscall_stat {

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
    struct System_Syscall_stat_timestamp accessTime;
    struct System_Syscall_stat_timestamp modifyTime;
    struct System_Syscall_stat_timestamp changeTime;
    System_IntPtr __reserved[3];

};

export System_Var  System_Syscall_open(System_String8 fileName, System_IntPtr flags, System_IntPtr mode);
export System_Var  System_Syscall_openat(System_Var directoryPtr, System_String8 fileName, System_IntPtr flags, System_IntPtr mode);
export System_Size  System_Syscall_read(System_Var filePtr, const void  * buf, System_Size count);
export System_Size  System_Syscall_write(System_Var filePtr, const void  * buf, System_Size count);
export System_Size  System_Syscall_lseek(System_Var filePtr, System_Size offset, System_IntPtr whence);
export void  System_Syscall_fsync(System_Var filePtr);
export void  System_Syscall_close(System_Var filePtr);
export void  System_Syscall_fstatat(System_Var directoryPtr, const System_String8 pathName, struct System_Syscall_stat  * that, System_IntPtr flags);

export System_Var  System_Syscall_mmap(System_Size length, System_IntPtr pageflags, System_IntPtr mapflags, System_Var file, System_IntPtr offset);
export void  System_Syscall_munmap(System_Var address, System_Size length);

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
#endif

#endif
