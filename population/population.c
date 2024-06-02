#include <cs50.h>
#include <stdio.h>

int get_start(void);
int get_end(int start);
int calculate_years(int start, int end);
int main(void)
{
    // TODO: Prompt for start size
    int start_size = get_start();

    // TODO: Prompt for end size
    int end_size = get_end(start_size);

    // TODO: Calculate number of years until we reach threshold
    int years = calculate_years(start_size, end_size);

    // TODO: Print number of years
    printf("Years: %i\n", years);
}

int get_start(void)
{
    int start;
    do
    {
        start = get_int("Start size: ");
    }
    while (start < 9);
    return start;
}

int get_end(int start)
{
    int end;
    do
    {
        end = get_int("End size: ");
    }
    while (end < start);
    return end;
}

int calculate_years(int start, int end)
{
    int year = 0;
    while (start < end)
    {
        start = start + (start / 3) - (start / 4);
        year++;
    }
    return year;
}