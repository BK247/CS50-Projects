#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

int checkCl();
bool only_digits();
char rotate(char c, int n);

int main(int argc, string argv[])
{
    // Check program was run with just one command-line argument

    int check = checkCl(argc);
    if (check >= 1)
    {
        return 1;
    }

    // Makes sure array variables in argv[1] are digits

    int digits = only_digits(argv[1]);
    if (digits == 1)
    {
        return 1;
    }
    // Converts argv[1] from a string to int

    int pt = atoi(argv[1]);

    // Gets plaintext

    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    // Rotate plaintext array variables

    for (int i = 0, len = strlen(plaintext); i <= len; i++)
    {
        if (isupper((plaintext[i])))
        {
            char c = rotate(plaintext[i], pt);
            printf("%c", c);
        }
        else if (islower((plaintext[i])))
        {
            char c = rotate(plaintext[i], pt);
            printf("%c", c);
        }
        else if (isspace(plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
        else if isgraph((plaintext[i]))
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}




// Checks the key

int checkCl(x)
{
    if (x > 2 || x < 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    return 0;
}

// Checks to make sure key is only digits

bool only_digits(string x)
{
    int count = 0;
    for (int i = 0, len = strlen(x); i <= len; i++)
    {
        if (isdigit(x[i]))
        {
            count++;
        }
    }

    if (count != strlen(x))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// Rotates based on key

char rotate(char c, int n)
{
    if (isupper(c))
    {
        char x = (((c - 'A') + n) % 26) + 'A';
        return x;
    }
    else
    {
        char x = (((c - 'a') + n) % 26) + 'a';
        return x;
    }
}















