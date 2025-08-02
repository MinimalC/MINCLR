#define using_System
#include <min/System.h>

int Shell1_main(int argc, char * argv[]) {

    // if (argc == 1) { }

    struct System_Terminal terminal_saved; Stack_clear(terminal_saved);
    struct System_Terminal terminal; Stack_clear(terminal);

    System_ErrorCode errno = System_Terminal_get(&System_Console_StdIn, &terminal_saved);
    if (errno) { System_Console_writeLine("struct Terminal: {0:bool} {1:string}", 2, !errno, enum_getName(typeof(System_ErrorCode), errno)); return false; }
    // Memory_copyTo(&terminal_saved, sizeof(struct System_Terminal), &terminal);
    terminal = terminal_saved;

    // terminal.inputFlags |= System_Terminal_InputFlags_IUTF8;
    terminal.localFlags &= ~(System_Terminal_LocalFlags_ICANONICAL | System_Terminal_LocalFlags_ECHO);
    terminal.controlChars[System_Terminal_ControlChar_MIN] = 1;
    terminal.controlChars[System_Terminal_ControlChar_TIME] = 0;
    //terminal.controlChars[System_Terminal_ControlChar_ERASE] = '\b';
    errno = System_Terminal_set(&System_Console_StdIn, &terminal);
    if (errno) System_Console_writeLine("struct Terminal: set error: {0:bool} {1:string}", 2, !errno, enum_getName(typeof(System_ErrorCode), errno));

    Char8 backspace = terminal.controlChars[System_Terminal_ControlChar_ERASE];

    // Set style to bold, red foreground.
    System_Console_writeLine__string("\e[1;31mHello World.\e[0m");

    Size position = 0, length = 0, n = 0, x = 0, y = 0;
    Char8 input[4096]; Stack_clear(input);
    Char8 text[4096]; Stack_clear(text);

    while (true) {
        length = System_File_read(&System_Console_StdIn, input, 4096);

        for (n = 0; n < length; ++n) {

            if (System_Char8_isPrintable(input[n])) {
                text[position++] = input[n];
                System_Console_write__string_size(input, 1);
                continue;
            }

            if (input[n] == backspace) { // BS is DEL
                if (position) text[--position] = '\0';
                System_Console_write__string("\b \b");
                continue;
            }

            if (input[n] == '\n') { // LF LineFeed, NewLine

                if (String8_equals(text, "exit")) {
                    System_Console_writeLineEmpty();
                    System_Console_writeLine__string("Exit.");
                    goto break_Terminal; 
                }
                if (String8_equals(text, "cursor")) {
                    System_Terminal_getCursorPosition(&System_Console_StdOut);
                    System_Console_writeLineEmpty();
                    Stack_clear(text); position = 0;
                    continue;
                }

                if (position) {
                    System_Console_writeLineEmpty();
                    System_Console_writeLine("What {0:string}?", 1, text);
                    Stack_clear(text); position = 0;
                }
                continue;
            }

            if (input[n] == '\e' && n + 2 < length && input[n + 1] == '[') {
                if (input[n + 2] == 'A') {
                    System_Console_write__string_size(input + n, 3);
                    n += 2; continue;
                }
                if (input[n + 2] == 'B') {
                    System_Console_write__string_size(input + n, 3);
                    n += 2; continue;
                }
                if (input[n + 2] == 'C') {
                    System_Console_write__string_size(input + n, 3);
                    n += 2; continue;
                }
                if (input[n + 2] == 'D') {
                    System_Console_write__string_size(input + n, 3);
                    n += 2; continue;
                }
                SSize report = System_String8_indexOf(input + n, 'R');
                if (report > -1) {
                    x = System_UInt64_parsebase10(input + n + 2);
                    SSize semikolon = System_String8_indexOf(input + n, ';');
                    if (semikolon > -1) {
                        y = System_UInt64_parsebase10(input + n + semikolon + 1);
                        System_Console_writeLine("Cursor Report: x {0:uint} y {1:uint}", 2, x, y);
                        n = report;
                        continue;
                    }
                }
            }

            System_Console_writeHex(length - n, input + n);
            break;
        }

        // System_Console_write__string_size(input + position, length);
    } 
    break_Terminal: ;

    errno = System_Terminal_set__optional(&System_Console_StdIn, &terminal_saved, System_Terminal_ioctls_TCSAFLUSH);
    if (errno) System_Console_writeLine("struct Terminal: saved set error: {0:bool} {1:string}", 2, !errno, enum_getName(typeof(System_ErrorCode), errno));

    return true;
}
