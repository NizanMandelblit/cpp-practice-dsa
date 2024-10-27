#include "gtest/gtest.h"
#include "../src/LinkedList.h"
#include "../src/Stack.h"

// LinkedList Tests

// Test insertion at head, tail, and in between
TEST(LinkedListTest, InsertMultipleElements) {
    LinkedList list;
    list.insert(5);
    list.insert(10);
    list.insert(15);
    EXPECT_TRUE(list.contains(5));
    EXPECT_TRUE(list.contains(10));
    EXPECT_TRUE(list.contains(15));
    EXPECT_EQ(list.size(), 3);
}

// Test duplicate elements insertion
TEST(LinkedListTest, InsertDuplicateElements) {
    LinkedList list;
    list.insert(5);
    list.insert(5);  // Assume duplicates are allowed or handle as per requirement
    EXPECT_EQ(list.size(), 2); // or 1 if duplicates are disallowed
}

// Test remove on an empty list
TEST(LinkedListTest, RemoveFromEmptyList) {
    LinkedList list;
    EXPECT_FALSE(list.remove(5));
    EXPECT_EQ(list.size(), 0);
}

// Test removing an element that does not exist
TEST(LinkedListTest, RemoveNonExistentElement) {
    LinkedList list;
    list.insert(1);
    EXPECT_FALSE(list.remove(100));
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.contains(1));
}

// Test inserting and removing all elements
TEST(LinkedListTest, InsertAndClear) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    EXPECT_TRUE(list.remove(1));
    EXPECT_TRUE(list.remove(2));
    EXPECT_TRUE(list.remove(3));
    EXPECT_EQ(list.size(), 0);
    EXPECT_FALSE(list.contains(1));
    EXPECT_FALSE(list.contains(2));
    EXPECT_FALSE(list.contains(3));
}

// Test list size after each operation
TEST(LinkedListTest, SizeAfterOperations) {
    LinkedList list;
    EXPECT_EQ(list.size(), 0);
    list.insert(1);
    EXPECT_EQ(list.size(), 1);
    list.insert(2);
    EXPECT_EQ(list.size(), 2);
    list.remove(1);
    EXPECT_EQ(list.size(), 1);
    list.remove(2);
    EXPECT_EQ(list.size(), 0);
}

// Test contains on an empty list
TEST(LinkedListTest, ContainsInEmptyList) {
    LinkedList list;
    EXPECT_FALSE(list.contains(10));
}

// Test order of elements in insertion (if order matters)
TEST(LinkedListTest, CheckOrderOfElements) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
}

// Edge cases with large input size
TEST(LinkedListTest, LargeNumberOfElements) {
    LinkedList list;
    for (int i = 0; i < 10000; ++i) {
        list.insert(i);
    }
    EXPECT_EQ(list.size(), 10000);
    EXPECT_TRUE(list.contains(5000));
    EXPECT_TRUE(list.remove(5000));
    EXPECT_FALSE(list.contains(5000));
    EXPECT_EQ(list.size(), 9999);
}

// Test removal of head element
TEST(LinkedListTest, RemoveHeadElement) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    EXPECT_TRUE(list.remove(1));
    EXPECT_FALSE(list.contains(1));
    EXPECT_EQ(list.size(), 2);
}

// Test removal of tail element
TEST(LinkedListTest, RemoveTailElement) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    EXPECT_TRUE(list.remove(3));
    EXPECT_FALSE(list.contains(3));
    EXPECT_EQ(list.size(), 2);
}

// Test removal of middle element
TEST(LinkedListTest, RemoveMiddleElement) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    EXPECT_TRUE(list.remove(2));
    EXPECT_FALSE(list.contains(2));
    EXPECT_EQ(list.size(), 2);
    EXPECT_TRUE(list.contains(1));
    EXPECT_TRUE(list.contains(3));
}

// Check if list is empty after clearing
TEST(LinkedListTest, IsEmptyAfterClearing) {
    LinkedList list;
    list.insert(1);
    list.insert(2);
    list.insert(3);
    list.remove(1);
    list.remove(2);
    list.remove(3);
    EXPECT_EQ(list.size(), 0);
    EXPECT_FALSE(list.contains(1));
    EXPECT_FALSE(list.contains(2));
    EXPECT_FALSE(list.contains(3));
}
