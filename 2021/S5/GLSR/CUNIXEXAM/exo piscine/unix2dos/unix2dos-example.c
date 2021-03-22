#include <stdio.h>

#include "unix2dos.h"

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        return 2;
    }
    return unix2dos(argv[1]);
}
