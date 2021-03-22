#include <stddef.h>

#include "list.h"
#include "person.h"

double get_revenue(const struct list_node *node)
{
    double revenue = 0;
    switch (node->person->type)
    {
    case PERSON_TYPE_STUDENT:
        revenue += 10000;
        break;

    case PERSON_TYPE_TEACHER:
        revenue -= node->person->data.teacher.salary;
        break;

    case PERSON_TYPE_STAFF:
        revenue -= node->person->data.staff.salary;
        break;
    }

    return revenue;
}

ssize_t list_count(const struct list *list, enum person_type type)
{
    if (!list)
        return -1;

    ssize_t count = 0;

    struct list_node *node = list->head;
    while (node->next != list->head)
    {
        if (!node)
            return -1;

        if (node->person->type == type)
            count += 1;
        node = node->next;
    }

    if (node->person->type == type)
        count += 1;

    return count;
}

double list_revenue(const struct list *list)
{
    if (!list)
        return -1;

    struct list_node *node = list->head;
    double revenue = 0;

    while (node->next != list->head)
    {
        if (!node)
            return -1;

        revenue += get_revenue(node);

        node = node->next;
    }

    revenue += get_revenue(node);

    return revenue;
}

double list_average(const struct list *list, size_t promotion)
{
    if (!list)
        return -1;

    struct list_node *node = list->head;
    double average = 0;
    double nb_student = 0;
    while (node->next != list->head)
    {
        if (!node)
            return -1;

        if (node->person->type == PERSON_TYPE_STUDENT)
        {
            if (node->person->data.student.promotion == promotion)
            {
                average += node->person->data.student.average;
                nb_student += 1;
            }
        }
        node = node->next;
    }

    if (node->person->type == PERSON_TYPE_STUDENT)
    {
        if (node->person->data.student.promotion == promotion)
        {
            average += node->person->data.student.average;
            nb_student += 1;
        }
    }
    return average / nb_student;
}
