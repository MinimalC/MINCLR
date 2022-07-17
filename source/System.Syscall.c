/* Gemeinfrei. Public Domain. */
#if !defined(have_System_internal)
#include "System.internal.h"
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(code_System_Syscall_command)
#define code_System_Syscall_command

/*# System_Syscall_command #*/

struct_System_Type_FieldInfo  System_Syscall_commandTypeFields[] = {
#if defined(have_Linux)

#if defined(have_ARM)
#include <min/ARM/GNU.Linux/System.Syscall.command.asm.h>

#elif defined(have_AMD64)
#include <min/AMD64/GNU.Linux/System.Syscall.command.asm.h>

#elif defined(have_X86)
#include <min/X86/GNU.Linux/System.Syscall.command.asm.h>

#else
#error Architecture not implemented
#endif

#else
#error Platform not implemented
#endif
};

struct_System_Type  System_Syscall_commandType = { .base = { .type = typeof(System_Type) },
    .name = "System.Syscall.command",
    .size = sizeof(System_Syscall_command),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_Syscall_commandTypeFields, .length = sizeof_array(System_Syscall_commandTypeFields),
    },
};

#endif
#if !defined(code_System_error)
#define code_System_error

/*# System_error #*/

struct_System_Type_FieldInfo  System_errorTypeFields[] = {
#include <min/System.error.generic.asm.h>
};

struct_System_Type  System_errorType = { .base = { .type = typeof(System_Type) },
    .name = "System.error",
    .size = sizeof(System_error),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_errorTypeFields, .length = sizeof_array(System_errorTypeFields),
    },
};

#endif
#if !defined(code_System_Syscall)
#define code_System_Syscall

/*# System_Syscall #*/

struct_System_Type  System_SyscallType = { .base = { .type = typeof(System_Type) },
    .name = "System.Syscall",
};

void System_Syscall_error(const System_error erreur) {
    if (!erreur) return;

    System_Exception exception = new_System_Exception__error();
    exception->error = erreur;
    System_Exception_throw((System_Exception)exception);
}

void  System_Syscall_terminate(System_size code)  {
    (void)System_Syscall_call01(System_Syscall_command_exit, code);
    /* inline_unreachable... for noreturn just repeat: */
    (void)System_Syscall_terminate(code);
}


System_var  System_Syscall_open(System_string8 fileName, System_intptr flags, System_intptr mode) {
    return (System_var)System_Syscall_call03(System_Syscall_command_open, (System_intptr)fileName, flags, mode);
}

System_var  System_Syscall_openat(System_var directoryPtr, System_string8 fileName, System_intptr flags, System_intptr mode) {
    return (System_var)System_Syscall_call04(System_Syscall_command_openat, (System_intptr)directoryPtr, (System_intptr)fileName, flags, mode);
}

System_size  System_Syscall_read(System_var filePtr, const void  * buf, System_size count) {
    return System_Syscall_call03(System_Syscall_command_read, (System_intptr)filePtr, (System_intptr)buf, count);
}

System_size  System_Syscall_write(System_var filePtr, const void  * buf, System_size count) {
    return System_Syscall_call03(System_Syscall_command_write, (System_intptr)filePtr, (System_intptr)buf, count);
}

System_size  System_Syscall_lseek(System_var filePtr, System_size offset, System_intptr whence) {
    return System_Syscall_call03(System_Syscall_command_lseek, (System_intptr)filePtr, offset, whence);
}

void  System_Syscall_fsync(System_var filePtr) {
    (void)System_Syscall_call01(System_Syscall_command_fsync, (System_intptr)filePtr);
}

void  System_Syscall_close(System_var filePtr) {
    (void)System_Syscall_call01(System_Syscall_command_close, (System_intptr)filePtr);
}

void  System_Syscall_fstatat(System_var directoryPtr, const System_string8 pathName, struct_System_Syscall_stat  * that, System_intptr flags) {
    (void)System_Syscall_call04(System_Syscall_command_fstatat, (System_intptr)directoryPtr, (System_intptr)pathName, (System_intptr)that, flags);
}

System_var  System_Syscall_mmap(System_size length, System_intptr page, System_intptr map, System_var file, System_intptr offset) {
    return (System_var)System_Syscall_call06(System_Syscall_command_mmap, /* initial address */ null, length, page, map, (System_intptr)file, offset);
}

void  System_Syscall_munmap(System_var address, System_size length) {
    (void)System_Syscall_call02(System_Syscall_command_munmap, (System_intptr)address, length);
}

#endif
