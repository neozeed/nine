/* sys/types.h (emx/gcc) */

#if !defined (_SYS_TYPES_H)
#define _SYS_TYPES_H

#if !defined (_SIZE_T_DEFINED)
#define _SIZE_T_DEFINED
typedef unsigned long size_t;
#endif

#if !defined (_TIME_T_DEFINED)
#define _TIME_T_DEFINED
typedef long time_t;
#endif

#if !defined (_INO_T_DEFINED)
#define _INO_T_DEFINED
typedef unsigned short ino_t;
#endif

#if !defined (_DEV_T_DEFINED)
#define _DEV_T_DEFINED
typedef short dev_t;
#endif

#if !defined (_OFF_T_DEFINED)
#define _OFF_T_DEFINED
typedef long off_t;
#endif

#endif /* !defined (_SYS_TYPES_H) */
