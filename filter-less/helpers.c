#include "helpers.h"
#include "math.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    float buffer;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            image[i][j].rgbtBlue = round(buffer);
            image[i][j].rgbtGreen = round(buffer);
            image[i][j].rgbtRed = round(buffer);
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    float sepiaRed;
    float sepiaGreen;
    float sepiaBlue;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            sepiaRed = fmin(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue, 255.0);
            sepiaGreen = fmin(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue, 255.0);
            sepiaBlue = fmin(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue, 255.0);
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE buffer;
    float m = floor(width / 2.0);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (int) m; j++)
        {
            buffer = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = buffer;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    float mean, avg = 0.0, sumRed = 0.0, sumGreen = 0.0, sumBlue = 0.0;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            for (int k = i - 1; k < i + 2; k++)
            {
                for (int l = j - 1; l < j + 2; l++)
                {
                    if (k < 0)
                    {
                        k = 0;
                    }
                    if (k >= height)
                    {
                        break;
                    }
                    if (l < 0)
                    {
                        l = 0;
                    }
                    if (l >= width)
                    {
                        break;
                    }
                    sumRed += copy[k][l].rgbtRed;
                    sumGreen += copy[k][l].rgbtGreen;
                    sumBlue += copy[k][l].rgbtBlue;
                    avg++;
                }
            }
            image[i][j].rgbtRed = round(sumRed / avg);
            image[i][j].rgbtGreen = round(sumGreen / avg);
            image[i][j].rgbtBlue = round(sumBlue / avg);
            sumRed = 0.0;
            sumGreen = 0.0;
            sumBlue = 0.0;
            avg = 0.0;
        }
    }
    return;
}
