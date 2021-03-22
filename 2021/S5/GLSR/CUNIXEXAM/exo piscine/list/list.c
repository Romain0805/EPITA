#include "list.h"

#include <stdlib.h>

struct list *list_add(struct list *l, int e)
{
    struct list *new1 = malloc(sizeof(struct list));
    if (!new1)
        return l;
    new1->next = l;
    new1->data = e;
    return new1;
}

struct list *list_find(struct list *l, int e)
{
    if (!l)
        return NULL;
    while (l != NULL && l->data != e)
        l = l->next;
    return l;
}

struct list *list_remove(struct list *l, int e)
{
    if (!l)
        return NULL;
    struct list *temp = l;
    if (l->data == e)
    {
        l = l->next;
        free(temp);
        return l;
    }
    struct list *prev = temp;
    while (temp != NULL && temp->data != e)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return l;
    prev->next = temp->next;
    free(temp);
    return l;
}

struct list *list_reverse_sorted_add(struct list *l, int e)
{
    if (!l || l->data < e)
    {
        return list_add(l, e);
    }
    struct list *new1 = malloc(sizeof(struct list));
    if (!new1)
        return l;
    new1->data = e;
    new1->next = NULL;
    struct list *begin = l;
    struct list *temp = l;
    while (l && l->data >= e)
    {
        temp = l;
        l = l->next;
    }
    if (!l)
    {
        temp->next = new1;
    }
    else
    {
        temp->next = new1;
        new1->next = l;
    }
    return begin;
}

struct list *list_remove_if(struct list *l, int (*predicate)(int))
{
    struct list *begin = l;
    struct list *temp = l;

    if (l == NULL)
        return NULL;
    while (predicate(l->data) == 1)
    {
        temp = l;
        l = l->next;
        free(temp);
        if (!l)
            return NULL;
    }
    begin = l;
    temp = l;
    while (l->next != NULL)
    {
        if (predicate(l->next->data) == 1)
        {
            temp = l->next;
            l->next = temp->next;
            free(temp);
        }
        else
        {
            l = l->next;
        }
    }
    return begin;
}