// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
    bool test = load(argv[1]);
    if (test)
        printf("Something happened\n");
    else
        printf("nothing happened");
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
        for (char *p = word; *p; p++)
        {
            // If the node for the current letter already exist, only traverse
            if (cur->children[*p - 97])
            {
                cur = cur->children[*p - 97];
                continue;
            }
            // Allocates memory to a new node
            node *new = malloc(sizeof(node));
            // Unload the dictionary and returns false if allocation fails
            if (new == NULL)
            {
                unload();
                return false;
            }
            // Assigns the new node to index of the current letter and assigns
            // cur to point to child node
            cur->children[*p - 97] = new;
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
    // TODO
    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
