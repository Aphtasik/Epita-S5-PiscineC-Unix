void str_revert(char str[])
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }

    char reversed[len];
    int i;
    for (i = 0; i < len; i++)
    {
        reversed[i] = str[len - 1 - i];
    }

    for (i = 0; i < len; i++)
    {
        str[i] = reversed[i];
    }
}
