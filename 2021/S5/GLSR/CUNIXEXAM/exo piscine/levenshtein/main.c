#include <stdio.h>

#include "levenshtein.h"

int main(void)
{
    size_t res = levenshtein("","");
    printf("%zu\n", res);
    return 0;
}