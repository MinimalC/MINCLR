/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Exception)
#include "System.Exception.h"
#endif
#if !defined(have_System_error)
#include "System.error.h"
#endif
#if !defined(have_System_Syscall_command)
#include "System.Syscall.command.h"
#endif
#if !defined(have_System_SystemException)
#define have_System_SystemException

#define struct_System_SystemException  struct class_System_SystemException
typedef __fixed struct_System_SystemException {
    struct_System_Exception base;

    System_error error;

}  * System_SystemException;

#define stack_System_SystemException(__error)  (struct_System_SystemException){ .base = stack_System_Object(System_SystemException), .error = __error, }

__export struct_System_Type  System_SystemExceptionType;

typedef System_SystemException __delegate(System_SystemException_init)(System_SystemException that);
typedef System_void __delegate(System_SystemException_free)(System_SystemException that);

__export System_SystemException  System_SystemException_new();
__export System_SystemException  base_System_SystemException_init(System_SystemException that);

#define System_SystemException_init(o)  ((function_System_SystemException_init)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_init))(o)
#define System_SystemException_free(o)  ((function_System_SystemException_free)System_Type_getMethod(System_Object_get_Type((System_Object)o), base_System_Object_free))(o)

#define inline_System_SystemException_new()  (base_System_SystemException_init(inline_System_Object_allocClass(System_SystemException)))

#if defined(using_System)
#define struct_SystemException  struct_System_SystemException
#define stack_SystemException  stack_System_SystemException
#define __SystemException  System_SystemException
#define __SystemExceptionType  System_SystemExceptionType

#define __SystemException_new  System_SystemException_new

#define __SystemException_init  System_SystemException_init
#define __SystemException_free  System_SystemException_free
#define base_SystemException_init  base_System_SystemException_init
#define function_SystemException_init  function_System_SystemException_init
#define function_SystemException_free  function_System_SystemException_free
#endif

#endif
#if !defined(have_System_Syscall)
#define have_System_Syscall

__import System_intptr  System_Syscall_call00(System_Syscall_command number);
__import System_intptr  System_Syscall_call01(System_Syscall_command number, System_intptr arg1);
__import System_intptr  System_Syscall_call02(System_Syscall_command number, System_intptr arg1, System_intptr arg2);
__import System_intptr  System_Syscall_call03(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3);
__import System_intptr  System_Syscall_call04(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3, System_intptr arg4);
__import System_intptr  System_Syscall_call05(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3, System_intptr arg4, System_intptr arg5);
__import System_intptr  System_Syscall_call06(System_Syscall_command number, System_intptr arg1, System_intptr arg2, System_intptr arg3, System_intptr arg4, System_intptr arg5, System_intptr arg6);

#if defined(using_System)
#define __Syscall_call00  System_Syscall_call00
#define __Syscall_call01  System_Syscall_call01
#define __Syscall_call02  System_Syscall_call02
#define __Syscall_call03  System_Syscall_call03
#define __Syscall_call04  System_Syscall_call04
#define __Syscall_call05  System_Syscall_call05
#define __Syscall_call06  System_Syscall_call06
#endif

__export System_void  System_Syscall_error(System_error error);

__export System_void  System_Syscall_terminate(System_size code)  __noreturn;

__export System_var  System_Syscall_open(System_string8 fileName, System_intptr flags, System_intptr mode);
__export System_var  System_Syscall_openat(System_var directoryPtr, System_string8 fileName, System_intptr flags, System_intptr mode);
__export System_size  System_Syscall_read(System_var filePtr, const void  * buf, System_size count);
__export System_size  System_Syscall_write(System_var filePtr, const void  * buf, System_size count);
__export System_size  System_Syscall_lseek(System_var filePtr, System_size offset, System_intptr whence);
__export System_void  System_Syscall_fsync(System_var filePtr);
__export System_void  System_Syscall_close(System_var filePtr);


#define struct_System_Syscall_stat_timestamp  struct System_Syscall_stat_timestamp
struct_System_Syscall_stat_timestamp {

    System_int64 sec;
    System_intptr nsec;
};

#define struct_System_Syscall_stat  struct System_Syscall_stat
struct_System_Syscall_stat {

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
    struct_System_Syscall_stat_timestamp accessTime;
    struct_System_Syscall_stat_timestamp modifyTime;
    struct_System_Syscall_stat_timestamp changeTime;
    System_intptr __reserved[3];

};

__export System_void  System_Syscall_fstatat(System_var directoryPtr, const System_string8 pathName, struct_System_Syscall_stat  * that, System_intptr flags);

__export struct_System_Type  System_SyscallType;

#if defined(using_System)
#define __SyscallType  System_SyscallType
#define __Syscall_error  System_Syscall_error
#define __Syscall_terminate  System_Syscall_terminate
#define __Syscall_open  System_Syscall_open
#define __Syscall_openat  System_Syscall_openat
#define __Syscall_read  System_Syscall_read
#define __Syscall_write  System_Syscall_write
#define __Syscall_lseek  System_Syscall_lseek
#define __Syscall_fsync  System_Syscall_fsync
#define __Syscall_close  System_Syscall_close
#endif

#endif
