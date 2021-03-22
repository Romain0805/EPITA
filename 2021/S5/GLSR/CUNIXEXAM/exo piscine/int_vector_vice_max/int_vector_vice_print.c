#include <stdio.h>
#include "int_vector_vice_max.h"

void print_arr(int *arr, const struct int_vector vec)
{
    int i = 0;
    printf("arr : ");
    while (i < vec.size)
    {
        printf("%d ", arr[i]);
        i++;
    }
    printf("\n");
}

void print_vec(struct int_vector vec)
{
    size_t i = 0;
    printf("vec : ");
    while (i < vec.size)
    {
        printf("%d ", vec.data[i]);
        i++;
    }
    printf("\n");
    printf("vec_size = %zu\n",vec.size);
}