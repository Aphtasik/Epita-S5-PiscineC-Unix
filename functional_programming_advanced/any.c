#include "functional_programming_advanced.h"

bool any(int *array, size_t len, bool (*func)(int))
{
    bool is_ok = false;
    for (int i = 0; i < len; i++)
    {
        if (func(array[i]))
        {
            return true;
        }
    }
    return false;
}
