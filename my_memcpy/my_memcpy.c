#include "my_memcpy.h"

void *my_memcpy(void *dest, const void *source, size_t num)
{
    char *cdest = dest;
    const char *csrc = source;

    for (size_t i = 0; i < num; i++)
    {
        cdest[i] = csrc[i];
    }
    return dest;
}
