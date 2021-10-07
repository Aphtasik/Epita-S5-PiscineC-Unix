#include "heap.h"

#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

static void swap_pairs(struct heap *heap, size_t x1, size_t x2)
{
    size_t val_tmp = heap->array[x1];
    heap->array[x1] = heap->array[x2];
    heap->array[x2] = val_tmp;
}

int pop(struct heap *heap)
{
    if (heap->size <= 0)
    {
        assert(0);
    }
    int firstVal = heap->array[0];
    swap_pairs(heap, 0, heap->size - 1);
    heap->array[heap->size - 1] = -1;
    heap->size--;

    int n = heap->size - 1;
    int ok = 0;
    int i = 0;
    int j = 0;
    while ((i <= n / 2) && ok == 0)
    {
        j = 2 * i;
        if ((j + 1 <= n) && (heap->array[j + 1] > heap->array[j]))
        {
            j++;
        }
        if (heap->array[i] < heap->array[j])
        {
            swap_pairs(heap, i, j);
            i = j;
        }
        else
        {
            ok = 1;
        }
    }
    return firstVal;
}
