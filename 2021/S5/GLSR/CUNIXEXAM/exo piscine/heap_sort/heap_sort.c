#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdio.h>

void heapify_rec(int *array, size_t root, size_t size)
{
    size_t largest = root;
    size_t l = 2 * root + 1;
    size_t r = 2 * root + 2;

    if (l < size && array[l] > array[largest])
        largest = l;

    if (r < size && array[r] > array[largest])
        largest = r;

    if (largest != root)
    {
        int swap = array[root];
        array[root] = array[largest];
        array[largest] = swap;
        heapify_rec(array, largest, size);
    }
}
void heapify(int *array, size_t size)
{
    for (int root = (size / 2) - 1; root >= 0; root--)
        heapify_rec(array, root, size);
}
void heap_sort(int *array, size_t size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(array, size);

    for (int i = size - 1; i >= 0; i--)
    {
        int temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        heapify(array, i);
    }
}