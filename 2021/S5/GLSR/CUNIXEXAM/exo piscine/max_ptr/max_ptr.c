#include <limits.h>
#include <stdio.h>

int max_ptr(int *ptr, size_t size)
{
    int max = INT_MIN;

    for (size_t i = 0; i < size; i++)
    {
        if (max < ptr[i])
            max = ptr[i];
    }
    return max;
}