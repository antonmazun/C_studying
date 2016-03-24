#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

#define STACK_SIZE 100
#define STACK_EMPTY -1

typedef struct stack_s stack_t;

stack_t * stack_new(void);
void stack_free(stack_t * self);

int stack_getCount(stack_t * self);
void stack_push(stack_t * self, int val);
int stack_pop(stack_t * self);
int stack_peek(stack_t * self);

void stack_print(stack_t * self);

int DLL_EXPORT compare(int a, int b);
void DLL_EXPORT reaction(stack_t * a, stack_t * b);

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
