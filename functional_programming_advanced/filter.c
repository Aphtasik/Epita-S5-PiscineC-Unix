#include <stdlib.h>

#include "functional_programming_advanced.h"

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int))
{
    out_array = malloc(sizeof(int *));
    *out_array = array;
    int out_i = 0;

    for (size_t i = 0; i < len; i++)
    {
        if (func(array[i]))
        {
            *out_array[out_i] = array[i];
            out_i++;
        }
    }
    free(out_array);
    return out_i + 1;
}
