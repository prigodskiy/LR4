#include <gtest/gtest.h>
#include "queue.h"

TEST(QueueTest, InitEmpty) {
    Queue q;
    QueueInit(&q);
    EXPECT_TRUE(QueueIsEmpty(&q));
}

TEST(QueueTest, EnqueueDequeue) {
    Queue q;
    QueueInit(&q);
    
    QueueEnqueue(&q, 10);
    QueueEnqueue(&q, 20);
    QueueEnqueue(&q, 30);
    
    EXPECT_EQ(QueueFront(&q), 10);
    QueueDequeue(&q);
    EXPECT_EQ(QueueFront(&q), 20);
    QueueDequeue(&q);
    QueueDequeue(&q);
    EXPECT_TRUE(QueueIsEmpty(&q));
}

TEST(QueueTest, Clear) {
    Queue q;
    QueueInit(&q);
    QueueEnqueue(&q, 1);
    QueueEnqueue(&q, 2);
    QueueClear(&q);
    EXPECT_TRUE(QueueIsEmpty(&q));
}