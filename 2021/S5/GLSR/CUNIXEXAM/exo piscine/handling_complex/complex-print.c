#include <stdio.h>

#include "complex.h"

int my_abs(int c)
{
    if (c < 0)
        return -c;
    return c;
}
void print_complex(struct complex a)
{
    if (a.img < 0)
    {
        a.img = my_abs(a.img);
        printf("complex(%.2f - %.2fi)\n", a.real, a.img);
    }
    else
        printf("complex(%.2f + %.2fi)\n", a.real, a.img);
}