/* syserr.c (emx/gcc) -- Copyright (c) 1990-1992 by Eberhard Mattes */

const char *sys_errlist[] =
    {
    /*  0 EZERO     */ "Error 0",
    /*  1 EPERM     */ "",
    /*  2 ENOENT    */ "No such file or directory",
    /*  3 ESRCH     */ "No such process",
    /*  4 EINTR     */ "Interrupted system call",
    /*  5 EIO       */ "I/O error",
    /*  6 ENXIO     */ "",
    /*  7 E2BIG     */ "Arguments or environment too big",
    /*  8 ENOEXEC   */ "Invalid executable file format",
    /*  9 EBADF     */ "Bad file number",
    /* 10 ECHILD    */ "No children",
    /* 11 EAGAIN    */ "No more processes",
    /* 12 ENOMEM    */ "Not enough memory",
    /* 13 EACCES    */ "Permission denied",
    /* 14 EFAULT    */ "",
    /* 15 ENOTBLK   */ "",
    /* 16 EBUSY     */ "",
    /* 17 EEXIST    */ "File exists",
    /* 18 EXDEV     */ "Cross-device link",
    /* 19 ENODEV    */ "",
    /* 20 ENOTDIR   */ "",
    /* 21 EISDIR    */ "",
    /* 22 EINVAL    */ "Invalid argument",
    /* 23 ENFILE    */ "",
    /* 24 EMFILE    */ "Too many open files",
    /* 25 ENOTTY    */ "",
    /* 26 ETXTBSY   */ "",
    /* 27 EFBIG     */ "",
    /* 28 ENOSPC    */ "Disk full",
    /* 29 ESPIPE    */ "",
    /* 30 EROFS     */ "",
    /* 31 EMLINK    */ "",
    /* 32 EPIPE     */ "",
    /* 33 EDOM      */ "",
    /* 34 ERANGE    */ "Result too large",
    /* 35 EUCLEAN   */ "",
    /* 36 EDEADLOCK */ "",
    /* 37 UNKNOWN   */ "Unknown error"
    };

const int sys_nerr = sizeof (sys_errlist) / sizeof (sys_errlist[0]) - 1;