#include <stdio.h>

int int_sqrt(int n)
{
    int i = 0;

    if (n < 0)
        return -1;
    else
    {
        while (i * i < n)
            i++;

        if (i * i == n)
            return i;
        else
            return i - 1;
    }
}