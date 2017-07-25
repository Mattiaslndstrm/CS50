#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define AL 52
#define ARRAY_LENGTH 7314372
#define STRING_LENGTH 5

string crack(string hash, string salt);
char toChar(int num);
void generateArray(void);
char arr[ARRAY_LENGTH][STRING_LENGTH] = {0};

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        generateArray();
        string hash = argv[1];
        //https://stackoverflow.com/questions/4214314/get-a-substring-of-a-char
        char salt[3];
        memcpy(salt, &hash[0], 2);
        salt[2] = '\0';
        printf("%s\n", crack(hash, salt));
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
}

string crack(string hash, string salt)
{
    for (int x = 0; x < ARRAY_LENGTH; x++)
    {
        if (strcmp(crypt(arr[x], salt), hash) == 0)
        {
            return arr[x];
        }
    }
    return "apa";
}

void generateArray(void)
{
    for (int f = 0; f < AL; f++)
    {
        arr[f][0] = toChar(f);
        arr[f][1] = '\0';
        for (int g = 0; g < AL; g++)
        {   int second = g + AL + AL * f;
            arr[second][0] = toChar(f);
            arr[second][1] = toChar(g);
            arr[second][2] = '\0';
            for (int h = 0; h < AL; h++)
            {   int third = AL*(AL+1) + h + AL*g + AL*AL*f;
                arr[third][0] = toChar(f);
                arr[third][1] = toChar(g);
                arr[third][2] = toChar(h);
                arr[third][3] = '\0';

                for (int i = 0; i < AL; i++)
                {   int fourth = AL*(AL+1) + i + AL*h + AL*AL*g + AL*AL*AL*f;
                    arr[fourth][0] = toChar(f);
                    arr[fourth][1] = toChar(g);
                    arr[fourth][2] = toChar(h);
                    arr[fourth][3] = toChar(i);
                    arr[fourth][4] = '\0';
                }
            }
        }
    }
}

char toChar(int num)
{
    return (num < 26) ? (num + 65) : (num + 71);
}
