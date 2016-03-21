#include <stdlib.h> //malloc
#include <strings.h> //strcasecmp
#include "keyval.h"

keyval *keyval_new(char *key, void *value)
{
    keyval *out = (keyval *) malloc(sizeof(keyval));
    *out = (keyval)
    {
        .key = key, .value = value
    };
    return (out);
}

void keyval_free(keyval *self)
{
    free(self);
}

keyval *keyval_copy(const keyval *self)
{
    keyval *out = (keyval *) malloc(sizeof(keyval));
    *out = *self;
    return (out);
}

int keyval_matches(const keyval *in, const char *key)
{
    return (!strcasecmp(in->key, key));
}
