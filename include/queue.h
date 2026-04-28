#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define QUEUE_MAX 100

typedef struct {
    int data[QUEUE_MAX];
    int front;
    int rear;
    int count;
} Queue;

void QueueInit(Queue* q);
bool QueueIsEmpty(Queue* q);
bool QueueEnqueue(Queue* q, int x);
bool QueueDequeue(Queue* q);
int QueueFront(Queue* q);
void QueueClear(Queue* q);

#ifdef __cplusplus
}
#endif

#endif