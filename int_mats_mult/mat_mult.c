#include "mat_mult.c"

#include <stddef.h>

void mat_mult(int **mat1, int **mat2, size_t *matrices_size, int **out)
{
    for (size_t i = 0; i < *matrices_size; i++)
    {
        for (size_t j = 0; j < *matrices_size; j++)
        {
            out[i][j] = 0;
            for (size_t k = 0; k < *matrices_size; k++)
            {
                out[i][j] += mat1[i][k] * mat[k][j];
            }
        }
    }
}
