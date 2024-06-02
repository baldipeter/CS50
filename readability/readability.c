#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letter(string t);
int count_words(string tx);
int count_sencences(string txt);
int calculate_index(int lt, int wo, int se);

int main(void)
{
    // Get the text from the user
    string text = get_string("Text: ");

    // Count the letters, words, and sentences
    int l = count_letter(text);
    int w = count_words(text);
    int s = count_sencences(text);

    // Calculate the index
    int index = calculate_index(l, w, s);

    // Output the Grade
    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letter(string t)
{
    int letters = 0;
    for (int i = 0, n = strlen(t); i < n; i++)
    {
        if ((t[i] >= 'a' && t[i] <= 'z') || (t[i] >= 'A' && t[i] <= 'Z'))
        {
            letters++;
        }
    }
    return letters;
}

int count_words(string tx)
{
    int words = 0;
    for (int i = 0, n = strlen(tx); i < n; i++)
    {
        if (tx[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}

int count_sencences(string txt)
{
    int snt = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (txt[i] == '.' || txt[i] == '!' || txt[i] == '?')
        {
            snt++;
        }
    }
    return snt;
}

int calculate_index(int lt, int wo, int se)
{
    float L = (float) lt / wo * 100;
    float S = (float) se / wo * 100;
    float ind = roundf(0.0588 * L - 0.296 * S - 15.8);
    int i = ind;
    return i;
}