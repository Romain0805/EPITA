#include "int_vector_vice_max.h"

#include <limits.h>

int *remplissage_arr(const struct int_vector vec, int *a)
{
    size_t i = 0;
    while (i < vec.size)
    {
        a[i] = vec.data[i];
        i++;
    }
    return a;
}

int *trie(int *a, const struct int_vector vec)
{
    for (size_t j = 0; j < vec.size; j++)
    {
        for (size_t i = 0; i < vec.size; i++)
        {
            if (a[i] > a[i + 1])
            {
                int temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
        }
    }
    return a;
}
int int_vector_vice_max(const struct int_vector vec)
{
    int new_arr[1000];

    remplissage_arr(vec, new_arr);

    trie(new_arr, vec);

    return new_arr[vec.size - 2];
}