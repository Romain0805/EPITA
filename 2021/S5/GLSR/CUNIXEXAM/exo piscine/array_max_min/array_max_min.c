#include "array_max_min.h"

void array_max_min(int tab[], size_t len, int *max, int *min)
{
    if (tab != NULL || len != 0)
    {
        *min = tab[0];
        *max = tab[0];
        for (size_t i = 0; i < len; i++)
        {
            if (tab[i] > *max)
                *max = tab[i];

            if (tab[i] < *min)
                *min = tab[i];
        }
    }
}