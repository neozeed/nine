/* strspn.c (emx/gcc) -- Copyright (c) 1990-1992 by Eberhard Mattes */

#include <string.h>

size_t strspn (const char *string1, const char *string2)
    {
    char table[256];
    size_t i;

    memset (table, 0, 256);
    while (*string2 != 0)
        table[(unsigned char)*string2++] = 1;
    table[0] = 0;
    i = 0;
    while (table[(unsigned char)string1[i]])
        ++i;
    return (i);
    }
