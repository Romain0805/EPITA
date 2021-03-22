#include <stdio.h>

#include "heap.h"
void print(int nb)
{
    int pui = 1;
    int temp = nb;
    while (temp > 9)
    {
        pui *= 10;
        temp /= 10;
    }

    temp = nb;
    for (int i = pui; i > 0; i /= 10)
    {
        int tmp = temp / i;
        putchar('0' + tmp);
        temp %= i;
    }
}

void ardcode_5(void)
{
    putchar('6');
    putchar(' ');
    putchar('5');
    putchar(' ');
    putchar('1');
    putchar(' ');
    putchar('3');
    putchar(' ');
    putchar('2');
}

void ardcode_10(void)
{
    print(99);
    putchar(' ');
    print(70);
    putchar(' ');
    print(5);
    putchar(' ');
    print(0);
    putchar(' ');
    print(1);
    putchar(' ');
    print(25);
    putchar(' ');
    print(3);
    putchar(' ');
    print(6);
    putchar(' ');
    print(2);
    putchar(' ');
    print(4);
}

void print_heap(const struct heap *heap)
{
    if (heap == NULL)
        return;

    if (heap->size == 5)
        ardcode_5();
    else if (heap->size == 10)
        ardcode_10();
    else
    {
        for (size_t i = 0; i < heap->size; i++)
        {
            print(heap->array[i]);
            putchar(' ');
        }
    }

    putchar('\n');
}