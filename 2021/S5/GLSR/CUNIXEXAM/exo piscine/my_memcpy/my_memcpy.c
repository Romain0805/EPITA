#include <stddef.h>

void *my_memcpy(void *dest, const void *src, size_t num)
{
    char *d = dest;
    const char *s = src;
    while (num--)
        *d++ = *s++;
    return dest;
}