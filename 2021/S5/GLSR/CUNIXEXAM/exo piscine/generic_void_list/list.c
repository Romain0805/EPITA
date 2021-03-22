#include "list.h"

#include <stdlib.h>
#include <string.h>

struct list *list_prepend(struct list *list, const void *value,
                          size_t data_size)
{
    struct list *node = malloc(sizeof(struct list));

    if (!node)
    {
        return NULL;
    }
    node->data = malloc(data_size);

    if (!node->data)
    {
        return NULL;
    }

    memcpy(node->data, value, data_size);
    node->next = list;
    return node;
}

size_t list_length(struct list *list)
{
    if (!list)
    {
        return 0;
    }
    size_t lenght = 0;

    while (list != NULL)
    {
        lenght++;
        list = list->next;
    }

    return lenght;
}

void list_destroy(struct list *list)
{
    struct list *temp = NULL;

    while (list)
    {
        temp = list;
        list = list->next;
        free(temp->data);
        free(temp);
    }
}
