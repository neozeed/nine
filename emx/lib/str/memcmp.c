/* memcmp.c (emx/gcc) -- Copyright (c) 1990-1992 by Eberhard Mattes */

#include <string.h>

int memcmp (const void *s1, const void *s2, size_t n)
    {
    int i, d;
    
    for (i = 0; i < n; ++i)
        {
        d = (int)((unsigned char *)s1)[i] - (int)((unsigned char *)s2)[i];
        if (d != 0)
            {
            if (d > 0)
                return (1);
            else
                return (-1);
            }
        }
    return (0);
    }
