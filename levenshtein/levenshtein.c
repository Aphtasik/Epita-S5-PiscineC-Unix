#include <stdlib.h>
#include <stddef.h>
#define MIN(A, B) ((A) < (B) ? (A) : (B))

size_t len(const char *s)
{
    size_t len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

size_t levenshtein(const char *s1, const char *s2)
{
    if (len(s1) == 0)
    {
        return len(s2);
    }
    else if (len(s2) == 0)
    {
        return len(s1);
    }
    else if (s1[0] == s2[0])
    {
        return levenshtein(s1 + 1, s2 + 1);
    }
    else
    {
        size_t mini_btw_two = MIN(levenshtein(s1 + 1, s2), levenshtein(s1, s2 + 1));
        return 1 + MIN(mini_btw_two, levenshtein(s1 + 1, s2 + 1));
    }
}
