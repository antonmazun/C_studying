#include <stdio.h> //fprintf
#include <stdlib.h> //malloc realloc
#include "dict.h"

void *dictionary_not_found;

dictionary *dictionary_new(void)
{
    static int dnf;
    if (!dictionary_not_found)
        dictionary_not_found = &dnf; //because the address of dnf is unique
    dictionary *out = (dictionary *) malloc(sizeof(dictionary));
    *out = (dictionary) { };
    return (out);
}

void dictionary_free(dictionary *self)
{
    for(int i = 0; i < self->length; i++)
        keyval_free(self->pairs[i]);
    free(self);
}

static void dictionary_add_keyval(dictionary *self, keyval *kv)
{
    self->length++;
    self->pairs = realloc(self->pairs, sizeof(keyval*)*self->length);
    self->pairs[self->length - 1] = kv;
}

void dictionary_add(dictionary *self, char *key, void *value)
{
    if(!key) {
        fprintf(stderr, "Key cannot be NULL.\n");
        abort();
    }
    dictionary_add_keyval(self, keyval_new(key, value));
}

void *dictionary_find(const dictionary *self, const char *key)
{
    for(int i = 0; i < self->length; i++)
        if(keyval_matches(self->pairs[i], key))
            return (self->pairs[i]->value);
    return (dictionary_not_found);
}

dictionary *dictionary_copy(dictionary *self)
{
    dictionary *out = dictionary_new();
    for(int i = 0; i < self->length; i++)
        dictionary_add_keyval(out, keyval_copy(self->pairs[i]));
    return (out);
}


