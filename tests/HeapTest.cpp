#include <gtest/gtest.h>
#include "../src/Heap.h"
#include <unordered_map>
#include <vector>

// Test inserting multiple elements and checking heap property
TEST(HeapTest, InsertMultipleElementsAndPeek) {
    Heap heap;
    heap.insert(50);
    heap.insert(30);
    heap.insert(70);
    heap.insert(20);
    heap.insert(40);
    heap.insert(60);
    heap.insert(80);

    // Check the root element for min-heap property
    EXPECT_EQ(heap.peek(), 20);
}

// Test extracting the minimum element in a min-heap
TEST(HeapTest, ExtractMinElement) {
    Heap heap;
    heap.insert(50);
    heap.insert(30);
    heap.insert(70);
    heap.insert(20);

    EXPECT_EQ(heap.extract(), 20);  // Minimum element
    EXPECT_EQ(heap.peek(), 30);     // Next minimum element after extraction
}

// Test inserting and removing all elements
TEST(HeapTest, InsertAndRemoveAllElements) {
    Heap heap;
    heap.insert(10);
    heap.insert(15);
    heap.insert(20);
    heap.insert(17);

    EXPECT_EQ(heap.extract(), 10);
    EXPECT_EQ(heap.extract(), 15);
    EXPECT_EQ(heap.extract(), 17);
    EXPECT_EQ(heap.extract(), 20);

    EXPECT_TRUE(heap.isEmpty());
}

// Test maintaining the min-heap property after multiple insertions and extractions
TEST(HeapTest, MinHeapProperty) {
    Heap heap;
    heap.insert(45);
    heap.insert(20);
    heap.insert(14);
    heap.insert(7);
    heap.insert(30);
    heap.insert(50);

    EXPECT_EQ(heap.extract(), 7);
    EXPECT_EQ(heap.extract(), 14);
    EXPECT_EQ(heap.extract(), 20);
    EXPECT_EQ(heap.extract(), 30);
    EXPECT_EQ(heap.extract(), 45);
    EXPECT_EQ(heap.extract(), 50);
}

// Test a large sequence of insertions to check heap integrity
TEST(HeapTest, LargeHeapInsertion) {
    Heap heap;
    for (int i = 100; i > 0; --i) {
        heap.insert(i);
    }
    EXPECT_EQ(heap.peek(), 1);  // Root should hold the smallest element in min-heap
    EXPECT_EQ(heap.size(), 100);

    for (int i = 1; i <= 100; ++i) {
        EXPECT_EQ(heap.extract(), i);
    }
    EXPECT_TRUE(heap.isEmpty());
}

// Test extracting from an empty heap
TEST(HeapTest, ExtractFromEmptyHeap) {
    Heap heap;
    EXPECT_THROW(heap.extract(), std::out_of_range);
}

// Test peeking into an empty heap
TEST(HeapTest, PeekIntoEmptyHeap) {
    Heap heap;
    EXPECT_THROW(heap.peek(), std::out_of_range);
}
