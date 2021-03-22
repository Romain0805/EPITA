#include <stdio.h>

unsigned int number_digits_rec(unsigned int n)
{
    unsigned int i = 1;

    if (n < 10)
        return 1;
    else
    {
        return i + number_digits_rec(n / 10);
    }
}