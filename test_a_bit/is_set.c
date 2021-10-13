int my_pow(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    else if (b == 0)
    {
        return 1;
    }
    else if (b % 2 == 0)
    {
        return my_pow(a, b / 2) * my_pow(a, b / 2);
    }
    else
    {
        return my_pow(a, b / 2) * my_pow(a, b / 2) * a;
    }
}

unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned short flag_set = 1 << (n - 1);
    return (value & flag_set) == (my_pow(2, n - 1));
}
