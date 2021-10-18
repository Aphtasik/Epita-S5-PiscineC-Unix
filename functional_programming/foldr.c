#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int acc = 0;
    for (size_t i = 0; i < len; i++)
    {
        acc = func(array[i], acc);
    }
    return acc;
}
