#include <stdio.h>

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