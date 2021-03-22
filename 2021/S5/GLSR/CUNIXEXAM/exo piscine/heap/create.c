#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *new = malloc(sizeof(struct heap));
    if (new == NULL)
        return NULL;
    new->size = 0;
    new->capacity = 8;
    new->array = malloc(8 * sizeof(int));
    for (int i = 0; i < 8; i++)
        new->array[i] = 0;

    return new;
}
