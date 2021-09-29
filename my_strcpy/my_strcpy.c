#include <stddef.h>

char *my_strcpy(char *dest, const char *source)
{
    size_t i;

    if (!dest && !source)
    {
        return NULL;
    }
    for (i = 0; src[i] != '\0'; i++)
    {
        dest[i] = src[i];
    }
    dest[i] = '\0';

    return dest;
}
