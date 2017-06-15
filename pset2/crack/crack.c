#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

string crack(string hash);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        string hash = argv[1];
        printf("%s\n", crypt(hash, "abcd"));
    }
    else 
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
}

string crack(string hash)
{   
    const char *arr[500000];
    for (int f = 0; f < 25; f++)
    {
        arr[f] = (string) (97 + f);
        for (int g = 0; g < 25; g++)
            string *twochar = strcat((string) 97 + f, (string) 97 + g);
            arr[g + 25 + 25*f]  = twochar;
        {
            for (int h = 0; h < 25; h++)
            {
                arr[h + 25*25]  = char {(char) 97 + f, (char) 97 + g, (char) 97 +h};
                //strcat((string) 97 + f, (string) 97 + g, (string) 97 + h)
                for (int i = 0; i < 25; i++)
                {
                    
                }
            }
        }
    }
}

int hej[] = {1}