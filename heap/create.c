#include <stddef.h>
#include <stdlib.h>

#include "heap.h"

struct heap *create_heap(void)
{
    struct heap *heap = malloc(sizeof(struct heap));

    heap->capacity = 8;
    heap->size = 0;

    heap->array = malloc(sizeof(int) * 8);

    return heap;
}
