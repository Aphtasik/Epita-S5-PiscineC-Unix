#include <stddef.h>

int vmax(const int *const ptr, size_t size)
{
    int max = ptr[0];
    int vmax = ptr[1];

    for (size_t i = 1; i < size; i++)
    {
        if (ptr[i] > max)
        {
            vmax = max;
            max = ptr[i];
        }
    }

    return vmax;
}
