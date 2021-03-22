#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int abs(int i)
{
    if (i < 0)
        return -i;
    return i;
}

unsigned int_width(int i)
{
    unsigned count = 0;
    if (i < 1)
    {
        count += 1;
        i = abs(i);
    }
    while (i >= 1)
    {
        i /= 10;
        count += 1;
    }
    return count;
}

unsigned ints_width(const int *tab, unsigned count)
{
    unsigned max = int_width(tab[0]);
    for (unsigned i = 0; i < count; i++)
    {
        if (max < int_width(tab[i]))
            max = int_width(tab[i]);
    }
    return max;
}
void print_check_begin(FILE *out, unsigned count, unsigned current_index)
{
    unsigned len_space_start = int_width(count - 1) - int_width(current_index);

    for (unsigned j = 0; j < len_space_start && count > 10; j++)
        fprintf(out, " ");
    for (unsigned i = 0; i < int_width(count) + 2; i++)
    {
        if (i == int_width(count) + 1)
            fprintf(out, "]");
        if (i == int_width(count) + 1 - int_width(current_index))
            fprintf(out, "%u", current_index);
        if (i == int_width(count) - int_width(current_index))
            fprintf(out, "[");
    }
}

void print_int_array(FILE *out, const int *tab, unsigned count)
{
    unsigned current_index = 0;
    unsigned temp = 0;
    unsigned len_nb_max = ints_width(tab, count);
    print_check_begin(out, count, 0);
    for (unsigned i = 0; i < count; i++)
    {
        unsigned len_nb = int_width(tab[i]);
        unsigned len_space = len_nb_max - len_nb + 1;
        unsigned len_space_start = int_width(count) - int_width(current_index);
        unsigned nb_index_ligne = ((80 - (2 + int_width(count) + len_space_start)) / (len_nb_max + 1));

        for (unsigned j = 0; j < len_space; j++)
            fprintf(out, " ");
        fprintf(out, "%d", tab[i]);
        current_index++;
        if (current_index == nb_index_ligne)
        {
            temp += current_index;
            current_index = 0;
            if (count - 1 - i > 0)
            {
                fprintf(out, "\n");
                print_check_begin(out, count, temp);
            }
        }
    }
    fprintf(out, "\n");
}

void insert_sort(int *tab, unsigned count)
{
    for (unsigned i = 1; i < count; i++)
    {
        int key = tab[i];
        int j = i - 1;
        while (j >= 0 && tab[j] > key)
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

void insert_sort_cmp(int *tab, unsigned count, int (*cmp)(int a, int b))
{
    for (unsigned i = 1; i < count; i++)
    {
        int key = tab[i];
        int j = i - 1;
        while (j >= 0 && cmp(tab[j], key) > 0)
        {
            tab[j + 1] = tab[j];
            j--;
        }
        tab[j + 1] = key;
    }
}

unsigned linear_search(const int *tab, unsigned count, int val, int (*cmp)(int a, int b))
{
    for (unsigned j = 0; j < count; j++)
    {
        int compare = cmp(tab[j], val);

        if (compare == 0)
            return j;
        else if (compare > 0)
            return j;
    }
    return count;
}

unsigned binary_search(int *tab, unsigned count, int val, int (*cmp)(int a, int b))
{
    int l = 0;
    int r = count;
    int x = val;
    while (r > l)
    {
        int mid = l + (r - l) / 2;
        int compare = cmp(tab[mid], x);
        if (compare == 0)
            return mid;
        if (compare > 0)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

void bs_insert_sort_cmp(int *tab, unsigned count, int (*cmp)(int a, int b))
{
    for (unsigned i = 1; i < count; i++)
    {
        int key = tab[i];
        int j = binary_search(tab, i, tab[i], cmp);
        for (int k = i - 1; k >= j; k--)
            tab[k + 1] = tab[k];
        tab[j] = key;
    }
}

unsigned interpolate(int *tab, unsigned b, unsigned e, int val,
                     int (*cmp)(int, int))
{

    if (cmp(val, tab[e]) > 0)
        return e;
    if (cmp(val, tab[b]) < 0)
        return b;
    unsigned res = b + 0.5 + (((double)(e - b) / 
    (tab[e] - tab[b]))* (val - tab[b]));

    return res;
}

unsigned interpolation_search(int *tab, unsigned count, int val,
                              int (*cmp)(int a, int b))
{
    int l = 0;
    int r = count;
    int x = val;
    while (r > l)
    {
        int mid = interpolate(tab, l, r - 1, x, cmp);
        int compare = cmp(tab[mid], x);
        if (compare == 0)
            return mid;
        if (compare > 0)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}
