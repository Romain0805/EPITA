#include "rot_x.h"

void alphabet(char *s, int x)
{
    char alpha1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char alpha2[] = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";

    for (int i = 0; *s == alpha1[i] || *s == alpha2[i]; i++)
    {
        if (*s == alpha1[i])
        {
            *s == alpha1[i + x];
        }
        if (*s == alpha2[i])
        {
            /* code */
        }
        
        
    }
    
}

void rot_x(char *s, int x)
{
    if (!s || x > 26 || x < -26)
        return;
        
    //check caractere

    //
}