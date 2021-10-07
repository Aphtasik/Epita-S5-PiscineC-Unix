#include "functional_programming.h"

int foldr(int *array, size_t len ,int (*funct)(int,  int))
{
    if (!len)
    {
        return 0;
    }
    return fn(*array, len, foldr(array + 1, len - 1));
}
