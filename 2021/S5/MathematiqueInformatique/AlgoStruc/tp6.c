#include<stdio.h>
#include<stdlib.h>

void display_words(FILE* out, unsigned size, char** words)
{
    for  (unsigned i = 0; i < size; i++)
        fprintf(out, "%s\n", words[i]);
}

size_t my_strlen(char *s)
{
    size_t i = 0;
    while (s[i] != '\0')
        i++;
    return i;
}

unsigned bad_hash(char* word)
{
    unsigned res = 0;
    for (size_t i = 0; i < my_strlen(word); i++)
    {
        res += word[i];
    }
    return res;
}

struct keyval {
  char* key;
  unsigned val;
  struct keyval* next;
};

struct ht {
  struct keyval** table;
  unsigned size;
};

struct ht* ht_malloc(unsigned size)
{
    struct ht* new_ht = malloc(size);
    new_ht->size = size;
    return new_ht;
}

void ht_free(struct ht* table)
{
    free(table);
}
