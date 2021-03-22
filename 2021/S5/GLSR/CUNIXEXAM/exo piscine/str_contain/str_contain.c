#include "str_contain.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t my_strlen(const char *s)
{
    size_t i = 0;

    while (s[i] != '\0')
        i++;
    return i;
}

size_t my_strspn(const char *str_1, const char *str_2)
{
    size_t count = 0;
    int check = 0;
    for (size_t i = 0; str_1[i] != '\0'; i++)
    {
        for (size_t j = 0; str_2[j] != '\0'; j++)
            if (str_1[i] == str_2[j])
            {
                check = 1;
                break;
            }
        if (check == 0)
            return count;
        check = 0;
        count++;
    }
    return count;
}

size_t my_strcspn(const char *s, const char *reject)
{
    size_t count = 0;
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        for (size_t j = 0; reject[j] != '\0'; j++)
            if (s[i] == reject[j])
                return count;
        count++;
    }
    return count;
}

char *my_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *end;
    if (str == NULL)
        str = *saveptr;

    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    str += my_strspn(str, delim);
    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    end = str + my_strcspn(str, delim);
    if (*end == '\0')
    {
        *saveptr = end;
        return str;
    }
    *end = '\0';
    *saveptr = end + 1;
    return str;
}

unsigned str_contain(const char *str, const char *params)
{
    const char *separator = "|";

    char *strtoken = strtok((char *)params, separator);

    while (strtoken != NULL)
    {
        printf("%s\n", strtoken);
        strtoken = strtok(NULL, separator);
    }

    return 0;
}

size_t count_cuts(const char *str)
{
    size_t res = 0;
    size_t i = 0;

    while (str[i] != "|")
        res++;
    return res;
}

char **split(const char *str, const char *cuts)
{
    printf("mystrlen : %zu\n", my_strlen(str));
    printf("mycutslen : %zu\n", count_cuts(str));
    char **res = malloc(sizeof(char));

    res[1] = "AZEER";
    res[2] = "TEST";
    printf("%s\n", res[1]);
    printf("%s\n", res[2]);

    char test[80], blah[80];
    char *sep = "|";
    char *word, *phrase, *brkt, *brkb;

    strcpy(test, "This|is|a|test");

    for (word = strtok_r(test, sep, &brkt); word;
         word = strtok_r(NULL, sep, &brkt))
    {
        strcpy(blah, "blah:blat:blab:blag");

        for (phrase = strtok_r(blah, sep, &brkb); phrase;
             phrase = strtok_r(NULL, sep, &brkb))
        {
            printf("So far we're at %s:%s\n", word, phrase);
        }
    }
    free(res);
    return res;
}