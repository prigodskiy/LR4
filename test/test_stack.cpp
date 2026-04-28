#include <gtest/gtest.h>
#include "stack.h"

TEST(StackTest, InitEmpty) {
    Stack s;
    StackInit(&s);
    EXPECT_TRUE(StackIsEmpty(&s));
}

TEST(StackTest, PushPop) {
    Stack s;
    StackInit(&s);
    
    StackPush(&s, 10);
    StackPush(&s, 20);
    StackPush(&s, 30);
    
    EXPECT_EQ(StackTop(&s), 30);
    StackPop(&s);
    EXPECT_EQ(StackTop(&s), 20);
    StackPop(&s);
    StackPop(&s);
    EXPECT_TRUE(StackIsEmpty(&s));
}

TEST(StackTest, Clear) {
    Stack s;
    StackInit(&s);
    StackPush(&s, 1);
    StackPush(&s, 2);
    StackClear(&s);
    EXPECT_TRUE(StackIsEmpty(&s));
}
