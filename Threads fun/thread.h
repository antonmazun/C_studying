#pragma once

// Basic types
typedef struct thread_s thread_t;
typedef void *(*thread_func_t)(void *);

// Helper functions.
thread_t *thread_create(thread_func_t func);
thread_t *thread_create_args(thread_func_t func, void *args);

// Destructor
void thread_free(thread_t *self);

// Main methods
int thread_join(const thread_t *self);
int thread_join_result(const thread_t *self, void **result);
int thread_terminate(const thread_t *self);
int thread_equals(const thread_t *t1, const thread_t *t2);
