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

void System_Console_exit(const Size code)  {
#if DEBUG == DEBUG_System_Syscall_mmap
    System_Syscall_mmap__debug();
#endif
#if DEBUG
    System_Memory_debug();
#endif
    if (System_Exception_current) System_Exception_terminate(System_Exception_current);
    System_Syscall_terminate(code);
}

#define WEXITSTATUS(status)  (((status) & 0xff00) >> 8)
#define WTERMSIG(status)  ((status) & 0x7f)

System_Size System_Console_execute__arguments(System_String8 fileName, Size argc, System_String8 argv[]) {

    System_Signal_block__number(System_Signal_Number_SIGCHILD);
    System_Thread_TID pid = System_Syscall_fork();
    System_ErrorCode error = 0;
    if (!pid) { // i'm the child
        System_String8 argv1[System_Arguments_Limit + 1]; Stack_clear(argv1);
        for (Size c = 0; c < argc && c < System_Arguments_Limit; ++c) argv1[c] = argv[c];
        System_Syscall_execve(fileName, argv1, System_Environment_Arguments);
        error = System_Syscall_get_Error();
        if (error) System_Exception_terminate(new_System_IOException(String8_format("System_Syscall_execve error {0:string}", 1, enum_getName(typeof(System_ErrorCode), error))));
    }
    System_Size status = 0;
    while (true) {
        System_Syscall_wait(pid, &status, 0);
        error = System_Syscall_get_Error();
        break;
    }
    if (error) System_Exception_throw(new_System_IOException(String8_format("System_Syscall_wait error {0:string}", 1, enum_getName(typeof(System_ErrorCode), error))));
    System_Signal_unblock__number(System_Signal_Number_SIGCHILD);
    return !error;
}

System_Size System_Console_execute(System_String8 fileName, ...) {
    Arguments args;
    Arguments_start(args, fileName);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_Console_execute__arguments(fileName, argc, (System_String8 *)argv);
}

void  System_Console_write__string_size(String8 string, Size size) {
    Console_assert(string);
    System_File_write__string_size(&System_Console_StdOut, string, size);
}

void  System_Console_write__string(String8 string) {
    System_Console_write__string_size(string, String8_get_Length(string));
}

void  System_Console_write__char(Char8 character) {
    System_Console_write__string_size(&character, 1);
}

void  System_Console_write(String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_File_writeEnd__arguments(&System_Console_StdOut, format, 0, argc, argv);
}

void  System_Console_writeLineEmpty(void) {
    System_File_write__string_size(&System_Console_StdOut, "\n", 1);
}

void  System_Console_writeLine__string(String8 string) {
    System_Console_writeLine(string, 0);
}

void  System_Console_writeLine(String8 format, ...) {
    Console_assert(format);
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_File_writeEnd__arguments(&System_Console_StdOut, format, '\n', argc, argv);
}

void System_Console_assert__string8(System_Bool expression, const System_String8 text, const System_String8 functionName, const System_String8 fileName, const System_Size line) {
    if (expression) return;
    Var argv[4];
    argv[0] = (Var)text;
    argv[1] = (Var)functionName;
    argv[2] = (Var)fileName;
    argv[3] = (Var)line;
    System_File_writeEnd__arguments(&System_Console_StdErr, "ASSERT: {0:string} in function {1:string} in {2:string}:{3:int}", '\n', 4, argv);
}

void System_Console_debug(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_File_writeEnd__arguments(&System_Console_StdErr, format, '\0', argc, argv);
}

void System_Console_debug__string(System_String8 string) {
    System_File_write__string(&System_Console_StdErr, string);
}

void System_Console_debug__string_size(System_String8 string, System_Size size) {
    System_File_write__string_size(&System_Console_StdErr, string, size);
}

void System_Console_debugLine(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_File_writeEnd__arguments(&System_Console_StdErr, format, '\n', argc, argv);
}

void  System_Console_debugLine__string(System_String8 string) {
    System_Console_debugLine(string, 0);
}

void System_Console_debugLineEmpty(void) {
    System_File_write__string_size(&System_Console_StdErr, "\n", 1);
}

void System_Console_error(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_File_writeEnd__arguments(&System_Console_StdErr, format, '\0', argc, argv);
}

void System_Console_errorLine(const System_String8 format, ...) {
    Arguments args;
    Arguments_start(args, format);
    Var argv[System_Arguments_Limit];
    Size argc = stack_System_Arguments_get(args, argv);
    Arguments_end(args);
    System_File_writeEnd__arguments(&System_Console_StdErr, format, '\n', argc, argv);
}

void System_Console_errorLineEmpty(void) {
    System_File_write__string_size(&System_Console_StdErr, "\n", 1);
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