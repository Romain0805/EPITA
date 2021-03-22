#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n <= 2)
        return;
    int *list = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        list[i] = i;
    for (int j = 2; j < (n / 2); j++)
        if (list[j] != -1)
            for (int k = 2 * j; k < n; k = k + j)
                list[k] = -1;
    int len = 0;
    for (int i = 2; i < n; i++)
    {
        if (list[i] != -1)
            len += 1;
    }
    printf("%d\n", len);
    free(list);
}