#include <stdio.h>

unsigned char rol(unsigned char value, unsigned char roll)
{
    if ((roll &= sizeof(value) * 8 - 1) == 0)
        return value;
    return (value << roll) | (value >> (sizeof(value) * 8 - roll));
}