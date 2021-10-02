int palindrome(const char *s)
{
    if (!s)
    {
        return 0;
    }

    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }

    int left = 0;
    int right = len - 1;

    while (s[left] < 48 || (s[left] > 57 && s[left] < 65) || (s[left] > 90 && s[left] < 97) || s[left] > 122)
    {
        left++;
    }
    while (s[right] < 48 || (s[right] > 57 && s[right] < 65) || (s[right] > 90 && s[right] < 97) || s[right] > 122)
    {
        right--;
    }

    while (s[left] == s[right] && left < right)
    {
        left++;
        right--;
        while (s[left] < 48 || (s[left] > 57 && s[left] < 65) || (s[left] > 90 && s[left] < 97) || s[left] > 122)
        {
            left++;
        }
        while (s[right] < 48 || (s[right] > 57 && s[right] < 65) || (s[right] > 90 && s[right] < 97) || s[right] > 122)
        {
            right--;
        }
    }

    if (right <= left)
    {
        return 1;
    }
    return 0;
}
