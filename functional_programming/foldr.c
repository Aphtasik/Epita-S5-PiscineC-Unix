#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int i = 1;
    int acc = 0;
    for (; (len - i) > 0; i++)
    {
        acc = func(array[len - i], acc);
    }
    acc = func(array[len - i], acc);
    return acc;
}
