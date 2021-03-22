#include "element_count.h"

size_t element_count(int *begin, int *end)
{
    size_t count = 0;

    while (begin[count] != *end)
        count++;

    return count;
}