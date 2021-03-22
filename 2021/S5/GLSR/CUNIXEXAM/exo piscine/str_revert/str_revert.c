#include "str_revert.h"

int my_strlen(const char *s)
{
    int i = 0;

    while (s[i] != '\0')
        i++;
    return i;
}

void str_revert(char str[])
{
    int i = 0;
    int len_str = my_strlen(str) - 1;

    while (i <= len_str / 2)
    {
        char swap = str[i];
        str[i] = str[len_str - i];
        str[len_str - i] = swap;
        i++;
    }
}