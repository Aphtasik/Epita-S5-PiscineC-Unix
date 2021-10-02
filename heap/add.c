#include "heap.h"

#include <stdlib.h>
#include <stddef.h>

size_t IsInHeap(struct heap heap, size_t x)
{
   return(x < heap.size);
}

int MovePointerInHeap(struct heap heap, size_t x)
{
    if (!IsInHeap(heap, x))
    {
        heap.array = realloc(heap.array, heap.size * 2);
        heap.capacity = heap.size * 2;
    }
    return *(heap.array + x);

}

void ChangeEltInHeap(struct heap heap, size_t x, int c)
{
    if (!IsInHeap(heap, x))
    {
        heap.array = realloc(heap.array, heap.size * 2);
        heap.capacity = heap.size * 2;
    }
    *(heap.array + x) = c;
}

void SwapPairs(struct heap heap, size_t x1, size_t x2)
{
    if (!(IsInHeap(heap, x1) || IsInHeap(heap, x2)))
    {
        heap.array = realloc(heap.array, heap.size * 2);
        heap.capacity = heap.size * 2;
    }
    size_t valTmp = MovePointerInHeap(heap, x1);

    ChangeEltInHeap(heap, x1, MovePointerInHeap(heap, x2));

    ChangeEltInHeap(heap, x2, valTmp);
}

void add(struct heap *heap, int value)
{
    heap->size+=1;
    ChangeEltInHeap(*heap, heap->size-1, value);
    size_t i = heap->size-1;

    while(i>1 && value < MovePointerInHeap(*heap, i/2))
    {
        SwapPairs(*heap, i, i/2);
        i/=2;
    }
}
