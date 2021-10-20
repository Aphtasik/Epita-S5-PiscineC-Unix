#include "heap_sort.h"

#include <stddef.h>

static void swap(int *array, size_t i, size_t j)
{
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

static void heapify_rec(int *array, size_t size, size_t i)
{
    size_t max = i;
    size_t left = 2 * i + 1;
    size_t right = 2 * i + 2;

    if (left < size && array[left] > array[max])
    {
        max = left;
    }
    if (right < size && array[right] > array[max])
    {
        max = right;
    }
    if (max != i)
    {
        swap(array, max, i);
        heapify_rec(array, size, max);
    }
}

void heapify(int *array, size_t size)
{
    if (array)
    {
        heapify_rec(array, size, 0);
    }
}

void heap_sort(int *array, size_t size)
{
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify_rec(array, size, i);
    }

    for (int i = size - 1; i > 0; i--)
    {
        swap(array, i, 0);
        heapify_rec(array, i, 0);
    }
}
