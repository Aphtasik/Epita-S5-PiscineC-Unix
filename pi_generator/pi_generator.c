double pi_generator_rec(double n, double res) 
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (1 + res / (res * 2 + 1) * pi_generator_rec(n - 1, res + 1));
    }
}

double pi_generator(int precision)
{
    double dprec = precision;
    return (2 * pi_generator_rec(dprec, 1));
}
