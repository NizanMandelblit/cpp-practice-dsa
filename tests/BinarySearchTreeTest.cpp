#include <gtest/gtest.h>
#include "../src/BinarySearchTree.h"

// BinarySearchTree Tests with Complex Scenarios

// Test inserting multiple elements and checking tree structure
TEST(BinarySearchTreeTest, InsertMultipleElementsAndContains) {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    // Check presence of inserted elements
    EXPECT_TRUE(bst.contains(50));
    EXPECT_TRUE(bst.contains(30));
    EXPECT_TRUE(bst.contains(70));
    EXPECT_TRUE(bst.contains(20));
    EXPECT_TRUE(bst.contains(40));
    EXPECT_TRUE(bst.contains(60));
    EXPECT_TRUE(bst.contains(80));

    // Check non-inserted elements
    EXPECT_FALSE(bst.contains(10));
    EXPECT_FALSE(bst.contains(90));
}

// Test removing a leaf node
TEST(BinarySearchTreeTest, RemoveLeafNode) {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);  // Leaf node

    EXPECT_TRUE(bst.remove(20));
    EXPECT_FALSE(bst.contains(20));  // Ensure it's removed
}

// Test removing a node with one child
TEST(BinarySearchTreeTest, RemoveNodeWithOneChild) {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(30);
    bst.insert(60);  // Node with one child

    EXPECT_TRUE(bst.remove(70));
    EXPECT_FALSE(bst.contains(70));
    EXPECT_TRUE(bst.contains(60));  // Check if child is still present
}

// Test removing a node with two children
TEST(BinarySearchTreeTest, RemoveNodeWithTwoChildren) {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    EXPECT_TRUE(bst.remove(70));
    EXPECT_FALSE(bst.contains(70));
    EXPECT_TRUE(bst.contains(60));
    EXPECT_TRUE(bst.contains(80));
}

/*
Test removing a node with two children where the successor is not the immediate right child
Binary Search Tree Structure for RemoveNodeWithTwoChildrenNonImmediateSuccessor Test:

          50
         /  \
       30    70
             /  \
           60    80
          /
        55

Explanation:
- Root node: 50
- Node 50 has two children, 30 (left) and 70 (right).
- Node 70 has two children: 60 (left) and 80 (right).
- Node 60 has a left child, 55, which is the leftmost node in the right subtree of 50.

Test Case Objective:
- Remove node 50.
- Node 55 is the in-order successor of 50 (the smallest node greater than 50).
- After deletion, 55 should replace 50 as the new root, with 30 as its left child and 70 as its right child.
- The subtree under 70 should remain intact, with 60 and 80 properly positioned.

Resulting Tree after Removal of 50:

          55
         /  \
       30    70
             /  \
           60    80
*/
TEST(BinarySearchTreeTest, RemoveNodeWithTwoChildrenNonImmediateSuccessor) {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(60);       // Left child of the right subtree
    bst.insert(80);
    bst.insert(55);       // Leftmost child of the 70's subtree

    EXPECT_TRUE(bst.remove(50));
    EXPECT_FALSE(bst.contains(50));
    EXPECT_TRUE(bst.contains(30));
    EXPECT_TRUE(bst.contains(70));
    EXPECT_TRUE(bst.contains(60));
    EXPECT_TRUE(bst.contains(80));
    EXPECT_TRUE(bst.contains(55));  // Successor's original child should still be present
}


// Test getMin and getMax with complex tree structures
TEST(BinarySearchTreeTest, GetMinAndMaxComplexTree) {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);

    EXPECT_EQ(bst.getMin(), 20);
    EXPECT_EQ(bst.getMax(), 80);
}

// Test a combination of insert, remove, getMin, and getMax
TEST(BinarySearchTreeTest, ComplexOperationsSequence) {
    BinarySearchTree bst;
    bst.insert(10);
    bst.insert(20);
    bst.insert(30);
    bst.insert(25);
    bst.insert(5);

    // Initial min and max checks
    EXPECT_EQ(bst.getMin(), 5);
    EXPECT_EQ(bst.getMax(), 30);

    // Remove nodes and check min/max updates
    bst.remove(30);
    EXPECT_EQ(bst.getMax(), 25);

    bst.remove(5);
    EXPECT_EQ(bst.getMin(), 10);

    // Further complex insertions and deletions
    bst.insert(50);
    EXPECT_EQ(bst.getMax(), 50);
    bst.remove(10);
    EXPECT_EQ(bst.getMin(), 20);
}


// Test inserting a large sequence of elements and performing complex operations
TEST(BinarySearchTreeTest, LargeTreeInsertionAndRemoval) {
    BinarySearchTree bst;

    for (int i = 0; i < 100; ++i) {
        bst.insert(i);
    }
    EXPECT_EQ(bst.getMin(), 0);
    EXPECT_EQ(bst.getMax(), 99);

    for (int i = 0; i < 50; ++i) {
        bst.remove(i);
    }

    EXPECT_EQ(bst.getMin(), 50);
    EXPECT_EQ(bst.getMax(), 99);
}
