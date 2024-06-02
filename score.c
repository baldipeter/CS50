#include <cs50.h>
#include <stdio.h>

float average(int array[]);

const int N = 3;

int main(void)
{
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("My score is %f\n", average(scores));
}

float average(int array[])
{
    float sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += array[i];
    }
    return sum / N;
}