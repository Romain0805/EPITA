#include "selection_sort.h"

unsigned array_min(const int arr[], unsigned start, unsigned size)
{
    unsigned index_min = start;
    for (unsigned i = start; i < size; i++)
        if (arr[i] < arr[index_min])
            index_min = i;
    return index_min;
}

void selection_sort(int arr[], unsigned size)
{
    for (unsigned i = 0; i < size; i++)
    {
        unsigned index_min = array_min(arr, i, size);
        int temp = arr[i];
        arr[i] = arr[index_min];
        arr[index_min] = temp;
    }
}
