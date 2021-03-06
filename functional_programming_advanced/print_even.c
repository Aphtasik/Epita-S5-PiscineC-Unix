#include <stdio.h>
#include <stdlib.h>

#include "functional_programming_advanced.h"

static bool even(int n)
{
    return n % 2 == 0;
}

void print_even(int *array, size_t len)
{
    int *out_arr;
    size_t n_len = filter(array, len, &out_arr, even);
    for (size_t i = 0; i < n_len; i++)
        printf("%d\n", out_arr[i]);
    free(out_arr);
}
