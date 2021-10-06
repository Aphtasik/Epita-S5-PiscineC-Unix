#include "heap.h"

#include <stdlib.h>
#include <stddef.h>
#include <err.h>

static void swap_pairs(struct heap *heap, size_t x1, size_t x2)
{
    size_t val_tmp = heap->array[x1];
    heap->array[x1] = heap->array[x2];
    heap->array[x2] = val_tmp;
}

void add(struct heap *heap, int value)
{
    heap->size += 1;
    if (heap->size >= heap->capacity)
    {
        heap->array = realloc(heap->array, heap->capacity * 2);
        heap->capacity = heap->capacity * 2;
    }
    heap->array[heap->size - 1] = value;
    size_t i = heap->size - 1;

    while (i > 0 && value > heap->array[i / 2])
    {
        swap_pairs(heap, i, i / 2);
        i /= 2;
    }
}
