#include <stdio.h>
#include <stdlib.h>

int *my_calloc(size_t size, int init)
{
    if (size == 0)
        return NULL;
    int *ptr = malloc(size * sizeof(int));
    for (int i = 0; ptr + i < ptr + size; ++i)
        ptr[i] = init;
    return ptr;
}
