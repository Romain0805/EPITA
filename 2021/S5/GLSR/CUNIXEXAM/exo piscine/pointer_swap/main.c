#include <assert.h>
#include "pointer_swap.h"

int main(void)
{
    int a = 5;
    int *ptr_a = &a;
    int b = 6;
    int *ptr_b = &b;
    pointer_swap(&ptr_a, &ptr_b);
    assert(ptr_a == &b);
    assert(ptr_b == &a);
    assert(a == 5);
    assert(b == 6);
    return 0;
}