#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 0)
    {
        printf("Hello World!\n");
    }
    else
    {
        for (int i = 1; i < argc - 1; i++)
        {
            printf("Hello %s!\n", argv[i]);
        }
    }
    return 0;
}
