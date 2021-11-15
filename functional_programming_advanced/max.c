#include "functional_programming_advanced.h"

int max(int *array, size_t len)
{
    if (!array)
        return 0;

    int max = array[0];
    for (size_t i = 0; i < len; i++)
    {
        if (array[i] > max)
            max = array[i];
    }
    return max;
}
