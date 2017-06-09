#include <cs50.h>
#include <stdio.h>
#include <math.h>

int sum_double(long long num);
int luhn_algorithm(long long num);
string card_type(long long num, int len);
int validate(int num);

int main(void)
{
    printf("Number: ");
    long long number = get_long_long();
    int length = floor(log10(llabs(number))) + 1;
    // Source for length: https://stackoverflow.com/questions/3068397/finding-the-length-of-an-integer-in-c
    printf("%s", card_type(number, length));

}

// Checking num according to Luhn’s algorithm
// Inspiration for luhn_algorithm was found on https://stackoverflow.com/questions/8671845/iterating-through-digits-in-integer-in-c
int luhn_algorithm(long long num) 
{   int sum = 0;
    while (num > 0) 
    {
        sum += num % 10;
        num /= 10;
        sum += sum_double(num);
        num /= 10;
    }
    return sum % 10 == 0;
}

// Returns 2*num or if 2*num > 9: the digit sum of 2*num

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


// Returns a string with cardtype or "INVALID\n"
string card_type(long long num, int len) 
{
    if (luhn_algorithm(num))
    {
        int start = num / pow(10, len-2);
        if (len == 15 && (start == 34 || start == 37)) 
        {
            return "AMEX\n";
        }
        else if ((len == 13 || len == 16) && start / 10 == 4)
        {
            return "VISA\n";
        }
        else if (len == 16 && (start > 50 && start < 56))
        {
            return "MASTERCARD\n";
        }
        else
        {
            return "INVALID\n";
        }

    }

    else 
    {
        return "INVALID\n";
    }

}