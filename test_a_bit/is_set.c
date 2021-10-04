unsigned int is_set(unsigned int value, unsigned char n)
{
    unsigned short flag_set = 1 << n;
    return value & flag_set;
}
