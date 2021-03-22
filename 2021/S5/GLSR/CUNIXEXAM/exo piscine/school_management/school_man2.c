#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"
#include "person.h"

static void my_print(const struct person *person)
{
    switch (person->type)
    {
    case PERSON_TYPE_STUDENT:
        printf("type: stduent\n");
        printf("login: %s\n ", person->data.student.login);
        printf("promotion: %zu\n", person->data.student.promotion);
        printf("age: %.2f\n", person->data.student.average);
        printf("\n");
        break;

    case PERSON_TYPE_TEACHER:
        printf("type: teacher\n");
        printf("name: %s\n", person->data.teacher.name);
        printf("speciality: %s\n", person->data.teacher.speciality);
        printf("salary: %.2f\n", person->data.teacher.salary);
        printf("\n");
        break;

    case PERSON_TYPE_STAFF:
        printf("type: staff\n");
        printf("name: %s\n", person->data.staff.name);
        printf("role: %s\n", person->data.staff.role);
        printf("salary: %.2f\n", person->data.staff.salary);
        printf("\n");
        break;
    }
}

int list_dump(const struct list *list)
{
    if (!list)
        return 0;
    if (!list->head)
        return 1;

    struct list_node *node = list->head;
    while (node->next != list->head)
    {
        if (!node)
            return 0;
        my_print(node->person);
        node = node->next;
    }
    my_print(node->person);
    return 1;
}

int list_dump_ordered(const struct list *list)
{
    if (!list)
        return 0;
    if (!list->head)
        return 1;

    struct list_node *node = list->head;
    while (node->next != list->head)
    {
        if (!node)
            return 0;
        my_print(node->person);
        node = node->next;
    }

    my_print(node->person);
    return 1;
}
