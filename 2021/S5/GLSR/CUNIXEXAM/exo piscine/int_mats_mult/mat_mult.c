#include "mat_mult.h"

void mat_mult(int **mat1, int **mat2, size_t *matrix_size, int **out)
{
    for (size_t i = 0; i < matrix_size[0]; i++)
    {
        for (size_t j = 0; j < matrix_size[2]; j++)
        {
            out[i][j] = 0;
            for (size_t x = 0; x < matrix_size[1]; x++)
                *(*(out + i) + j) += *(*(mat1 + i) + x) * *(*(mat2 + x) + j);
        }
    }
}