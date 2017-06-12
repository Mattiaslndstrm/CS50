#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void initials(string name);

int main(void) 
{   // Gets the users name as a string.
    string name = get_string();
    initials(name);
}

void initials(string name) 
{   
    // Prints the character at index i in uppercase if the preceding character 
    // is a space and not a space or index is 0 and not a space.
    for (int i = 0, n = strlen(name); i < n; i++)
    {   
        if (name[i] != 32 && (name[i -1] == 32 || i == 0))
        {
            printf("%c", toupper(name[i]));
        }
        
    }
    printf("\n");
}