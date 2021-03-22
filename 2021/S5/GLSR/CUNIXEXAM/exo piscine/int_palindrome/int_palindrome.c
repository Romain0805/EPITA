#include <stdio.h>

int int_palindrome(int n)
{
    int reverse_num = 0;
    int remainder = 0;
    int temp = n;

    while (temp != 0)
    {
        remainder = temp % 10;
        reverse_num = reverse_num * 10 + remainder;
        temp /= 10;
    }

    if (reverse_num == n)
        return 1;
    return 0;
}
