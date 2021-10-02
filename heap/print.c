#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

void print_heap_rec(const struct heap *heap, size_t i)
{
    if (i > heap->size)
    {
        return;
    }
    putchar(heap->array[i]);
    putchar(' ');
    print_heap_rec(heap, 2 * i + 1);
    print_heap_rec(heap, 2 * i + 2);
}

void print_heap(const struct heap *heap)
{
    print_heap_rec(heap, 0);
    putchar('\n');
}
