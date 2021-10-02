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
