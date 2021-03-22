#include "bubble_sort.h"

#include <stddef.h>
#include <stdio.h>

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void bubble_sort(int arr[], size_t size)
{
    for (size_t i = size; i > 0; i--)
        for (size_t j = 0; j < i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}
