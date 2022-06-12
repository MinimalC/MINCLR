#if !defined(have_auto_System_Syscall_command)
#define have_auto_System_Syscall_command
#define have_ASM_ARM_UNISTD

#define System_Syscall_command_BASE  0x900000

#if defined(__thumb__) || defined(__ARM_EABI__)
#undef  System_Syscall_command_BASE
#define System_Syscall_command_BASE  0
#endif

#define System_Syscall_command_time (System_Syscall_command_BASE + 13)
#define System_Syscall_command_umount (System_Syscall_command_BASE + 22)
#define System_Syscall_command_stime (System_Syscall_command_BASE + 25)
#define System_Syscall_command_alarm (System_Syscall_command_BASE + 27)
#define System_Syscall_command_utime (System_Syscall_command_BASE + 30)
#define System_Syscall_command_getrlimit (System_Syscall_command_BASE + 76)
#define System_Syscall_command_select (System_Syscall_command_BASE + 82)
#define System_Syscall_command_readdir (System_Syscall_command_BASE + 89)
#define System_Syscall_command_mmap (System_Syscall_command_BASE + 90)
#define System_Syscall_command_socketcall (System_Syscall_command_BASE + 102)
#define System_Syscall_command_syscall (System_Syscall_command_BASE + 113) /* ? */
#define System_Syscall_command_ipc (System_Syscall_command_BASE + 117)

#define System_Syscall_command_restart (System_Syscall_command_BASE + 0)
#define System_Syscall_command_exit (System_Syscall_command_BASE + 1)
#define System_Syscall_command_fork (System_Syscall_command_BASE + 2)
#define System_Syscall_command_read (System_Syscall_command_BASE + 3)
#define System_Syscall_command_write (System_Syscall_command_BASE + 4)
#define System_Syscall_command_open (System_Syscall_command_BASE + 5)
#define System_Syscall_command_close (System_Syscall_command_BASE + 6)
#define System_Syscall_command_creat (System_Syscall_command_BASE + 8)
#define System_Syscall_command_link (System_Syscall_command_BASE + 9)
#define System_Syscall_command_unlink (System_Syscall_command_BASE + 10)
#define System_Syscall_command_execve (System_Syscall_command_BASE + 11)
#define System_Syscall_command_chdir (System_Syscall_command_BASE + 12)
#define System_Syscall_command_mknod (System_Syscall_command_BASE + 14)
#define System_Syscall_command_chmod (System_Syscall_command_BASE + 15)
#define System_Syscall_command_lchown (System_Syscall_command_BASE + 16)
#define System_Syscall_command_lseek (System_Syscall_command_BASE + 19)
#define System_Syscall_command_getpid (System_Syscall_command_BASE + 20)
#define System_Syscall_command_mount (System_Syscall_command_BASE + 21)
#define System_Syscall_command_setuid (System_Syscall_command_BASE + 23)
#define System_Syscall_command_getuid (System_Syscall_command_BASE + 24)
#define System_Syscall_command_ptrace (System_Syscall_command_BASE + 26)
#define System_Syscall_command_pause (System_Syscall_command_BASE + 29)
#define System_Syscall_command_access (System_Syscall_command_BASE + 33)
#define System_Syscall_command_nice (System_Syscall_command_BASE + 34)
#define System_Syscall_command_sync (System_Syscall_command_BASE + 36)
#define System_Syscall_command_kill (System_Syscall_command_BASE + 37)
#define System_Syscall_command_rename (System_Syscall_command_BASE + 38)
#define System_Syscall_command_mkdir (System_Syscall_command_BASE + 39)
#define System_Syscall_command_rmdir (System_Syscall_command_BASE + 40)
#define System_Syscall_command_dup (System_Syscall_command_BASE + 41)
#define System_Syscall_command_pipe (System_Syscall_command_BASE + 42)
#define System_Syscall_command_times (System_Syscall_command_BASE + 43)
#define System_Syscall_command_brk (System_Syscall_command_BASE + 45)
#define System_Syscall_command_setgid (System_Syscall_command_BASE + 46)
#define System_Syscall_command_getgid (System_Syscall_command_BASE + 47)
#define System_Syscall_command_geteuid (System_Syscall_command_BASE + 49)
#define System_Syscall_command_getegid (System_Syscall_command_BASE + 50)
#define System_Syscall_command_acct (System_Syscall_command_BASE + 51)
#define System_Syscall_command_umount2 (System_Syscall_command_BASE + 52)
#define System_Syscall_command_ioctl (System_Syscall_command_BASE + 54)
#define System_Syscall_command_fcntl (System_Syscall_command_BASE + 55)
#define System_Syscall_command_setpgid (System_Syscall_command_BASE + 57)
#define System_Syscall_command_umask (System_Syscall_command_BASE + 60)
#define System_Syscall_command_chroot (System_Syscall_command_BASE + 61)
#define System_Syscall_command_ustat (System_Syscall_command_BASE + 62)
#define System_Syscall_command_dup2 (System_Syscall_command_BASE + 63)
#define System_Syscall_command_getppid (System_Syscall_command_BASE + 64)
#define System_Syscall_command_getpgrp (System_Syscall_command_BASE + 65)
#define System_Syscall_command_setsid (System_Syscall_command_BASE + 66)
#define System_Syscall_command_sigaction (System_Syscall_command_BASE + 67)
#define System_Syscall_command_setreuid (System_Syscall_command_BASE + 70)
#define System_Syscall_command_setregid (System_Syscall_command_BASE + 71)
#define System_Syscall_command_sigsuspend (System_Syscall_command_BASE + 72)
#define System_Syscall_command_sigpending (System_Syscall_command_BASE + 73)
#define System_Syscall_command_sethostname (System_Syscall_command_BASE + 74)
#define System_Syscall_command_setrlimit (System_Syscall_command_BASE + 75)
#define System_Syscall_command_getrusage (System_Syscall_command_BASE + 77)
#define System_Syscall_command_gettimeofday (System_Syscall_command_BASE + 78)
#define System_Syscall_command_settimeofday (System_Syscall_command_BASE + 79)
#define System_Syscall_command_getgroups (System_Syscall_command_BASE + 80)
#define System_Syscall_command_setgroups (System_Syscall_command_BASE + 81)
#define System_Syscall_command_symlink (System_Syscall_command_BASE + 83)
#define System_Syscall_command_readlink (System_Syscall_command_BASE + 85)
#define System_Syscall_command_uselib (System_Syscall_command_BASE + 86)
#define System_Syscall_command_swapon (System_Syscall_command_BASE + 87)
#define System_Syscall_command_reboot (System_Syscall_command_BASE + 88)
#define System_Syscall_command_munmap (System_Syscall_command_BASE + 91)
#define System_Syscall_command_truncate (System_Syscall_command_BASE + 92)
#define System_Syscall_command_ftruncate (System_Syscall_command_BASE + 93)
#define System_Syscall_command_fchmod (System_Syscall_command_BASE + 94)
#define System_Syscall_command_fchown (System_Syscall_command_BASE + 95)
#define System_Syscall_command_getpriority (System_Syscall_command_BASE + 96)
#define System_Syscall_command_setpriority (System_Syscall_command_BASE + 97)
#define System_Syscall_command_statfs (System_Syscall_command_BASE + 99)
#define System_Syscall_command_fstatfs (System_Syscall_command_BASE + 100)
#define System_Syscall_command_syslog (System_Syscall_command_BASE + 103)
#define System_Syscall_command_setitimer (System_Syscall_command_BASE + 104)
#define System_Syscall_command_getitimer (System_Syscall_command_BASE + 105)
#define System_Syscall_command_stat (System_Syscall_command_BASE + 106)
#define System_Syscall_command_lstat (System_Syscall_command_BASE + 107)
#define System_Syscall_command_fstat (System_Syscall_command_BASE + 108)
#define System_Syscall_command_vhangup (System_Syscall_command_BASE + 111)
#define System_Syscall_command_wait4 (System_Syscall_command_BASE + 114)
#define System_Syscall_command_swapoff (System_Syscall_command_BASE + 115)
#define System_Syscall_command_sysinfo (System_Syscall_command_BASE + 116)
#define System_Syscall_command_fsync (System_Syscall_command_BASE + 118)
#define System_Syscall_command_sigreturn (System_Syscall_command_BASE + 119)
#define System_Syscall_command_clone (System_Syscall_command_BASE + 120)
#define System_Syscall_command_setdomainname (System_Syscall_command_BASE + 121)
#define System_Syscall_command_uname (System_Syscall_command_BASE + 122)
#define System_Syscall_command_adjtimex (System_Syscall_command_BASE + 124)
#define System_Syscall_command_mprotect (System_Syscall_command_BASE + 125)
#define System_Syscall_command_sigprocmask (System_Syscall_command_BASE + 126)
#define System_Syscall_command_init_module (System_Syscall_command_BASE + 128)
#define System_Syscall_command_delete_module (System_Syscall_command_BASE + 129)
#define System_Syscall_command_quotactl (System_Syscall_command_BASE + 131)
#define System_Syscall_command_getpgid (System_Syscall_command_BASE + 132)
#define System_Syscall_command_fchdir (System_Syscall_command_BASE + 133)
#define System_Syscall_command_bdflush (System_Syscall_command_BASE + 134)
#define System_Syscall_command_sysfs (System_Syscall_command_BASE + 135)
#define System_Syscall_command_personality (System_Syscall_command_BASE + 136)
#define System_Syscall_command_setfsuid (System_Syscall_command_BASE + 138)
#define System_Syscall_command_setfsgid (System_Syscall_command_BASE + 139)
#define System_Syscall_command__llseek (System_Syscall_command_BASE + 140)
#define System_Syscall_command_getdents (System_Syscall_command_BASE + 141)
#define System_Syscall_command__newselect (System_Syscall_command_BASE + 142)
#define System_Syscall_command_flock (System_Syscall_command_BASE + 143)
#define System_Syscall_command_msync (System_Syscall_command_BASE + 144)
#define System_Syscall_command_readv (System_Syscall_command_BASE + 145)
#define System_Syscall_command_writev (System_Syscall_command_BASE + 146)
#define System_Syscall_command_getsid (System_Syscall_command_BASE + 147)
#define System_Syscall_command_fdatasync (System_Syscall_command_BASE + 148)
#define System_Syscall_command__sysctl (System_Syscall_command_BASE + 149)
#define System_Syscall_command_mlock (System_Syscall_command_BASE + 150)
#define System_Syscall_command_munlock (System_Syscall_command_BASE + 151)
#define System_Syscall_command_mlockall (System_Syscall_command_BASE + 152)
#define System_Syscall_command_munlockall (System_Syscall_command_BASE + 153)
#define System_Syscall_command_sched_setparam (System_Syscall_command_BASE + 154)
#define System_Syscall_command_sched_getparam (System_Syscall_command_BASE + 155)
#define System_Syscall_command_sched_setscheduler (System_Syscall_command_BASE + 156)
#define System_Syscall_command_sched_getscheduler (System_Syscall_command_BASE + 157)
#define System_Syscall_command_sched_yield (System_Syscall_command_BASE + 158)
#define System_Syscall_command_sched_get_priority_max (System_Syscall_command_BASE + 159)
#define System_Syscall_command_sched_get_priority_min (System_Syscall_command_BASE + 160)
#define System_Syscall_command_sched_rr_get_interval (System_Syscall_command_BASE + 161)
#define System_Syscall_command_nanosleep (System_Syscall_command_BASE + 162)
#define System_Syscall_command_mremap (System_Syscall_command_BASE + 163)
#define System_Syscall_command_setresuid (System_Syscall_command_BASE + 164)
#define System_Syscall_command_getresuid (System_Syscall_command_BASE + 165)
#define System_Syscall_command_poll (System_Syscall_command_BASE + 168)
#define System_Syscall_command_nfsservctl (System_Syscall_command_BASE + 169)
#define System_Syscall_command_setresgid (System_Syscall_command_BASE + 170)
#define System_Syscall_command_getresgid (System_Syscall_command_BASE + 171)
#define System_Syscall_command_prctl (System_Syscall_command_BASE + 172)
#define System_Syscall_command_rt_sigreturn (System_Syscall_command_BASE + 173)
#define System_Syscall_command_rt_sigaction (System_Syscall_command_BASE + 174)
#define System_Syscall_command_rt_sigprocmask (System_Syscall_command_BASE + 175)
#define System_Syscall_command_rt_sigpending (System_Syscall_command_BASE + 176)
#define System_Syscall_command_rt_sigtimedwait (System_Syscall_command_BASE + 177)
#define System_Syscall_command_rt_sigqueueinfo (System_Syscall_command_BASE + 178)
#define System_Syscall_command_rt_sigsuspend (System_Syscall_command_BASE + 179)
#define System_Syscall_command_pread64 (System_Syscall_command_BASE + 180)
#define System_Syscall_command_pwrite64 (System_Syscall_command_BASE + 181)
#define System_Syscall_command_chown (System_Syscall_command_BASE + 182)
#define System_Syscall_command_getcwd (System_Syscall_command_BASE + 183)
#define System_Syscall_command_capget (System_Syscall_command_BASE + 184)
#define System_Syscall_command_capset (System_Syscall_command_BASE + 185)
#define System_Syscall_command_sigaltstack (System_Syscall_command_BASE + 186)
#define System_Syscall_command_sendfile (System_Syscall_command_BASE + 187)
#define System_Syscall_command_vfork (System_Syscall_command_BASE + 190)
#define System_Syscall_command_ugetrlimit (System_Syscall_command_BASE + 191)
#define System_Syscall_command_mmap2 (System_Syscall_command_BASE + 192)
#define System_Syscall_command_truncate64 (System_Syscall_command_BASE + 193)
#define System_Syscall_command_ftruncate64 (System_Syscall_command_BASE + 194)
#define System_Syscall_command_stat64 (System_Syscall_command_BASE + 195)
#define System_Syscall_command_lstat64 (System_Syscall_command_BASE + 196)
#define System_Syscall_command_fstat64 (System_Syscall_command_BASE + 197)
#define System_Syscall_command_lchown32 (System_Syscall_command_BASE + 198)
#define System_Syscall_command_getuid32 (System_Syscall_command_BASE + 199)
#define System_Syscall_command_getgid32 (System_Syscall_command_BASE + 200)
#define System_Syscall_command_geteuid32 (System_Syscall_command_BASE + 201)
#define System_Syscall_command_getegid32 (System_Syscall_command_BASE + 202)
#define System_Syscall_command_setreuid32 (System_Syscall_command_BASE + 203)
#define System_Syscall_command_setregid32 (System_Syscall_command_BASE + 204)
#define System_Syscall_command_getgroups32 (System_Syscall_command_BASE + 205)
#define System_Syscall_command_setgroups32 (System_Syscall_command_BASE + 206)
#define System_Syscall_command_fchown32 (System_Syscall_command_BASE + 207)
#define System_Syscall_command_setresuid32 (System_Syscall_command_BASE + 208)
#define System_Syscall_command_getresuid32 (System_Syscall_command_BASE + 209)
#define System_Syscall_command_setresgid32 (System_Syscall_command_BASE + 210)
#define System_Syscall_command_getresgid32 (System_Syscall_command_BASE + 211)
#define System_Syscall_command_chown32 (System_Syscall_command_BASE + 212)
#define System_Syscall_command_setuid32 (System_Syscall_command_BASE + 213)
#define System_Syscall_command_setgid32 (System_Syscall_command_BASE + 214)
#define System_Syscall_command_setfsuid32 (System_Syscall_command_BASE + 215)
#define System_Syscall_command_setfsgid32 (System_Syscall_command_BASE + 216)
#define System_Syscall_command_getdents64 (System_Syscall_command_BASE + 217)
#define System_Syscall_command_pivot_root (System_Syscall_command_BASE + 218)
#define System_Syscall_command_mincore (System_Syscall_command_BASE + 219)
#define System_Syscall_command_madvise (System_Syscall_command_BASE + 220)
#define System_Syscall_command_fcntl64 (System_Syscall_command_BASE + 221)
#define System_Syscall_command_gettid (System_Syscall_command_BASE + 224)
#define System_Syscall_command_readahead (System_Syscall_command_BASE + 225)
#define System_Syscall_command_setxattr (System_Syscall_command_BASE + 226)
#define System_Syscall_command_lsetxattr (System_Syscall_command_BASE + 227)
#define System_Syscall_command_fsetxattr (System_Syscall_command_BASE + 228)
#define System_Syscall_command_getxattr (System_Syscall_command_BASE + 229)
#define System_Syscall_command_lgetxattr (System_Syscall_command_BASE + 230)
#define System_Syscall_command_fgetxattr (System_Syscall_command_BASE + 231)
#define System_Syscall_command_listxattr (System_Syscall_command_BASE + 232)
#define System_Syscall_command_llistxattr (System_Syscall_command_BASE + 233)
#define System_Syscall_command_flistxattr (System_Syscall_command_BASE + 234)
#define System_Syscall_command_removexattr (System_Syscall_command_BASE + 235)
#define System_Syscall_command_lremovexattr (System_Syscall_command_BASE + 236)
#define System_Syscall_command_fremovexattr (System_Syscall_command_BASE + 237)
#define System_Syscall_command_tkill (System_Syscall_command_BASE + 238)
#define System_Syscall_command_sendfile64 (System_Syscall_command_BASE + 239)
#define System_Syscall_command_futex (System_Syscall_command_BASE + 240)
#define System_Syscall_command_sched_setaffinity (System_Syscall_command_BASE + 241)
#define System_Syscall_command_sched_getaffinity (System_Syscall_command_BASE + 242)
#define System_Syscall_command_io_setup (System_Syscall_command_BASE + 243)
#define System_Syscall_command_io_destroy (System_Syscall_command_BASE + 244)
#define System_Syscall_command_io_getevents (System_Syscall_command_BASE + 245)
#define System_Syscall_command_io_submit (System_Syscall_command_BASE + 246)
#define System_Syscall_command_io_cancel (System_Syscall_command_BASE + 247)
#define System_Syscall_command_exit_group (System_Syscall_command_BASE + 248)
#define System_Syscall_command_lookup_dcookie (System_Syscall_command_BASE + 249)
#define System_Syscall_command_epoll_create (System_Syscall_command_BASE + 250)
#define System_Syscall_command_epoll_ctl (System_Syscall_command_BASE + 251)
#define System_Syscall_command_epoll_wait (System_Syscall_command_BASE + 252)
#define System_Syscall_command_remap_file_pages (System_Syscall_command_BASE + 253)
#define System_Syscall_command_set_tid_address (System_Syscall_command_BASE + 256)
#define System_Syscall_command_timer_create (System_Syscall_command_BASE + 257)
#define System_Syscall_command_timer_settime (System_Syscall_command_BASE + 258)
#define System_Syscall_command_timer_gettime (System_Syscall_command_BASE + 259)
#define System_Syscall_command_timer_getoverrun (System_Syscall_command_BASE + 260)
#define System_Syscall_command_timer_delete (System_Syscall_command_BASE + 261)
#define System_Syscall_command_clock_settime (System_Syscall_command_BASE + 262)
#define System_Syscall_command_clock_gettime (System_Syscall_command_BASE + 263)
#define System_Syscall_command_clock_getres (System_Syscall_command_BASE + 264)
#define System_Syscall_command_clock_nanosleep (System_Syscall_command_BASE + 265)
#define System_Syscall_command_statfs64 (System_Syscall_command_BASE + 266)
#define System_Syscall_command_fstatfs64 (System_Syscall_command_BASE + 267)
#define System_Syscall_command_tgkill (System_Syscall_command_BASE + 268)
#define System_Syscall_command_utimes (System_Syscall_command_BASE + 269)
#define System_Syscall_command_arm_fadvise64_64 (System_Syscall_command_BASE + 270)
#define System_Syscall_command_pciconfig_iobase (System_Syscall_command_BASE + 271)
#define System_Syscall_command_pciconfig_read (System_Syscall_command_BASE + 272)
#define System_Syscall_command_pciconfig_write (System_Syscall_command_BASE + 273)
#define System_Syscall_command_mq_open (System_Syscall_command_BASE + 274)
#define System_Syscall_command_mq_unlink (System_Syscall_command_BASE + 275)
#define System_Syscall_command_mq_timedsend (System_Syscall_command_BASE + 276)
#define System_Syscall_command_mq_timedreceive (System_Syscall_command_BASE + 277)
#define System_Syscall_command_mq_notify (System_Syscall_command_BASE + 278)
#define System_Syscall_command_mq_getsetattr (System_Syscall_command_BASE + 279)
#define System_Syscall_command_waitid (System_Syscall_command_BASE + 280)
#define System_Syscall_command_socket (System_Syscall_command_BASE + 281)
#define System_Syscall_command_bind (System_Syscall_command_BASE + 282)
#define System_Syscall_command_connect (System_Syscall_command_BASE + 283)
#define System_Syscall_command_listen (System_Syscall_command_BASE + 284)
#define System_Syscall_command_accept (System_Syscall_command_BASE + 285)
#define System_Syscall_command_getsockname (System_Syscall_command_BASE + 286)
#define System_Syscall_command_getpeername (System_Syscall_command_BASE + 287)
#define System_Syscall_command_socketpair (System_Syscall_command_BASE + 288)
#define System_Syscall_command_send (System_Syscall_command_BASE + 289)
#define System_Syscall_command_sendto (System_Syscall_command_BASE + 290)
#define System_Syscall_command_recv (System_Syscall_command_BASE + 291)
#define System_Syscall_command_recvfrom (System_Syscall_command_BASE + 292)
#define System_Syscall_command_shutdown (System_Syscall_command_BASE + 293)
#define System_Syscall_command_setsockopt (System_Syscall_command_BASE + 294)
#define System_Syscall_command_getsockopt (System_Syscall_command_BASE + 295)
#define System_Syscall_command_sendmsg (System_Syscall_command_BASE + 296)
#define System_Syscall_command_recvmsg (System_Syscall_command_BASE + 297)
#define System_Syscall_command_semop (System_Syscall_command_BASE + 298)
#define System_Syscall_command_semget (System_Syscall_command_BASE + 299)
#define System_Syscall_command_semctl (System_Syscall_command_BASE + 300)
#define System_Syscall_command_msgsnd (System_Syscall_command_BASE + 301)
#define System_Syscall_command_msgrcv (System_Syscall_command_BASE + 302)
#define System_Syscall_command_msgget (System_Syscall_command_BASE + 303)
#define System_Syscall_command_msgctl (System_Syscall_command_BASE + 304)
#define System_Syscall_command_shmat (System_Syscall_command_BASE + 305)
#define System_Syscall_command_shmdt (System_Syscall_command_BASE + 306)
#define System_Syscall_command_shmget (System_Syscall_command_BASE + 307)
#define System_Syscall_command_shmctl (System_Syscall_command_BASE + 308)
#define System_Syscall_command_add_key (System_Syscall_command_BASE + 309)
#define System_Syscall_command_request_key (System_Syscall_command_BASE + 310)
#define System_Syscall_command_keyctl (System_Syscall_command_BASE + 311)
#define System_Syscall_command_semtimedop (System_Syscall_command_BASE + 312)
#define System_Syscall_command_vserver (System_Syscall_command_BASE + 313)
#define System_Syscall_command_ioprio_set (System_Syscall_command_BASE + 314)
#define System_Syscall_command_ioprio_get (System_Syscall_command_BASE + 315)
#define System_Syscall_command_inotify_init (System_Syscall_command_BASE + 316)
#define System_Syscall_command_inotify_add_watch (System_Syscall_command_BASE + 317)
#define System_Syscall_command_inotify_rm_watch (System_Syscall_command_BASE + 318)
#define System_Syscall_command_mbind (System_Syscall_command_BASE + 319)
#define System_Syscall_command_get_mempolicy (System_Syscall_command_BASE + 320)
#define System_Syscall_command_set_mempolicy (System_Syscall_command_BASE + 321)
#define System_Syscall_command_openat (System_Syscall_command_BASE + 322)
#define System_Syscall_command_mkdirat (System_Syscall_command_BASE + 323)
#define System_Syscall_command_mknodat (System_Syscall_command_BASE + 324)
#define System_Syscall_command_fchownat (System_Syscall_command_BASE + 325)
#define System_Syscall_command_futimesat (System_Syscall_command_BASE + 326)
#define System_Syscall_command_fstatat (System_Syscall_command_BASE + 327)
#define System_Syscall_command_unlinkat (System_Syscall_command_BASE + 328)
#define System_Syscall_command_renameat (System_Syscall_command_BASE + 329)
#define System_Syscall_command_linkat (System_Syscall_command_BASE + 330)
#define System_Syscall_command_symlinkat (System_Syscall_command_BASE + 331)
#define System_Syscall_command_readlinkat (System_Syscall_command_BASE + 332)
#define System_Syscall_command_fchmodat (System_Syscall_command_BASE + 333)
#define System_Syscall_command_faccessat (System_Syscall_command_BASE + 334)
#define System_Syscall_command_pselect6 (System_Syscall_command_BASE + 335)
#define System_Syscall_command_ppoll (System_Syscall_command_BASE + 336)
#define System_Syscall_command_unshare (System_Syscall_command_BASE + 337)
#define System_Syscall_command_set_robust_list (System_Syscall_command_BASE + 338)
#define System_Syscall_command_get_robust_list (System_Syscall_command_BASE + 339)
#define System_Syscall_command_splice (System_Syscall_command_BASE + 340)
#define System_Syscall_command_arm_sync_file_range (System_Syscall_command_BASE + 341)
#define System_Syscall_command_tee (System_Syscall_command_BASE + 342)
#define System_Syscall_command_vmsplice (System_Syscall_command_BASE + 343)
#define System_Syscall_command_move_pages (System_Syscall_command_BASE + 344)
#define System_Syscall_command_getcpu (System_Syscall_command_BASE + 345)
#define System_Syscall_command_epoll_pwait (System_Syscall_command_BASE + 346)
#define System_Syscall_command_kexec_load (System_Syscall_command_BASE + 347)
#define System_Syscall_command_utimensat (System_Syscall_command_BASE + 348)
#define System_Syscall_command_signalfd (System_Syscall_command_BASE + 349)
#define System_Syscall_command_timerfd_create (System_Syscall_command_BASE + 350)
#define System_Syscall_command_eventfd (System_Syscall_command_BASE + 351)
#define System_Syscall_command_fallocate (System_Syscall_command_BASE + 352)
#define System_Syscall_command_timerfd_settime (System_Syscall_command_BASE + 353)
#define System_Syscall_command_timerfd_gettime (System_Syscall_command_BASE + 354)
#define System_Syscall_command_signalfd4 (System_Syscall_command_BASE + 355)
#define System_Syscall_command_eventfd2 (System_Syscall_command_BASE + 356)
#define System_Syscall_command_epoll_create1 (System_Syscall_command_BASE + 357)
#define System_Syscall_command_dup3 (System_Syscall_command_BASE + 358)
#define System_Syscall_command_pipe2 (System_Syscall_command_BASE + 359)
#define System_Syscall_command_inotify_init1 (System_Syscall_command_BASE + 360)
#define System_Syscall_command_preadv (System_Syscall_command_BASE + 361)
#define System_Syscall_command_pwritev (System_Syscall_command_BASE + 362)
#define System_Syscall_command_rt_tgsigqueueinfo (System_Syscall_command_BASE + 363)
#define System_Syscall_command_perf_event_open (System_Syscall_command_BASE + 364)
#define System_Syscall_command_recvmmsg (System_Syscall_command_BASE + 365)
#define System_Syscall_command_accept4 (System_Syscall_command_BASE + 366)
#define System_Syscall_command_fanotify_init (System_Syscall_command_BASE + 367)
#define System_Syscall_command_fanotify_mark (System_Syscall_command_BASE + 368)
#define System_Syscall_command_prlimit64 (System_Syscall_command_BASE + 369)
#define System_Syscall_command_name_to_handle_at (System_Syscall_command_BASE + 370)
#define System_Syscall_command_open_by_handle_at (System_Syscall_command_BASE + 371)
#define System_Syscall_command_clock_adjtime (System_Syscall_command_BASE + 372)
#define System_Syscall_command_syncfs (System_Syscall_command_BASE + 373)
#define System_Syscall_command_sendmmsg (System_Syscall_command_BASE + 374)
#define System_Syscall_command_setns (System_Syscall_command_BASE + 375)
#define System_Syscall_command_process_vm_readv (System_Syscall_command_BASE + 376)
#define System_Syscall_command_process_vm_writev (System_Syscall_command_BASE + 377)
#define System_Syscall_command_kcmp (System_Syscall_command_BASE + 378)
#define System_Syscall_command_finit_module (System_Syscall_command_BASE + 379)
#define System_Syscall_command_sched_setattr (System_Syscall_command_BASE + 380)
#define System_Syscall_command_sched_getattr (System_Syscall_command_BASE + 381)
#define System_Syscall_command_renameat2 (System_Syscall_command_BASE + 382)
#define System_Syscall_command_seccomp (System_Syscall_command_BASE + 383)
#define System_Syscall_command_getrandom (System_Syscall_command_BASE + 384)
#define System_Syscall_command_memfd_create (System_Syscall_command_BASE + 385)
#define System_Syscall_command_bpf (System_Syscall_command_BASE + 386)
#define System_Syscall_command_execveat (System_Syscall_command_BASE + 387)
#define System_Syscall_command_userfaultfd (System_Syscall_command_BASE + 388)
#define System_Syscall_command_membarrier (System_Syscall_command_BASE + 389)
#define System_Syscall_command_mlock2 (System_Syscall_command_BASE + 390)
#define System_Syscall_command_copy_file_range (System_Syscall_command_BASE + 391)
#define System_Syscall_command_preadv2 (System_Syscall_command_BASE + 392)
#define System_Syscall_command_pwritev2 (System_Syscall_command_BASE + 393)
#define System_Syscall_command_pkey_mprotect (System_Syscall_command_BASE + 394)
#define System_Syscall_command_pkey_alloc (System_Syscall_command_BASE + 395)
#define System_Syscall_command_pkey_free (System_Syscall_command_BASE + 396)
#define System_Syscall_command_statx (System_Syscall_command_BASE + 397)
#define System_Syscall_command_rseq (System_Syscall_command_BASE + 398)

#elif defined(code_System_Syscall_command)
[0] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.read", .value = System_Syscall_command_read },
[1] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.write", .value = System_Syscall_command_write },
[2] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.open", .value = System_Syscall_command_open },
[3] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.close", .value = System_Syscall_command_close },
[4] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.stat", .value = System_Syscall_command_stat },
[5] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fstat", .value = System_Syscall_command_fstat },
[6] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.lstat", .value = System_Syscall_command_lstat },
[7] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.poll", .value = System_Syscall_command_poll },
[8] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.lseek", .value = System_Syscall_command_lseek },
[9] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mmap", .value = System_Syscall_command_mmap },
[10] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mprotect", .value = System_Syscall_command_mprotect },
[11] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.munmap", .value = System_Syscall_command_munmap },
[12] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.brk", .value = System_Syscall_command_brk },
[13] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_sigaction", .value = System_Syscall_command_rt_sigaction },
[14] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_sigprocmask", .value = System_Syscall_command_rt_sigprocmask },
[15] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_sigreturn", .value = System_Syscall_command_rt_sigreturn },
[16] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.ioctl", .value = System_Syscall_command_ioctl },
[17] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pread64", .value = System_Syscall_command_pread64 },
[18] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pwrite64", .value = System_Syscall_command_pwrite64 },
[19] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.readv", .value = System_Syscall_command_readv },
[20] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.writev", .value = System_Syscall_command_writev },
[21] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.access", .value = System_Syscall_command_access },
[22] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pipe", .value = System_Syscall_command_pipe },
[23] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.select", .value = System_Syscall_command_select },
[24] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_yield", .value = System_Syscall_command_sched_yield },
[25] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mremap", .value = System_Syscall_command_mremap },
[26] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.msync", .value = System_Syscall_command_msync },
[27] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mincore", .value = System_Syscall_command_mincore },
[28] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.madvise", .value = System_Syscall_command_madvise },
[29] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.shmget", .value = System_Syscall_command_shmget },
[30] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.shmat", .value = System_Syscall_command_shmat },
[31] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.shmctl", .value = System_Syscall_command_shmctl },
[32] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.dup", .value = System_Syscall_command_dup },
[33] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.dup2", .value = System_Syscall_command_dup2 },
[34] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pause", .value = System_Syscall_command_pause },
[35] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.nanosleep", .value = System_Syscall_command_nanosleep },
[36] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getitimer", .value = System_Syscall_command_getitimer },
[37] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.alarm", .value = System_Syscall_command_alarm },
[38] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setitimer", .value = System_Syscall_command_setitimer },
[39] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getpid", .value = System_Syscall_command_getpid },
[40] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sendfile", .value = System_Syscall_command_sendfile },
[41] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.socket", .value = System_Syscall_command_socket },
[42] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.connect", .value = System_Syscall_command_connect },
[43] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.accept", .value = System_Syscall_command_accept },
[44] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sendto", .value = System_Syscall_command_sendto },
[45] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.recvfrom", .value = System_Syscall_command_recvfrom },
[46] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sendmsg", .value = System_Syscall_command_sendmsg },
[47] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.recvmsg", .value = System_Syscall_command_recvmsg },
[48] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.shutdown", .value = System_Syscall_command_shutdown },
[49] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.bind", .value = System_Syscall_command_bind },
[50] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.listen", .value = System_Syscall_command_listen },
[51] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getsockname", .value = System_Syscall_command_getsockname },
[52] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getpeername", .value = System_Syscall_command_getpeername },
[53] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.socketpair", .value = System_Syscall_command_socketpair },
[54] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setsockopt", .value = System_Syscall_command_setsockopt },
[55] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getsockopt", .value = System_Syscall_command_getsockopt },
[56] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.clone", .value = System_Syscall_command_clone },
[57] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fork", .value = System_Syscall_command_fork },
[58] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.vfork", .value = System_Syscall_command_vfork },
[59] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.execve", .value = System_Syscall_command_execve },
[60] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.exit", .value = System_Syscall_command_exit },
[61] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.wait4", .value = System_Syscall_command_wait4 },
[62] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.kill", .value = System_Syscall_command_kill },
[63] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.uname", .value = System_Syscall_command_uname },
[64] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.semget", .value = System_Syscall_command_semget },
[65] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.semop", .value = System_Syscall_command_semop },
[66] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.semctl", .value = System_Syscall_command_semctl },
[67] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.shmdt", .value = System_Syscall_command_shmdt },
[68] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.msgget", .value = System_Syscall_command_msgget },
[69] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.msgsnd", .value = System_Syscall_command_msgsnd },
[70] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.msgrcv", .value = System_Syscall_command_msgrcv },
[71] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.msgctl", .value = System_Syscall_command_msgctl },
[72] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fcntl", .value = System_Syscall_command_fcntl },
[73] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.flock", .value = System_Syscall_command_flock },
[74] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fsync", .value = System_Syscall_command_fsync },
[75] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fdatasync", .value = System_Syscall_command_fdatasync },
[76] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.truncate", .value = System_Syscall_command_truncate },
[77] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.ftruncate", .value = System_Syscall_command_ftruncate },
[78] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getdents", .value = System_Syscall_command_getdents },
[79] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getcwd", .value = System_Syscall_command_getcwd },
[80] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.chdir", .value = System_Syscall_command_chdir },
[81] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fchdir", .value = System_Syscall_command_fchdir },
[82] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rename", .value = System_Syscall_command_rename },
[83] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mkdir", .value = System_Syscall_command_mkdir },
[84] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rmdir", .value = System_Syscall_command_rmdir },
[85] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.creat", .value = System_Syscall_command_creat },
[86] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.link", .value = System_Syscall_command_link },
[87] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.unlink", .value = System_Syscall_command_unlink },
[88] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.symlink", .value = System_Syscall_command_symlink },
[89] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.readlink", .value = System_Syscall_command_readlink },
[90] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.chmod", .value = System_Syscall_command_chmod },
[91] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fchmod", .value = System_Syscall_command_fchmod },
[92] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.chown", .value = System_Syscall_command_chown },
[93] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fchown", .value = System_Syscall_command_fchown },
[94] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.lchown", .value = System_Syscall_command_lchown },
[95] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.umask", .value = System_Syscall_command_umask },
[96] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.gettimeofday", .value = System_Syscall_command_gettimeofday },
[97] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getrlimit", .value = System_Syscall_command_getrlimit },
[98] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getrusage", .value = System_Syscall_command_getrusage },
[99] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sysinfo", .value = System_Syscall_command_sysinfo },
[100] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.times", .value = System_Syscall_command_times },
[101] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.ptrace", .value = System_Syscall_command_ptrace },
[102] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getuid", .value = System_Syscall_command_getuid },
[103] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.syslog", .value = System_Syscall_command_syslog },
[104] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getgid", .value = System_Syscall_command_getgid },
[105] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setuid", .value = System_Syscall_command_setuid },
[106] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setgid", .value = System_Syscall_command_setgid },
[107] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.geteuid", .value = System_Syscall_command_geteuid },
[108] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getegid", .value = System_Syscall_command_getegid },
[109] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setpgid", .value = System_Syscall_command_setpgid },
[110] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getppid", .value = System_Syscall_command_getppid },
[111] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getpgrp", .value = System_Syscall_command_getpgrp },
[112] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setsid", .value = System_Syscall_command_setsid },
[113] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setreuid", .value = System_Syscall_command_setreuid },
[114] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setregid", .value = System_Syscall_command_setregid },
[115] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getgroups", .value = System_Syscall_command_getgroups },
[116] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setgroups", .value = System_Syscall_command_setgroups },
[117] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setresuid", .value = System_Syscall_command_setresuid },
[118] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getresuid", .value = System_Syscall_command_getresuid },
[119] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setresgid", .value = System_Syscall_command_setresgid },
[120] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getresgid", .value = System_Syscall_command_getresgid },
[121] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getpgid", .value = System_Syscall_command_getpgid },
[122] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setfsuid", .value = System_Syscall_command_setfsuid },
[123] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setfsgid", .value = System_Syscall_command_setfsgid },
[124] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getsid", .value = System_Syscall_command_getsid },
[125] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.capget", .value = System_Syscall_command_capget },
[126] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.capset", .value = System_Syscall_command_capset },
[127] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_sigpending", .value = System_Syscall_command_rt_sigpending },
[128] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_sigtimedwait", .value = System_Syscall_command_rt_sigtimedwait },
[129] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_sigqueueinfo", .value = System_Syscall_command_rt_sigqueueinfo },
[130] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_sigsuspend", .value = System_Syscall_command_rt_sigsuspend },
[131] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sigaltstack", .value = System_Syscall_command_sigaltstack },
[132] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.utime", .value = System_Syscall_command_utime },
[133] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mknod", .value = System_Syscall_command_mknod },
[134] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.uselib", .value = System_Syscall_command_uselib },
[135] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.personality", .value = System_Syscall_command_personality },
[136] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.ustat", .value = System_Syscall_command_ustat },
[137] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.statfs", .value = System_Syscall_command_statfs },
[138] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fstatfs", .value = System_Syscall_command_fstatfs },
[139] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sysfs", .value = System_Syscall_command_sysfs },
[140] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getpriority", .value = System_Syscall_command_getpriority },
[141] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setpriority", .value = System_Syscall_command_setpriority },
[142] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_setparam", .value = System_Syscall_command_sched_setparam },
[143] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_getparam", .value = System_Syscall_command_sched_getparam },
[144] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_setscheduler", .value = System_Syscall_command_sched_setscheduler },
[145] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_getscheduler", .value = System_Syscall_command_sched_getscheduler },
[146] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_get_priority_max", .value = System_Syscall_command_sched_get_priority_max },
[147] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_get_priority_min", .value = System_Syscall_command_sched_get_priority_min },
[148] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_rr_get_interval", .value = System_Syscall_command_sched_rr_get_interval },
[149] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mlock", .value = System_Syscall_command_mlock },
[150] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.munlock", .value = System_Syscall_command_munlock },
[151] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mlockall", .value = System_Syscall_command_mlockall },
[152] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.munlockall", .value = System_Syscall_command_munlockall },
[153] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.vhangup", .value = System_Syscall_command_vhangup },
[154] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pivot_root", .value = System_Syscall_command_pivot_root },
[155] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command._sysctl", .value = System_Syscall_command__sysctl },
[156] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.prctl", .value = System_Syscall_command_prctl },
[157] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.adjtimex", .value = System_Syscall_command_adjtimex },
[158] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setrlimit", .value = System_Syscall_command_setrlimit },
[159] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.chroot", .value = System_Syscall_command_chroot },
[160] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sync", .value = System_Syscall_command_sync },
[161] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.acct", .value = System_Syscall_command_acct },
[162] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.settimeofday", .value = System_Syscall_command_settimeofday },
[163] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mount", .value = System_Syscall_command_mount },
[164] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.umount2", .value = System_Syscall_command_umount2 },
[165] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.swapon", .value = System_Syscall_command_swapon },
[166] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.swapoff", .value = System_Syscall_command_swapoff },
[167] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.reboot", .value = System_Syscall_command_reboot },
[168] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sethostname", .value = System_Syscall_command_sethostname },
[169] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setdomainname", .value = System_Syscall_command_setdomainname },
[170] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.init_module", .value = System_Syscall_command_init_module },
[171] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.delete_module", .value = System_Syscall_command_delete_module },
[172] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mmap2", .value = System_Syscall_command_mmap2 },
[173] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.quotactl", .value = System_Syscall_command_quotactl },
[174] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.nfsservctl", .value = System_Syscall_command_nfsservctl },
[175] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.gettid", .value = System_Syscall_command_gettid },
[176] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.readahead", .value = System_Syscall_command_readahead },
[177] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setxattr", .value = System_Syscall_command_setxattr },
[178] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.lsetxattr", .value = System_Syscall_command_lsetxattr },
[179] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fsetxattr", .value = System_Syscall_command_fsetxattr },
[180] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getxattr", .value = System_Syscall_command_getxattr },
[181] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.lgetxattr", .value = System_Syscall_command_lgetxattr },
[182] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fgetxattr", .value = System_Syscall_command_fgetxattr },
[183] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.listxattr", .value = System_Syscall_command_listxattr },
[184] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.llistxattr", .value = System_Syscall_command_llistxattr },
[185] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.flistxattr", .value = System_Syscall_command_flistxattr },
[186] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.removexattr", .value = System_Syscall_command_removexattr },
[187] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.lremovexattr", .value = System_Syscall_command_lremovexattr },
[188] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fremovexattr", .value = System_Syscall_command_fremovexattr },
[189] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.tkill", .value = System_Syscall_command_tkill },
[190] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.time", .value = System_Syscall_command_time },
[191] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.futex", .value = System_Syscall_command_futex },
[192] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_setaffinity", .value = System_Syscall_command_sched_setaffinity },
[193] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_getaffinity", .value = System_Syscall_command_sched_getaffinity },
[194] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.io_setup", .value = System_Syscall_command_io_setup },
[195] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.io_destroy", .value = System_Syscall_command_io_destroy },
[196] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.io_getevents", .value = System_Syscall_command_io_getevents },
[197] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.io_submit", .value = System_Syscall_command_io_submit },
[198] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.io_cancel", .value = System_Syscall_command_io_cancel },
[199] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.lookup_dcookie", .value = System_Syscall_command_lookup_dcookie },
[200] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.epoll_create", .value = System_Syscall_command_epoll_create },
[201] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.remap_file_pages", .value = System_Syscall_command_remap_file_pages },
[202] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getdents64", .value = System_Syscall_command_getdents64 },
[203] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.set_tid_address", .value = System_Syscall_command_set_tid_address },
[204] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.semtimedop", .value = System_Syscall_command_semtimedop },
[205] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timer_create", .value = System_Syscall_command_timer_create },
[206] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timer_settime", .value = System_Syscall_command_timer_settime },
[207] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timer_gettime", .value = System_Syscall_command_timer_gettime },
[208] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timer_getoverrun", .value = System_Syscall_command_timer_getoverrun },
[209] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timer_delete", .value = System_Syscall_command_timer_delete },
[210] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.clock_settime", .value = System_Syscall_command_clock_settime },
[211] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.clock_gettime", .value = System_Syscall_command_clock_gettime },
[212] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.clock_getres", .value = System_Syscall_command_clock_getres },
[213] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.clock_nanosleep", .value = System_Syscall_command_clock_nanosleep },
[214] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.exit_group", .value = System_Syscall_command_exit_group },
[215] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.epoll_wait", .value = System_Syscall_command_epoll_wait },
[216] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.epoll_ctl", .value = System_Syscall_command_epoll_ctl },
[217] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.tgkill", .value = System_Syscall_command_tgkill },
[218] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.utimes", .value = System_Syscall_command_utimes },
[219] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.vserver", .value = System_Syscall_command_vserver },
[220] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mbind", .value = System_Syscall_command_mbind },
[221] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.set_mempolicy", .value = System_Syscall_command_set_mempolicy },
[222] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.get_mempolicy", .value = System_Syscall_command_get_mempolicy },
[223] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mq_open", .value = System_Syscall_command_mq_open },
[224] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mq_unlink", .value = System_Syscall_command_mq_unlink },
[225] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mq_timedsend", .value = System_Syscall_command_mq_timedsend },
[226] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mq_timedreceive", .value = System_Syscall_command_mq_timedreceive },
[227] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mq_notify", .value = System_Syscall_command_mq_notify },
[228] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mq_getsetattr", .value = System_Syscall_command_mq_getsetattr },
[229] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.kexec_load", .value = System_Syscall_command_kexec_load },
[230] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.waitid", .value = System_Syscall_command_waitid },
[231] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.add_key", .value = System_Syscall_command_add_key },
[232] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.request_key", .value = System_Syscall_command_request_key },
[233] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.keyctl", .value = System_Syscall_command_keyctl },
[234] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.ioprio_set", .value = System_Syscall_command_ioprio_set },
[235] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.ioprio_get", .value = System_Syscall_command_ioprio_get },
[236] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.inotify_init", .value = System_Syscall_command_inotify_init },
[237] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.inotify_add_watch", .value = System_Syscall_command_inotify_add_watch },
[238] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.inotify_rm_watch", .value = System_Syscall_command_inotify_rm_watch },
[239] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.openat", .value = System_Syscall_command_openat },
[240] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mkdirat", .value = System_Syscall_command_mkdirat },
[241] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mknodat", .value = System_Syscall_command_mknodat },
[242] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fchownat", .value = System_Syscall_command_fchownat },
[243] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.futimesat", .value = System_Syscall_command_futimesat },
[244] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fstatat", .value = System_Syscall_command_fstatat },
[245] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.unlinkat", .value = System_Syscall_command_unlinkat },
[246] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.renameat", .value = System_Syscall_command_renameat },
[247] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.linkat", .value = System_Syscall_command_linkat },
[248] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.symlinkat", .value = System_Syscall_command_symlinkat },
[249] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.readlinkat", .value = System_Syscall_command_readlinkat },
[250] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fchmodat", .value = System_Syscall_command_fchmodat },
[251] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.faccessat", .value = System_Syscall_command_faccessat },
[252] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pselect6", .value = System_Syscall_command_pselect6 },
[253] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.ppoll", .value = System_Syscall_command_ppoll },
[254] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.unshare", .value = System_Syscall_command_unshare },
[255] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.set_robust_list", .value = System_Syscall_command_set_robust_list },
[256] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.get_robust_list", .value = System_Syscall_command_get_robust_list },
[257] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.splice", .value = System_Syscall_command_splice },
[258] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.tee", .value = System_Syscall_command_tee },
[259] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.vmsplice", .value = System_Syscall_command_vmsplice },
[260] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.move_pages", .value = System_Syscall_command_move_pages },
[261] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.utimensat", .value = System_Syscall_command_utimensat },
[262] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.epoll_pwait", .value = System_Syscall_command_epoll_pwait },
[263] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.signalfd", .value = System_Syscall_command_signalfd },
[264] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timerfd_create", .value = System_Syscall_command_timerfd_create },
[265] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.eventfd", .value = System_Syscall_command_eventfd },
[266] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fallocate", .value = System_Syscall_command_fallocate },
[267] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timerfd_settime", .value = System_Syscall_command_timerfd_settime },
[268] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.timerfd_gettime", .value = System_Syscall_command_timerfd_gettime },
[269] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.accept4", .value = System_Syscall_command_accept4 },
[270] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.signalfd4", .value = System_Syscall_command_signalfd4 },
[271] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.eventfd2", .value = System_Syscall_command_eventfd2 },
[272] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.epoll_create1", .value = System_Syscall_command_epoll_create1 },
[273] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.dup3", .value = System_Syscall_command_dup3 },
[274] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pipe2", .value = System_Syscall_command_pipe2 },
[275] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.inotify_init1", .value = System_Syscall_command_inotify_init1 },
[276] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.preadv", .value = System_Syscall_command_preadv },
[277] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pwritev", .value = System_Syscall_command_pwritev },
[278] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.rt_tgsigqueueinfo", .value = System_Syscall_command_rt_tgsigqueueinfo },
[279] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.perf_event_open", .value = System_Syscall_command_perf_event_open },
[280] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.recvmmsg", .value = System_Syscall_command_recvmmsg },
[281] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fanotify_init", .value = System_Syscall_command_fanotify_init },
[282] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.fanotify_mark", .value = System_Syscall_command_fanotify_mark },
[283] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.prlimit64", .value = System_Syscall_command_prlimit64 },
[284] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.name_to_handle_at", .value = System_Syscall_command_name_to_handle_at },
[285] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.open_by_handle_at", .value = System_Syscall_command_open_by_handle_at },
[286] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.clock_adjtime", .value = System_Syscall_command_clock_adjtime },
[287] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.syncfs", .value = System_Syscall_command_syncfs },
[288] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sendmmsg", .value = System_Syscall_command_sendmmsg },
[289] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.setns", .value = System_Syscall_command_setns },
[290] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getcpu", .value = System_Syscall_command_getcpu },
[291] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.process_vm_readv", .value = System_Syscall_command_process_vm_readv },
[292] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.process_vm_writev", .value = System_Syscall_command_process_vm_writev },
[293] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.kcmp", .value = System_Syscall_command_kcmp },
[294] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.finit_module", .value = System_Syscall_command_finit_module },
[295] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_setattr", .value = System_Syscall_command_sched_setattr },
[296] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.sched_getattr", .value = System_Syscall_command_sched_getattr },
[297] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.renameat2", .value = System_Syscall_command_renameat2 },
[298] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.seccomp", .value = System_Syscall_command_seccomp },
[299] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.getrandom", .value = System_Syscall_command_getrandom },
[300] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.memfd_create", .value = System_Syscall_command_memfd_create },
[301] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.bpf", .value = System_Syscall_command_bpf },
[302] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.execveat", .value = System_Syscall_command_execveat },
[303] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.userfaultfd", .value = System_Syscall_command_userfaultfd },
[304] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.membarrier", .value = System_Syscall_command_membarrier },
[305] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.mlock2", .value = System_Syscall_command_mlock2 },
[306] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.copy_file_range", .value = System_Syscall_command_copy_file_range },
[307] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.preadv2", .value = System_Syscall_command_preadv2 },
[308] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pwritev2", .value = System_Syscall_command_pwritev2 },
[309] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pkey_mprotect", .value = System_Syscall_command_pkey_mprotect },
[310] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pkey_alloc", .value = System_Syscall_command_pkey_alloc },
[311] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.pkey_free", .value = System_Syscall_command_pkey_free },
[312] = { .base = stack_System_Object(System_Type_FieldInfo), .name = "System.Syscall.command.statx", .value = System_Syscall_command_statx },
#define System_Syscall_commandType_fields_length_DEFAULT  313

#endif /* have_ASM_ARM_UNISTD_COMMON_H */
