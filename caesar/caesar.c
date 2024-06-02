#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

string enrypt(int k, string txt);

int main(int argc, string argv[])
{
    // Got the argument?
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Is the argument a number?
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < 48 || argv[1][i] > 57)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Get plaintext
    string text = get_string("Plaintext:  ");

    // Get argv to be the KEY
    int key = 0;
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        key = key * 10;
        key += (argv[1][i] - 48);
    }
    key = key % 26;

    // Encrypt
    string cryptic = enrypt(key, text);

    // Print the result
    printf("ciphertext: %s\n", cryptic);
}

string enrypt(int k, string txt)
{
    string crypt = txt;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (!isalnum(txt[i]))
        {
            crypt[i] = txt[i];
        }
        else if ((islower(txt[i]) && (txt[i] + k) > 122) || (isupper(txt[i]) && (txt[i] + k) > 90))
        {
            crypt[i] = txt[i] + k - 26;
        }
        else
        {
            crypt[i] = txt[i] + k;
        }
    }
    return crypt;
}