#include <stdio.h>

void display_square(int width)
{
    int ROWS = 0;
    int COLS = 0;

    if (width % 2 == 0)
    {
        ROWS = (width + 2) / 2;
        COLS = width + 1;
    }
    else
    {
        ROWS = (width + 1) / 2;
        COLS = width;
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
            {
                putchar(42);
            }
            else
            {
                putchar(32);
            }
        }
        putchar(10);
    }
}