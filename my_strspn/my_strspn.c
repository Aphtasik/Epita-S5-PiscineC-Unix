#include <stddef.h>

size_t my_strspn(const char *s, const char *accept)
{
    size_t len = 0;

    if ((s == NULL) || (accept == NULL))
    {
        return len;
    }

    size_t i = 0;
    size_t j = 0;
    int isMatch = 1;

    while (isMatch && s[i] != '\0')
    {
        isMatch = 0;
        j = 0;
        while (accept[j] != s[i] && accept[j] != '\0')
        {
            j++;
        }

        if (accept[j] == s[i])
        {
            isMatch = 1;
            len++;
        }
        i++;
    }
    return len;
}
