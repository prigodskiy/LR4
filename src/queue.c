#include "queue.h"

void queue_init(Queue *queue) {
    queue->front_index = 0;
    queue->rear_index = 0;
    queue->count = 0;
}

bool queue_is_empty(const Queue *queue) {
    return queue->count == 0;
}

bool queue_enqueue(Queue *queue, int value) {
    if (queue->count >= QUEUE_MAX_SIZE) {
        return false;
    }
    queue->data[queue->rear_index] = value;
    queue->rear_index = (queue->rear_index + 1) % QUEUE_MAX_SIZE;
    ++queue->count;
    return true;
}

bool queue_dequeue(Queue *queue) {
    if (queue_is_empty(queue)) {
        return false;
    }
    queue->front_index = (queue->front_index + 1) % QUEUE_MAX_SIZE;
    --queue->count;
    return true;
}

int queue_front(const Queue *queue) {
    return queue->data[queue->front_index];
}

void queue_clear(Queue *queue) {
    queue_init(queue);
}
