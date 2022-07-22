/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(code_System_Syscall_Command)
#define code_System_Syscall_Command

/*# System_Syscall_Command #*/

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

struct System_Type  System_Syscall_CommandType = { .base = { .type = typeof(System_Type) },
    .name = "System.Syscall.Command",
    .size = sizeof(System_Syscall_Command),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_Syscall_CommandTypeFields, .length = sizeof_array(System_Syscall_CommandTypeFields),
    },
};

#endif
#if !defined(code_System_Error)
#define code_System_Error

/*# System_Error #*/

struct System_Type_FieldInfo  System_ErrorTypeFields[] = {
#include <min/System.Error.generic.asm.h>
};

struct System_Type  System_ErrorType = { .base = { .type = typeof(System_Type) },
    .name = "System.Error",
    .size = sizeof(System_Error),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_ErrorTypeFields, .length = sizeof_array(System_ErrorTypeFields),
    },
};

#endif
#if !defined(code_System_Syscall)
#define code_System_Syscall

/*# System_Syscall #*/

struct System_Type  System_SyscallType = { .base = { .type = typeof(System_Type) },
    .name = "System.Syscall",
};

System_Error System_Syscall_error = 0;

void System_Syscall_set_Error(const System_Error error) {
    System_Syscall_error = error;
}

System_Error System_Syscall_get_Error() {
    System_Error error = System_Syscall_error;
    System_Syscall_error = 0;
    return error;
}

void  System_Syscall_terminate(System_Size code)  {
    (void)System_Syscall_call01(System_Syscall_Command_exit, code);
    /* inline_unreachable... for noreturn just repeat: */
    (void)System_Syscall_terminate(code);
}

System_Var  System_Syscall_open(System_String8 fileName, System_IntPtr flags, System_IntPtr mode) {
    return (System_Var)System_Syscall_call03(System_Syscall_Command_open, (System_IntPtr)fileName, flags, mode);
}

System_Var  System_Syscall_openat(System_Var directoryPtr, System_String8 fileName, System_IntPtr flags, System_IntPtr mode) {
    return (System_Var)System_Syscall_call04(System_Syscall_Command_openat, (System_IntPtr)directoryPtr, (System_IntPtr)fileName, flags, mode);
}

System_Size  System_Syscall_read(System_Var filePtr, const void  * buf, System_Size count) {
    return System_Syscall_call03(System_Syscall_Command_read, (System_IntPtr)filePtr, (System_IntPtr)buf, count);
}

System_Size  System_Syscall_write(System_Var filePtr, const void  * buf, System_Size count) {
    return System_Syscall_call03(System_Syscall_Command_write, (System_IntPtr)filePtr, (System_IntPtr)buf, count);
}

System_Size  System_Syscall_lseek(System_Var filePtr, System_Size offset, System_IntPtr whence) {
    return System_Syscall_call03(System_Syscall_Command_lseek, (System_IntPtr)filePtr, offset, whence);
}

void  System_Syscall_fsync(System_Var filePtr) {
    (void)System_Syscall_call01(System_Syscall_Command_fsync, (System_IntPtr)filePtr);
}

void  System_Syscall_close(System_Var filePtr) {
    (void)System_Syscall_call01(System_Syscall_Command_close, (System_IntPtr)filePtr);
}

void  System_Syscall_fstatat(System_Var directoryPtr, const System_String8 pathName, struct System_Syscall_stat  * that, System_IntPtr flags) {
    (void)System_Syscall_call04(System_Syscall_Command_fstatat, (System_IntPtr)directoryPtr, (System_IntPtr)pathName, (System_IntPtr)that, flags);
}

System_Var  System_Syscall_mmap(System_Size length, System_IntPtr page, System_IntPtr map, System_Var file, System_IntPtr offset) {
    return (System_Var)System_Syscall_call06(System_Syscall_Command_mmap, /* initial address */ null, length, page, map, (System_IntPtr)file, offset);
}

void  System_Syscall_munmap(System_Var address, System_Size length) {
    (void)System_Syscall_call02(System_Syscall_Command_munmap, (System_IntPtr)address, length);
}

#endif
