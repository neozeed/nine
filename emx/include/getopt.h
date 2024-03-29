/* getopt (emx/gcc) */

#if !defined (_GETOPT_H)
#define _GETOPT_H

#if !defined (_GETOPT_C)

extern char *optarg;       /* argument of current option                    */
extern int optind;         /* index of next argument; default=0: initialize */
extern int opterr;         /* 0=disable error messages; default=1: enable   */
extern char *optswchar;    /* characters introducing options; default="-"   */

#endif

extern enum _optmode
    {
    GETOPT_UNIX,           /* options at start of argument list (default)   */
    GETOPT_ANY,            /* move non-options to the end                   */
    GETOPT_KEEP,           /* return options in order                       */
    } optmode;


int getopt (int argc, char **argv, const char *opt_str);

#endif /* !defined (_GETOPT_H) */
