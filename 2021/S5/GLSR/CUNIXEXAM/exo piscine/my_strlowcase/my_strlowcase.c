#include <stdio.h>

void my_strlowcase(char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        if ('A' <= str[i] && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i += 1;
    }
}