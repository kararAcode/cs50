#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

// PROTOTYPES

int countLetters(string text);
int countWords(string text);
int countSentences(string text);

int main(void)
{
    string text = get_string("Text: ");
    float letters = countLetters(text); // num of letters in text
    float words = countWords(text); // num of words in text
    float sentences = countSentences(text); // num of sentences in text

    double L = 100 * (letters / words); // avg letters per 100 words
    double S = 100 * (sentences / words); // avg sentences per 100 words

    float index = 0.0588 * L - 0.296 * S - 15.8;

    if (index >= 16)
    {
        printf("Grade 16+\n"); //
    }

    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else
    {
        printf("Grade %.0f\n", index);
    }

}

int countLetters(string text)
// counts number of letters
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            count++;
        }
    }
    return count;
}

int countWords(string text)
// counts number of words
{
    int count = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            count++;
        }
    }
    return count;
}

int countSentences(string text)
// counts number of sentences
{
    int count = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            count++;
        }
    }
    return count;
}