#include <stdio.h>

int first_ligne(void)
{
    for (int ligne = 0; ligne < 5; ligne++)
    {
        putchar(79);
        putchar(88);
    }
    putchar(10);
    return 0;
}

int seconde_ligne(void)
{
    for (int ligne = 0; ligne < 5; ligne++)
    {
        putchar(88);
        putchar(79);
    }
    putchar(10);
    return 0;
}

int main(void)
{
    for (int ligne = 0; ligne < 5; ligne++)
    {
        first_ligne();
        seconde_ligne();
    }

    return 0;
}