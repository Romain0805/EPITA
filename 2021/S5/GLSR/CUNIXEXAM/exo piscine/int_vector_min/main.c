#include "int_vector_min.h"

void print_vector(struct int_vector vec)
{
    for (size_t i = 0; i < vec.size - 1; i++)
    {
        printf("%d ", vec.data[i]);
    }
    printf("%d\n", vec.data[vec.size - 1]);

}

int main(void)
{
    struct int_vector new_vec =
    {
        new_vec.size = 5,
        new_vec.data[new_vec.size] =  3, 2, 3, 4, 1
    };

    return int_vector_min(new_vec);
}