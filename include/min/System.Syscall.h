/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_error)
#include "System.error.h"
#endif
#if !defined(have_System_Syscall_command)
#include "System.Syscall.command.h"
#endif
#if !defined(have_System_Syscall)
#define have_System_Syscall

export struct System_Type  System_SyscallType;

import System_intptr  System_Syscall_call00(System_Syscall_command number);
import System_intptr  System_Syscall_call01(System_Syscall_command number, System_intptr arg1);
import System_intptr  System_Syscall_call02(System_Syscall_command number, System_intptr arg1, System_intptr arg2);
import System_intptr  System_Syscall_call03(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3);
import System_intptr  System_Syscall_call04(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3, System_intptr arg4);
import System_intptr  System_Syscall_call05(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3, System_intptr arg4, System_intptr arg5);
import System_intptr  System_Syscall_call06(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3, System_intptr arg4, System_intptr arg5, System_intptr arg6);

#if defined(using_System)
#define Syscall_call00  System_Syscall_call00
#define Syscall_call01  System_Syscall_call01
#define Syscall_call02  System_Syscall_call02
#define Syscall_call03  System_Syscall_call03
#define Syscall_call04  System_Syscall_call04
#define Syscall_call05  System_Syscall_call05
#define Syscall_call06  System_Syscall_call06
#endif

export thread System_error System_Syscall_error;

export void  System_Syscall_set_error(System_error error);
export System_error  System_Syscall_get_error();
export void  System_Syscall_terminate(System_size code)  noreturn;


struct System_Syscall_stat_timestamp {

    System_int64 sec;
    System_intptr nsec;
};


struct System_Syscall_stat {

    System_uint64 deviceId;
    System_uint64 iNodeId;
    System_uint64 hardlinks;
    System_uint32 mode;
    System_uint32 userId;
    System_uint32 groupId;
    System_uint32 __padding1;

    System_uint64 isDevice;
    System_int64 size;
    System_int64 bulkSize;
    System_int64 blocks;
    struct System_Syscall_stat_timestamp accessTime;
    struct System_Syscall_stat_timestamp modifyTime;
    struct System_Syscall_stat_timestamp changeTime;
    System_intptr __reserved[3];

};

export System_var  System_Syscall_open(System_string8 fileName, System_intptr flags, System_intptr mode);
export System_var  System_Syscall_openat(System_var directoryPtr, System_string8 fileName, System_intptr flags, System_intptr mode);
export System_size  System_Syscall_read(System_var filePtr, const void  * buf, System_size count);
export System_size  System_Syscall_write(System_var filePtr, const void  * buf, System_size count);
export System_size  System_Syscall_lseek(System_var filePtr, System_size offset, System_intptr whence);
export void  System_Syscall_fsync(System_var filePtr);
export void  System_Syscall_close(System_var filePtr);
export void  System_Syscall_fstatat(System_var directoryPtr, const System_string8 pathName, struct System_Syscall_stat  * that, System_intptr flags);

export System_var  System_Syscall_mmap(System_size length, System_intptr pageflags, System_intptr mapflags, System_var file, System_intptr offset);
export void  System_Syscall_munmap(System_var address, System_size length);

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
