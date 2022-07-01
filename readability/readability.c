#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

string getText();
int countLetters();
int countWords();
int countSentence();

int main(void)
{

//variables
    string text = getText();
    int letters = countLetters(text);
    int words = countWords(text);
    int sentence = countSentence(text);
    float L = ((float)letters / (float)words) * 100;
    float S = ((float)sentence / (float)words) * 100;
//calculation for grade level
    float index = ((0.0588 * L) - (0.296 * S)) - 15.8;
//determines grade
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", (int)round(index));
    }
}


//gets input
string getText()
{
    string text1 = get_string("Text: ");

    return text1;
}


//counts the letters
int countLetters(string text)
{
    int count = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isupper(text[i]))
        {
            count++;
        }
        else if (islower(text[i]))
        {
            count++;
        }
    }
    return count;
}

//counts how many words
int countWords(string text)
{
    int countWords = 1;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            countWords++;
        }
    }
    return countWords;
}

//counts how many sentences
int countSentence(string text)
{
    int countSentence = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '!' || text[i] == '.' || text[i] == '?')
        {
            countSentence++;
        }
    }
    return countSentence;
}