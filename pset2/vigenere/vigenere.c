#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string vigenere(string plain);

int main(int argc, string argv[]) 
{   
    if (argc == 2)
    {
        printf("plaintext: ");
        string plaintext = get_string();
        printf("ciphertext: %s\n", vigenere(plaintext));
    }

    else
    {
        printf("Usage: ./vigenere plaintext");
        return 1;
    }
}

