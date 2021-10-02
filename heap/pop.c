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

void ResetEltInHeap(struct heap heap, size_t x)
{
    if (!IsInHeap(heap, x))
    {
        heap.array = realloc(heap.array, heap.size * 2);
        heap.capacity = heap.size * 2;
    }
    ChangeEltInHeap(heap, x, -1);
}

int pop(struct heap *heap)
{
    int firstVal = MovePointerInHeap(*heap, 1);
    SwapPairs(*heap, 1, heap->size - 1);
    ResetEltInHeap(*heap, heap->size - 1);
    heap->size--;

    int n = heap->size-1;
    int ok = 0;
    int i = 1;
    int j = 0;
    while((i <= n/2) && ok == 0)
    {
        j = 2*i;
        if((j+1 <= n) && (MovePointerInHeap(*heap, j+1) < MovePointerInHeap(*heap, j)))
        {
            j++;
        }
        if(MovePointerInHeap(*heap, i) > MovePointerInHeap(*heap, j))
        {
            SwapPairs(*heap, i, j);
            i=j;
        }
        else
        {
            ok = 1;
        }
    }
    return firstVal;
}
