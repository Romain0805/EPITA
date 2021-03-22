#include "palindrome.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *s)
{
    if (!s)
        return 0;

    int i = 0;

    while (s[i] != '\0')
        i++;
    return i;
}

int check_alphabet(char c)
{
    char alphabet[] =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for (int i = 0; i <= my_strlen(alphabet); i++)
    {
        if (c == alphabet[i])
            return 1;
    }
    return 0;
}

int nb_char_valid(const char *s1)
{
    if (!s1)
        return 0;

    int count_valid_char = 0;

    for (int i = 0; i < my_strlen(s1); i++)
    {
        if (check_alphabet(s1[i]) != 0)
            count_valid_char += 1;
    }
    return count_valid_char;
}

int check_palindrome(char *valid_string, int VALID_SIZE)
{
    if (!valid_string)
        return 0;
    int incr = 0;
    for (int i = 0; i < VALID_SIZE; i++)
    {
        if (valid_string[i] == valid_string[VALID_SIZE - i - 1])
        {
            incr++;
        }
    }
    if (incr == VALID_SIZE)
        return 1;
    else
        return 0;
}

int palindrome(const char *s)
{
    if (!s)
        return 0;

    int count = my_strlen(s);
    if (count <= 1)
        return 1;

    int SIZE = nb_char_valid(s);
    char valid_string[1000];
    int i1 = 0;
    int j1 = 0;
    while (i1 < count)
    {
        if (check_alphabet(s[i1]) == 1)
        {
            valid_string[j1] = s[i1];
            j1++;
        }
        i1++;
    }
    if (check_palindrome(valid_string, SIZE) == 1)
        return 1;
    return 0;
}
