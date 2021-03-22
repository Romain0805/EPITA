#include <stdio.h>

int my_strlen(const char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

int my_strcmp(char const *s1, char const *s2)
{
    int score = 0;
    if (my_strlen(s1) > my_strlen(s2))
        return (my_strlen(s1) - my_strlen(s2));
    else if (my_strlen(s1) < my_strlen(s2))
        return (my_strlen(s1) - my_strlen(s2));
    for (int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
    {
        if (s1[i] < s2[i])
            score--;
        else if (s1[i] > s2[i])
            score++;
    }
    return score;
}