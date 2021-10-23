#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void csv(char *file_name)
{
    FILE *f = fopen(file_name, "r");
    if (!f)
    {
        exit(1);
    }

    char *line = NULL;
    size_t len;
    int read;
    char *str_toked = NULL;
    int max;
    int curr_arg;

    while ((read = getline(&line, &len, f)) != -1)
    {
        str_toked = strtok(line, ",");
        max = atoi(str_toked);

        while (1)
        {
            str_toked = strtok(NULL, ",");
            if (!str_toked)
                break;
            curr_arg = atoi(str_toked);
            if (curr_arg > max)
                max = curr_arg;
        }
        printf("%d\n", max);
    }

    fclose(f);
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 1;
    }

    csv(argv[1]);
    return 0;
}
