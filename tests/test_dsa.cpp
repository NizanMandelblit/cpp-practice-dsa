#include "gtest/gtest.h"
#include "../src/LinkedList.h"
#include "../src/Stack.h"

// LinkedList Tests
TEST(LinkedListTest, InsertElement) {
    LinkedList list;
    list.insert(5);
    EXPECT_TRUE(list.contains(5));
}

TEST(LinkedListTest, RemoveElement) {
    LinkedList list;
    list.insert(10);
    EXPECT_TRUE(list.remove(10));
    EXPECT_FALSE(list.contains(10));
}

TEST(LinkedListTest, CheckSize) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    EXPECT_EQ(list.size(), 2);
}

// Stack Tests
TEST(StackTest, PushElement) {
    Stack stack;
    stack.push(5);
    EXPECT_FALSE(stack.isEmpty());
}

TEST(StackTest, PopElement) {
    Stack stack;
    stack.push(10);
    EXPECT_EQ(stack.pop(), 10);
    EXPECT_TRUE(stack.isEmpty());
}

TEST(StackTest, PopEmptyStack) {
    Stack stack;
    EXPECT_THROW(stack.pop(), std::runtime_error);
}

