unsigned char rol(unsigned char value, unsigned char roll)
{
    return (value << roll) | (value >> ((sizeof(value) * 8) - value));
}
