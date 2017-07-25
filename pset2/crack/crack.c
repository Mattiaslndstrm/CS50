#define _XOPEN_SOURCE
#include <unistd.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void crack(void);

// int main(int argc, string argv[])
int main(void)
{
    unsigned char arr[7314371][5];
    for (unsigned char f = 0; f < 52; f++)
    {
        arr[f][0] = (f < 26) ? (f + 65) : (f + 71);
        arr[f][1] = '\0';
        for (unsigned char g = 0; g < 52; g++)
        {
            arr[g + 52 + 52 * f][0] = (f < 26) ? (f + 65) : (f + 71);
            arr[g + 52 + 52 * f][1] = (g < 26) ? (g + 65) : (g + 71);
            arr[g + 52 + 52 * f][2] = '\0';
            for (unsigned char h = 0; h < 52; h++)
            {
                arr[52*53 + h + 52*g + 52*52*f][0] = (f < 26) ? (f + 65) : (f + 71);
                arr[52*53 + h + 52*g + 52*52*f][1] = (g < 26) ? (g + 65) : (g + 71);
                arr[52*53 + h + 52*g + 52*52*f][2] = (h < 26) ? (h + 65) : (h + 71);
                arr[52*53 + h + 52*g + 52*52*f][3] = '\0';
                // printf("f = %c, g = %c, h = %c, arr = %i\n", f, g, h,h - 97) + 26*27 + ((f -97)*(26^2 +1)) + (g - 97)*(26+1));

                for (unsigned char i = 0; i < 52; i++)
                {
                    arr[52*53 + i + 52*h + 52*52*g + 52*52*52*f][0] = (f < 26) ? (f + 65) : (f + 71);
                    arr[52*53 + i + 52*h + 52*52*g + 52*52*52*f][1] = (g < 26) ? (g + 65) : (g + 71);
                    arr[52*53 + i + 52*h + 52*52*g + 52*52*52*f][2] = (h < 26) ? (h + 65) : (h + 71);
                    arr[52*53 + i + 52*h + 52*52*g + 52*52*52*f][3] = (i < 26) ? (i + 65) : (i + 71);
                    arr[52*53 + i + 52*h + 52*52*g + 52*52*52*f][4] = '\0';
                }
            }
        }
    }
    for (int a = 7314000; a < 7314100; a++)
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
