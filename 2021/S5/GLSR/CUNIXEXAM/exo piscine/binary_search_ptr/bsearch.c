#include "bsearch.h"

#include <stddef.h>
#include <stdio.h>

int element_count(int *begin, int *end)
{
    int count = 0;
    if (!begin || !end)
        return 0;
    else
    {
        while (begin[count] < *(end - 1))
            count++;
    }
    return count;
}

int check_pos(int *tab, int end, int elt)
{
    if (!tab)
        return -1;
    int pos = 0;
    while (tab[pos] < elt && pos <= end)
        pos++;
    return pos;
}

int binarySearch_rec(int a[], int s, int e, int f)
{
    int m = (s + e) / 2;
    if (a[m] == f)
        return f;
    else if (f > a[m])
        return binarySearch_rec(a, m + 1, e, f);
    else
        return binarySearch_rec(a, s, m - 1, f);
}

int *binary_search(int *begin, int *end, int elt)
{
    if (begin != end)
    {
        int l = *begin;
        int len_begin = element_count(begin, end);
        int r = begin[len_begin];
        int index = check_pos(begin, len_begin, elt);
        // printf("*begin = %d  l = %d\n", *begin, l);
        // printf("len_begin = %d\n", len_begin);
        // printf("*end = %d  r = %d\n", *end, r);
        // printf("elt = %d\n", elt);
        // printf("index = %d\n", index);
        if (elt < l)
        {
            // printf("DEPASSEMENT BEGIN\n");
            return begin;
        }
        else if (r < elt)
        {
            // printf("DEPASSEMENT END\n");
            return end;
        }
        else if (begin[index] == elt)
        {
            // printf("GOOD\n");
            int pos_l = check_pos(begin, len_begin, l);
            int pos_r = check_pos(begin, len_begin, r);
            index = check_pos(begin, len_begin,
                              binarySearch_rec(begin, pos_l, pos_r, elt));
        }
        // printf("GOODGOOD\n");
        return begin + index;
    }
    // printf("AUTRES\n");
    return begin;
}