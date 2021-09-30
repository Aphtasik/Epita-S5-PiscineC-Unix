#include <stddef.h>
char *my_strcpy(char *dest, const char *source)
{
    size_t i;

    if (!dest && !source)
    {
        return NULL;
    }
    for (i = 0; source[i] != '\0'; i++)
    {
        dest[i] = source[i];
    }
    dest[i] = '\0';

    return dest;
}
