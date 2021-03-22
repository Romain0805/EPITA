#include "str_revert.h"

int main(void)
{
    char foo[] = "fou";
    str_revert(foo);
    printf("%s\n", foo); // "uof"
}