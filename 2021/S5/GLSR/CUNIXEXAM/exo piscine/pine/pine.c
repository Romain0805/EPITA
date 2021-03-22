#include <stdio.h>

void space(unsigned n, unsigned i)
{
    unsigned j1 = 1;
    while (j1 < n - i)
    {
        putchar(32);
        j1++;
    }
}

void etoile(unsigned i)
{
    unsigned j2 = 1;
    while (j2 <= 2 * i + 1)
    {
        putchar(42);
        j2++;
    }
}

int pine(unsigned n)
{
    for (unsigned i = 0; i < n; i++)
    {
        space(n, i);

        etoile(i);

        putchar(10);
    }

    for (unsigned i = 0; i < n / 2; i++)
    {
        space(n, 0);

        putchar(42);

        putchar(10);
    }

    if (n < 3)
    {
        return 1;
    }
    return 0;
}