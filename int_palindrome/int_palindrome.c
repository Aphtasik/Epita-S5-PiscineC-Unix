int int_palindrome(int n)
{
    int nombre = n;
    int reverse = 0;
    int reste;

    while (n != 0)
    {
        reste = n % 10;
        reverse = reverse * 10 + reste;
        n /= 10;
    }

    return (reverse == nombre) ? 1 : 0;
}
