#include "int_vector_vice_max.h"

int int_vector_vice_max(const struct int_vector vec)
{
    int max = vec.data[0];
    int vmax = vec.data[0];
    size_t i;

    if (vec.size < 2)
    {
        return max;
    }

    for (i = 1; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            vmax = max;
            max = vec.data[i];
        }
    }

    if (max == vec.data[0])
    {
        vmax = vec.data[1];
    }

    for (i = 0; i < vec.size; i++)
    {
        if (vec.data[i] > vmax && vec.data[i] != max)
        {
            vmax = vec.data[i];
        }
    }

    return vmax;
}
