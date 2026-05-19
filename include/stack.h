#ifndef STACK_H
#define STACK_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STACK_MAX_SIZE 100

typedef struct {
    int data[STACK_MAX_SIZE];
    int top_index;
} Stack;

void stack_init(Stack* stack);
bool stack_is_empty(const Stack* stack);
bool stack_push(Stack* stack, int value);
bool stack_pop(Stack* stack);
int stack_top(const Stack* stack);
void stack_clear(Stack* stack);

#ifdef __cplusplus
}
#endif

#endif
