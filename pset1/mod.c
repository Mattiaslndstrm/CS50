#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void) 
{
    printf("Number1: ");
    long long num1 = get_long_long();
    while (num1 > 1) 
    {
        int mjau = num1 % 10;
        num1 /= 100;
        printf("%i\n", mjau);
    }
}