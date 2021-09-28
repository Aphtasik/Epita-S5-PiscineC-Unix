int *add_int_ptr(int *a, int *b) 
{
    if (!a || !b) 
    {
        return a;
    }
    int c = *a + *b;
    return &c;
}
