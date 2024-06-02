#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1); // if you use malloc you have to use free!!!
    if (t == NULL)
    {
        return 2;
    }

    // strcpy(t, s)
    for (int i = 0, n = strlen(s) + 1; i < n; i++)
    {
        t[i] = s[i];
    }

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("s: %s\n", s);
    printf("t: %s\n", t);

    free(t);

    return 0;
}