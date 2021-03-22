#include <stdio.h>

void print_hanoi(int start, int end)
{
    putchar(start);
    putchar(45);
    putchar(62);
    putchar(end);
    putchar(10);
}

void hanoi_rec(int n, int from, int to, int aux)
{
    if (n == 1)
    {
        print_hanoi(from, to);
        return;
    }
    hanoi_rec(n - 1, from, aux, to);
    print_hanoi(from, to);
    hanoi_rec(n - 1, aux, to, from);
}

void hanoi(unsigned n)
{
    hanoi_rec(n, 49, 51, 50);
}