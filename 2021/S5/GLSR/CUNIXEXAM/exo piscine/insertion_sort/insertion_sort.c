#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>

typedef int (*f_cmp)(const void *, const void *);

void insertion_sort(void **array, f_cmp comp)
{
    if (array != NULL)
    {
        for (int i = 1; array[i] != NULL; i++)
        {
            void *key = array[i];
            int j = i - 1;
            while (j >= 0 && comp(array[j], key) > 0)
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = key;
        }
    }
}
