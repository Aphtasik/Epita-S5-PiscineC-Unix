int my_strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

char convertToDec(int n)
{
    if (n >= 0 && n <= 9)
    {
        return (n + '0');
    }
    return (n + 'A' - 10);
}

void reverseString(char *s)
{
    int len = my_strlen(s);

    for (int i = 0; i < len / 2; i++)
    {
        char temp = s[i];
        s[i] = s[len - i - 1];
        s[len - i - 1] = temp;
    }
}

char *my_itoa_base(int n, char *s, const char *base)
{
    int baseNb = my_strlen(base);
    int i = 0;

    while (n > 0)
    {
        s[i++] = convertToDec(n % baseNb);
        n/= baseNb;
    }
    s[i] = '\0';

    reverseString(s);
    return s;
}
