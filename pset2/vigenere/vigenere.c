#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string vigenere(string keyword, string plain);

int main(int argc, string argv[]) 
{   
    if (argc == 2)
    // Checks if there is one additional command line argument.
    {
        printf("plaintext: ");
        // Gets the plain text from the user
        string plaintext = get_string();
        // Prints the encoded string from the command line argument stored in 
        // position 1
        printf("cyphertext: %s\n", vigenere(argv[1], plaintext));
    }

    else
    {
        printf("Usage: ./vigenere keyword");
        return 1;
    }
}

string vigenere(string keyword, string plain)
{
    for (int i = 0, n = strlen(plain); i < n; i ++) {
        // Equals the difference between the current character in keyword  
        // converted to lowercase and lowercase a. The current position in 
        // keyword equals i % (length of keyword)
        int diff = tolower(keyword[i % strlen(keyword)]) - 97;

        // For uppercase. plain[i] + diff - 13) % 26 equals the position of 
        // the cypher letter in the alphabet (because 65 % 26 = 13) . Add 65 
        // and we get the position of the letter in ASCII.
        if (plain[i] >= 65 && plain[i] <= 90)
        {   
            plain[i] = (plain[i] + diff - 13) % 26 + 65;
        }
        // For lowercase. plain[i] + diff - 19) % 26 equals the position of 
        // the cypher letter in the alphabet (because 97 % 26 = 19). Add 97 and 
        // we get the position of the letter in ASCII. 
        if (plain[i] >= 97 && plain[i] <= 122)
        {
            plain[i] = (plain[i] + diff - 19) % 26 + 97;
        }
    }
    return plain;
}
