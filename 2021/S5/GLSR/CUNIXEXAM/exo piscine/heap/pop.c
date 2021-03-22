#include <assert.h>
#include <stdlib.h>

#include "heap.h"

void heapify_pop(int *array, size_t i, size_t size)
{
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    size_t g = 0;
    if ((l < size) && (array[l] < array[i]))
        g = l;
    else
        g = r;
    if ((r < size) && (array[r] < array[i]))
        g = r;
    if (g != i)
    {
        int temp = array[i];
        array[i] = array[g];
        array[g] = temp;
        heapify_pop(array, g, size);
    }
}

void make_heap_pop(int *array, size_t i)
{
    for (int j = (i / 2) - 1; j != 0; j--)
        heapify_pop(array, j, i);
}

int pop(struct heap *heap)
{
    assert(heap->size != 0);
    int res = heap->array[0];

    heap->array[0] = heap->array[heap->size];
    heap->array[heap->size] = 0;
    make_heap_pop(heap->array, heap->size - 1);

    return res;
}
