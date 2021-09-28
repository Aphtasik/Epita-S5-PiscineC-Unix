#include <stdio.h>

int main() 
{
    char letter;

    for (int i = 0; i < 25; i++) 
    {
        letter = i + 97;
        putchar(letter);
        putchar(' ');
    }
    putchar('z');
    putchar('\n');
    return 0;
}
