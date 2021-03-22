#include <stdio.h>

#include "palindrome.h"

int main(void)
{
    printf("\n");
    printf("%d\n\n", palindrome("r0xor")); // 0
    printf("%d\n\n", palindrome("kayak")); // 1
    printf("%d\n\n", palindrome("KaYaK")); // 1
    printf("%d\n\n", palindrome("Tu l'aS troP ete, Port-SaluT.")); // CASE1  1
    printf("%d\n\n", palindrome("Tu l'aS troP ete, port-SaluT.")); // CASE2  O
    printf("%d\n\n", palindrome(((void *)0))); // 0
    return 0;
}
