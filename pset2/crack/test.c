#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void) 
{
    char *arr[10000];
    for (char i = 97; i < 123; i ++)
    {
        for (char f = 97; f < 123; f++)
        {   
            char *g = &i;
            char *h = &f;
            string gris = strcat(g, h);
            strcpy(arr[(i-97)+(25*(i-97))], gris);
            //(i-97)+(25*(i-97))
            // arr[i-97+25*i]
            // arr[i-97+25*i]

        }
    }
    for (int j = 0; j < 26; j++)
    {
        printf("%s", arr[j]);
    }
}

