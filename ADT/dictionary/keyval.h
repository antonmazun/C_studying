#pragma once

/*keyval struct - this is an object,
that represents a simple key-value pair*/

typedef struct keyval
{
    char *key;
    void *value;
} keyval;

keyval *keyval_new(char *key, void *value);
void keyval_free(keyval *self);

keyval *keyval_copy(const keyval *self);
int keyval_matches(const keyval *self, const char *key);
