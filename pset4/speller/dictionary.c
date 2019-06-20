// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "dictionary.h"

// Represents number of children for each node in a trie
#define N 27

// Represents a node in a trie
typedef struct node
{
    bool is_word;
    struct node *children[N];
}
node;

// Represents a trie
node *root, *cur;

int main(int argc, char *argv[])
{
    load(argv[1]);
    bool word = check(argv[2]);
    if (word)
        printf("%s is correctly spelled\n", argv[2]);
    else
        printf("%s is NOT correctly spelled\n", argv[2]);
}
// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        return false;
    }
    root->is_word = false;
    for (int i = 0; i < N; i++)
    {
        root->children[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        printf("ERROR: failed to open dict\n");
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];

    // Insert words into trie
    while (fscanf(file, "%s", word) != EOF)
    {
        // Assign cur to point to the root node.
        cur = root;
        // Iterate through word with pointer p
        for (char *p = word; *p != '\0'; p++)
        {
            // Sets c to 26 if the current char is an apostrophe, else *p - 97
            int c = char_to_int(*p);
            // If the node for the current letter already exist, only traverse
            if (cur->children[c])
            {
                cur = cur->children[c];
                continue;
            }
            // Allocates memory to a new node
            node *new = malloc(sizeof(node));
            // Unload the dictionary and returns false if allocation fails
            if (new == NULL)
            {
                printf("ERROR: malloc failed to allocate to *new\n");
                unload();
                return false;
            }
            // Assigns the new node to index of the current letter and assigns
            // cur to point to child node
            cur->children[c] = new;
            cur = new;
            // Sets all children to NULL
            for (int i = 0; i < N; i++)
                cur->children[i] = NULL;
        }
        // Since we have iterated through a whole word cur is a word
        cur->is_word = true;
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    cur = root;
    for (const char *p = word; *p != '\0'; p++)
    {
        int c = char_to_int(*p);
        cur = cur->children[c];
        if (cur == NULL)
            return false;
    }
    if (cur->is_word)
        return true;
    return false;
}

int char_to_int(const char c)
{
    return tolower(c) == '\'' ? 26 : tolower(c) - 97;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
