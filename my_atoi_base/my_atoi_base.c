#include "my_atoi_base.h"

int my_strlen(const char *str)
{
    int len = 0;
    while (str[len] != '\0')
    {
        len++;
    }
    return len;
}

int my_pow(int a, int b)
{
    int res = 1;
    for (int i = 0; i < b; i++)
    {
        res *= a;
    }
    return res;
}

int skipSpaces(const char *str)
{
    int i = 0;
    while (str[i] != '\0' && str[i] == ' ')
    {
        i++;
    }
    return i;
}

// 1 neg 2 positive 0 digit
int isNeg(const char *str)
{
    if (str[0] == '-')
    {
        return 1;
    }
    else if (str[0] == '+')
    {
        return 2;
    }
    return 0;
}

int findInStr(const char *s, char elt)
{
    int i = 0;
    while (s[i] != '\0' && s[i] != elt)
    {
        i++;
    }
    return (s[i] == elt) ? i : -1;
}

int my_atoi_base(const char *str, const char *base)
{
    if (*str == '\0')
    {
        return 0;
    }

    str += skipSpaces(str);
    int base_len = my_strlen(base);

    int base_i = 0;
    int str_i = 0;

    int neg = isNeg(str);

    int str_len = my_strlen(str);
    if (neg != 0)
    {
        str++;
        str_len -= 1;
    }

    int res = 0;

    for (str_i = 0; str_i < str_len; str_i++)
    {
        base_i = findInStr(base, str[str_i]);
        if (base_i == -1)
        {
            return 0;
        }
        res = res + base_i * my_pow(base_len, str_len - str_i - 1);
    }

    return (neg == 1) ? -res : res;
}
