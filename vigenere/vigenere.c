#include "vigenere.h"

int isChar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        return 1;
    }
    return 0;
}

int getLen(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    return len;
}

char convertUpperPositive(char a, char b, int cypher)
{
    int upper_a = (a >= 'a' && a <= 'z') ? ((int)a - 32) : (int)a;
    int upper_b = (b >= 'a' && b <= 'z') ? ((int)b - 32) : (int)b;
    
    if (cypher == 1)
    {
        return (char)((upper_a + upper_b) % 26 + 65);
    }
    else if (upper_b - upper_a >= 0)
    {
        return (char)((upper_b - upper_a) % 26 + 65);
    }
    else
    {
        int diff = (upper_b - upper_a);
        return (char)((26 + diff) % 26 + 65);
    }
}

void cipher(const char *key, const char *msg, char *res)
{
    int key_i = 0;
    int msg_i = 0;
    int key_len = getLen(key);

    while (msg[msg_i] != '\0')
    {
        if (isChar(msg[msg_i]))
        {
            res[msg_i] = convertUpperPositive(key[key_i], msg[msg_i], 1);
            key_i = (key_i + 1) % key_len;
        }
        else
        {
            res[msg_i] = msg[msg_i];
        }
        msg_i++;
    }
    res[msg_i] = '\0';
}

void decipher(const char *key, const char *msg, char *res)
{
    int key_i = 0;
    int msg_i = 0;
    int key_len = getLen(key);

    while (msg[msg_i] != '\0')
    {
        if (isChar(msg[msg_i]))
        {
            res[msg_i] = convertUpperPositive(key[key_i], msg[msg_i], 0);
            key_i = (key_i + 1) % key_len;
        }
        else
        {
            res[msg_i] = msg[msg_i];
        }
        msg_i++;
    }
    res[msg_i] = '\0';

}
