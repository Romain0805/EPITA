#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

int max(char *line)
{
    char *line_new = strdup(line);
    char *rest = line_new;
    char *token = strtok_r(line_new, ",", &rest);
    int max = atoi(token);

    while ((token = strtok_r(rest, ",", &rest)) != NULL)
    {
        if (atoi(token) > max)
        {
            max = atoi(token);
        }
    }

    return max;
}

int main(int argc, char **argv)
{
    if (argc != 2)
        return 1;
    char *patch = argv[1];
    if (!patch)
        return 1;

    FILE *fd = fopen(argv[1], "r");

    if (!fd)
        return 1;

    char *line = NULL;
    size_t temp = 0;
    ssize_t size = getline(&line, &temp, fd);
    while (size >= 0)
    {
        printf("%d\n", max(line));
        size = getline(&line, &temp, fd);
    }

    free(line);
    fclose(fd);
    return 0;
}
