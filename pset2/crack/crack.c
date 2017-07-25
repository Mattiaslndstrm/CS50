#define _XOPEN_SOURCE
#include <unistd.h>
// #include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define AL 52

void crack(void);
char toChar(int num);

// int main(int argc, string argv[])

char arr[7314372][5] = {0};
int main(void)
{
    // char arr[7314372][5];
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
    for (int a = 7314332; a < 7314372; a++)
    {
        printf("%i: %s\n", a, arr[a]);
    }

    // if (argc == 2)
    // {
    //     string hash = argv[1];
    //     printf("%s\n", crypt(hash, "abcd"));
    // }
    // else
    // {
    //     printf("Usage: ./crack hash\n");
    //     return 1;
    // }
}


char toChar(int num)
{
    return (num < 26) ? (num + 65) : (num + 71);
}

// void crack(void)
// {
//     char arr[500000][5];
//     for (char f = 97; f < 123; f++)
//     {
//         arr[f-97][0] = f;
//         arr[f-97][1] = '\0';
//         for (char g = 97; g < 123; g++)
//         {
//             arr[g - 97 + 25 + 25*(f-97)][0] = f;
//             arr[g - 97 + 25 + 25*(f-97)][1] = g;
//             arr[g - 97 + 25 + 25*(f-97)][2] = '\0';
//             for (char h = 97; h < 123; h++)
//             {
//                 arr[g - 97 + 25 + 25*(f-97) + 25*(g-97)][0] = f;
//                 arr[g - 97 + 25 + 25*(f-97) + 25*(g-97)][1] = g;
//                 arr[g - 97 + 25 + 25*(f-97) + 25*(g-97)][2] = h;
//                 arr[g - 97 + 25 + 25*(f-97) + 25*(g-97)][3] = '\0';

//                 for (char i = 97; i < 123; i++)
//                 {
//                     arr[g - 97 + 25 + 25*(f-97) + 25*(g-97) + 25*(h-97)][0] = f;
//                     arr[g - 97 + 25 + 25*(f-97) + 25*(g-97) + 25*(h-97)][1] = g;
//                     arr[g - 97 + 25 + 25*(f-97) + 25*(g-97) + 25*(h-97)][2] = h;
//                     arr[g - 97 + 25 + 25*(f-97) + 25*(g-97) + 25*(h-97)][3] = i;
//                     arr[g - 97 + 25 + 25*(f-97) + 25*(g-97) + 25*(h-97)][4] = '\0';
//                 }
//             }
//         }
//     }
//     for (int a = 0; a > 20000; a++)
//     {
//         printf("%s", arr[a]);
//     }
// }
