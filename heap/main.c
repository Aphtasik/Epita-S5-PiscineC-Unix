#include "heap.h"

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <assert.h>

int main(void)
{
    struct heap *h = create_heap();

    for (int j = 0; j < 10; j++)
    {
        add(h, j);
    }

    for (int j = 0; j < 10; j++)
    {
        printf("%d ", h->array[j]);
    }
    printf("\n");

    print_heap(h);
    delete_heap(h);
    return 0;

}
