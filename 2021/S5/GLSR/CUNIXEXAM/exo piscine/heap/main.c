#include <assert.h>
#include <err.h>
#include <errno.h>
#include <stddef.h>
#include <stdlib.h>

#include "heap.h"

int main(void)
{
    struct heap *new_heap = create_heap();
    print_heap(new_heap);
    add(new_heap, 1);
    print_heap(new_heap);
    add(new_heap, 2);
    print_heap(new_heap);
    add(new_heap, 3);
    print_heap(new_heap);
    pop(new_heap);
    print_heap(new_heap);
    delete_heap(new_heap);
    print_heap(new_heap);
    return 0;
}
