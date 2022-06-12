/* Gemeinfrei. Public Domain. */

/* #include <asm-generic/errno.h> */
#if !defined(have_generic_System_error)
#define have_generic_System_error
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
#define have_ASM_GENERIC_ERRNO_BASE_H
#define have_ASM_GENERIC_ERRNO_H

#define  System_error_EPERM  1
#define  System_error_ENOENT  2
#define  System_error_ESRCH  3
#define  System_error_EINTR  4
#define  System_error_EIO  5
#define  System_error_ENXIO  6
#define  System_error_E2BIG  7
#define  System_error_ENOEXEC  8
#define  System_error_EBADF  9
#define  System_error_ECHILD  10
#define  System_error_EAGAIN  11
#define  System_error_ENOMEM  12
#define  System_error_EACCES  13
#define  System_error_EFAULT  14
#define  System_error_ENOTBLK  15
#define  System_error_EBUSY  16
#define  System_error_EEXIST  17
#define  System_error_EXDEV  18
#define  System_error_ENODEV  19
#define  System_error_ENOTDIR  20
#define  System_error_EISDIR  21
#define  System_error_EINVAL  22
#define  System_error_ENFILE  23
#define  System_error_EMFILE  24
#define  System_error_ENOTTY  25
#define  System_error_ETXTBSY  26
#define  System_error_EFBIG  27
#define  System_error_ENOSPC  28
#define  System_error_ESPIPE  29
#define  System_error_EROFS  30
#define  System_error_EMLINK  31
#define  System_error_EPIPE  32
#define  System_error_EDOM  33
#define  System_error_ERANGE  34

/* #include <asm-generic/errno-base.h> */

#define  System_error_EDEADLK  35
#define  System_error_ENAMETOOLONG  36
#define  System_error_ENOLCK  37

/*
 * This error code is special: arch syscall entry code will return
 * -ENOSYS if users try to call a syscall that doesn't exist.  To keep
 * failures of syscalls that really do exist distinguishable from
 * failures due to attempts to use a nonexistent syscall, syscall
 * implementations should refrain from returning -ENOSYS.
 */
#define  System_error_ENOSYS  38

#define  System_error_ENOTEMPTY  39
#define  System_error_ELOOP  40
#define  System_error_EWOULDBLOCK  System_error_EAGAIN
#define  System_error_ENOMSG  42
#define  System_error_EIDRM  43
#define  System_error_ECHRNG  44
#define  System_error_EL2NSYNC  45
#define  System_error_EL3HLT  46
#define  System_error_EL3RST  47
#define  System_error_ELNRNG  48
#define  System_error_EUNATCH  49
#define  System_error_ENOCSI  50
#define  System_error_EL2HLT  51
#define  System_error_EBADE  52
#define  System_error_EBADR  53
#define  System_error_EXFULL  54
#define  System_error_ENOANO  55
#define  System_error_EBADRQC  56
#define  System_error_EBADSLT  57

#define  System_error_EDEADLOCK  System_error_EDEADLK

#define  System_error_EBFONT  59
#define  System_error_ENOSTR  60
#define  System_error_ENODATA  61
#define  System_error_ETIME  62
#define  System_error_ENOSR  63
#define  System_error_ENONET  64
#define  System_error_ENOPKG  65
#define  System_error_EREMOTE  66
#define  System_error_ENOLINK  67
#define  System_error_EADV  68
#define  System_error_ESRMNT  69
#define  System_error_ECOMM  70
#define  System_error_EPROTO  71
#define  System_error_EMULTIHOP  72
#define  System_error_EDOTDOT  73
#define  System_error_EBADMSG  74
#define  System_error_EOVERFLOW  75
#define  System_error_ENOTUNIQ  76
#define  System_error_EBADFD  77
#define  System_error_EREMCHG  78
#define  System_error_ELIBACC  79
#define  System_error_ELIBBAD  80
#define  System_error_ELIBSCN  81
#define  System_error_ELIBMAX  82
#define  System_error_ELIBEXEC  83
#define  System_error_EILSEQ  84
#define  System_error_ERESTART  85
#define  System_error_ESTRPIPE  86
#define  System_error_EUSERS  87
#define  System_error_ENOTSOCK  88
#define  System_error_EDESTADDRREQ  89
#define  System_error_EMSGSIZE  90
#define  System_error_EPROTOTYPE  91
#define  System_error_ENOPROTOOPT  92
#define  System_error_EPROTONOSUPPORT  93
#define  System_error_ESOCKTNOSUPPORT  94
#define  System_error_EOPNOTSUPP  95
#define  System_error_EPFNOSUPPORT  96
#define  System_error_EAFNOSUPPORT  97
#define  System_error_EADDRINUSE  98
#define  System_error_EADDRNOTAVAIL  99
#define  System_error_ENETDOWN  100
#define  System_error_ENETUNREACH  101
#define  System_error_ENETRESET  102
#define  System_error_ECONNABORTED  103
#define  System_error_ECONNRESET  104
#define  System_error_ENOBUFS  105
#define  System_error_EISCONN  106
#define  System_error_ENOTCONN  107
#define  System_error_ESHUTDOWN  108
#define  System_error_ETOOMANYREFS  109
#define  System_error_ETIMEDOUT  110
#define  System_error_ECONNREFUSED  111
#define  System_error_EHOSTDOWN  112
#define  System_error_EHOSTUNREACH  113
#define  System_error_EALREADY  114
#define  System_error_EINPROGRESS  115
#define  System_error_ESTALE  116
#define  System_error_EUCLEAN  117
#define  System_error_ENOTNAM  118
#define  System_error_ENAVAIL  119
#define  System_error_EISNAM  120
#define  System_error_EREMOTEIO  121
#define  System_error_EDQUOT  122

#define  System_error_ENOMEDIUM  123
#define  System_error_EMEDIUMTYPE  124
#define  System_error_ECANCELED  125
#define  System_error_ENOKEY  126
#define  System_error_EKEYEXPIRED  127
#define  System_error_EKEYREVOKED  128
#define  System_error_EKEYREJECTED  129

/* for robust mutexes */
#define  System_error_EOWNERDEAD  130
#define  System_error_ENOTRECOVERABLE  131

#define  System_error_ERFKILL  132

#define  System_error_EHWPOISON  133

#elif defined(code_System_error)
[0] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EPERM", .value = System_error_EPERM },
[1] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOENT", .value = System_error_ENOENT },
[2] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ESRCH", .value = System_error_ESRCH },
[3] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EINTR", .value = System_error_EINTR },
[4] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EIO", .value = System_error_EIO },
[5] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENXIO", .value = System_error_ENXIO },
[6] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.E2BIG", .value = System_error_E2BIG },
[7] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOEXEC", .value = System_error_ENOEXEC },
[8] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBADF", .value = System_error_EBADF },
[9] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ECHILD", .value = System_error_ECHILD },
[10] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EAGAIN", .value = System_error_EAGAIN },
[11] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOMEM", .value = System_error_ENOMEM },
[12] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EACCES", .value = System_error_EACCES },
[13] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EFAULT", .value = System_error_EFAULT },
[14] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTBLK", .value = System_error_ENOTBLK },
[15] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBUSY", .value = System_error_EBUSY },
[16] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EEXIST", .value = System_error_EEXIST },
[17] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EXDEV", .value = System_error_EXDEV },
[18] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENODEV", .value = System_error_ENODEV },
[19] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTDIR", .value = System_error_ENOTDIR },
[20] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EISDIR", .value = System_error_EISDIR },
[21] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EINVAL", .value = System_error_EINVAL },
[22] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENFILE", .value = System_error_ENFILE },
[23] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EMFILE", .value = System_error_EMFILE },
[24] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTTY", .value = System_error_ENOTTY },
[25] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ETXTBSY", .value = System_error_ETXTBSY },
[26] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EFBIG", .value = System_error_EFBIG },
[27] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOSPC", .value = System_error_ENOSPC },
[28] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ESPIPE", .value = System_error_ESPIPE },
[29] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EROFS", .value = System_error_EROFS },
[30] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EMLINK", .value = System_error_EMLINK },
[31] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EPIPE", .value = System_error_EPIPE },
[32] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EDOM", .value = System_error_EDOM },
[33] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ERANGE", .value = System_error_ERANGE },

[34] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EDEADLK", .value = System_error_EDEADLK },
[35] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENAMETOOLONG", .value = System_error_ENAMETOOLONG },
[36] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOLCK", .value = System_error_ENOLCK },
[37] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOSYS", .value = System_error_ENOSYS },
[38] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTEMPTY", .value = System_error_ENOTEMPTY },
[39] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ELOOP", .value = System_error_ELOOP },
[40] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EWOULDBLOCK", .value = System_error_EWOULDBLOCK },
[41] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOMSG", .value = System_error_ENOMSG },
[42] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EIDRM", .value = System_error_EIDRM },
[43] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ECHRNG", .value = System_error_ECHRNG },
[44] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EL2NSYNC", .value = System_error_EL2NSYNC },
[45] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EL3HLT", .value = System_error_EL3HLT },
[46] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EL3RST", .value = System_error_EL3RST },
[47] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ELNRNG", .value = System_error_ELNRNG },
[48] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EUNATCH", .value = System_error_EUNATCH },
[49] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOCSI", .value = System_error_ENOCSI },
[50] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EL2HLT", .value = System_error_EL2HLT },
[51] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBADE", .value = System_error_EBADE },
[52] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBADR", .value = System_error_EBADR },
[53] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EXFULL", .value = System_error_EXFULL },
[54] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOANO", .value = System_error_ENOANO },
[55] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBADRQC", .value = System_error_EBADRQC },
[56] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBADSLT", .value = System_error_EBADSLT },
[57] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EDEADLOCK", .value = System_error_EDEADLOCK },
[58] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBFONT", .value = System_error_EBFONT },
[59] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOSTR", .value = System_error_ENOSTR },
[60] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENODATA", .value = System_error_ENODATA },
[61] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ETIME", .value = System_error_ETIME },
[62] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOSR", .value = System_error_ENOSR },
[63] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENONET", .value = System_error_ENONET },
[64] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOPKG", .value = System_error_ENOPKG },
[65] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EREMOTE", .value = System_error_EREMOTE },
[66] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOLINK", .value = System_error_ENOLINK },
[67] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EADV", .value = System_error_EADV },
[68] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ESRMNT", .value = System_error_ESRMNT },
[69] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ECOMM", .value = System_error_ECOMM },
[70] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EPROTO", .value = System_error_EPROTO },
[71] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EMULTIHOP", .value = System_error_EMULTIHOP },
[72] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EDOTDOT", .value = System_error_EDOTDOT },
[73] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBADMSG", .value = System_error_EBADMSG },
[74] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EOVERFLOW", .value = System_error_EOVERFLOW },
[75] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTUNIQ", .value = System_error_ENOTUNIQ },
[76] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EBADFD", .value = System_error_EBADFD },
[77] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EREMCHG", .value = System_error_EREMCHG },
[78] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ELIBACC", .value = System_error_ELIBACC },
[79] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ELIBBAD", .value = System_error_ELIBBAD },
[80] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ELIBSCN", .value = System_error_ELIBSCN },
[81] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ELIBMAX", .value = System_error_ELIBMAX },
[82] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ELIBEXEC", .value = System_error_ELIBEXEC },
[83] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EILSEQ", .value = System_error_EILSEQ },
[84] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ERESTART", .value = System_error_ERESTART },
[85] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ESTRPIPE", .value = System_error_ESTRPIPE },
[86] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EUSERS", .value = System_error_EUSERS },
[87] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTSOCK", .value = System_error_ENOTSOCK },
[88] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EDESTADDRREQ", .value = System_error_EDESTADDRREQ },
[89] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EMSGSIZE", .value = System_error_EMSGSIZE },
[90] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EPROTOTYPE", .value = System_error_EPROTOTYPE },
[91] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOPROTOOPT", .value = System_error_ENOPROTOOPT },
[92] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EPROTONOSUPPORT", .value = System_error_EPROTONOSUPPORT },
[93] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ESOCKTNOSUPPORT", .value = System_error_ESOCKTNOSUPPORT },
[94] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EOPNOTSUPP", .value = System_error_EOPNOTSUPP },
[95] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EPFNOSUPPORT", .value = System_error_EPFNOSUPPORT },
[96] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EAFNOSUPPORT", .value = System_error_EAFNOSUPPORT },
[97] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EADDRINUSE", .value = System_error_EADDRINUSE },
[98] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EADDRNOTAVAIL", .value = System_error_EADDRNOTAVAIL },
[99] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENETDOWN", .value = System_error_ENETDOWN },
[100] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENETUNREACH", .value = System_error_ENETUNREACH },
[101] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENETRESET", .value = System_error_ENETRESET },
[102] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ECONNABORTED", .value = System_error_ECONNABORTED },
[103] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ECONNRESET", .value = System_error_ECONNRESET },
[104] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOBUFS", .value = System_error_ENOBUFS },
[105] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EISCONN", .value = System_error_EISCONN },
[106] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTCONN", .value = System_error_ENOTCONN },
[107] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ESHUTDOWN", .value = System_error_ESHUTDOWN },
[108] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ETOOMANYREFS", .value = System_error_ETOOMANYREFS },
[109] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ETIMEDOUT", .value = System_error_ETIMEDOUT },
[110] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ECONNREFUSED", .value = System_error_ECONNREFUSED },
[111] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EHOSTDOWN", .value = System_error_EHOSTDOWN },
[112] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EHOSTUNREACH", .value = System_error_EHOSTUNREACH },
[113] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EALREADY", .value = System_error_EALREADY },
[114] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EINPROGRESS", .value = System_error_EINPROGRESS },
[115] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ESTALE", .value = System_error_ESTALE },
[116] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EUCLEAN", .value = System_error_EUCLEAN },
[117] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTNAM", .value = System_error_ENOTNAM },
[118] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENAVAIL", .value = System_error_ENAVAIL },
[119] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EISNAM", .value = System_error_EISNAM },
[120] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EREMOTEIO", .value = System_error_EREMOTEIO },
[121] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EDQUOT", .value = System_error_EDQUOT },
[122] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOMEDIUM", .value = System_error_ENOMEDIUM },
[123] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EMEDIUMTYPE", .value = System_error_EMEDIUMTYPE },
[124] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ECANCELED", .value = System_error_ECANCELED },
[125] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOKEY", .value = System_error_ENOKEY },
[126] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EKEYEXPIRED", .value = System_error_EKEYEXPIRED },
[127] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EKEYREVOKED", .value = System_error_EKEYREVOKED },
[128] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EKEYREJECTED", .value = System_error_EKEYREJECTED },
[129] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EOWNERDEAD", .value = System_error_EOWNERDEAD },
[130] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ENOTRECOVERABLE", .value = System_error_ENOTRECOVERABLE },
[131] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.ERFKILL", .value = System_error_ERFKILL },
[132] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.error.EHWPOISON", .value = System_error_EHWPOISON },
#define System_errorType_fields_length_DEFAULT  133
#endif
