#include <stdlib.h>
#include <stdio.h>

static int calc_size(const char *s)
{
    int res = 0;
    int repeat = 0;
    for (int i = 0; s[i]; i += 1)
    {
        if (i == 0 || s[i] != s[i - 1])
        {
            res += 2;
            repeat = 1;
        }
        else if (s[i] == s[i - 1])
        {
            if (repeat == 9)
            {
                res += 2;
                repeat = 0;
            }
            repeat += 1;
        }
    }
    return res;
}

char *rle_encode(const char *s)
{
    size_t sz = calc_size(s);
    char *res = malloc(sz + 1);
    res[sz] = 0;
    char *tmp = res;
    int repeat = 0;
    for (int i = 0; s[i]; i += 1)
    {
        if (i == 0 || s[i] != s[i - 1])
        {
            if (i != 0)
            {
                tmp[0] = repeat + '0';
                tmp[1] = s[i - 1];
                tmp += 2;
            }
            repeat = 1;
        }
        else if (s[i] == s[i - 1])
        {
            if ( repeat == 9 )
            {
                tmp[0] = repeat + '0';
                tmp[1] = s[i - 1];
                tmp += 2;
            }
            repeat += 1;
        }
        if (repeat)
        {
            tmp[0] = repeat + '0';
            tmp[1] = s[i];
        }
    }
    return res;
}
char *rle_decode(const char *s)
{
    size_t sz = 0;
    for (int i = 0; s[i]; i += 2)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int repeat = s[i] - '0';
            i += 1;
            sz += repeat;
        }
    }
    char *res = malloc(sz + 1);
    res[sz] = 0;
    char *tmp = res;
    for (int i = 0; s[i]; i += 2)
    {
        if (s[i] >= '0' && s[i] <= '9')
        {
            int repeat = s[i] - '0';
            for (int j = 0; j < repeat; j += 1)
            {
                *tmp = s[i + 1];
                tmp += 1;
            }
        }
    }
    return res;
}