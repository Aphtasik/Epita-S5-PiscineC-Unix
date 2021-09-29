char *my_itoa(int value, char *s)
{
    int s_i = 0;
    int reversedInt = 0;
    int remainder;


    if (value < 0)
    {
        value = - value;
        s[s_i] = '-';
        s_i++;
    }

    while (value != 0)
    {
        remainder = value % 10;
        reversedInt = reversedInt * 10 + remainder;
        value = value / 10;
    }

    while(reversedInt != 0)
    {
        remainder = reversedInt % 10;
        s[s_i] = remainder + '0';
        reversedInt = reversedInt / 10;
        s_i++;
    }
    s[s_i] = '\0';

    return s;
}
