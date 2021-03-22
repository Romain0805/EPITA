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