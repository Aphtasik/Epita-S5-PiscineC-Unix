#include <stdlib.h>
#include <unistd.h>

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
                    s[i] = (s[i] + x - 65) % 26 + 65;
                else
                    s[i] = (s[i] + x - 65 + 26) % 26 + 65;
            }
            else if (s[i] <= 'z' && s[i] >= 'a')
            {
                if (x > 0)
                    s[i] = (s[i] + x - 97) % 26 + 97;
                else
                    s[i] = (s[i] + x - 97 + 26) % 26 + 97;
            }
            else if (s[i] <= '0' && s[i] >= '9')
            {
                if (x > 0)
                    s[i] = (s[i] + x - '0') % 26 + 65;
                else
                    s[i] = (s[i] + x - '0' + 26) % 26 + 65;
            }
            i++;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        return 0;

    int x = atoi(argv[1]);
    char str[2048] =  { 0 };
    size_t nread = read(0, str, 2048);

    rot_x(str, x);

    write(1, str, nread);

    return 1;
}
