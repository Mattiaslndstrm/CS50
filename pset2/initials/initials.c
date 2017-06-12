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
    if (name[0] != 32)
    {
        printf("%c", toupper(name[0]));
    }
    for (int i = 0, n = strlen(name); i < n; i++)
    {   
        if (name[i] != 32 && name[i -1] == 32)
        {
            printf("%c", toupper(name[i]));
        }
        
    }
    printf("\n");
}