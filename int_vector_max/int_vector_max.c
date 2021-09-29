#include "int_vector_max.h"

int int_vector_max(const struct int_vector vec)
{
    int max = 0;
    
    for (int i = 0; i < vec.size; i++)
    {
        if (data[i] > max)
        {
            max = data[i];
        }
    }
    return max;
}
