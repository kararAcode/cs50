#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>

//  PROTOTYPES
int count(string text, char character);
int validate_key(string key);

int main(int argc, string argv[])
{
    string key = argv[1];
    if (argc != 2) // check if you have given one arg(key)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    else if (strlen(key) != 26) // check if len of key is valid
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    else if (validate_key(key) == 1) // checks if key is valid
    {
        printf("Please Enter a valid key!\n");
        return 1;
    }

    else // ciphers text if no error occurs
    {
        string plain_text = get_string("plaintext: ");
        printf("ciphertext: ");

        int plain_txt_len = strlen(plain_text);
        for (int i = 0; i < plain_txt_len; i++)
        {
            char x = plain_text[i];
            if (!isalpha(x)) // checks if char is not an alpha
            {
                printf("%c", x);
            }

            else
            {
                // logic for case insensitivity
                if (isupper(x))
                {
                    char cipher_letter = toupper(key[(int) x - 65]);
                    printf("%c", cipher_letter);
                }

                else
                {
                    char cipher_letter = tolower(key[(int) x - 97]);
                    printf("%c", cipher_letter);
                }
            }
        }
        printf("\n");
    }

}

int validate_key(string key)
{
    // checks if key is alpha and does not have any repeating chars
    int key_len = strlen(key);
    for (int i = 0; i < key_len; i++)
    {
        int occ = count(key, key[i]);
        if (!isalpha(key[i]) || occ > 1)
        {
            return 1;
        }



    }

    return 0;
}

// counts occurences of a char in string
int count(string text, char character)
{
    int occ = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == character)
        {
            occ++;
        }
    }
    return occ;
}