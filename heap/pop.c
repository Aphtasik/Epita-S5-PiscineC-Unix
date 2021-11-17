#include <assert.h>
#include <stddef.h>
#include <stdlib.h>

#include "heap.h"

static void swap_pairs(struct heap *heap, size_t x1, size_t x2)
{
    size_t val_tmp = heap->array[x1];
    heap->array[x1] = heap->array[x2];
    heap->array[x2] = val_tmp;
}

void heapify(struct heap *h, size_t i)
{
    size_t l = 2 * 1 + 1;
    size_t r = 2 * i + 2;
    size_t greatest = i;
    if (l < h->size && h->array[l] > h->array[i])
        greatest = l;
    if (r < h->size && h->array[r] > h->array[greatest])
        greatest = r;
    if (greatest != i)
    {
        swap_pairs(h, i, greatest);
        heapify(h, greatest);
    }
}
int pop(struct heap *heap)
{
    if (heap->size <= 0)
        assert(0);
    if (heap->size == 1)
    {
        heap->size--;
        return heap->array[0];
    }

    int max = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    heap->size--;
    heapify(heap, 0);
    return max;
}
