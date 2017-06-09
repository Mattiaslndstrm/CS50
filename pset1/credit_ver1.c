#include <cs50.h>
#include <stdio.h>
#include <math.h>

int sum_double(int num);
int sum_num(long long num, int len);
int create_array(long long num, int length);


int main(void)
{
    printf("Number: ");
    long long number = get_long_long();
    int length = floor(log10(llabs(number))) + 1;
    int hej = sum_num(number, length);
    printf("%i", hej);
}

int sum_num(long long num, int len)
{
    int sum = 0;
    char arr[len+1];
    snprintf(arr, len +1, "%lld", num);
    for (int i = len-1; i < 0; i--)
    {
        if ((len - 1) % 2 == 0) 
        {
            if (i % 2 == 0) 
            {
                sum += arr[i];
            }
            else
            {
            sum += sum_double(arr[i]);   
            }
        }
        else 
        {
            if ((len - 1) % 2 == 0) 
            {   
                if (i % 2 != 0) 
                {
                sum += arr[i];
                }

                else
                {
                    sum += sum_double(arr[i]);   
                }
        }
        }
    }
    return (sum);
}




// int create_array(long long num, int length) 
// {
//     char arr[length];
//     snprintf(arr, length, "%lld", num);
//     return arr;
// }

int sum_double(int num)
{   
    int sum = 0;
    if (num * 2 > 9) 
    {
        char ten[3];
        snprintf(ten, 3, "%i", num*2);
        for (int j = 0; j < 2; j++) 
        {
            sum += ten[j];
        }
    }
    else 
    {
        sum += (num *2);
    }
    return (sum);
}