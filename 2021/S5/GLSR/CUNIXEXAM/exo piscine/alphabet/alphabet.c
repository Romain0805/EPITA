#include <stdio.h>

void puts_alphabete1()
{
    putchar(97);
    int i = 98;
    while (i < 123)
    {
        putchar(32);
        putchar(i);
        ++i;
    }
}
int main(void)
{
    puts_alphabete1();
    return 0;
}