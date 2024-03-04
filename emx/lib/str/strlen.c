/* strlen.c (emx/gcc) -- Copyright (c) 1990-1992 by Eberhard Mattes */

#include <string.h>

size_t strlen (const char *string)
    {
    int i;

    i = 0;
    while (string[i] != 0) ++i;
    return (i);
    }
