int my_atoi(const char *str)
{
    if (!str)
    {
        return 0;
    }

    int i = 0;
    int isNeg = 0;
    while (str[i] == ' ')
    {
        i++;
    }

    if (str[i] < '0' || str[i] > '9')
    {
        if (str[i] == '-')
        {
            isNeg = 1;
        }
        else if (str[i] != '+')
        {
            return 0;
        }
        i++;
    }

    int res = 0;
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            return 0;
        }
        res = res * 10 + (str[i] - '0');
        i++;
    }

    return isNeg ? (-res) : res;
}
