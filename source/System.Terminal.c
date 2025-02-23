/* Gemeinfrei. Public Domain. */
#if !defined(System_internal)
#include <System.internal.h>
#endif
#if !defined(have_System_Terminal)
#include <min/System.Terminal.h>
#endif
#if !defined(have_System_Syscall)
#include <min/System.Syscall.h>
#endif

/** class System_Terminal  **/

struct System_Type System_TerminalType = {
    .base = { .type = typeof(System_Type) },
    .name = "Terminal",
    .size = sizeof(struct System_Terminal),
};

System_Bool System_Terminal_isTTY(System_File that) {

    struct System_Terminal terminal; System_Stack_clear(terminal);
    System_IntPtr errno = System_Terminal_get(that, &terminal);
    return errno != System_ErrorCode_ENOTTY; 
}

System_ErrorCode System_Terminal_get(System_File that, System_Terminal terminal) {
    
    System_Syscall_ioctl1(that->fileId, System_Terminal_ioctls_TCGETS, terminal);
    System_ErrorCode errno = System_Syscall_get_Error();
    return errno;
}

System_ErrorCode System_Terminal_set__optional(System_File that, System_Terminal terminal, System_Terminal_Flag optional) {
    
    System_Terminal_Flag command = System_Terminal_ioctls_TCSETS;
    switch (optional) {
	case System_Terminal_ioctls_TCSADRAIN:
	    command = System_Terminal_ioctls_TCSETSW;
	    break;
	case System_Terminal_ioctls_TCSAFLUSH:
	    command = System_Terminal_ioctls_TCSETSF;
	    break;
    }
    System_Syscall_ioctl1(that->fileId, command, terminal);
    System_ErrorCode errno = System_Syscall_get_Error();
    return errno;
}

System_ErrorCode System_Terminal_set(System_File that, System_Terminal terminal) {
    
    return System_Terminal_set__optional(that, terminal, System_Terminal_ioctls_TCSANOW);
}

System_ErrorCode System_Terminal_getWindowSize(System_File that, System_Terminal_WindowSize window) {
    
    System_Syscall_ioctl1(that->fileId, System_Terminal_ioctls_TIOGETWINSIZE, window);
    System_ErrorCode errno = System_Syscall_get_Error();
    return errno;
}

System_ErrorCode System_Terminal_setWindowSize(System_File that, System_Terminal_WindowSize window) {
    
    System_Syscall_ioctl1(that->fileId, System_Terminal_ioctls_TIOSETWINSIZE, window);
    System_ErrorCode errno = System_Syscall_get_Error();
    return errno;
}

System_ErrorCode System_Terminal_setInput(System_File that, System_String8 string) {
    System_Syscall_ioctl1(that->fileId, System_Terminal_ioctls_TIOCSTI, string);
    System_ErrorCode errno = System_Syscall_get_Error();
    return errno;
}

void System_Terminal_reset(System_File that) {
    base_System_File_write__string(that, "\ec");
}

void System_Terminal_saveCursor(System_File that) {
    base_System_File_write__string(that, "\e7");
}

void System_Terminal_restoreCursor(System_File that) {
    base_System_File_write__string(that, "\e8");
}

void System_Terminal_insertBlankChars(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}@", 1, n);
}

void System_Terminal_insertBlankRows(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}L", 1, n);
}

void System_Terminal_moveUp(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}A", 1, n);
}

void System_Terminal_moveDown(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}B", 1, n);
}

void System_Terminal_moveRight(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}C", 1, n);
}

void System_Terminal_moveLeft(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}D", 1, n);
}

void System_Terminal_move(System_File that, System_Size row, System_Size column) {
    base_System_File_write(that, "\e[{0:uint};{1:uint}H", 2, row, column);
}

void System_Terminal_deleteRows(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}M", 1, n);
}

void System_Terminal_deleteColumns(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}P", 1, n);
}

void System_Terminal_eraseColumns(System_File that, System_Size n) {
    base_System_File_write(that, "\e[{0:uint}X", 1, n);
}

void System_Terminal_version(System_File that) {
    base_System_File_write__string(that, "\e[c");
}

void System_Terminal_status(System_File that) {
    base_System_File_write__string(that, "\e[5n");
}

void System_Terminal_getCursorPosition(System_File that) {
    base_System_File_write__string(that, "\e[6n");
}

