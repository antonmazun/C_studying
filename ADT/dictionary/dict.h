#pragma once
#include "keyval.h"
//A sign, that will return, if a key won`t be found in the dit
extern void *dictionary_not_found;

typedef struct dictionary
{
    keyval **pairs;
    int length;
} dictionary;

dictionary *dictionary_new(void);
void dictionary_free(dictionary *self);

dictionary *dictionary_copy(dictionary *self);
void dictionary_add(dictionary *self, char *key, void *value);
void *dictionary_find(const dictionary *self, const char *key);
