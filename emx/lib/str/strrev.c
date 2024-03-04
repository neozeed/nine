/* strrev.c (emx/gcc) -- Copyright (c) 1990-1992 by Eberhard Mattes */

#include <string.h>

char *strrev (char *string)
    {
    char *p, *q, c;

    p = q = string;
    while (*q != 0)
        ++q;
    --q;                                  /* Benign, as string must be != 0 */
    while ((size_t)q > (size_t)p)
        {
        c = *p; *p = *q; *q = c;
        ++p; --q;
        }
    return (string);
    }
