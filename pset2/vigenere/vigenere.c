#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string vigenere(string keyword, string plain);
bool alpha(string word);

int main(int argc, string argv[]) 
{   
    // Checks if there is one additional command line argument.
    if (argc == 2)
    {
        // Checks if the keyword does not contain any non-alphabetic 
        // characters
        if (alpha(argv[1]))
        {
            printf("plaintext: ");
            // Gets the plain text from the user
            string plaintext = get_string();
            // Prints the encoded string from the command line argument stored  
            // in position 1
            printf("ciphertext: %s\n", vigenere(argv[1], plaintext));
            // To terminate the program
            return 0;
        }
    }

    // Incorrect use of vigenere. Exit with error.
    printf("Usage: ./vigenere keyword\n");
    return 1;
}

bool alpha(string word)
// Iterates through the string word and returns false if it contains any 
// non-alphabetic characters.
{   
    bool alpha = true;
    for (int j = 0, m = strlen(word); j < m; j++)
        {
            if (!isalpha(word[j]))
        {
            alpha = false;
        }
        }
    return alpha;
}

string vigenere(string keyword, string plain)
{
    int non_alpha = 0;
    // Iterates through the character of plain 
    for (int i = 0, n = strlen(plain); i < n; i ++) {
        
        // Adds 1 for every non alphabetic character to the int non_alpha
        if (!isalpha(plain[i]))
        {
            non_alpha += 1;
        }

        // Equals the difference between the current character in the keyword  
        // converted to lowercase and lowercase a. The current position in 
        // keyword equals (i minus eventual non-alphabetic characters) % 
        // (length of keyword)
        int diff = tolower(keyword[(i - non_alpha) % strlen(keyword)]) - 97;

        // For uppercase. plain[i] + diff - 13) % 26 equals the position of 
        // the cipher letter in the alphabet (because 65 % 26 = 13) . Add 65 
        // and we get the position of the letter in ASCII. Changes the current 
        //character of plain to the cipherletter
        if (plain[i] >= 65 && plain[i] <= 90)
        {   
            plain[i] = (plain[i] + diff - 13) % 26 + 65;
        }
        // For lowercase. plain[i] + diff - 19) % 26 equals the position of 
        // the cipher letter in the alphabet (because 97 % 26 = 19). Add 97  
        // and we get the position of the letter in ASCII. Changes the current 
        // character of plain to the cipherletter
        if (plain[i] >= 97 && plain[i] <= 122)
        {
            plain[i] = (plain[i] + diff - 19) % 26 + 97;
        }
    }
    return plain;
}
