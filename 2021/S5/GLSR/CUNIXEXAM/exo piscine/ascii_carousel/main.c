#include <stdio.h>
#include <string.h>

#include "rot_x.h"

int main()
{
    char in[] = "Shhh ShE is ZZZzZ059%";

    printf("In: %s\n", in);
    rot_x(in, 13);
    printf("Out: %s\n", in);

    return 0;
}