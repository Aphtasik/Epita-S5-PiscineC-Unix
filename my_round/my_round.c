int my_round(float n)
{
    int neg = 0;
    if(n<0)
    {
        n = -n;
    }

    // if n - n rounded to inferior > 0.5
    int int_n = n;
    if(n-((float)int_n) > 0.5)
    {
        n = (float)int_n + 1;
    }

    return neg ? -n : n;
}
