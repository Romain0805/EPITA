#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

void add_heapify_construct(int *array, size_t i, size_t size)
{
    size_t l = 2 * i + 1;
    size_t r = 2 * i + 2;
    size_t g = i;

    if ((l < size) && (array[l] > array[i]))
        g = l;
    if ((r < size) && (array[r] > array[g]))
        g = r;
    if (g != i)
    {
        int temp = array[i];
        array[i] = array[g];
        array[g] = temp;
        add_heapify_construct(array, g, size);
    }
}

void add_heapify(int *array, size_t size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
        add_heapify_construct(array, i, size);
}

void add(struct heap *heap, int val)
{
    if ((heap->size % 8 == 0) && (heap->size != 0))
        heap->array = realloc(heap->array, heap->size + 8 * sizeof(int));

    heap->array[heap->size] = val;
    heap->size++;

    add_heapify(heap->array, heap->size);
}
