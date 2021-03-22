#include <stdio.h>

int main(int argc, char **argv)
{
    char *pointer = *argv;

    if (argc - 1 <= 0 || pointer[0] == '\0')
        return 0;

    int i = 1;
    while (i < argc)
    {
        if (i % 2)
            puts("Hello Even!");
        else
            puts("Hello Odd!");
        puts(argv[i]);
        i++;
    }
    return 0;
}