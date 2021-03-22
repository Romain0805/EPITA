#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void my_xor_crypt(void *data, size_t data_len, const void *key, size_t key_len)
{
    if (!data | !key)
        return;
    char *data_str = data;
    const char *key_str = key;
    size_t key_index = 0;
    for (size_t i = 0; i < data_len; i++)
    {
        if (key_index == key_len)
            key_index = 0;
        data_str[i] ^= key_str[key_index];
        key_index += 1;
    }
}
