#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        return 1;
    }

    int n = *argv[2] - '0';
    char *str = argv[1];

    for (int i = 0; i < n; i++)
    {
        puts(str);
    }
    return 0;
}
