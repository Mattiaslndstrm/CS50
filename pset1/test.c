#include <cs50.h>
#include <stdio.h>
#include <math.h>

int sum_double(long long num);
int sum_num(long long num);
int validate(int num);

int main(void)
{
    printf("Number: ");
    long long number = get_long_long();
    // int length = floor(log10(llabs(number))) + 1;
    printf("%s", sum_num(number));

}

int sum_num(long long num) 
{   int sum = 0;
    while (num > 0) 
    {
        sum += num % 10;
        num /= 10;
        sum += sum_double(num);
        num /= 10;
    }
    return validate(sum);
}

int validate(int num) 
{
    return num % 10 == 0;
}

int sum_double(long long num)
{
    int result = 0;
    int dbl = ((num % 10) * 2);
    if (dbl > 9) 
    {
        while (dbl > 0)
        {
            result += dbl % 10;
            dbl /= 10;
        }
    }
    else 
    {
        result += dbl;
    }
    return result;
}