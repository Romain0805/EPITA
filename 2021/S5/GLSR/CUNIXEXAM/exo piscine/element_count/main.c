#include "element_count.h"

int main(void)
{
    int a[] = { 0, 1, 6, 40, 35 };
    printf(" element_count res = %zu\n", element_count(a, a + 4));
    return 0;
}