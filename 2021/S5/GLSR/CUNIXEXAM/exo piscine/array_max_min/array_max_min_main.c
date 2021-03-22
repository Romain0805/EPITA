#include "array_max_min.h"

int main(void)
{
    int max = 0;
    int min = 0;
    int tab[] = { 5, 3, 1, 42, 53, 3, 47 };
    size_t len = 7;
    array_max_min(tab, len, &max, &min);
    printf("max : %d\n", max);
    printf("min : %d\n", min);

    return 0;
}