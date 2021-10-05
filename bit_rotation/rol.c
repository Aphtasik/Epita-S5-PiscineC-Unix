unsigned char rol(unsigned char value, unsigned char roll)
{
    return (value << roll % (sizeof(value)) | (value >> ((sizeof(value) * 8) - roll % (sizeof(value) * 8)));
}
