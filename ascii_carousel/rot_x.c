void rot_x(char *s, int x)
{
    if (s)
    {
        int i = 0;
        if (x <= -26)
        {
            x = -x;
            x = x % 26;
            x = -x;
        }

        while (s[i] != '\0')
        {
            if (s[i] <= 'Z' && s[i] >= 'A')
            {
                if (x > 0)
                {
                    s[i] = (s[i] + x - 65) % 26 + 65;
                }
                else
                {
                    s[i] = (s[i] + x - 65 + 26) % 26 + 65;
                }
            }
            else if (s[i] <= 'z' && s[i] >= 'a')
            {
                if (x > 0)
                {
                    s[i] = (s[i] + x - 97) % 26 + 97;
                }
                else
                {
                    s[i] = (s[i] + x - 97 + 26) % 26 + 97;
                }
            }
            i++;
        }
    }
}
