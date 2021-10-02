#include <stdio.h>
#include <stdlib.h>

void sieve(int n)
{
    if (n > 2)
    {
        int *marked = calloc(n + 1, sizeof(int));
        int i;
        int total_primes = 0;

        for (i = 2; i * i <= n; i++)
        {
            if (marked[i] == 0)
            {
                for (int j = i * i; j <= n; j += i)
                {
                    marked[j] = 1;
                }
            }
        }

        for (i = 3; i <= n; i++)
        {
            if (marked[i] == 0)
            {
                total_primes++;
            }
        }
        printf("%d\n", total_primes);
        free(marked);
    }
}
