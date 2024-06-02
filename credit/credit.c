// Checks if the credit card number is valid, and if it is, tells which company made it

#include <cs50.h>
#include <stdio.h>

int length(long l);
long valid_check(long m, int leng);
void company_check(long n, int lengt);

int main(void)
{
    // Get the card number
    long num;
    do
    {
        num = get_long("Number: ");
    }
    while (num < 1);

    // Check if valid
    int len = length(num);
    long valid_num = valid_check(num, len);

    // Check the company
    company_check(valid_num, len);
}

// Length of num
int length(long l)
{
    int a = 0;
    while (l > 0)
    {
        l /= 10;
        a++;
    }
    return a;
}

// Check if card number is valid; if valid returns card num, if not returns 0
long valid_check(long m, int leng)
{
    long valid = m;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 0; i < leng; i++)
    {
        if (i % 2 == 0)
        {
            sum1 += (m % 10);
        }
        else if (i % 2 == 1)
        {
            if (((m % 10) * 2 > 9))
            {
                sum2 += (((m % 10) * 2) % 10);
                sum2 += (((m % 10) * 2) / 10);
            }
            else
            {
                sum2 += ((m % 10) * 2);
            }
        }
        m /= 10;
    }
    if ((sum1 + sum2) % 10 == 0)
    {
        return valid;
    }
    else
    {
        valid = 0;
        return valid;
    }
}

// Get the first two number, then check the company
void company_check(long n, int lengt)
{
    while (n >= 100)
    {
        n /= 10;
    }
    if ((n == 34 || n == 37) && (lengt == 15))
    {
        printf("AMEX\n");
    }
    else if ((n > 50 && n < 56) && (lengt == 16))
    {
        printf("MASTERCARD\n");
    }
    else if ((n > 39 && n < 50) && (lengt == 13 || lengt == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}