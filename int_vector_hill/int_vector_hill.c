#include "int_vector_hill.h"

#include <stddef.h>

int int_vector_hill(struct int_vector vec)
{
    size_t left = 0;
    size_t right = vec.size - 1;

    while (left != right)
    {
        if (vec.data[left] < vec.data[right])
        {
            if (vec.data[left] <= vec.data[left + 1])
            {
                left++;
            }
            else
            {
                return -1;
            }
        }
        else
        {
            if (vec.data[right - 1] >= vec.data[right])
            {
                right--;
            }
            else
            {
                return -1;
            }
        }
    }

    return ((int)left);
}
