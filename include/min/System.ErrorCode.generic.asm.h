/* Gemeinfrei. Public Domain. */

/* #include <asm-generic/errno.h> */
#if !defined(have_generic_System_ErrorCode)
#define have_generic_System_ErrorCode
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#define have_ASM_GENERIC_ERRNO_BASE_H
#define have_ASM_GENERIC_ERRNO_H

#define  System_ErrorCode_EPERM  1
#define  System_ErrorCode_ENOENT  2
#define  System_ErrorCode_ESRCH  3
#define  System_ErrorCode_EINTR  4
#define  System_ErrorCode_EIO  5
#define  System_ErrorCode_ENXIO  6
#define  System_ErrorCode_E2BIG  7
#define  System_ErrorCode_ENOEXEC  8
#define  System_ErrorCode_EBADF  9
#define  System_ErrorCode_ECHILD  10
#define  System_ErrorCode_EAGAIN  11
#define  System_ErrorCode_ENOMEM  12
#define  System_ErrorCode_EACCES  13
#define  System_ErrorCode_EFAULT  14
#define  System_ErrorCode_ENOTBLK  15
#define  System_ErrorCode_EBUSY  16
#define  System_ErrorCode_EEXIST  17
#define  System_ErrorCode_EXDEV  18
#define  System_ErrorCode_ENODEV  19
#define  System_ErrorCode_ENOTDIR  20
#define  System_ErrorCode_EISDIR  21
#define  System_ErrorCode_EINVAL  22
#define  System_ErrorCode_ENFILE  23
#define  System_ErrorCode_EMFILE  24
#define  System_ErrorCode_ENOTTY  25
#define  System_ErrorCode_ETXTBSY  26
#define  System_ErrorCode_EFBIG  27
#define  System_ErrorCode_ENOSPC  28
#define  System_ErrorCode_ESPIPE  29
#define  System_ErrorCode_EROFS  30
#define  System_ErrorCode_EMLINK  31
#define  System_ErrorCode_EPIPE  32
#define  System_ErrorCode_EDOM  33
#define  System_ErrorCode_ERANGE  34

/* #include <asm-generic/errno-base.h> */

#define  System_ErrorCode_EDEADLK  35
#define  System_ErrorCode_ENAMETOOLONG  36
#define  System_ErrorCode_ENOLCK  37

/*
 * This error code is special: arch syscall entry code will return
 * -ENOSYS if users try to call a syscall that doesn't exist.  To keep
 * failures of syscalls that really do exist distinguishable from
 * failures due to attempts to use a nonexistent syscall, syscall
 * implementations should refrain from returning -ENOSYS.
 */
#define  System_ErrorCode_ENOSYS  38

#define  System_ErrorCode_ENOTEMPTY  39
#define  System_ErrorCode_ELOOP  40
#define  System_ErrorCode_EWOULDBLOCK  System_ErrorCode_EAGAIN
#define  System_ErrorCode_ENOMSG  42
#define  System_ErrorCode_EIDRM  43
#define  System_ErrorCode_ECHRNG  44
#define  System_ErrorCode_EL2NSYNC  45
#define  System_ErrorCode_EL3HLT  46
#define  System_ErrorCode_EL3RST  47
#define  System_ErrorCode_ELNRNG  48
#define  System_ErrorCode_EUNATCH  49
#define  System_ErrorCode_ENOCSI  50
#define  System_ErrorCode_EL2HLT  51
#define  System_ErrorCode_EBADE  52
#define  System_ErrorCode_EBADR  53
#define  System_ErrorCode_EXFULL  54
#define  System_ErrorCode_ENOANO  55
#define  System_ErrorCode_EBADRQC  56
#define  System_ErrorCode_EBADSLT  57

#define  System_ErrorCode_EDEADLOCK  System_ErrorCode_EDEADLK

#define  System_ErrorCode_EBFONT  59
#define  System_ErrorCode_ENOSTR  60
#define  System_ErrorCode_ENODATA  61
#define  System_ErrorCode_ETIME  62
#define  System_ErrorCode_ENOSR  63
#define  System_ErrorCode_ENONET  64
#define  System_ErrorCode_ENOPKG  65
#define  System_ErrorCode_EREMOTE  66
#define  System_ErrorCode_ENOLINK  67
#define  System_ErrorCode_EADV  68
#define  System_ErrorCode_ESRMNT  69
#define  System_ErrorCode_ECOMM  70
#define  System_ErrorCode_EPROTO  71
#define  System_ErrorCode_EMULTIHOP  72
#define  System_ErrorCode_EDOTDOT  73
#define  System_ErrorCode_EBADMSG  74
#define  System_ErrorCode_EOVERFLOW  75
#define  System_ErrorCode_ENOTUNIQ  76
#define  System_ErrorCode_EBADFD  77
#define  System_ErrorCode_EREMCHG  78
#define  System_ErrorCode_ELIBACC  79
#define  System_ErrorCode_ELIBBAD  80
#define  System_ErrorCode_ELIBSCN  81
#define  System_ErrorCode_ELIBMAX  82
#define  System_ErrorCode_ELIBEXEC  83
#define  System_ErrorCode_EILSEQ  84
#define  System_ErrorCode_ERESTART  85
#define  System_ErrorCode_ESTRPIPE  86
#define  System_ErrorCode_EUSERS  87
#define  System_ErrorCode_ENOTSOCK  88
#define  System_ErrorCode_EDESTADDRREQ  89
#define  System_ErrorCode_EMSGSIZE  90
#define  System_ErrorCode_EPROTOTYPE  91
#define  System_ErrorCode_ENOPROTOOPT  92
#define  System_ErrorCode_EPROTONOSUPPORT  93
#define  System_ErrorCode_ESOCKTNOSUPPORT  94
#define  System_ErrorCode_EOPNOTSUPP  95
#define  System_ErrorCode_EPFNOSUPPORT  96
#define  System_ErrorCode_EAFNOSUPPORT  97
#define  System_ErrorCode_EADDRINUSE  98
#define  System_ErrorCode_EADDRNOTAVAIL  99
#define  System_ErrorCode_ENETDOWN  100
#define  System_ErrorCode_ENETUNREACH  101
#define  System_ErrorCode_ENETRESET  102
#define  System_ErrorCode_ECONNABORTED  103
#define  System_ErrorCode_ECONNRESET  104
#define  System_ErrorCode_ENOBUFS  105
#define  System_ErrorCode_EISCONN  106
#define  System_ErrorCode_ENOTCONN  107
#define  System_ErrorCode_ESHUTDOWN  108
#define  System_ErrorCode_ETOOMANYREFS  109
#define  System_ErrorCode_ETIMEDOUT  110
#define  System_ErrorCode_ECONNREFUSED  111
#define  System_ErrorCode_EHOSTDOWN  112
#define  System_ErrorCode_EHOSTUNREACH  113
#define  System_ErrorCode_EALREADY  114
#define  System_ErrorCode_EINPROGRESS  115
#define  System_ErrorCode_ESTALE  116
#define  System_ErrorCode_EUCLEAN  117
#define  System_ErrorCode_ENOTNAM  118
#define  System_ErrorCode_ENAVAIL  119
#define  System_ErrorCode_EISNAM  120
#define  System_ErrorCode_EREMOTEIO  121
#define  System_ErrorCode_EDQUOT  122

#define  System_ErrorCode_ENOMEDIUM  123
#define  System_ErrorCode_EMEDIUMTYPE  124
#define  System_ErrorCode_ECANCELED  125
#define  System_ErrorCode_ENOKEY  126
#define  System_ErrorCode_EKEYEXPIRED  127
#define  System_ErrorCode_EKEYREVOKED  128
#define  System_ErrorCode_EKEYREJECTED  129

/* for robust mutexes */
#define  System_ErrorCode_EOWNERDEAD  130
#define  System_ErrorCode_ENOTRECOVERABLE  131

#define  System_ErrorCode_ERFKILL  132

#define  System_ErrorCode_EHWPOISON  133

#elif defined(code_System_ErrorCode)
[0] = { .name = "EPERM", .value = System_ErrorCode_EPERM },
[1] = { .name = "ENOENT", .value = System_ErrorCode_ENOENT },
[2] = { .name = "ESRCH", .value = System_ErrorCode_ESRCH },
[3] = { .name = "EINTR", .value = System_ErrorCode_EINTR },
[4] = { .name = "EIO", .value = System_ErrorCode_EIO },
[5] = { .name = "ENXIO", .value = System_ErrorCode_ENXIO },
[6] = { .name = "E2BIG", .value = System_ErrorCode_E2BIG },
[7] = { .name = "ENOEXEC", .value = System_ErrorCode_ENOEXEC },
[8] = { .name = "EBADF", .value = System_ErrorCode_EBADF },
[9] = { .name = "ECHILD", .value = System_ErrorCode_ECHILD },
[10] = { .name = "EAGAIN", .value = System_ErrorCode_EAGAIN },
[11] = { .name = "ENOMEM", .value = System_ErrorCode_ENOMEM },
[12] = { .name = "EACCES", .value = System_ErrorCode_EACCES },
[13] = { .name = "EFAULT", .value = System_ErrorCode_EFAULT },
[14] = { .name = "ENOTBLK", .value = System_ErrorCode_ENOTBLK },
[15] = { .name = "EBUSY", .value = System_ErrorCode_EBUSY },
[16] = { .name = "EEXIST", .value = System_ErrorCode_EEXIST },
[17] = { .name = "EXDEV", .value = System_ErrorCode_EXDEV },
[18] = { .name = "ENODEV", .value = System_ErrorCode_ENODEV },
[19] = { .name = "ENOTDIR", .value = System_ErrorCode_ENOTDIR },
[20] = { .name = "EISDIR", .value = System_ErrorCode_EISDIR },
[21] = { .name = "EINVAL", .value = System_ErrorCode_EINVAL },
[22] = { .name = "ENFILE", .value = System_ErrorCode_ENFILE },
[23] = { .name = "EMFILE", .value = System_ErrorCode_EMFILE },
[24] = { .name = "ENOTTY", .value = System_ErrorCode_ENOTTY },
[25] = { .name = "ETXTBSY", .value = System_ErrorCode_ETXTBSY },
[26] = { .name = "EFBIG", .value = System_ErrorCode_EFBIG },
[27] = { .name = "ENOSPC", .value = System_ErrorCode_ENOSPC },
[28] = { .name = "ESPIPE", .value = System_ErrorCode_ESPIPE },
[29] = { .name = "EROFS", .value = System_ErrorCode_EROFS },
[30] = { .name = "EMLINK", .value = System_ErrorCode_EMLINK },
[31] = { .name = "EPIPE", .value = System_ErrorCode_EPIPE },
[32] = { .name = "EDOM", .value = System_ErrorCode_EDOM },
[33] = { .name = "ERANGE", .value = System_ErrorCode_ERANGE },

[34] = { .name = "EDEADLK", .value = System_ErrorCode_EDEADLK },
[35] = { .name = "ENAMETOOLONG", .value = System_ErrorCode_ENAMETOOLONG },
[36] = { .name = "ENOLCK", .value = System_ErrorCode_ENOLCK },
[37] = { .name = "ENOSYS", .value = System_ErrorCode_ENOSYS },
[38] = { .name = "ENOTEMPTY", .value = System_ErrorCode_ENOTEMPTY },
[39] = { .name = "ELOOP", .value = System_ErrorCode_ELOOP },
[40] = { .name = "EWOULDBLOCK", .value = System_ErrorCode_EWOULDBLOCK },
[41] = { .name = "ENOMSG", .value = System_ErrorCode_ENOMSG },
[42] = { .name = "EIDRM", .value = System_ErrorCode_EIDRM },
[43] = { .name = "ECHRNG", .value = System_ErrorCode_ECHRNG },
[44] = { .name = "EL2NSYNC", .value = System_ErrorCode_EL2NSYNC },
[45] = { .name = "EL3HLT", .value = System_ErrorCode_EL3HLT },
[46] = { .name = "EL3RST", .value = System_ErrorCode_EL3RST },
[47] = { .name = "ELNRNG", .value = System_ErrorCode_ELNRNG },
[48] = { .name = "EUNATCH", .value = System_ErrorCode_EUNATCH },
[49] = { .name = "ENOCSI", .value = System_ErrorCode_ENOCSI },
[50] = { .name = "EL2HLT", .value = System_ErrorCode_EL2HLT },
[51] = { .name = "EBADE", .value = System_ErrorCode_EBADE },
[52] = { .name = "EBADR", .value = System_ErrorCode_EBADR },
[53] = { .name = "EXFULL", .value = System_ErrorCode_EXFULL },
[54] = { .name = "ENOANO", .value = System_ErrorCode_ENOANO },
[55] = { .name = "EBADRQC", .value = System_ErrorCode_EBADRQC },
[56] = { .name = "EBADSLT", .value = System_ErrorCode_EBADSLT },
[57] = { .name = "EDEADLOCK", .value = System_ErrorCode_EDEADLOCK },
[58] = { .name = "EBFONT", .value = System_ErrorCode_EBFONT },
[59] = { .name = "ENOSTR", .value = System_ErrorCode_ENOSTR },
[60] = { .name = "ENODATA", .value = System_ErrorCode_ENODATA },
[61] = { .name = "ETIME", .value = System_ErrorCode_ETIME },
[62] = { .name = "ENOSR", .value = System_ErrorCode_ENOSR },
[63] = { .name = "ENONET", .value = System_ErrorCode_ENONET },
[64] = { .name = "ENOPKG", .value = System_ErrorCode_ENOPKG },
[65] = { .name = "EREMOTE", .value = System_ErrorCode_EREMOTE },
[66] = { .name = "ENOLINK", .value = System_ErrorCode_ENOLINK },
[67] = { .name = "EADV", .value = System_ErrorCode_EADV },
[68] = { .name = "ESRMNT", .value = System_ErrorCode_ESRMNT },
[69] = { .name = "ECOMM", .value = System_ErrorCode_ECOMM },
[70] = { .name = "EPROTO", .value = System_ErrorCode_EPROTO },
[71] = { .name = "EMULTIHOP", .value = System_ErrorCode_EMULTIHOP },
[72] = { .name = "EDOTDOT", .value = System_ErrorCode_EDOTDOT },
[73] = { .name = "EBADMSG", .value = System_ErrorCode_EBADMSG },
[74] = { .name = "EOVERFLOW", .value = System_ErrorCode_EOVERFLOW },
[75] = { .name = "ENOTUNIQ", .value = System_ErrorCode_ENOTUNIQ },
[76] = { .name = "EBADFD", .value = System_ErrorCode_EBADFD },
[77] = { .name = "EREMCHG", .value = System_ErrorCode_EREMCHG },
[78] = { .name = "ELIBACC", .value = System_ErrorCode_ELIBACC },
[79] = { .name = "ELIBBAD", .value = System_ErrorCode_ELIBBAD },
[80] = { .name = "ELIBSCN", .value = System_ErrorCode_ELIBSCN },
[81] = { .name = "ELIBMAX", .value = System_ErrorCode_ELIBMAX },
[82] = { .name = "ELIBEXEC", .value = System_ErrorCode_ELIBEXEC },
[83] = { .name = "EILSEQ", .value = System_ErrorCode_EILSEQ },
[84] = { .name = "ERESTART", .value = System_ErrorCode_ERESTART },
[85] = { .name = "ESTRPIPE", .value = System_ErrorCode_ESTRPIPE },
[86] = { .name = "EUSERS", .value = System_ErrorCode_EUSERS },
[87] = { .name = "ENOTSOCK", .value = System_ErrorCode_ENOTSOCK },
[88] = { .name = "EDESTADDRREQ", .value = System_ErrorCode_EDESTADDRREQ },
[89] = { .name = "EMSGSIZE", .value = System_ErrorCode_EMSGSIZE },
[90] = { .name = "EPROTOTYPE", .value = System_ErrorCode_EPROTOTYPE },
[91] = { .name = "ENOPROTOOPT", .value = System_ErrorCode_ENOPROTOOPT },
[92] = { .name = "EPROTONOSUPPORT", .value = System_ErrorCode_EPROTONOSUPPORT },
[93] = { .name = "ESOCKTNOSUPPORT", .value = System_ErrorCode_ESOCKTNOSUPPORT },
[94] = { .name = "EOPNOTSUPP", .value = System_ErrorCode_EOPNOTSUPP },
[95] = { .name = "EPFNOSUPPORT", .value = System_ErrorCode_EPFNOSUPPORT },
[96] = { .name = "EAFNOSUPPORT", .value = System_ErrorCode_EAFNOSUPPORT },
[97] = { .name = "EADDRINUSE", .value = System_ErrorCode_EADDRINUSE },
[98] = { .name = "EADDRNOTAVAIL", .value = System_ErrorCode_EADDRNOTAVAIL },
[99] = { .name = "ENETDOWN", .value = System_ErrorCode_ENETDOWN },
[100] = { .name = "ENETUNREACH", .value = System_ErrorCode_ENETUNREACH },
[101] = { .name = "ENETRESET", .value = System_ErrorCode_ENETRESET },
[102] = { .name = "ECONNABORTED", .value = System_ErrorCode_ECONNABORTED },
[103] = { .name = "ECONNRESET", .value = System_ErrorCode_ECONNRESET },
[104] = { .name = "ENOBUFS", .value = System_ErrorCode_ENOBUFS },
[105] = { .name = "EISCONN", .value = System_ErrorCode_EISCONN },
[106] = { .name = "ENOTCONN", .value = System_ErrorCode_ENOTCONN },
[107] = { .name = "ESHUTDOWN", .value = System_ErrorCode_ESHUTDOWN },
[108] = { .name = "ETOOMANYREFS", .value = System_ErrorCode_ETOOMANYREFS },
[109] = { .name = "ETIMEDOUT", .value = System_ErrorCode_ETIMEDOUT },
[110] = { .name = "ECONNREFUSED", .value = System_ErrorCode_ECONNREFUSED },
[111] = { .name = "EHOSTDOWN", .value = System_ErrorCode_EHOSTDOWN },
[112] = { .name = "EHOSTUNREACH", .value = System_ErrorCode_EHOSTUNREACH },
[113] = { .name = "EALREADY", .value = System_ErrorCode_EALREADY },
[114] = { .name = "EINPROGRESS", .value = System_ErrorCode_EINPROGRESS },
[115] = { .name = "ESTALE", .value = System_ErrorCode_ESTALE },
[116] = { .name = "EUCLEAN", .value = System_ErrorCode_EUCLEAN },
[117] = { .name = "ENOTNAM", .value = System_ErrorCode_ENOTNAM },
[118] = { .name = "ENAVAIL", .value = System_ErrorCode_ENAVAIL },
[119] = { .name = "EISNAM", .value = System_ErrorCode_EISNAM },
[120] = { .name = "EREMOTEIO", .value = System_ErrorCode_EREMOTEIO },
[121] = { .name = "EDQUOT", .value = System_ErrorCode_EDQUOT },
[122] = { .name = "ENOMEDIUM", .value = System_ErrorCode_ENOMEDIUM },
[123] = { .name = "EMEDIUMTYPE", .value = System_ErrorCode_EMEDIUMTYPE },
[124] = { .name = "ECANCELED", .value = System_ErrorCode_ECANCELED },
[125] = { .name = "ENOKEY", .value = System_ErrorCode_ENOKEY },
[126] = { .name = "EKEYEXPIRED", .value = System_ErrorCode_EKEYEXPIRED },
[127] = { .name = "EKEYREVOKED", .value = System_ErrorCode_EKEYREVOKED },
[128] = { .name = "EKEYREJECTED", .value = System_ErrorCode_EKEYREJECTED },
[129] = { .name = "EOWNERDEAD", .value = System_ErrorCode_EOWNERDEAD },
[130] = { .name = "ENOTRECOVERABLE", .value = System_ErrorCode_ENOTRECOVERABLE },
[131] = { .name = "ERFKILL", .value = System_ErrorCode_ERFKILL },
[132] = { .name = "EHWPOISON", .value = System_ErrorCode_EHWPOISON },
#define System_ErrorCodeType_fields_length_DEFAULT  133
#endif
