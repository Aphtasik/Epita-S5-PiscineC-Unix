#include <stdio.h>

void hanoi_print(unsigned n, char d, char a, char i)
{
    if (n != 0)
    {
        hanoi_print(n - 1, d, i, a);
        putchar(d);
        putchar('-');
        putchar('>');
        putchar(a);
        putchar('\n');
        hanoi_print(n - 1, i, a, d);
    }
}

void hanoi(unsigned n)
{
    hanoi_print(n, '1', '3', '2');
}
