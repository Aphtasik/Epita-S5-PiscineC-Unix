#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "heap.h"

#define LEFT(A) (2 * A + 1)
#define RIGHT(A) (2 * A + 2)

static void print_number(size_t n)
{
    if (n / 10)
        print_number(n / 10);
    putchar(n % 10 + '0');
}

static void print_heap_rec(const struct heap *heap, size_t i)
{
    if (i >= heap->size)
        return;
    else
    {
        print_number(heap->array[i]);
        if (LEFT(i) < heap->size)
        {
            putchar(' ');
            print_heap_rec(heap, LEFT(i));
        }
        if (RIGHT(i) < heap->size)
        {
            putchar(' ');
            print_heap_rec(heap, RIGHT(i));
        }
    }
}

void print_heap(const struct heap *heap)
{
    if (heap && heap->array[0])
    {
        print_heap_rec(heap, 0);
        putchar('\n');
    }
}
