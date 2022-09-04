// Implements a dictionary's functionality
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 19683; //27^3
unsigned int wordcount = 0;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    int n = 0;
    char copyword[LENGTH + 1] = {'\0'};
    while (word[n] != '\0')
    {
        copyword[n] = word[n];
        n++;
    }
    node *p = table[hash(copyword)];
    while (p != NULL)
    {
        if (strcasecmp(copyword, p->word) == 0)
        {
            return true;
        }
        p = p->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    int hashindex = 0, num = 27, letter = 3;// 27 alphabets including the apostrophes and sortting by the first 3 letters
    for (int i = 0; i < letter; i++)
    {
        if (((tolower(word[i]) - 'a') < 0) && (tolower(word[i]) != '\0'))
        {
            hashindex += 0;
        }
        else if (tolower(word[i]) == '\0')
        {
            hashindex += 1;
        }
        else
        {
            hashindex = hashindex + (tolower(word[i]) - 'a') * pow(num, (letter - i - 1)) + 1;
        }
    }
    return hashindex;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    char vocab[LENGTH + 1];
    int numhash;

    //Open dictionary file
    FILE *dict =  fopen(dictionary, "r");
    if (dict == NULL)
    {
        return false;
    }

    //Copy words to an array
    while (fscanf(dict, "%s", vocab) != EOF)
    {
        //Create a new node for each word
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return false;
        }
        //Copy the array to the node
        strcpy(n->word, vocab);
        n->next = NULL;
        //Get the table index
        numhash = hash(vocab);
        //Put the node to the hash
        if (table[numhash] == NULL)
        {
            table[numhash] = n;
            //printf("%s",table[numhash]->word);
        }
        else
        {
            n->next = table[numhash];
            table[numhash] = n;
        }
        wordcount++;
    }
    fclose(dict);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{

    return wordcount;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    int count = 0;
    for (int i = 0; i < N; i++)
    {
        node *p = table[i];
        node *tmp = table[i];
        while (tmp != NULL)
        {
            p = p->next;
            free(tmp);
            count++;
            tmp = p;
        }
    }
    if (count == wordcount)
    {
        return true;
    }
    else
    {
        return false;
    }
}
