#include <stdio.h>

int *add_int_ptr(int *a, int *b)
{
    if (!a || !b)
        return a;
    else
    {
        *a += *b;
        return a;
    }
}