#include "functional_programming.h"

int foldr(int *array, size_t len, int (*func)(int, int))
{
    int acc = 0;
    int i;
    for (; (len - i) >= 0; i++)
    {
        acc = func(array[len - i], acc);
    }
    return acc;
}
