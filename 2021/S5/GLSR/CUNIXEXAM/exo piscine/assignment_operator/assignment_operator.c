#include <stdio.h>

void plus_equal(int *a, int *b)
{
    if (a == NULL)
        return;
    else if (b == NULL)
        return;
    else
        *a += *b;
}

void minus_equal(int *a, int *b)
{
    if (a == NULL)
        return;
    else if (b == NULL)
        return;
    else
        *a -= *b;
}

void mult_equal(int *a, int *b)
{
    if (a == NULL)
        return;
    else if (b == NULL)
        return;
    else
        *a *= *b;
}

int div_equal(int *a, int *b)
{
    if (a == NULL || *a == 0)
        return 0;
    else if (b == NULL || *b == 0)
        return 0;
    else
    {
        int rst = *a % *b;
        *a = *a / *b;
        return rst;
    }
}
