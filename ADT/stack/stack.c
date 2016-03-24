#include <stdio.h> // printf
#include <stdlib.h> // malloc free
#include <strings.h>

#include "stack.h"

// private:
struct stack_s{
    char arr[STACK_SIZE][STRING_SIZE];
    int top;
};

// public:
stack_t * stack_new(void)
{
    stack_t * out = (stack_t *) malloc(sizeof(struct stack_s));
    out->top = STACK_EMPTY;
    return (out);
}

void stack_free(stack_t * self)
{
    free(self);
}

int stack_size(const stack_t * self)
{
    return (self->top + 1);
}

void stack_push(stack_t * self, const char * elem)
{
    if(stack_size(self) == STACK_SIZE)
        return;
    strcpy(self->arr[self->top++], elem);
}

char *stack_pop(stack_t * self)
{
    if(stack_size(self) == 0)
        return NULL;
    char temp[STRING_SIZE];
    strcpy(temp, self->arr[self->top--]);
    return (temp);
}

char *stack_peek(stack_t * self)
{
    if(stack_size(self) == 0)
        return NULL;
    return (self->arr[self->top]);
}

void stack_print(stack_t * self)
{
    puts("Current stack: ");
    for(int i = 0; i < STACK_SIZE; i++)
        printf("%s\n", self->arr[i]);
}
