#include <cs50.h>
#include <stdio.h>

void printchar(char c, int num);
void printpyramid(int num);
int getheight(void);

int main(void) 
{   
    int height = getheight();
    printpyramid(height);
}

// Gets a valid height
int getheight(void) 
{
    int num = 0;
    while (num < 1 || num > 23)
    {
        printf("Height: ");
        num = get_int();
        if (num == 0) {
            break;
        }
    }
    return num;
}

// Source for printchar https://stackoverflow.com/questions/28465610/c-multiply-char-by-int
// Prints char c num number of times
void printchar(char c, int num)
    {
        for (int j = 0; j < num; j++)
        {
            putchar(c);
        }
    }


// Prints a pyramid of num height.
void printpyramid(int num)
{
    for (int i = 0; i < num; i++) 
    {   
        printchar(' ', num-i-1);
        printchar('#', i+1);
        printf("  ");
        printchar('#', i+1);
        printf("\n");
    }
}

