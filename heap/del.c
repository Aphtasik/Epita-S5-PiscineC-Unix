#include "heap.h"

#include <stdlib.h>

void delete_heap(struct heap *heap)
{
    free(heap->array);
    free(heap);
}
