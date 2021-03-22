#include "string_replace.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_strlen(const char *str)
{
    int ret = 0;
    while (str[ret])
        ret++;
    return ret;
}

char *check_searchSize(const char *old_path, int size, char *ret,
                       const char *str)
{
    int searchSize = my_strlen(old_path);
    if (!searchSize)
    {
        ret = malloc(size + 1);
        for (int t = 0; t <= size; t++)
            ret[t] = str[t];
        return ret;
    }
    return NULL;
}

char *string_replace(const char *old_path, const char *str, const char *new_pat)
{
    if (str == NULL)
        return NULL;

    int size = my_strlen(str);
    int retAllocSize = (size + 1) * 2;
    char *ret = NULL;
    ret = check_searchSize(old_path, size, ret, str);
    ret = malloc(retAllocSize);
    char *Buffer = malloc(my_strlen(old_path));
    int bufferSize = 0;
    int j = 0;
    for (int i = 0; i <= size; i++)
    {
        if (retAllocSize <= j + my_strlen(new_pat))
            ret = realloc(ret, retAllocSize *= 2);
        else if (str[i] == old_path[bufferSize])
        {
            Buffer[bufferSize++] = str[i];
            if (bufferSize == my_strlen(old_path))
            {
                bufferSize = 0;
                for (int a = 0; a < my_strlen(new_pat); a++)
                    ret[j++] = new_pat[a];
            }
        }
        else
        {
            for (int k = 0; k < bufferSize; k++)
                ret[j++] = Buffer[k];
            bufferSize = 0;
            ret[j++] = str[i];
        }
    }
    free(Buffer);
    return ret;
}
