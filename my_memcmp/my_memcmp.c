#include "my_memcmp.h"

int my_memcmp(const void *s1, const void *s2, size_t num)
{
    const char *cs1 = s1;
    const char *cs2 = s2;

    for (size_t i = 0; i < num; i++)
    {
        if (*cs1 < *cs2)
            return -1;
        else if (*cs1 > *cs2)
            return 1;
        cs1++;
        cs2++;
    }

    if (!cs1 || !cs2)
        return 1;
    return 0;
}
