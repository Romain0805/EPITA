#include "levenshtein.h"

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define min3(a, b, c)                                                          \
    ((a) < (b) ? ((a) < (c) ? (a) : (c)) : ((b) < (c) ? (b) : (c)))

size_t my_strlen(const char *s)
{
    size_t i = 0;

    while (s[i] != '\0')
        i++;
    return i;
}

size_t levenshtein(const char *s1, const char *s2)
{
    size_t x = 0;
    size_t y = 0;
    size_t last = 0;
    size_t old = 0;
    size_t s1len = my_strlen(s1);
    size_t s2len = my_strlen(s2);
    if (s1len == 0 && s2len == 0)
        return 0;
    size_t column[100];
    for (y = 1; y <= s1len; y++)
        column[y] = y;
    for (x = 1; x <= s2len; x++)
    {
        column[0] = x;
        for (y = 1, last = x - 1; y <= s1len; y++)
        {
            old = column[y];
            column[y] = min3(column[y] + 1, column[y - 1] + 1,
                             last + (s1[y - 1] == s2[x - 1] ? 0 : 1));
            last = old;
        }
    }
    return column[s1len];
}