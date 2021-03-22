#include "int_vector_print.h"

#include <stddef.h>
#include <stdio.h>

void int_vector_print(const struct int_vector vec)
{
    size_t i = 0;
    while (i < vec.size - 1)
    {
        printf("%d ", vec.data[i]);
        i++;
    }

    printf("%d\n", vec.data[vec.size - 1]);
}