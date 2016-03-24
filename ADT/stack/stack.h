#pragma once

#define STACK_SIZE 10
#define STRING_SIZE 5
#define STACK_EMPTY -1

typedef struct stack_s stack_t;

// Constructor.
stack_t * stack_new(void);
// Destructor.
void stack_free(stack_t * self);
// Default methods.
int stack_size(const stack_t * self);
void stack_push(stack_t * self, const char * elem);
char *stack_pop(stack_t * self);
char *stack_peek(stack_t * self);
// Some fun functions.
void stack_print(stack_t * self);

