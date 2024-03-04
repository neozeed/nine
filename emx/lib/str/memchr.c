/* memchr.c (emx/gcc) -- Copyright (c) 1990-1992 by Eberhard Mattes */
#include <string.h>

void *memchr (const void *s, int c, size_t n)
   {
    size_t i;
    const char *p;

    p = s;
    for (i = 0; i < n; ++i)
           if (p[i] == (char)c)
               return ((void *)(p+i));
    return (NULL);
    }
