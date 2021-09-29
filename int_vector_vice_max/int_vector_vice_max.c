#include "int_vector_vice_max.h"
#include <stddef.h>

int int_vector_vice_max(const struct int_vector vec)
{
    size_t i;
    int max = vec.data[0];
    size_t max_i = 0;

    for (i = 0; i < vec.size; i++)
    {
        if (vec.data[i] > max)
        {
            max = vec.data[i];
            max_i = i;
        }
    }
    
    if (max_i != 0)
    {
        int sec_max = vec.data[0];
    }
    else
    {
        int sec_max = vec.data[0];
    }

    for (i = 0; i < vec.size; i++)
    {
        if (i != max_i && vec.data[i] > sec_max)
        {
            sec_max = vec.data[i];
        }

    }
    return sec_max;
}
