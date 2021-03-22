#include <stdio.h>

int my_pow(int a, int b)
{
    if (a == 0)
        return 0;

    if (b == 0)
        return 1;

    int compteur = 0;
    int res = 1;

    while (compteur < b)
    {
        res = res * a;
        compteur += 1;
    }
    return res;
}