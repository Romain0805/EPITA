#include "int_vector_min.h"

int int_vector_min(struct int_vector vec)
{
    int min = vec.data[0];
    for (size_t j = 0; j < vec.size; j++)
    {
        for (size_t i = 0; i < vec.size; i++)
        {
            if (min > vec.data[i])
                min = vec.data[i];
        }
    }
    return min;
}