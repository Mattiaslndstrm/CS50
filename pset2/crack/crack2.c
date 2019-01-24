#define _XOPEN_SOURCE
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define AL 52
#define STRING_LENGTH 6

char *crack(char *hash, char *salt);
char to_char(int num);
bool compare_hash(char *hash, char *salt, char *text);
char *make_string(int a[], int n);

int main(int argc, char *argv[])
{
    if (argc == 2)
    {
        char *hash = argv[1];
        //https://stackoverflow.com/questions/4214314/get-a-substring-of-a-char
        // Copies 2 characters from hash to salt, starting at index 0 in the hash
        char salt[3];
        memcpy(salt, &hash[0], 2);
        salt[2] = '\0';
        char *s = crack(hash, salt);
        // Prints the stringed returned from crack();
        printf("%s\n", s);
        // Frees the memory allocated in make_string()
        free(s);
        return 0;
    }
    else
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }
}

char *crack(char *hash, char *salt)
{
    char *s;
    // For passwords of length 1
    for (int i = 0; i < AL; i++)
    {
        // Assigns the string created from the integers to the string literal s
        s = make_string((int []) {i}, 1);
        // Returns s if the hash created with s equals the hash the user provided
        if (compare_hash(hash, salt, s))
            return s;
        // Frees the memory allocated in make_string()
        free(s);
    }

    // For passwords of length 2
    for (int i = 0; i < AL; i++)
        for (int j = 0; j < AL; j++)
        {
            s = make_string((int []) {i, j}, 2);
            if (compare_hash(hash, salt, s))
                return s;
            free(s);
        }

    // For passwords of length 3
    for (int i = 0; i < AL; i++)
        for (int j = 0; j < AL; j++)
            for (int k = 0; k < AL; k++)
            {
                s = make_string((int []) {i, j, k}, 3);
                if (compare_hash(hash, salt, s))
                    return s;
                free(s);
            }

    // For passwords of length 4
    for (int i = 0; i < AL; i++)
        for (int j = 0; j < AL; j++)
            for (int k = 0; k < AL; k++)
                for (int l = 0; l < AL; l++)
                {
                    s = make_string((int []) {i, j, k, l}, 4);
                    if (compare_hash(hash, salt, s))
                        return s;
                    free(s);
                }

    // For passwords of length 5
    for (int i = 0; i < AL; i++)
        for (int j = 0; j < AL; j++)
            for (int k = 0; k < AL; k++)
                for (int l = 0; l < AL; l++)
                    for (int m = 0; m < AL; m++)
                    {
                        s = make_string((int []) {i, j, k, l, m}, 5);
                        if (compare_hash(hash, salt, s))
                            return s;
                        free(s);
                    }
    return "No password below six characters were found";
}

char *make_string(int a[], int n)
{
    // Allocates memory of length n + 1 to s. Since characters always are 1 byte
    // There is no need to use sizeof()
    char *s = malloc(n + 1);
    // Exit if malloc returns a null pointer
    if (s == NULL)
    {
        printf("ERROR: malloc failed in make_string\n");
        exit(EXIT_FAILURE);
    }
    int i;
    // Adds the integers converted to characters to s
    for (i = 0; i < n; i++)
        s[i] = to_char(a[i]);
    // Adds a null character as last character of s
    s[i] = '\0';
    return s;
}

char to_char(int num)
{
    // Returns uppercase character for all integers < 26 and lowercase for the rest
    return (num < 26) ? (num + 65) : (num + 71);
}

bool compare_hash(char *hash, char *salt, char *text)
{
    // Returns true if the text, encrypted, is equal to the user provided hash
    return strcmp(crypt(text, salt), hash) == 0;
}
