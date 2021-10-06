#include <stdio.h>

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned short flag_set = 1 << n;
    return value & flag_set;
}

int main()
{
    printf("%d\n", is_set(24, 4));
    printf("%d\n", is_set(24, 3));
    return 0;
}
