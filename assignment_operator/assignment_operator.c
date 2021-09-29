void plus_equal(int *a, int *b)
{
    if (a && b)
    {
        *a = *a + *b;
    }
}

void minus_equal(int *a, int *b)
{
    if (a && b)
    {
        *a = *a - *b;
    }
}

void mult_equal(int *a, int *b)
{
    if (a && b)
    {
        *a = (*a) * (*b);
    }
}

int div_equal(int *a, int *b)
{
    int remainder = 0;
    if (a && b && b != 0)
    {
        remainder = (*a) % (*b);
        *a = (*a) / (*b);
        return remainder;
    }
    return 0;
}
