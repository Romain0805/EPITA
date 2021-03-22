#include <stdio.h>

void sieve(int n)
{
    int p = 0;
    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (j % i == 0)
                p++;
        }
        if (p == 2)
            printf("%d\n", j);
        p = 0;
    }
}
