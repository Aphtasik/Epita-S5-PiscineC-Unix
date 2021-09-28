#include <stdlib.h>

int *my_calloc(size_t size, int init) 
{
    if (size == 0) 
    {
        return NULL;
    }

    int *call = malloc(sizeof(int) * size);
    if (!call) 
    {
        return NULL;
    }

    for (int i = 0; i < size; i++) 
    {
        call[i] = init;
    }

    return call;
}
