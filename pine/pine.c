int pine(unsigned n)
{
    int trunk = n/2;
    int max_half = (n-1); // tronc pas compris
    int i;
    int j;

    // tronc
    for(i = 0; i<n; i++)
    {
        for(j=(n-1)-i;j>0;j--)
        {
            putchar(' ');
        }
        for(j = 0; j<2*i+1;j++)
        {
            putchar('*');
        }
        putchar('\n');
        max_half--;
    }

    // pied
    for(i = 0; i<n/2;i++)
    {
        for(j = 0; j<n-1; j++)
        {
            putchar(' ');
        }
        putchar('*');
        putchar('\n');
    }

    if(n<3)
    {
        return 1;
    }
    return 0;
}
