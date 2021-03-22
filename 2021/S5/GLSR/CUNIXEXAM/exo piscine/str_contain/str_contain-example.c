#include <stdio.h>

#include "str_contain.h"

int main(void)
{
    printf("%p\n", split("s|i|t|e", "|")); //1
    //printf("%u\n", str_contain("site", "it||"));//1
    //printf("%u\n", str_contain("site", "i|t"));//2
    //printf("%u\n", str_contain("God save the quimm", "z|e t"));//1
    return 0;
}
