unsigned int is_set(unsigned int value, unsigned char n)
{
    return (value >> (n - 1)) % 2;
}
