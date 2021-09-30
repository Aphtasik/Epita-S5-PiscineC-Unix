#include "my_strstr.h"

int my_strstr(const char *haystack, const char *needle)
{
    int first_match = 0;
    int i = 0;
    int j = 0;

    while (haystack[i] != '\0')
    {
        if (haystack[i] == needle[first_match])
        {
            j = i;
            while (haystack[j] != '\0' && needle[first_match] != '\0')
            {
                if ()
            }
        }
    }
}
