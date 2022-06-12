/* Gemeinfrei. Public Domain. */
#if !defined(have_System)
#include "System.internal.h"
#endif
#if !defined(code_System_Syscall_command)
#define code_System_Syscall_command

/*# System_Syscall_command #*/

struct_System_String  STRING_System_Syscall_command = const_System_String("System.Syscall.command");

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

struct_System_Type  System_Syscall_commandType = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_Syscall_command,
    .size = sizeof(System_Syscall_command),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_Syscall_commandTypeFields, .length = __sizeof_array(&System_Syscall_commandTypeFields),
    },
};

#endif
#if !defined(code_System_error)
#define code_System_error

/*# System_error #*/

struct_System_String  STRING_System_error = const_System_String("System.error");

struct_System_Type_FieldInfo  System_errorTypeFields[] = {
#include <min/System.error.generic.asm.h>
};

struct_System_Type  System_errorType = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_error,
    .size = sizeof(System_error),
	.fields = { .base = stack_System_Object(System_Type_FieldInfoArray),
        .value = &System_errorTypeFields, .length = __sizeof_array(&System_errorTypeFields),
    },
};

#endif
#if !defined(code_System_SystemException)
#define code_System_SystemException

/*# System_SystemException #*/

System_SystemException  System_SystemException_new() {
    return inline_System_SystemException_new();
}

System_SystemException  base_System_SystemException_init(System_SystemException that) {
    base_System_Object_init((System_Object)that);

    return that;
}

/* void  base_System_SystemException_free(System_SystemException that) {

    base_System_Object_free((System_Object)that);
} */

struct_System_String  STRING_System_SystemException = const_System_String("System.SystemException");

struct_System_Type_FunctionInfo  System_SystemExceptionTypeFunctions[] = {
    [0] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_init, .value = base_System_SystemException_init },
/*    [1] = { .base = stack_System_Object(System_Type_FunctionInfo), .function = base_System_Object_free, .value = base_System_SystemException_free }, */
};

struct_System_Type  System_SystemExceptionType = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_SystemException,
    .size = sizeof(struct_System_SystemException),
    .baseType = __typeof(System_Exception),
    .functions = { .base = stack_System_Object(System_Type_FunctionInfoArray),
        .length = __sizeof_array(&System_SystemExceptionTypeFunctions), .value = &System_SystemExceptionTypeFunctions
    },
};

#endif
#if !defined(code_System_Syscall)
#define code_System_Syscall

/*# System_Syscall #*/

struct_System_String  STRING_System_Syscall = const_System_String("System.Syscall");

struct_System_Type  System_SyscallType = { .base = { .Type = __typeof(System_Type) },
    .name = &STRING_System_Syscall,
};

void System_Syscall_error(const System_error erreur) {

    // if (!erreur) return;

    struct_System_SystemException exception = stack_System_SystemException(erreur);
    System_Exception_throw((System_Exception)&exception);
}

void  System_Syscall_terminate(System_size code)  {
    (void)System_Syscall_call01(System_Syscall_command_exit, code);
    /* inline_unreachable... for noreturn just repeat: */
    (void)System_Syscall_terminate(code);
}


System_intptr  System_Syscall_open(System_string8 fileName, System_intptr flags, System_intptr mode) {
    return System_Syscall_call03(System_Syscall_command_open, (System_intptr)fileName, flags, mode);
}

System_intptr  System_Syscall_openat(System_intptr directoryPtr, System_string8 fileName, System_intptr flags, System_intptr mode) {
    return System_Syscall_call04(System_Syscall_command_openat, directoryPtr, (System_intptr)fileName, flags, mode);
}

System_size  System_Syscall_read(System_intptr filePtr, const void  * buf, System_size count) {
    return System_Syscall_call03(System_Syscall_command_read, filePtr, (System_intptr)buf, count);
}

System_size  System_Syscall_write(System_intptr filePtr, const void  * buf, System_size count) {
    return System_Syscall_call03(System_Syscall_command_write, filePtr, (System_intptr)buf, count);
}

System_size  System_Syscall_lseek(System_intptr filePtr, System_size offset, System_intptr whence) {
    return System_Syscall_call03(System_Syscall_command_lseek, filePtr, offset, whence);
}

void  System_Syscall_fsync(System_intptr filePtr) {
    (void)System_Syscall_call01(System_Syscall_command_fsync, filePtr);
}

void  System_Syscall_close(System_intptr filePtr) {
    (void)System_Syscall_call01(System_Syscall_command_close, filePtr);
}

void  System_Syscall_fstatat(System_intptr directoryPtr, const System_string8 pathName, struct_System_Syscall_stat  * that, System_intptr flags) {
    (void)System_Syscall_call04(System_Syscall_command_fstatat, directoryPtr, (System_intptr)pathName, (System_intptr)that, flags);
}


#endif
