#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Console)
#include <min/System.Console.h>
#endif
#if !defined(have_System_UInt8)
#include <min/System.Integers.auto.h>
#endif
#if !defined(have_System_Memory)
#include <min/System.Memory.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif
#if !defined(have_System_Exception)
#include <min/System.Exception.h>
#endif
#if !defined(have_System_String8)
#include <min/System.String8.h>
#endif
#if !defined(code_System_Console)
#define code_System_Console

/** static System_Console **/

struct System_Type System_ConsoleType = { .base = { .type = typeof(System_Type) }, .name = "Console", };

struct System_File  System_Console_StdIn = {
    .base = { .type = typeof(System_File) },
    .fileId = System_Syscall_StandardFile_STDIN,
};
struct System_File  System_Console_StdOut = {
    .base = { .type = typeof(System_File) },
    .fileId = System_Syscall_StandardFile_STDOUT,
};
struct System_File  System_Console_StdErr = {
    .base = { .type = typeof(System_File) },
    .fileId = System_Syscall_StandardFile_STDERR,
};

void  System_Console_sync() {
    System_Syscall_fsync(System_Syscall_StandardFile_STDIN);
    System_Syscall_fsync(System_Syscall_StandardFile_STDOUT);
    System_Syscall_fsync(System_Syscall_StandardFile_STDERR);
}

/* __attribute__((constructor)) void System_init */

/** function System_Console_exit
    Quit or Exit the program quietly, writing System_Exception to the Console, before terminating the process.
    Argument Size code
    No return
**/
void System_Console_exit(const Size code)  {
#if DEBUG == DEBUG_System_Syscall_mmap
    if (System_Thread_TID == System_Thread_PID) System_Syscall_mmap__debug();
#endif
    if (System_Exception_current) 
        System_Exception_terminate(System_Exception_current);
    /*if (System_Thread_Current) {
        if (System_Thread_Current->stack) {
            System_Syscall_munmap(System_Thread_Current->stack, STACK_SIZE);
            System_Thread_Current->stack = null;
        }
        System_Int32_atomic_exchange(&System_Thread_Current->returnValue, code);
        System_Int32_atomic_exchange(&System_Thread_Current->threadId, 0);
    }*/
    if (System_Thread_TID == System_Thread_PID) {
        System_Var tls = System_Thread_getRegister();
        System_Memory_freeClass(&tls);
    }
    System_Memory_cleanup();
    System_Syscall_terminate(code);
}

#define WEXITSTATUS(status)  (((status) & 0xff00) >> 8)
#define WTERMSIG(status)  ((status) & 0x7f)

System_Size System_Console_execute__arguments(System_String8 fileName, Size argc, System_String8 argv[]) {
    return System_Console_execute__stdout_stderr_stdin_arguments(fileName, null, null, null, argc, argv);
}

System_Size System_Console_execute__stdout_arguments(System_String8 fileName, File stdout, Size argc, System_String8 argv[]) {
    return System_Console_execute__stdout_stderr_stdin_arguments(fileName, stdout, null, null, argc, argv);
}

System_Size System_Console_execute__stdout_stderr_arguments(System_String8 fileName, File stdout, File stderr, Size argc, System_String8 argv[]) {
    return System_Console_execute__stdout_stderr_stdin_arguments(fileName, stdout, stderr, null, argc, argv);
}

/** function System_Console_execute__stdout_stderr_stdin_arguments
    Execute a program, with absolute path. Specify the program name as the first argument. Redirecting stdout, stderr and stdin.
    Argument System_String8 fileName
    Argument System_File stdout
    Argument System_File stderr
    Argument System_File stdin
    Argument System_Size argc
    Argument System_String8 argv[]
    Returns the exit status of the program.
**/
System_Size System_Console_execute__stdout_stderr_stdin_arguments(System_String8 fileName, File stdout, File stderr, File stdin, Size argc, System_String8 argv[]) {

    System_Signal_block__number(System_Signal_Number_SIGCHILD);
    System_Thread_ID pid = System_Syscall_fork();
    System_ErrorCode error = 0;
    if (!pid) { // i'm the child
        if (stdout) System_Syscall_dup2(stdout->fileId, 1);
        if (stderr) System_Syscall_dup2(stderr->fileId, 2);
        if (stdin) System_Syscall_dup2(stdin->fileId, 0);
        System_String8 argv1[System_Arguments_Limit + 1]; Stack_clear(argv1);
        for (Size c = 0; c < argc && c < System_Arguments_Limit; ++c) argv1[c] = argv[c];
        System_Syscall_execve(fileName, argv1, System_Environment_Arguments);
        error = System_Syscall_get_Error();
        if (error) System_Exception_terminate(new_System_IOException(String8_format("System_Syscall_execve error {0:string}", 1, enum_getName(typeof(System_ErrorCode), error))));
    }
    System_Size status = 0;
    System_Syscall_wait(pid, &status, 0);
    error = System_Syscall_get_Error();
    if (error) System_Exception_throw(new_System_IOException(String8_format("System_Syscall_wait error {0:string}", 1, enum_getName(typeof(System_ErrorCode), error))));
    System_Signal_unblock__number(System_Signal_Number_SIGCHILD);
    return WEXITSTATUS(status);
}

System_Size System_Console_execute(System_String8 fileName, ...) {
    Arguments args;
    Arguments_start(args, fileName);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_Console_execute__stdout_stderr_stdin_arguments(fileName, null, null, null, argc, (System_String8 *)argv);
}

System_Size System_Console_execute__stdout(System_String8 fileName, System_File stdout, ...) {
    Arguments args;
    Arguments_start(args, stdout);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_Console_execute__stdout_stderr_stdin_arguments(fileName, stdout, null, null, argc, (System_String8 *)argv);
}

System_Size System_Console_execute__stdout_stderr(System_String8 fileName, System_File stdout, System_File stderr, ...) {
    Arguments args;
    Arguments_start(args, stderr);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_Console_execute__stdout_stderr_stdin_arguments(fileName, stdout, stderr, null, argc, (System_String8 *)argv);
}

/** function System_Console_execute__stdout_stderr_stdin
    Execute a program, with absolute path. You also need to specify the program name as the first argument. Redirecting stdout, stderr and stdin.
    Argument System_String8 fileName
    Argument System_File stdout
    Argument System_File stderr
    Argument System_File stdin
    Argument ...
    Returns the exit status of the program.
**/
System_Size System_Console_execute__stdout_stderr_stdin(System_String8 fileName, System_File stdout, System_File stderr, System_File stdin, ...) {
    Arguments args;
    Arguments_start(args, stdin);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_Console_execute__stdout_stderr_stdin_arguments(fileName, stdout, stderr, stdin, argc, (System_String8 *)argv);
}

/** function System_Console_write__string_size 
    Write a String8 to System_Console_StdOut, with length of size.
    Argument System_String8 string
    Argument System_Size size
    Returns the length of the string.
**/
System_Size  System_Console_write__string_size(String8 string, Size size) {
    Console_assert(string);
    return System_File_write__string_size(&System_Console_StdOut, string, size);
}

/** function System_Console_write__string 
    Write a String8 to System_Console_StdOut, using System_String8_get_Length.
    Argument System_String8 string
    Returns the length of the string.
**/
System_Size  System_Console_write__string(String8 string) {
    return System_Console_write__string_size(string, String8_get_Length(string));
}

/** function System_Console_write__char 
    Write a char to System_Console_StdOut.
    Argument System_Char8 character
    Returns 1.
**/
System_Size  System_Console_write__char(Char8 character) {
    System_Console_write__string_size(&character, 1);
    return 1;
}

/** function System_Console_write
    Write a formatted string to System_Console_StdOut. 
    Argument System_String8 format
    Argument ...
    Returns the length of the string.
    Example: Console_write("({0:uint}){1:string}", 2, String8_get_Length("Hallo"), "Hallo");
**/
System_Size  System_Console_write(String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(&System_Console_StdOut, format, 0, argc, argv);
}

/** function System_Console_writeLineEmpty
    Write an empty new line to System_Console_StdOut.
    Returns 1.
**/
System_Size  System_Console_writeLineEmpty(void) {
    System_File_write__string_size(&System_Console_StdOut, "\n", 1);
    return 1;
}

/** function System_Console_writeLine__string
    Write a string to System_Console_StdOut, this function is using String8_get_Length.
    Argument System_String8 string
    Returns the length of the string.
**/
System_Size  System_Console_writeLine__string(String8 string) {
    return System_Console_writeLine(string, 0);
}

/** function System_Console_writeLine
    Write a formatted string and a new line to System_Console_StdOut. 
    Argument System_String8 format
    Argument ...
    Returns the length of the string.
    Example: Console_writeLine("({0:uint}){1:string}", 2, String8_get_Length("Hallo"), "Hallo");
**/
System_Size  System_Console_writeLine(String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(&System_Console_StdOut, format, '\n', argc, argv);
}

/** function System_Console_assert__string8
    Assert an expression. If false, write expression text, functionName, fileName and line to System_Console_StdErr.
    Argument System_Bool expression
    Argument System_String8 text
    Argument System_String8 functionName
    Argument System_String8 fileName
    Argument System_Size line
    Returns true, if the expression is false.
**/
Bool System_Console_assert__string8(System_Bool expression, const System_String8 text, const System_String8 functionName, const System_String8 fileName, const System_Size line) {
    if (expression) return false;
    Var argv[4]; argv[0] = (Var)text; argv[1] = (Var)functionName; argv[2] = (Var)line; argv[3] = (Var)fileName;
    System_File_writeEnd__arguments(&System_Console_StdErr, "System_Console_assert {0:string} in function {1:string} line {2:int} file {3:string}", '\n', 4, argv);
    return true;
}

/** function System_Console_debug
    Write a formatted string to System_Console_StdErr. 
    Argument System_String8 format
    Argument ...
    Returns the length of the string.
    Example: Console_debug("({0:uint}){1:string}", 2, String8_get_Length("Hallo"), "Hallo");
**/
Size System_Console_debug(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(&System_Console_StdErr, format, '\0', argc, argv);
}

/** function System_Console_debug__string_size 
    Write a String8 to System_Console_StdErr, with length of size.
    Argument System_String8 string
    Argument System_Size size
    Returns the length of the string.
**/
Size System_Console_debug__string_size(System_String8 string, System_Size size) {
    return System_File_write__string_size(&System_Console_StdErr, string, size);
}

/** function System_Console_debug__string 
    Write a String8 to System_Console_StdErr, using System_String8_get_Length.
    Argument System_String8 string
    Returns the length of the string.
**/
Size System_Console_debug__string(System_String8 string) {
    return System_File_write__string(&System_Console_StdErr, string);
}

/** function System_Console_debug__char 
    Write a char to System_Console_StdErr.
    Argument System_Char8 character
    Returns 1.
**/
System_Size  System_Console_debug__char(Char8 character) {
    System_Console_debug__string_size(&character, 1);
    return 1;
}

/** function System_Console_debugLine
    Write a formatted string and a new line to System_Console_StdErr. 
    Argument System_String8 format
    Argument ...
    Returns the length of the string.
    Example: Console_debugLine("({0:uint}){1:string}", 2, String8_get_Length("Hallo"), "Hallo");
**/
Size System_Console_debugLine(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(&System_Console_StdErr, format, '\n', argc, argv);
}

/** function System_Console_debugLine__string
    Write a string to System_Console_StdErr, this function is using String8_get_Length.
    Argument System_String8 string
    Returns the length of the string.
**/
Size  System_Console_debugLine__string(System_String8 string) {
    return System_Console_debugLine(string, 0);
}

/** function System_Console_debugLineEmpty
    Write an empty new line to System_Console_StdErr.
    Returns 1.
**/
Size System_Console_debugLineEmpty(void) {
    System_File_write__string_size(&System_Console_StdErr, "\n", 1);
    return 1;
}

/** function System_Console_error
    Write a formatted string to System_Console_StdErr. 
    Argument System_String8 format
    Argument ...
    Returns the length of the string.
    Example: Console_error("({0:uint}){1:string}", 2, String8_get_Length("Hallo"), "Hallo");
**/
Size System_Console_error(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(&System_Console_StdErr, format, '\0', argc, argv);
}

/** function System_Console_error__string_size 
    Write a String8 to System_Console_StdErr, with length of size.
    Argument System_String8 string
    Argument System_Size size
    Returns the length of the string.
**/
Size System_Console_error__string_size(System_String8 string, System_Size size) {
    return System_File_write__string_size(&System_Console_StdErr, string, size);
}

/** function System_Console_error__string 
    Write a String8 to System_Console_StdErr, using System_String8_get_Length.
    Argument System_String8 string
    Returns the length of the string.
**/
Size System_Console_error__string(System_String8 string) {
    return System_File_write__string(&System_Console_StdErr, string);
}

/** function System_Console_error__char 
    Write a char to System_Console_StdErr.
    Argument System_Char8 character
    Returns 1.
**/
System_Size  System_Console_error__char(Char8 character) {
    System_Console_error__string_size(&character, 1);
    return 1;
}

/** function System_Console_errorLine
    Write a formatted string and a new line to System_Console_StdErr. 
    Argument System_String8 format
    Argument ...
    Returns the length of the string.
    Example: Console_errorLine("({0:uint}){1:string}", 2, String8_get_Length("Hallo"), "Hallo");
**/
Size System_Console_errorLine(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    return System_File_writeEnd__arguments(&System_Console_StdErr, format, '\n', argc, argv);
}

/** function System_Console_errorLine__string
    Write a string to System_Console_StdErr, this function is using String8_get_Length.
    Argument System_String8 string
    Returns the length of the string.
**/
Size  System_Console_errorLine__string(System_String8 string) {
    return System_Console_errorLine(string, 0);
}

/** function System_Console_errorLineEmpty
    Write an empty new line to System_Console_StdErr.
    Returns 1.
**/
Size System_Console_errorLineEmpty(void) {
    System_File_write__string_size(&System_Console_StdErr, "\n", 1);
    return 1;
}

void System_Console_writeHex(Size length, void  * value) {
    if (length == 0 || !value) return;

    #define hexdump_Columns  32

    UInt8  * memory = (UInt8  *)value;
    Size i, j, l, pos, length_div_columns_rem = length % hexdump_Columns, i_div_columns_rem;

    Char8 scratch[System_UInt64_String8Capacity_base16 + 1]; System_Stack_clear(scratch);

    #define hexdump_Space_VALUE  142 /* = 12 + (hexdump_Columns * 3) + hexdump_Columns + 2 */

    Char8 buffer[hexdump_Space_VALUE]; System_Stack_clear(buffer);

    #undef hexdump_Space_VALUE

    buffer[0] = '0';
    buffer[1] = 'x';

    for (i = 0; i < length + ((length_div_columns_rem) ? (hexdump_Columns - length_div_columns_rem) : 0); ++i)
    {
        i_div_columns_rem = i % hexdump_Columns;

        /* print offset */
        if(i_div_columns_rem == 0)
        {
            pos = 2;
            l = stack_System_UInt64_toString8base16(i, scratch);
            Memory_copyTo(scratch, l, buffer + pos);
            pos += l;
            buffer[pos++] = ':';
            buffer[pos++] = ' ';
        }

        /* print hex data */
        if(i < length)
        {
            l = stack_System_UInt8_toString8base16(0xFF & memory[i], scratch);
            Memory_copyTo(scratch, l, buffer + pos);
            pos += l;
            buffer[pos++] = ' ';
        }
        else /* end of block, just aligning for ASCII dump */
        {
            buffer[pos++] = ' ';
            /* buffer[pos++] = ' '; */
            /* buffer[pos++] = ' '; */
        }

        /* print ASCII dump */
        if(i_div_columns_rem == (hexdump_Columns - 1))
        {
            for(j = i - (hexdump_Columns - 1); j <= i; j++)
            {
                if(j >= length) /* end of block, not really printing */
                {
                    buffer[pos++] = ' ';
                }
                else if(System_Char8_isPrintable(memory[j])) /* printable char */
                {
                    buffer[pos++] = 0xFF & memory[j];
                }
                else /* other char */
                {
                    buffer[pos++] = '.';
                }
            }
            buffer[pos++] = '\n';
            buffer[pos++] = '\0';
            Console_write__string(buffer);
        }
    }
    #undef hexdump_Columns
}

#endif