#include <stdio.h>

int is_separator(int c)
{
    if (c == ' ' || c == '\n' || c == '\t')
    {
        return 1;
    }
    return 0;
}

int count_words(const char *file_in)
{
    int count = 0;
    FILE *f = fopen(file_in, "r");
    int c;
    int is_word = 0;
    while ((c = fgetc(f)) != EOF)
    {
        if (!is_separator(c) && is_word == 0)
        {
            is_word = 1;
            count++;
        }
        else if (is_separator(c) && is_word == 1)
        {
            is_word = 0;
        }
    }
    fclose(f);

    return count;
}
