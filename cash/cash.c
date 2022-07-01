#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int get_quarters(int cents);
int get_dimes(int cents);
int get_nickles(int cents);
int get_pennies(int cents);

int main(void)
{
    int cents = get_cents();

    int quarters = get_quarters(cents);
    cents = cents - quarters * 25;

    int dimes = get_dimes(cents);
    cents = cents - dimes * 10;

    int nickles = get_nickles(cents);
    cents = cents - nickles * 5;

    int pennies = get_pennies(cents);
    cents = cents - pennies * 1;

    int total = quarters + dimes + nickles + pennies;

    printf("%i\n", total);

}



int get_cents(void)
{
    int cents;
    do
    {
        cents = get_int("How many cents do you have? ");
    }
    while (cents < 0);

    return cents;
}

int get_quarters(int cents)
{
    cents = cents / 25;

    return cents;
}

int get_dimes(int cents)
{
    cents = cents / 10;

    return cents;
}

int get_nickles(int cents)
{
    cents = cents / 5;

    return cents;
}

int get_pennies(int cents)
{
    cents = cents / 1;

    return cents;
}