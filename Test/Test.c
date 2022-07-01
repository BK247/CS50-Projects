#include <stdio.h>
#include <cs50.h>

bool valid_triangle(int a, int b, int c);

int main (void)
{


int x = get_int("Length of side 1:\n ");
int y = get_int("Length of side 2:\n ");
int z = get_int("Length of side 3:\n ");

bool a = valid_triangle(x, y, z);

if(a == true)
{
    printf("Valid Triangle\n");
}
else
{
printf("Invalid Triangle\n");
}
}


bool valid_triangle(int a, int b, int c)
{

if((a <= 0 || b <= 0 || c <= 0))
{
    return false;
}
if(a + b <= c || b + c <= a || c + a <= b)
{
    return false;
}
else
{
    return true;
}
}