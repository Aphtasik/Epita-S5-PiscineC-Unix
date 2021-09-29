#include "int_vector_vice_max.h"
#include <stddef.h>

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int vmax = vec.data[1];

    for (size_t i = 1; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            vmax = max;
            max = vec.data[i];
        }
    }

    return vmax;
}
