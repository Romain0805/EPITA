#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "person.h"

struct list *list_init(struct list *list)
{
    if (!list)
        return NULL;

    list->head = NULL;
    return list;
}

struct list *list_free(struct list *list)
{
    if (!list)
        return NULL;

    if (!list->head)
    {
        list->head = NULL;
        return list;
    }

    struct list_node *node = list->head;
    if (node->next == node)
    {
        free(node);
        list->head = NULL;
        return list;
    }
    struct list_node *temp = node;

    while (node)
    {
        temp = node;
        node = node->next;
        free(temp);
    }

    list->head = NULL;
    return list;
}

ssize_t list_size(const struct list *list)
{
    if (!list)
        return -1;
    ssize_t count = 1;
    struct list_node *node = list->head;

    while (node->next != list->head)
    {
        count += 1;
        node = node->next;
    }

    return count;
}

struct list_node *list_append(struct list *list, struct person *person)
{
    if (!list || !person)
        return NULL;

    struct list_node *new = malloc(sizeof(struct list_node));
    if (!new)
        abort();
    new->person = person;

    struct list_node *temp = list->head;
    while (temp->next != list->head)
    {
        temp = temp->next;
    }

    temp->next = new;
    new->next = list->head;
    return new;
}

int list_remove(struct list *list, size_t index)
{
    if (!list || !list->head)
        return 0;
    struct list_node *node = list->head;
    struct list_node *temp = node;

    if (list_size(list) == 1)
    {
        free(list->head);
        list->head = NULL;
        return 1;
    }

    while (index > 0)
    {
        if (!node)
            return 0;

        temp = node;
        node = node->next;
        index -= 1;
    }

    temp->next = node->next;
    free(node->person);
    free(node);
    return 1;
}
