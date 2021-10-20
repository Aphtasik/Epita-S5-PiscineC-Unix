unsigned char rol(unsigned char value, unsigned char roll)
{
    return (value << (roll % 8)) | (value >> (8 - roll % 8));
}
