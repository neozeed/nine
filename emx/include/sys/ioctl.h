/* ioctl.h (emx/gcc) */

#if !defined (_SYS_IOCTL_H)
#define _SYS_IOCTL_H

#if !defined (TCGETA)
#define TCGETA      1
#define TCSETA      2
#define TCSETAW     3
#define TCSETAF     4
#define TCFLSH      5
#endif

#if !defined (FIONREAD)
#define FIONREAD   16
#endif

int ioctl (int handle, int request, ...);

#endif /* !defined (_SYS_IOCTL_H) */
