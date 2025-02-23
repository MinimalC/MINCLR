/* Gemeinfrei. Public Domain. */
#if !defined(have_System_Type)
#include "System.Type.h"
#endif
#if !defined(have_System_Terminal)
#define have_System_Terminal

enum {
    System_Terminal_ioctls_TCGETS  = 0x5401,
    System_Terminal_ioctls_TCSETS  = 0x5402,
    System_Terminal_ioctls_TCSETSW  = 0x5403,
    System_Terminal_ioctls_TCSETSF  = 0x5404,

    System_Terminal_ioctls_TIOGETWINSIZE = 0x5413,
    System_Terminal_ioctls_TIOSETWINSIZE = 0x5414,    

    System_Terminal_ioctls_TCSANOW = 0,
    System_Terminal_ioctls_TCSADRAIN = 1,
    System_Terminal_ioctls_TCSAFLUSH = 2,

    System_Terminal_ioctls_TIOCSTI = 0x5412, /* Faking input: Inserts the given byte in the input queue. */

    System_Terminal_InputFlags_IGNBRK = (1 << 0),   /* Ignore break condition.  */
    System_Terminal_InputFlags_BRKINT = (1 << 1),    /* Signal interrupt on break.  */
    System_Terminal_InputFlags_IGNPAR = (1 << 2),    /* Ignore characters with parity errors.  */
    System_Terminal_InputFlags_PARMRK = (1 << 3),    /* Mark parity and framing errors.  */
    System_Terminal_InputFlags_INPCK = (1 << 4),    /* Enable input parity check.  */
    System_Terminal_InputFlags_ISTRIP = (1 << 5),    /* Strip 8th bit off characters.  */
    System_Terminal_InputFlags_INLCR = (1 << 6),    /* Map NL to CR on input.  */
    System_Terminal_InputFlags_IGNCR = (1 << 7),    /* Ignore CR.  */
    System_Terminal_InputFlags_ICRNL = (1 << 8),    /* Map CR to NL on input.  */
    System_Terminal_InputFlags_IUCLC = (1 << 9),    /* Translate upper case input to lower case. */
    System_Terminal_InputFlags_IXON = (1 << 10),    /* Enable start/stop output control.  */
    System_Terminal_InputFlags_IXANY = (1 << 11),    /* Any character will restart after stop.  */
    System_Terminal_InputFlags_IXOFF = (1 << 12),    /* Enable start/stop input control.  */
    System_Terminal_InputFlags_IMAXBEL = (1 << 13),    /* Ring bell when input queue is full.  */
    System_Terminal_InputFlags_IUTF8 = (1 << 14),    /* Use UTF8  */
    
    System_Terminal_OutputFlags_OPOST = 0000001,
    System_Terminal_OutputFlags_OLCUC = 0000002,
    System_Terminal_OutputFlags_ONLCR = 0000004,
    System_Terminal_OutputFlags_OCRNL = 0000010,
    System_Terminal_OutputFlags_ONOCR = 0000020,
    System_Terminal_OutputFlags_ONLRET = 0000040,
    System_Terminal_OutputFlags_OFILL = 0000100,
    System_Terminal_OutputFlags_OFDEL = 0000200,
    System_Terminal_OutputFlags_NLDLY = 0000400,
    System_Terminal_OutputFlags_NL0 = 0000000,
    System_Terminal_OutputFlags_NL1 = 0000400,
    System_Terminal_OutputFlags_CRDLY = 0003000,
    System_Terminal_OutputFlags_CR0 = 0000000,
    System_Terminal_OutputFlags_CR1 = 0001000,
    System_Terminal_OutputFlags_CR2 = 0002000,
    System_Terminal_OutputFlags_CR3 = 0003000,
    System_Terminal_OutputFlags_TABDLY = 0014000,
    System_Terminal_OutputFlags_TAB0 = 0000000,
    System_Terminal_OutputFlags_TAB1 = 0004000,
    System_Terminal_OutputFlags_TAB2 = 0010000,
    System_Terminal_OutputFlags_TAB3 = 0014000,
    System_Terminal_OutputFlags_XTABS = 0014000,
    System_Terminal_OutputFlags_BSDLY = 0020000,
    System_Terminal_OutputFlags_BS0 = 0000000,
    System_Terminal_OutputFlags_BS1 = 0020000,
    System_Terminal_OutputFlags_VTDLY = 0040000,
    System_Terminal_OutputFlags_VT0 = 0000000,
    System_Terminal_OutputFlags_VT1 = 0040000,
    System_Terminal_OutputFlags_FFDLY = 0100000,
    System_Terminal_OutputFlags_FF0 = 0000000,
    System_Terminal_OutputFlags_FF1 = 0100000,

    System_Terminal_ControlFlags_CSIZE = 0000060,
    System_Terminal_ControlFlags_CS5 = 0000000,
    System_Terminal_ControlFlags_CS6 = 0000020,
    System_Terminal_ControlFlags_CS7 = 0000040,
    System_Terminal_ControlFlags_CS8 = 0000060,
    System_Terminal_ControlFlags_CSTOPB = 0000100,
    System_Terminal_ControlFlags_CREAD = 0000200,
    System_Terminal_ControlFlags_PARENB = 0000400,
    System_Terminal_ControlFlags_PARODD = 0001000,
    System_Terminal_ControlFlags_HUPCL = 0002000,
    System_Terminal_ControlFlags_CLOCAL = 0004000,
    System_Terminal_ControlFlags_CBAUD = 0010017,
    System_Terminal_ControlFlags_CBAUDEX = 0010000,
    System_Terminal_ControlFlags_CIBAUD = 002003600000,
    System_Terminal_ControlFlags_CMSPAR = 010000000000,
    System_Terminal_ControlFlags_CRTSCTS = 020000000000,
    System_Terminal_ControlFlags_B57600 = 0010001,
    System_Terminal_ControlFlags_B115200 = 0010002,
    System_Terminal_ControlFlags_B230400 = 0010003,
    System_Terminal_ControlFlags_B460800 = 0010004,
    System_Terminal_ControlFlags_B500000 = 0010005,
    System_Terminal_ControlFlags_B576000 = 0010006,
    System_Terminal_ControlFlags_B921600 = 0010007,
    System_Terminal_ControlFlags_B1000000 = 0010010,
    System_Terminal_ControlFlags_B1152000 = 0010011,
    System_Terminal_ControlFlags_B1500000 = 0010012,
    System_Terminal_ControlFlags_B2000000 = 0010013,
    System_Terminal_ControlFlags_B2500000 = 0010014,
    System_Terminal_ControlFlags_B3000000 = 0010015,
    System_Terminal_ControlFlags_B3500000 = 0010016,
    System_Terminal_ControlFlags_B4000000 = 0010017,

    System_Terminal_LocalFlags_ISIGNAL = 0000001,
    System_Terminal_LocalFlags_ICANONICAL = 0000002,
    System_Terminal_LocalFlags_XCASE = 0000004,
    System_Terminal_LocalFlags_ECHO = 0000010,
    System_Terminal_LocalFlags_ECHOE = 0000020,
    System_Terminal_LocalFlags_ECHOK = 0000040,
    System_Terminal_LocalFlags_ECHONL = 0000100,
    System_Terminal_LocalFlags_NOFLSH = 0000200,
    System_Terminal_LocalFlags_TOSTOP = 0000400,
    System_Terminal_LocalFlags_ECHOCTL = 0001000,
    System_Terminal_LocalFlags_ECHOPRT = 0002000,
    System_Terminal_LocalFlags_ECHOKE = 0004000,
    System_Terminal_LocalFlags_FLUSHO = 0010000,
    System_Terminal_LocalFlags_PENDIN = 0040000,
    System_Terminal_LocalFlags_IEXTEND = 0100000,
    System_Terminal_LocalFlags_EXTPROC = 0200000,

    System_Terminal_ControlChar_INTERRUPT = 0, /* Interrupt character [ISIGNAL].  */
    System_Terminal_ControlChar_QUIT = 1, /* Quit character [ISIGNAL].  */
    System_Terminal_ControlChar_ERASE = 2, /* Erase character [ICANONICAL].  */
    System_Terminal_ControlChar_KILL = 3, /* Kill-line character [ICANONICAL].  */
    System_Terminal_ControlChar_EOF = 4, /* End-of-file character [ICANONICAL].  */
    System_Terminal_ControlChar_TIME = 5, /* Time-out value (tenths of a second) [!ICANONICAL].  */
    System_Terminal_ControlChar_MIN = 6, /* Minimum number of bytes read at once [!ICANONICAL].  */
    System_Terminal_ControlChar_SWTC = 7,
    System_Terminal_ControlChar_START = 8, /* Start (X-ON) character [IXON, IXOFF].  */
    System_Terminal_ControlChar_STOP = 9, /* Stop (X-OFF) character [IXON, IXOFF].  */
    System_Terminal_ControlChar_SUSPEND = 10, /* Suspend character [ISIGNAL].  */
    System_Terminal_ControlChar_EOL = 11, /* End-of-line character [ICANONICAL].  */
    System_Terminal_ControlChar_REPRINT = 12, /* Reprint-line character [ICANONICAL].  */
    System_Terminal_ControlChar_DISCARD = 13, /* Discard character [IEXTEND].  */
    System_Terminal_ControlChar_WORDERASE = 14, /* Word-erase character [ICANONICAL].  */
    System_Terminal_ControlChar_LITERALNEXT = 15, /* Literal-next character [IEXTEND].  */
    System_Terminal_ControlChar_EOL2 = 16, /* Second EOL character [ICANONICAL].  */
    /* System_Terminal_ControlChar_VDSUSP = 11, Delayed suspend character [ISIGNAL].  */    
    /* System_Terminal_ControlChar_VSTATUS = 18, Status character [ICANONICAL].  */  

    System_Terminal_LineDiscipline_TTY = 0,
    System_Terminal_LineDiscipline_SLIP = 1,
    System_Terminal_LineDiscipline_MOUSE = 2,
    System_Terminal_LineDiscipline_PPP = 3,
    System_Terminal_LineDiscipline_STRIP = 4,
    System_Terminal_LineDiscipline_AX25 = 5,
    System_Terminal_LineDiscipline_X25 = 6,	/* X.25 async  */
    System_Terminal_LineDiscipline_6PACK = 7,
    System_Terminal_LineDiscipline_MASC = 8,	/* Mobitex module  */
    System_Terminal_LineDiscipline_R3964 = 9,	/* Simatic R3964 module  */
    System_Terminal_LineDiscipline_PROFIBUS_FDL = 10,	/* Profibus  */
    System_Terminal_LineDiscipline_IRDA = 11,	/* Linux IR  */
    System_Terminal_LineDiscipline_SMSBLOCK = 12,	/* SMS block mode  */
    System_Terminal_LineDiscipline_HDLC = 13,	/* synchronous HDLC  */
    System_Terminal_LineDiscipline_SYNC_PPP = 14,	/* synchronous PPP  */
    System_Terminal_LineDiscipline_HCI = 15,	/* Bluetooth HCI UART  */  
};

/* Type of terminal control flag masks.  */
typedef unsigned int System_Terminal_Flag;

/* Type of control characters.  */
typedef unsigned char System_Terminal_ControlChar;

/* Type of baud rate specifiers.  */
typedef unsigned int System_Terminal_Speed;

typedef struct System_Terminal_WindowSize {
    unsigned short rows;
    unsigned short columns;
    unsigned short x;   /* unused */
    unsigned short y;   /* unused */
} * System_Terminal_WindowSize;

typedef System_fixed struct System_Terminal {

    System_Terminal_Flag inputFlags;
    System_Terminal_Flag outputFlags;
    System_Terminal_Flag controlFlags;
    System_Terminal_Flag localFlags;
    System_Terminal_ControlChar lineDiscipline;
    System_Terminal_ControlChar controlChars[32];

    System_Terminal_Speed inputSpeed;
    System_Terminal_Speed outputSpeed;

}  * System_Terminal;

export struct System_Type  System_TerminalType;

export System_Bool System_Terminal_isTTY(System_File that);
export System_ErrorCode System_Terminal_get(System_File that, System_Terminal terminal);
export System_ErrorCode System_Terminal_set(System_File that, System_Terminal terminal);
export System_ErrorCode System_Terminal_set__optional(System_File that, System_Terminal terminal, System_Terminal_Flag optional);
export System_ErrorCode System_Terminal_getWindowSize(System_File that, System_Terminal_WindowSize window);
export System_ErrorCode System_Terminal_setWindowSize(System_File that, System_Terminal_WindowSize window);
export System_ErrorCode System_Terminal_setInput(System_File that, System_String8 string);
export void System_Terminal_reset(System_File that);
export void System_Terminal_saveCursor(System_File that);
export void System_Terminal_restoreCursor(System_File that);
export void System_Terminal_insertBlankChars(System_File that, System_Size n);
export void System_Terminal_insertBlankRows(System_File that, System_Size n);
export void System_Terminal_moveUp(System_File that, System_Size n);
export void System_Terminal_moveDown(System_File that, System_Size n);
export void System_Terminal_moveRight(System_File that, System_Size n);
export void System_Terminal_moveLeft(System_File that, System_Size n);
export void System_Terminal_move(System_File that, System_Size row, System_Size column);
export void System_Terminal_deleteRows(System_File that, System_Size n);
export void System_Terminal_deleteColumns(System_File that, System_Size n);
export void System_Terminal_eraseColumns(System_File that, System_Size n);
export void System_Terminal_version(System_File that);
export void System_Terminal_status(System_File that);
export void System_Terminal_getCursorPosition(System_File that);

#if defined(using_System)
#define Terminal  System_Terminal
#define TerminalType  System_TerminalType
#endif
#endif
