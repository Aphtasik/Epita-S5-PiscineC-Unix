#include <stdlib.h>
#include <stdio.h>
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
    size_t len_s1 = len(s1);
    size_t len_s2 = len(s2);
    size_t i = 0;
    size_t j = 0;
    size_t sub_cost = 0;

    size_t **distance = malloc(sizeof(size_t) * len_s1);
    for (i = 0; i < len_s1; i++)
    {
        size_t *cols = calloc(len_s2, sizeof(size_t));
        distance[i] = cols;
    }

    for (i = 1; i < len_s1; i++)
    {
        distance[i][0] = i;
    }

    for (i = 1; i < len_s2; i++)
    {
        distance[0][j] = j;
    }

    for (j = 1; j < len_s2; j++)
    {
        for (i = 1; i < len_s1; i++)
        {
            if (s1[i] == s2[j])
            {
                sub_cost = 0;
            }
            else
            {
                sub_cost = 1;
            }
            size_t min =MIN(distance[i - 1][j] + 1, distance[i][j - 1] + 1);
            distance[i][j] =MIN(min, distance[i - 1][j - 1] + sub_cost);
        }
    }
    return distance[len_s1][len_s2];
}

int main()
{
    printf("%ld\n", levenshtein("doom", "tools"));
}
