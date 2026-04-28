#include <stdio.h>
#include "stack.h"
#include "queue.h"
#include "tree.h"

static void print_char(char c) {
    printf("%c ", c);
}

int main() {
    printf("=== Stack ===\n");
    Stack s;
    StackInit(&s);
    StackPush(&s, 1);
    StackPush(&s, 2);
    StackPush(&s, 3);
    printf("Top: %d\n", StackTop(&s));
    StackPop(&s);
    printf("After pop: %d\n", StackTop(&s));
    
    printf("\n=== Queue ===\n");
    Queue q;
    QueueInit(&q);
    QueueEnqueue(&q, 10);
    QueueEnqueue(&q, 20);
    QueueEnqueue(&q, 30);
    printf("Front: %d\n", QueueFront(&q));
    QueueDequeue(&q);
    printf("After dequeue: %d\n", QueueFront(&q));
    
    printf("\n=== Tree ===\n");
    Tree t;
    TreeInit(&t);
    TreeNode* root = TreeNodeCreate('A');
    TreeNode* b = TreeNodeCreate('B');
    TreeNode* c = TreeNodeCreate('C');
    TreeSetLeft(root, b);
    TreeSetRight(root, c);
    t.root = root;
    
    printf("Preorder: ");
    TreePreorder(root, print_char);
    printf("\n");
    
    TreeFree(&t);
    return 0;
}