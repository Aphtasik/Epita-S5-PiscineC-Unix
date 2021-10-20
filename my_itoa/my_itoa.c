void reverse_string(char s[], int len)
{
    int start = 0;
    int end = len - 1;
    char tmp;
    while (start < end)
    {
        tmp = *(s + start);
        *(s + start) = *(s + end);
        *(s + end) = tmp;
        start++;
        end--;
    }
}

char *my_itoa(int value, char *s)
{
    int s_i = 0;
    int remainder;
    int is_neg = 0;

    if (value < 0)
    {
        value = -value;
        is_neg = 1;
    }

    if (value == 0)
    {
        s[s_i++] = '0';
        s[s_i] = '\0';
        return s;
    }

    while (value != 0)
    {
        remainder = value % 10;
        s[s_i++] = remainder + '0';
        value = value / 10;
    }

    if (is_neg)
    {
        s[s_i++] = '-';
    }
    s[s_i] = '\0';

    reverse_string(s, s_i);
    return s;
}
