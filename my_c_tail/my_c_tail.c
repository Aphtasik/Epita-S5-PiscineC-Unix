#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

size_t count_backslash(char *str)
{
    size_t count = 0;
    size_t i = 0;

    while (str[i])
    {
        if (str[i] == '\n')
            count++;
        i++;
    }
    return count;
}

void stdintail(unsigned int n)
{
    if (n <= 0)
        return;

    // Create buffer
    char str[4096] = { 0 };
    if (read(0, str, 4095) == -1)
        return;

    // Vars
    char **lines = malloc(sizeof(char *) * 128);
    char *one = calloc(1024, sizeof(char));
    size_t lines_i = 0;
    size_t one_i = 0;
    size_t i = 0;

    // Fill lines
    while (str[i])
    {
        if (str[i] == '\n')
        {
            one[one_i++] = '\n';
            one[one_i] = '\0';
            lines[lines_i] = one;
            one = calloc(1024, sizeof(char));
            one_i = 0;
            lines_i++;
            i++;
            continue;
        }
        one[one_i] = str[i];
        one_i++;
        i++;
    }
    if (one[0] != '\0')
        lines[lines_i++] = one;

    // Print lines
    size_t print = lines_i - (size_t)n - 1;
    size_t p;
    for (p = 0; p < lines_i; p++)
    {
        if (p > print)
            write(1, lines[p], 1024);
    }

    // Free all
    for (p = 0; p < lines_i; p++)
    {
        free(lines[p]);
    }
    free(lines);
}
