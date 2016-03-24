#include <stdlib.h> // malloc
#include <stdio.h> // printf
#include "stack.h"

struct stack_s {
    int array[STACK_SIZE];
    int top;
};

stack_t * stack_new(void)
{
    stack_t * out = (stack_t *) malloc(sizeof(struct stack_s));
    out->top = 0;
    return (out);
}

void stack_free(stack_t * self)
{
    free(self);
}

int stack_getCount(stack_t * self)
{
    return (self->top);
}

void stack_push(stack_t * self, int val)
{
    self->array[self->top] = val;
    self->top++;
}

int stack_pop(stack_t * self)
{
    if(self->top > 0) {
        int val = self->array[self->top - 1];
        self->top--;
        return (val);
    }
    return (STACK_EMPTY);
}

int stack_peek(stack_t * self)
{
    if(self->top > 0) {
        int val = self->array[self->top - 1];
        return (val);
    }
    return (STACK_EMPTY);
}

void stack_print(stack_t * self)
{
    for(int i = 0; i < self->top; i++)
        printf("%3i ", self->array[i]);
}
