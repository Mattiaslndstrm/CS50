#include <unistd.h>
#include <cs50.h>
#include <stdlib.h>
#include <stdio.h>

#define _XOPEN_SOURCE

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