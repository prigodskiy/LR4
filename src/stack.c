#include "stack.h"

void StackInit(Stack* s) {
    s->top = -1;
}

bool StackIsEmpty(Stack* s) {
    return s->top == -1;
}

bool StackPush(Stack* s, int x) {
    if (s->top >= STACK_MAX - 1) {
        return false;
    }
    s->data[++s->top] = x;
    return true;
}

bool StackPop(Stack* s) {
    if (StackIsEmpty(s)) {
        return false;
    }
    s->top--;
    return true;
}

int StackTop(Stack* s) {
    return s->data[s->top];
}

void StackClear(Stack* s) {
    s->top = -1;
}
