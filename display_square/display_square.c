#include <stdio.h>

void display_square(int width)
{
    if(width%2 == 0)
    {
        width++;
    }
    
    int i;
    int j;

    for(i = 0; i<width; i++)
    {
        putchar('*');
    }
    putchar('\n');

    for(i = 0; i<((width+1)/2)-2;i++)
    {
        putchar('*');
        for(j = 0; j<width-2;j++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }

    for(i = 0; i<width; i++)
    {
        putchar('*');
    }
    putchar('\n');
}
