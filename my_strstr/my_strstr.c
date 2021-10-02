int compareString(const char *haystack, const char *needle)
{
    while (*haystack && *needle)
    {
        if (*haystack != *needle)
        {
            return 0;
        }
        haystack++;
        needle++;
    }
    return (*needle == '\0');
}

int my_strstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
    {
        return 0;
    }

    int i = 0;

    while (*haystack != '\0')
    {
        if (*haystack == *needle)
        {
            if (compareString(haystack, needle))
            {
                return i;
            }
        }
        haystack++;
        i++;
    }
    return -1;
}
