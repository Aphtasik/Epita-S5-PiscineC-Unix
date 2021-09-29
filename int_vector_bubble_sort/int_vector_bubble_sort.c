#include "int_vector_bubble_sort.h"
#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int temp = vec.data[i];
    data[i] = data[j];
    data[j] = temp;

    return vec;
}

struct int_vector int_vector_bubble_sort(struct int_vector vec)
{
    size_t i;
    size_t j;
    for (i = 0; i < vec.size - 1; i++)
    {
        for (j = 0; i < vec.size - i - 1; j++)
        {
            if (vec.data[j] > vec.data[j + 1])
            {
                vec = swap(vec, j, j + 1);
            }
        }
    }
    return vec;
}
