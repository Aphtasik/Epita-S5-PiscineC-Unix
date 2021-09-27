#include<stdio.h>

double pi_generator_rec(int precision, int lim)
{
    if(precision == lim)
    {
        return (1+(lim/lim*2+1));
    }
    return 1+(precision/precision*2+1)*pi_generator_rec(precision+1, lim);
}

double pi_generator(int precision)
{
    return pi_generator_rec(1, precision);
}

int main()
{
    printf("%f\n",pi_generator(50));
}
