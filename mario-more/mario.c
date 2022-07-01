#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    int row;
    int column;
    int space;
//check the input
    do
    {
        height = get_int("How tall is the pyramid? ");
    }
    while (height < 1 || height > 8);
//counts the rows
    for (row = 0; row < height; row++)
    {
        //prints the spaces
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }
        //prints the #
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("  ");

        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");

    }
}