#if !defined(have_auto_System_Syscall_Command)
#define have_auto_System_Syscall_Command
#define have_ASM_ARM_UNISTD

#define System_Syscall_Command_BASE  0x900000

#if defined(__thumb__) || defined(__ARM_EABI__)
#undef  System_Syscall_Command_BASE
#define System_Syscall_Command_BASE  0
#endif

#define System_Syscall_Command_time (System_Syscall_Command_BASE + 13)
#define System_Syscall_Command_umount (System_Syscall_Command_BASE + 22)
#define System_Syscall_Command_stime (System_Syscall_Command_BASE + 25)
#define System_Syscall_Command_alarm (System_Syscall_Command_BASE + 27)
#define System_Syscall_Command_utime (System_Syscall_Command_BASE + 30)
#define System_Syscall_Command_getrlimit (System_Syscall_Command_BASE + 76)
#define System_Syscall_Command_select (System_Syscall_Command_BASE + 82)
#define System_Syscall_Command_readdir (System_Syscall_Command_BASE + 89)
#define System_Syscall_Command_mmap (System_Syscall_Command_BASE + 90)
#define System_Syscall_Command_socketcall (System_Syscall_Command_BASE + 102)
#define System_Syscall_Command_syscall (System_Syscall_Command_BASE + 113) /* ? */
#define System_Syscall_Command_ipc (System_Syscall_Command_BASE + 117)

#define System_Syscall_Command_restart (System_Syscall_Command_BASE + 0)
#define System_Syscall_Command_exit (System_Syscall_Command_BASE + 1)
#define System_Syscall_Command_fork (System_Syscall_Command_BASE + 2)
#define System_Syscall_Command_read (System_Syscall_Command_BASE + 3)
#define System_Syscall_Command_write (System_Syscall_Command_BASE + 4)
#define System_Syscall_Command_open (System_Syscall_Command_BASE + 5)
#define System_Syscall_Command_close (System_Syscall_Command_BASE + 6)
#define System_Syscall_Command_creat (System_Syscall_Command_BASE + 8)
#define System_Syscall_Command_link (System_Syscall_Command_BASE + 9)
#define System_Syscall_Command_unlink (System_Syscall_Command_BASE + 10)
#define System_Syscall_Command_execve (System_Syscall_Command_BASE + 11)
#define System_Syscall_Command_chdir (System_Syscall_Command_BASE + 12)
#define System_Syscall_Command_mknod (System_Syscall_Command_BASE + 14)
#define System_Syscall_Command_chmod (System_Syscall_Command_BASE + 15)
#define System_Syscall_Command_lchown (System_Syscall_Command_BASE + 16)
#define System_Syscall_Command_lseek (System_Syscall_Command_BASE + 19)
#define System_Syscall_Command_getpid (System_Syscall_Command_BASE + 20)
#define System_Syscall_Command_mount (System_Syscall_Command_BASE + 21)
#define System_Syscall_Command_setuid (System_Syscall_Command_BASE + 23)
#define System_Syscall_Command_getuid (System_Syscall_Command_BASE + 24)
#define System_Syscall_Command_ptrace (System_Syscall_Command_BASE + 26)
#define System_Syscall_Command_pause (System_Syscall_Command_BASE + 29)
#define System_Syscall_Command_access (System_Syscall_Command_BASE + 33)
#define System_Syscall_Command_nice (System_Syscall_Command_BASE + 34)
#define System_Syscall_Command_sync (System_Syscall_Command_BASE + 36)
#define System_Syscall_Command_kill (System_Syscall_Command_BASE + 37)
#define System_Syscall_Command_rename (System_Syscall_Command_BASE + 38)
#define System_Syscall_Command_mkdir (System_Syscall_Command_BASE + 39)
#define System_Syscall_Command_rmdir (System_Syscall_Command_BASE + 40)
#define System_Syscall_Command_dup (System_Syscall_Command_BASE + 41)
#define System_Syscall_Command_pipe (System_Syscall_Command_BASE + 42)
#define System_Syscall_Command_times (System_Syscall_Command_BASE + 43)
#define System_Syscall_Command_brk (System_Syscall_Command_BASE + 45)
#define System_Syscall_Command_setgid (System_Syscall_Command_BASE + 46)
#define System_Syscall_Command_getgid (System_Syscall_Command_BASE + 47)
#define System_Syscall_Command_geteuid (System_Syscall_Command_BASE + 49)
#define System_Syscall_Command_getegid (System_Syscall_Command_BASE + 50)
#define System_Syscall_Command_acct (System_Syscall_Command_BASE + 51)
#define System_Syscall_Command_umount2 (System_Syscall_Command_BASE + 52)
#define System_Syscall_Command_ioctl (System_Syscall_Command_BASE + 54)
#define System_Syscall_Command_fcntl (System_Syscall_Command_BASE + 55)
#define System_Syscall_Command_setpgid (System_Syscall_Command_BASE + 57)
#define System_Syscall_Command_umask (System_Syscall_Command_BASE + 60)
#define System_Syscall_Command_chroot (System_Syscall_Command_BASE + 61)
#define System_Syscall_Command_ustat (System_Syscall_Command_BASE + 62)
#define System_Syscall_Command_dup2 (System_Syscall_Command_BASE + 63)
#define System_Syscall_Command_getppid (System_Syscall_Command_BASE + 64)
#define System_Syscall_Command_getpgrp (System_Syscall_Command_BASE + 65)
#define System_Syscall_Command_setsid (System_Syscall_Command_BASE + 66)
#define System_Syscall_Command_sigaction (System_Syscall_Command_BASE + 67)
#define System_Syscall_Command_setreuid (System_Syscall_Command_BASE + 70)
#define System_Syscall_Command_setregid (System_Syscall_Command_BASE + 71)
#define System_Syscall_Command_sigsuspend (System_Syscall_Command_BASE + 72)
#define System_Syscall_Command_sigpending (System_Syscall_Command_BASE + 73)
#define System_Syscall_Command_sethostname (System_Syscall_Command_BASE + 74)
#define System_Syscall_Command_setrlimit (System_Syscall_Command_BASE + 75)
#define System_Syscall_Command_getrusage (System_Syscall_Command_BASE + 77)
#define System_Syscall_Command_gettimeofday (System_Syscall_Command_BASE + 78)
#define System_Syscall_Command_settimeofday (System_Syscall_Command_BASE + 79)
#define System_Syscall_Command_getgroups (System_Syscall_Command_BASE + 80)
#define System_Syscall_Command_setgroups (System_Syscall_Command_BASE + 81)
#define System_Syscall_Command_symlink (System_Syscall_Command_BASE + 83)
#define System_Syscall_Command_readlink (System_Syscall_Command_BASE + 85)
#define System_Syscall_Command_uselib (System_Syscall_Command_BASE + 86)
#define System_Syscall_Command_swapon (System_Syscall_Command_BASE + 87)
#define System_Syscall_Command_reboot (System_Syscall_Command_BASE + 88)
#define System_Syscall_Command_munmap (System_Syscall_Command_BASE + 91)
#define System_Syscall_Command_truncate (System_Syscall_Command_BASE + 92)
#define System_Syscall_Command_ftruncate (System_Syscall_Command_BASE + 93)
#define System_Syscall_Command_fchmod (System_Syscall_Command_BASE + 94)
#define System_Syscall_Command_fchown (System_Syscall_Command_BASE + 95)
#define System_Syscall_Command_getpriority (System_Syscall_Command_BASE + 96)
#define System_Syscall_Command_setpriority (System_Syscall_Command_BASE + 97)
#define System_Syscall_Command_statfs (System_Syscall_Command_BASE + 99)
#define System_Syscall_Command_fstatfs (System_Syscall_Command_BASE + 100)
#define System_Syscall_Command_syslog (System_Syscall_Command_BASE + 103)
#define System_Syscall_Command_setitimer (System_Syscall_Command_BASE + 104)
#define System_Syscall_Command_getitimer (System_Syscall_Command_BASE + 105)
#define System_Syscall_Command_stat (System_Syscall_Command_BASE + 106)
#define System_Syscall_Command_lstat (System_Syscall_Command_BASE + 107)
#define System_Syscall_Command_fstat (System_Syscall_Command_BASE + 108)
#define System_Syscall_Command_vhangup (System_Syscall_Command_BASE + 111)
#define System_Syscall_Command_wait4 (System_Syscall_Command_BASE + 114)
#define System_Syscall_Command_swapoff (System_Syscall_Command_BASE + 115)
#define System_Syscall_Command_sysinfo (System_Syscall_Command_BASE + 116)
#define System_Syscall_Command_fsync (System_Syscall_Command_BASE + 118)
#define System_Syscall_Command_sigreturn (System_Syscall_Command_BASE + 119)
#define System_Syscall_Command_clone (System_Syscall_Command_BASE + 120)
#define System_Syscall_Command_setdomainname (System_Syscall_Command_BASE + 121)
#define System_Syscall_Command_uname (System_Syscall_Command_BASE + 122)
#define System_Syscall_Command_adjtimex (System_Syscall_Command_BASE + 124)
#define System_Syscall_Command_mprotect (System_Syscall_Command_BASE + 125)
#define System_Syscall_Command_sigprocmask (System_Syscall_Command_BASE + 126)
#define System_Syscall_Command_init_module (System_Syscall_Command_BASE + 128)
#define System_Syscall_Command_delete_module (System_Syscall_Command_BASE + 129)
#define System_Syscall_Command_quotactl (System_Syscall_Command_BASE + 131)
#define System_Syscall_Command_getpgid (System_Syscall_Command_BASE + 132)
#define System_Syscall_Command_fchdir (System_Syscall_Command_BASE + 133)
#define System_Syscall_Command_bdflush (System_Syscall_Command_BASE + 134)
#define System_Syscall_Command_sysfs (System_Syscall_Command_BASE + 135)
#define System_Syscall_Command_personality (System_Syscall_Command_BASE + 136)
#define System_Syscall_Command_setfsuid (System_Syscall_Command_BASE + 138)
#define System_Syscall_Command_setfsgid (System_Syscall_Command_BASE + 139)
#define System_Syscall_Command__llseek (System_Syscall_Command_BASE + 140)
#define System_Syscall_Command_getdents (System_Syscall_Command_BASE + 141)
#define System_Syscall_Command__newselect (System_Syscall_Command_BASE + 142)
#define System_Syscall_Command_flock (System_Syscall_Command_BASE + 143)
#define System_Syscall_Command_msync (System_Syscall_Command_BASE + 144)
#define System_Syscall_Command_readv (System_Syscall_Command_BASE + 145)
#define System_Syscall_Command_writev (System_Syscall_Command_BASE + 146)
#define System_Syscall_Command_getsid (System_Syscall_Command_BASE + 147)
#define System_Syscall_Command_fdatasync (System_Syscall_Command_BASE + 148)
#define System_Syscall_Command__sysctl (System_Syscall_Command_BASE + 149)
#define System_Syscall_Command_mlock (System_Syscall_Command_BASE + 150)
#define System_Syscall_Command_munlock (System_Syscall_Command_BASE + 151)
#define System_Syscall_Command_mlockall (System_Syscall_Command_BASE + 152)
#define System_Syscall_Command_munlockall (System_Syscall_Command_BASE + 153)
#define System_Syscall_Command_sched_setparam (System_Syscall_Command_BASE + 154)
#define System_Syscall_Command_sched_getparam (System_Syscall_Command_BASE + 155)
#define System_Syscall_Command_sched_setscheduler (System_Syscall_Command_BASE + 156)
#define System_Syscall_Command_sched_getscheduler (System_Syscall_Command_BASE + 157)
#define System_Syscall_Command_sched_yield (System_Syscall_Command_BASE + 158)
#define System_Syscall_Command_sched_get_priority_max (System_Syscall_Command_BASE + 159)
#define System_Syscall_Command_sched_get_priority_min (System_Syscall_Command_BASE + 160)
#define System_Syscall_Command_sched_rr_get_interval (System_Syscall_Command_BASE + 161)
#define System_Syscall_Command_nanosleep (System_Syscall_Command_BASE + 162)
#define System_Syscall_Command_mremap (System_Syscall_Command_BASE + 163)
#define System_Syscall_Command_setresuid (System_Syscall_Command_BASE + 164)
#define System_Syscall_Command_getresuid (System_Syscall_Command_BASE + 165)
#define System_Syscall_Command_poll (System_Syscall_Command_BASE + 168)
#define System_Syscall_Command_nfsservctl (System_Syscall_Command_BASE + 169)
#define System_Syscall_Command_setresgid (System_Syscall_Command_BASE + 170)
#define System_Syscall_Command_getresgid (System_Syscall_Command_BASE + 171)
#define System_Syscall_Command_prctl (System_Syscall_Command_BASE + 172)
#define System_Syscall_Command_rt_sigreturn (System_Syscall_Command_BASE + 173)
#define System_Syscall_Command_rt_sigaction (System_Syscall_Command_BASE + 174)
#define System_Syscall_Command_rt_sigprocmask (System_Syscall_Command_BASE + 175)
#define System_Syscall_Command_rt_sigpending (System_Syscall_Command_BASE + 176)
#define System_Syscall_Command_rt_sigtimedwait (System_Syscall_Command_BASE + 177)
#define System_Syscall_Command_rt_sigqueueinfo (System_Syscall_Command_BASE + 178)
#define System_Syscall_Command_rt_sigsuspend (System_Syscall_Command_BASE + 179)
#define System_Syscall_Command_pread64 (System_Syscall_Command_BASE + 180)
#define System_Syscall_Command_pwrite64 (System_Syscall_Command_BASE + 181)
#define System_Syscall_Command_chown (System_Syscall_Command_BASE + 182)
#define System_Syscall_Command_getcwd (System_Syscall_Command_BASE + 183)
#define System_Syscall_Command_capget (System_Syscall_Command_BASE + 184)
#define System_Syscall_Command_capset (System_Syscall_Command_BASE + 185)
#define System_Syscall_Command_sigaltstack (System_Syscall_Command_BASE + 186)
#define System_Syscall_Command_sendfile (System_Syscall_Command_BASE + 187)
#define System_Syscall_Command_vfork (System_Syscall_Command_BASE + 190)
#define System_Syscall_Command_ugetrlimit (System_Syscall_Command_BASE + 191)
#define System_Syscall_Command_mmap2 (System_Syscall_Command_BASE + 192)
#define System_Syscall_Command_truncate64 (System_Syscall_Command_BASE + 193)
#define System_Syscall_Command_ftruncate64 (System_Syscall_Command_BASE + 194)
#define System_Syscall_Command_stat64 (System_Syscall_Command_BASE + 195)
#define System_Syscall_Command_lstat64 (System_Syscall_Command_BASE + 196)
#define System_Syscall_Command_fstat64 (System_Syscall_Command_BASE + 197)
#define System_Syscall_Command_lchown32 (System_Syscall_Command_BASE + 198)
#define System_Syscall_Command_getuid32 (System_Syscall_Command_BASE + 199)
#define System_Syscall_Command_getgid32 (System_Syscall_Command_BASE + 200)
#define System_Syscall_Command_geteuid32 (System_Syscall_Command_BASE + 201)
#define System_Syscall_Command_getegid32 (System_Syscall_Command_BASE + 202)
#define System_Syscall_Command_setreuid32 (System_Syscall_Command_BASE + 203)
#define System_Syscall_Command_setregid32 (System_Syscall_Command_BASE + 204)
#define System_Syscall_Command_getgroups32 (System_Syscall_Command_BASE + 205)
#define System_Syscall_Command_setgroups32 (System_Syscall_Command_BASE + 206)
#define System_Syscall_Command_fchown32 (System_Syscall_Command_BASE + 207)
#define System_Syscall_Command_setresuid32 (System_Syscall_Command_BASE + 208)
#define System_Syscall_Command_getresuid32 (System_Syscall_Command_BASE + 209)
#define System_Syscall_Command_setresgid32 (System_Syscall_Command_BASE + 210)
#define System_Syscall_Command_getresgid32 (System_Syscall_Command_BASE + 211)
#define System_Syscall_Command_chown32 (System_Syscall_Command_BASE + 212)
#define System_Syscall_Command_setuid32 (System_Syscall_Command_BASE + 213)
#define System_Syscall_Command_setgid32 (System_Syscall_Command_BASE + 214)
#define System_Syscall_Command_setfsuid32 (System_Syscall_Command_BASE + 215)
#define System_Syscall_Command_setfsgid32 (System_Syscall_Command_BASE + 216)
#define System_Syscall_Command_getdents64 (System_Syscall_Command_BASE + 217)
#define System_Syscall_Command_pivot_root (System_Syscall_Command_BASE + 218)
#define System_Syscall_Command_mincore (System_Syscall_Command_BASE + 219)
#define System_Syscall_Command_madvise (System_Syscall_Command_BASE + 220)
#define System_Syscall_Command_fcntl64 (System_Syscall_Command_BASE + 221)
#define System_Syscall_Command_gettid (System_Syscall_Command_BASE + 224)
#define System_Syscall_Command_readahead (System_Syscall_Command_BASE + 225)
#define System_Syscall_Command_setxattr (System_Syscall_Command_BASE + 226)
#define System_Syscall_Command_lsetxattr (System_Syscall_Command_BASE + 227)
#define System_Syscall_Command_fsetxattr (System_Syscall_Command_BASE + 228)
#define System_Syscall_Command_getxattr (System_Syscall_Command_BASE + 229)
#define System_Syscall_Command_lgetxattr (System_Syscall_Command_BASE + 230)
#define System_Syscall_Command_fgetxattr (System_Syscall_Command_BASE + 231)
#define System_Syscall_Command_listxattr (System_Syscall_Command_BASE + 232)
#define System_Syscall_Command_llistxattr (System_Syscall_Command_BASE + 233)
#define System_Syscall_Command_flistxattr (System_Syscall_Command_BASE + 234)
#define System_Syscall_Command_removexattr (System_Syscall_Command_BASE + 235)
#define System_Syscall_Command_lremovexattr (System_Syscall_Command_BASE + 236)
#define System_Syscall_Command_fremovexattr (System_Syscall_Command_BASE + 237)
#define System_Syscall_Command_tkill (System_Syscall_Command_BASE + 238)
#define System_Syscall_Command_sendfile64 (System_Syscall_Command_BASE + 239)
#define System_Syscall_Command_futex (System_Syscall_Command_BASE + 240)
#define System_Syscall_Command_sched_setaffinity (System_Syscall_Command_BASE + 241)
#define System_Syscall_Command_sched_getaffinity (System_Syscall_Command_BASE + 242)
#define System_Syscall_Command_io_setup (System_Syscall_Command_BASE + 243)
#define System_Syscall_Command_io_destroy (System_Syscall_Command_BASE + 244)
#define System_Syscall_Command_io_getevents (System_Syscall_Command_BASE + 245)
#define System_Syscall_Command_io_submit (System_Syscall_Command_BASE + 246)
#define System_Syscall_Command_io_cancel (System_Syscall_Command_BASE + 247)
#define System_Syscall_Command_exit_group (System_Syscall_Command_BASE + 248)
#define System_Syscall_Command_lookup_dcookie (System_Syscall_Command_BASE + 249)
#define System_Syscall_Command_epoll_create (System_Syscall_Command_BASE + 250)
#define System_Syscall_Command_epoll_ctl (System_Syscall_Command_BASE + 251)
#define System_Syscall_Command_epoll_wait (System_Syscall_Command_BASE + 252)
#define System_Syscall_Command_remap_file_pages (System_Syscall_Command_BASE + 253)
#define System_Syscall_Command_set_tid_address (System_Syscall_Command_BASE + 256)
#define System_Syscall_Command_timer_create (System_Syscall_Command_BASE + 257)
#define System_Syscall_Command_timer_settime (System_Syscall_Command_BASE + 258)
#define System_Syscall_Command_timer_gettime (System_Syscall_Command_BASE + 259)
#define System_Syscall_Command_timer_getoverrun (System_Syscall_Command_BASE + 260)
#define System_Syscall_Command_timer_delete (System_Syscall_Command_BASE + 261)
#define System_Syscall_Command_clock_settime (System_Syscall_Command_BASE + 262)
#define System_Syscall_Command_clock_gettime (System_Syscall_Command_BASE + 263)
#define System_Syscall_Command_clock_getres (System_Syscall_Command_BASE + 264)
#define System_Syscall_Command_clock_nanosleep (System_Syscall_Command_BASE + 265)
#define System_Syscall_Command_statfs64 (System_Syscall_Command_BASE + 266)
#define System_Syscall_Command_fstatfs64 (System_Syscall_Command_BASE + 267)
#define System_Syscall_Command_tgkill (System_Syscall_Command_BASE + 268)
#define System_Syscall_Command_utimes (System_Syscall_Command_BASE + 269)
#define System_Syscall_Command_arm_fadvise64_64 (System_Syscall_Command_BASE + 270)
#define System_Syscall_Command_pciconfig_iobase (System_Syscall_Command_BASE + 271)
#define System_Syscall_Command_pciconfig_read (System_Syscall_Command_BASE + 272)
#define System_Syscall_Command_pciconfig_write (System_Syscall_Command_BASE + 273)
#define System_Syscall_Command_mq_open (System_Syscall_Command_BASE + 274)
#define System_Syscall_Command_mq_unlink (System_Syscall_Command_BASE + 275)
#define System_Syscall_Command_mq_timedsend (System_Syscall_Command_BASE + 276)
#define System_Syscall_Command_mq_timedreceive (System_Syscall_Command_BASE + 277)
#define System_Syscall_Command_mq_notify (System_Syscall_Command_BASE + 278)
#define System_Syscall_Command_mq_getsetattr (System_Syscall_Command_BASE + 279)
#define System_Syscall_Command_waitid (System_Syscall_Command_BASE + 280)
#define System_Syscall_Command_socket (System_Syscall_Command_BASE + 281)
#define System_Syscall_Command_bind (System_Syscall_Command_BASE + 282)
#define System_Syscall_Command_connect (System_Syscall_Command_BASE + 283)
#define System_Syscall_Command_listen (System_Syscall_Command_BASE + 284)
#define System_Syscall_Command_accept (System_Syscall_Command_BASE + 285)
#define System_Syscall_Command_getsockname (System_Syscall_Command_BASE + 286)
#define System_Syscall_Command_getpeername (System_Syscall_Command_BASE + 287)
#define System_Syscall_Command_socketpair (System_Syscall_Command_BASE + 288)
#define System_Syscall_Command_send (System_Syscall_Command_BASE + 289)
#define System_Syscall_Command_sendto (System_Syscall_Command_BASE + 290)
#define System_Syscall_Command_recv (System_Syscall_Command_BASE + 291)
#define System_Syscall_Command_recvfrom (System_Syscall_Command_BASE + 292)
#define System_Syscall_Command_shutdown (System_Syscall_Command_BASE + 293)
#define System_Syscall_Command_setsockopt (System_Syscall_Command_BASE + 294)
#define System_Syscall_Command_getsockopt (System_Syscall_Command_BASE + 295)
#define System_Syscall_Command_sendmsg (System_Syscall_Command_BASE + 296)
#define System_Syscall_Command_recvmsg (System_Syscall_Command_BASE + 297)
#define System_Syscall_Command_semop (System_Syscall_Command_BASE + 298)
#define System_Syscall_Command_semget (System_Syscall_Command_BASE + 299)
#define System_Syscall_Command_semctl (System_Syscall_Command_BASE + 300)
#define System_Syscall_Command_msgsnd (System_Syscall_Command_BASE + 301)
#define System_Syscall_Command_msgrcv (System_Syscall_Command_BASE + 302)
#define System_Syscall_Command_msgget (System_Syscall_Command_BASE + 303)
#define System_Syscall_Command_msgctl (System_Syscall_Command_BASE + 304)
#define System_Syscall_Command_shmat (System_Syscall_Command_BASE + 305)
#define System_Syscall_Command_shmdt (System_Syscall_Command_BASE + 306)
#define System_Syscall_Command_shmget (System_Syscall_Command_BASE + 307)
#define System_Syscall_Command_shmctl (System_Syscall_Command_BASE + 308)
#define System_Syscall_Command_add_key (System_Syscall_Command_BASE + 309)
#define System_Syscall_Command_request_key (System_Syscall_Command_BASE + 310)
#define System_Syscall_Command_keyctl (System_Syscall_Command_BASE + 311)
#define System_Syscall_Command_semtimedop (System_Syscall_Command_BASE + 312)
#define System_Syscall_Command_vserver (System_Syscall_Command_BASE + 313)
#define System_Syscall_Command_ioprio_set (System_Syscall_Command_BASE + 314)
#define System_Syscall_Command_ioprio_get (System_Syscall_Command_BASE + 315)
#define System_Syscall_Command_inotify_init (System_Syscall_Command_BASE + 316)
#define System_Syscall_Command_inotify_add_watch (System_Syscall_Command_BASE + 317)
#define System_Syscall_Command_inotify_rm_watch (System_Syscall_Command_BASE + 318)
#define System_Syscall_Command_mbind (System_Syscall_Command_BASE + 319)
#define System_Syscall_Command_get_mempolicy (System_Syscall_Command_BASE + 320)
#define System_Syscall_Command_set_mempolicy (System_Syscall_Command_BASE + 321)
#define System_Syscall_Command_openat (System_Syscall_Command_BASE + 322)
#define System_Syscall_Command_mkdirat (System_Syscall_Command_BASE + 323)
#define System_Syscall_Command_mknodat (System_Syscall_Command_BASE + 324)
#define System_Syscall_Command_fchownat (System_Syscall_Command_BASE + 325)
#define System_Syscall_Command_futimesat (System_Syscall_Command_BASE + 326)
#define System_Syscall_Command_fstatat (System_Syscall_Command_BASE + 327)
#define System_Syscall_Command_unlinkat (System_Syscall_Command_BASE + 328)
#define System_Syscall_Command_renameat (System_Syscall_Command_BASE + 329)
#define System_Syscall_Command_linkat (System_Syscall_Command_BASE + 330)
#define System_Syscall_Command_symlinkat (System_Syscall_Command_BASE + 331)
#define System_Syscall_Command_readlinkat (System_Syscall_Command_BASE + 332)
#define System_Syscall_Command_fchmodat (System_Syscall_Command_BASE + 333)
#define System_Syscall_Command_faccessat (System_Syscall_Command_BASE + 334)
#define System_Syscall_Command_pselect6 (System_Syscall_Command_BASE + 335)
#define System_Syscall_Command_ppoll (System_Syscall_Command_BASE + 336)
#define System_Syscall_Command_unshare (System_Syscall_Command_BASE + 337)
#define System_Syscall_Command_set_robust_list (System_Syscall_Command_BASE + 338)
#define System_Syscall_Command_get_robust_list (System_Syscall_Command_BASE + 339)
#define System_Syscall_Command_splice (System_Syscall_Command_BASE + 340)
#define System_Syscall_Command_arm_sync_file_range (System_Syscall_Command_BASE + 341)
#define System_Syscall_Command_tee (System_Syscall_Command_BASE + 342)
#define System_Syscall_Command_vmsplice (System_Syscall_Command_BASE + 343)
#define System_Syscall_Command_move_pages (System_Syscall_Command_BASE + 344)
#define System_Syscall_Command_getcpu (System_Syscall_Command_BASE + 345)
#define System_Syscall_Command_epoll_pwait (System_Syscall_Command_BASE + 346)
#define System_Syscall_Command_kexec_load (System_Syscall_Command_BASE + 347)
#define System_Syscall_Command_utimensat (System_Syscall_Command_BASE + 348)
#define System_Syscall_Command_signalfd (System_Syscall_Command_BASE + 349)
#define System_Syscall_Command_timerfd_create (System_Syscall_Command_BASE + 350)
#define System_Syscall_Command_eventfd (System_Syscall_Command_BASE + 351)
#define System_Syscall_Command_fallocate (System_Syscall_Command_BASE + 352)
#define System_Syscall_Command_timerfd_settime (System_Syscall_Command_BASE + 353)
#define System_Syscall_Command_timerfd_gettime (System_Syscall_Command_BASE + 354)
#define System_Syscall_Command_signalfd4 (System_Syscall_Command_BASE + 355)
#define System_Syscall_Command_eventfd2 (System_Syscall_Command_BASE + 356)
#define System_Syscall_Command_epoll_create1 (System_Syscall_Command_BASE + 357)
#define System_Syscall_Command_dup3 (System_Syscall_Command_BASE + 358)
#define System_Syscall_Command_pipe2 (System_Syscall_Command_BASE + 359)
#define System_Syscall_Command_inotify_init1 (System_Syscall_Command_BASE + 360)
#define System_Syscall_Command_preadv (System_Syscall_Command_BASE + 361)
#define System_Syscall_Command_pwritev (System_Syscall_Command_BASE + 362)
#define System_Syscall_Command_rt_tgsigqueueinfo (System_Syscall_Command_BASE + 363)
#define System_Syscall_Command_perf_event_open (System_Syscall_Command_BASE + 364)
#define System_Syscall_Command_recvmmsg (System_Syscall_Command_BASE + 365)
#define System_Syscall_Command_accept4 (System_Syscall_Command_BASE + 366)
#define System_Syscall_Command_fanotify_init (System_Syscall_Command_BASE + 367)
#define System_Syscall_Command_fanotify_mark (System_Syscall_Command_BASE + 368)
#define System_Syscall_Command_prlimit64 (System_Syscall_Command_BASE + 369)
#define System_Syscall_Command_name_to_handle_at (System_Syscall_Command_BASE + 370)
#define System_Syscall_Command_open_by_handle_at (System_Syscall_Command_BASE + 371)
#define System_Syscall_Command_clock_adjtime (System_Syscall_Command_BASE + 372)
#define System_Syscall_Command_syncfs (System_Syscall_Command_BASE + 373)
#define System_Syscall_Command_sendmmsg (System_Syscall_Command_BASE + 374)
#define System_Syscall_Command_setns (System_Syscall_Command_BASE + 375)
#define System_Syscall_Command_process_vm_readv (System_Syscall_Command_BASE + 376)
#define System_Syscall_Command_process_vm_writev (System_Syscall_Command_BASE + 377)
#define System_Syscall_Command_kcmp (System_Syscall_Command_BASE + 378)
#define System_Syscall_Command_finit_module (System_Syscall_Command_BASE + 379)
#define System_Syscall_Command_sched_setattr (System_Syscall_Command_BASE + 380)
#define System_Syscall_Command_sched_getattr (System_Syscall_Command_BASE + 381)
#define System_Syscall_Command_renameat2 (System_Syscall_Command_BASE + 382)
#define System_Syscall_Command_seccomp (System_Syscall_Command_BASE + 383)
#define System_Syscall_Command_getrandom (System_Syscall_Command_BASE + 384)
#define System_Syscall_Command_memfd_create (System_Syscall_Command_BASE + 385)
#define System_Syscall_Command_bpf (System_Syscall_Command_BASE + 386)
#define System_Syscall_Command_execveat (System_Syscall_Command_BASE + 387)
#define System_Syscall_Command_userfaultfd (System_Syscall_Command_BASE + 388)
#define System_Syscall_Command_membarrier (System_Syscall_Command_BASE + 389)
#define System_Syscall_Command_mlock2 (System_Syscall_Command_BASE + 390)
#define System_Syscall_Command_copy_file_range (System_Syscall_Command_BASE + 391)
#define System_Syscall_Command_preadv2 (System_Syscall_Command_BASE + 392)
#define System_Syscall_Command_pwritev2 (System_Syscall_Command_BASE + 393)
#define System_Syscall_Command_pkey_mprotect (System_Syscall_Command_BASE + 394)
#define System_Syscall_Command_pkey_alloc (System_Syscall_Command_BASE + 395)
#define System_Syscall_Command_pkey_free (System_Syscall_Command_BASE + 396)
#define System_Syscall_Command_statx (System_Syscall_Command_BASE + 397)
#define System_Syscall_Command_rseq (System_Syscall_Command_BASE + 398)

#elif defined(code_System_Syscall_Command)
[0] = { .name = "Syscall.Command.read", .value = System_Syscall_Command_read },
[1] = { .name = "Syscall.Command.write", .value = System_Syscall_Command_write },
[2] = { .name = "Syscall.Command.open", .value = System_Syscall_Command_open },
[3] = { .name = "Syscall.Command.close", .value = System_Syscall_Command_close },
[4] = { .name = "Syscall.Command.stat", .value = System_Syscall_Command_stat },
[5] = { .name = "Syscall.Command.fstat", .value = System_Syscall_Command_fstat },
[6] = { .name = "Syscall.Command.lstat", .value = System_Syscall_Command_lstat },
[7] = { .name = "Syscall.Command.poll", .value = System_Syscall_Command_poll },
[8] = { .name = "Syscall.Command.lseek", .value = System_Syscall_Command_lseek },
[9] = { .name = "Syscall.Command.mmap", .value = System_Syscall_Command_mmap },
[10] = { .name = "Syscall.Command.mprotect", .value = System_Syscall_Command_mprotect },
[11] = { .name = "Syscall.Command.munmap", .value = System_Syscall_Command_munmap },
[12] = { .name = "Syscall.Command.brk", .value = System_Syscall_Command_brk },
[13] = { .name = "Syscall.Command.rt_sigaction", .value = System_Syscall_Command_rt_sigaction },
[14] = { .name = "Syscall.Command.rt_sigprocmask", .value = System_Syscall_Command_rt_sigprocmask },
[15] = { .name = "Syscall.Command.rt_sigreturn", .value = System_Syscall_Command_rt_sigreturn },
[16] = { .name = "Syscall.Command.ioctl", .value = System_Syscall_Command_ioctl },
[17] = { .name = "Syscall.Command.pread64", .value = System_Syscall_Command_pread64 },
[18] = { .name = "Syscall.Command.pwrite64", .value = System_Syscall_Command_pwrite64 },
[19] = { .name = "Syscall.Command.readv", .value = System_Syscall_Command_readv },
[20] = { .name = "Syscall.Command.writev", .value = System_Syscall_Command_writev },
[21] = { .name = "Syscall.Command.access", .value = System_Syscall_Command_access },
[22] = { .name = "Syscall.Command.pipe", .value = System_Syscall_Command_pipe },
[23] = { .name = "Syscall.Command.select", .value = System_Syscall_Command_select },
[24] = { .name = "Syscall.Command.sched_yield", .value = System_Syscall_Command_sched_yield },
[25] = { .name = "Syscall.Command.mremap", .value = System_Syscall_Command_mremap },
[26] = { .name = "Syscall.Command.msync", .value = System_Syscall_Command_msync },
[27] = { .name = "Syscall.Command.mincore", .value = System_Syscall_Command_mincore },
[28] = { .name = "Syscall.Command.madvise", .value = System_Syscall_Command_madvise },
[29] = { .name = "Syscall.Command.shmget", .value = System_Syscall_Command_shmget },
[30] = { .name = "Syscall.Command.shmat", .value = System_Syscall_Command_shmat },
[31] = { .name = "Syscall.Command.shmctl", .value = System_Syscall_Command_shmctl },
[32] = { .name = "Syscall.Command.dup", .value = System_Syscall_Command_dup },
[33] = { .name = "Syscall.Command.dup2", .value = System_Syscall_Command_dup2 },
[34] = { .name = "Syscall.Command.pause", .value = System_Syscall_Command_pause },
[35] = { .name = "Syscall.Command.nanosleep", .value = System_Syscall_Command_nanosleep },
[36] = { .name = "Syscall.Command.getitimer", .value = System_Syscall_Command_getitimer },
[37] = { .name = "Syscall.Command.alarm", .value = System_Syscall_Command_alarm },
[38] = { .name = "Syscall.Command.setitimer", .value = System_Syscall_Command_setitimer },
[39] = { .name = "Syscall.Command.getpid", .value = System_Syscall_Command_getpid },
[40] = { .name = "Syscall.Command.sendfile", .value = System_Syscall_Command_sendfile },
[41] = { .name = "Syscall.Command.socket", .value = System_Syscall_Command_socket },
[42] = { .name = "Syscall.Command.connect", .value = System_Syscall_Command_connect },
[43] = { .name = "Syscall.Command.accept", .value = System_Syscall_Command_accept },
[44] = { .name = "Syscall.Command.sendto", .value = System_Syscall_Command_sendto },
[45] = { .name = "Syscall.Command.recvfrom", .value = System_Syscall_Command_recvfrom },
[46] = { .name = "Syscall.Command.sendmsg", .value = System_Syscall_Command_sendmsg },
[47] = { .name = "Syscall.Command.recvmsg", .value = System_Syscall_Command_recvmsg },
[48] = { .name = "Syscall.Command.shutdown", .value = System_Syscall_Command_shutdown },
[49] = { .name = "Syscall.Command.bind", .value = System_Syscall_Command_bind },
[50] = { .name = "Syscall.Command.listen", .value = System_Syscall_Command_listen },
[51] = { .name = "Syscall.Command.getsockname", .value = System_Syscall_Command_getsockname },
[52] = { .name = "Syscall.Command.getpeername", .value = System_Syscall_Command_getpeername },
[53] = { .name = "Syscall.Command.socketpair", .value = System_Syscall_Command_socketpair },
[54] = { .name = "Syscall.Command.setsockopt", .value = System_Syscall_Command_setsockopt },
[55] = { .name = "Syscall.Command.getsockopt", .value = System_Syscall_Command_getsockopt },
[56] = { .name = "Syscall.Command.clone", .value = System_Syscall_Command_clone },
[57] = { .name = "Syscall.Command.fork", .value = System_Syscall_Command_fork },
[58] = { .name = "Syscall.Command.vfork", .value = System_Syscall_Command_vfork },
[59] = { .name = "Syscall.Command.execve", .value = System_Syscall_Command_execve },
[60] = { .name = "Syscall.Command.exit", .value = System_Syscall_Command_exit },
[61] = { .name = "Syscall.Command.wait4", .value = System_Syscall_Command_wait4 },
[62] = { .name = "Syscall.Command.kill", .value = System_Syscall_Command_kill },
[63] = { .name = "Syscall.Command.uname", .value = System_Syscall_Command_uname },
[64] = { .name = "Syscall.Command.semget", .value = System_Syscall_Command_semget },
[65] = { .name = "Syscall.Command.semop", .value = System_Syscall_Command_semop },
[66] = { .name = "Syscall.Command.semctl", .value = System_Syscall_Command_semctl },
[67] = { .name = "Syscall.Command.shmdt", .value = System_Syscall_Command_shmdt },
[68] = { .name = "Syscall.Command.msgget", .value = System_Syscall_Command_msgget },
[69] = { .name = "Syscall.Command.msgsnd", .value = System_Syscall_Command_msgsnd },
[70] = { .name = "Syscall.Command.msgrcv", .value = System_Syscall_Command_msgrcv },
[71] = { .name = "Syscall.Command.msgctl", .value = System_Syscall_Command_msgctl },
[72] = { .name = "Syscall.Command.fcntl", .value = System_Syscall_Command_fcntl },
[73] = { .name = "Syscall.Command.flock", .value = System_Syscall_Command_flock },
[74] = { .name = "Syscall.Command.fsync", .value = System_Syscall_Command_fsync },
[75] = { .name = "Syscall.Command.fdatasync", .value = System_Syscall_Command_fdatasync },
[76] = { .name = "Syscall.Command.truncate", .value = System_Syscall_Command_truncate },
[77] = { .name = "Syscall.Command.ftruncate", .value = System_Syscall_Command_ftruncate },
[78] = { .name = "Syscall.Command.getdents", .value = System_Syscall_Command_getdents },
[79] = { .name = "Syscall.Command.getcwd", .value = System_Syscall_Command_getcwd },
[80] = { .name = "Syscall.Command.chdir", .value = System_Syscall_Command_chdir },
[81] = { .name = "Syscall.Command.fchdir", .value = System_Syscall_Command_fchdir },
[82] = { .name = "Syscall.Command.rename", .value = System_Syscall_Command_rename },
[83] = { .name = "Syscall.Command.mkdir", .value = System_Syscall_Command_mkdir },
[84] = { .name = "Syscall.Command.rmdir", .value = System_Syscall_Command_rmdir },
[85] = { .name = "Syscall.Command.creat", .value = System_Syscall_Command_creat },
[86] = { .name = "Syscall.Command.link", .value = System_Syscall_Command_link },
[87] = { .name = "Syscall.Command.unlink", .value = System_Syscall_Command_unlink },
[88] = { .name = "Syscall.Command.symlink", .value = System_Syscall_Command_symlink },
[89] = { .name = "Syscall.Command.readlink", .value = System_Syscall_Command_readlink },
[90] = { .name = "Syscall.Command.chmod", .value = System_Syscall_Command_chmod },
[91] = { .name = "Syscall.Command.fchmod", .value = System_Syscall_Command_fchmod },
[92] = { .name = "Syscall.Command.chown", .value = System_Syscall_Command_chown },
[93] = { .name = "Syscall.Command.fchown", .value = System_Syscall_Command_fchown },
[94] = { .name = "Syscall.Command.lchown", .value = System_Syscall_Command_lchown },
[95] = { .name = "Syscall.Command.umask", .value = System_Syscall_Command_umask },
[96] = { .name = "Syscall.Command.gettimeofday", .value = System_Syscall_Command_gettimeofday },
[97] = { .name = "Syscall.Command.getrlimit", .value = System_Syscall_Command_getrlimit },
[98] = { .name = "Syscall.Command.getrusage", .value = System_Syscall_Command_getrusage },
[99] = { .name = "Syscall.Command.sysinfo", .value = System_Syscall_Command_sysinfo },
[100] = { .name = "Syscall.Command.times", .value = System_Syscall_Command_times },
[101] = { .name = "Syscall.Command.ptrace", .value = System_Syscall_Command_ptrace },
[102] = { .name = "Syscall.Command.getuid", .value = System_Syscall_Command_getuid },
[103] = { .name = "Syscall.Command.syslog", .value = System_Syscall_Command_syslog },
[104] = { .name = "Syscall.Command.getgid", .value = System_Syscall_Command_getgid },
[105] = { .name = "Syscall.Command.setuid", .value = System_Syscall_Command_setuid },
[106] = { .name = "Syscall.Command.setgid", .value = System_Syscall_Command_setgid },
[107] = { .name = "Syscall.Command.geteuid", .value = System_Syscall_Command_geteuid },
[108] = { .name = "Syscall.Command.getegid", .value = System_Syscall_Command_getegid },
[109] = { .name = "Syscall.Command.setpgid", .value = System_Syscall_Command_setpgid },
[110] = { .name = "Syscall.Command.getppid", .value = System_Syscall_Command_getppid },
[111] = { .name = "Syscall.Command.getpgrp", .value = System_Syscall_Command_getpgrp },
[112] = { .name = "Syscall.Command.setsid", .value = System_Syscall_Command_setsid },
[113] = { .name = "Syscall.Command.setreuid", .value = System_Syscall_Command_setreuid },
[114] = { .name = "Syscall.Command.setregid", .value = System_Syscall_Command_setregid },
[115] = { .name = "Syscall.Command.getgroups", .value = System_Syscall_Command_getgroups },
[116] = { .name = "Syscall.Command.setgroups", .value = System_Syscall_Command_setgroups },
[117] = { .name = "Syscall.Command.setresuid", .value = System_Syscall_Command_setresuid },
[118] = { .name = "Syscall.Command.getresuid", .value = System_Syscall_Command_getresuid },
[119] = { .name = "Syscall.Command.setresgid", .value = System_Syscall_Command_setresgid },
[120] = { .name = "Syscall.Command.getresgid", .value = System_Syscall_Command_getresgid },
[121] = { .name = "Syscall.Command.getpgid", .value = System_Syscall_Command_getpgid },
[122] = { .name = "Syscall.Command.setfsuid", .value = System_Syscall_Command_setfsuid },
[123] = { .name = "Syscall.Command.setfsgid", .value = System_Syscall_Command_setfsgid },
[124] = { .name = "Syscall.Command.getsid", .value = System_Syscall_Command_getsid },
[125] = { .name = "Syscall.Command.capget", .value = System_Syscall_Command_capget },
[126] = { .name = "Syscall.Command.capset", .value = System_Syscall_Command_capset },
[127] = { .name = "Syscall.Command.rt_sigpending", .value = System_Syscall_Command_rt_sigpending },
[128] = { .name = "Syscall.Command.rt_sigtimedwait", .value = System_Syscall_Command_rt_sigtimedwait },
[129] = { .name = "Syscall.Command.rt_sigqueueinfo", .value = System_Syscall_Command_rt_sigqueueinfo },
[130] = { .name = "Syscall.Command.rt_sigsuspend", .value = System_Syscall_Command_rt_sigsuspend },
[131] = { .name = "Syscall.Command.sigaltstack", .value = System_Syscall_Command_sigaltstack },
[132] = { .name = "Syscall.Command.utime", .value = System_Syscall_Command_utime },
[133] = { .name = "Syscall.Command.mknod", .value = System_Syscall_Command_mknod },
[134] = { .name = "Syscall.Command.uselib", .value = System_Syscall_Command_uselib },
[135] = { .name = "Syscall.Command.personality", .value = System_Syscall_Command_personality },
[136] = { .name = "Syscall.Command.ustat", .value = System_Syscall_Command_ustat },
[137] = { .name = "Syscall.Command.statfs", .value = System_Syscall_Command_statfs },
[138] = { .name = "Syscall.Command.fstatfs", .value = System_Syscall_Command_fstatfs },
[139] = { .name = "Syscall.Command.sysfs", .value = System_Syscall_Command_sysfs },
[140] = { .name = "Syscall.Command.getpriority", .value = System_Syscall_Command_getpriority },
[141] = { .name = "Syscall.Command.setpriority", .value = System_Syscall_Command_setpriority },
[142] = { .name = "Syscall.Command.sched_setparam", .value = System_Syscall_Command_sched_setparam },
[143] = { .name = "Syscall.Command.sched_getparam", .value = System_Syscall_Command_sched_getparam },
[144] = { .name = "Syscall.Command.sched_setscheduler", .value = System_Syscall_Command_sched_setscheduler },
[145] = { .name = "Syscall.Command.sched_getscheduler", .value = System_Syscall_Command_sched_getscheduler },
[146] = { .name = "Syscall.Command.sched_get_priority_max", .value = System_Syscall_Command_sched_get_priority_max },
[147] = { .name = "Syscall.Command.sched_get_priority_min", .value = System_Syscall_Command_sched_get_priority_min },
[148] = { .name = "Syscall.Command.sched_rr_get_interval", .value = System_Syscall_Command_sched_rr_get_interval },
[149] = { .name = "Syscall.Command.mlock", .value = System_Syscall_Command_mlock },
[150] = { .name = "Syscall.Command.munlock", .value = System_Syscall_Command_munlock },
[151] = { .name = "Syscall.Command.mlockall", .value = System_Syscall_Command_mlockall },
[152] = { .name = "Syscall.Command.munlockall", .value = System_Syscall_Command_munlockall },
[153] = { .name = "Syscall.Command.vhangup", .value = System_Syscall_Command_vhangup },
[154] = { .name = "Syscall.Command.pivot_root", .value = System_Syscall_Command_pivot_root },
[155] = { .name = "Syscall.Command._sysctl", .value = System_Syscall_Command__sysctl },
[156] = { .name = "Syscall.Command.prctl", .value = System_Syscall_Command_prctl },
[157] = { .name = "Syscall.Command.adjtimex", .value = System_Syscall_Command_adjtimex },
[158] = { .name = "Syscall.Command.setrlimit", .value = System_Syscall_Command_setrlimit },
[159] = { .name = "Syscall.Command.chroot", .value = System_Syscall_Command_chroot },
[160] = { .name = "Syscall.Command.sync", .value = System_Syscall_Command_sync },
[161] = { .name = "Syscall.Command.acct", .value = System_Syscall_Command_acct },
[162] = { .name = "Syscall.Command.settimeofday", .value = System_Syscall_Command_settimeofday },
[163] = { .name = "Syscall.Command.mount", .value = System_Syscall_Command_mount },
[164] = { .name = "Syscall.Command.umount2", .value = System_Syscall_Command_umount2 },
[165] = { .name = "Syscall.Command.swapon", .value = System_Syscall_Command_swapon },
[166] = { .name = "Syscall.Command.swapoff", .value = System_Syscall_Command_swapoff },
[167] = { .name = "Syscall.Command.reboot", .value = System_Syscall_Command_reboot },
[168] = { .name = "Syscall.Command.sethostname", .value = System_Syscall_Command_sethostname },
[169] = { .name = "Syscall.Command.setdomainname", .value = System_Syscall_Command_setdomainname },
[170] = { .name = "Syscall.Command.init_module", .value = System_Syscall_Command_init_module },
[171] = { .name = "Syscall.Command.delete_module", .value = System_Syscall_Command_delete_module },
[172] = { .name = "Syscall.Command.mmap2", .value = System_Syscall_Command_mmap2 },
[173] = { .name = "Syscall.Command.quotactl", .value = System_Syscall_Command_quotactl },
[174] = { .name = "Syscall.Command.nfsservctl", .value = System_Syscall_Command_nfsservctl },
[175] = { .name = "Syscall.Command.gettid", .value = System_Syscall_Command_gettid },
[176] = { .name = "Syscall.Command.readahead", .value = System_Syscall_Command_readahead },
[177] = { .name = "Syscall.Command.setxattr", .value = System_Syscall_Command_setxattr },
[178] = { .name = "Syscall.Command.lsetxattr", .value = System_Syscall_Command_lsetxattr },
[179] = { .name = "Syscall.Command.fsetxattr", .value = System_Syscall_Command_fsetxattr },
[180] = { .name = "Syscall.Command.getxattr", .value = System_Syscall_Command_getxattr },
[181] = { .name = "Syscall.Command.lgetxattr", .value = System_Syscall_Command_lgetxattr },
[182] = { .name = "Syscall.Command.fgetxattr", .value = System_Syscall_Command_fgetxattr },
[183] = { .name = "Syscall.Command.listxattr", .value = System_Syscall_Command_listxattr },
[184] = { .name = "Syscall.Command.llistxattr", .value = System_Syscall_Command_llistxattr },
[185] = { .name = "Syscall.Command.flistxattr", .value = System_Syscall_Command_flistxattr },
[186] = { .name = "Syscall.Command.removexattr", .value = System_Syscall_Command_removexattr },
[187] = { .name = "Syscall.Command.lremovexattr", .value = System_Syscall_Command_lremovexattr },
[188] = { .name = "Syscall.Command.fremovexattr", .value = System_Syscall_Command_fremovexattr },
[189] = { .name = "Syscall.Command.tkill", .value = System_Syscall_Command_tkill },
[190] = { .name = "Syscall.Command.time", .value = System_Syscall_Command_time },
[191] = { .name = "Syscall.Command.futex", .value = System_Syscall_Command_futex },
[192] = { .name = "Syscall.Command.sched_setaffinity", .value = System_Syscall_Command_sched_setaffinity },
[193] = { .name = "Syscall.Command.sched_getaffinity", .value = System_Syscall_Command_sched_getaffinity },
[194] = { .name = "Syscall.Command.io_setup", .value = System_Syscall_Command_io_setup },
[195] = { .name = "Syscall.Command.io_destroy", .value = System_Syscall_Command_io_destroy },
[196] = { .name = "Syscall.Command.io_getevents", .value = System_Syscall_Command_io_getevents },
[197] = { .name = "Syscall.Command.io_submit", .value = System_Syscall_Command_io_submit },
[198] = { .name = "Syscall.Command.io_cancel", .value = System_Syscall_Command_io_cancel },
[199] = { .name = "Syscall.Command.lookup_dcookie", .value = System_Syscall_Command_lookup_dcookie },
[200] = { .name = "Syscall.Command.epoll_create", .value = System_Syscall_Command_epoll_create },
[201] = { .name = "Syscall.Command.remap_file_pages", .value = System_Syscall_Command_remap_file_pages },
[202] = { .name = "Syscall.Command.getdents64", .value = System_Syscall_Command_getdents64 },
[203] = { .name = "Syscall.Command.set_tid_address", .value = System_Syscall_Command_set_tid_address },
[204] = { .name = "Syscall.Command.semtimedop", .value = System_Syscall_Command_semtimedop },
[205] = { .name = "Syscall.Command.timer_create", .value = System_Syscall_Command_timer_create },
[206] = { .name = "Syscall.Command.timer_settime", .value = System_Syscall_Command_timer_settime },
[207] = { .name = "Syscall.Command.timer_gettime", .value = System_Syscall_Command_timer_gettime },
[208] = { .name = "Syscall.Command.timer_getoverrun", .value = System_Syscall_Command_timer_getoverrun },
[209] = { .name = "Syscall.Command.timer_delete", .value = System_Syscall_Command_timer_delete },
[210] = { .name = "Syscall.Command.clock_settime", .value = System_Syscall_Command_clock_settime },
[211] = { .name = "Syscall.Command.clock_gettime", .value = System_Syscall_Command_clock_gettime },
[212] = { .name = "Syscall.Command.clock_getres", .value = System_Syscall_Command_clock_getres },
[213] = { .name = "Syscall.Command.clock_nanosleep", .value = System_Syscall_Command_clock_nanosleep },
[214] = { .name = "Syscall.Command.exit_group", .value = System_Syscall_Command_exit_group },
[215] = { .name = "Syscall.Command.epoll_wait", .value = System_Syscall_Command_epoll_wait },
[216] = { .name = "Syscall.Command.epoll_ctl", .value = System_Syscall_Command_epoll_ctl },
[217] = { .name = "Syscall.Command.tgkill", .value = System_Syscall_Command_tgkill },
[218] = { .name = "Syscall.Command.utimes", .value = System_Syscall_Command_utimes },
[219] = { .name = "Syscall.Command.vserver", .value = System_Syscall_Command_vserver },
[220] = { .name = "Syscall.Command.mbind", .value = System_Syscall_Command_mbind },
[221] = { .name = "Syscall.Command.set_mempolicy", .value = System_Syscall_Command_set_mempolicy },
[222] = { .name = "Syscall.Command.get_mempolicy", .value = System_Syscall_Command_get_mempolicy },
[223] = { .name = "Syscall.Command.mq_open", .value = System_Syscall_Command_mq_open },
[224] = { .name = "Syscall.Command.mq_unlink", .value = System_Syscall_Command_mq_unlink },
[225] = { .name = "Syscall.Command.mq_timedsend", .value = System_Syscall_Command_mq_timedsend },
[226] = { .name = "Syscall.Command.mq_timedreceive", .value = System_Syscall_Command_mq_timedreceive },
[227] = { .name = "Syscall.Command.mq_notify", .value = System_Syscall_Command_mq_notify },
[228] = { .name = "Syscall.Command.mq_getsetattr", .value = System_Syscall_Command_mq_getsetattr },
[229] = { .name = "Syscall.Command.kexec_load", .value = System_Syscall_Command_kexec_load },
[230] = { .name = "Syscall.Command.waitid", .value = System_Syscall_Command_waitid },
[231] = { .name = "Syscall.Command.add_key", .value = System_Syscall_Command_add_key },
[232] = { .name = "Syscall.Command.request_key", .value = System_Syscall_Command_request_key },
[233] = { .name = "Syscall.Command.keyctl", .value = System_Syscall_Command_keyctl },
[234] = { .name = "Syscall.Command.ioprio_set", .value = System_Syscall_Command_ioprio_set },
[235] = { .name = "Syscall.Command.ioprio_get", .value = System_Syscall_Command_ioprio_get },
[236] = { .name = "Syscall.Command.inotify_init", .value = System_Syscall_Command_inotify_init },
[237] = { .name = "Syscall.Command.inotify_add_watch", .value = System_Syscall_Command_inotify_add_watch },
[238] = { .name = "Syscall.Command.inotify_rm_watch", .value = System_Syscall_Command_inotify_rm_watch },
[239] = { .name = "Syscall.Command.openat", .value = System_Syscall_Command_openat },
[240] = { .name = "Syscall.Command.mkdirat", .value = System_Syscall_Command_mkdirat },
[241] = { .name = "Syscall.Command.mknodat", .value = System_Syscall_Command_mknodat },
[242] = { .name = "Syscall.Command.fchownat", .value = System_Syscall_Command_fchownat },
[243] = { .name = "Syscall.Command.futimesat", .value = System_Syscall_Command_futimesat },
[244] = { .name = "Syscall.Command.fstatat", .value = System_Syscall_Command_fstatat },
[245] = { .name = "Syscall.Command.unlinkat", .value = System_Syscall_Command_unlinkat },
[246] = { .name = "Syscall.Command.renameat", .value = System_Syscall_Command_renameat },
[247] = { .name = "Syscall.Command.linkat", .value = System_Syscall_Command_linkat },
[248] = { .name = "Syscall.Command.symlinkat", .value = System_Syscall_Command_symlinkat },
[249] = { .name = "Syscall.Command.readlinkat", .value = System_Syscall_Command_readlinkat },
[250] = { .name = "Syscall.Command.fchmodat", .value = System_Syscall_Command_fchmodat },
[251] = { .name = "Syscall.Command.faccessat", .value = System_Syscall_Command_faccessat },
[252] = { .name = "Syscall.Command.pselect6", .value = System_Syscall_Command_pselect6 },
[253] = { .name = "Syscall.Command.ppoll", .value = System_Syscall_Command_ppoll },
[254] = { .name = "Syscall.Command.unshare", .value = System_Syscall_Command_unshare },
[255] = { .name = "Syscall.Command.set_robust_list", .value = System_Syscall_Command_set_robust_list },
[256] = { .name = "Syscall.Command.get_robust_list", .value = System_Syscall_Command_get_robust_list },
[257] = { .name = "Syscall.Command.splice", .value = System_Syscall_Command_splice },
[258] = { .name = "Syscall.Command.tee", .value = System_Syscall_Command_tee },
[259] = { .name = "Syscall.Command.vmsplice", .value = System_Syscall_Command_vmsplice },
[260] = { .name = "Syscall.Command.move_pages", .value = System_Syscall_Command_move_pages },
[261] = { .name = "Syscall.Command.utimensat", .value = System_Syscall_Command_utimensat },
[262] = { .name = "Syscall.Command.epoll_pwait", .value = System_Syscall_Command_epoll_pwait },
[263] = { .name = "Syscall.Command.signalfd", .value = System_Syscall_Command_signalfd },
[264] = { .name = "Syscall.Command.timerfd_create", .value = System_Syscall_Command_timerfd_create },
[265] = { .name = "Syscall.Command.eventfd", .value = System_Syscall_Command_eventfd },
[266] = { .name = "Syscall.Command.fallocate", .value = System_Syscall_Command_fallocate },
[267] = { .name = "Syscall.Command.timerfd_settime", .value = System_Syscall_Command_timerfd_settime },
[268] = { .name = "Syscall.Command.timerfd_gettime", .value = System_Syscall_Command_timerfd_gettime },
[269] = { .name = "Syscall.Command.accept4", .value = System_Syscall_Command_accept4 },
[270] = { .name = "Syscall.Command.signalfd4", .value = System_Syscall_Command_signalfd4 },
[271] = { .name = "Syscall.Command.eventfd2", .value = System_Syscall_Command_eventfd2 },
[272] = { .name = "Syscall.Command.epoll_create1", .value = System_Syscall_Command_epoll_create1 },
[273] = { .name = "Syscall.Command.dup3", .value = System_Syscall_Command_dup3 },
[274] = { .name = "Syscall.Command.pipe2", .value = System_Syscall_Command_pipe2 },
[275] = { .name = "Syscall.Command.inotify_init1", .value = System_Syscall_Command_inotify_init1 },
[276] = { .name = "Syscall.Command.preadv", .value = System_Syscall_Command_preadv },
[277] = { .name = "Syscall.Command.pwritev", .value = System_Syscall_Command_pwritev },
[278] = { .name = "Syscall.Command.rt_tgsigqueueinfo", .value = System_Syscall_Command_rt_tgsigqueueinfo },
[279] = { .name = "Syscall.Command.perf_event_open", .value = System_Syscall_Command_perf_event_open },
[280] = { .name = "Syscall.Command.recvmmsg", .value = System_Syscall_Command_recvmmsg },
[281] = { .name = "Syscall.Command.fanotify_init", .value = System_Syscall_Command_fanotify_init },
[282] = { .name = "Syscall.Command.fanotify_mark", .value = System_Syscall_Command_fanotify_mark },
[283] = { .name = "Syscall.Command.prlimit64", .value = System_Syscall_Command_prlimit64 },
[284] = { .name = "Syscall.Command.name_to_handle_at", .value = System_Syscall_Command_name_to_handle_at },
[285] = { .name = "Syscall.Command.open_by_handle_at", .value = System_Syscall_Command_open_by_handle_at },
[286] = { .name = "Syscall.Command.clock_adjtime", .value = System_Syscall_Command_clock_adjtime },
[287] = { .name = "Syscall.Command.syncfs", .value = System_Syscall_Command_syncfs },
[288] = { .name = "Syscall.Command.sendmmsg", .value = System_Syscall_Command_sendmmsg },
[289] = { .name = "Syscall.Command.setns", .value = System_Syscall_Command_setns },
[290] = { .name = "Syscall.Command.getcpu", .value = System_Syscall_Command_getcpu },
[291] = { .name = "Syscall.Command.process_vm_readv", .value = System_Syscall_Command_process_vm_readv },
[292] = { .name = "Syscall.Command.process_vm_writev", .value = System_Syscall_Command_process_vm_writev },
[293] = { .name = "Syscall.Command.kcmp", .value = System_Syscall_Command_kcmp },
[294] = { .name = "Syscall.Command.finit_module", .value = System_Syscall_Command_finit_module },
[295] = { .name = "Syscall.Command.sched_setattr", .value = System_Syscall_Command_sched_setattr },
[296] = { .name = "Syscall.Command.sched_getattr", .value = System_Syscall_Command_sched_getattr },
[297] = { .name = "Syscall.Command.renameat2", .value = System_Syscall_Command_renameat2 },
[298] = { .name = "Syscall.Command.seccomp", .value = System_Syscall_Command_seccomp },
[299] = { .name = "Syscall.Command.getrandom", .value = System_Syscall_Command_getrandom },
[300] = { .name = "Syscall.Command.memfd_create", .value = System_Syscall_Command_memfd_create },
[301] = { .name = "Syscall.Command.bpf", .value = System_Syscall_Command_bpf },
[302] = { .name = "Syscall.Command.execveat", .value = System_Syscall_Command_execveat },
[303] = { .name = "Syscall.Command.userfaultfd", .value = System_Syscall_Command_userfaultfd },
[304] = { .name = "Syscall.Command.membarrier", .value = System_Syscall_Command_membarrier },
[305] = { .name = "Syscall.Command.mlock2", .value = System_Syscall_Command_mlock2 },
[306] = { .name = "Syscall.Command.copy_file_range", .value = System_Syscall_Command_copy_file_range },
[307] = { .name = "Syscall.Command.preadv2", .value = System_Syscall_Command_preadv2 },
[308] = { .name = "Syscall.Command.pwritev2", .value = System_Syscall_Command_pwritev2 },
[309] = { .name = "Syscall.Command.pkey_mprotect", .value = System_Syscall_Command_pkey_mprotect },
[310] = { .name = "Syscall.Command.pkey_alloc", .value = System_Syscall_Command_pkey_alloc },
[311] = { .name = "Syscall.Command.pkey_free", .value = System_Syscall_Command_pkey_free },
[312] = { .name = "Syscall.Command.statx", .value = System_Syscall_Command_statx },
#define System_Syscall_CommandType_fields_length_DEFAULT  313

#endif /* have_ASM_ARM_UNISTD_COMMON_H */
