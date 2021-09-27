unsigned long fibo_iter(unsigned long n)
{
    unsigned long f1 = 0;
    unsigned long f2 = 1;
    unsigned long temp;

    for(int i = 0; i<n; i++)
    {
        temp = f1 + f2;
        f1 = f2;
        f2 = temp;
    }
    return f1;
}
