#include "functional_programming_advanced.h"

size_t filter(int *array, size_t len, int **out_array, bool (*func)(int))
{
    int **out_array = malloc(sizeof(*int));
    int out_i = 0;

    for (int i = 0; i < len; i++)
    {
        if (func(array[i]))
        {
            *out_array[out_i] = array[i];
            out_i++;
        }
    }
    return out_i + 1;
}
