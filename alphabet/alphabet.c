#include<stdio.h>

int main()
{
    for(int i = 0; i<26; i++)
    {
        putchar((char)(i+97));
        putchar(' ');
    }
    putchar('\n');
    return 0;
}
