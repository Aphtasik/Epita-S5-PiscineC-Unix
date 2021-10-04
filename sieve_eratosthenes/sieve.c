#include <stdio.h>

void sieve(int n)
{
    if (n >= 2)
    {
        int arr[1000] = { 0 };
        int i;

        for (i = 0; i < n - 1; i++)
        {
            arr[i] = 1;
        }

        for (i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                if ((j + 2) % (i + 2) == 0 && i != j)
                {
                    arr[j] = 0;
                }
            }
        }

        for (i = 0; i < n - 1; i++)
        {
            if (arr[i] == 1)
            {
                printf("%d\n", i + 2);
            }
        }
    }
}
