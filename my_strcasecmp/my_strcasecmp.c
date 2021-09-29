int my_strcasecmp(const char *s1, const char *s2)
{
    int i = 0;
    char c1;
    char c2;
    char c11;
    char c22;

    while (s1[i] != '\0' && s2[i] != '\0')
    {
        c1 = (s1[i] < 91 && s1[i] > 64) ? (s1[i] + 32) : (s1[i]);
        c2 = (s2[i] < 91 && s2[i] > 64) ? (s2[i] + 32) : (s2[i]);
        c11 = s1[i + 1];
        c22 = s2[i + 1]; 

        if ((c1 > c2) || ((c11 != '\0') && (c22 == '\0')))
        {
            return 1;
        }
        else if ((c1 < c2) || ((c11 == '\0') && (c22 != '\0')))
        {
            return -1;
        }
        i++;
    }
    return 0;
}
