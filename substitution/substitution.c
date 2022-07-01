#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int checkCl();
bool keyCheck();
int rotate(char c);

int main(int argc, string argv[])
{
    
// Check program was run with just one command-line argument

    int check = checkCl(argc);
    if (check >= 1)
    {
        return 1;
    }

// Checks key

    string key = argv[1];
    int check2 = keyCheck(key);
    if (check2 == 1)
    {
        return 1;
    }

// Gets plaintext

    string plaintext  = get_string("plaintext: ");
    printf("ciphertext: ");

// Rotate plaintext array variables

    for (int i = 0, len = strlen(plaintext); i <= len; i++)
    {
        if (isupper((plaintext[i])))
        {
            int c = rotate(plaintext[i]);
            printf("%c", toupper(argv[1][c]));
        }
        else if (islower((plaintext[i])))
        {
            int c = rotate(plaintext[i]);
            printf("%c", tolower(argv[1][c]));
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
        printf("Usage: ./substitution key\n");
        return 1;
    }
    return 0;
}

// Checks to make sure key is correct

bool keyCheck(string x)
{
    int count = 0;
    int len = strlen(x);

    for (int i = 0; i <= len; i++)
    {
        if (isalpha(x[i]) != 0)
        {
            count++;
        }

        char z = x[i];
        int counter = 0;

        for (int j = 0; j <= len; j++)
        {
            if (z == x[j])
            {
                counter++;
            }
            if (counter == 2)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    if (count != strlen(x) || count != 26)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else
    {
        return 0;
    }
}

// Rotates based on key

int rotate(char c)
{
    if (isupper(c))
    {
        char x = ((c - 'A') % 26);
        return x;
    }
    else
    {
        char x = (((c - 'a')) % 26);
        return x;
    }
}


