#define using_System
#include <min/System.h>

int System_Runtime_main(int argc, char * argv[]) {

    struct System_Terminal terminal; Stack_clear(terminal);

    File file = null;
    if (argc == 1) {
        file = System_File_open("/dev/tty", System_File_Mode_readOnly);
        if (file) System_Console_writeLine__string("Using /dev/tty:");
    }
    else if (argc == 2 && !String8_equals(argv[1], "-")) {
        file = System_File_open(argv[1], System_File_Mode_readOnly);
        if (file) System_Console_writeLine("Using {0:string}:", 1, argv[1]);
    }
    if (!file) {
        file = &System_Console_StdIn;
        System_Console_writeLine__string("Using System_Console_StdIn:");
    }

    System_ErrorCode errno = System_Terminal_get(file, &terminal);
    System_Console_writeLine("struct Terminal: {0:bool} {1:string}", 2, !errno, enum_getName(typeof(System_ErrorCode), errno));
    if (errno) return false;

    System_Console_write__string("\tinputFlags: ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IGNBRK) System_Console_write__string("IGNBRK, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_BRKINT) System_Console_write__string("BRKINT, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IGNPAR) System_Console_write__string("IGNPAR, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_PARMRK) System_Console_write__string("PARMRK, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_INPCK) System_Console_write__string("INPCK, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_ISTRIP) System_Console_write__string("ISTRIP, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_INLCR) System_Console_write__string("INLCR, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IGNCR) System_Console_write__string("IGNCR, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_ICRNL) System_Console_write__string("ICRNL, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IXON) System_Console_write__string("IXON, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IXOFF) System_Console_write__string("IXOFF, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IXANY) System_Console_write__string("IXANY, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IMAXBEL) System_Console_write__string("IMAXBEL, ");
    if (terminal.inputFlags & System_Terminal_InputFlags_IUCLC) System_Console_write__string("IUCLC, ");
    System_Console_writeLineEmpty();

    System_Console_write__string("\toutputFlags: ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_OPOST) System_Console_write__string("OPOST, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_OLCUC) System_Console_write__string("OLCUC, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_ONLCR) System_Console_write__string("ONLCR, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_OCRNL) System_Console_write__string("OCRNL, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_ONOCR) System_Console_write__string("ONOCR, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_ONLRET) System_Console_write__string("ONLRET, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_OFILL) System_Console_write__string("OFILL, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_OFDEL) System_Console_write__string("OFDEL, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_NLDLY) System_Console_write__string("NLDLY, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_NL1) System_Console_write__string("NL1, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_CRDLY) System_Console_write__string("CRDLY, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_CR1) System_Console_write__string("CR1, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_CR2) System_Console_write__string("CR2, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_CR3) System_Console_write__string("CR3, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_TABDLY) System_Console_write__string("TABDLY, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_TAB1) System_Console_write__string("TAB1, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_TAB2) System_Console_write__string("TAB2, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_TAB3) System_Console_write__string("TAB3, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_XTABS) System_Console_write__string("XTABS, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_BSDLY) System_Console_write__string("BSDLY, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_BS1) System_Console_write__string("BS1, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_VTDLY) System_Console_write__string("VTDLY, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_VT1) System_Console_write__string("VT1, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_FFDLY) System_Console_write__string("FFDLY, ");
    if (terminal.outputFlags & System_Terminal_OutputFlags_FF1) System_Console_write__string("FF1, ");
    System_Console_writeLineEmpty();

    System_Console_write__string("\tcontrolFlags: ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CSIZE) System_Console_write__string("CSIZE, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CS5) System_Console_write__string("CS5, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CS6) System_Console_write__string("CS6, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CS7) System_Console_write__string("CS7, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CS8) System_Console_write__string("CS8, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CSTOPB) System_Console_write__string("CSTOPB, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CREAD) System_Console_write__string("CREAD, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_PARENB) System_Console_write__string("PARENB, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_PARODD) System_Console_write__string("PARODD, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_HUPCL) System_Console_write__string("HUPCL, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CLOCAL) System_Console_write__string("CLOCAL, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CBAUD) System_Console_write__string("CBAUD, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CBAUDEX) System_Console_write__string("CBAUDEX, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CIBAUD) System_Console_write__string("CIBAUD, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CMSPAR) System_Console_write__string("CMSPAR, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_CRTSCTS) System_Console_write__string("CRTSCTS, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B57600) System_Console_write__string("B57600, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B115200) System_Console_write__string("B115200, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B230400) System_Console_write__string("B230400, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B460800) System_Console_write__string("B460800, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B500000) System_Console_write__string("B500000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B576000) System_Console_write__string("B576000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B921600) System_Console_write__string("B921600, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B1000000) System_Console_write__string("B1000000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B1152000) System_Console_write__string("B1152000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B1500000) System_Console_write__string("B1500000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B2000000) System_Console_write__string("B2000000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B2500000) System_Console_write__string("B2500000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B3000000) System_Console_write__string("B3000000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B3500000) System_Console_write__string("B3500000, ");
    if (terminal.controlFlags & System_Terminal_ControlFlags_B4000000) System_Console_write__string("B4000000, ");
    System_Console_writeLineEmpty();

    System_Console_write__string("\tlocalFlags: ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ISIGNAL) System_Console_write__string("ISIGNAL, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ICANONICAL) System_Console_write__string("ICANONICAL, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_XCASE) System_Console_write__string("XCASE, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ECHO) System_Console_write__string("ECHO, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ECHOE) System_Console_write__string("ECHOE, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ECHOK) System_Console_write__string("ECHOK, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ECHONL) System_Console_write__string("ECHONL, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_NOFLSH) System_Console_write__string("NOFLSH, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_TOSTOP) System_Console_write__string("TOSTOP, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ECHOCTL) System_Console_write__string("ECHOCTL, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ECHOPRT) System_Console_write__string("ECHOPRT, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_ECHOKE) System_Console_write__string("ECHOKE, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_FLUSHO) System_Console_write__string("FLUSHO, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_IEXTEND) System_Console_write__string("IEXTEND, ");
    if (terminal.localFlags & System_Terminal_LocalFlags_EXTPROC) System_Console_write__string("EXTPROC, ");
    System_Console_writeLineEmpty();

    System_Console_writeLine("\tlineDiscipline: {0:uint8:hex}", 1, terminal.lineDiscipline);

    System_Console_write__string("\tcontrolChars: ");
    System_Console_write("INTERRUPT {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_INTERRUPT]);
    System_Console_write("QUIT {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_QUIT]);
    System_Console_write("ERASE {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_ERASE]);
    System_Console_write("KILL {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_KILL]);
    System_Console_write("EOF {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_EOF]);
    System_Console_write("TIME {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_TIME]);
    System_Console_write("MIN {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_MIN]);
    System_Console_write("SWTC {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_SWTC]);
    System_Console_write("START {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_START]);
    System_Console_write("STOP {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_STOP]);
    System_Console_write("SUSPEND {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_SUSPEND]);
    System_Console_write("EOL {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_EOL]);
    System_Console_write("REPRINT {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_REPRINT]);
    System_Console_write("DISCARD {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_DISCARD]);
    System_Console_write("WORDERASE {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_WORDERASE]);
    System_Console_write("LITERALNEXT {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_LITERALNEXT]);
    System_Console_write("EOL2 {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_EOL2]);
    // System_Console_write("VDSUSP {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_VDSUSP]);
    // System_Console_write("VSTATUS {0:uint8:hex}, ", 1, terminal.controlChars[System_Terminal_ControlChar_VSTATUS]);
    System_Console_writeLineEmpty();

    System_Console_writeLine("\tspeed: input {0:uint}, output {1:uint}", 2, terminal.inputSpeed, terminal.outputSpeed);

    struct System_Terminal_WindowSize window = { 0, 0, 0, 0 };
    System_Terminal_getWindowSize(&System_Console_StdIn, &window);
    System_Console_writeLine("\tgetWindowSize: rows {0:uint16} columns {1:uint16}", 2, window.rows, window.columns);

    Memory_free(file);

    return true;
}
