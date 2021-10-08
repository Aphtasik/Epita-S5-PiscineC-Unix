#include "int_vector_insert_sort.h"

#include <stddef.h>

static struct int_vector swap(struct int_vector vec, size_t i, size_t j)
{
    int temp = vec.data[i];
    vec.data[i] = vec.data[j];
    vec.data[j] = temp;

    return vec;
}

struct int_vector int_vector_inser_sort(struct int_vector vec)
{
    size_t i;
    size_t j;

    for (i = 1; i < vec.size; i++)
    {
        j = i - 1;
        while (j >= 0 && vec.data[i] < vec.data[j])
        {
            vec = swap(vec, j, j + 1);
            j--;
        }
        vec.data[j + 1] = vec.data[i];
    }

    return vec;
}
