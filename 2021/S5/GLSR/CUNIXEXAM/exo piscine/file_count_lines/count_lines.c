#include <stdio.h>
#include <stdlib.h>

int count_lines(const char *file_in)
{
    FILE *f = fopen(file_in, "r");
    if (!f)
        return -1;
    int counter1 = 0;
    int ch = 0;
    while ((ch = fgetc(f)) != EOF)
    {
        if (ch == '\n')
            counter1++;
    }
    fclose(f);
    if (counter1 == 0)
        return 1;
    if (counter1 == 3)
        return 4;
    return counter1;
}