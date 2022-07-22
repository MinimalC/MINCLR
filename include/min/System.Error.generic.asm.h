/* Gemeinfrei. Public Domain. */

/* #include <asm-generic/errno.h> */
#if !defined(have_generic_System_Error)
#define have_generic_System_Error
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#define have_ASM_GENERIC_ERRNO_BASE_H
#define have_ASM_GENERIC_ERRNO_H

#define  System_Error_EPERM  1
#define  System_Error_ENOENT  2
#define  System_Error_ESRCH  3
#define  System_Error_EINTR  4
#define  System_Error_EIO  5
#define  System_Error_ENXIO  6
#define  System_Error_E2BIG  7
#define  System_Error_ENOEXEC  8
#define  System_Error_EBADF  9
#define  System_Error_ECHILD  10
#define  System_Error_EAGAIN  11
#define  System_Error_ENOMEM  12
#define  System_Error_EACCES  13
#define  System_Error_EFAULT  14
#define  System_Error_ENOTBLK  15
#define  System_Error_EBUSY  16
#define  System_Error_EEXIST  17
#define  System_Error_EXDEV  18
#define  System_Error_ENODEV  19
#define  System_Error_ENOTDIR  20
#define  System_Error_EISDIR  21
#define  System_Error_EINVAL  22
#define  System_Error_ENFILE  23
#define  System_Error_EMFILE  24
#define  System_Error_ENOTTY  25
#define  System_Error_ETXTBSY  26
#define  System_Error_EFBIG  27
#define  System_Error_ENOSPC  28
#define  System_Error_ESPIPE  29
#define  System_Error_EROFS  30
#define  System_Error_EMLINK  31
#define  System_Error_EPIPE  32
#define  System_Error_EDOM  33
#define  System_Error_ERANGE  34

/* #include <asm-generic/errno-base.h> */

#define  System_Error_EDEADLK  35
#define  System_Error_ENAMETOOLONG  36
#define  System_Error_ENOLCK  37

/*
 * This error code is special: arch syscall entry code will return
 * -ENOSYS if users try to call a syscall that doesn't exist.  To keep
 * failures of syscalls that really do exist distinguishable from
 * failures due to attempts to use a nonexistent syscall, syscall
 * implementations should refrain from returning -ENOSYS.
 */
#define  System_Error_ENOSYS  38

#define  System_Error_ENOTEMPTY  39
#define  System_Error_ELOOP  40
#define  System_Error_EWOULDBLOCK  System_Error_EAGAIN
#define  System_Error_ENOMSG  42
#define  System_Error_EIDRM  43
#define  System_Error_ECHRNG  44
#define  System_Error_EL2NSYNC  45
#define  System_Error_EL3HLT  46
#define  System_Error_EL3RST  47
#define  System_Error_ELNRNG  48
#define  System_Error_EUNATCH  49
#define  System_Error_ENOCSI  50
#define  System_Error_EL2HLT  51
#define  System_Error_EBADE  52
#define  System_Error_EBADR  53
#define  System_Error_EXFULL  54
#define  System_Error_ENOANO  55
#define  System_Error_EBADRQC  56
#define  System_Error_EBADSLT  57

#define  System_Error_EDEADLOCK  System_Error_EDEADLK

#define  System_Error_EBFONT  59
#define  System_Error_ENOSTR  60
#define  System_Error_ENODATA  61
#define  System_Error_ETIME  62
#define  System_Error_ENOSR  63
#define  System_Error_ENONET  64
#define  System_Error_ENOPKG  65
#define  System_Error_EREMOTE  66
#define  System_Error_ENOLINK  67
#define  System_Error_EADV  68
#define  System_Error_ESRMNT  69
#define  System_Error_ECOMM  70
#define  System_Error_EPROTO  71
#define  System_Error_EMULTIHOP  72
#define  System_Error_EDOTDOT  73
#define  System_Error_EBADMSG  74
#define  System_Error_EOVERFLOW  75
#define  System_Error_ENOTUNIQ  76
#define  System_Error_EBADFD  77
#define  System_Error_EREMCHG  78
#define  System_Error_ELIBACC  79
#define  System_Error_ELIBBAD  80
#define  System_Error_ELIBSCN  81
#define  System_Error_ELIBMAX  82
#define  System_Error_ELIBEXEC  83
#define  System_Error_EILSEQ  84
#define  System_Error_ERESTART  85
#define  System_Error_ESTRPIPE  86
#define  System_Error_EUSERS  87
#define  System_Error_ENOTSOCK  88
#define  System_Error_EDESTADDRREQ  89
#define  System_Error_EMSGSIZE  90
#define  System_Error_EPROTOTYPE  91
#define  System_Error_ENOPROTOOPT  92
#define  System_Error_EPROTONOSUPPORT  93
#define  System_Error_ESOCKTNOSUPPORT  94
#define  System_Error_EOPNOTSUPP  95
#define  System_Error_EPFNOSUPPORT  96
#define  System_Error_EAFNOSUPPORT  97
#define  System_Error_EADDRINUSE  98
#define  System_Error_EADDRNOTAVAIL  99
#define  System_Error_ENETDOWN  100
#define  System_Error_ENETUNREACH  101
#define  System_Error_ENETRESET  102
#define  System_Error_ECONNABORTED  103
#define  System_Error_ECONNRESET  104
#define  System_Error_ENOBUFS  105
#define  System_Error_EISCONN  106
#define  System_Error_ENOTCONN  107
#define  System_Error_ESHUTDOWN  108
#define  System_Error_ETOOMANYREFS  109
#define  System_Error_ETIMEDOUT  110
#define  System_Error_ECONNREFUSED  111
#define  System_Error_EHOSTDOWN  112
#define  System_Error_EHOSTUNREACH  113
#define  System_Error_EALREADY  114
#define  System_Error_EINPROGRESS  115
#define  System_Error_ESTALE  116
#define  System_Error_EUCLEAN  117
#define  System_Error_ENOTNAM  118
#define  System_Error_ENAVAIL  119
#define  System_Error_EISNAM  120
#define  System_Error_EREMOTEIO  121
#define  System_Error_EDQUOT  122

#define  System_Error_ENOMEDIUM  123
#define  System_Error_EMEDIUMTYPE  124
#define  System_Error_ECANCELED  125
#define  System_Error_ENOKEY  126
#define  System_Error_EKEYEXPIRED  127
#define  System_Error_EKEYREVOKED  128
#define  System_Error_EKEYREJECTED  129

/* for robust mutexes */
#define  System_Error_EOWNERDEAD  130
#define  System_Error_ENOTRECOVERABLE  131

#define  System_Error_ERFKILL  132

#define  System_Error_EHWPOISON  133

#elif defined(code_System_Error)
[0] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EPERM", .value = System_Error_EPERM },
[1] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOENT", .value = System_Error_ENOENT },
[2] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ESRCH", .value = System_Error_ESRCH },
[3] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EINTR", .value = System_Error_EINTR },
[4] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EIO", .value = System_Error_EIO },
[5] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENXIO", .value = System_Error_ENXIO },
[6] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.E2BIG", .value = System_Error_E2BIG },
[7] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOEXEC", .value = System_Error_ENOEXEC },
[8] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBADF", .value = System_Error_EBADF },
[9] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ECHILD", .value = System_Error_ECHILD },
[10] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EAGAIN", .value = System_Error_EAGAIN },
[11] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOMEM", .value = System_Error_ENOMEM },
[12] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EACCES", .value = System_Error_EACCES },
[13] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EFAULT", .value = System_Error_EFAULT },
[14] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTBLK", .value = System_Error_ENOTBLK },
[15] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBUSY", .value = System_Error_EBUSY },
[16] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EEXIST", .value = System_Error_EEXIST },
[17] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EXDEV", .value = System_Error_EXDEV },
[18] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENODEV", .value = System_Error_ENODEV },
[19] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTDIR", .value = System_Error_ENOTDIR },
[20] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EISDIR", .value = System_Error_EISDIR },
[21] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EINVAL", .value = System_Error_EINVAL },
[22] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENFILE", .value = System_Error_ENFILE },
[23] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EMFILE", .value = System_Error_EMFILE },
[24] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTTY", .value = System_Error_ENOTTY },
[25] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ETXTBSY", .value = System_Error_ETXTBSY },
[26] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EFBIG", .value = System_Error_EFBIG },
[27] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOSPC", .value = System_Error_ENOSPC },
[28] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ESPIPE", .value = System_Error_ESPIPE },
[29] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EROFS", .value = System_Error_EROFS },
[30] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EMLINK", .value = System_Error_EMLINK },
[31] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EPIPE", .value = System_Error_EPIPE },
[32] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EDOM", .value = System_Error_EDOM },
[33] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ERANGE", .value = System_Error_ERANGE },

[34] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EDEADLK", .value = System_Error_EDEADLK },
[35] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENAMETOOLONG", .value = System_Error_ENAMETOOLONG },
[36] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOLCK", .value = System_Error_ENOLCK },
[37] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOSYS", .value = System_Error_ENOSYS },
[38] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTEMPTY", .value = System_Error_ENOTEMPTY },
[39] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ELOOP", .value = System_Error_ELOOP },
[40] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EWOULDBLOCK", .value = System_Error_EWOULDBLOCK },
[41] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOMSG", .value = System_Error_ENOMSG },
[42] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EIDRM", .value = System_Error_EIDRM },
[43] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ECHRNG", .value = System_Error_ECHRNG },
[44] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EL2NSYNC", .value = System_Error_EL2NSYNC },
[45] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EL3HLT", .value = System_Error_EL3HLT },
[46] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EL3RST", .value = System_Error_EL3RST },
[47] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ELNRNG", .value = System_Error_ELNRNG },
[48] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EUNATCH", .value = System_Error_EUNATCH },
[49] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOCSI", .value = System_Error_ENOCSI },
[50] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EL2HLT", .value = System_Error_EL2HLT },
[51] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBADE", .value = System_Error_EBADE },
[52] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBADR", .value = System_Error_EBADR },
[53] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EXFULL", .value = System_Error_EXFULL },
[54] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOANO", .value = System_Error_ENOANO },
[55] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBADRQC", .value = System_Error_EBADRQC },
[56] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBADSLT", .value = System_Error_EBADSLT },
[57] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EDEADLOCK", .value = System_Error_EDEADLOCK },
[58] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBFONT", .value = System_Error_EBFONT },
[59] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOSTR", .value = System_Error_ENOSTR },
[60] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENODATA", .value = System_Error_ENODATA },
[61] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ETIME", .value = System_Error_ETIME },
[62] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOSR", .value = System_Error_ENOSR },
[63] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENONET", .value = System_Error_ENONET },
[64] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOPKG", .value = System_Error_ENOPKG },
[65] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EREMOTE", .value = System_Error_EREMOTE },
[66] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOLINK", .value = System_Error_ENOLINK },
[67] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EADV", .value = System_Error_EADV },
[68] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ESRMNT", .value = System_Error_ESRMNT },
[69] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ECOMM", .value = System_Error_ECOMM },
[70] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EPROTO", .value = System_Error_EPROTO },
[71] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EMULTIHOP", .value = System_Error_EMULTIHOP },
[72] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EDOTDOT", .value = System_Error_EDOTDOT },
[73] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBADMSG", .value = System_Error_EBADMSG },
[74] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EOVERFLOW", .value = System_Error_EOVERFLOW },
[75] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTUNIQ", .value = System_Error_ENOTUNIQ },
[76] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EBADFD", .value = System_Error_EBADFD },
[77] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EREMCHG", .value = System_Error_EREMCHG },
[78] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ELIBACC", .value = System_Error_ELIBACC },
[79] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ELIBBAD", .value = System_Error_ELIBBAD },
[80] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ELIBSCN", .value = System_Error_ELIBSCN },
[81] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ELIBMAX", .value = System_Error_ELIBMAX },
[82] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ELIBEXEC", .value = System_Error_ELIBEXEC },
[83] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EILSEQ", .value = System_Error_EILSEQ },
[84] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ERESTART", .value = System_Error_ERESTART },
[85] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ESTRPIPE", .value = System_Error_ESTRPIPE },
[86] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EUSERS", .value = System_Error_EUSERS },
[87] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTSOCK", .value = System_Error_ENOTSOCK },
[88] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EDESTADDRREQ", .value = System_Error_EDESTADDRREQ },
[89] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EMSGSIZE", .value = System_Error_EMSGSIZE },
[90] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EPROTOTYPE", .value = System_Error_EPROTOTYPE },
[91] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOPROTOOPT", .value = System_Error_ENOPROTOOPT },
[92] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EPROTONOSUPPORT", .value = System_Error_EPROTONOSUPPORT },
[93] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ESOCKTNOSUPPORT", .value = System_Error_ESOCKTNOSUPPORT },
[94] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EOPNOTSUPP", .value = System_Error_EOPNOTSUPP },
[95] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EPFNOSUPPORT", .value = System_Error_EPFNOSUPPORT },
[96] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EAFNOSUPPORT", .value = System_Error_EAFNOSUPPORT },
[97] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EADDRINUSE", .value = System_Error_EADDRINUSE },
[98] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EADDRNOTAVAIL", .value = System_Error_EADDRNOTAVAIL },
[99] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENETDOWN", .value = System_Error_ENETDOWN },
[100] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENETUNREACH", .value = System_Error_ENETUNREACH },
[101] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENETRESET", .value = System_Error_ENETRESET },
[102] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ECONNABORTED", .value = System_Error_ECONNABORTED },
[103] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ECONNRESET", .value = System_Error_ECONNRESET },
[104] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOBUFS", .value = System_Error_ENOBUFS },
[105] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EISCONN", .value = System_Error_EISCONN },
[106] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTCONN", .value = System_Error_ENOTCONN },
[107] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ESHUTDOWN", .value = System_Error_ESHUTDOWN },
[108] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ETOOMANYREFS", .value = System_Error_ETOOMANYREFS },
[109] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ETIMEDOUT", .value = System_Error_ETIMEDOUT },
[110] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ECONNREFUSED", .value = System_Error_ECONNREFUSED },
[111] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EHOSTDOWN", .value = System_Error_EHOSTDOWN },
[112] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EHOSTUNREACH", .value = System_Error_EHOSTUNREACH },
[113] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EALREADY", .value = System_Error_EALREADY },
[114] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EINPROGRESS", .value = System_Error_EINPROGRESS },
[115] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ESTALE", .value = System_Error_ESTALE },
[116] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EUCLEAN", .value = System_Error_EUCLEAN },
[117] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTNAM", .value = System_Error_ENOTNAM },
[118] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENAVAIL", .value = System_Error_ENAVAIL },
[119] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EISNAM", .value = System_Error_EISNAM },
[120] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EREMOTEIO", .value = System_Error_EREMOTEIO },
[121] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EDQUOT", .value = System_Error_EDQUOT },
[122] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOMEDIUM", .value = System_Error_ENOMEDIUM },
[123] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EMEDIUMTYPE", .value = System_Error_EMEDIUMTYPE },
[124] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ECANCELED", .value = System_Error_ECANCELED },
[125] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOKEY", .value = System_Error_ENOKEY },
[126] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EKEYEXPIRED", .value = System_Error_EKEYEXPIRED },
[127] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EKEYREVOKED", .value = System_Error_EKEYREVOKED },
[128] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EKEYREJECTED", .value = System_Error_EKEYREJECTED },
[129] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EOWNERDEAD", .value = System_Error_EOWNERDEAD },
[130] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ENOTRECOVERABLE", .value = System_Error_ENOTRECOVERABLE },
[131] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.ERFKILL", .value = System_Error_ERFKILL },
[132] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Error.EHWPOISON", .value = System_Error_EHWPOISON },
#define System_ErrorType_fields_length_DEFAULT  133
#endif
