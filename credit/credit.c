#include <cs50.h>
#include <stdio.h>


//4003600000000014


int main(void)
{
// prompt for input
    long ccnumber = get_long("Enter your number: ");
    long cccopy = ccnumber;
    long total = 0;
    long count = 0;
    long placeholder = 0;
    long length = 0;
// calculate checksum
    do
    {
        if (count % 2 != 0)
        {
            placeholder = 2 * (ccnumber % 10);
            if (placeholder > 9)
            {
                total += (placeholder % 10) + (placeholder / 10);
            }
            else
            {
                total += placeholder;
            }
        }
        else
        {
            total += ccnumber % 10;
        }
        count++;
        length++;
        ccnumber = ccnumber / 10;
    }
    while (ccnumber != 0);
// check for card length and starting digits

    if (total % 10 == 0 && length == 15 && (cccopy / 10000000000000 == 34 || cccopy / 10000000000000 == 37))
    {
        printf("AMEX\n");
    }
    else if (total % 10 == 0 && length == 16 && (cccopy / 100000000000000 == 51 || cccopy / 100000000000000 == 52
             || cccopy / 100000000000000 == 53 || cccopy / 100000000000000 == 54 || cccopy / 100000000000000 == 55))
    {
        printf("MASTERCARD\n");
    }
    else if (total % 10 == 0 && (length == 13 || length == 16) && (cccopy / 1000000000000 == 4 || cccopy / 1000000000000000 == 4))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}



// American Express numbers start with 34 or 37 == American Express uses 15-digit numbers
// MasterCard numbers start with 51, 52, 53, 54, or 55 -- MasterCard uses 16-digit numbers
// Visa numbers start with 4 -- Visa uses 13- and 16-digit numbers
// Print Amex, Mastercard, Visa, or Invalid


































