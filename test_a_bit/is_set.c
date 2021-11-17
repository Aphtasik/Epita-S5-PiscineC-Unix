unsigned int is_set(unsigned int value, unsigned char n)
{
    return (n) & (1<<(value));
}
