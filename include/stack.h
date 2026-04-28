#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STACK_MAX 100

typedef struct {
    int data[STACK_MAX];
    int top;
} Stack;

void StackInit(Stack* s);
bool StackIsEmpty(Stack* s);
bool StackPush(Stack* s, int x);
bool StackPop(Stack* s);
int StackTop(Stack* s);
void StackClear(Stack* s);

#ifdef __cplusplus
}
#endif

#endif
