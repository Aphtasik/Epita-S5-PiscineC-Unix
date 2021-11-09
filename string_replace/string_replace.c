#include "string_replace.h"

#include <stdlib.h>
#include <stdio.h>

int len(const char *str)
{
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int countc(const char *str, int len, char c)
{
    int count = 0;

    for (int i = 0; i < len; i++)
    {
        if (str[i] == c)
        {
            count++;
        }
    }
    return count;
}

char *string_replace(char c, const char *str, const char *pattern)
{
    if (!str)
        return NULL;
    if (!pattern)
        pattern = "";

    int len_str = len(str);
    int len_pattern = len(pattern);
    int count = countc(str, len_str, c);
    int new_i = 0;

    char *new = malloc(sizeof(char) * (len_str - count + (count * len_pattern + 1)));

    for (int i = 0; i < len_str; i++)
    {
        if (str[i] == c)
        {
            for (int j = 0; j < len_pattern && pattern; j++)
            {
                new[new_i] = pattern[j];
                new_i++;
            }
        }
        else
        {
            new[new_i] = str[i];
            new_i++;
        }
    }

    new[new_i] = '\0';
    return new;
}
