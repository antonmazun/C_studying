#pragma once

typedef struct mutex_s mutex_t;

// Constructor .
mutex_t *mutex_new(void);

// Destructor.
void mutex_free(mutex_t *self);

// Lock and Unlock mutex functions.
void mutex_lock(mutex_t *self);
void mutex_unlock(mutex_t *self);
