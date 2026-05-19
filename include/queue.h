#ifndef QUEUE_H
#define QUEUE_H

#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#define QUEUE_MAX_SIZE 100

typedef struct {
    int data[QUEUE_MAX_SIZE];
    int front_index;
    int rear_index;
    int count;
} Queue;

void queue_init(Queue* queue);
bool queue_is_empty(const Queue* queue);
bool queue_enqueue(Queue* queue, int value);
bool queue_dequeue(Queue* queue);
int queue_front(const Queue* queue);
void queue_clear(Queue* queue);

#ifdef __cplusplus
}
#endif

#endif
