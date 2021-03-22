#include "list.h"

#include <stdio.h>

void list_print(struct list *l)
{
    while (l)
    {
        printf("%d", l->data);
        l = l->next;
        if (l)
            printf(" ");
    }
    printf("\n");
}