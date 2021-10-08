#include "check_alphabet.h"

int check_alphabet(const char *str, const char *alphabet)
{
    if (!alphabet || alphabet[0] == '\0')
    {
        return 1;
    }

    int bool_list[255];
    int i = 0;

    for (i = 0; i < 256; i++)
    {
        bool_list[i] = 0;
    }

    i = 0;
    while (str[i] != '\0')
    {
        if (bool_list[str[i] + 0] == 0)
        {
            bool_list[str[i] + 0] = 1;
        }
        i++;
    }

    i = 0;
    while (alphabet[i] != '\0')
    {
        if (bool_list[alphabet[i] + 0] == 0)
        {
            return 0;
        }
        i++;
    }
    return 1;
}
