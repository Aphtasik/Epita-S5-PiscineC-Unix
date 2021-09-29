int int_sqrt(int n) 
{
    if (n < 0)
    {
        return -1;
    } 
    else if (n == 0 || n == 1)
    {
        return n;
    } 
    else
    {
        int root = 1;
        int i = 1;

        while (root <= n)
        {
            i++;
            root = i * i;
        }

        return i - 1;
    }
}
