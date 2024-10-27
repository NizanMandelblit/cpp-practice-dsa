#include "gtest/gtest.h"
#include "../src/Stack.h"

// Stack Tests

// Test pushing a single element to the stack
TEST(StackTest, PushSingleElement) {
    Stack stack;
    stack.push(10);
    EXPECT_FALSE(stack.isEmpty());
}

// Test popping a single element from the stack
TEST(StackTest, PopSingleElement) {
    Stack stack;
    stack.push(10);
    EXPECT_EQ(stack.pop(), 10);
    EXPECT_TRUE(stack.isEmpty());
}

// Test pushing and popping multiple elements
TEST(StackTest, PushAndPopMultipleElements) {
    Stack stack;
    stack.push(5);
    stack.push(10);
    stack.push(15);
    EXPECT_EQ(stack.pop(), 15);
    EXPECT_EQ(stack.pop(), 10);
    EXPECT_EQ(stack.pop(), 5);
    EXPECT_TRUE(stack.isEmpty());
}

// Test stack is empty after multiple push and pop operations
TEST(StackTest, IsEmptyAfterOperations) {
    Stack stack;
    stack.push(20);
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}

// Test popping from an empty stack
TEST(StackTest, PopFromEmptyStack) {
    Stack stack;
    EXPECT_THROW(stack.pop(), std::underflow_error); // Assumes pop throws an error if stack is empty
    EXPECT_TRUE(stack.isEmpty());
}

// Test pushing multiple elements and checking the top element each time
TEST(StackTest, CheckTopElementAfterPushes) {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    EXPECT_EQ(stack.pop(), 3);
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.pop(), 1);
}

// Test behavior with large input size
TEST(StackTest, LargeNumberOfElements) {
    Stack stack;
    for (int i = 0; i < 10000; ++i) {
        stack.push(i);
    }
    EXPECT_FALSE(stack.isEmpty());
    EXPECT_EQ(stack.pop(), 9999); // Assuming LIFO order
    EXPECT_EQ(stack.pop(), 9998);
}

// Test isEmpty on a new stack
TEST(StackTest, IsEmptyOnNewStack) {
    Stack stack;
    EXPECT_TRUE(stack.isEmpty());
}

// Test isEmpty after clearing all elements
TEST(StackTest, IsEmptyAfterClearing) {
    Stack stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.pop();
    stack.pop();
    stack.pop();
    EXPECT_TRUE(stack.isEmpty());
}
