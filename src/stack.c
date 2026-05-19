#include "stack.h"

void stack_init(Stack *stack) {
    stack->top_index = -1;
}

bool stack_is_empty(const Stack *stack) {
    return stack->top_index == -1;
}

bool stack_push(Stack *stack, int value) {
    if (stack->top_index >= STACK_MAX_SIZE - 1) {
        return false;
    }
    stack->data[++stack->top_index] = value;
    return true;
}

bool stack_pop(Stack *stack) {
    if (stack_is_empty(stack)) {
        return false;
    }
    --stack->top_index;
    return true;
}

int stack_top(const Stack *stack) {
    return stack->data[stack->top_index];
}

void stack_clear(Stack *stack) {
    stack->top_index = -1;
}
