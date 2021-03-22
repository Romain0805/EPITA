#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
}

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

void heapify(int *tab, int root, int size)
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < size && tab[l] > tab[largest])
        largest = l;

    if (r < size && tab[r] > tab[largest])
        largest = r;

    if (largest != root)
    {
        int swap = tab[root];
        tab[root] = tab[largest];
        tab[largest] = swap;
        heapify(tab, largest, size);
    }
    return;
}

void make_heap(int *tab, int size)
{
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify(tab, i, size);
}

bool check_heap(int *heap, int n)
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && heap[l] > heap[largest])
            return 0;

        if (r < n && heap[r] > heap[largest])
            return 0;
    }
    return 1;
}

int depth1(unsigned n, int i)
{
    unsigned l = 2 * i + 1;
    if (l < n)
        return 1 + depth1(n, l);
    return 1;
}

void pretty_print_heap(FILE *out, const int *v, unsigned n)
{
    int size = ints_width(v, n);
    int depth = depth1(n, 0);
    int nb_char_lines = (size + 1) * pow(2, depth - 1);
    unsigned index = 0;
    for (int i = 0; i < depth; i++)
    {
        int nb_pers_line = pow(2, i);
        int nb_space_line = nb_char_lines / nb_pers_line - size;
        fprintf(out, "%*s%*d", nb_space_line / 2, "", size, v[index++]);
        for (int j = 1; j < nb_pers_line && index < n; j++)
        {
            fprintf(out, "%*s%*d", nb_space_line, "", size, v[index++]);
        }
        fprintf(out, "\n");
    }
}

int pop_heap(int *heap, unsigned *n)
{
    int res = heap[0];
    *n -= 1;
    heap[0] = heap[*n];
    make_heap(heap, *n);
    return res;
}

void heap_sort(int *tab, unsigned n)
{
    int tab2[n];
    unsigned m = n;
    for (unsigned i = 0; i < n; i++)
        tab2[i] = tab[i];
    make_heap(tab2, n);
    for (unsigned j = n; j > 0; j--)
        tab[j - 1] = pop_heap(tab2, &m);
}

void heapify_cmp(int *tab, int root, int size, int (*cmp)(int a, int b))
{
    int largest = root;
    int l = 2 * root + 1;
    int r = 2 * root + 2;

    if (l < size && cmp(tab[l], tab[largest]) == 1)
        largest = l;

    if (r < size && cmp(tab[r], tab[largest]) == 1)
        largest = r;

    if (largest != root)
    {
        int swap = tab[root];
        tab[root] = tab[largest];
        tab[largest] = swap;
        heapify_cmp(tab, largest, size, cmp);
    }
    return;
}

void make_heap_cmp(int *tab, unsigned size, int (*cmp)(int a, int b))
{
    for (int i = (size / 2) - 1; i >= 0; i--)
        heapify_cmp(tab, i, size, cmp);
}

bool check_heap_cmp(const int *heap, int n, int (*cmp)(int a, int b))
{
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < n && cmp(heap[l], heap[largest]) == 1)
            return 0;

        if (r < n && cmp(heap[r], heap[largest]) == 1)
            return 0;
    }
    return 1;
}

int pop_heap_cmp(int *heap, unsigned *n, int (*cmp)(int a, int b))
{
    int res = heap[0];
    *n -= 1;
    heap[0] = heap[*n];
    make_heap_cmp(heap, *n, cmp);
    return res;
}

void heap_sort_cmp(int *tab, unsigned n, int (*cmp)(int a, int b))
{
    int tab2[n];
    unsigned m = n;
    for (unsigned i = 0; i < n; i++)
        tab2[i] = tab[i];
    make_heap_cmp(tab2, n, cmp);
    for (unsigned j = n; j > 0; j--)
        tab[j - 1] = pop_heap_cmp(tab2, &m, cmp);
}

int increasing(int a, int b)
{
    if (a < b)
        return -1;
    return a > b;
}

int decreasing(int a, int b)
{
    if (a > b)
        return -1;
    return a < b;
}

unsigned partition_cmp(int *tab, unsigned b, unsigned e,
                       unsigned p, int (*cmp)(int a, int b))
{
    int x = tab[p];
    int i = b - 1;
    int j = e;
    while (i < j)
    {
        do
        {
            i++;
        } while (cmp(tab[i], x) < 0);
        do
        {
            j--;
        } while (cmp(tab[j], x) > 0);
        if (j <= i)
            return i;
        swap(&tab[i], &tab[j]);
    }
}
/*
unsigned pivot_first(const int* tab, unsigned l, unsigned r,
                     int (*cmp)(int a, int b))
{
  (void) tab;
  (void) r;
  (void) cmp;
  return l;
}


unsigned pivot_rand(const int* tab, unsigned l, unsigned r,
                    int (*cmp)(int a, int b))
{
  (void) tab;
  return l + (rand() % (r - l));
}
*/
/*
unsigned pivot_median3(const int* tab, unsigned l, unsigned r,
                       int (*cmp)(int a, int b))
{

} */

/*
void quick_sort_cmp(int* tab, unsigned count,
                    unsigned (*pivot)(const int* tab, unsigned l, unsigned r,
                                      int (*cmp)(int a, int b)),
                    int (*cmp)(int a, int b))
{

} */