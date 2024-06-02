// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 3300;

// Hash table
node *table[N];

// Size counter
unsigned int d_size = 0;
// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    unsigned int h = hash(word);
    if (table[h] == NULL)
    {
        return false;
    }
    node *cursor = table[h];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    int k = (toupper(word[0])) * (toupper(word[0]) - 'A'), sum = k;
    for (int i = 1, n = strlen(word); i < n; i++)
    {
        if (word[i] != '\'')
        {
            sum += (k + toupper(word[i]));
        }
        else if (word[i] == '\'')
        {
            return i;
        }
    }
    return sum % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char words[LENGTH + 1];
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }
    FILE *d = fopen(dictionary, "r");
    if (d == NULL)
    {
        printf("could not open %s\n", dictionary);
        return false;
    }

    while (fscanf(d, "%s", words) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        strcpy(n->word, words);
        unsigned int h = hash(n->word);
        n->next = table[h];
        table[h] = n;
        size();
    }
    // printf("Size is: %i\n", d_size);
    fclose(d);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return d_size++;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        node *cursor = NULL;
        node *tmp = NULL;
        if (table[i] != NULL)
        {
            cursor = table[i];
            tmp = cursor;
            while (cursor != NULL)
            {
                cursor = cursor->next;
                free(tmp);
                tmp = cursor;
            }
        }
        if (i == (N - 1))
        {
            return true;
        }
    }
    return false;
}
