#include "levenshtein.h"

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
    size_t ld;
    size_t od;
    size_t len_s1 = len(s1);
    size_t len_s2 = len(s2);
    size_t i = 0;
    size_t j = 0;

    size_t *distance = calloc(len_s1 + 1, sizeof(size_t));

    for (i = 1; i <= len_s1; i++)
    {
        distance[i] = i;
    }

    for (j = 1; j <= len_s2; j++)
    {
        distance[0] = j;
        ld = j - 1;
        for (i = 1, ld = j - 1; i <= len_s1; i++)
        {
            od = distance[i];
            size_t temp = MIN(distance[i] + 1, distance[i - 1] + 1);
            size_t is_eq = (s1[i - 1] == s2[j - 1]) ? 0 : 1;
            distance[i] = MIN(temp, ld + is_eq); 
            ld = od;
        }
    }
    return distance[len_s1];
}
