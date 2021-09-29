void my_strlowcase(char *str)
{
    if (str)
    {
        int i = 0;
        while (str[i] != '\0')
        {
            if (str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
            i++;
        }
    }
}
