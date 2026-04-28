#include "queue.h"

void QueueInit(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}

bool QueueIsEmpty(Queue* q) {
    return q->count == 0;
}

bool QueueEnqueue(Queue* q, int x) {
    if (q->count >= QUEUE_MAX) {
        return false;
    }
    q->data[q->rear] = x;
    q->rear = (q->rear + 1) % QUEUE_MAX;
    q->count++;
    return true;
}

bool QueueDequeue(Queue* q) {
    if (QueueIsEmpty(q)) {
        return false;
    }
    q->front = (q->front + 1) % QUEUE_MAX;
    q->count--;
    return true;
}

int QueueFront(Queue* q) {
    return q->data[q->front];
}

void QueueClear(Queue* q) {
    q->front = 0;
    q->rear = 0;
    q->count = 0;
}