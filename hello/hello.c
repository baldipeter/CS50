#include <cs50.h> //clang -o hello hello.c -lcs50
#include <stdio.h>

int main(void)
{
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}