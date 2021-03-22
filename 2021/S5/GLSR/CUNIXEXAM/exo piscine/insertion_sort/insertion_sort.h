#ifndef INSERTION_SORT
#define INSERTION_SORT

typedef int (*f_cmp)(const void *, const void *);
void insertion_sort(void **array, f_cmp comp);

#endif /* !INSERTION_SORT */
