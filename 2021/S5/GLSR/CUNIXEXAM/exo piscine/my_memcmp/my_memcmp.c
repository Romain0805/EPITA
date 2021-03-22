#include <stddef.h>

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const unsigned char *str1 = s1;
    const unsigned char *str2 = s2;

    while (num-- > 0)
    {
        if (*str1++ != *str2++)
            return str1[-1] < str2[-1] ? -1 : 1;
    }
    return 0;
}