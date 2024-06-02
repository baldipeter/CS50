// Draw a pyramid shape from Mario

#include <cs50.h>
#include <stdio.h>

int get_height(void);
void spaces(int height1);
void hastag(int height2);

int main(void)
{
    // Ask for height (h)
    int pyramid = get_height();

    // Draw the piramid
    for (int h = pyramid; h > 0; h--)
    {
        spaces(h);
        hastag(pyramid - h + 1);
        printf("\n");
    }
}

// Ask for height (h)
int get_height(void)
{
    int height;
    do
    {
        height = get_int("Height of the pyramid? ");
    }
    while (height < 1 || height > 8);
    return height;
}

// Draw the piramid: h * space
void spaces(int height1)
{
    for (int j = (height1 - 1); j > 0; j--)
    {
        printf(" ");
    }
}

// Draw the piramid: (height - h + 1) * # followed by two spaces and then (height - h + 1) * #
void hastag(int height2)
{
    for (int i = 0; i < height2; i++)
    {
        printf("#");
    }
    printf("  ");
    for (int i = 0; i < height2; i++)
    {
        printf("#");
    }
}