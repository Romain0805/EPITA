#ifndef INT_VECTOR_MIN_H
#define INT_VECTOR_MIN_H

#define INT_VECTOR_LENGTH 64

#include <stddef.h>
#include <stdio.h>

struct int_vector
{
    size_t size;
    int data[INT_VECTOR_LENGTH];
};

struct int_vector trie(struct int_vector vec);

int int_vector_min(struct int_vector vec);

#endif /* !INT_VECTOR_MIN_H */
