#include "heap.h"

#include <stdlib.h>
#include <stddef.h>

static size_t is_in_heap(struct heap heap, size_t x)
{
   return (x < heap.size);
}

static int move_pointer_in_heap(struct heap heap, size_t x)
{
    if (!is_in_heap(heap, x))
    {
        heap.array = realloc(heap.array, heap.size * 2);
        heap.capacity = heap.size * 2;
    }
    return *(heap.array + x);

}

static void change_elt_in_heap(struct heap heap, size_t x, int c)
{
    if (!is_in_heap(heap, x))
    {
        heap.array = realloc(heap.array, heap.size * 2);
        heap.capacity = heap.size * 2;
    }
    *(heap.array + x) = c;
}

static void swap_pairs(struct heap heap, size_t x1, size_t x2)
{
    if (!(is_in_heap(heap, x1) || is_in_heap(heap, x2)))
    {
        heap.array = realloc(heap.array, heap.size * 2);
        heap.capacity = heap.size * 2;
    }
    size_t valTmp = move_pointer_in_heap(heap, x1);

    change_elt_in_heap(heap, x1, move_pointer_in_heap(heap, x2));

    change_elt_in_heap(heap, x2, valTmp);
}

void add(struct heap *heap, int value)
{
    heap->size += 1;
    change_elt_in_heap(*heap, heap->size - 1, value);
    size_t i = heap->size - 1;

    while (i > 1 && value < move_pointer_in_heap(*heap, i / 2))
    {
        swap_pairs(*heap, i, i / 2);
        i /= 2;
    }
}
